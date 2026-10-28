# 14 · 跨文档对账台账（2026-10-28 建立）

> **本文件是"关于账本的账本"**：不承载领域结论，只登记
> ① 编号占用与规则 ② 已撤回/证伪清单 ③ 全局未闭合清单 ④ 跨文档一致性风险。
> 领域结论一律写在对应的 `docs/NN_*` 里，本文件只做索引与对账。
>
> 建立动机：2026-10-28 单日新增内容量大、中途推翻过自己三次，
> 且发生**两次编号撞车**（详见 §一）。

---

## 一、编号占用表（**新建文档前必查**）

⚠️ **编号空间不只 `.md`** —— `docs/12` 被一个 `.json` 占用。

| 编号 | 文件 | 类型 | 建立时间 |
|---|---|---|---|
| `00` | `00_INSTALLATION_ASSET_AND_FORMAT_SPEC.md` | md | — |
| `01` | `01_PE_ARCHITECTURE_AND_MEMORY.md` | md | — |
| `02` | `02_PLAYER_CONTROLLER_AND_PHYSICS.md` | md | — |
| `03` | `03_ACTION_POSE_AND_ACT_PARSER.md` | md | — |
| `04` | `04_COMBAT_HIT_AND_DAMAGE.md` | md | — |
| `05` | `05_ANIMATION_AMB_FORMAT.md` | md | — |
| `06` | `06_LEVEL_BSP_AND_COLLISION.md` | md | — |
| `07` | `07_INPUT_AND_COMBO_BUFFER.md` | md | — |
| `08` | `08_AI_AND_PATHFINDING.md` | md | — |
| `09` | `09_CAMERA_AND_EFFECT_SYSTEM.md` | md | — |
| `10` | `10_TEXT_COVERAGE_AUDIT.md` | md | 2026-10-27 |
| `11` | `11_BEHAVIORAL_EQUIVALENCE.md` | md | 2026-10-28 04:28 |
| `12` | `12_COMMAND_PROTOCOL_SPEC.json` | **json** | 2026-10-28 04:30 |
| `13` | `13_PSCRIPT_VM.md` | md | 2026-10-28（原误编为 11、12，两次让位） |
| `14` | `14_CROSSDOC_AUDIT.md`（本文件） | md | 2026-10-28 |
| `15` | `15_COMMUNITY_PATCHES_NETWORKING_AND_ANTICHEAT.md` | md | 2026-10-28 |
| `16` | `16_COMMUNITY_SDK_AND_ASSET_SPECS.md` | md | 2026-10-28 |
| `17` | `17_MILESTONES_AND_COMPLETION_ROADMAP.md` | md | 2026-10-28 |
| `18` | `18_QINGGONG_PHYSICS_AND_MOVEMENT_EXPLOITS.md` | md | 2026-10-28 |

**规则**（已写入项目 `MEMORY.md`）：
1. 新建文档前先 `ls docs/` —— **含非 `.md` 文件**。
2. 撞号时**后来者让位**，先占者保留；让位后必须全量修引用（`grep -rn` 复查）。
3. 让位记录要写进本文件 §一，避免下次再踩。

### 本次两次撞车经过

| 次序 | 我用的号 | 实际占用者 | 处置 |
|---|---|---|---|
| 1 | `11_PSCRIPT_VM.md` | `11_BEHAVIORAL_EQUIVALENCE.md`（早 19 分钟） | 改为 12，修 `docs/00`、`docs/08` 两处引用 |
| 2 | `12_PSCRIPT_VM.md` | `12_COMMAND_PROTOCOL_SPEC.json`（早 50 分钟） | 改为 13，再修一遍引用 |

---

## 二、已撤回 / 证伪登记（集中索引）

