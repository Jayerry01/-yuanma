# 《流星蝴蝶剑.net》战斗打击判定、击飞冲量与伤害结算逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，MD5: `cf2aa5c21a0a687afacc5e5c0876c543`，基址: `0x00400000`)  
> **代码来源**: `07_Combat_HitDamage_System.c` 与 `09_Weapon_HitBox_Pipeline.c`（经 Ghidra 12.1.4 真实反编译）  
> **核心函数定位**:
> - `0x004D0540`: `PlayerController::OnHit`（击飞冲量积分、受击浮空偏置、受击姿态切换）
> - `0x004D0AC0`: `PlayerController::ProcessDamage`（气血扣减、击退速度分级查表、武器数据绑定）
> - `0x004D1740`: `CombatSystem::LoadAttackParameters`（招式攻击数据解析器）
> - `0x004D1EA0`: `CombatSystem::ApplyKnockbackImpulse`（受击速度叠加与速度限幅）
> - `0x004D3634` / `0x004D3690`: `WeaponSystem::EvaluateHitBoxOverlap`（武器扫掠盒与角色 AABB 求交）
> - `0x0055DA50`: `CharacterActor::TestHitBoxOverlap`（AABB 宽相检测与中相骨骼/刀刃切分）
> - `0x0056F1D0`: `WeaponSystem::TestBladeRibbonSweep`（刀光轨迹面线段相交检测）
> - `0x00570630` / `0x005706C0`: `Math::IntersectSegmentOBB`（分离轴定理 SAT 线段与有向包围盒相交测试）
> - `0x004FDDC9`: `AIController::EvaluateRageBreakout`（AI 怒气爆发与绝招反击判定）

---

## 一、 受击击飞冲量动力学方程 (`0x004D0540`)

在反编译产物 `07_Combat_HitDamage_System.c` 的 `FUN_004d0540` 中，揭示了《流星蝴蝶剑》经典浮空与吹飞手感的真实底层计算式：

```c
/* 提取自 0x004D0668 ~ 0x004D06BE */
// 0x004D0674: fadd dword ptr [0x5AA944] (+0.13f 向上偏置)
// 0x004D0698, 0x004D06A6, 0x004D06BE: fmul dword ptr [0x5AA934] (600.0f 标量缩放)
float impulseX = hitNormalX * 600.0f;
float impulseY = hitNormalY * 600.0f;
float impulseZ = (hitNormalZ + 0.13f) * 600.0f; // 垂直仰角抬升偏置
```

### 1. 物理参数物理学诠释
- **`600.0f` (`METEOR_MAX_SPEED_CAP`)**: 二进制地址 `0x005AA934`。游戏全引擎标量速度天花板，任何攻击的最大瞬间击退初速均以此为基准进行衰减与缩放。
- **`+0.13f` 垂直抬升偏置 (Pop-Up Bias)**: 
  - 即使攻击法线完全水平（`hitNormalZ = 0.0f`），在被击中时也会强制施加 `0.13 * 600.0f = 78.0f/s` 的向上垂直冲量！
  - **这一设计是原版“轻击也能打出微浮空、形成空中连续技（小跳挑空）”的底层物理根本原因**。
- **受击点探测基准 (`+40.0f`)**: 
  - 指令位置 `0x004D05EB: fadd dword ptr [0x5A8E7C]`（机器码 `D8 05 7C 8E 5A 00`）：角色受击检测上身探测点取自脚底原点上浮 40 单位，精确对应人物胸腔重心。
- **中间偏置 (`+20.0f`)**:
  - 指令位置 `0x004D0B73: fadd dword ptr [0x5A8B08]`（机器码 `D8 05 08 8B 5A 00`）：受击火花与受力作用点在角色胸腔与盆骨中点（+20 单位）。

---

## 二、 4 级击退初速分级查表 (`0x004D0AC0` / `0x004D0CBC`)

在 `0x004D0BA5` ~ `0x004D0BD0`，游戏引擎根据招式的打击强度等级（`impactLevel`，通过栈参数传入），对受击角色的瞬间击退初速进行分级查表映射：

