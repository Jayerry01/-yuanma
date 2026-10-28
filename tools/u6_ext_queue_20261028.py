# -*- coding: utf-8 -*-
# U6 第二轮建体队列: v14 ORPHAN_REACHABLE 洞中, 外部引用 >=1 的才可建
# 内部引用(洞内跳点)不算证据; 全零外部引用 = 死碎片, 不建
import csv, struct

BIN = r"C:\Program Files (x86)\Meteor\Meteor.exe"
OUT = r"D:\MeteorRE\evidence\u6_orphans_ext_20261028.txt"
IB = 0x400000
TEXT_LO, TEXT_HI = 0x401000, 0x5A72BD

d = open(BIN, 'rb').read()
rows = list(csv.DictReader(open(r"D:\MeteorRE\evidence\u6_holes_v14_20261028.csv")))
orph = [r for r in rows if r['kind'] == 'ORPHAN_REACHABLE']

def ref_sites(s, e):
    sites = []
    i = TEXT_LO - IB
    n = TEXT_HI - IB
    while i < n - 5:
        op = d[i]
        if op in (0xE8, 0xE9):
            t = i + IB + 5 + struct.unpack_from('<i', d, i + 1)[0]
            if s <= t < e: sites.append(i + IB)
            i += 5
        else:
            i += 1
    i = TEXT_LO - IB
    while i < n - 2:
        op = d[i]
        if op == 0xEB or 0x70 <= op <= 0x7F:
            t = i + IB + 2 + struct.unpack_from('<b', d, i + 1)[0]
            if s <= t < e: sites.append(i + IB)
        i += 1
    for i in range(TEXT_LO - IB, n - 4):
        v = struct.unpack_from('<I', d, i)[0]
        if s <= v < e: sites.append(i + IB)
    return sites

out = []
tot_ext = 0
for r in sorted(orph, key=lambda r: -int(r['n'])):
    s, e, n = int(r['s']), int(r['e']), int(r['n'])
    sites = set(ref_sites(s, e))
    ext = sorted(x for x in sites if not (s <= x < e))
    tag = 'QUEUE' if ext else 'DEAD'
    if ext: tot_ext += n
    out.append((s, n, len(sites), len(ext), ext[0] if ext else 0, tag))
    print('%08X-%08X %5d B  sites=%2d ext=%2d first_ext=%s  %s'
          % (s, e, n, len(sites), len(ext), hex(ext[0]) if ext else 'NONE', tag))

with open(OUT, 'w') as f:
    for s, n, si, ex, fe, tag in out:
        if tag == 'QUEUE':
            f.write('%08X %d\n' % (s, n))
print('queue holes=%d bytes=%d ; dead fragments=%d' % (sum(1 for o in out if o[5]=='QUEUE'), tot_ext, sum(1 for o in out if o[5]=='DEAD')))
print('written', OUT)
