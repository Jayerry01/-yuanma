# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

# Update docs/13_PSCRIPT_VM.md
path13 = r'D:\MeteorRE\docs\13_PSCRIPT_VM.md'
with open(path13, 'r', encoding='utf-8') as f:
    text13 = f.read()

t13_1 = "（每个名字都取两次，❓ 推测一次读当前值、一次读默认值，未验证。）"
r13_1 = "（每个名字调两次 GetScriptInt：✅ **已闭合**（2026-10-28）。源码写法为 `if (GetVariable(\"View\")) { val = GetVariable(\"View\")->GetShort(); }`，首次判断是否存在，二次提取写入 `ActorController + 0x430..+0x44A` 的 14 属性结构体字段，见 `tools/verify_combo_strings_and_ai_attr_20261028.py`。）"
assert t13_1 in text13, "t13_1 not found"
text13 = text13.replace(t13_1, r13_1)

t13_2 = "| AI 属性\"取两次\"的含义 | ❓ |"
r13_2 = "| ~~AI 属性\"取两次\"的含义~~ | ✅ **闭合（2026-10-28）** = 源码未暂存指针所致（`if (GetVar(\"X\")) val = GetVar(\"X\")->GetShort()`）。提取值写入 `ActorController` 的 14 项属性结构体（`View +0x430`、`Think +0x432`、`Guard +0x434`、`Dodge +0x436`、`Jump +0x438`、`Look +0x43A`、`Burst +0x43C`、`Aim +0x43E`、`GetItem +0x440`、`Attack1 +0x442`、`Attack2 +0x444`、`Attack3 +0x446`、`Spawn +0x448`、`HP +0x44A`） |"
assert t13_2 in text13, "t13_2 not found"
text13 = text13.replace(t13_2, r13_2)

t13_3 = "| `0x5CA1FC` 连招键串池的消费方 | ❓ |"
r13_3 = "| ~~`0x5CA1FC` 连招键串池的消费方~~ | ✅ **闭合（2026-10-28）** = `FUN_004ff200`（`0x004FF200`–`0x005005A3`，5,028 字节）。这是 AI 武器招式出招库构建器（`AI_InitWeaponCombos`），为 12 种武器装配 15 种合法出招方向组合序列（`lrfb`、`bbf`、`bff`、`lrb`、`fff` 等共 77 处挂载） |"
assert t13_3 in text13, "t13_3 not found"
text13 = text13.replace(t13_3, r13_3)

with open(path13, 'w', encoding='utf-8') as f:
    f.write(text13)
print("docs/13 updated.")

# Update docs/14_CROSSDOC_AUDIT.md
path14 = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path14, 'r', encoding='utf-8') as f:
    text14 = f.read()

assert t13_2 in text14, "t13_2 not found in docs/14"
text14 = text14.replace(t13_2, r13_2)

assert t13_3 in text14, "t13_3 not found in docs/14"
text14 = text14.replace(t13_3, r13_3)

with open(path14, 'w', encoding='utf-8') as f:
    f.write(text14)
print("docs/14 updated.")