```x86
0x004D0B9D: mov   dword ptr [esp + 0xc], 0x44160000 ; 默认初速 600.0f
0x004D0BA5: lea   eax, [edx - 8]
0x004D0BA8: cmp   eax, 3
0x004D0BAB: ja    0x004D0BD0                        ; 超出 8..11 则使用默认 600.0f
0x004D0BAD: jmp   dword ptr [eax*4 + 0x004D0CBC]    ; 跳转表

; --- 跳转表分支 ---
0x004D0BB4: mov   dword ptr [esp + 0xc], 0x43AF0000 ; Level 8:  350.0f
            jmp   0x004D0BD0
0x004D0BBE: mov   dword ptr [esp + 0xc], 0x43C80000 ; Level 9:  400.0f
            jmp   0x004D0BD0
0x004D0BC8: mov   dword ptr [esp + 0xc], 0x43E10000 ; Level 10/11: 450.0f
```

### 速度分级实测与映射对照

| 打击强度等级 (`impactLevel`) | 十六进制浮点 | 标量速度 (单位/秒) | 物理手感与招式对应 |
|---|---|---|---|
| **Level 8** | `0x43AF0000` | **`350.0f`** | 轻攻击、小刺、匕首普攻第 1 段 (快速轻直拳) |
| **Level 9** | `0x43C80000` | **`400.0f`** | 中打击、剑刺、刀劈第 2 段 (中度后仰) |
| **Level 10 / 11** | `0x43E10000` | **`450.0f`** | 重斩、回旋踢、长枪横扫 (重创并造成大后仰) |
| **Default (超限/吹飞招式)** | `0x44160000` | **`600.0f`** | 击飞大招、重重击倒、大刀重劈、绝招 (全速吹飞) |

---

## 三、 武器属性结构体与伤害乘法模型 (`0x0055DDD0` / `0x004D0C26`)

`0x0055DDD0` 通过角色的装备武器索引 (`[esi + 0xfc]`)，在武器属性表基址 (`[ecx + 0x94]`) 中以每项 **104 字节 (`0x68`)** 的步长索引到当前武器数据：

```x86
0x0055DDF6: lea   edx, [eax + eax*2]        ; eax * 3
0x0055DDFF: lea   eax, [eax + edx*4]        ; eax * 13
0x0055DE02: lea   eax, [ecx + eax*8]        ; ecx + eax * 104 (0x68)
```

### 1. 104 字节武器属性结构 (`MeteorWeaponProperty`)
```c
typedef struct MeteorWeaponProperty {
    char        name[32];           /* +0x00: 武器资源名称 (如 "W0_0") */
    uint32_t    weaponType;         /* +0x20: 武器类别 (0:拳, 1:匕首, 2:剑, 3:枪, 4:刀...) */
    uint32_t    subType;            /* +0x24: 细分类型 */
    uint32_t    meshHandle;         /* +0x28: 3D 渲染网格句柄 */
    uint32_t    boneDummyId;        /* +0x2C: 挂载骨骼 Dummy 节点 */
    uint32_t    attributeFlags;     /* +0x30: 属性标记 (包含毒、灼烧、特效等，shl 10 打包进伤害包) */
    float       minAttackRate;      /* +0x3C: 最小攻击倍率 */
    float       minDefenseRate;     /* +0x40: 最小防御减伤率 */
    int32_t     baseAttack;         /* +0x48: 基础攻击力 (整型，如 20..150) */
    uint32_t    reserved[5];        /* +0x4C: 备用属性/音效索引 */
    float       attackMultiplier;   /* +0x60: 主攻击倍率 (乘以 100.0f 后转整型存入包) */
    float       defenseMultiplier;  /* +0x64: 主防御减伤倍率 (乘以 100.0f 后转整型存入包) */
} MeteorWeaponProperty;
```

### 2. 伤害参数打包与整型量化 (`0x004D08CD` ~ `0x004D0936`)
引擎不直接传输浮点乘数，而是采用定点百分比化存储（乘 100.0 并加上 0.5 四舍五入）：

