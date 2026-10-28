# -*- coding: utf-8 -*-
# 验证 0x5241E0 = DIOBJECTDATAFORMAT[]: 字段统计 + DIDATAFORMAT 头定位
import json, struct, sys, collections
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

out = []
GUID = {0x5AD200:'GUID_Key', 0x5AD210:'A36D02E4(RyAxis?)', 0x5AD220:'A36D02E3(RxAxis?)',
        0x5AD230:'A36D02F5(?)', 0x5AD240:'A36D02F4(?)', 0x5AD250:'A36D02E2(ZAxis?)',
        0x5AD260:'A36D02E1(YAxis)', 0x5AD270:'A36D02E0(XAxis)'}

# 记录字段统计
cnt = collections.Counter(); ofs_rng=[1<<30,-1]; types=collections.Counter(); flags=collections.Counter()
guid_dist = collections.Counter()
for i in range(311):
    r = rd(0x5241E0 + i*16, 16)
    p, ofs, ty, fl = struct.unpack('<IIII', r)
    if p == 0: cnt['NULL'] += 1
    elif p in GUID: cnt[GUID[p]] += 1
    else: cnt[f'other_{p:08X}'] += 1
    ofs_rng = [min(ofs_rng[0],ofs), max(ofs_rng[1],ofs)]
    types[ty & 0xFF] += 1; flags[fl] += 1
out.append("311 记录字段统计:")
for k,v in cnt.most_common(): out.append(f"  pguid {k}: {v}")
out.append(f"  dwOfs 范围 {ofs_rng[0]:#x}-{ofs_rng[1]:#x}")
out.append(f"  dwType 低字节分布: {dict(types)}")
out.append(f"  dwFlags 分布: {dict(flags)}")
# 轴段 vs 键段分界: 找第一条 GUID_Key 记录
for i in range(311):
    r = rd(0x5241E0 + i*16, 16)
    p, ofs, ty, fl = struct.unpack('<IIII', r)
    if p == 0x5AD200:
        out.append(f"  第一条 GUID_Key 记录 idx={i} ofs={ofs:#x} type={ty:#010x} flags={fl:#010x}")
        break
# 抽 3 条代表性记录
for i in (0, 14, 15, 270, 310):
    r = rd(0x5241E0 + i*16, 16)
    p, ofs, ty, fl = struct.unpack('<IIII', r)
    g = GUID.get(p, 'NULL' if p==0 else f'{p:08X}')
    out.append(f"  rec[{i:3}] pguid={g:<22} dwOfs={ofs:#06x} dwType={ty:#010x} dwFlags={fl:#010x}")

# DIDATAFORMAT 头定位: 全文件扫 4LE==0x5241E0, 排除表自身
target = struct.pack('<I', 0x5241E0)
pos, hits = 0, []
while True:
    i = EXE.find(target, pos)
    if i < 0: break
    # off -> va
    va = None
    for s in PE['secs']:
        if s['pr'] <= i < s['pr'] + s['rs']:
            va = IB + s['va'] + (i - s['pr']); break
    if va is not None and not (0x5241E0 <= va < 0x525550):
        hits.append(va)
    pos = i + 1
out.append(f"\n全文件 4LE==0x5241E0 命中(排除表自身): {[f'{h:08X}' for h in hits]}")
for h in hits:
    d = rd(h-16, 40)
    out.append(f"  头候选 @ {h:08X}: 前16B {d[:16].hex(' ')} | 此处起 {d[16:].hex(' ')}")
    # 若 DIDATAFORMAT: dwSize=24 dwObjSize=16 dwFlags dwDataSize dwNumObjs rgodf
    if h >= 20:
        hdr = struct.unpack('<IIIIII', rd(h-20, 24))
        out.append(f"    若 rgodf 在末字段, 头=(dwSize={hdr[0]}, dwObjSize={hdr[1]}, dwFlags={hdr[2]:#x}, dwDataSize={hdr[3]:#x}, dwNumObjs={hdr[4]}, rgodf={hdr[5]:#x})")

# GUID 窗口外还有无相邻 GUID (0x5AD190-0x5AD300 全景)
out.append("\n0x5AD180-0x5AD300 全景(找 SysKeyboard/SysMouse 6F1D2B60/61):")
d = rd(0x5AD180, 0x180)
for i in range(0, len(d), 16):
    out.append(f"  {0x5AD180+i:08X}  {d[i:i+16].hex(' ')}")
# 全文件搜 SysKeyboard/SysMouse
for name, dv in (('SysKeyboard 6F1D2B60', 0x6F1D2B60), ('SysMouse 6F1D2B61', 0x6F1D2B61)):
    pat = struct.pack('<I', dv) + struct.pack('<H', 0xD5A0) + struct.pack('<H', 0x11CF)
    idxs = []
    pos = 0
    while True:
        i = EXE.find(pat, pos)
        if i < 0: break
        va = None
        for s in PE['secs']:
            if s['pr'] <= i < s['pr'] + s['rs']:
                va = IB + s['va'] + (i - s['pr']); break
        idxs.append(f"{va:08X}" if va else f"off{i:#x}")
        pos = i + 1
    out.append(f"  {name}: {idxs if idxs else '无'}")

txt = '\n'.join(out)
open('D:/MeteorRE/evidence/semA_verify2_20261028.txt','w',encoding='utf-8').write(txt)
print(txt)
