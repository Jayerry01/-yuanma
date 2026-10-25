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
