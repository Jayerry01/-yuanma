# -*- coding: utf-8 -*-
import sys

sys.stdout.reconfigure(encoding='utf-8')

# Update docs/13_PSCRIPT_VM.md
path13 = r'D:\MeteorRE\docs\13_PSCRIPT_VM.md'
with open(path13, 'r', encoding='utf-8') as f:
    text13 = f.read()

t13 = "| VM 是字节码还是 AST 直解 | ❓ 未见字节码分派特征，倾向 AST/树遍历，无证据 |"
r13 = "| ~~VM 是字节码还是 AST 直解~~ | ✅ **闭合（2026-10-28）** = 纯 AST 递归语法树遍历解释（Tree-Walk Interpreter），无字节码中间表示。`FunctionNode::Execute`（`0x00570F80`）遍历 `m_ppStatements` 数组对每个节点调虚表 Slot 2 `call dword ptr [edx+8]`（`StatementNode::Execute`）；全模块无 `switch(*pc++)` 字节码分派循环（见 `tools/verify_pscript_ast_interpreter_20261028.py`） |"

assert t13 in text13, "t13 not found"
text13 = text13.replace(t13, r13)

with open(path13, 'w', encoding='utf-8') as f:
    f.write(text13)
print("docs/13 updated.")

# Update docs/14_CROSSDOC_AUDIT.md
path14 = r'D:\MeteorRE\docs\14_CROSSDOC_AUDIT.md'
with open(path14, 'r', encoding='utf-8') as f:
    text14 = f.read()

t14 = "| VM 是字节码还是 AST 直解 | ❓ 倾向 AST，无证据 |"
r14 = "| ~~VM 是字节码还是 AST 直解~~ | ✅ **闭合（2026-10-28）** = 纯 AST 递归语法树遍历解释（Tree-Walk Interpreter），无字节码中间表示。`FunctionNode::Execute`（`0x00570F80`）遍历节点调虚表 Slot 2 `call dword ptr [edx+8]`；无字节码提取/调度循环 |"

assert t14 in text14, "t14 not found"
text14 = text14.replace(t14, r14)

with open(path14, 'w', encoding='utf-8') as f:
    f.write(text14)
print("docs/14 updated.")