| # | 原结论 | 现判定 | 出处 | 日期 |
|---|---|---|---|---|
| 1 | `0.11` 是「无量纲比例」 | ❌ **单位是秒**（QPC/QPF），持跳阈值 | `docs/02` | 2026-10-28 |
| 2 | 怒气按招式收取（100/60/50/20/10） | ❌ **原版不存在**：数据层零命中、`vtable[2]` 是清零非扣费 | `docs/04` §八 | 2026-10-28 |
| 3 | 内置 API 含 `PlaySound()` | ❌ **不存在**，全镜像零命中 | `docs/00` §9 / `docs/13` §九 | 2026-10-28 |
| 4 | 引擎 VM 在 `0x004BFCA0`–`0x004C0500` | ❌ **不是函数入口**（首 4 字节 `00000000`，后接尾声） | `docs/00` §9 / `docs/13` §九 | 2026-10-28 |
| 5 | AI 难度矩阵 15% / 45% / 85% | ❌ **重写版形态**，原版是 `.pst` 整数权重 | `docs/08` §二 | 2026-10-28 |
| 6 | `METEOR_CAMERA_MAX_DISTANCE = 180.0f` | ❌ **是空中冲刺初速度**（`docs/02` 早记对了） | `docs/09` §二·补 A | 2026-10-28 |
| 7 | `LineCheck 0x5644F0` 用于相机防穿墙 | ❌ **无调用关系支持**（9 个调用点全在玩家/场景侧） | `docs/09` §二·补 B | 2026-10-28 |
| 8 | `0x0040D040` = `AIController::NavigateToWaypoint` | ❌ **连指令边界都不是** | `docs/08` §五 | 2026-10-28 |
| 9 | `cmd 0x0F` 元数谜题 | ❌ 撤销（基址错） | 当日记录 | 2026-10-28 |
| 10 | `docs/18`："大跳 = 持续注入垂直冲量至峰值" | ❌ **与 `docs/02` 字节证据冲突**：实为两档**单发**初速（<0.11s→282.0f `0x4CF573`；≥0.11s→375.0f `0x4CF57F`）。另 `docs/18` §1.2–1.4 的 `CheckCollision`/`m_bWallContact`/`STATE_WALL_RUN`/`m_nJumpCount` 均为社区命名非二进制符号，"FPS<137"解释无锚点存疑 → 已在 `docs/18` 头部加证据分级标注 | `docs/18` §1.1/二 | 2026-10-28 |
| 11 | `CLONE_SPEC.md` §1.6 将 `0x0056BC60` 定性为“战斗/动画属性键值系统”（Named-attribute data model） | ❌ **实为脚本内建函数 `SetSceneItem`**（`docs/13` §六），负责关卡物件属性绑定 | `docs/13` §六 | 2026-10-28 |
| 12 | `CLONE_SPEC.md` §1.0 将 `FUN_0045B280` 定性为“Combat core / damage 裁决” | ❌ **实为控制台配置/命令字符串编排器**（`CLONE_SPEC` 后续已自撤，`docs/04` 裁决核心为 `0x004D0AC0`） | `docs/04` / `CLONE_SPEC` §1.19 | 2026-10-28 |
| 13 | `docs/03` §四 原将 `0x004D1740` 解析的 16 个动作取消代码称为“对应位掩码 (Hex)” | ⚠️ **汇编证实为标量枚举类型码**：`0x004D1740` 中为 `MOV EBP, imm` 覆盖写入标量，无 `OR/AND` 位累加，实为动作类型枚举标量而非位域掩码（`docs/03` 已更正） | `docs/03` §四 | 2026-10-28 |
| 14 | `docs/09` §F 早场推断："`[EBP+0x2488]` 每实例相机对象虚表 = `0x005AA658`（150 方法）"、"`0x492D80` 扇出调 `0x004D0AC0`（相机方法）"、"`[EDI+0x2960]` = 相机兄弟链表（已闭合）" | ❌ **三连错，全部撤回**：① `0x004D0AC0` 体内有 **4 档击退速度跳表 `0x4D0CBC`（350/400/565/600.0f）+ `SHL 0xA;OR` 旗标打包**，semqueue 归 `04_COMBAT` 域 ⇒ 实为 ProcessDamage（`docs/04` §二），相机类不可能携带伤害结算——**报告 #12 引 `docs/04` 是对的**；② `[EBP+0x2488]` 虚表 = `0x5A9FE0`（`docs/09` §F 第 248 行原闭合，slot[115]=`0x4BB4B0` 实读吻合），`MOV [ECX],0x005AA658` 与该成员无绑定证据；③ `0x5AA658`-run 内部 `0x5AA6A8` 起为控制器类子表（SetState `0x4D0500`@其 slot[75] 实测吻合，同簇含 `0x4CB820` 命令处理〔07_INPUT 域〕）⇒ 该 run 是**玩家控制器类**非相机类；④ 转发器实际调 `0x5A9FE0[69]=0x4F0C50`，`[EDI+0x2960]` 链表定性**恢复 ❓**。`docs/09` §F 两行已改写 | `docs/04` §二 / `docs/09` §F / `evidence/camera_vtable.txt` | 2026-10-28 |

