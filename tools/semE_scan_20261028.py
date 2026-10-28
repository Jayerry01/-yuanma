# -*- coding: utf-8 -*-
# 批次E 扫描器: 对 1,103 个 33-100B UNNAMED 函数出五类证据 + 命名辅助画像聚类
#   (1) 调用方 E8/E9; (2) 被调方; (3) IAT; (4) imm32→节+字符串; (5) f32
#   尾节: 按已命名辅助集 + IAT 集聚簇 (同画像组 → 批量定性判据)
# 判据随行: 加载 semqueue_v14 中全部 5,526 个已命名函数作为已知符号表
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

def sec_of(va):
    for s in secs:
        base = IB + s['va']
        if base <= va < base + s['vs']:
            return s['name']
    return '?'

def cstr_off(o, maxlen=64):
    if o is None or o < 0 or o >= len(EXE):
        return None
    e = EXE.find(b'\0', o, o + maxlen)
    if e < 0:
        return None
    b = EXE[o:e]
    if len(b) < 4:
        return None
    if all(32 <= c < 127 for c in b):
        return b.decode('ascii')
    return None

# ---------- 导入表 ----------
imports = {}
o_dos = struct.unpack('<I', EXE[0x3C:0x40])[0]
opt = o_dos + 24
ddoff = opt + 96
iva, isz = struct.unpack('<II', EXE[ddoff+8:ddoff+16])
o = va2off(IB + iva)
if o is not None:
    while True:
        d = EXE[o:o+20]
        if len(d) < 20 or d == b'\0'*20:
            break
        oft, tds, fc, name_rva, ft = struct.unpack('<IIIII', d)
        dll = cstr_off(va2off(IB + name_rva)) or '?'
        i = 0
        while True:
            tva = va2off(IB + oft + i*4)
            if tva is None:
                break
            t = struct.unpack('<I', EXE[tva:tva+4])[0]
            if t == 0:
                break
            nm = f'{dll}!#{t & 0xFFFF}' if t & 0x80000000 else f'{dll}!' + (cstr_off(va2off(IB + t + 2)) or '?')
            imp_va = IB + ft + i*4
            imports.setdefault(imp_va, nm)
            i += 1
        o += 20

FF = json.load(open('D:/MeteorProjects/_private/ghidra_scripts/fresh_functions_v14.json'))
funcs = sorted([(int(f['a'], 16), int(f['a'], 16) + int(f['s'])) for f in FF])
starts = [a for a, e in funcs]

def parent(va):
    i = bisect.bisect_right(starts, va) - 1
    if i < 0:
        return (0, 0)
    a, e = funcs[i]
    return (a, e)

# ---------- 已命名符号全集 (5,526 个) ----------
NAMED = {}
for row in csv.DictReader(open('D:/MeteorRE/evidence/semqueue_v14_20261028.csv', encoding='utf-8')):
    if row['status'] == 'NAMED':
        NAMED[int(row['addr'], 16)] = row['name']

QUEUE = []
for row in csv.DictReader(open('D:/MeteorRE/evidence/semqueue_v14_20261028.csv', encoding='utf-8')):
    if row['band'] == 'E_33-100B' and row['status'] == 'UNNAMED':
        QUEUE.append(int(row['addr'], 16))
QSET = set(QUEUE)

out = []
out.append("="*78)
out.append("批次E 扫描: %d 个 33-100B UNNAMED 函数, 五类证据 + 画像聚类" % len(QUEUE))
out.append("判据: 调用方=E8字节扫描(C1通道); 被调/IAT/imm32/f32=capstone线性解码")
out.append("NAMED 符号库来源: semqueue_v14 全部 %d 个已命名符号" % len(NAMED))
out.append("="*78)

tsec = [s for s in secs if s['name'] == '.text'][0]
t_base = IB + tsec['va']
t_off0 = tsec['pr']
t_len = tsec['rs']
callers = collections.defaultdict(list)
jmp_callers = collections.defaultdict(list)
data = EXE[t_off0:t_off0 + t_len]
for i in range(len(data) - 5):
    op = data[i]
    if op != 0xE8 and op != 0xE9:
        continue
    rel = struct.unpack('<i', data[i+1:i+5])[0]
    tgt = t_base + i + 5 + rel
    if tgt in QSET:
        site = t_base + i
        (callers if op == 0xE8 else jmp_callers)[tgt].append(site)

