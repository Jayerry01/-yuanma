# -*- coding: utf-8 -*-
import sys

# 1. Update docs/02
path2 = r'D:\MeteorRE\docs\02_PLAYER_CONTROLLER_AND_PHYSICS.md'
with open(path2, 'r', encoding='utf-8') as f:
    text2 = f.read()

old_p2 = '| `Pose90` 是唯一可处于状态 4 的动作 | ❓ 未反驳，但仅为单会话观测 |'
new_p2 = '| ~~`Pose90` 是唯一可处于状态 4 的动作~~ | ✅ **已证伪推翻**：`0x004D042B` 与 `0x004D04BE` 两处 `SetState(4)` 均由 cmd 0x35 动作派发器驱动，可锁定任意指定动作，不限于 Pose90 |'

assert old_p2 in text2, "old_p2 not found"
text2 = text2.replace(old_p2, new_p2)
with open(path2, 'w', encoding='utf-8') as f:
    f.write(text2)

# 2. Update docs/14
path14 = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path14, 'r', encoding='utf-8') as f:
    text14 = f.read()

old_p14 = '| `Pose90` 是唯一可处于状态 4 的动作 | `docs/02` | ❓ 仅单会话观测 |'
new_p14 = '| ~~`Pose90` 是唯一可处于状态 4 的动作~~ | `docs/02` | ✅ **已证伪推翻**：cmd 0x35 派发器可在 `0x4D042B` 将任意指定动作置为状态 4 |'

assert old_p14 in text14, "old_p14 not found"
text14 = text14.replace(old_p14, new_p14)
with open(path14, 'w', encoding='utf-8') as f:
    f.write(text14)

print("Updated docs/02 and docs/14 state 4 item successfully!")