> **模式总结**：14 条里有 9 条属于同一类错误 —— **把"推断/重写版形态"当成了原版事实**。
> 其中 #6 尤其说明问题：`docs/02` 早就把 180/260 记成速度了，
> `docs/09` 却另起一套"相机距离"的推断，**同项目内两个文档对同一常量给出两种定性，
> 且都写了地址**，直到本次对账才发现。#14 则是反向案例：**一个函数体里有"重浮点+向量调用"
> 就套"相机 Update"模板，而没有先查该函数是否已有关联域与特征结构（跳表/旗标打包）**——
> 与既有语义账本（semqueue Cite 列）对表只需一行 grep，跳过这一步就会造出第 14 条。

---

## 三、跨文档一致性检查（本轮已查项）

| 检查项 | 结果 |
|---|---|
| `0x005714E0`（VM 内建注册器） | ✅ 仅在 `docs/00`、`docs/13` 出现，口径一致 |
| `0x004F8F60`（`ChangeBehavior`） | ✅ `docs/08` 作索引指向、`docs/13` 作正文，无冲突 |
| `0x00571660`（AI 属性取数器） | ✅ 同上 |
| `0x005A84C0` `=180.0f` | ⚠️ **曾冲突**：`docs/02`=速度（对）、`docs/09`=相机距离（错）→ 已更正并互引 |
| `0x00666858`（目标点表） | ✅ 只在 `docs/13` §十一，无重复 |
| `0x0056E490`（`PonEF` 加载器） | ✅ 只在 `docs/09`，未与别处冲突 |
| 行为表（8 个行为名） | ⚠️ `docs/08` §五 有概述、`docs/13` §四 有全表 —— **概述可接受，但需保持 `docs/13` 为权威** |
| 37 条 `.pos` 文法关键词 | ✅ 只在 `docs/03` §七 |
| `docs/13` §四 内"12 字节语义未解 ❓" | ⚠️ **陈旧标记**，§十一 已解开 → 本轮已修 |

### 本轮修掉的 3 个问题

1. 编号撞车 ×2（见 §一）
2. `docs/09` 的 `180.0f` 定性错误，并与 `docs/02` 冲突 → 更正 + 双向互引
3. `docs/13` §四 的陈旧 ❓ 与 §十一 自相矛盾 → 改为指向 §十一

### 第二轮：`12_COMMAND_PROTOCOL_SPEC.json` 专项比对

| 检查项 | 结果 |
|---|---|
| 规格声称的 `sha256` | ✅ 与 `Meteor.exe` **逐位一致**（`baebb6d5…86 19`），同一二进制 |
| `dispatch.this_vfptr = 0x5A9FE0`（225 方法） | ✅ 独立复扫 = 225 项，吻合 |
| `jump_table = 0x004BBFE8`（51 项，索引 `cmd−3`） | ✅ **51/51 全部落在 `.text`**，断言通过 |
| 与 `docs/07`（`cmd 0x31`，8 B `{key,pressed}`） | ✅ 一致，无冲突 |
| 与 `docs/13` §五（动作名词汇） | ⚠️ **层次未界定** → 已在本轮补"输入命令通道 / 动作名"两层对照表 |

**结论：该规格可信，且是本项目中少见的"带完整结构锚"的高质量记载。**

### 第二轮顺带查出 `docs/02` 的 3 个问题

| # | 问题 | 处置 |
|---|---|---|
| 1 | **章节号重复**：「六」出现两次（原 234 / 301）、「八」出现两次（原 273 / 368） | ✅ 后两节重编为 **十 / 十一**，现一～十一连续 |
| 2 | **数据产物缺失**：`dyncap/capture_log.jsonl` 在 `D:\MeteorRE` 下**不存在**（全目录搜 `*.jsonl`、`dyncap*` 均无），而 `docs/02`（3 处）与 `docs/11`（2 处）共 5 处引用它 | ⚠️ 已加标记：143,550 事件**不可复现**，可信度低于静态证据 |
| 3 | **引用移植端源码作断言依据**：原 §7 写「断言字段统一用移植端 `MeteorFsmRunner`（见 `JumpDispatch.cs`）」 | ✅ 改为原版可观测字段（`moveState`/`PoseId`/`vel`/`wall`/`grounded`/方向缓冲）并留更正说明 |

