# -*- coding: utf-8 -*-
# 簇G（图像/音频/3DNow! 82个）、簇H（网络栈/大厅 98个）、簇I（场景/PVS/样条/粒子 182个）综合分析
import os, sys, glob, re, csv
sys.stdout.reconfigure(encoding='utf-8')

PSEUDO_DIR = 'D:/MeteorRE/evidence/semD_pseudo'
DUMP_FILE = 'D:/MeteorRE/evidence/semD_dump_20261028.txt'

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
    if 0x520000 <= fa < 0x5A0000:
        funcs_dump[fa_str.lower()] = block.strip()

print(f"找到 Dump 记录: {len(funcs_dump)} / 362")

analysis = []
for fa_str, dump_block in sorted(funcs_dump.items()):
    fa = int(fa_str, 16)
    c_path = os.path.join(PSEUDO_DIR, f"{fa_str}.c")
    has_pseudo = os.path.exists(c_path)
    pseudo_snippet = ""
    if has_pseudo:
        lines = open(c_path, 'r', encoding='utf-8', errors='replace').readlines()
        code_lines = [l.strip() for l in lines if l.strip() and not l.strip().startswith(('/*', '*', '//', 'undefined', 'int ', 'uint ', 'float ', 'short ', 'char ', 'byte '))]
        pseudo_snippet = ' | '.join(code_lines[:6])
    
    dlines = dump_block.splitlines()
    header = dlines[0]
    callers = dlines[1] if len(dlines) > 1 else ""
    callees = dlines[2] if len(dlines) > 2 else ""
    iat = dlines[3] if len(dlines) > 3 else ""
    strings = [l for l in dlines if l.startswith('[4] 串')]
    str_info = strings[0] if strings else ""
    f32s = [l for l in dlines if l.startswith('[5] f32')]
    f32_info = f32s[0] if f32s else ""
    
    if fa < 0x540000:
        cl_name = 'G'
    elif fa < 0x560000:
        cl_name = 'H'
    else:
        cl_name = 'I'
    
    analysis.append({
        'addr': fa_str.upper(),
        'fa': fa,
        'cluster': cl_name,
        'header': header,
        'callers': callers,
        'callees': callees,
        'iat': iat,
        'str_info': str_info,
        'f32_info': f32_info,
        'pseudo': pseudo_snippet[:140]
    })

out_path = 'D:/MeteorRE/evidence/semD_clusterGHI_analysis.txt'
with open(out_path, 'w', encoding='utf-8') as f:
    for a in analysis:
        f.write(f"=== {a['addr']} [Cluster {a['cluster']}] ({a['header']}) ===\n")
        f.write(f"  {a['callers']}\n")
        f.write(f"  {a['callees']}\n")
        if a['str_info']: f.write(f"  {a['str_info']}\n")
        if a['f32_info']: f.write(f"  {a['f32_info']}\n")
        f.write(f"  [PSEUDO]: {a['pseudo']}\n\n")

print(f"分析写入 {out_path} 完成")
