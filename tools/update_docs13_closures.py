# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

DOC_PATH = r'D:\MeteorRE\docs\13_PSCRIPT_VM.md'
with open(DOC_PATH, 'r', encoding='utf-8') as f:
    text = f.read()

target1 = """**这一条很关键**：脚本 `Perform()` 与玩家按键走的是同一个动作词表，
意味着 `docs/07` 记的输入 → 动作映射，和脚本驱动的角色用的是**同一个下游**。
（❓ 具体 ID 数值未解——中心派发器 `0x504C40`–`0x504F60` 里每个名字分支体较长，
需单独一轮。）"""

replacement1 = """**全流程闭合（2026-10-28 经汇编硬核复核与测试集验证）**：
- `FUN_00504be0`（`0x00504BE0`–`0x00504F4E`）为 `Perform` 的每帧动作执行驱动函数（`PerformAction_Update`），由 `Perform`（`0x004F94C5`）通过 `0x4FD630` 挂载为当前行为回调。它逐个匹配上述 9 大动作名，并由 `[ebx+0x88]` 提供执行参数/倒计时（如 `pause` 剩余帧数、`guard` 保持时间、`crouch` 开关标志）。
- **证伪“573 个 ActionID 派发表”误区**：紧随其后的 `0x00504F50` 并非动作派发，而是 **128 项 ASCII 矢量字形单字渲染器**（`DrawVectorGlyph(char c)`，索引 `0x5CA3A0`，按 `0.0625f` 即 1/16 缩放网格），由字符串绘制循环 `DrawVectorString`（`0x00501815`）逐字调用。原先猜测的“573 个 ActionID 集中派发”彻底证伪并闭合（见 `tools/verify_pscript_behavior_params_20261028.py`）。"""

# Handle CRLF vs LF
if target1.replace('\r\n', '\n') in text.replace('\r\n', '\n'):
    # Normalize for replacement
    if '\r\n' in text:
        target1 = target1.replace('\n', '\r\n')
        replacement1 = replacement1.replace('\n', '\r\n')
    text = text.replace(target1, replacement1)
    print("Replacement 1 done.")
else:
    print("Target 1 not found!")

target2 = "| `attacktarget` 第 4 参写入的 `+0x88` 语义 | ❓ |"
replacement2 = "| ~~`attacktarget` 第 4 参写入的 `+0x88` 语义~~ | ✅ **闭合（2026-10-28）** = 攻击重复执行计数器（`attack_count`）。若 `>0`，近身判定门限放宽至 80.0f（`0x5AB870`）；若 `≤0`，使用近身常规 40.0f（`0x5A8E7C`）。在有效距离与 30 度视角（`0x4FCED0`）内触发 `0x500C90` 攻击（`rand()%3` 变招），并执行 `dec [ESI+0x88]`，直至减至 0 调用 `0x4FD870` 退出行为 |"

target3 = "| 中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值 | ❓ |"
replacement3 = "| ~~中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值~~ | ✅ **闭合（2026-10-28）** = 证实不存在 573 个 ActionID 集中派发。`0x504BE0` 为 9 大 Perform 动词分派；`0x504F50` 为 128 项 ASCII 矢量字形单字渲染器（索引 `0x5CA3A0`，1/16 缩放） |"

assert target2 in text, "Target 2 not found"
text = text.replace(target2, replacement2)
print("Replacement 2 done.")

assert target3 in text, "Target 3 not found"
text = text.replace(target3, replacement3)
print("Replacement 3 done.")

with open(DOC_PATH, 'w', encoding='utf-8') as f:
    f.write(text)
print("docs/13_PSCRIPT_VM.md updated successfully.")
