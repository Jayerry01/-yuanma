# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

DOC_PATH = r'D:\MeteorRE\docs\13_PSCRIPT_VM.md'
with open(DOC_PATH, 'r', encoding='utf-8') as f:
    text = f.read()

target = """  - `transfer(id, dname)`：按名查物件后 `sprintf("%d", id)`，把结果交给
    `[0x5D186C]` 指向的 `0x56CB40`（该函数按首参返回 3/-1/0/1，
    ❓ 传送是否真正生效未验证——`0x56CB40` 不写任何对象字段）。"""

replacement = """  - `transfer(id, dname)`：✅ **已闭合**（2026-10-28）。`0x564FC0` 提取路点 `[esi+0x28]+0x98` 坐标 Vec3，`sprintf("%d", id)` 后传实参 `(0x1E, id_str, &Vec3)` 调用引擎事件钩子 `[0x5D186C]`；该钩子由 `0x004936B3` 注册为 `0x004D8CF0`，判定 `0x1E` 事件后调用 `WorldManager::Slot 200 (+0x31C)` 传参 `(actor_id, 0x4D, &Vec3, 0x40, 1)` 完成角色物理坐标硬重定位与网络同步。此前“指向 0x56CB40”实为看错返回码工具函数的陈旧误区。"""

if target.replace('\r\n', '\n') in text.replace('\r\n', '\n'):
    if '\r\n' in text:
        target = target.replace('\n', '\r\n')
        replacement = replacement.replace('\n', '\r\n')
    text = text.replace(target, replacement)
    with open(DOC_PATH, 'w', encoding='utf-8') as f:
        f.write(text)
    print("Fixed line 379-382 in docs/13_PSCRIPT_VM.md")
else:
    print("Target not found!")
