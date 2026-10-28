# 控制台层（2026-10-28，二进制派发链表 × 社区指令表复核）

> 注：docs/12 主体是 JSON spec；控制台层为补充笔记，随后并入 JSON 的 channels。

## 修正：不是“连续字符串区”，而是真派发链

上版“41/45 个命令名以字符串存在于 0x5C9730–0x5C9884”只证明了字符串存在，未证明派发。
本轮定位到控制台命令的**映射器 + 执行器**：

- **映射器** `[0x4B63B0, 0x4B6940)`：48 条 if-else 链，每条
  `mov edi,<串>; mov ecx,<len+1>; repe cmpsb`（连结尾 NUL 精确比较）→ `mov eax,<id>`。
  实测 **48 条目 / 48 个 id / 47 个唯一名字**，长度 48/48 = `strlen+1`。
  `host` 注册两次：`0x3F` 先命中，`0x07` 为死条目。
- **执行器** `0x4B6940`：`call [edx+0x110]`（取 id）→ `dec eax; cmp eax,0x3F; ja default;
  jmp [eax*4+0x4B7878]`。跳表 64 槽，**48 个 id 有处理、16 个落 default**
  （`0x1A–0x1F`、`0x21–0x29`、`0x2E`）。`cheat → 0x2E → default`：有名可映射，无处理分支。
- **vtable 锚点**：映射器指针 `@0x5A9178 = 0x5A9068+0x110`；执行器指针 `@0x5A9174 = +0x10C`。

## 41/45 对账（结论）

- 44 条社区名 + 变体 `box off` = 45；精确命中 40，加 `FPS → fps`（大小写不敏感）1 条 = **41/45**。
- **其中只有 36 条在 0x5C9730–0x5C9884 区内**；5 条在区外：
  `win@0x5C972C`、`lose@0x5C9724`（紧邻区前）、`test@0x5C7B4C`、`record@0x5C7644`、`fps@0x5C68A0`。
- 区内共 42 条字符串，**全部被映射器引用（42/42）**；其中 36 条 = 社区名，另 6 条为社区表外
  （`serverinfo`、`replay`、`save`、`load`、`closeserver`、`dcam`）。
- 缺失 3 条：`disarm`、`reset`、`box off` 在 exe 中无独立 NUL 终止串（`reset`/`FPS` 仅有子串出现，不算）；
  `IP` 仅作为 `.data` 网络配置键 `@0x5C422C`，不在控制台链。
- 正确表述：**41/45 在 exe 中以独立命令名存在；控制台派发链为 48 条目**；
  “全部位于 0x5C9730–0x5C9884 连续区”**不成立**（区内只覆盖 36/41）。

## 命令清单（社区语义，全部有名可查）

- **实体/外观**：pose X（播动作）、weapon X（换武器）、loadch/loadmych/loadmyno pX X
  （换皮肤/pos 切换/换人物）、disarm/reset X（解除/恢复武装）、dropw、switch
- **传送/调试**：moveto X X X、position（查坐标）、box/box off（3D 框线）、wave X X X
- **状态/作弊**：mhp（全员 HP/SP/攻防）、ang（气绝全满）、win/lose（主机直判胜负）、
  cheat、testserver、test
- **场景/会话**：loadsnp snX（切场景）、loadsn、joins（UI 入场隐藏界面）、freecam（配
  loadsnp 主界面自由视角）、play（刷新本局）、editai（**AI 路点编辑器**，Shift+S 保存）、
  host（接管主机）、IP X（直连）
- **网络/系统**：lag 0-255（模拟延时！）、shows（服务器 IP）、mnet、FPS、kick/skick/kill id、
  camera 0/1、msense/minverse、elight、quit、record、AI [档名]（载 SN 档 AI——PST 通道）
- `adddummy 1 2 3`（人物 0-19、队伍 0-3、武器 1-59）——**武器编号上限 59** 与 res 表对接；
  参数范围的社区侧依据：[人物资料表 ID 0–19](https://www.lxres.com/LiuXingBiJi/1554.html)、
  [武器编号表 1–59](https://www.lxres.com/LiuXingBiJi/1552.html)（社区数据，非 exe 证据）

## 语义注释

- `lag X`（0-255 人为延时）= 联机同步调试旋钮——与 docs/00 附录 int16×10 同步量化互证利器
- `editai` = 路点编辑器入口——docs/08 路点格式、docs/13 §十一 目标点表的源头
- `pose X`/`weapon X` = 直接驱动 docs/02 状态机与武器映射器（vft+0x28）的运行时入口
- 使用前缀 `\`（单反斜杠）+ 隐藏开关（docs/00 附录 loadsnp 条目）

## 复现

- `tools/verify_cmd_names_20261028.py` → `evidence/verify_cmd_names_20261028_out.txt`
  （区段转储、映射器逐条反汇编与长度核对、跳表解码、社区名单对账）。
- 被测 exe：`C:\Program Files (x86)\Meteor\Meteor.exe`，1,945,600 B，sha256 `baebb6d5…`。
