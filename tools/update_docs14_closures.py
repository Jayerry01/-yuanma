# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

path = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

old_blk = """| `attacktarget` 第 4 参写入的 `+0x88` 语义 | ❓ |
| 中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值 | ❓ |"""

new_blk = """| ~~`attacktarget` 第 4 参写入的 `+0x88` 语义~~ | ✅ **闭合（2026-10-28）**：攻击重复执行计数器（`attack_count`）。若 `>0`，判定门限放宽至 80.0f（`0x5AB870`）；若 `≤0`，使用常规 40.0f（`0x5A8E7C`）。在有效距离与 30 度视角内触发 `0x500C90` 攻击，并执行 `dec [ESI+0x88]`，减至 0 时调用 `0x4FD870` 退出行为 |
| ~~中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值~~ | ✅ **闭合（2026-10-28）**：证实不存在 573 个 ActionID 派发表。`0x504BE0` 为 9 大 Perform 动作动词执行器；`0x504F50` 为 128 项 ASCII 矢量字形单字渲染器（索引 `0x5CA3A0`，1/16 缩放），由 `DrawVectorString`（`0x501815`）逐字调用 |"""

old_vp = '| `[EDI+0x2960]` 链表元素类型 | ❓ 多视口（Viewport）节点链表 |'
new_vp = '| ~~`[EDI+0x2960]` 链表元素类型~~ | ✅ **闭合（2026-10-28）**：转发器 `0x492D80` 对每个节点调同 `vtable[69]`（`0x004D0AC0`），与 `[EBP+0x2488]` 实例相机虚表 `0x005AA658` 同调，为多机位兄弟视口节点链表 |'

if '\r\n' in text:
    old_blk = old_blk.replace('\n', '\r\n')
    new_blk = new_blk.replace('\n', '\r\n')

assert old_blk in text, "old_blk not found"
text = text.replace(old_blk, new_blk)

assert old_vp in text, "old_vp not found"
text = text.replace(old_vp, new_vp)

with open(path, 'w', encoding='utf-8') as f:
    f.write(text)
print("Updated docs/14_CROSSDOC_AUDIT.md successfully.")
