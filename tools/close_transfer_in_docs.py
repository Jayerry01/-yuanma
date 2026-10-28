# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

old_str = '| `Misc("transfer")` 是否真正传送 | ❓ 名/参数已锚；`0x56CB40` 只按首参返回 1 个整数，未写对象字段 |'
new_str = '| ~~`Misc("transfer")` 是否真正传送~~ | ✅ **闭合（2026-10-28）**：真实生效。`Misc`（`0x0056C770` 于 `0x0056C8D9`）调用 `0x564FC0` 提取路点 `[esi+0x28]+0x98` 坐标 Vec3，格式化 actor_id 后调用引擎事件钩子 `[0x5D186C]`（实装回调 `0x004D8CF0`）派发 `0x1E` 传送事件，最终调用 `WorldManager::Slot 200 (+0x31C)` 执行角色硬瞬移（见 `tools/verify_pscript_behavior_params_20261028.py`） |'

for path in [r'D:\MeteorRE\docs\13_PSCRIPT_VM.md', r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md']:
    with open(path, 'r', encoding='utf-8') as f:
        text = f.read()
    if old_str in text:
        text = text.replace(old_str, new_str)
        with open(path, 'w', encoding='utf-8') as f:
            f.write(text)
        print(f"Updated {path}")
    else:
        print(f"Old str not found in {path}")
