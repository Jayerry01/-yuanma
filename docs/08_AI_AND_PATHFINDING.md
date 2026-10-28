# 《流星蝴蝶剑.net》NPC 决策树、仇恨系统与寻路状态机逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，基址: `0x00400000`)  
> **代码来源**: `10_AI_Controller_FSM.c`（经 Ghidra 12.1.4 真实反编译，共 9,720 行）  
> **核心函数定位**:
> - `0x0040A2A0`: `AIController::UpdateDecisionTree`（NPC 核心思考主时钟）
> - `0x0040B0C0`: `AIController::EvaluateTargetHostility`（仇恨值与距离评估）
> - `0x0040C040`: `AIController::SelectComboAction`（招式派发与难度权重表）
> - `0x0040D040`: ~~`AIController::NavigateToWaypoint`（路网节点巡航与避障）~~
>
> ⚠️ **2026-10-28：以上四个命名全部作废**，且 `0x0040D040` 不是函数入口（落在一条指令内部）。
> 真实形态见 **§五 重定位**：NPC 行为写在 `Level\*.pst` 脚本里，路网写在 `Level\*.wp`。

---

## 一、 既往伪模型撤回：不存在硬编码的「5 宏观状态」与「cos ≥ 0.5」

> ❌ **彻底证伪并撤回**：早前草稿中记载的「0巡逻/1警戒/2战斗/3防御/4寻物」5 宏观状态机与「cos ≥ 0.5 视场」在 `Meteor.exe` **根本不存在**。经二进制逐指令扫描（见 §五.1–§五.5），所谓 `0x40A2A0`/`0x40C040` 均为世界网格与关卡求交函数，非 AI 决策；百分比难度矩阵亦为移植重写版的臆测。

---

## 二、 原版 PC 二进制的真实 AI 架构：脚本驱动的 8 大原生行为

`Meteor.exe` 的真实 AI 并非硬编码状态机，而是由 **`Level/*.pst` 脚本驱动 + 原生派发器 `0x004F8F60` (`ChangeBehavior`)** 承载的 **8 大行为对象体系**（详见 `docs/13` §四）：

| 行为名 (字符串) | 名字 VA | 原生行为对象 | 装载入口 | 运行时语义与参数契约 |
|---|---|---|---|---|
| **`wait`** | `0x5CA11C` | `0x503970` | `0x4FD5B0` | 停止当前动作，原地待命等待触发 |
| **`idle`** | `0x5CA114` | `0x5039F0` | `0x4FD5B0` | 常规闲置与呼吸动画循环 |
| **`run`** | `0x5CA110` | `0x503D00` | `0x4FD5B0` | 逃跑/疾跑位移 |
| **`follow`** | `0x5CA108` | `0x503B30` | `0x4FD5B0` | 跟随指定目标玩家/队友 |
| **`patrol`** | `0x5CA100` | `0x503A00` | `0x4FD5B0` | **路网巡逻**：变长参数灌入 `[EBX+0x108]` 向量（如 `ChangeBehavior(g_self,"patrol",12,15,20)` 沿路点 12→15→20 巡游） |
| **`attacktarget`** | `0x5CA0F0` | `0x504A70` | `0x4FD630` | 索敌进攻：锁定 TargetPos 目标槽 [0..9] 并将第 4 参写入 `[ESI+0x88]` |
| **`kill`** | `0x5C9858` | `0x504670` | `0x4FD630` | 死斗决杀：无视撤退阈值全力击杀目标 |
| **`dodge`** | `0x5CA0E8` | `0x504560` | `0x4FD630` | 受击/遇险翻滚闪避（结果写入 `[this+0x74]`） |

### 行为参数来源（全量数据化，非常量）
每个 NPC 思考频率与行为偏好由 `Level/npc*.pst` 动态注入 18 个整数：
- `View`（索敌视野半径）、`Think`（思考间隔毫秒/Tick）
- `Attack1/2/3`（普攻/连招/绝招权重）
- `Guard` / `Dodge` / `Jump` / `Look` / `Burst` / `Aim` / `GetItem` / `Spawn` / `HP`

---

## 三、 关卡路网与寻路导航 (`0x0040D040`)