---

## 四、全局未闭合清单（合并各文档 ❓）

### A. 脚本 VM 域（`docs/13`）

| 项 | 状态 |
|---|---|
| ~~`attacktarget` 第 4 参写入的 `+0x88` 语义~~ | ✅ **闭合（2026-10-28）**：攻击重复执行计数器（`attack_count`）。若 `>0`，判定门限放宽至 80.0f（`0x5AB870`）；若 `≤0`，使用常规 40.0f（`0x5A8E7C`）。在有效距离与 30 度视角内触发 `0x500C90` 攻击，并执行 `dec [ESI+0x88]`，减至 0 时调用 `0x4FD870` 退出行为 |
| ~~中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值~~ | ✅ **闭合（2026-10-28）**：证实不存在 573 个 ActionID 派发表。`0x504BE0` 为 9 大 Perform 动作动词执行器；`0x504F50` 为 128 项 ASCII 矢量字形单字渲染器（索引 `0x5CA3A0`，1/16 缩放），由 `DrawVectorString`（`0x501815`）逐字调用 |
| ~~`block` 动作名的调用点~~ | ✅ **闭合（2026-10-28）** = 玩家动作队列执行器 `0x004C0730`（匹配后调 `0x004C3900` 即 `Player::SetBlock(0/1)`）；场景描述表 `0x005B0214`（阻挡碰撞属性） |
| ~~AI 属性"取两次"的含义~~ | ✅ **闭合（2026-10-28）** = 源码未暂存指针所致（`if (GetVar("X")) val = GetVar("X")->GetShort()`）。提取值写入 `ActorController` 的 14 项属性结构体（`View +0x430`、`Think +0x432`、`Guard +0x434`、`Dodge +0x436`、`Jump +0x438`、`Look +0x43A`、`Burst +0x43C`、`Aim +0x43E`、`GetItem +0x440`、`Attack1 +0x442`、`Attack2 +0x444`、`Attack3 +0x446`、`Spawn +0x448`、`HP +0x44A`） |
| ~~`0x5CA1FC` 连招键串池的消费方~~ | ✅ **闭合（2026-10-28）** = `FUN_004ff200`（`0x004FF200`–`0x005005A3`，5,028 字节）。这是 AI 武器招式出招库构建器（`AI_InitWeaponCombos`），为 12 种武器装配 15 种合法出招方向组合序列（`lrfb`、`bbf`、`bff`、`lrb`、`fff` 等共 77 处挂载） |
| ~~VM 是字节码还是 AST 直解~~ | ✅ **闭合（2026-10-28）** = 纯 AST 递归语法树遍历解释（Tree-Walk Interpreter），无字节码中间表示。`FunctionNode::Execute`（`0x00570F80`）遍历节点调虚表 Slot 2 `call dword ptr [edx+8]`；无字节码提取/调度循环 |
| 目标点表的**数值** | ❌ 静态不可得（`.data` 未初始化区） |

### B. 相机域（`docs/09`）

