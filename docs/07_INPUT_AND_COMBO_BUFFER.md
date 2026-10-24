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
