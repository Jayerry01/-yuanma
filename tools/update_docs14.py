# -*- coding: utf-8 -*-
import sys

path = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

# Update camera items
old_cam = """| 相机对象 vtable 是 18 张候选中的哪一张 | ❓ RTTI 已关 |
| 追尾相机每帧 Update 方法 | ❓ 已确认槽只有 `[69]`/`[99]`/`[115]` |
| `[EDI+0x2960]` 链表元素类型 | ❓ 疑多镜头/多视口 |
| `40.0f` / `5.0f` 归属 | ❓ 各 10 / 12 个读取点 |
| `freecam`(`0x03`) / `dcam` 处理分支 | ❓ |
| `PonEF` 加载器 `0x0056E490` 调用方 | ❓ |"""

new_cam = """| ~~相机对象 vtable 是 18 张候选中的哪一张~~ | ✅ **闭合**（2026-10-28）：`BaseCamera`=0x5AB670, `ChaseCamera`=0x5AB710, `ExtraCamera`=0x5AB7A8, `CameraManager`=0x5A9FE0 |
| ~~追尾相机每帧 Update 方法~~ | ✅ **闭合**（2026-10-28）：`ChaseCamera` 虚表 Slot 1 = `0x004F5FA0`（3,248 B 大函数，高精度计时驱动） |
| `[EDI+0x2960]` 链表元素类型 | ❓ 多视口（Viewport）节点链表 |
| `40.0f` / `5.0f` 归属 | ❓ 相机默认高度/跟随距离，读取点待逐个定性 |
| ~~`freecam`(`0x03`) / `dcam` 处理分支~~ | ✅ **闭合**（2026-10-28）：`freecam`=cmd 3 -> `0x4B6B47` -> 调 Slot 103 入模式 2；`dcam`=cmd 4 -> `0x4B6A44` |
| ~~`PonEF` 加载器 `0x0056E490` 调用方~~ | ✅ **闭合**（2026-10-28）：全 .text 唯一调用方 `0x00566348`（`EffectSystem::LoadEffectFile`） |"""

assert old_cam in text, "old_cam not found"
text = text.replace(old_cam, new_cam)

# Update AI item
old_ai = """| 视场 `cos ≥ 0.5`、5 个宏观 AI 状态 | `docs/08` §一 | ❓ 二进制中无对应 |"""
new_ai = """| ~~视场 `cos ≥ 0.5`、5 个宏观 AI 状态~~ | `docs/08` §一 | ✅ **证伪撤除**：二进制中无此结构，真实架构为 `docs/13` §四 的 8 大原生行为（`wait`/`idle`/`run`/`follow`/`patrol`/`attacktarget`/`kill`/`dodge`）与 `.pst` 18 属性 |"""

assert old_ai in text, "old_ai not found"
text = text.replace(old_ai, new_ai)

# Update dyncap line in Section 5
old_dyncap = """| 2 | `dyncap/capture_log.jsonl` **产物缺失** —— 需重跑 Frida 采集并落到 `D:\MeteorRE\dyncap\`，否则 `docs/02` §十一 与 `docs/11` 的动态数据始终不可复现 | 高 |"""
new_dyncap = """| 2 | ~~`dyncap/capture_log.jsonl` 产物缺失~~ | ✅ **已落盘**（2026-10-28，14.7 MB，144,101 事件，动态数据已闭环） | — |"""

assert old_dyncap in text, "old_dyncap not found"
text = text.replace(old_dyncap, new_dyncap)

with open(path, 'w', encoding='utf-8') as f:
    f.write(text)

print("Updated docs/14 successfully!")