md = Cs(CS_ARCH_X86, CS_MODE_32)
IMM_RE = re.compile(r'0x[0-9a-fA-F]{4,}')
IAT_RE = re.compile(r'dword ptr \[0x([0-9a-fA-F]+)\]')

profiles = {}
for fa in sorted(QUEUE):
    i = bisect.bisect_right(starts, fa) - 1
    fe = funcs[i][1] if i >= 0 and funcs[i][0] == fa else fa + 0x8000
    size = fe - fa
    out.append("")
    out.append("FUN %08X  (n=%d)  sec=%s" % (fa, size, sec_of(fa)))
    cl = callers.get(fa, [])
    byp = collections.Counter()
    for s in cl:
        byp[parent(s)[0]] += 1
    out.append("[1] E8调用方 %d 处; E9尾调 %d 处; 父:%s" % (
        len(cl), len(jmp_callers.get(fa, [])),
        ' '.join('%08X x%d' % (p, c) for p, c in byp.most_common(5))))
    body = rd(fa, size)
    callee = collections.Counter()
    iat_use = collections.Counter()
    strs = {}
    f32 = collections.Counter()
    nins = 0
    for ins in md.disasm(body, fa):
        nins += 1
        m = ins.mnemonic
        if m == 'call':
            mm = re.match(r'^0x([0-9a-fA-F]+)$', ins.op_str.strip())
            if mm:
                callee[int(mm.group(1), 16)] += 1
        for mm in IAT_RE.finditer(ins.op_str):
            v = int(mm.group(1), 16)
            if v in imports:
                iat_use[imports[v]] += 1
        for tok in IMM_RE.findall(ins.op_str):
            v = int(tok, 16)
            if 0x400000 <= v < 0x600000 and ins.mnemonic not in ('call', 'jmp'):
                sn = sec_of(v)
                if sn == '.rdata':
                    s = cstr_off(va2off(v))
                    if s:
                        strs.setdefault(v, s)
                try:
                    f = struct.unpack('<f', struct.pack('<I', v))[0]
                    if 1e-4 <= abs(f) < 1e7:
                        f32[v] += 1
                except Exception:
                    pass
    out.append("[2] ins=%d 被调 unique=%d: %s" % (nins, len(callee), ' '.join(
        '%08X%s' % (t, ('=' + NAMED[t]) if t in NAMED else (' x%d' % c if c > 1 else ''))
        for t, c in callee.most_common(12))))
    out.append("[3] IAT: %s" % (dict(iat_use) if iat_use else '-'))
    if strs:
        out.append("[4] 串(%d): %s" % (len(strs), ' | '.join('"%s"' % s[:28] for _, s in sorted(strs.items())[:8])))
    if f32:
        out.append("[5] f32: %s" % ' '.join('%08X=%g' % (v, struct.unpack('<f', struct.pack('<I', v))[0]) for v, _ in f32.most_common(6)))
    named_used = frozenset(t for t in callee if t in NAMED)
    iat_sig = frozenset(iat_use)
    profiles[fa] = (size, named_used, iat_sig, len(strs), len(callee))

# ---------- 画像聚类尾节 ----------
out.append("")
out.append("="*78)
out.append("画像聚类: 按 已命名辅助使用集 + IAT 集 分组 (同组→同族批量定性候选)")
out.append("="*78)
groups = collections.defaultdict(list)
for fa, (size, nu, isig, ns, nc) in profiles.items():
    groups[(nu, isig)].append(fa)
big = [(k, v) for k, v in groups.items() if len(v) >= 3 and (k[0] or k[1])]
big.sort(key=lambda kv: -len(kv[1]))
for (nu, isig), members in big:
    out.append("组 n=%d  named={%s}  iat={%s}" % (
        len(members), ','.join(sorted(NAMED[t] for t in nu)) or '-',
        ','.join(sorted(isig)) or '-'))
    for fa in members:
        out.append("    %08X (n=%d)" % (fa, profiles[fa][0]))

txt = '\n'.join(out)
open('D:/MeteorRE/evidence/semE_dump_20261028.txt', 'w', encoding='utf-8').write(txt)
print("written evidence/semE_dump_20261028.txt lines=%d groups>=3: %d" % (len(out), len(big)))