关卡中的 AI 寻路依托 `Level/*.pst` 脚本定义的 Waypoint 路标点系统：
1. **路标点连通图 (Waypoint Graph)**: 每个路标包含世界坐标、连接邻居索引与通过类型（步行/轻功跳跃）。
2. **转向与速度解算**: AI 根据当前路标与目标路标的向量差，模拟生成摇杆推力矢量（`inputVector`），驱动与玩家完全一致的物理移动接口，杜绝了“瞬移或穿墙”假 AI。

---

## 四、 参考实现索引：iOS/安卓源码侧的 NPC 行为机（2026-10-28）

> 本节不是逆向结论，而是**答案在哪里**的登记。此前本域只有三个入口地址（`0x40A2A0` / `0x40C040` /
> `0x40D040`）且未验证，看上去像空白域。实际上第三方重写工程里有**可直接阅读的等价实现**，
> 规模 120 KB / 14 个行为状态。**用法：拿它当假设源，用 `Meteor.exe` 当判据。**

### 1. 实现位置与规模

| 文件 | 大小 | 作用 |
|---|---|---|
| `_gt/master/meteor_original_ios-master/Assets/Meteor/AI/State.cs` | **65,002 B** | 14 个行为状态的完整实现 |
| `.../AI/StateMachine.cs` | **55,729 B** | 状态机骨架与转移 |
| `.../AI/RVOController.cs` | 5,381 B | 局部避障（RVO） |
| `.../AI/WayPoints.cs` | 360 B | 路点标记 |

命名空间：`Idevgame.Meteor.AI`。基类 `State`，派生 14 类。

### 2. 14 个行为状态（含源码行号）

| # | 类 | 行 | 语义 |
|---|---|---|---|
| 1 | `IdleState` | 6 | 待机 |
| 2 | `WaitState` | 31 | 等待（计时/条件） |
| 3 | `GuardState` | 69 | 防御/警戒 |
| 4 | `DodgeState` | 96 | 闪避 |
| 5 | `KillState` | 238 | 击杀动作 |
| 6 | `ReviveState` | 307 | 复活 |
| 7 | `PatrolState` | **337** | **巡逻（本文件最大一段，约 370 行）** |
| 8 | `LookState` | 707 | 观察/环视 |
| 9 | `PickUpState` | 802 | 拾取 |
| 10 | `FaceToState` | 936 | 转向目标 |
| 11 | `FindState` | 991 | 搜索目标（仇恨入口候选） |
| 12 | `FollowState` | 1078 | 跟随 |
| 13 | `FightState` | 1242 | 战斗（选招/走位） |
| 14 | `AttackState` | 1368 | 攻击执行 |

### 3. 与本域三个入口地址的对应关系（待逐条验证）

| 本域已有地址 | 疑对应源码位置 | 验证方法 |
|---|---|---|
| `0x0040A2A0`（思考循环） | `StateMachine` 的 per-frame tick | 比对状态枚举数量与转移表规模 |
| `0x0040C040`（难度矩阵/连招权重） | `FightState` / `AttackState` 内的权重选择 | 搜 0–3 之类小整数权重表 |
| `0x0040D040`（路网/寻路） | `PatrolState` + `WayPoints` + `RVOController` | 比对路点结构与避障半径常量 |

> ⚠️ **不要直接把源码当原版结论。** 该工程是「用 unity 重新写的仿造工程」，权重数值与状态划分
> 都可能被重写者调整（对照 `docs/00` 第三节：物理常量已证实被改过）。
> 源码的价值是**给出结构假设**，数值仍须 `Meteor.exe` 侧确认。

### 4. 建议的推进顺序

1. 先验 `0x0040A2A0` 是否真是 per-frame AI tick（`RET` 元数 + 是否被 GameApp 主循环调用）；
2. 若成立，再验它的状态枚举空间是否 ≥14（比对跳表/比较链）；
3. 最后逐状态核对 `FightState` / `AttackState` 的选招逻辑是否与本项目已确认的
   `KeyMap → group → action` 同构（见 `docs/03` 第五节）——**若同构，说明 AI 与玩家共用选招器**，
   这是最有价值的单点结论。


---

## 五、重定位（2026-10-28）：NPC 行为在 `.pst` 脚本里，不在 exe 的 FSM 里

