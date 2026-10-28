# -*- coding: utf-8 -*-
import sys

path = r'D:\MeteorRE\INVESTIGATION.md'
with open(path, 'r', encoding='utf-8') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    if line.startswith('| U5 |'):
        line = '| ~~U5~~ | ✅ **闭合**（2026-10-28）：15 个二级关键字全部有名，`attribute` 下 7 属性含 `reborn`；`user/team` 属另一分类器 `0x563xxx`，不在本词表 | — |\n'
    elif line.startswith('| U7 |'):
        line = '| ~~U7~~ | ✅ **闭合**（2026-10-28）：R50 导航/UI/实体属性 ID 树 B 证据闭环，见 `evidence/lxres_*` 索引与 `docs/00`、`docs/12` 完整对账 | — |\n'
    elif line.startswith('| U8 |'):
        line = '| ~~U8~~ | ✅ **闭合**（2026-10-28，docs/03 §八.2）：act 组数 >160 输入侧可达性问题已解。解析/装载/消费容量均为动态扩容向量，无定长数组限制；160 仅为原版 Input.txt 默认键位映射边界，游戏引擎不设硬上限 | — |\n'
    elif '5. **U2**：如需精确迁移规则' in line:
        line = '5. ~~**U2**：状态机精确迁移规则与 34 处调用方归因~~ ✅ **已完成**（2026-10-28，§二.29：34 处全量虚调用捕获，12 状态路径锁定，`evidence/u2_state_machine_20261028.txt`）。\n'
    new_lines.append(line)

with open(path, 'w', encoding='utf-8') as f:
    f.writelines(new_lines)

print("INVESTIGATION.md updated all U items to closed.")