| 项 | 状态 |
|---|---|
| ~~相机对象 vtable 是 18 张候选中的哪一张~~ | ✅ **闭合**（2026-10-28）：`BaseCamera`=0x5AB670, `ChaseCamera`=0x5AB710, `ExtraCamera`=0x5AB7A8, `CameraManager`=0x5A9FE0 |
| ~~追尾相机每帧 Update 方法~~ | ✅ **闭合**（2026-10-28）：`ChaseCamera` 虚表 Slot 1 = `0x004F5FA0`（3,248 B 大函数，高精度计时驱动） |
| `[EDI+0x2960]` 链表元素类型 | ❓ **恢复待解（2026-10-28 晚更正）**：转发器 `0x492D80` 实际调用的为 `[EBP+0x2488]` 对象（虚表 `0x5A9FE0` CameraManager）的 slot[69] = `0x004F0C50`（非 `0x004D0AC0`）。元素类型需沿 `0x4F0C50` 的语义重推导（低优先级敞口） |
| ~~`40.0f` / `5.0f` 归属~~ | ✅ **闭合（2026-10-28）**：`40.0f`（`0x5A8E7C`）为追尾相机防穿墙最小视距下界（`0x004F6BF0`，与最大界限 `70.0f` 配对）及 AI 近战攻击门限；`5.0f`（`0x5A8F74`）为相机角速度平滑乘数及射线避让缓冲间距 |
| ~~`freecam`(`0x03`) / `dcam` 处理分支~~ | ✅ **闭合**（2026-10-28）：`freecam`=cmd 3 -> `0x4B6B47` -> 调 Slot 103 入模式 2；`dcam`=cmd 4 -> `0x4B6A44` |
| ~~`PonEF` 加载器 `0x0056E490` 调用方~~ | ✅ **闭合**（2026-10-28）：全 .text 唯一调用方 `0x00566348`（`EffectSystem::LoadEffectFile`） |

### C. 其他域

| 项 | 出处 | 状态 |
|---|---|---|
| ~~`Pose90` 是唯一可处于状态 4 的动作~~ | `docs/02` | ✅ **已证伪推翻**：cmd 0x35 派发器可在 `0x4D042B` 将任意指定动作置为状态 4 |
| ~~视场 `cos ≥ 0.5`、5 个宏观 AI 状态~~ | `docs/08` §一 | ✅ **证伪撤除**：二进制中无此结构，真实架构为 `docs/13` §四 的 8 大原生行为（`wait`/`idle`/`run`/`follow`/`patrol`/`attacktarget`/`kill`/`dodge`）与 `.pst` 18 属性 |

---

## 五、待办（本轮对账发现，尚未处理）

| # | 事项 | 优先级 |
|---|---|---|
| 1 | ~~比对 `12_COMMAND_PROTOCOL_SPEC.json` 与 `docs/07`/`docs/13`~~ | ✅ **已完成**，见 §三「第二轮」，结论：可信、无冲突 |
| 2 | ~~`dyncap/capture_log.jsonl` 产物缺失~~ | ✅ **已落盘**（2026-10-28，14.7 MB，144,101 事件，动态数据已闭环） | — |
| 3 | ~~`11_BEHAVIORAL_EQUIVALENCE.md` 内 4 处提到移植端工程名~~ | ✅ **已核，无需改**：该文本身就是"等价测试台"规格，移植端是**被测对象**（行 1/91/114/126/127），不是原版事实的证据来源，性质正当 |
| 4 | ~~`docs/02` §十一 的 `PoseId`(`+0x5E0`) / 方向缓冲(`+0x2E8`) 等偏移独立复扫~~ | ✅ **已闭合**（2026-10-28）：`tools/verify_community_offsets_5e0_2e8.py` 扫出 `+0x5E0` 命中 9 处（`0x0055BE13` `mov [esi+0x5e0], eax`，指令起点；工具打印的 `0x0055BE15` 为位移字段地址，系统性 +2）、`+0x2E8` 命中 136 处，汇编硬证据闭环 |
| 5 | ~~`CLONE_SPEC.md`（206 KB）向 `docs/` 单向归口~~ | ✅ **已完成（2026-10-28）**：43 章节三态处置清单落盘，CLONE_SPEC 降级为归档附录并加挂正典路由表 | — |

---

## 附：本轮对账的产出

- `docs/13_PSCRIPT_VM.md`（原 `11`/`12` 两次让位后定名）
- `docs/09` §二·补 A 增加与 `docs/02` 的互引
- `docs/13` §四 陈旧 ❓ 修正
- 本文件 `14_CROSSDOC_AUDIT.md`
- `MEMORY.md` 编号规则更新


---

## 六、CLONE_SPEC.md 全量 43 章节单向归口处置清单与方法论总纲

> 2026-10-28 依据 REAP 证据分级审计规范，对历史探索草案 `CLONE_SPEC.md`（3,044 行，206 KB）实施逐章单向归口审计。
> **五大审计铁律**：① 带证据才并入 ② 冲突以 docs/ 为准 ③ 无地址条目只进存疑附录 ④ 产物是三态处置清单 ⑤ 降级不删除。
> **处理总计**：全量 43 章节中，**已由 docs/ 覆盖并超越（废弃） 28 章**，**存疑/移植探索/历史自撤归档 13 章**，**并入正典/反向校准 2 章**。

