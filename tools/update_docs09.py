# -*- coding: utf-8 -*-
import sys

path = r'D:\MeteorRE\docs\09_CAMERA_AND_EFFECT_SYSTEM.md'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

old_f = """### F. 未知

| 项 | 状态 |
|---|---|
| ~~`camera`(`0x39`) 的处理分支~~ | ✅ **闭合** = `0x4B6A05`–`0x4B6A3F`，相机对象 `+0x2488`，见 §二·补 E |
| 相机对象 vtable 具体是 18 张中的哪一张 | ❓ RTTI 已关，需靠方法体特征逐个排除 |
| 追尾相机的**每帧 Update** 方法 | ❓ 已确认的槽只有 `vtable[69]` / `[99]` / `[115]`，Update 未指认 |
| `[EDI+0x2960]` 那条链表的元素类型 | ❓ 与相机同调 `vtable[69]`，疑为多镜头/多视口，未证实 |
| `40.0f` / `5.0f` 的真实归属 | ❓ 各有 10 / 12 个读取点，未逐个定性 |
| `freecam`(`0x03`) / `dcam` 的处理分支 | ❓ |
| 特效 `PonEF` 加载器 `0x0056E490` 的调用方 | ❓ 未按 `docs/09` §三.3 的验证顺序推进 |"""

new_f = """### F. 未知与最新闭合（2026-10-28 逆向闭环）

| 项 | 状态 | 证明细节 |
|---|---|---|
| ~~`camera`(`0x39`) 的处理分支~~ | ✅ **闭合** | `0x4B6A05`–`0x4B6A3F`，调 CameraManager (`0x5A9FE0`) Slot 115 (`+0x1CC` = `0x4BB4B0`) 转发内层相机 Slot 17 (`+0x44` = `0x4F6C70`)，字符串 `0x5C98AC` "Switch Extra Camera." |
| ~~相机对象 vtable 具体是 18 张中的哪一张~~ | ✅ **闭合** | 构造链反查全解：<br>① `BaseCamera`：构造 `0x004F58F0`（0x78B），vtable = **`0x005AB670`**<br>② `ChaseCamera`（追尾相机）：构造 `0x004F5D60`（0xA8B），vtable = **`0x005AB710`**<br>③ `ExtraCamera`（战斗锁视/自由附加相机）：构造 `0x004F7200`（0xB0B），vtable = **`0x005AB7A8`**<br>外层 CameraManager（`[0x6659b8] + 0x2488`）构造 `0x004B96C0`，主虚表 = **`0x005A9FE0`**（`+0x10` 辅虚表 `0x005A9FAC`） |
| ~~追尾相机的**每帧 Update** 方法~~ | ✅ **闭合** | **`ChaseCamera` 虚表 `0x005AB710` Slot 1（`+0x04`）= `0x004F5FA0`**（3,248 字节大函数）。读取高精度计时器（异常串 `0x5C9F9C` "performance counter Error!"），结合跟踪角色 `[esi + 0x80]` 矩阵与视线做障碍裁剪平滑更新；外层 CameraManager 驱动入口为 `Slot 1 (+0x04) = 0x004B9F80` |
| `[EDI+0x2960]` 那条链表的元素类型 | ❓ 与相机同调 `vtable[69]`，为多视口（Viewport）节点链表 |
| `40.0f` / `5.0f` 的真实归属 | ❓ 各有 10 / 12 个读取点，未逐个定性 |
| `freecam`(`0x03`) / `dcam` 的处理分支 | ❓ |
| 特效 `PonEF` 加载器 `0x0056E490` 的调用方 | ❓ 未按 `docs/09` §三.3 的验证顺序推进 |"""

assert old_f in text, "old_f not found"
text = text.replace(old_f, new_f)

with open(path, 'w', encoding='utf-8') as f:
    f.write(text)

print("Updated docs/09 successfully!")
