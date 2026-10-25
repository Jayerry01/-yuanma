# 《流星蝴蝶剑.net》动作招式脚本 (character.act) 与状态机逆向解析

## 一、 character.act 结构体系与 Flex/Bison 解析器

在 `Meteor.exe` 中，程序在初始化角色骨骼时调用 `0x004E82E0`，进而触发 `0x00574930` 载入 `Common\character.act`：

```c
// Meteor.exe 0x004E82E0 汇编追踪
FUN_00574930("common\\character.act");
iVar1 = FUN_00574460("common\\character.amb");
if (iVar1 == 0) {
    FUN_00574460("common\\character.amc");
}
```

逆向发现，昱泉开发团队在 `Meteor.exe` 中内置了一套标准 **Flex / Bison (Lex/Yacc)** 词法与语法分析器：
- 字符串 `fatal flex scanner internal error--no action found` (`0x005D1E64`)
- 关键字表: `KEY_action`, `KEY_defensepose`, `KEY_targetpose`, `KEY_attack`

---

## 二、 内存数据结构 (Memory Layout)

解析后在堆中分配两个平坦的 STL 连续动态数组：

### 1. 姿势数组 (Pose Table, 8 字节/项)
- 对应 `character.amb` 动画帧片段：
```c
struct PoseDef {
    int16_t startFrame;  // 动画起始帧编号
    int16_t endFrame;    // 动画终止帧编号
    int16_t loopStart;   // 循环帧 (-1 表示单次播放)
    int16_t flags;       // 动作标签掩码
};
```

### 2. 招式动作数组 (Action Table, 20 字节/项)
```c
struct ActionDef {
    int32_t actionId;      // 招式 ID
    int32_t poseId;        // 绑定的 Pose ID
    int32_t nextPoseId;    // 自然完结后连携的下一 Pose
    float   blendDuration; // 骨骼融合过渡时间 (通常 0.08f ~ 0.12f)
    int32_t flags;         // 判定标志 (攻击/防御/浮空/受创)
};
```

---

## 三、 匕首招式 (Dagger Combo Groups) 官方原版配置对照

从原版客户端 `Common\character.act` 提取的完整匕首招式组：

| 招式组编号 | 对应 Pose 范围 | 招式名称 | 连携机制与特性 |
| :--- | :--- | :--- | :--- |
| **group(248-249)** | Pose 248 -> 249 | 匕首轻击一、二段 | 快速近身挥刺，第 8 帧开放连携窗口 |
| **group(250-251)** | Pose 250 -> 251 | 匕首轻击三、四段 | 交叉横抹接反手挑刺，第 10 帧开放连携 |
| **group(253)** | Pose 253 | 匕首重刺 (重击) | 单段突刺，造成目标僵直 |
| **group(370-371)** | Pose 370 -> 371 | 碧血凌空 (空中重刺) | 空中快速下潜刺地，击中后产生震地冲击波 |
| **group(255)** | Pose 255 | 鬼影迷踪 (匕首绝技) | 多段位移穿梭连斩，全身无敌帧判定 |
| **group(257-258)** | Pose 257 -> 258 | 暗杀背刺 | 敌后贴身发动背刺致盲与大伤害判定 |
| **group(259)** | Pose 259 | 阎罗判命 (破防斩) | 强制破开敌方防御状态，击退目标 |
| **group(245-247)** | Pose 245..247 | 匕首防御姿势与防守受击 | 245=防守待机, 246=轻防受击, 247=重防硬直 |
| **group(252)** | Pose 252 | 拔出匕首 | 武器切换动作 |
| **group(256)** | Pose 256 | 收起匕首 | 卸除武器动作 |

---

## 四、 招式取消窗口与动作中断解析引擎 (`0x004D1740`)

在 `PlayerController::vtable[149]`（`0x004D1740`）中，引擎实现了招式中断取消规则解析器：

### 1. 取消关键字与十六进制位掩码映射表 (`0x4D1899 - 0x4D1A08`)
当解析 `character.act` 中每个 Action 的 Cancel 规则块时，逐一比对以下 13 个关键词：

| 动作取消关键字 (Keyword) | 内存字符串地址 | 对应位掩码 (Hex) | 功能定义与应用场景 |
|---|---|---|---|
| `"Attack"` | `0x005C91FC` | **`0x1000`** | **攻击连招取消**: 在有效攻击帧后提前连入下一段招式 |
| `"Guard"` | `0x005C9CDC` | **`0x0020`** | **防御取消 (防守收招)**: 收招后摇强行拉防御中断 |
| `"Jump"` | `0x005C9CD4` | **`0x1200`** | **跳跃取消 (小跳取消)**: 滞空/后摇由跳跃动作切入 |
| `"SwitchWeapon"` | `0x005C9CC4` | **`0x0045`** | **切武器取消**: 拔刀/切刀强制切入换武器动作 |
| `"Unlock"` | `0x005C9CBC` | **`0x0051`** | **解控/解除锁定**: 退出当前自动锁定视角与动作 |
| `"DropWeapon"` | `0x005C9CB0` | **`0x0047`** | **丢武器取消**: 卸除当前手持兵刃 |
| `"Fake"` | `0x005C9CA8` | **`0x0059`** | **虚招/佯攻取消**: 动作前摇假动作骗招收手 |
| `"RightTurn"` | `0x005C9C9C` | **`0x0027`** | **右转取消**: 快速向右扭头/转体中断 |
| `"LeftTurn"` | `0x005C9C90` | **`0x0025`** | **左转取消**: 快速向左扭头/转体中断 |
| `"DropItem"` | `0x005C9C84` | **`0x0048`** | **丢弃道具取消** |
| `"Cure"` | `0x005C9C7C` | **`0x0054`** | **服药/疗伤取消**: 吃包子/解毒打断 |
| `"Crouch"` | `0x005C9C74` | **`0x0043`** | **蹲下取消**: 蹲姿受控中断 |
| `"InitialCamera"` | `0x005C9C64` | **`0x004C`** | **重置视角取消**: 强制校准摄像机朝向 |
| `"Fool"` | `0x005C9C5C` | **`0x0052`** | **挑衅/嘲讽取消**: 播放嘲讽动作中断 |
| `"Score"` | `0x005C9C54` | **`0x0009`** | **收招评分取消**: 绝招收式评分结算 |
| `"HitAttack"` | `0x005C9C48` | **`0x0046`** | **命中确认追加攻击取消**: 击中目标后允许派生追加连击 |

### 2. 帧区间语法分析与计算式 (`0x004D1A1C - 0x004D1AAC`)
`character.act` 中的帧区间支持两种声明格式：
1. **绝对帧格式**: `Cancel <Type> <StartFrame>`
2. **延展相对帧格式**: `Cancel <Type> <StartFrame> + <Duration>`
   - 在 `0x004D1A5A` 处通过 `f3 a6 repe cmpsb` 检查下一个 Token 是否为字符串 `"+"`（地址 `0x005C9C44`）。
   - 若命中 `"+"`，则读取后续的 `<Duration>` 并与 `<StartFrame>` 相加，得出最终终止帧 `EndFrame = StartFrame + Duration`。
   - 通过 `0x0049C330` 注入到当前动作的取消窗口映射红黑树中。