本节推翻本文档前四节的**前提**。结论一句话：**原版的「决策树 / 仇恨 / 难度权重 / 寻路」不是
C++ 状态机，是每个 NPC 一份 `.pst` 脚本 + 每张地图一份 `.wp` 路点数据。**

> 📌 **2026-10-28 续**：VM 本体已完全解出，**见 `docs/13_PSCRIPT_VM.md`**。
> 关键三条：① 内建函数 26 个，逐个硬注册于 `0x004F8950`；
> ② `ChangeBehavior` 实为 `0x004F8F60` 内的 8 分支线性 `strcmp`
> （`wait/idle/run/follow/patrol/attacktarget/kill/dodge`）；
> ③ AI 权重（`View`/`Think`/`Attack1..3`/`Guard`/`Dodge`/`Jump`/`Burst`/`Aim`/`Spawn`）
> 是**运行时从脚本全局按名读取**（`0x00571660`），不是二进制常量。
> ④ **目标选择**不是引擎内建的仇恨系统，是脚本自己管的：
> `SetTarget(槽,"char",角色)` / `SetTarget(槽,"waypoint",路点号)` 写
> `0x666858` 那张 10 槽 Vec3 表，`Distance(槽A,槽B)` 读它比距离
> （瞄角色时 Z 自动 +30.0 抬到上身高度；瞄路点不抬）。
> 见 `docs/13` §十一。

### 1. 「四定位三真一假」——假的是 `0x0040D040`，而且它不是函数

| 地址 | 是否函数入口 | 大小 | 元数 | 唯一调用者 |
|---|---|---|---|---|
| `0x0040A2A0` | ✅ 是 | 2,274 B | `RET`（0 参） | thunk `0x00408EF0`（5 B）← `FUN_00408DA0` |
| `0x0040B0C0` | ✅ 是 | 49 B | `RET`（0 参） | `FUN_004A44D0` |
| `0x0040C040` | ✅ 是 | 752 B | `RET`（0 参） | `FUN_0040BBE0`（1,111 B，18 个不同调用者） |
| **`0x0040D040`** | ❌ **否** | — | — | **0 处引用，不是跳转目标** |

`0x40D040` 落在 `FUN_0040CD10`（1,695 B）+0x330，而那里**连指令边界都不是**：

```asm
0040d03e  8b 6c cd 04   MOV EBP,dword ptr [EBP + ECX*0x8 + 0x4]   ; 6 字节，止于 0040D044
0040d042  89 6c 90 1c   MOV dword ptr [EAX + EDX*0x4 + 0x1c],EBP
```

`0x40D040` 落在上面那条 6 字节指令**内部**。⇒ 它从来不是一个地址点，是从某份 listing 里
读错列读出来的。

### 2. 三个「真」的定性也不成立

- **`0x40A2A0` 不是「NPC 核心思考主时钟」。** 它唯一的进入路径是
  `FUN_00408DA0`（289 B）→ thunk → 它；而 `FUN_00408DA0` 做的是
  **按 `[node+0]` 的类型码派发**：先在 `[arg+0x150]` 上沿 `[node+8]` 扫一条链表找成员，
  然后 `CMP dword ptr [ESI],0x1 / JNZ` 分叉。这是**对象类型分派**，不是主循环。
- **`0x40A2A0` 自身首段是空间查询**：`SUB ESP,0x1A8`（424 B 栈帧）→ 4 参调用
  `FUN_00406ED0`（890 B，标志位 `| 0x02000000`）→ `EDI=8` 的 8 次迭代调 `FUN_00431FD0`。
  形状像扫描/求交，不像状态机。
- **整条 `0x40xxxx` 区带更像关卡/世界子系统**：全局 `[0x005D5A00]` 在该区带被
  **100+ 个函数**读取（`0x406ED0`、`0x40BBE0`、`0x40C330`… 一律以 `MOV EAX,[0x5D5A00]` 开头），
  而它的写者只有 `FUN_004038A0`（3 处）与 `FUN_00404040`（1 处）。

⇒ **`AIController::*` 这套命名整体作废**，它们是世界/关卡层的函数。

### 3. 真正的 AI 锚点在字符串上（字节级 xref）

