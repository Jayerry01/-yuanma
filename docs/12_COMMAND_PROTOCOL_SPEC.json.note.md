# 控制台层（2026-10-27，社区指令表 × 二进制名表互证）

> 注：docs/12 主体是 JSON spec；控制台层为补充笔记，随后并入 JSON 的 channels。

## 名表锚定

社区两份指令表（隐藏 30+ 条 / 通用 11 条）与二进制互证：**41/45 个命令名以字符串
存在于连续数据区 0x5C9730–0x5C9884**（控制台派发名表）。锚点样例：
`editai@0x5C9730`、`adddummy2@0x5C973C`、`adddummy@0x5C9748`、`mhp@0x5C976C`、
`loadsnp@0x5C97B4`、`moveto@0x5C97BC`、`loadmych@0x5C97E4`、`freecam@0x5C9800`、
`host@0x5C9824`、`cheat@0x5C9810`、`kill@0x5C9858`、`position@0x5C9884`。

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
- `adddummy 1 2 3`（人物 0-19、队伍 0-3、武器 1-59）——**武器编号上限 59** 与 res 表对接

## 语义注释

- `lag X`（0-255 人为延时）= 联机同步调试旋钮——与 docs/00 附录 int16×10 同步量化互证利器
- `editai` = 路点编辑器入口——docs/08 路点格式、docs/13 §十一 目标点表的源头
- `pose X`/`weapon X` = 直接驱动 docs/02 状态机与武器映射器（vft+0x28）的运行时入口
- 使用前缀 `\`（单反斜杠）+ 隐藏开关（docs/00 附录 loadsnp 条目）
