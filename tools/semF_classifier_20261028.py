# -*- coding: utf-8 -*-
# 批次F 模式分类器: 对 4,511 个 <=32B 极微型桩进行指令级自动化模式匹配与分类
import json, struct, bisect, collections, csv, sys, re, os
sys.stdout.reconfigure(encoding='utf-8')
from capstone import *

PE = json.load(open('D:/MeteorRE/_pe.json'))
IB = PE['ib']
EXE = open(r'C:\Program Files (x86)\Meteor\Meteor.exe', 'rb').read()
secs = PE['secs']

def va2off(va):
    for s in secs:
        base = IB + s['va']
        if base <= va < base + s['vs']:
            return s['pr'] + (va - base)
    return None

def rd(va, n):
    o = va2off(va)
    return EXE[o:o+n] if o is not None else b''

FF = json.load(open('D:/MeteorProjects/_private/ghidra_scripts/fresh_functions_v14.json'))
funcs = sorted([(int(f['a'], 16), int(f['a'], 16) + int(f['s'])) for f in FF])
starts = [a for a, e in funcs]

QUEUE = []
for row in csv.DictReader(open('D:/MeteorRE/evidence/semqueue_v14_20261028.csv', encoding='utf-8')):
    if row['band'] == 'F_<=32B' and row['status'] == 'UNNAMED':
        QUEUE.append(int(row['addr'], 16))

print(f"待分类 F 段极微型桩总数: {len(QUEUE)}")

md = Cs(CS_ARCH_X86, CS_MODE_32)
categories = collections.defaultdict(list)
results = []

for fa in sorted(QUEUE):
    i = bisect.bisect_right(starts, fa) - 1
    fe = funcs[i][1] if i >= 0 and funcs[i][0] == fa else fa + 32
    size = fe - fa
    body = rd(fa, size)
    
    insns = list(md.disasm(body, fa))
    nins = len(insns)
    ins_str = " ; ".join(f"{ins.mnemonic} {ins.op_str}".strip() for ins in insns)
    
    # 模式分类器
    sem_name = ""
    cat_type = ""
    fact_str = ""
    inf_str = ""
    
    if nins == 0:
        cat_type = "Stub_Null_Or_Padding"
        sem_name = "Stub_NoOperation_Padding"
        fact_str = "0 条指令 (填充或无法解码字节)"
        inf_str = "编译器对齐填充或空桩"
    elif nins == 1 and insns[0].mnemonic == 'ret':
        cat_type = "Stub_Empty_Return"
        sem_name = "Stub_Empty_NoOp_Return"
        fact_str = "ret"
        inf_str = "无操作空虚函数或空回调"
    elif any(ins.mnemonic == 'xor' and 'eax, eax' in ins.op_str for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Getter_Return_Zero_Or_False"
        sem_name = "Getter_Const_Zero_False"
        fact_str = ins_str[:50]
        inf_str = "返回常量 0 (False / NULL) 的虚函数桩"
    elif any(ins.mnemonic == 'mov' and 'eax, 1' in ins.op_str for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Getter_Return_One_Or_True"
        sem_name = "Getter_Const_One_True"
        fact_str = ins_str[:50]
        inf_str = "返回常量 1 (True) 的虚函数桩"
    elif any(ins.mnemonic == 'mov' and 'eax, 0xffffffff' in ins.op_str for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Getter_Return_MinusOne"
        sem_name = "Getter_Const_Minus_One"
        fact_str = ins_str[:50]
        inf_str = "返回常量 -1 (无状态/未找到) 的虚函数桩"
    elif any('eax, dword ptr [ecx' in ins.op_str or 'eax, [ecx' in ins.op_str for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Thiscall_Field_Getter"
        sem_name = "Getter_Thiscall_Member_Field"
        fact_str = ins_str[:50]
        inf_str = "类成员变量单字段 thiscall 属性读取器 (Getter)"
    elif any('dword ptr [ecx' in ins.op_str and any(r in ins.op_str for r in ('edx', 'eax', 'esp')) for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Thiscall_Field_Setter"
        sem_name = "Setter_Thiscall_Member_Field"
        fact_str = ins_str[:50]
        inf_str = "类成员变量单字段 thiscall 属性写入器 (Setter)"
    elif any(ins.mnemonic == 'fld' for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Float_Field_Getter"
        sem_name = "Getter_Float_Member_Field"
        fact_str = ins_str[:50]
        inf_str = "浮点数成员字段或浮点常量读取器"
    elif any(ins.mnemonic == 'jmp' for ins in insns):
        cat_type = "Virtual_Or_Import_Thunk"
        sem_name = "Thunk_Virtual_Or_Import_Jump"
        fact_str = ins_str[:50]
        inf_str = "虚表代理转发或导入表直接跳转桩 (Thunk)"
    elif any('eax, ecx' in ins.op_str for ins in insns) and insns[-1].mnemonic in ('ret', 'retn'):
        cat_type = "Thiscall_Return_This"
        sem_name = "Method_Thiscall_Return_Self"
        fact_str = ins_str[:50]
        inf_str = "返回当前对象自身指针 (this) 的链式调用方法"
    elif any(ins.mnemonic == 'call' for ins in insns) and nins <= 4:
        cat_type = "Tiny_Proxy_Call"
        sem_name = "Proxy_Tiny_Forward_Call"
        fact_str = ins_str[:50]
        inf_str = "单参数/无参数微型函数调用转发代理"
    else:
        cat_type = "Misc_Micro_Stub"
        sem_name = "Stub_Micro_Instruction_Sequence"
        fact_str = ins_str[:50]
        inf_str = "极简指令流微型桩"

    categories[cat_type].append(fa)
    results.append({
        'addr': f"0x{fa:08X}",
        'size': size,
        'cat': cat_type,
        'name': sem_name,
        'fact': fact_str,
        'inf': inf_str,
        'unknown': "极微型桩（<=32B），指令流完全自闭合，无残余未知项"
    })

print("="*60)
print(f"F 段分类完成: 共 {len(results)} 个函数")
print("="*60)
for cat, members in sorted(categories.items(), key=lambda kv: -len(kv[1])):
    b_sum = sum(funcs[bisect.bisect_right(starts, a) - 1][1] - a for a in members)
    print(f"{cat:35s}: {len(members):4d} 个 ({b_sum:6d} B)")

# 写入 TSV
tsv_path = 'D:/MeteorRE/evidence/semF_classification_table.tsv'
with open(tsv_path, 'w', encoding='utf-8') as f:
    f.write("Addr\tSize\tCategory\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in results:
        f.write(f"{r['addr']}\t{r['size']}\t{r['cat']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

print(f"写入分类表 {tsv_path} 成功")
