# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

# Update docs/09_CAMERA_AND_EFFECT_SYSTEM.md
path09 = r'D:\MeteorRE\docs\09_CAMERA_AND_EFFECT_SYSTEM.md'
with open(path09, 'r', encoding='utf-8') as f:
    text09 = f.read()

t09 = "| `40.0f` / `5.0f` 的真实归属 | ❓ 各有 10 / 12 个读取点，未逐个定性 |"
r09 = "| ~~`40.0f` / `5.0f` 的真实归属~~ | ✅ **闭合（2026-10-28）**：<br>① `40.0f`（`0x5A8E7C`）：在 `ChaseCamera::Update`（`0x004F6BF0`）作为**追尾相机防穿墙最小视距下界（Min Distance Clamp = 40.0f）**，与 `0x004F6B90` 处的最大裁剪界限 `70.0f`（`0x5A8E78`）配对；在 AI 系统（`0x00504AD0`）中作为常规近战攻击判定距离门限。<br>② `5.0f`（`0x5A8F74`）：在 `ExtraCamera::Update`（`0x004F6E8D`）作为角速度平滑乘数（Damping Factor = 5.0f）；在射线求交中作为碰撞安全缓冲距离（Clearance Buffer = 5.0f，见 `tools/verify_camera_floats_40_5_20261028.py`） |"

assert t09 in text09, "t09 not found"
text09 = text09.replace(t09, r09)
with open(path09, 'w', encoding='utf-8') as f:
    f.write(text09)
print("docs/09 updated.")

# Update docs/14_CROSSDOC_AUDIT.md
path14 = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path14, 'r', encoding='utf-8') as f:
    text14 = f.read()

t14 = "| `40.0f` / `5.0f` 归属 | ❓ 相机默认高度/跟随距离，读取点待逐个定性 |"
r14 = "| ~~`40.0f` / `5.0f` 归属~~ | ✅ **闭合（2026-10-28）**：`40.0f`（`0x5A8E7C`）为追尾相机防穿墙最小视距下界（`0x004F6BF0`，与最大界限 `70.0f` 配对）及 AI 近战攻击门限；`5.0f`（`0x5A8F74`）为相机角速度平滑乘数及射线避让缓冲间距 |"

assert t14 in text14, "t14 not found"
text14 = text14.replace(t14, r14)
with open(path14, 'w', encoding='utf-8') as f:
    f.write(text14)
print("docs/14 updated.")
