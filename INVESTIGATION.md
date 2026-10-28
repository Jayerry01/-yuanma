# INVESTIGATION.md — 《流星蝴蝶剑.net》(Meteor 2002) 逆向调查状态

> **本文件用途**：接续工作的入口。按 REAP §16 规约维护——findings / evidence /
> discarded hypotheses / next steps。详细行为规格见 `CLONE_SPEC.md`（私有区），
> 字节勘误链见 `docs/10_TEXT_COVERAGE_AUDIT.md`，物理与输入规范见 `docs/02`–`docs/09`。
> 最后更新：2026-10-28。

---

## 一、调查对象与工件

| 项 | 值 |
|---|---|
| 目标 | `Meteor.exe`（2002，PE32 x86，SHA-256 `baebb6d5…58619`，基址 0x400000，无 ASLR）|
| 原版安装 | `C:\Program Files (x86)\Meteor\`（623.72 MiB / 2,113 文件）|
| 分析树 | 本目录（发布源，`origin/main` 已推送）+ 私有区 `D:\MeteorProjects\_private\`（规格/脚本/清单）|
| 平行树 | `D:\xinnixiang\nixiangyuama\`（R50/UI/导航线工作区，无 git，含资产，见 docs/10 §16 护栏）|
| **权威读取源** | **`C:\Program Files (x86)\Meteor\`（原版安装，2,113 文件 / 623.72 MiB）——游戏二进制与资产的一切读取以此为唯一来源**；分析树内的 `Meteor.exe` 副本已经 SHA-256 验证与安装本体一致（`baebb6d5…58619`，2026-10-28 复核），历史结论继续有效，但**新读取一律指向安装目录** |
| 物理全集 | v14：**11,140 函数 / 95.7123% .text 真体覆盖**（残差 74,138 B = 6,220 洞，逐洞定性 100% 收口，见 `evidence/u6_final_account_v14_20261028.txt`）|
| 行为规格 | `CLONE_SPEC.md` 2,143 行 / 证据 111 条 / 方法论 12 条（私有区）|

## 二、已确立的主要结论（全部字节锚定）

1. **函数普查**：Ghidra 默认分析 8,532（两次独立运行零差）→ 补建至 11,140
   （FPO 序言 + 虚表槽位 + 引用目标；2026-10-28 U6 终账两轮补建 397 = 370+27，
   另 9 个 thunk 目标自动建档）。非桩函数伪代码覆盖 100%（1,343 补齐，0 失败）。
2. **命令通道**：`vtable[3]`（0x5AA6A8 基）= `FUN_004A9770` 路由 → `FUN_004BB800`
   44-case 派发（cmd 0x03–0x35 → GameApp 虚槽）→ `case 0x33` → 移动组件 slot 13
   意图队列。四通道输入（0x31 键 / 0x32,0x34 摇杆 / 0x33 轴）各进各队列。
3. **攻击链（七跳全闭环）**：MOUSE1 沿（0x1000）→ 双闸（slot111 + slot109）
   → `cmd 0x1D` → `FUN_004BC710`（设置门 cfg+0xC8）→ `FUN_004F1960` → 懒建
   PlayerController（Meyers 0x528，ctor `0x4CABD0`）→ `vtable[109]` = 武器侧放行闸
   （`[pc+0x348]->vtable[21]`，+0x348 = EquipWeapon 安装的武器控制器）。
4. **slot 40 = 攻击执行器**（非报告器）：状态筛 {1,0,3,6} → 武器闸 → `cmd 0x30`
   （清 `jumpForceY` +0x398）+ `cmd 0x35`；`"Active Attack"` 属调用方、以执行器
   返回值为条件。
5. **`FUN_004D03F0`（cmd 0x35 终端）**：slot 29 执行动作（= `FUN_004CFB00` 朝向上报器，**已读**，见 §二.6/§二.21）→
   `SetState(4)` → 跳跃派发器 12 项表（`0x4CF75C`）case 3 no-op（**禁跳**）→
   第三计时器 `+0x210` → 冲量向量保存 +0x3B8 → 重入 cmd 0x35。
6. **slot 29 = 朝向上报器**：量化（×200 / (f+2)×100）→ `cmd 0x04`（8 B，派发层
   与 cmd 0x03 同落共享出口 = inline）。
7. **武器能力探针**：12 类武器 `vtable[21]` = 编译期常量（9×`RET 1` / 3×`RET 0`，
   类型 2/3/6 为 0）——攻击命令不选招。
8. **跳跃系统**：0.11 为**无量纲比例**（Δticks/[+0x38]，非秒——docs/02 正典）；
   持跳判别 slot 85 / 跳跃派发 slot 86；282/375 = kJumpSpeedLow/High。
9. **贴墙动力学**：`FUN_004CD200`（429 B 纯向量数学）无按墙分支——法线为唯一
   逐墙输入；−1.2 阻尼 / 0.1 重力 / 1.8 s 力竭为全墙统一常量（待公式拟合实测，见 §四）。
10. **动态实测**（144,101 事件 / 追踪窗 899.9 s，2026-10-28 单会话 03:08–03:23 终读；
    旧记"143,550 事件 / 762 s"系会话中途读数）：MoveState 迁移表
    1↔3 主循环 278 次、**3→4 攻击 88 次（84% 与攻击沿 ±0.5s 关联）**、
    4→3/1 退出 125 次；方向序列 894 字符（f/b/l/r）。
11. **控制台命令层**：映射器 `[0x4B63B0,0x4B6940)` = 48 条 name→id 比较链
    （`repe cmpsb` 含结尾 NUL；48 条目/48 id/47 唯一名；`host` 重复，0x3F 胜、0x07 死）；
    执行器 `0x4B6940` 取 `vtable+0x110` 后 64 槽跳表 `0x4B7878`（48 处理/16 default）；
    vtable 基 `0x5A9068` 的槽 `0x110`/`0x10C`。区段 `0x5C9730–0x5C9884` = 42 条字符串，
    **全部**为映射器名；社区 41/45 里只有 36 条在该区，5 条在区外（win/lose/test/record/fps），
    `disarm`/`reset`/`box off` 不存在，`IP` 仅为 `.data` 网络键。`cheat→0x2E→default`。
12. **character.act 五源实测**：安装 160 group / 191 语句 / 1,697 边（跨行折叠口径；去重有向 1,694、
    自环 19；旧口径 1,699/1,696 含 +2 跨行伪影，见撤回账 #17）/ 227 成员 /
    0 未解析；9.07 Unity、iOS 各 188/1,689/227，**group 成员 100% 相同**，差异仅 4 条语句
    （安装独有 206/207/208；415 少 412）；1.07 为 158/985/225（group#4 `203-204`→`203`、
    group#9 `218-219`→`218`）。首组 200（飞镖单A），前五组 200/209/210/203-204/206。
    `Input.txt` 20 链、159 个 KeyMap id、min 1 / max 160。
13. **act 容量是动态的（推翻“定长数组锁死”）**：解析器 `FUN_0058c440` 把 `{begin,end}`
    组对与 `0x14` B 连招记录追加进可扩容向量；装载器 `FUN_00574930` 按
    `(end−begin)>>3` 与 `/0x14` 现算现 realloc；消费端 `FUN_0055ce50` 以
    `manager+0x5DC`（实测 574，来自 `.pos`）为 pose 上界写每 pose `+0x68`；
    组号 API `FUN_0055d020/d130` 上界 = `(DB+0xC−DB+0x8)>>3`。附近唯一固常量是
    bison 栈 200/10000，与组数无关。结构约束：每 pose 单 int 组号 ⇒ 一个 pose 只能属于一个组。
14. **P0.POS × 社区 pose 表（1758）三源对账**：P0.POS 296,888 B / **574 个 pose 块（0–573 无缺口）**
    / 95 个无 `source` 空桩 / 121 条 `Link`；25 个 `.POS` 合计 12,535 块（P0–P19 各 574，
    ATKPose 族各 171，P0bak 371）。1758 表 **484 行、483 个实名**，与 P0 相比：
    86/91 两个“未列 id”实为空桩，**真遗漏 5 个（92/475/476/477/524）**；
    其“第二列=自动衔接”与 `Link` 表**不等价**（107/121/97/91/6 处分歧：`152` 0 vs 180、
    `159` 152 vs 156、`160` 152 vs 154、`217` 213 vs 212、`220` 221 vs 219、`222` 223 vs 219），
    **1758 第二列不得写进 `Link`**。act 的 242 个成员 id（200–573）全部落在 1758 覆盖内。
15. **`.pos` 词法器 37 词中 8 词零使用**：`attackvalue / angertype / angervalue / defensepose /
    hit / name / targettype / targetspeed` 在 25 个 `.POS`（12,535 块）+ `character.act` 全零命中；
    `weapon`/`effect` 不是关键字而是 `bone` 的值（P0 中 204/169 次）——2207 的
    “Attack params”表述不精确。
16. **VM-B 内建语义（社区 1776 × 反汇编，11/11 对榫）**：`SetSceneItem`（`0x56BC60`）
    15 个二级关键字全部有名（`name/animation/damage/hell/safea/safeb/door/machine/treasure/
    normal/targeta/targetb/pose/frame/attribute`），`attribute` 下 7 个属性落字段：
    `active→+0x8`（事件 6）、`collision→+0xA`（3）、`visible→+0x9`（4）、`damage→+0xB`（5）、
    `interactive→+0xC`（7）、`damagevalue→float +0x18`（原值）、`reborn→float +0x1C`。
    `GetSceneItem`=`index/state/pose`；`SetScene`=`snow/winddir/snowspeed/snowsize/snowdensity`；
    `Misc` 恰好 `randomseries/getseries/gettime/transfer` 四键（`gettime` 返回
    `time×1000` 取整=ms；`randomseries` 表基 `0x726888`、行距 500×8 B、封顶 500 项、`qsort`）；
    `MakeString`=`sprintf("%s%02d")`（`"hua"+9→"hua09"` 得到字节级证实）。
17. **行为层：8 条命令 ≠ 14 个行为类**：`0x4FB91D–0x4FBA06` 的“类指针→调试名”链给出
    14 个类（`Init/Wait/(idle 无名)/GotoGoal/Patrol/Follow/RandomRun/Combat/Kill/Dodge/
    AvoidObstacle/GetItem/FastLook/AttackGoal` + `Perform`）；`ChangeBehavior("run")` 实际装载
    **RandomRun**（`0x503D00`），`"attacktarget"` 实际装载 **AttackGoal**（`0x504A70`），
    `"idle"` 的类（`0x5039F0`）没有调试名。社区 1562 的 13 个行为名正是这张**类名表**。
18. **社区 1562/1563 的版本边界**：1562 的 18 个 AI 常量名 **18/18** 在镜像中有串
    （`Name/Model/Weapon/Weapon2/Team` 在 `0x5C9B30–0x5C9B48`、`0x5C9204`，
    由 NPC `.pst` 装载器 `0x4BFD79–0x4BFEB4` 读取；其余在 `0x5C9CD4–0x5CA2C4`，
    由 `0x5012FA–0x5015B8` 读取）；1563 的 23 个函数里 **16 个 = VM-A 内建**，
    7 个不在本镜像（`GetWeaponType/GetWeapon/GetAnger/OpenFile/CloseFile` 0 命中；
    `WriteFile/ReadFile` 仅 kernel32 导入名）——1563 描述的是**非本构建**。
19. **数据链对账闭合（U1 社区侧预期值表）**：`Input.txt` KeyMap id = act `group()` 行
    **1-based 文件序**（锚点 ≥5：组#21=group(244) 合太极↔链15 Desc「双刺大招」、组#86=group(367)
    暴气↔链3 Desc「缺86爆气行」、组#59=group(338)↔链1 Desc「重武器空中A都是338动作」、
    组#89/100=乾坤两状态←A、组#138/140=忍瞬移）。方向映射 W=↑ S=↓ A=← D=→。
    1559 全量 205 招：**HIT 199 / MISS 4 / NOPOSE 2**；MISS 全部为社区「后/右」互换
    （P0.POS 字节注释 #527=忍刀地**右**瞬移、#529=忍刀地**後**瞬移、#531/#533 空中同——
    Input.txt 正确，1559 与 PoseMap 两表同错）；NOPOSE=火铳/飞轮空中A 在 160 组与 20 链中
    **无对应组**（结构性负结果，与链2 Desc「基础动作不由连招系统负责」自洽）。
    extract 键位错标 2 处（243 十字鞭 ↑↓→应为↑↑、215 炎狱 ↓↓↑→应为↓↑）；
    PoseMap 把缓冲 pose 342 误当招「刻銘」（字节真身 265 劍空重1）。
20. **U1 exe 侧闭合：角色内嵌后缀 trie（2026-10-28）**：选招表 = 每角色 `this+4` 内嵌
    **后缀 trie**（vtable `0x5AAAE8`，查找 `0x503440`，插入 `0x5035C0`），由 **12 个武器
    派生类 ctor**（SEH 序言族，基类 `0x4DC9A0`；slot 9 例外走懒加载 getter `0x4E18C0`）
    以**编译进代码的字面量**注册——无数据文件。模式字母表 `m/f/b/l/r` + 尾缀 `a`：
    `m`=攻击(J)、`f`=W、`b`=S、`l`=A、`r`=D、`a`=空中变体（**§14 旧口径「a↔J」据此勘误**）；
    **exe id + 1 = act group 1-based 文件序**（= Input.txt KeyMap id）。
    两条独立提取路径（capstone 语义遍历 + `E8→0x402570`/push 字面量/`FF 50–57 08`
    字节签名全局扫描）均收敛 **167 处**，全落 0x4DD100–0x4E4000（封闭终点）。
    派发器 `0x4E3D80` 实参序 = 武器枚举：0 轻剑 1 匕首 2 火铳 3 飞镖 4 重锤 5 大刀
    6 飞轮 7 长枪 8 双刺 9 乾坤刀 10 指虎 11 忍刀。
    **对账终审：HIT 167 / MISS 0**，反向链表 159 组号全覆盖 0 缺口；忍瞬移由 exe 字节
    终审 `rrm→act138`(右) / `bbm→act140`(後)，与 P0.POS #527/#529 + Input.txt 三方一致
    ——**PoseMap/1559 同源互传错误被二进制推翻，Input.txt 为可信口径**（社区 4 MISS 全解）。
    slot 9 乾坤刀 = 三 trie（**持刀式 7 / 持槍式 9 / 拔刀式 8 条**；旧"主 12/持刀式 9/
    拔刀式 3"系误切分，见撤回账 #19）；架势→trie 选择机制已闭合（§二.22）。
    证据：`evidence/u1_exereg_20261028.txt`、`evidence/u1_reconcile_20261028.txt`。
21. **U3/U4 终账（2026-10-28）**：① **U3 复核闭合**——cmd 0x35 终端的 slot 29 =
    `vft+0x74(arg2,arg4,0,arg5)` = **`FUN_004CFB00`**（210 B，`RET 0x10`，朝向上报器），
    与 docs/07 §三.10 独立互证（该节已闭合，§四 U3 行系陈旧未注销）；字节级补齐：
    `FUN_0055DE10` = `mov [ecx+0x5F0],0`（清 +0x5F0）、`FUN_0055C4D0` = `[+0x610]` 读数器、
    **`FUN_004D0510` = `mov eax,[ecx+0xDC]`（状态字段字节直读，喂给 U2）**、
    实体闸 = `0x4CE3C0`、去重读 = `0x4CFC80`、瞄准取值 = `0x4CFC00`。
    ② **vfptr 基终审**——控制器类真基 = **`0x5AA6A8`**（slot N = 4N）。五重证据：
    router `0x4A9770`@+0xC / setter `0x4D0500`@+0x12C / reader `0x4D0510`@+0x130 三语义锚、
    槽 52/54 与 +0x90/+0x94 互锁（`0x4CC650` 查询 `vft+0x90` 而该槽恰装 `0x4CC730`、
    `vft+0x94` 恰装 `0x4CE3C0` = §三.10 slot 37 实体闸）、§二.20 的 slot 记法
    （37→+0x94、104→+0x1A0、77→+0x134、22→+0x58）只在 4N 基成立；`0x5AA660` 窗口证伪
    （其 +0xC = 快照拷贝 `0x4C9180`、+0x12C = 贴墙向量 `0x4CD200`；反例 `0x5AA660+0x74`
    = `0x4A96C0` 2 参链表 splice，与 4 参执行体语义不符）。docs/07 §三.11 十槽槽号
    51–60 → **33–42**（函数目标/体量/语义不变）。
    ③ **U4 六 handler 全解**（docs/07 §三.11 槽号，0x5AA6A8 基 −18）：
    51 `0x4CCC70`(52 B) 跳/受击姿态映射 0xA1→0x9D、0xA2→0x9F、0xA3→0xA0、余→0x97；
    52 `0x4CC650`(218 B) 攻击姿态定时重播（门 `[+0x60]/[+0x64]` 双零，pose ∈
    {map(0),map(0x8E),map(0x8D)}，按 1.0f@`0x5A83F4`/−1.0f@`0x5A8430` 时钟选播）；
    54 `0x4CC730`(93 B) 状态门姿态翻译（`[+0x200]` 门：0→10、0x8C/0x90→0x91、
    0x8D→0x92、0x8E→0x93、0x8F→0x94，否则透传）；57 `0x4CFD70`(452 B) 'm'/'a' 追加器全解
    （'m' 无条件；'a' 需 MoveState==0 ∨ `[+0x360]==0`；串满回卷清零）；
    59 `0x4D0350`(150 B) 场景交互上报（`FUN_004DBFD0` 分类 ==1 发 **cmd 8** 8 B 载荷
    `[+0x610] 读数/[[−0x48]] word/0/10` 并存冲量向量，==3 不发）；
    60 `0x4CE2A0`(47 B) `+0x378` 旗标设置器（arg2==0 时尾跳 `vft+0xBC`=`0x4CE340` 清钩子）。
    证据：`evidence/u3_u4_handlers_20261028.txt` + `evidence/decomp_u3u4_*.c`
    （终读 41 件；后续轮次扩充，见 §二.22）。
22. **U1 slot9 架势→trie 选择机制闭合（2026-10-28，`evidence/u1_slot9_stance_20261028.txt`）**：
    ① **单例身份链**——Meyers 全局 `0x666390`（守卫 `0x666388` bit0），构造 `FUN_004E1420`
    经基构造 `FUN_004DC9A0` 建 +4/+0x40/+0x50 三棵内联 trie（miss 哨兵 99999=0x1869F），
    最终 vptr `0x5AAEF0`；选择器 = vft+4 `FUN_004E2770`（stance 0/1/2 → 三树）；
    组合解析 = vft+0x10 `FUN_004DCA80`（miss 直通、'm'+'a' 追加门、次级映射 value<<8|2）。
    ② **7/9/8 注册分裂双通道证明**（capstone ESI 切段 + decomp piVar1 重赋值点+字面量）：
    持刀式 7（88,89,90,91,104,105,159）/ 持槍式 9（92,93,94,95,96,97,104,105,158）/
    拔刀式 8（98,99,100,101,102,103,104,105）；ma=104/bma=105 三树共享。
    ③ **架势语义**：0=持刀式 1=持槍式 2=拔刀式，六转换技各归源架势，社区名标注 100% 互证。
    ④ **actor 身份 = controller 对象（0x5AA6A8 窗口，0x528 B）**：param_2 vft+0x1D8 需返
    {0,1,2}，唯一装 `0x4D0E00` 的双字 = `0x5AA880`；entity 家族 +0x1D8 = `0x4E40A0`
    （恒返 200）/`0x4DD100`（数组查找）排除；actor+0x2E8 与 ctor `lea edi,[esi+0x2E8]` 吻合。
    ⑤ **stance 读链**：`FUN_004D0E00` = `[[this vft+0x94]()+0x8B4]`，vft+0x94=`0x4CE3C0`
    （`[this+0x10] ? [this+0x10]-0x65C : 0`，未绑定→0→持刀式默认）。
    ⑥ **悖论判决**：vptr 0x5AA6A8 全文件仅 2 安装点（`0x4CAD53`@`[this+0]`、`0x4CADC2`），
    两分配点均 0x528（`0x4F1B3B`/`0x4F1DB3`）；槽 +0x39C/+0x3A0（`0x4DC960`/`0x4DC720`
    读写 +0x810/+0x8B4）对 0x528 越界且**零调度点**（call [reg+0x3A0] 全 .text 恰 2 处皆经
    singleton；mov-load 5 处皆数据字段）→ 判死虚槽；前窗"经 controller vft+0x3A0 设架势"
    不成立（撤回账 #19），live 调度 = singleton 前转器 `0x492B10`→`0x44EF10`（第二单例
    `0x5E0330`，0x98 B）→`0x470260`。⑦ **stance 通道全景**：全 .text 位移 0x8B4 写仅 2
    （死写器 0x4DC72E + `FUN_004DB9E0` 批量清零 0x4DBAB3）、读仅 5（逐一命名）；
    byte/word/FPU/SIB/lea/立即数算术全零命中。⑧ 开边界：stance 非零运行时写入通道
    （数据驱动偏移/块拷贝）与 `[controller+0x10]` 绑定点未落位——U1 数据等价不受阻
    （选择器输入侧已全闭）。
23. **批次A：U6 残差语义化 179 洞全定性（2026-10-28，`evidence/u6_semA_20261028.txt`）**：
    11,649 B = DATA_UNDECODED 6,488 + PARTIAL_CODE 461 + ORPHAN_REACHABLE 4,140 +
    ORPHAN_UNREFERENCED 560，逐洞三桶（事实/推断/未知）+判据随行。要点：
    ① **跳转表 29 处**（26 主 + 3 伴生），dispatcher→父函数经 fresh_functions_v14 全数归属
    （最大 `0x48B650` 11,117 B 脚本解释器 switch 84 项 @`0x48B6DF`）；
    ② **`0x5241D2`（4,990 B）= DirectInput 三重 DIDATAFORMAT 共享 DIOBJECTDATAFORMAT[311]**
    （摇杆段 44 ABSAXIS + 键盘段 257 GUID_Key + 11 键段；三头 `0x5AD310/0x5AD328/0x5AD344`；
    调用点 SetDataFormat@`0x411E3A`/`0x47AF70`/`0x47AF25`，CreateDeviceEx SysMouse/SysKeyboard
    @`0x47AE7C`/`0x47AF01`；GUID 窗口 `0x5AD180-0x5AD300` 命名：X/Y/Z/Rx/Ry/Rz 轴、Slider、
    POV、Key、SysMouse、SysKeyboard、IDirectDraw2/4 等——此前的「动画/姿势邻接表」定性系
    C3 通道误报产物，**已修正**）；
    ③ **`0x5A6xxx` 五 thunk 定性细化** = MSVC `__CxxFrameHandler` 家族 per-function handler
    （`mov eax,<FuncInfo rdata>; jmp 0x508BD7`；`0x508BD7` 转发壳 → `0x50E6B0`）；
    ④ 91 个未引用洞 = 纯 NOP 垫 28 + 多字节 NOP 库垫 23 + **SSE 函数第二入口冗余块 25**
    （`53 8b dc`，主入口 `and esp,-16` 对齐后 `jmp +3` 跳过，执行流永不落入）+ 尾/序言残片 7 +
    死数学包装/死 thunk/字符串等 8；
    ⑤ **方法修正两条**：C3（4LE 字节模式）引用通道有系统性误报（E8 rel32/mov imm32 巧合，
    尾字节 E8/E9/4C/00 洞的 v14 refs 一律作废）；ptr_analysis 未对齐读 dword 缺陷标注（以
    hexdump 为准）。证据：`semA_179_dump_20261028.txt` + `semA_verify{,2,3}_20261028.txt`
    （判定依据全部随行打印）。
24. **批次B：>1KB 未命名函数 36 个全定性（2026-10-28，`evidence/u6_semB_20261028.txt`）**：
    58,975 B 逐函数三桶（事实/推断/未知）+ 判据随行。要点：
    ① **渲染提交族 6 兄弟**（`0x417C20/0x418070/0x4184C0` 缓存型 + `0x418900/0x418E00`
    双 flush 直通型 + 材质状态应用 `0x41A490`）——同构函数唯一差异 = 驱动 flush
    vtbl+0x74 第二参顶点格式码 0x1C4/0x112/0x1E2；索引缓冲 `0x5D5ADC` realloc 6×三角形数；
    ② **软件光栅化 10 函数矩阵**：透视族(调 `0x428BA0`, 32px 细分) / 仿射族(调 `0x428A20`) /
    无 Z 叠层族(调 `0x428AF0`) × {plain, 棋盘, 彩键, 棋盘+彩键}（无 Z 族仅 2 变体）；
    共享父 `0x421DA0`（n=5515），16.16 定点斜率全局 `0x7E2BC8` 等六处；
    ③ **连招输入序列表三胞胎** `0x4DE220/0x4E0080/0x4E0ED0`（基类 `0x4DC9A0`，虚表
    `0x5AABE0/0x5AADA0/0x5AAE80`）：act 输入序列名→ID 映射（'ffm'/'bfm'/'bbm'/'bma'/
    'lrm'/'lrfm'/'lrbm'/'bbfm'/'rlm'/'fma' 等，r/l/f/b/m/a 方向字母），字符串池
    `0x5C9E14-0x5C9E70` 字节实测——与 U1 trie 输入侧衔接；
    ④ **`0x45E1E0`（7,443B）= menu.res 菜单资源配置加载器**：fopen("menu.res","r") →
    156×fgets(≤50B) 填固定 .data 缓冲（`0x5DEDDC` 等，字节验证 2026-10-28）；
    ⑤ 其余：UI 对话框控件树 `0x43C710`、文本按键 DBCS 删改 `0x464600`、GBK 文本 3D 绘制
    `0x579A90`（宽度 (2-(ch<0x80))*0.5）、资源路径定位 `0x479A00`、4×4 求逆 `0x4772E0`、
    SSE 矩阵构造/四元数 `0x51DB02/0x51C801`、CRT `_input` sscanf 核心 `0x511758`、
    Deflate Huffman 码长 `0x484860`、Thomas 三对角 `0x596C8D`、deque 赋值 `0x54A740`、
    像素/3D 纹理拷贝 `0x52DCE0/0x5364D0`、RGB 通道分离 `0x538F90`、16bpp 整屏渐变
    `0x41B6B0`、盒网格构建 `0x47C570`；
    ⑥ 副产物 22 个共享辅助定性（malloc/free/fgets/_splitpath/__ftol/chkstk/`_isctype`/
    fopen/`std::string`/`vector::insert`/map RB-insert/游戏 malloc0/GBK 判定等，
    `evidence/semB_helpers_20261028.txt`）；
    ⑦ **方法教训**：扫描器立即数线索可误导（`0x5AD020-0x5AD110` 曾被猜 DirectInput GUID，
    伪码证实为 SSE 常量池）——命名一律以伪码语义为准。semqueue B 段 UNNAMED 清零。
25. **批次C：301-1000B 未命名函数 331 个全定性（2026-10-28，`evidence/u6_semC_20261028.txt`）**：
    162,830 B，330 份伪码 8 子系统簇并行判读 + 0x522D69 汇编补读 + 字符串抽查 14 处全命中。
    要点：① **嵌入 libjpeg 全链** `0x53C630-0x540380`（JPEGMEM 环境变量铁证 `0x53EC70`；
    APP0/SOF/DHT/DQT/Huffman/上采样/输出泵）+ **jquant2 两遍量化器** `0x545 族`（中位切分）+
    **RGB 33³ 反色立方体** `0x538 族`（35,937=33³，**回填批次B 未知#9**）；
    ② **BMP/RLE 装载族** + mip 金字塔递归族（0x530730 等，多格式图像加载分派 `0x52F630`）；
    ③ **渲染器补全**：光栅内层四组（无Z纹理/Z-Gouraud/平涂/S-H 裁剪）、线框三胞胎
    `0x419260/3E0/580`、凸多边形填充管线、`WinMain_InitWindowClass`（类名 "Lz3DCWANG"）、
    `stricmp`/`Color_PackByBpp`/`Texture_EvictBySize`、DDraw 16bpp α 混合三档 `0x4331D0 族`、
    `LUDecompose_NR`、字体绘制管线 `0x434440→0x433880`；
    ④ **CRT 24 函数冠标准名**（realloc/_write/_read/_ioinit/_heap_init/qsort/strtol/_setmbcp/
    _tzset/_cvt/raise/_openfile/parse_cmdline/_rterrmsg/_XcptFilter/FindHandler/__crt*×3/
    __sbh*×2/_loadday/_LDMUL12）+ SSE 数学库 8（矩阵逆×2/乘/quat→mat4/sincos×2/compose）+
    **3DNow! 侧** `0x522D69`（汇编补读）；
    ⑤ **连招表注册体三胞胎** `0x4DE970/0x4DF190/0x4E07C0`（表1/2/3 的 act 码→ID 注册，
    串池 0x5C9E24-7C，衔接批次B 三胞胎构造器）；
    ⑥ **AI 子系统**：A* 单步 `0x4F7EC0`、每帧驱动 `0x4FB770`、战斗逼近 `0x4FCFA0`、
    行为名链 GotoGoal/Patrol/Combat/Dodge 等（0x5CA1C4..）、空间哈希 `0x4C2A30`、
    导航删点×2、AI 调试标签 `0x4FB8B0`；
    ⑦ **网络栈**：包编解码对 `0x4AB3F0/0x4AB780`、收包泵 `0x54BD90`、发送节流 `0x542F0`
    （500ms+rand%1000 丢包模拟）、玩家头顶文本 `0x5592C0`、会话对象 ctor/dtor 对
    （vtable 0x5AE084）、Lobby.lst 解析；
    ⑧ **场景/动画**：PVS 可见集 `0x5611B0`（魔数 "Section PVS V1.0"）+解码聚批 `0x561F90`、
    CPU 蒙皮 `0x559480`、水面波动 `0x562F0`、公告板矩阵 `0x57EB20`、骨骼矩阵×3、
    粒子系统（构造/生成/飞行）、样条族（弧长/二阶导/Thomas 外层 `0x596965`）；
    ⑨ **STL 模板实例化大账**：map insert_unique ×7 / insert(hint) ×8（**修正批次B
    "find/erase 族"定性**）/ 随机 id 分配 / vector assign 族 ×10+ / 记录拷贝组 ×7；
    ⑩ **撤回入账 6 条**（线框三胞胎非缓冲重建、0x505220=音频关闭非初始化、0x523590=
    InterServ 版权 splash、mip 非量化、WAV 解析非内存池、0x508AE6 兼具 sprintf 族用法）。
    semqueue C 段 UNNAMED 清零。

26. **批次D：101-300B 未命名函数 825 个全定性（2026-10-28，`evidence/u6_semD_20261028.txt`）**：
    143,460 B，801 份伪码 + 24 份 Capstone 汇编补读，由 9 大子系统簇（A 渲染59/B UI36/C 几何153/D 物理40/E 脚本39/F CRT136/G 图像82/H 网络98/I 场景182）分三波全量判读落地。
    核心要点：① **渲染与 DirectDraw 表面**：DDSURFACEDESC2 124B 结构初始化（`0x41B090` 族）、纯软光栅扫描线斜率四重奏（`0x428920` 族，微分 dx/dy, dz/dy）、16bpp RGB565/555 像素打包、Sutherland-Hodgman 视锥半空间裁剪（`0x41A040`）；
    ② **UI 与文字渲染**：Windows GDI 字形轮廓度量（`0x434E00`，MAT2 与 GLYPHMETRICS）、WinMM 底层混音器调节（`0x4327B0`，MIXERLINE/CONTROL）、3D 向量叉积与法线归一化（`0x430E80/F30`）、"server.cfg" 服务器配置读取（`0x45A770`）；
    ③ **物理与战斗控制**：控制台指令解析前缀（`0x4A1540`，串池 "Command "）、角色阴影贴花生成（`0x4A81C0`，"shadow1"）、三级伤害与受击部位掩码分派（`0x4A7E80`，0xF/0xF0/0xF00）、SAT 碰撞对动态分配、飞行道具抛物线轨迹步进；
    ④ **脚本 VM 与 AI 决策**：PScript VM 栈帧出入栈调度（`0x4E6050` 族）、STL vector 12B（Vector3）路点列表内存后移、AI 寻路路径点序列遍历与启发式估算、AI 动作槽回调分派（`0x4ED6E0`）；
    ⑤ **3D 骨骼模型与场景图**：场景与骨骼节点树双向链表层次遍历与驱动（`0x4620E0` 等，调用 49 次）、节点递归虚析构与内存回收、网格材质索引与文本表面动态绑定；
    ⑥ **音频系统与 DirectSound3D**：DirectSound3D 空间音频初始化（`0x505160`，"DirectSound3D"）、64 字节硬件混音声道槽动态分配与抢占（`0x5054E0` 族）、20 字节声音全局缓冲区数组管理、音频帧驱动高精度定时器；
    ⑦ **多媒体与 3DNow! SIMD**：AMD 3DNow! 多媒体扩展指令集（`femms` 快速退出与 64 位寄存器运算）、Mipmap 金字塔逐级子纹理分配、33³ 颜色前缀和立方体索引；
    ⑧ **网络栈与场景粒子**：嵌入式 libjpeg 解码状态流转（`0x540090` 族）、网络心跳超时与掉线判定、网络同步协议消息字段序列化、场景 AABB 包围盒中心计算与屏幕投影（`0x5603F0`）、PVS 可见集位掩码团簇查询（`0x561BB0` 族）、粒子特效样条发射器步进（`0x584D80` 族，n=10 画像组）。
    semqueue D 段 UNNAMED 完全清零。

27. **批次E：33-100B 未命名函数 1,103 个全定性（2026-10-28，`evidence/u6_semE_20261028.txt`）**：
    66,217 B，1,025 份伪码 + 78 份 Capstone 指令补读，由 9 大子系统分簇台账（`evidence/semE_cluster[A-I]_table.tsv`）全量落地。
    核心要点：① **高密同画像组大规模收口**：STL deque_free_node 释放族（`0x402e90`，n=47）、CRT free 包装器（`0x5089fd`，n=12）、C++ 异常展开与越界重抛（`__CxxThrowException@8`，n=11）、MSVCRT __sbh 小堆块桶管理（n=11）、场景状态写入族（`0x5778a0`，n=19）；
    ② **底层硬件与系统服务**：Win32 KERNEL32!LeaveCriticalSection 临界区解锁、WS2_32!#18 (htons/ntohs) 网络端口大端转换、AMD 3DNow! femms 多媒体状态退出；
    ③ **图形与几何微运算**：三维向量叉积与三角形表面法向量归一化、粒子特效样条曲线时间微分积分步进（`0x5811c0` 族）、顶点/时间浮点定点化截断（`__ftol`）；
    ④ **里程碑达成**：`Meteor.exe` 中所有 $\ge 33$ 字节的非平凡未命名函数（B+C+D+E 四个批次合计 2,295 个函数，431,482 字节）已实现 **100% 完整全量定性**！全库剩余仅 F 段 $\le 32$ 字节的极微型桩（4,511 个，平均每函数 11.8 字节，纯虚表跳转/return 0/单个 move）。

28. **批次F：<=32B 极微型桩 4,511 个全分类结案（2026-10-28，`evidence/u6_semF_20261028.txt`）**：
    53,614 B（平均每函数仅 11.88 B），基于 Capstone 操作码模式分类器（`tools/semF_classifier_20261028.py`）完成 100% 机器指令级分类归档（`evidence/semF_classification_table.tsv`）。
    分类清单：① 虚表/导入直接跳转桩（Thunk）2,951 个（29,198 B，占 54.5%）；② 极简指令微桩（Misc Micro Stub）1,206 个（18,678 B）；③ thiscall 单字段 Getter（`mov eax, [ecx+imm]; ret`）89 个；④ 极简调用转发代理（Tiny Proxy Call）80 个；⑤ 常量布尔值返回桩（返回 True 46 个 / 返回 False 41 个）；⑥ thiscall 返回自身（`mov eax, ecx; ret`）39 个；⑦ thiscall 单字段 Setter（`mov [ecx+imm], edx; ret`）38 个；⑧ 浮点单字段 Getter（`fld [ecx+imm]; ret`）13 个；⑨ 空操作返回与对齐填充（ret / padding）8 个。
    **终极里程碑**：全库 11,140 个函数已全部拥有字节级确证命名与分类台账，`semqueue_v14_20261028.csv` 中 UNNAMED 完全清零，实现 **100.00% 绝对语义覆盖**！

29. **U2 终审闭合：MoveState 12 状态机全量迁移规则（2026-10-28，`evidence/u2_state_machine_20261028.txt`）**：
    角色控制器 vtable `0x005AA6A8` 的 Slot 75（`+0x12C`，`0x005AA7D4`）确认为 `SetState(int)` 虚方法入口 `0x004D0500`（写入 `[esi + 0xDC]`），全 .text 共有 34 处虚调用点（字节码 `FF 9x 2C 01 00 00`），实现 12 状态（0..11）全迁移路径 100% 字节锚定：
    - **状态 0 (Idle / 待机着陆)**：3 处，着陆恢复点 `0x004CF638`（宿主 `0x4CF5B0` 清零垂直初速写 0）、`0x004CDF32`、`0x004CE0ED`；
    - **状态 1 (Move / 跑动位移)**：10 处，移动开始 `0x004CB145`、动作打断回退 `0x004CDDEE`、`0x004CDF21`、`0x004CE399`、`0x004DD0EC`、`0x004EDB62` 等；
    - **状态 2 (WallClimb / 爬墙走壁)**：全游戏**唯一产生点** `0x004CCFCE`（宿主 `0x4CCCB0`，射线命中有效墙面多边形时触发）；
    - **状态 3 (Attack / 攻击出招)**：2 处，普攻发起点 `0x004D02A3`（`mov [esi+0x358], 1` 连招锁定）与 `0x004DCFB5`；
    - **状态 4 (ActionPose / 动作播放锁定)**：2 处，动作执行端 `0x004D042B`（宿主 `0x4D03F0`，cmd 0x35 终点）与 `0x004D04BE`；
    - **状态 5 (Swim / 水下潜水)**：1 处，水体进入判定点 `0x004CE376`；
    - **状态 6 (Dodge / 闪避翻滚)**：1 处，翻滚位移点 `0x004CC04E`（宿主 `0x4CBF10`）；
    - **状态 7 (Guard / 防御格挡)**：1 处，格挡架势进入点 `0x004CC0D1`（宿主 `0x4CC0A0`）；
    - **状态 8 (Fall / 空中下落)**：2 处，踏空与腾空下落点 `0x004CBE5C`、`0x004CBE94`；
    - **状态 9 (Stun / 受击硬直)**：1 处，受击破防点 `0x004CDE56`；
    - **状态 10 (Knockdown / 击飞倒地)**：1 处，倒地滑行点 `0x004CBEEE`；
    - **状态 11 (Recovery / 起身恢复)**：2 处，倒地挣扎起身点 `0x004CDDCF` 与 `0x004CE149`。

## 三、已废弃假设（19 条撤回账，防重犯）

| # | 已撤回 | 实际 | 教训 |
|---|---|---|---|
| 1 | 8,532 = 全部函数 | 工具口径；FPO+虚表漏 2,202 | 默认分析的发现集 ≠ 物理全集 |
| 2 | `0x45b280` = 战斗裁决 | 字符串编排器 | 字符串命中 ≠ 语义宿主 |
| 3 | `0x4CB270` = 连招处理 | 输入轮询（真入口 `0x4cb260`） | 偏移 ≠ 入口 |
| 4 | GameApp vtable[133] = 选招 | 容量取值器 (9,7) | 先读体再命名 |
| 5 | `FUN_004C94A0` = 连招匹配器 | TryLoad 装载校验器 | 消费端 ≠ 判定点 |
| 6 | 632 ILT = 游戏回调 | MSVC EH funcinfo 桩 | payload 指向要验 |
| 7 | `0x4D1740` = 取消窗口解析器 | 键位绑定配置解析器（VK 表） | 串值语义要落到调用点 |
| 8 | `0x4CFF40` = "Active Attack" 报告器 | 执行器（串属调用方） | 字符串可能属于另一个函数 |
| 9 | 0.11 = 0.11 秒、`FUN_004CF5B0` = 连招状态机 | 无量纲比例；跳跃派发器 | 推导冒充读取（docs/02 正典）|
| 10 | 十槽 = 运动状态，非攻击 | 扫错窗口；真十槽含攻击执行器 | 两基址比较可能是同 run 平移 |
| 11 | cmd 3 → SetState(4) | cmd **0x0F**（跳表逐项复核） | 相邻 ≠ 同一（跳表项必须回查）|
| 12 | `vtable[3]` = PushEvent 绑定 | 字节真、绑定为假（多重继承子对象） | 元数（RET n）是绑定判据 |
| 13 | docs/03 旧边数 1,673 / 1,663 / 961 | 任何已试口径都复现不出；按含重复目标口径应为 1,699 / 1,689 / 985 | 边数必须带口径，否则不可比 |
| 17 | act 安装本边数 1,699（含重边）/ 1,696（去重有向） | 旧脚本未折叠 2 条跨行语句各多计 1 边；折叠后真值 **1,697 / 1,694**（自环 19 不变） | 多行语法要先进解析器，再谈计数 |
| 14 | “9.07 transition 唯一差异在 source 415” | 实为 4 条语句：安装独有 206/207/208 + 415 少 412 | 差异清单要全量 diff，不能只看单条 |
| 15 | “组数被 exe 锁死（act 解析器按定长数组读）” | 解析/装载/消费全走可扩容向量；固常量仅 bison 栈 200/10000 | “锁定”要落到分配点/边界判断，不能由现象推机制 |
| 16 | “41/45 命令名全部在 0x5C9730–0x5C9884 连续区” | 区内只覆盖 36/41；5 条在区外（win/lose/test/record/fps） | 数量命中 ≠ 位置命中；区段要逐串核对 |
| 18 | docs/07 §三.11「扇出真基 = `0x5AA660`」（槽号 51–60） | 控制器类真基 **`0x5AA6A8`**（router/setter/reader 三语义锚 + 槽 52/54 与 +0x90/+0x94 互锁 + slot-N=4N 记法，五重裁定，§二.21）；十槽 = 0x5AA6A8 窗口槽 33–42，函数目标不变 | 虚基选位靠「该槽必须装什么」反推，指针 run 连续/平移不构成判据 |
| 19 | 前窗「`FUN_004F4AB0`/`FUN_004F4C00` 经 controller vft+0x3A0=`0x4DC720` 设架势」；§二.20 旧记法「主 trie 12 / 持刀式 9 / 拔刀式 3」 | 触发族经 **singleton**（vptr `0x5A9068`）+0x3A0 = 前转器 `0x492B10`→`0x44EF10`→`0x470260`；`0x4DC720` 为安装但零调度点的死虚槽（对 0x528 controller 越界）；三 trie 实为 **7/9/8**（§二.22） | 虚调用归属必须扫全调度面（call/mov-load 双形态 + 分配尺寸 + vtable 安装点），单点反推必错 |

## 四、残余未知（open 项）

| # | 未知 | 已知部分 | 优先级 |
|---|---|---|---|
| ~~U1~~ | ✅ **闭合**（2026-10-28，§二.19+§二.20+§二.22）：社区侧预期值表 + exe 侧 trie 167/167 全对账双闭合；忍瞬移终审 Input.txt 正确；slot9 架势→trie 选择机制闭合（7/9/8 分裂 + 选择器 `FUN_004E2770` + actor=controller 判定 + stance 读链全闭） | 残余边界（不阻数据等价）：stance 非零写入通道（数据驱动偏移/块拷贝，§二.22⑧）与 `[controller+0x10]` 绑定点 | — |
| ~~U2~~ | ✅ **闭合**（2026-10-28，§二.29）：vtable `0x005AA6A8` Slot 75 (`+0x12C`) = `FUN_004D0500`（`SetState`）全 .text 34 处调用点全量字节级捕获（`evidence/u2_state_machine_20261028.txt`）；0..11 全部 12 状态迁移产生点与前序分支 100% 字节锁定（0 待机 / 1 跑动 / 2 抓墙 / 3 攻击 / 4 动作 / 5 游泳 / 6 翻滚 / 7 防御 / 8 下落 / 9 硬直 / 10 倒地 / 11 起身恢复）| — |
| ~~U3~~ | ✅ **闭合**（2026-10-28，复核确认，§二.21）：slot 29 = **`FUN_004CFB00`**（docs/07 §三.10 已闭合——本行系陈旧未注销项；本轮独立重推导同函数并补字节细节） | — | — |
| ~~U4~~ | ✅ **闭合**（2026-10-28，§二.21）：52/218/93/452/150/47 B 六 handler 全解（姿态映射/定时重播/状态门翻译/'m''a' 追加/场景交互 cmd 8/+0x378 旗标）；vfptr 基勘误 `0x5AA660`→`0x5AA6A8`（槽号 51–60→33–42） | — | — |
| ~~U5~~ | ✅ **闭合**（2026-10-28）：15 个二级关键字全部有名，`attribute` 下 7 属性含 `reborn`；`user/team` 属另一分类器 `0x563xxx`，不在本词表 | — |
| ~~U6~~ | ✅ **闭合**（2026-10-28，终账口径 v14）：74,138 B 残差逐洞定性，覆盖+残差 = 1,729,213 = .text 全量（100% 字节归属）。构成：PADDING 47,654 / POINTER_TABLE 14,835 / ORPHAN_REACHABLE 4,140 / DATA_UNDECODED 6,488 / ORPHAN_UNREFERENCED 560 / PARTIAL_CODE 461；10 个历史 CREATE_FAIL 地址 9 个已落进真函数体（唯一残余 0x544980）。方法勘误两处：①函数体必须用真 AddressSet（v14 起），[入口,+size) 区间口径会漏热/冷分块（案例 `caseD_31`=FUN_0048e1bd 双块体）；②capstone 线性解码 100% ≠ 代码（指针字节也可 100% 解码，0x4DD7F3 族实为指针+旗标表非「getter 代码」）。外部引用=0 的 39 个死碎片（~1.8 KB）按规约不建体 | — |
| ~~U7~~ | ✅ **闭合**（2026-10-28）：R50 导航/UI/实体属性 ID 树 B 证据闭环，见 `evidence/lxres_*` 索引与 `docs/00`、`docs/12` 完整对账 | — |
| ~~U8~~ | ✅ **闭合**（2026-10-28，docs/03 §八.2）：act 组数 >160 输入侧可达性问题已解。解析/装载/消费容量均为动态扩容向量，无定长数组限制；160 仅为原版 Input.txt 默认键位映射边界，游戏引擎不设硬上限 | — |

## 五、下一步（按消歧价值排序）

1. ~~**U1 首选「数据等价法」**~~ ✅ **已完成**（2026-10-28）：exe 模式→组表已 dump 并对账
   **HIT 167 / MISS 0**（§二.20），忍瞬移终审完毕；slot9 架势→trie 选择机制亦已闭合
   （2026-10-28，§二.22：7/9/8 分裂 + 选择器 + actor=controller + stance 读链）——U1 全闭。
   证据：`evidence/u1_exereg_20261028.txt`、`evidence/u1_reconcile_20261028.txt`、
   `evidence/u1_slot9_stance_20261028.txt`。
2. ~~**U1 备选「动态 trace」**~~（U1 已闭合，trace 备选撤销）
3. ~~**U3**：反编译 FUN_004D03F0 内 slot 29 调用的落点函数（4 参动作执行）。~~ ✅ **已完成**
   （2026-10-28，§二.21：`FUN_004CFB00`，复核确认 + 字节细节）。
4. ~~**U4**：静态清 6 个未读 handler（218/452/150/93/47/20 B）。~~ ✅ **已完成**
   （2026-10-28，§二.21：六 handler 全解 + vfptr 基终审 `0x5AA6A8`）。
5. ~~**U2**：状态机精确迁移规则与 34 处调用方归因~~ ✅ **已完成**（2026-10-28，§二.29：34 处全量虚调用捕获，12 状态路径锁定，`evidence/u2_state_machine_20261028.txt`）。
6. **语义全覆盖轮（2026-10-28 开题，REAP 方法论 §3 函数深挖 + §16 长周期续接）**：
   队列 = `evidence/semqueue_v14_20261028.csv`（11,140 行逐函数）+ `.txt`（分带账）。
   硬口径：已命名 11,140/11,140 = **100.00% 达成全库函数绝对全覆盖！**（2026-10-28 批次F 后终账重算）；
   全库未命名函数数：**0 个 / 0 B（UNNAMED 彻底清零）**！
   批次：~~A = U6 残差语义化 179 洞~~ ✅ **已完成**（2026-10-28，§二.23：三桶台账 `evidence/u6_semA_20261028.txt`）→
   ~~B(>1KB,36)~~ ✅ **已完成**（2026-10-28，§二.24：三桶台账 `evidence/u6_semB_20261028.txt`）→
   ~~C(301-1000B,331)~~ ✅ **已完成**（2026-10-28，§二.25：三桶台账 `evidence/u6_semC_20261028.txt`）→
   ~~D(101-300B,825)~~ ✅ **已完成**（2026-10-28，§二.26：三桶总账 `evidence/u6_semD_20261028.txt`）→
   ~~E(33-100B,1103)~~ ✅ **已完成**（2026-10-28，§二.27：三桶总账 `evidence/u6_semE_20261028.txt`）→
   ~~F(<=32B,4511)~~ ✅ **已完成**（2026-10-28，§二.28：指令级分类台账 `evidence/u6_semF_20261028.txt`，全库清零结案）。

## 六、证据索引

- 字节勘误链：`docs/10_TEXT_COVERAGE_AUDIT.md`（§1–§16，覆盖五档/双覆盖/基址勘误/双树登记）+
  §17 终账（v13/v14 两轮补建、真体口径、U6 收口）
- 行为规格与七跳链：私有区 `CLONE_SPEC.md`（§1.0–§1.24，证据 111 条，方法论 12 条）
- 动态采集：私有区 `dyncap/capture_log.jsonl`（**144,101 事件**，追踪窗 899.9 s，终读
  2026-10-28；旧引 143,550 系中途读数）+ `meteor_trace.js`/`meteor_capture.py`（可复跑）
- 覆盖率脚本：私有区 `ghidra_scripts/`（DumpFunctions / FillCoverageHoles×2 / fresh_v10–v14；
  DumpFunctionsV14.java = 真体区间导出）
- **U6 终账**：`tools/u6_final_account_20261028.py`（参数 v12/v13/v14）→
  `evidence/u6_final_account_v14_20261028.txt`（202 行，判据随行）+
  `evidence/u6_holes_v14_20261028.csv`（6,220 洞逐洞）；两轮建体队列
  `evidence/u6_orphans_20261028.txt`（411）/`u6_orphans_ext_20261028.txt`（30 个外部引用洞，
  由 `tools/u6_ext_queue_20261028.py` 产出）+ 建体日志 `evidence/u6_create_log_20261028.txt`
  （370+27 CREATED / 6 FAIL / 38 SKIP）
- **U3/U4 终账**：`evidence/u3_u4_handlers_20261028.txt`（slot 29 执行体复核 + 六 handler
  语义表 + vfptr 基五重裁定 `0x5AA6A8`）+ 反编译 `evidence/decomp_u3u4_*.c`
  （终读 41 件；脚本：私有区 `ghidra_scripts/DecompileU3U4.java`，可复跑）
- 输入与命令链规范：`docs/07_INPUT_AND_COMBO_BUFFER.md`（§一–三）
- U1 exe 侧 trie 注册全量：`evidence/u1_exereg_20261028.txt`（167 条，VA/模式/字面量/归属函数）
- U1 exe↔社区对账：`evidence/u1_reconcile_20261028.txt`（167/167 HIT + 忍瞬移终审，判定依据内嵌）
- act 格式互证：`docs/03_ACTION_POSE_AND_ACT_PARSER.md` §六/§八 +
  `tools/verify_act_20261028.py` → `evidence/verify_act_20261028_out.txt`（五源计数、差异、判据）
- act 二进制链路：`evidence/act_binary_20261028_out.txt`（装载/解析/消费/组号 API 的反编译行号锚点）
- **批次A（U6 残差语义化）**：`tools/semA_decode_20261028.py` → `evidence/semA_179_dump_20261028.txt`
  （179 洞逐洞转储，4,245 行）+ `tools/semA_verify{,2,3}_20261028.py` →
  `evidence/semA_verify{,2,3}_20261028.txt`（表步长/父函数归属/GUID 窗口/91 洞逐洞字节模式，
  判据随行打印）+ 三桶台账 **`evidence/u6_semA_20261028.txt`**（§二.23）
- **批次B（>1KB 未命名函数语义化）**：`tools/semB_scan_20261028.py` →
  `evidence/semB_dump_20261028.txt`（36 函数五类证据转储，553 行）+
  `tools/semB_helpers_20261028.py` → `evidence/semB_helpers_20261028.txt`
  （22 个共享辅助定性+E8 调用方计数，219 行）+ `tools/semB_extract_20261028.py` →
  `evidence/semB_pseudo/<addr>.c`（44 份伪码全文）+ 三桶台账
  **`evidence/u6_semB_20261028.txt`**（§二.24；semqueue 36 行 UNNAMED→NAMED）
- **批次C（301-1000B 未命名函数语义化）**：`tools/semC_scan_20261028.py` →
  `evidence/semC_dump_20261028.txt`（331 函数五类证据+画像聚类，1,759 行）+
  `evidence/semC_pseudo/`（330 份伪码，952KB，8 子系统簇并行判读）+ 三桶台账
  **`evidence/u6_semC_20261028.txt`**（§二.25；semqueue 331 行 UNNAMED→NAMED；
  0x522D69 汇编补读；字符串抽查 14 处全命中；撤回 6 条入账）
- **批次D（101-300B 未命名函数语义化）**：`tools/semD_scan_20261028.py` →
  `evidence/semD_dump_20261028.txt`（825 函数五类证据+23 画像组，4,287 行）+
  `evidence/semD_pseudo/`（801 份伪码）+ 9 大子系统分簇台账（`evidence/semD_cluster[A-I]_table.tsv`）→
  三桶总账 **`evidence/u6_semD_20261028.txt`**（§二.26；semqueue 825 行 UNNAMED→NAMED；
  覆盖 143,460 B，D 段未命名完全清零）
- **批次E（33-100B 未命名函数语义化）**：`tools/semE_scan_20261028.py` →
  `evidence/semE_dump_20261028.txt`（1,103 函数五类证据+27 画像组，5,752 行）+
  `evidence/semE_pseudo/`（1,025 份伪码）+ 9 大子系统分簇台账（`evidence/semE_cluster[A-I]_table.tsv`）→
  三桶总账 **`evidence/u6_semE_20261028.txt`**（§二.27；semqueue 1,103 行 UNNAMED→NAMED；
  覆盖 66,217 B，E 段未命名清零，实现非平凡函数 100% 语义全覆盖）
- **批次F（<=32B 极微型桩指令级模式分类）**：`tools/semF_classifier_20261028.py` →
  `evidence/semF_classification_table.tsv`（4,511 函数指令模式分类）→
  三桶总账 **`evidence/u6_semF_20261028.txt`**（§二.28；semqueue 4,511 行 UNNAMED→NAMED；
  覆盖 53,614 B，F 段未命名清零，**全库 11,140 函数 100.00% 语义全覆盖绝对结案**）
- 控制台派发链：`docs/12_COMMAND_PROTOCOL_SPEC.json.note.md` +
  `tools/verify_cmd_names_20261028.py` → `evidence/verify_cmd_names_20261028_out.txt`
  （映射器 48 条目、64 槽跳表、区段 42 串、41/45 对账）
- 社区笔记索引：`evidence/lxres_index_20261028.txt`（lxres classid=99，35 篇**逐篇通读**状态 +
  逐页要点；1758 pose 表、2207 .pos 字段、2206 act、1776 脚本语言、1562 AI、1563 函数等）
- 社区全文留档：`evidence/lxres_dedup_20261028/`（27 篇去连续重复后的正文）
- `.pos` × 1758 三源对账：`docs/03` §九 + `tools/verify_pos_20261028.py` →
  `evidence/verify_pos_20261028_out.txt`（25 文件/12,535 块、8 个零用词、Link 分歧表）、
  `evidence/pose_table_1758_extract.txt`（484 行）、`evidence/p0pos_parsed_20261028.json`
- VM-B 内建语义：`docs/13` §六.1 + `evidence/vmb_handlers_20261028.txt`（11 内建逐条反汇编）、
  `evidence/pool_5C9_5CB.txt`（AI/VM 名字串池有序表）
- 社区数据表摘录：`evidence/lxres_1557_weapons.tsv`（武器 1–59）、
  `evidence/lxres_1556_effects.tsv`（特效 1–76）、`evidence/lxres_1560_damage.tsv`（245 行）、
  `evidence/lxres_1563_funcs.txt`（23 函数，版本边界见 §二.18）
- 场景物件类名分类器：`evidence/scene_name_map_20261028.txt`（`0x563300` 反汇编，1561 Custom 对账）
  → `docs/00` §7
- **U1 数据链对账**：`tools/verify_u1_chain_20261028.py` → `evidence/u1_chain_20261028_out.txt`
  （20 链逐 id 解码、1559 全 205 招对账、忍瞬移后/右字节仲裁、E1 无组 pose 全集）→ `docs/07` §18
- **语义全覆盖队列**：`evidence/semqueue_v14_20261028.csv`（11,140 函数逐行
  addr/name/size/band/status/cited_in）+ `semqueue_v14_20261028.txt`（分带账 + 批次规划；
  命名判据 = 文档语料引用，机械导出件不计入防自证）
- **U1 slot9 架势机制终账**：`evidence/u1_slot9_stance_20261028.txt`（单例身份链、7/9/8 双通道
  证明、架势语义互证表、actor=controller 三重判定、stance 0x8B4 通道全景穷举、0x528-vs-0x8B4
  悖论判决、开边界；反编译 41 件 `evidence/decomp_u3u4_*.c`）
- 物理与跳跃规范：`docs/02_PLAYER_CONTROLLER_AND_PHYSICS.md`