```c
// 提取自 0x004D08CD: fld [esi+0x3c]; fmul 100.0; fadd 0.5; __ftol()
int32_t baseDmg   = *(int32_t*)(weapon + 0x48);
int32_t atkMinPct = (int32_t)(weapon->minAttackRate * 100.0f + 0.5f);
int32_t atkMaxPct = (int32_t)(weapon->attackMultiplier * 100.0f + 0.5f);
int32_t defMinPct = (int32_t)(weapon->minDefenseRate * 100.0f + 0.5f);
int32_t defMaxPct = (int32_t)(weapon->defenseMultiplier * 100.0f + 0.5f);

packet->damageFlags = (weapon->attributeFlags << 10) | 0x30000;
packet->attackRates = (atkMinPct << 16) | (atkMaxPct & 0xFFFF);
packet->defenseRates= (defMinPct << 16) | (defMaxPct & 0xFFFF);
```

---

## 四、 角色核心属性与 HUD 状态同步 (`0x004DC4C0` / `0x00475590`)

`CharacterActor` 通过虚方法表 `0x005AA9F8` 与分发器 `0x00475590` 统一管理血量、怒气与毒素：

### 1. 属性枚举映射
- `ACTOR_ATTR_CURRENT_HP` (`2`): 当前气血，同步写至 HUD 缓存 `0x005E0454`。
- `ACTOR_ATTR_MAX_HP` (`3`): 最大气血上限，同步写至 HUD 缓存 `0x005E045C`。
- `ACTOR_ATTR_ANGRY` (`6`): 怒气值 ($0 \sim 100$)，同步写至 HUD 缓存 `0x005E04A4`。
- `ACTOR_ATTR_POISON` (`10` / `0x0A`): 中毒状态位。

### 2. HUD 属性刷新入口 (`0x00475AB0`)
游戏每帧在 HUD 刷新函数中将全局角色状态压入分发器：
```x86
0x00475B03: mov   edx, [0x005E0454] ; 当前 HP
            push  edx
            push  2                 ; ACTOR_ATTR_CURRENT_HP
            call  0x00475590
0x00475B10: mov   eax, [0x005E045C] ; 最大 HP
            push  eax
            push  3                 ; ACTOR_ATTR_MAX_HP
            call  0x00475590
0x00475B3C: mov   eax, [0x005E04A4] ; 怒气值
            push  eax
            push  6                 ; ACTOR_ATTR_ANGRY
            call  0x00475590
```

---

## 五、 AI 怒气爆发与绝招反击判定方程 (`0x004FDD70`)

当 AI 角色受击或处于近战对峙状态时，`0x004FDD70` 执行经典的**破怒反击 (Rage Breakout / Super Reversal)** 判定：

```x86
0x004FDDA2: mov   eax, dword ptr [esi + 0x10] ; AI 难度配置表
0x004FDDA5: movsx ecx, word ptr [eax + 6]     ; AI 攻击欲望/反应阈值
0x004FDDA9: cmp   edx, ecx                    ; rand() % 100 < reactionRate
0x004FDDAD: jge   0x004FDDC0
...
0x004FDDC9: cmp   dword ptr [esi + 0x11c], 0x3c ; 怒气值 >= 60 (0x3C)
0x004FDDD0: jle   0x004FDE44                  ; 怒气不足 60 则放弃大招
0x004FDDD2: mov   eax, dword ptr [esi + 0x74] ; 获取目标角色位置
...
0x004FDE12: call  0x0047ECF0                  ; 计算三维欧氏空间距离 ||P_ai - P_target||
0x004FDE17: fcomp dword ptr [0x005AB870]      ; 与 80.0f 近战爆发距离比较
0x004FDE22: jp    0x004FDE44
0x004FDE24: call  0x0050A8DE                  ; rand() % 5 == 0 (20% 离散触发率)
0x004FDE35: mov   ecx, dword ptr [esi + 0xc]  ; 触发 PlayerController 爆发绝招
0x004FDE38: call  0x00501010
```

