# -*- coding: utf-8 -*-
# 批次E 伪码抽取: 从 Meteor_all_functions.c 切出 1,103 个 33-100B 函数
import re, os, sys, csv
sys.stdout.reconfigure(encoding='utf-8')

SRC = 'D:/MeteorRE/decompiled_full/Meteor_all_functions.c'
OUT = 'D:/MeteorRE/evidence/semE_pseudo'
os.makedirs(OUT, exist_ok=True)

TARGETS = set()
for r in csv.DictReader(open('D:/MeteorRE/evidence/semqueue_v14_20261028.csv', encoding='utf-8')):
    if r['band'] == 'E_33-100B' and r['status'] == 'UNNAMED':
        TARGETS.add(r['addr'].lower())

print("批次E 目标函数数:", len(TARGETS))

lines = open(SRC, encoding='utf-8', errors='replace').read().split('\n')
hdr = re.compile(r'^[A-Za-z_][A-Za-z0-9_ \*]*\bFUN_([0-9a-fA-F]{8})\s*\(|^FUN_([0-9a-fA-F]{8})\s*\(')

defs = []
for i, ln in enumerate(lines):
    m = hdr.match(ln)
    if m:
        g1 = m.group(1)
        defs.append(((g1 if g1 else m.group(2)).lower(), i))
print("全集函数定义总数:", len(defs))

found = 0
for k, (fa, i) in enumerate(defs):
    if fa in TARGETS:
        end = defs[k+1][1] if k + 1 < len(defs) else len(lines)
        body = '\n'.join(lines[i:end])
        open(f'{OUT}/{fa}.c', 'w', encoding='utf-8').write(body)
        found += 1

print("抽出 %d / %d" % (found, len(TARGETS)))
missing = TARGETS - {f for f, _ in defs}
if missing:
    print("缺失 (%d 个):" % len(missing), sorted(missing)[:20])