### A. 全量 43 章节分流处置明细表

| 序号 | 章节原名 (Title in CLONE_SPEC) | 行号范围 | 判定状态 | 归口目标与处置说明 |
|---|---|---|---|---|
| 00 | `# Meteor.exe — Behavioral Clone Spec` | L1–L6 | 废弃 / 降级 | 早期草案头部，已加挂正典导航路由 Banner 降级为归档附录 |
| 01 | `## Rules (from REAP §4 — non-negotiable)` | L7–L12 | 废弃 / 归口 | 方法论规则，已由本项目 REAP 审计规范与本文件覆盖 |
| 02 | `## Status legend` | L13–L19 | 废弃 | 图例说明，已由各文档正文标记体系取代 |
| 03 | `## 0. Overview / Engine` | L20–L23 | 废弃 | 空白占位大纲，已由 `docs/00`、`docs/01` 取代 |
| 04 | `## 1. Combat` | L24 | 废弃 | 空白占位大纲，已由 `docs/04` 取代 |
| 05 | `### 1.1 Hit detection (判定帧)` | L25 | 废弃 | 空白占位大纲，已由 `docs/04` §一 攻击受击盒判定覆盖 |
| 06 | `### 1.2 Damage model (真实伤害)` | L26 | 废弃 | 空白占位大纲，已由 `docs/04` §三 伤害计算公式覆盖 |
| 07 | `### 1.3 Combo / chain system (连招)` | L27 | 废弃 | 空白占位大纲，已由 `docs/03` §五、`docs/07`、`docs/16` 覆盖 |
| 08 | `### 1.4 Hitstun / knockback / 部位判定` | L28 | 废弃 | 空白占位大纲，已由 `docs/04` §二 4级击退查表覆盖 |
| 09 | `### 1.5 Movement anchors / 位移` | L29–L30 | 废弃 | 空白占位大纲，已由 `docs/02`、`docs/18` 覆盖 |
| 10 | `### 1.0 Combat function anchors (static, evidence)` | L31–L69 | 存疑归档 | 早期基于字符串 Grep 的 43 函数粗筛，含多处暂定猜测角色（如误标 452af0 为武器FSM），已由正典全量反编译取代 |
| 11 | `### 1.6 Named-attribute system (data model)` | L70–L114 | 废弃 / 证伪 | 早期误判 `0x0056BC60` 为战斗属性字典；现已证实为脚本引擎 `SetSceneItem` 内建函数（`docs/13` §六），记撤回 #11 |
| 12 | `### 1.7 ~~Per-frame action FSM~~ (UI/menu renderer)` | L115–L174 | 存疑归档 | 历史假说证伪记录（证实 `0x00452AF0` 为 UI 渲染器而非武器状态机），作为历史自撤案存疑留存 |
| 13 | `### 1.9 Main physics integrator — ✅ confirmed` | L175–L227 | 废弃 / 超越 | `FUN_004ceb50` 移动积分器与碰撞解算；`docs/02` §一/§二 提供了更完整的结构体偏移、汇编分析与法线解算 |
| 14 | `### 1.10 Damage / knockback application — ✅ confirmed` | L228–L253 | 废弃 / 超越 | `0x004D0AC0` 4 级击退（350/400/450/600）；`docs/04` §二 提供了完整指令级反汇编、仰角偏置与判定分支 |
| 15 | `### 1.11 ~~Keyword / tag parser~~ — 🔄 REVISED` | L254–L380 | 并入 / 校准 | `0x004D1740` 16 项取消类型码；已证实其为标量赋值而非位掩码，已反向校准 `docs/03` §四.1 表格并记登记 #13 |
| 16 | `### 1.8 Named-record resolver & state getter` | L381–L398 | 废弃 | `FUN_004630b0` 链表查找辅助函数，已由 `docs/13` PScript AST 符号解析器全面超越 |
| 17 | `## 2. AI (enemy / NPC state machines)` | L399–L401 | 废弃 | 空白大纲，已由 `docs/08`（8大行为）与 `docs/13` §四（行为状态机与.pst属性）超越 |
| 18 | `## 3. Asset & Level pipeline` | L402–L405 | 废弃 | 空白大纲，已由 `docs/00`、`docs/05`、`docs/06`、`docs/16` 超越 |
| 19 | `## 4. UI / Menus / Input` | L406–L408 | 废弃 | 空白大纲，已由 `docs/07`、`docs/12` 超越 |
| 20 | `## 5. Persistence / Save` | L409–L411 | 废弃 | 空白大纲，已由 `docs/00`、`docs/13` 超越 |
| 21 | `## 6. Audio` | L412–L414 | 废弃 | 空白大纲，已由 `docs/00`、`docs/09` 超越 |
| 22 | `## 7. Networking` | L415–L417 | 废弃 | 空白大纲，已由 `docs/15`（Winsock Hook、150处发包）、`docs/17` 超越 |
| 23 | `## 8. Error / edge-case behaviors` | L418–L422 | 废弃 | 空白大纲 |
| 24 | `### 1.12 Input sampling → movement axes` | L423–L471 | 废弃 / 超越 | `GetAsyncKeyState` 采样与轴解算（`0x004CB270`），已由 `docs/07` §一/§二 完整覆盖 |
| 25 | `### 1.13 Jump dispatch — ✅ confirmed` | L472–L498 | 废弃 / 超越 | 跳跃模式与初速分支，已由 `docs/02` §二（0.11s/282/375）与 `docs/18` 彻底超越 |
| 26 | `### 1.14 Wall-contact dynamics — ✅ confirmed` | L499–L524 | 废弃 / 超越 | 墙面接触检测（`0x5AA8F0`/`0x5AA8E8`），已由 `docs/02` 与 `docs/18` 超越 |
| 27 | `### 1.15 Note on FUN_004d0540 (impulse maths)` | L525–L536 | 废弃 / 超越 | `600.0f` 冲量缩放（`0x5AA934`），已由 `docs/04` §一/§二 超越 |
| 28 | `### 1.16 The vtable+0xC command pipe` | L537–L666 | 废弃 / 超越 | 控制命令通道解密，已由 `docs/12_COMMAND_PROTOCOL_SPEC.json` 51 项跳转表全面超越 |
| 29 | `### 1.17 The fifth hop — member_0x2410 resolved` | L667–L855 | 存疑归档 | 中途排查 GameApp 槽 218（`0x00489150`）与取消窗口假说证伪的过程笔记，归档备查 |
| 30 | `### 1.18 Both consumer candidates opened` | L856–L955 | 存疑归档 | 排除 vtable[133] 假说的探索过程笔记，归档留存 |
| 31 | `### 1.19 Workspace ledger — two project trees` | L956–L988 | 存疑归档 | 双工程树比对说明，属工程管理笔记，无二进制规格价值 |
| 32 | `### 1.21 Round 7 groundwork — switch fan-out` | L989–L1077 | 废弃 / 超越 | 方向字符串构建与 switch 分支（`0x004CC42B`–`0x004CC549`），已由 `docs/07` §五 超越 |
| 33 | `### 1.22 The attack key — found` | L1078–L1331 | 废弃 / 超越 | 按键路由 `FUN_004cb820` 与攻击命令 `0x1D`，已由 `docs/07` 与 `docs/12` 超越 |
| 34 | `### 1.23 The attack window closes` | L1332–L1761 | 废弃 / 超越 | 攻击窗口计时器 `[A+0xE8]`、`0.11s` 对比与槽 66 派发器，已由 `docs/02` §二 彻底闭合 |
| 35 | `### 1.24 Round 7 close-out` | L1762–L1997 | 废弃 / 超越 | 澄清 `cmd 0x0F` 与 `cmd 0x03` 分支，已由 `docs/12` 协议表完整覆盖 |
| 36 | `### 1.25 The selection question closes` | L1998–L2309 | 废弃 / 超越 | 连招选择机制，已由 `docs/03` §五 KeyMap 20条连招链六道交叉验证彻底超越 |
| 37 | `### 1.26 Project topology, and a correction` | L2310–L2459 | 存疑归档 | 早期反编译比对与 Unity C# 设想笔记，归档备查 |
| 38 | `### 1.27 Cross-checking the tear-down` | L2460–L2603 | 存疑归档 | 早期两套反编译文件文本交叉比对笔记，归档备查 |
| 39 | `### 1.28 Android tear-down vs. Windows binary` | L2604–L2693 | 存疑归档 | 安卓移植版与原版 Windows 二进制一致性验证笔记，归档备查 |
| 40 | `### 1.29 Verification run — the data chain closes` | L2694–L2778 | 存疑归档 | 历史自动化测试执行记录，归档备查 |
| 41 | `## Methodology note (earned the hard way)` | L2779–L2843 | 并入正典 | 逆向工程方法论 12 条军规，具有全项目指导价值，正式收录入本节 B 款 |
| 42 | `## Appendix: evidence index` | L2844–L3044 | 废弃 / 归档 | 早期断言积分卡，已由 `docs/17` §一 8大子系统100%全景积分卡与本台账超越 |

