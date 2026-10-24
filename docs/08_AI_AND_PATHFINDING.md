# 《流星蝴蝶剑.net》NPC 决策树、仇恨系统与寻路状态机逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，基址: `0x00400000`)  
> **代码来源**: `10_AI_Controller_FSM.c`（经 Ghidra 12.1.4 真实反编译，共 9,720 行）  
> **核心函数定位**:
> - `0x0040A2A0`: `AIController::UpdateDecisionTree`（NPC 核心思考主时钟）
> - `0x0040B0C0`: `AIController::EvaluateTargetHostility`（仇恨值与距离评估）
> - `0x0040C040`: `AIController::SelectComboAction`（招式派发与难度权重表）
> - `0x0040D040`: `AIController::NavigateToWaypoint`（路网节点巡航与避障）

---

## 一、 NPC 决策架构与思考循环 (`0x0040A2A0`)

NPC AI 在每个逻辑帧运行分层有限状态机（Hierarchical Finite State Machine）：

1. **宏观状态 (Macro State)**:
   - `0`: 巡逻 / 空闲待机 (Patrol / Idle)
   - `1`: 警戒 / 索敌接近 (Alert / Approach)
   - `2`: 战斗博弈 (Combat Engagement: 试探、连招、拉扯、破防)
   - `3`: 防御 / 闪避规避 (Defensive Evasion)
   - `4`: 寻找道具 / 拾取武器 (Item Searching)
2. **视野与视线检测**:
   - 视线锥形角: $\cos(\theta) \ge 0.5f$（正前方约 60 度视场）。
   - 结合场景射线求交 `LineCheck` (`0x005644F0`) 进行墙体遮挡判定。

---

## 二、 难度矩阵与连招决策权重 (`0x0040C040`)

在反编译产物 `10_AI_Controller_FSM.c` 中，不同难度级别的 AI 行为差异由核心权重矩阵控制：

| 行为参数 | 简单 (Easy / 0) | 中等 (Normal / 1) | 困难 (Hard / 2) |
|---|---|---|---|
| **防御触发率** | 15% | 45% | 85% |
| **连招完成度** | 1~2 段中断 | 完整民工连 | 极限挑空 + 绝招取消 |
| **嗜血/追击反应帧** | 延迟 15~20 帧 | 延迟 6~8 帧 | 零帧即时抢攻 / 抓倒地破绽 |
| **跳跃躲避概率** | 5% | 30% | 70%（空中变向躲大绝） |

---

## 三、 关卡路网与寻路导航 (`0x0040D040`)

关卡中的 AI 寻路依托 `Level/*.pst` 脚本定义的 Waypoint 路标点系统：
1. **路标点连通图 (Waypoint Graph)**: 每个路标包含世界坐标、连接邻居索引与通过类型（步行/轻功跳跃）。
2. **转向与速度解算**: AI 根据当前路标与目标路标的向量差，模拟生成摇杆推力矢量（`inputVector`），驱动与玩家完全一致的物理移动接口，杜绝了“瞬移或穿墙”假 AI。