| 字符串 | VA | 引用者 | 大小 | 元数 |
|---|---|---|---|---|
| `"Load NPC %s.pst error"` | `0x005C9B18` | **`FUN_004BF910`** | 748 B | `ends 00` |
| 〃 | 〃 | `FUN_004F9D60` | 54 B | `RET(0)` |
| `"Level\%s_.pst"` | `0x005C9AEC` | **`FUN_004BF650`** | 665 B | `ends 00` |
| `"Load %s.wp error"` | `0x005C9AFC` | `FUN_004BF910` / `FUN_004BF650` | 〃 | 〃 |
| `"%s.wp"` | `0x005C9BEC` | **`FUN_004C2DE0`** | 1,515 B | `ends ad` |
| `"Waypoints %d\n"` | `0x005C9BBC` | **`FUN_004C2C40`** | 404 B | `RET(0)` |
| `"RemoveNPC"` | `0x005C9FF0` | `FUN_004F8950` | 882 B | `ends 00` |

配套字符串还有 `"PscriptLib\jug.pst"` / `"chair.pst"` / `"desk.pst"` / `"box.pst"` / `"def.pst"`
（场景道具的脚本）与 `"%s%s.pst"`。

**分工猜想（🟡 待验）**：`FUN_004BF650` 读关卡级 `Level\<名>_.pst`，`FUN_004BF910` 负责
`.pst` + `.wp` 的成对装载与报错，`FUN_004C2DE0` 单独解析 `.wp`，`FUN_004C2C40` 打印路点数。

### 4. 数据形态（原件，非产物）

安装目录 `app\Level\` 下：**110 个 `.pst`、21 个 `.wp`**。`npc01_01.pst`（513 B，Big5 文本）原文：

```
string Name = "鐵槍哨兵．甲";
int Model = 8;      int Weapon = 7;   int Weapon2 = 0;  int Team = 2;
int View  = 400;    int Think  = 40;
int Attack1 = 50;   int Attack2 = 30; int Attack3 = 0;
int Guard = 20;     int Dodge = 10;   int Jump = 5;     int Look = 10;
int Burst = 2;      int Aim = 60;     int GetItem = 3;  int Spawn = 53;
int HP = 1000;

int g_selfAddr;  int g_self;
OnInit(int this) { g_selfAddr = this; }
OnStart() { g_self = GetSelf(g_selfAddr); ChangeBehavior(g_self, "wait"); }
```

**这是行为权重表，不是 exe 里的常量。** 它带 `OnInit` / `OnStart` / `GetSelf` / `ChangeBehavior`
四个钩子 ⇒ 该二进制里有一台**脚本 VM**（PscriptLib）。

`sn01.wp`（7,856 B，文本）结构：

```
WayPoints 81
Pos -18.589 19.913 184.125
Size 40
Link 8
1 0 156.762
2 0 149.044
...            ; 每个 WayPoint 一段：Pos / Size / Link N / N 行邻居
```

即：路点 = `Pos`（世界坐标）+ `Size`（到达半径）+ `Link`（邻居数）+ 每个邻居
`(索引, ?, 距离)`。第三个字段待定名。

### 5. 对 §二「难度矩阵」的处置

§二 那张 15% / 45% / 85% 的表**不是原版**：原版是**每个 NPC 一份整数权重**
（`View 400 / Think 40 / Attack1 50 / Attack2 30 / Guard 20 / Dodge 10 / Jump 5 / Look 10 /
Burst 2 / Aim 60 / GetItem 3 / Spawn 53`），随 `.pst` 走。百分比形态来自重写版，撤回。

同样旧草稿的「5 个宏观状态」与「视场 cos ≥ 0.5」已彻底证伪并撤除，真实体系为 `0x004F8F60` 的 8 大原生行为。

### 6. 下一步（按收益排序）

1. 反汇编 `FUN_004BF650` / `FUN_004BF910`，确认 `.pst` 的装载与 VM 注入顺序；
2. 找 `ChangeBehavior` 的实现 —— 它的第二个参数是字符串（`"wait"`），
   **行为名 → 行为表**的映射就是「状态机」的真身，且**在数据里**；
3. 读 `FUN_004C2DE0` 解 `.wp` 三字段的语义（尤其邻居行第三个 float）。
