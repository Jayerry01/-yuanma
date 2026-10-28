# -*- coding: utf-8 -*-
# 簇A（渲染器底层/软光栅/D3D 59个函数）特征综合分析脚本
import os, sys, glob, re, csv
sys.stdout.reconfigure(encoding='utf-8')

PSEUDO_DIR = 'D:/MeteorRE/evidence/semD_pseudo'
DUMP_FILE = 'D:/MeteorRE/evidence/semD_dump_20261028.txt'

# 1. 读取 semD_dump 中这 59 个函数的 dump 段
dump_text = open(DUMP_FILE, 'r', encoding='utf-8').read()
funcs_dump = {}
for block in dump_text.split('FUN '):
    if not block.strip():
        continue
    fa_str = block[:8]
    try:
        fa = int(fa_str, 16)
    except ValueError:
        continue
    if 0x400000 <= fa < 0x430000:
        funcs_dump[fa_str.lower()] = block.strip()

print(f"找到 Dump 记录: {len(funcs_dump)} / 59")

# 2. 读取对应伪码文件，提炼特征
analysis = []
for fa_str, dump_block in sorted(funcs_dump.items()):
    c_path = os.path.join(PSEUDO_DIR, f"{fa_str}.c")
    has_pseudo = os.path.exists(c_path)
    pseudo_snippet = ""
    if has_pseudo:
        lines = open(c_path, 'r', encoding='utf-8', errors='replace').readlines()
        # 过滤掉纯类型声明，保留前 15 行核心逻辑
        code_lines = [l.strip() for l in lines if l.strip() and not l.strip().startswith(('/*', '*', '//', 'undefined', 'int ', 'uint ', 'float ', 'short ', 'char ', 'byte '))]
        pseudo_snippet = ' | '.join(code_lines[:6])
    
    # 提取 dump 中的关键行
    dlines = dump_block.splitlines()
    header = dlines[0]
    callers = dlines[1] if len(dlines) > 1 else ""
    callees = dlines[2] if len(dlines) > 2 else ""
    iat = dlines[3] if len(dlines) > 3 else ""
    strings = [l for l in dlines if l.startswith('[4] 串')]
    str_info = strings[0] if strings else ""
    f32s = [l for l in dlines if l.startswith('[5] f32')]
    f32_info = f32s[0] if f32s else ""
    
    analysis.append({
        'addr': fa_str.upper(),
        'header': header,
        'callers': callers,
        'callees': callees,
        'iat': iat,
        'str_info': str_info,
        'f32_info': f32_info,
        'pseudo': pseudo_snippet[:140]
    })

out_path = 'D:/MeteorRE/evidence/semD_clusterA_analysis.txt'
with open(out_path, 'w', encoding='utf-8') as f:
    for a in analysis:
        f.write(f"=== {a['addr']} ({a['header']}) ===\n")
        f.write(f"  {a['callers']}\n")
        f.write(f"  {a['callees']}\n")
        if a['str_info']: f.write(f"  {a['str_info']}\n")
        if a['f32_info']: f.write(f"  {a['f32_info']}\n")
        f.write(f"  [PSEUDO]: {a['pseudo']}\n\n")

print(f"分析写入 {out_path} 完成")
