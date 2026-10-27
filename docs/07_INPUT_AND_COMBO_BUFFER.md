# 《流星蝴蝶剑.net》输入轮询、按键缓冲队列与搓招识别系统逆向规范

> **二进制基准**: `Meteor.exe` (2002 原版，基址: `0x00400000`)  
> **代码来源**: `08_Input_Combo_Buffer.c`（经 Ghidra 12.1.4 真实反编译）  
> **核心函数定位**:
> - `0x00486270`: `InputSystem::PollDeviceState`（DirectInput 设备轮询与 Win32 消息同步）
> - `0x00486A80`: `InputSystem::ProcessKeyQueue`（循环环形按键事件队列推入与老化）
> - `0x00487830`: `InputSystem::GetInputSingleton`（输入管理器单例访问点）
> - `0x00488130`: `InputSystem::MatchComboSequence`（连招指令模式匹配器：如 `AA`, `↓↑A`, `←→A`）

---

## 一、 输入状态机与环形缓冲队列

在 `08_Input_Combo_Buffer.c` 中，输入子系统维持一个容量为 32 个槽位的环形事件缓冲区（Circular Event Buffer）：

```c
typedef struct {
    uint16_t keyCode;      /* 按键虚拟键码 (方向键 / 攻击 / 跳跃 / 防御) */
    uint16_t eventType;    /* 0 = KeyUp, 1 = KeyDown, 2 = KeyHold */
    uint32_t frameStamp;   /* 触发时的物理帧计数器 (用于时间窗口计算) */
} InputKeyRecord;
```

- **采样周期**: 随游戏主循环在 `0x00486270` 进行每帧 1 次的同步采样。
- **老化机制**: 超过容差时间窗口（通常为 12 帧，即 400ms）的历史按键记录在 `0x00486A80` 中被标记为过期并被环形头指针覆盖。

---

## 二、 搓招模式匹配逻辑 (`0x00488130`)

《流星蝴蝶剑》的核心招式触发依赖指令序列的时序状态匹配：

1. **按键编码映射**:
   - `KEY_UP` (前): `0x01`
   - `KEY_DOWN` (后): `0x02`
   - `KEY_LEFT` (左): `0x04`
   - `KEY_RIGHT` (右): `0x08`
   - `KEY_ATTACK` (轻击/A): `0x10`
   - `KEY_HEAVY` (重击/大绝): `0x20`
   - `KEY_JUMP` (跳): `0x40`
2. **时序序列匹配 (Sequence Matching)**:
   - 以经典招式“下上A”（`↓↑A`）为例：
     - 检测栈顶最近按键是否为 `KEY_ATTACK`；
     - 向前回溯历史记录，在 $[t - 8, t]$ 帧内寻找 `KEY_UP`；
     - 再向前回溯，在 $[t_{up} - 8, t_{up}]$ 帧内寻找 `KEY_DOWN`；
     - 若三者均在时间容差窗内连续满足且未插入非法冲突键，匹配成功。
3. **招式分发与动作覆盖**:
   - 匹配成功后，调用当前角色的动作控制器，将目标招式的 Pose ID（通过 `character.act` 映射）注入角色有限状态机。
   - 若角色当前处于不可打断的后摇动作，指令将被暂存在预输入寄存器（Buffer Register）中，在当前动作的 `CanCancel` 帧自动触发。

## 三、 离散键事件入口、四通道命令层与攻击命令落点（2026-10-28，字节级实锚）

### 1. 唯一离散键入口 `FUN_004CB820` (1,009 B, `RET 0x8`)
所有离散按键（含鼠标）只从这里进入：**先无条件发 `cmd 0x31`**（8 B `{key, pressed}`），
再按 keyCode 分派——`0x20–0x47` → 40 项跳表 `0x4CBC14`（字节索引 `0x4CBC40`）；
`0x49–0x54` → 12 项表 `0x4CBC68`（索引 `0x4CBC80`）；`0x1000/0x1200` 由 `CMP` 直判（攻击/跳跃动作码）。

### 2. 攻击分支（`0x1000`）——纯按下沿 + 双闸
`TEST EBX,EBX; JZ`（**释放不做任何事**）→ 闸1 slot111 `FUN_004D0D90`（`[this+0x10] && [this+0x34C]`）
→ 闸2 slot109 `FUN_004CE2D0`（`[this+0x348]->vtable[21]()`）→ 载荷 slot37（实体句柄）→ `PUSH 0x1D`。
函数内唯一字符串 `"Active Attack"`（`0x5C9C34` → GameApp slot 172），仅此分支引用。
跳跃（`0x1200`）**不对称**：按下 slot67→slot31，释放也处理（`CALL [EDX+0x104]`）。

### 3. 四通道事件记录器（非状态快照）
| cmd | 载荷 | GameApp 槽 | 队列方法 | 落队列（280 B 移动组件, vfptr `0x5AA660`） |
|---|---|---|---|---|
| `0x31` | 8 B {key,pressed} | 220 | 10 | 12 B @+0x18 |
| `0x32` | 12 B 摇杆 A | 221 | 11 | 12 B @+0x48 |
| `0x34` | 12 B 摇杆 B | 222 | 12 | 16 B @+0x38 |
| `0x33` | 16 B {fwd,right,cnt,x} | 223 | 13 | 8 B @+0x28 |

四类各进各队列，由 per-frame tick（slot 19）统一排空。**方向缓冲 `this+0x2E8` 有两个写者**
（tick 轴驱动 `'f'/'b'/'l'/'r'` + 键事件 `FUN_004CBCE0` 经 vtable slot 24、字符走栈参数
`MOV [ECX],BL @0x4CBD41`）——克隆必须做**跨写者去重**。

### 4. `cmd 0x1D` 落点（已裁定）：`FUN_004BC710` (402 B, SEH)
三基址裁定：派发器 `FUN_004BB800` 的 `this` vfptr = **`0x5A9FE0`**（唯一被 case 0x33 →
`FUN_004BC100 @+0x1E8` 交叉验证的基），slot 31（`+0x7C`）= `FUN_004BC710`。
内部：懒建设置单例 `[0x5E0328]`（0x33C，ctor `0x44D020`——**与键位轮询器 `FUN_00503020` 共用同一实例**）
→ 快照 `FUN_0045A450`（`rep movsd`×5、字段至 +0xE8、`+0xEC` 起 0x1A dword）→ 门 `cfg+0xC8`
→ `FUN_004F1960`（15 B 两跳转发：`vtable[17]` → 尾 JMP 子对象 `vtable[109]` @+0x1B4）。
**未解**：子对象 `vtable[109]` 的落点（第三跳）。

### 5. 槽位正典与移植端三条硬要求
- 槽位正典基 = `0x5AA658`（PlayerController，150 方法）：`FUN_004CF5B0` = slot 86（+0x158）、
  `FUN_004CF540` = slot 85（+0x154）、`FUN_004CE100` = slot 65（+0x104，力竭滑落）；
  移动组件子对象虚表 `0x5AA6A8` 对同一段 run 以 **−18 槽** 重索引。引用槽位必须写
  `base + index` 加解析后地址（方法论第 10 条）。
- **攻击 = 带双闸的沿事件**（按帧采样鼠标按下必双发）；**攻击无释放路径、跳跃必有**（原版不对称）；
  **方向缓冲按 {tick, 键沿} 双源去重**，且是带 capacity 的可增长字节数组。