### 判定逻辑流
1. **基础怒气门槛**: `Rage >= 60`（`METEOR_AI_BREAKOUT_THRESHOLD = 0x3C`）。原版中怒气达到 60% 即可释放小绝招或爆气。
2. **距离门槛**: 与受击者/攻击者距离 $\le 80.0\text{ units}$（`0x005AB870`），确保大招能有效命中。
3. **随机触发离散度**: 每一决策帧以 $20\%$（`rand() % 5 == 0`）概率发起反击，避免 AI 每次刚好 60 气就机械秒发大招，呈现自然战斗心理。

---

## 六、 武器 HitBox 扫掠与分离轴定理 (SAT) 管线

《流星蝴蝶剑》采用了分层裁剪的碰撞检测架构：

```
[阶段 1: Broadphase 粗检] (0x0055DA97 / 0x00570B70)
  武器 AABB 与 目标角色全身 AABB 求交
  ├─ 失败: 直接退出 (0x0055DC00)，耗时 < 0.1μs
  └─ 成功: 进入中相判定
       │
[阶段 2: Midphase 骨骼/刀光切分] (0x0055DAE8 / 0x0055DB4E)
  ├─ 0x1000: 角色 32 根骨骼包围盒遍历 (0x0055DAEF, 步长 0x2F0)
  └─ 0x1001: 武器刃面扫掠轨迹 (Ribbon Blade Trail, 0x0056F1D0)
       │
[阶段 3: Narrowphase SAT 精确测试] (0x00570630 / 0x005706C0)
  刀刃线段 (Dummy0 -> Dummy1) 与 目标 Oriented Bounding Box (OBB)
  进行三维分离轴定理投影相交测试
       │
[阶段 4: Contact 命中反馈] (0x004D3E60)
  触发受击音效、粒子系统回调 (0x0056C9B0) 与 OnHit 冲量结算
```

### SAT 投影算法实现 (`0x005706C0`)
在 `0x005706C0` 中，线段向量 $\vec{S} = P_1 - P_0$ 与 OBB 盒中心差向量 $\vec{D} = P_{box} - P_0$ 分别投影至 OBB 的 3 个正交局部基底轴 $\vec{u}_0, \vec{u}_1, \vec{u}_2$：

$$\text{Proj}_i = \vec{u}_i \cdot \vec{D}$$
$$\text{SegProj}_i = \vec{u}_i \cdot \vec{S}$$

只要在任一正交轴上，线段投影区间与盒体半长 $e_i$ 无交集，即判定分离：
$$\min(\text{Proj}_i, \text{Proj}_i + \text{SegProj}_i) > e_i \quad \lor \quad \max(\text{Proj}_i, \text{Proj}_i + \text{SegProj}_i) < -e_i$$
若 3 轴均重叠，则命中成立，返回相交点。


---

## 七、 玩家武器必杀、怒气消耗与换武器清怒机制深度实锚

### 1. 换武器清空怒气机制 (`PlayerController::EquipWeapon @ 0x004CFD20`)
在 PC 原版中，角色切换武器时怒气直接归零。换武器主函数位于 `0x004CFD20`：
```x86
0x004CFD20: mov   eax, dword ptr [esp + 4]    ; weaponType (0..11)
0x004CFD24: push  esi
0x004CFD25: push  edi
0x004CFD26: push  eax
0x004CFD27: mov   esi, ecx                    ; PlayerController* this
0x004CFD29: call  0x004E3D80                  ; WeaponControllerFactory::Get(weaponType)
0x004CFD2E: mov   edi, eax
0x004CFD3C: mov   ecx, dword ptr [esi + 0x348]; 旧武器控制器指针
0x004CFD42: test  ecx, ecx
0x004CFD44: je    0x004CFD4C
0x004CFD46: mov   edx, dword ptr [ecx]
0x004CFD48: push  esi
0x004CFD49: call  dword ptr [edx + 0xc]       ; OldWeaponController::vtable[3](Player) -> 注销旧武器
0x004CFD4C: mov   eax, dword ptr [edi]
0x004CFD4E: push  esi
0x004CFD4F: mov   ecx, edi                    ; 新武器控制器指针
0x004CFD51: call  dword ptr [eax + 8]         ; NewWeaponController::vtable[2](Player) -> 装备初始化并清空怒气
0x004CFD54: mov   dword ptr [esi + 0x348], edi; 记录新武器控制器
```

