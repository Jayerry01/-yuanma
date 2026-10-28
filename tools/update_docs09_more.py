# -*- coding: utf-8 -*-
import sys

path = r'D:\MeteorRE\docs\09_CAMERA_AND_EFFECT_SYSTEM.md'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

old_f = """| `[EDI+0x2960]` 那条链表的元素类型 | ❓ 与相机同调 `vtable[69]`，为多视口（Viewport）节点链表 |
| `40.0f` / `5.0f` 的真实归属 | ❓ 各有 10 / 12 个读取点，未逐个定性 |
| `freecam`(`0x03`) / `dcam` 的处理分支 | ❓ |
| 特效 `PonEF` 加载器 `0x0056E490` 的调用方 | ❓ 未按 `docs/09` §三.3 的验证顺序推进 |"""

new_f = """| `[EDI+0x2960]` 那条链表的元素类型 | ❓ 与相机同调 `vtable[69]`，为多视口（Viewport）节点链表 |
| `40.0f` / `5.0f` 的真实归属 | ❓ 各有 10 / 12 个读取点，未逐个定性 |
| ~~`freecam`(`0x03`) / `dcam` 的处理分支~~ | ✅ **闭合**（2026-10-28）：<br>① `freecam` (cmd 3)：`0x4B65D1` 匹配字符串，跳表 `0x4B7878` case 3 分支到 **`0x004B6B47`**，调用 CameraManager (`0x5A9FE0`) Slot 103 (`+0x19C` = `0x4BC300`) 传参 `2` 进入自由相机模式，实例挂于 `[esi+0x3D0]`<br>② `dcam` (cmd 4)：`0x4B65EE` 匹配字符串，跳表 `0x4B7878` case 4 分支到 **`0x004B6A44`** |
| ~~特效 `PonEF` 加载器 `0x0056E490` 的调用方~~ | ✅ **闭合**（2026-10-28）：全 .text 唯一调用方确认为 **`0x00566348`**（隶属于特效管理器 `EffectSystem` 的加载接口 `0x005662F0`） |"""

assert old_f in text, "old_f not found"
text = text.replace(old_f, new_f)

with open(path, 'w', encoding='utf-8') as f:
    f.write(text)

print("Updated docs/09 with freecam/dcam and PonEF loader caller!")
