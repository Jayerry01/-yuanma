# -*- coding: utf-8 -*-
# 批次A 验证: (1) 0x5241E0 记录表步长+尾结构+指向区转储 (2) dispatcher 父函数归属 (3) 0x508BD7 本体
import json, struct, sys
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

md = Cs(CS_ARCH_X86, CS_MODE_32)
out = []

# ---------- (1) 0x5241D2 表: 步长验证 ----------
out.append("="*70)
out.append("(1) 0x5241D2-0x525550 DATA_UNDECODED 记录表验证")
out.append("="*70)
# 前 14 字节 (0x5241D2-0x5241DF) 先看
head = rd(0x5241D2, 0x5241E0-0x5241D2)
out.append(f"head 0x5241D2-0x5241DF: {head.hex(' ')}")
# 311 记录 x 16B 从 0x5241E0
rec_end = 0x5241E0 + 311*16
out.append(f"record area 0x5241E0 + 311*16 = {rec_end:08X}")
# 验证每条记录: dword ptr / dword idx*4 / 8 bytes
ok_ptr = ok_idx = 0
ptr_lo, ptr_hi = 0xFFFFFFFF, 0
idx_lo, idx_hi = 0xFFFFFFFF, 0
tail_bytes = set()
for i in range(311):
    r = rd(0x5241E0 + i*16, 16)
    p = struct.unpack('<I', r[0:4])[0]
    ix = struct.unpack('<I', r[4:8])[0]
    if 0x5AD000 <= p < 0x5B0000: ok_ptr += 1
    ptr_lo, ptr_hi = min(ptr_lo,p), max(ptr_hi,p)
    if ix % 4 == 0 and ix < 0x10000: ok_idx += 1
    idx_lo, idx_hi = min(idx_lo,ix), max(idx_hi,ix)
    tail_bytes.update(r[8:16])
out.append(f"311 记录: ptr∈[0x5AD000,0x5B0000) 命中 {ok_ptr}/311, ptr范围 {ptr_lo:08X}-{ptr_hi:08X}")
out.append(f"idx*4 命中 {ok_idx}/311, idx 范围 {idx_lo:08X}-{idx_hi:08X}")
out.append(f"尾 8 字节取值集合: {sorted(tail_bytes)}")
# 尾区结构 0x524BA4-0x525550
out.append("\n尾区 0x524BA4-0x525550 按 4LE 分类:")
tail = rd(0x524BA4, 0x525550-0x524BA4)
import collections
cls = collections.Counter()
for i in range(0, len(tail)-3, 4):
    v = struct.unpack('<I', tail[i:i+4])[0]
    if v == 0: cls['zero'] += 1
    elif 0x5AD000 <= v < 0x5B0000: cls['ptr_5AD'] += 1
    elif 0x400000 <= v < 0x5A0000: cls['text'] += 1
    elif 0x5C0000 <= v < 0x600000: cls['rdata'] += 1
    else: cls['other'] += 1
out.append(f"  {dict(cls)}  (total dwords {len(tail)//4})")
# 指向区 0x5AD200-0x5AD280 转储
out.append("\n指向区 0x5AD200-0x5AD280 (rdata?):")
d = rd(0x5AD200, 0x80)
for i in range(0, len(d), 16):
    out.append(f"  {0x5AD200+i:08X}  {d[i:i+16].hex(' ')}")
# 该区落在哪个节
for s in PE['secs']:
    base = IB + s['va']
    if base <= 0x5AD200 < base + s['vs']:
        out.append(f"  → 节 {s['name']} (va {s['va']:08X})")

# ---------- (2) dispatcher 父函数归属 ----------
out.append("\n" + "="*70)
out.append("(2) dispatcher → 父函数 (fresh_functions_v14.json)")
out.append("="*70)
FF = json.load(open('D:/MeteorProjects/_private/ghidra_scripts/fresh_functions_v14.json'))
funcs = sorted([(int(f['a'], 16), int(f['a'], 16) + int(f['s'])) for f in FF])
out.append(f"函数总数 {len(FF)}")
import bisect
starts = [a for a,e in funcs]
def parent(va):
    i = bisect.bisect_right(starts, va) - 1
    if i < 0: return None
    a,e = funcs[i]
    if a <= va < e: return (a, e, e-a)
    # 不在内部: 报前一个函数
    return (a, e, None)
dispatchers = [
    ('0x48B6DF', 0x48B6DF), ('0x53CA86', 0x53CA86), ('0x4AD566', 0x4AD566),
    ('0x4CC75E', 0x4CC75E), ('0x54EE96', 0x54EE96), ('0x4D8E9E', 0x4D8E9E),
    ('0x4D9010', 0x4D9010), ('0x52ED66', 0x52ED66), ('0x52F1AF', 0x52F1AF),
    ('0x56EF52', 0x56EF52), ('0x42EE83', 0x42EE83), ('0x42D845', 0x42D845),
    ('0x4E4BAB', 0x4E4BAB), ('0x4B28BD', 0x4B28BD),
    # PARTIAL_CODE dispatchers
    ('0x411236', 0x411236), ('0x41134A', 0x41134A), ('0x4114E0', 0x4114E0),
    ('0x42BEA4', 0x42BEA4), ('0x47E23D', 0x47E23D), ('0x47E27E', 0x47E27E),
    ('0x40B501', 0x40B501), ('0x50931E', 0x50931E), ('0x470270', 0x470270),
    ('0x4CB185', 0x4CB185), ('0x4DCE6F', 0x4DCE6F), ('0x4A7774', 0x4A7774),
    ('0x477B99', 0x477B99), ('0x477C19', 0x477C19), ('0x477C97', 0x477C97),
    ('0x477D37', 0x477D37), ('0x4844F0', 0x4844F0),
    ('0x509317', 0x509317), ('0x5094A5', 0x5094A5), ('0x50C23D', 0x50C23D),
    # 其它
    ('0x481C20', 0x481C20), ('0x508BD7', 0x508BD7),
]
for name, va in dispatchers:
    p = parent(va)
    if p is None:
        out.append(f"  {name}: 无父 (在首个函数前)")
    elif p[2] is None:
        out.append(f"  {name}: 洞外, 前一函数 {p[0]:08X}-{p[1]:08X} (n={p[1]-p[0]})")
    else:
        out.append(f"  {name}: 父函数 {p[0]:08X}-{p[1]:08X} (n={p[2]})")

# ---------- (3) 0x508BD7 本体 ----------
out.append("\n" + "="*70)
out.append("(3) 0x508BD7 EH stub 公共目标解码")
out.append("="*70)
d = rd(0x508BD7, 0x60)
for ins in md.disasm(d, 0x508BD7):
    out.append(f"  {ins.address:08X}  {ins.bytes.hex():<14} {ins.mnemonic} {ins.op_str}")

# ---------- (4) 0x5241E0 记录指向区抽样解引用 ----------
out.append("\n" + "="*70)
out.append("(4) 记录 ptr 指向区抽样 (前 8 条)")
out.append("="*70)
for i in range(8):
    r = rd(0x5241E0 + i*16, 16)
    p = struct.unpack('<I', r[0:4])[0]
    ix = struct.unpack('<I', r[4:8])[0]
    d2 = rd(p, 32)
    out.append(f"  rec[{i}] ptr={p:08X} idx={ix:04X} → {d2.hex(' ')}")

txt = '\n'.join(out)
open('D:/MeteorRE/evidence/semA_verify_20261028.txt','w',encoding='utf-8').write(txt)
print("written evidence/semA_verify_20261028.txt")
print(txt[:3000])