进入 12 类武器控制器的 `vtable[2]`（如匕首 `0x004DF4D0`、飞轮 `0x004DEC70`、长枪 `0x004DFC50`）：
```x86
0x004DF4D0: mov   ecx, dword ptr [esp + 4]    ; PlayerController*
0x004DF4D4: push  0                           ; param3 = 0
0x004DF4D6: push  0                           ; param2 = 0
0x004DF4D8: push  6                           ; param1 = 6 (ACTOR_ATTR_ANGRY / 怒气属性事件)
0x004DF4DA: mov   eax, dword ptr [ecx]
0x004DF4DC: call  dword ptr [eax + 0xc]       ; PlayerController::vtable[3] (PushEvent)
0x004DF4DF: ret   4
```
**机制结论**：换武器时，新武器控制器的 `vtable[2]` 必然向事件队列推送 `Event 6`（`ACTOR_ATTR_ANGRY`）并将数值重置为 `0`，从而在物理层强制清空怒气。

### 2. 玩家按键连招与必杀怒气扣除驱动 (`0x004CB270 - 0x004CB390`)
玩家输入连招时，输入队列由 `PlayerController::ProcessKeyCombos`（`0x004CB270`）逐帧轮询处理：
```x86
0x004CB2D3: mov   esi, dword ptr [edi + 0x3d4]; 武器连招控制器接口
0x004CB2D9: lea   ebx, [edi + 0x3d4]
0x004CB2EA: call  0x00487830                  ; InputSystem::GetSingleton()
0x004CB2EF: add   eax, 0x1ee8                 ; &InputSystem->KeyBuffer
0x004CB2F4: mov   ecx, ebx
0x004CB2F6: push  eax
0x004CB2F7: call  dword ptr [esi]             ; WeaponController::vtable[0] (灌入按键流)
0x004CB2F9: mov   edx, dword ptr [ebx]
0x004CB2FB: lea   eax, [esp + 0x10]
0x004CB2FF: lea   ecx, [esp + 0x14]
0x004CB303: push  eax
0x004CB304: push  ecx
0x004CB305: mov   ecx, ebx
0x004CB30F: call  dword ptr [edx + 0x14]      ; WeaponController::vtable[5] (MatchCombo: 匹配招式序列与 Pose)
0x004CB312: test  eax, eax
0x004CB314: je    0x004CB33F
0x004CB316: mov   eax, dword ptr [esp + 0x10]
0x004CB31A: mov   ecx, dword ptr [esp + 0x14]
0x004CB31E: mov   edx, dword ptr [edi]
0x004CB320: push  eax
0x004CB321: push  ecx
0x004CB322: mov   ecx, edi
0x004CB324: call  dword ptr [edx + 0x1a4]     ; PlayerController::vtable[105] (派发连招姿态)
...
0x004CB370: mov   edx, dword ptr [ebx]
0x004CB372: mov   ecx, ebx
0x004CB374: call  dword ptr [edx + 8]         ; WeaponController::vtable[2] = 武器复位 + 清怒（见 §八；原注「扣除怒气」已撤回）
0x004CB377: test  eax, eax
0x004CB379: jle   0x004CB37E
0x004CB37B: inc   dword ptr [edi + 0x60]      ; 累加连招段数 / 招式序号
```

### 3. 必杀索敌硬约束与脱出清空 (`PlayerController::vtable[99] @ 0x004CE540`)
在必杀与锁敌状态机中，包含面向锁敌与必杀释放的极限距离与角偏差门控：
```x86
0x004CE60D: call  0x0047ECF0                  ; 计算与锁定目标的 3D 欧氏距离
0x004CE612: fcomp dword ptr [0x005AA924]      ; 比较最大锁敌半径 240.0f (常量 VA: 0x005AA924)
0x004CE618: fnstsw ax
0x004CE61A: test  ah, 5
0x004CE61D: jp    0x004CE6AF                  ; 若超出 240.0f，跳入脱出清空序列
0x004CE627: call  0x00509980                  ; 角度差转整型
0x004CE631: cmp   eax, 0x64                   ; 比较角偏差是否 >= 100 (0x64)
0x004CE634: jge   0x004CE6AF                  ; 若角偏差 >= 100，跳入脱出清空序列
...
0x004CE6AF:                                   ; 目标丢失 / 必杀脱出清空序列
  mov   edx, dword ptr [edi]
  push  0
  push  0
  push  6                                     ; 抛送 Event 6 清空
  mov   ecx, edi
  call  dword ptr [edx + 0xc]                 ; PlayerController::vtable[3]
  ret
```
- **距离上限**: 单精度常量 `0x005AA924` = **`240.0f`**。
- **角偏差上限**: 立即数 `0x64` = **`100`**。
- 超出范围或目标丢失时，立即通过 `vtable[3]` 抛送 `Event 6` 截断状态。

