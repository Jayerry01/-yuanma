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
