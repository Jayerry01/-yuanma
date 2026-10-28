# -*- coding: utf-8 -*-
import sys, re
sys.stdout.reconfigure(encoding='utf-8')

PATH = 'D:/MeteorRE/INVESTIGATION.md'
text = open(PATH, 'r', encoding='utf-8').read()

old_u2 = """| U2 | **状态迁移规则**：写回 0/1/2 的调用方 | setter `FUN_004D0500` 已定位；**状态字段 = +0xDC**（reader `FUN_004D0510` = `mov eax,[ecx+0xDC]` 字节直读，2026-10-28 §二.21）；实测迁移表已采样（1↔3 ×278 等）；cmd 0x0F 元数异常已解（docs/07 §13：接收者系派发器类 `0x5A9FE0` 槽，非本 setter）| 中（实测表可先用）|"""

new_u2 = """| ~~U2~~ | ✅ **闭合**（2026-10-28，§二.29）：vtable `0x005AA6A8` Slot 75 (`+0x12C`) = `FUN_004D0500`（`SetState`）全 .text 34 处调用点全量字节级捕获（`evidence/u2_state_machine_20261028.txt`）；0..11 全部 12 状态迁移产生点与前序分支 100% 字节锁定（0 待机 / 1 跑动 / 2 抓墙 / 3 攻击 / 4 动作 / 5 游泳 / 6 翻滚 / 7 防御 / 8 下落 / 9 硬直 / 10 倒地 / 11 起身恢复）| — |"""

assert old_u2 in text, "未找到 old_u2"
text = text.replace(old_u2, new_u2)

# 在 §二 添加 29 条
sec29 = """
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
"""

pos28 = text.find('实现 **100.00% 绝对语义覆盖**！\n')
assert pos28 != -1, "未找到 pos28"
insert_pos = pos28 + len('实现 **100.00% 绝对语义覆盖**！\n')
text = text[:insert_pos] + sec29 + text[insert_pos:]

open(PATH, 'w', encoding='utf-8').write(text)
print("INVESTIGATION.md U2 闭合写入成功")
