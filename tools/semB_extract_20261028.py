# -*- coding: utf-8 -*-
# 批次B 伪码抽取: 从 Meteor_all_functions.c 切出 36 函数 + 关键辅助
import re, os, sys
sys.stdout.reconfigure(encoding='utf-8')

SRC = 'D:/MeteorRE/decompiled_full/Meteor_all_functions.c'
OUT = 'D:/MeteorRE/evidence/semB_pseudo'
os.makedirs(OUT, exist_ok=True)

TARGETS = {
    '00417c20', '00418070', '004184c0', '00418900', '00418e00', '0041a490',
    '0041b6b0', '00423c30', '00424360', '00424ac0', '00425200', '00425970',
    '004261e0', '00426680', '00426a80', '00427300', '004277b0', '0043c710',
    '0045e1e0', '00464600', '004772e0', '00479a00', '0047c570', '00484860',
    '004de220', '004e0080', '004e0ed0', '00511758', '0051c801', '0051db02',
    '0052dce0', '005364d0', '00538f90', '0054a740', '00579a90', '00596c8d',
    # 关键辅助 (命名判据用)
    '0050ab32', '0050a85c', '00509607', '005089fd', '00509980',
    # 集群被调方 (命名判据用)
    '00428ba0', '00428a20', '00484400', '00434ec0', '00481ee0',
}

lines = open(SRC, encoding='utf-8', errors='replace').read().split('\n')
hdr = re.compile(r'^[A-Za-z_][A-Za-z0-9_ \*]*\bFUN_([0-9a-fA-F]{8})\s*\(|^FUN_([0-9a-fA-F]{8})\s*\(')
# 函数定义行索引
defs = []
for i, ln in enumerate(lines):
    m = hdr.match(ln)
    if m:
        g1 = m.group(1)
        defs.append(((g1 if g1 else m.group(2)).lower(), i))
print("函数定义总数 %d" % len(defs))

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
    print("缺失:", sorted(missing))