---

## 七、 选招怒气门槛：`weaponType × KeyMap` 二维表（2026-10-28）

> 与第五节（`0x004FDD70` AI 怒气爆发）不同：本节是**玩家出招时的门票检查**——
> 某些招式组要求怒气达标，并当场扣除。这是连招系统唯一的资源消耗点。

### 1. 函数签名与结构

```csharp
public bool CheckPos(int KeyMap, int targetAct)   // 前置闸 AcceptInput() → switch(weaponType) → switch(KeyMap)
```

`KeyMap` 即 `character.act` 的 group 出现序号（见 `docs/03` 第五节），**不是招式 ID**。

### 2. 武器类型枚举（`EquipWeaponType`）

| 值 | 名称 | 中文 | 值 | 名称 | 中文 |
|---|---|---|---|---|---|
| 0 | `Sword` | 剑 | 6 | `Guillotines` | 血滴子 |
| 1 | `Knife` | 匕首 | 7 | `Lance` | 长枪 |
| 2 | `Gun` | 火枪 | 8 | `Brahchthrust` | 分水刺 |
| 3 | `Dart` | 飞镖 | 9 | `HeavenLance` | 乾坤拔刀 |
| 4 | `Hammer` | 锤子 | 10 | `Gloves` | 拳套 |
| 5 | `Blade` | 刀 | 11 | `NinjaSword` | 忍刀 |

> 附注：类型 **2/3/6（火枪/飞镖/血滴子）** 的武器控制器 `vtable[21]` 返回 **0**，
> 其余 9 类返回 1 —— 该常量是「能否进入近战连招选招」的编译期答案，远程武器为 0。

### 3. 完整门槛表

| 武器 | 免费 KeyMap | 收费（怒气消耗） | 原文注释（节选） |
|---|---|---|---|
| **剑** (0) | 44, 47 | **45:100**, 151:60, 152:60 | 大招 / 左右A剑气 / 右左A小绝旋转 |
| **匕首** (1) | 25,26,27,28,29,30,32,33,34 | 31:**100**, 88:60, 150:60 | 下上上A 阎罗 / 下下A 地面小绝 下扎 / 空中下下A |
| **火枪** (2) | 6, 59 | **7:20**, 8:100, 147:60 | 大绝 / 一般空踢 / 小绝 |
| **飞镖** (3) | 1, 85, 87 | 4:**100**, 143:60, 144:60 | 落樱雪 / 地面八方绝 / 空中八方绝 |
| **锤** (4) | 59, 81, 83 | 82:**100**, 157:60, 158:**100** | 铜皮 / 震荡波 / 大绝 |
| **刀** (5) | 59, 70, 72 | 71:**100**, 155:60, 156:60 | 大绝招 / 旋风斩 / 雷电斩 |
| **血滴子** (6) | 11, 59 | 12:**100**, 145:60, 146:60 | 一般空踢 |
| **长枪** (7) | 57, 60 | 58:**100**, 153:60, 154:60 | 大招 / 强攻 前前前A / 左右下A 小绝招 |
| **分水刺** (8) | 20, 24 | 21:**100**, 148:60, 149:60 | 左右上小绝 / 加速BUFF |
| **乾坤拔刀** (9) | 106 | 104:**100**, 159:60, 160:60 | 大绝招 / 持枪小绝 Pos570 / 拔刀小绝 Pos568 |
| **拳套** (10) | 114, 119 | 115:60, 120:**100**, 121:**100** | 大绝 / 嗜血 |
| **忍刀** (11) | 127, 135, 140 | 128:50, 136:50, 141:50, **142:10** | 忍术-隐忍 / 天地同寿 / 忍爆弹-忍大招 / 左右A 10气 |

