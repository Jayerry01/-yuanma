# -*- coding: utf-8 -*-
# 91 个 ORPHAN_UNREFERENCED 逐洞字节模式分类 (每洞打印判定依据)
import csv, json, struct, sys
sys.stdout.reconfigure(encoding='utf-8')
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
rows = list(csv.DictReader(open('evidence/u6_holes_v14_20261028.csv', encoding='utf-8')))
holes = sorted([(int(r['s']), int(r['e'])) for r in rows if r['kind']=='ORPHAN_UNREFERENCED'])
NOPREP = [b'\x8d\xb4\x26\x00\x00\x00\x00', b'\x8d\xbc\x27\x00\x00\x00\x00',
          b'\x8d\xa4\x24\x00\x00\x00\x00', b'\x8d\x64\x24\x00', b'\x8b\xff', b'\x8b\xf6',
          b'\x8d\x49\x00', b'\x8d\x09']
out=[]
from collections import Counter
fam = Counter()
for s,e in holes:
    d = rd(s, e-s)
    # 判定链 (按序): ASCII 串 / 死包装 call rel32;ret / 死 thunk mov edx,imm;jmp / lea+call 片段 / 死尾 xor;add esp;ret / 纯 NOP 垫 / 混合
    asc = ''.join(chr(b) if 0x20<=b<0x7f else '.' for b in d)
    cls, why = None, ''
    if d.startswith(b'\x90') or d in NOPREP or all(b in (0x90,) for b in d):
        cls='对齐垫(90)'; why=f"全 90, n={e-s}"
    else:
        matched=None
        for p in NOPREP:
            if len(d)==len(p) and d==p:
                matched=f"对齐垫({p.hex(' ')})"; break
        if matched: cls=matched; why=f"字节=={d.hex(' ')}"
        elif d.startswith(b'\x8d') and d.endswith(b'\x90\x90\x90\x90'):
            cls='对齐垫(lea前缀+90)'; why=d.hex(' ')
        elif set(d) <= {0x90, 0x8b, 0xff, 0xf6, 0x8d, 0xb4, 0xbc, 0x27, 0xa4, 0x24, 0x64, 0x49, 0x09, 0x2e}:
            cls='对齐垫(多字节NOP库)'; why=d.hex(' ')
        elif len(d)>=7 and d[0]==0xe8 and d[-1]==0xc3:
            # call rel32 ... ret?
            rel = struct.unpack('<i', d[1:5])[0]; tgt = s+5+rel
            cls='死CRT包装(call+ret)'; why=f"call {tgt:08X}; ret"
        elif d.startswith(b'\xba') and b'\xe9' in d[5:8]:
            rel = struct.unpack('<i', d[6:10] if len(d)>=10 else b'\0\0\0\0')[0]
            cls='死thunk(mov edx,imm;jmp)'; why=f"mov edx,{struct.unpack('<I',d[1:5])[0]:08X}; jmp {s+10+rel:08X}"
        elif d.startswith(b'\x8d') and b'\xe8' in d:
            i = d.find(b'\xe8')
            rel = struct.unpack('<i', d[i+1:i+5])[0]; tgt = s+i+5+rel
            cls='片段(lea+call)'; why=f"lea @+0 ; call {tgt:08X}"
        elif d.startswith(b'\x33\xc0') or (b'\x83\xc4' in d and d.endswith(b'\xc2\x04\x00')):
            cls='死函数尾'; why=d.hex(' ')
        elif all(0x20<=b<0x7f for b in d):
            cls='字符串'; why=f'"{d.decode()}"'
        else:
            cls='其它'; why=d.hex(' ')
    fam[cls]+=1
    out.append(f"{s:08X}-{e:08X} n={e-s:<4} {cls:<22} 判据: {why}")
print('\n'.join(out))
print('\n家族统计:', dict(fam), '总', len(holes))
open('evidence/semA_verify3_20261028.txt','w',encoding='utf-8').write('\n'.join(out)+f"\n\n家族统计: {dict(fam)} 总 {len(holes)}\n")