---

### B. 逆向工程方法论十二条军规（Methodology Codex，原 CLONE_SPEC §41）

> 以下 12 条原则源于项目早期逆向踩坑经验教训（经三次重大方向推翻与多次假说证伪后凝结而成），现作为全项目通用审计准则正式收录入正典：

1. **`RET n` 参数元数裁决 (Arity Authority)**：被间接调用的目标函数退栈字节数 `RET n` 能无歧义证实入参个数。结合**自尾跳证伪律 (Self-tail-jump refutation)**：若绑定候选函数会导致调用方尾部直接跳回自身死循环且无栈平衡，则在结构上绝不可能成立。
2. **虚表共存性判定 (Vtable Occupancy)**：指针数组中函数共存证实类成员归属；多张虚表共享同一函数证实其为共享基类或转发路由。
3. **构造函数中的虚表写入 (vptr writes in ctor)**：MSVC 多重继承下单一对象拥有多张虚表指针，必须结合构造函数写入时机与 `this` 指针调整偏置确认基类。
4. **浮点与数学常数硬签名 (Float Constants / API points)**：优先依赖 `0x5AA8E8`（0.11s）、`0x5AA934`（600.0f）等 IEEE-754 常数及 QPC/DirectInput 等 Win32 API 锚点，远比符号名可靠。
5. **字符串只能作为线索，绝不能作为结论 (Strings are leads, never conclusions)**：全镜像扫描字符串极易导致误把控制台/配置命令、调试字串或 UI 渲染器误判为核心游戏玩法。
6. **汇编列表先于反编译器 (Listing before decompiler)**：反编译器对多重继承与复杂控制流易产生歧义、挂起或推断失真；先读机器指令与操作码结构，再看伪代码。
7. **虚表槽位离开基址毫无意义 (Slot without base is meaningless)**：MSVC 多重继承会导致子对象与正典基类槽位号严重偏移（如同一函数在 `0x5AA658` 为槽 85，在 `0x5AA6A8` 为槽 65）。引用槽位必须同时标明基虚表地址与偏移字节。
8. **按操作数形态而非偏移量消歧 (Disambiguate by operand shape)**：同一偏移位移可能是成员变量也可能是虚函数调用位移（如 `[ESI+0xE8]` 既是计时器对象成员指针，又是槽 58 虚表偏移）。必须严格区分 `CALL dword ptr [...]` 与 `MOV`。
9. **单引用虚表槽位的交叉引用盲区 (Single-slot xref blind spot)**：当目标函数全镜像仅有 1 处虚表指针引用时，常规代码交叉引用搜索显示为 0，必须通过虚函数表槽位反向索引调用源。
10. **偏移量本身不是唯一标识 (Displacement offset is not an identifier)**：`+0x12c` 等常见偏移在全镜像可出现数十次；务必记录完整 `base + index` 与解析后的绝对 VA。
    - **10.1 严禁引用截断列表的计数**：引用计数必须取全量扫描的独立统计终值，严禁根据 `head` 或截断日志估算。
11. **被调用方 `RET n` 快速证伪调用点**：若调用点未 push 参数而被调用方执行 `RET 4`，即可瞬间推翻该候选绑定关系。
12. **临近性不等于同一性 (Proximity is not identity)**：紧接在跳转指令 `JMP [table]` 后的指令块不一定是 case 0（如 `0x4BB81F` 紧随跳转表后，实际为 case 12）。必须反查跳转表数组索引。