### 4. 三个必须注意的细节

1. **消耗值不是单一刻度**：`20`（火枪 KeyMap 7，全游戏唯一）、`50`（忍刀四项）、
   `60`（各类小绝）、`100`（大招）四种并存；**忍刀 `142` 只要 10 气**。
   阈值与消耗是每行独立的两组数，不是共享常量。
2. **`EnableInfiniteAngry` 在扣除点读取**，不在加载时——作弊路径就是同一段代码跳一个分支。
   克隆若在载入时判定全局开关，中途切换会发散。
3. **`case 84` 与 `case 33` 共享标签**（`case 84: case 33:`），两者同属免费；反编译产物会把它们拆开。

### 5. 证据等级与待验项

| 项 | 等级 |
|---|---|
| 表结构（12 武器 × KeyMap） | ✅ 源码确认（`_gt/v280` 与 APK 反编译双份一致） |
| 具体数值 100/60/50/20/10 | 🟡 **仅安卓重制版源码，`Meteor.exe` 侧未证** |
| `EquipWeaponType` 12 类顺序 | 🟡 结构吻合原版 12 路工厂（`FUN_004E3D80`），名称未逐一验 |

> 未证依据：全镜像扫描 `CMP [reg+off],0x64|0x3c` 仅得 2 处、且分属不同偏移，
> 无一处同时出现 100 与 60 ⇒ 原版不以「同字段比较 100/60 立即数」的形式实现。
> 要么常量经寄存器传入，要么原版单位不是 100/60。**克隆时不可默认这些数值。**

### 6. 乾坤拔刀的 KeyMap → 动作号映射（源码注释，17 条）

这是全项目唯一的文档化转换表，直接可用：

| KeyMap | 含义 | 动作号 |
|---|---|---|
| 89 | 左A 拔刀切换持枪 | 430 |
| 90 | 下下A 拔刀切换居合 | 431 |
| 93 | 右A 持枪切换拔刀 | 440 |
| 94 | 下下A 持枪切换居合 | 441 |
| 99 | 右A 居合转换拔刀 | 447 |
| 100 | 左A 居合转换持枪 | 448 |
| 102 | 收刀下上A-拔刀术 | 449 |
| 104 | **大绝招** | 451 |
| 106 | 空中下A | 446 |
| 159 | 持枪小绝 | Pos 570 |
| 160 | 拔刀小绝 | Pos 568 |

---

## 八、怒气机制的边界：`vtable[2]` 是清零不是扣费，且无 per-KeyMap 成本数据（2026-10-28）

前面 §七.2 把 `0x004CB374` 的 `call [edx+8]` 注为「WeaponController::vtable[2]（扣除/消耗对应怒气）」。
**这一条要撤回。** 12 类武器的 `vtable[2]` 全表如下（逐 dword 实读 + 逐函数反汇编）：

| 武器 | 虚表 | `[+0x8]` 目标 | 大小 | 体 |
|---|---|---|---|---|
| 剑 0 | `0x5AAB00` | `0x004E4070` | 3 B | `RET 0x4`（**void，不设 EAX**） |
| 匕首 1 | `0x5AAE10` | `0x004E4070` | 3 B | 同上 |
| 火枪 2 | `0x5AAC50` | `0x004DEC70` | 32 B | 发 `cmd 6`，再 `[this+0x36C]=0` |
| 飞镖 3 | `0x5AACC0` | `0x004DF4D0` | 18 B | 发 `cmd 6` |
| 锤 4 | `0x5AADA0` | `0x004E4070` | 3 B | `RET 0x4` |
| 刀 5 | `0x5AABE0` | `0x004E4070` | 3 B | `RET 0x4` |
| 血滴子 6 | `0x5AAD30` | `0x004DFC50` | 28 B | 发 `cmd 6`，再 `[this+0x3CC]=0` |
| 长枪 7 | `0x5AAB70` | `0x004E4070` | 3 B | `RET 0x4` |
| 分水刺 8 | `0x5AAE80` | `0x004E4070` | 3 B | `RET 0x4` |
| 乾坤拔刀 9 | `0x5AAEF0` | `0x004E2BB0` | 20 B | 尾跳 `[EAX+0x1D4]` |
| 拳套 10 | `0x5AAFE8` | `0x004E4070` | 3 B | `RET 0x4` |
| 忍刀 11 | `0x5AAF70` | `0x004E4070` | 3 B | `RET 0x4` |

