# -*- coding: utf-8 -*-
# 批次A: U6 残差 179 洞语义化解码转储 (REAP 批次A)
# 每洞产出: hexdump+ASCII / capstone 从 frac 最佳起点解码 / 4LE 指针值分析 /
#          float/double 候选 / 引用点上下文解码
# 判定依据全部随行打印 (常设铁律)
import json, csv, re, struct, sys
sys.stdout.reconfigure(encoding='utf-8')
from capstone import *

PE = json.load(open('D:/MeteorRE/_pe.json'))
IB = PE['ib']
EXE = open(r'C:\Program Files (x86)\Meteor\Meteor.exe', 'rb').read()

def va2off(va):
    for s in PE['secs']:
        base = IB + s['va']
        if base <= va < base + s['vs']:
            return s['pr'] + (va - base)
    return None

def rd(va, n):
    o = va2off(va)
    return EXE[o:o+n] if o is not None else b''

TEXT = [s for s in PE['secs'] if s['name'] == '.text'][0]
T0, T1 = IB + TEXT['va'], IB + TEXT['va'] + TEXT['rs']
TDATA = EXE[TEXT['pr']:TEXT['pr']+TEXT['rs']]

md = Cs(CS_ARCH_X86, CS_MODE_32)

# 引用通道: C1 E8/E9 rel32 目标落洞内; C2 EB/Jcc rel8 落洞内; C3 全.text 4LE == 洞内地址
def find_refs(lo, hi):
    refs = []
    i = 0
    n = len(TDATA)
    while True:
        i = TDATA.find(b'\xe8', i)
        if i < 0: break
        if i+5 <= n:
            t = T0 + i + 5 + struct.unpack('<i', TDATA[i+1:i+5])[0]
            if lo <= t < hi: refs.append((T0+i, 'E8', t))
        i += 1
    i = 0
    while True:
        i = TDATA.find(b'\xe9', i)
        if i < 0: break
        if i+5 <= n:
            t = T0 + i + 5 + struct.unpack('<i', TDATA[i+1:i+5])[0]
            if lo <= t < hi: refs.append((T0+i, 'E9', t))
        i += 1
    i = 0
    while i < n-1:
        b = TDATA[i]
        if b in (0xEB, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
                 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F):
            t = T0 + i + 2 + struct.unpack('<b', TDATA[i+1:i+2])[0]
            if lo <= t < hi: refs.append((T0+i, 'Jcc8', t))
        i += 1
    # C3: 4LE 指向洞内
    for off in range(0, n-3):
        v = struct.unpack('<I', TDATA[off:off+4])[0]
        if lo <= v < hi:
            refs.append((T0+off, '4LE', v))
    refs.sort()
    return refs

def hexdump(va, data, maxb=96):
    out = []
    for i in range(0, min(len(data), maxb), 16):
        chunk = data[i:i+16]
        hx = ' '.join(f'{b:02x}' for b in chunk)
        asc = ''.join(chr(b) if 0x20 <= b < 0x7f else '.' for b in chunk)
        out.append(f"  {va+i:08X}  {hx:<47}  |{asc}|")
    if len(data) > maxb:
        out.append(f"  ... (+{len(data)-maxb} B)")
    return '\n'.join(out)

def decode_range(va, data, maxn=140):
    out = []
    for ins in md.disasm(data[:maxn], va):
        out.append(f"  {ins.address:08X}  {ins.bytes.hex():<16} {ins.mnemonic} {ins.op_str}")
    return '\n'.join(out) if out else '  (decode empty)'

def ptr_analysis(va, data):
    n4 = len(data)//4
    in_text = in_rdata = in_data = zero = 0
    floats = []
    for i in range(n4):
        v = struct.unpack('<I', data[i*4:i*4+4])[0]
        if v == 0: zero += 1
        elif T0 <= v < T1: in_text += 1
        elif 0x5A7000 <= v < 0x5C0000: in_rdata += 1
        elif 0x5C0000 <= v < 0x680000: in_data += 1
    for i in range(len(data)//4):
        f = struct.unpack('<f', data[i*4:i*4+4])[0]
        if f != 0 and (abs(f) < 1e6 and (abs(f) > 1e-4 or f in (0.0,))):
            if f == f and abs(f) not in (0,):  # not NaN
                floats.append(f)
    f8 = []
    for i in range(len(data)//8):
        d = struct.unpack('<d', data[i*8:i*8+8])[0]
        if d != 0 and abs(d) < 1e7 and abs(d) > 1e-6 and d == d:
            f8.append(d)
    return (f"  dword@text={in_text} rdata={in_rdata} data={in_data} zero={zero} / {n4}"
            f"  | f32 cand={floats[:6]}{'...' if len(floats)>6 else ''} f64 cand={f8[:4]}")

rows = list(csv.DictReader(open('D:/MeteorRE/evidence/u6_holes_v14_20261028.csv', encoding='utf-8')))
batch = [r for r in rows if r['kind'] in ('DATA_UNDECODED','PARTIAL_CODE','ORPHAN_REACHABLE','ORPHAN_UNREFERENCED')]
batch.sort(key=lambda r: (r['kind'], -int(r['n'])))

out = open('D:/MeteorRE/evidence/semA_179_dump_20261028.txt', 'w', encoding='utf-8')
out.write("# 批次A 逐洞转储 (179 洞, U6 v14 残差语义化)\n")
out.write("# 解码: capstone 从洞起点(frac 列最佳偏移)线性; 引用三通道 C1=E8/E9 rel32, C2=EB/Jcc rel8, C3=.text 内 4LE==洞内地址\n")
out.write("# 引用点上下文: 前后各 12 字节 capstone 重解\n\n")

cur_kind = None
for r in batch:
    lo, hi, kind = int(r['s']), int(r['e']), r['kind']
    if kind != cur_kind:
        cur_kind = kind
        out.write(f"\n{'='*74}\n== KIND {kind} ==\n{'='*74}\n")
    data = rd(lo, hi-lo)
    out.write(f"\n--- {lo:08X}-{hi:08X} n={hi-lo} frac={r['frac']} off={r['off']} refs={r['refs']} ref0={r['ref0']} ---\n")
    out.write(hexdump(lo, data, 96) + '\n')
    out.write("  PTR: " + ptr_analysis(lo, data).strip() + '\n')
    refs = find_refs(lo, hi)
    out.write(f"  REFS recomputed: {len(refs)}\n")
    seen = set()
    for ra, ch, t in refs[:10]:
        if ra in seen: continue
        seen.add(ra)
        ctx = rd(ra-12, 30)
        out.write(f"    ref@{ra:08X} [{ch} -> {t:08X}]\n")
        lines = []
        for ins in md.disasm(ctx, ra-12):
            mark = '  <<<' if ins.address <= ra < ins.address + ins.size else ''
            lines.append(f"      {ins.address:08X}  {ins.mnemonic} {ins.op_str}{mark}")
        out.write('\n'.join(lines) + '\n')
    if kind in ('ORPHAN_REACHABLE','PARTIAL_CODE','ORPHAN_UNREFERENCED'):
        out.write("  DECODE from hole start:\n" + decode_range(lo, data) + '\n')
out.close()
print("written D:/MeteorRE/evidence/semA_179_dump_20261028.txt")
import os
print("size:", os.path.getsize('D:/MeteorRE/evidence/semA_179_dump_20261028.txt'))
