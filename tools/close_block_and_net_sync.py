# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

# Update docs/13_PSCRIPT_VM.md
path13 = r'D:\MeteorRE\docs\13_PSCRIPT_VM.md'
with open(path13, 'r', encoding='utf-8') as f:
    text13 = f.read()

t13_1 = "| `block` | `0x5C9B6C` | （池中有，❓ 未见调用点） |"
r13_1 = "| `block` | `0x5C9B6C` | 玩家动作队列执行器 `0x004C0730`（取 `[ebp+0x18]` 调 `0x004C3900` 切换格挡状态 `Player::SetBlock(0/1)`）；场景描述表 `0x005B0214`（阻挡碰撞） |"
assert t13_1 in text13, "t13_1 not found"
text13 = text13.replace(t13_1, r13_1)

t13_2 = "`[0x5D1784]` 的函数指针（属性变更的网络同步出口，❓ 具体实现未读）。"
r13_2 = "`[0x5D1784]` 的函数指针（属性变更网络同步出口，✅ **已闭合**：由 `0x004936BD` 注册实装为 `0x004D95D0`，首参为事件类型；类型 2 接收 `(2, obj, 属性号, v)`，调用 `WorldManager::Slot 167 (+0x29C)` 执行全网广播同步）。"
assert t13_2 in text13, "t13_2 not found"
text13 = text13.replace(t13_2, r13_2)

t13_3 = "| `block` 动作名的调用点 | ❓ |"
r13_3 = "| ~~`block` 动作名的调用点~~ | ✅ **闭合（2026-10-28）** = 玩家动作队列执行器 `0x004C0730`（匹配后调 `0x004C3900` 即 `Player::SetBlock(0/1)`）；场景描述表 `0x005B0214`（阻挡碰撞属性） |"
assert t13_3 in text13, "t13_3 not found"
text13 = text13.replace(t13_3, r13_3)

t13_4 = "| 属性变更网络出口 `[0x5D1784]` | ❓ 仅在 `[0x72B6A8]!=0` 时调用，实参 `(2,obj,属性号,v)` |"
r13_4 = "| ~~属性变更网络出口 `[0x5D1784]`~~ | ✅ **闭合（2026-10-28）** = 实装为 `0x004D95D0`（由 `0x004936BD` 注册）。实参首参 2 为属性更新包，内部调用 `WorldManager::Slot 167 (+0x29C)` 执行服务器全网多播同步 |"
assert t13_4 in text13, "t13_4 not found"
text13 = text13.replace(t13_4, r13_4)

with open(path13, 'w', encoding='utf-8') as f:
    f.write(text13)
print("Updated docs/13 successfully.")

# Update docs/14_CROSSDOC_AUDIT.md
path14 = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path14, 'r', encoding='utf-8') as f:
    text14 = f.read()

assert t13_3 in text14, "t13_3 not found in docs/14"
text14 = text14.replace(t13_3, r13_3)

# In docs/14, check if property hook is there
if t13_4 in text14:
    text14 = text14.replace(t13_4, r13_4)
    print("Replaced t13_4 in docs/14.")
else:
    print("t13_4 not found in docs/14, searching variant...")
    for l in text14.splitlines():
        if '0x5D1784' in l:
            print("Found in docs/14:", l)

with open(path14, 'w', encoding='utf-8') as f:
    f.write(text14)
print("Updated docs/14 successfully.")