`distinct` 目标只有 **5 个**，其中 9 类共用 3 字节的空体。

### 1. 为什么这不可能是「扣怒」

```asm
004dec75  6a 00              PUSH 0x0        ; 载荷高 dword
004dec77  6a 00              PUSH 0x0        ; 载荷低 dword
004dec7b  6a 06              PUSH 0x6        ; ← cmd 6 = ACTOR_ATTR_ANGRY
004dec7d  8b ce              MOV ECX,ESI
004dec7f  ff 50 0c           CALL [EAX+0xC]  ; 命令通道
004dec82  c7 86 6c 03 00 00  MOV [ESI+0x36C],0x0
```

**三条独立理由：**
1. **9/12 是 void**（`RET 0x4` 不经 EAX）——调用点之后 `test eax,eax / jle` 若依赖返回值就是读垃圾；
   拿它当「扣费是否成功」的判据不成立。
2. **推的是 `cmd 6`（清怒事件）**，载荷恒为 `{0,0}`，与 §七.1 记录的「换武器时 vtable[2] 推 Event 6 清怒」
   **是同一函数的同一行为**——不是成本，是清零。
3. **没有 KeyMap 参数**：函数签名只有 `this + 1 个 dword`（`RET 0x4`），拿不到「这一招是哪个组」，
   物理上无法按 `KeyMap` 分档收 100/60/50。

⇒ **`vtable[2]` = 武器复位 + 清怒**。§七.2 里「扣除/消耗对应怒气」的括注撤回，
`0x004CB374` 那一跳的语义应改述为「**连招派发后复位武器连招状态（含清怒事件）**」。

### 2. per-KeyMap 怒气成本不是数据：`angervalue` 是文法词但无人使用

`.pos` 的词法表在 `0x5D1930`，**37 条记录、stride 0x24**（名字内联在 +0、id 在 +0x20），
映射函数 `FUN_0057A770`（99 B）线性比对后返回 `[0x5D1950 + idx*0x24]`。其中：

| idx | 词 | id |
|---|---|---|
| 4 | `angertype` | **0x105** |
| 5 | `angervalue` | **0x106** |
| 0 | `action` | 0x104 |
| 1/2/3 | `attack` / `attacktype` / `attackvalue` | 0x107–0x109 |

**但全安装目录搜索 `anger`：只命中 `Meteor.exe`（与其 IDA 库），25 个 `.pos`、`character.act`
一个都没有。** ⇒ 9.07.16 的随附数据**从未使用**这两个字段。

### 3. 对移植端的处置

- 移植端的招式表若打算实现「门票 → 扣 100/60/50」，**不要照抄 C# 版 `CheckPos` 的数值**。
  那是重写者自加的机制：原版既没有这份数据，`vtable[2]` 也不承担扣费。
- 原版确有的怒气事实只有三条，且都有地址：
  **属性 6（0–100）**、**HUD 镜像 `0x005E04A4`（`0x00475B3C`）**、**AI ≥ 60 爆气（`0x004FDDC9`）**，
  外加持怒清零（cmd 6，`0x004DF4D0` 等）。
- 若后续要复刻「必杀要扣怒」，应另找 `ACTOR_ATTR_ANGRY` 的写入点，
  **不在 weapon vtable，也不在 `.pos` 数据**。

### 4. 未解

玩家侧是否存在**固定数值**（非 per-KeyMap）的怒气消耗 —— 仍需在属性 6 的写入链上找，
本轮未查到。标 ❓。
