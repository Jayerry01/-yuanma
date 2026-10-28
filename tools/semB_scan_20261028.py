# -*- coding: utf-8 -*-
# 批次B 扫描器: 对 36 个 >1KB UNNAMED 函数出五类证据
#   (1) 调用方: .text 全量 E8 字节扫描, 计算目标 = 本函数起始, 按父函数聚合
#   (2) 被调方: capstone 从函数起点线性解码, call 目标去重计数
#   (3) IAT: 解码指令中 [imm32] 命中导入表 → dll!name
#   (4) imm32→节分类: 立即数落节归属; .rdata 附 48B 可打印 ASCII 前缀
#   (5) f32: imm32 重解释 float32, 1e-4<=|f|<1e7
# 判据随行: 每节输出标注口径; E8 扫描含非指令字节假阳性(批次A已定性为 C1 可靠通道)
import json, struct, bisect, collections, csv, sys, re
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
    try:
        s = b.decode('ascii')
    except UnicodeDecodeError:
        return None
    if all(32 <= c < 127 for c in b):
        return s
    return None

# ---------- 导入表 ----------
imports = {}
o_dos = struct.unpack('<I', EXE[0x3C:0x40])[0]
coff = o_dos + 4
opt = coff + 20
ddoff = opt + 96  # PE32 数据目录起点
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
            if t & 0x80000000:
                nm = f'{dll}!#{t & 0xFFFF}'
            else:
                nm = f'{dll}!' + (cstr_off(va2off(IB + t + 2)) or '?')
            imp_va = IB + ft + i*4
            if imp_va not in imports:
                imports[imp_va] = nm
            i += 1
        o += 20

# ---------- 函数表 ----------
FF = json.load(open('D:/MeteorProjects/_private/ghidra_scripts/fresh_functions_v14.json'))
funcs = sorted([(int(f['a'], 16), int(f['a'], 16) + int(f['s'])) for f in FF])
starts = [a for a, e in funcs]

def parent(va):
    i = bisect.bisect_right(starts, va) - 1
    if i < 0:
        return None
    a, e = funcs[i]
    if a <= va < e:
        return (a, e)
    return (a, e)

# ---------- 队列 ----------
QUEUE = []
for row in csv.DictReader(open('D:/MeteorRE/evidence/semqueue_v14_20261028.csv', encoding='utf-8')):
    if row['band'] == 'B_>1000B' and row['status'] == 'UNNAMED':
        QUEUE.append(int(row['addr'], 16))
QSET = set(QUEUE)
out = []
out.append("="*78)
out.append("批次B 扫描: %d 个 >1KB UNNAMED 函数, 五类证据" % len(QUEUE))
out.append("判据: 调用方=E8字节扫描(.text全量,C1通道); 被调方/IAT/imm32/f32=capstone线性解码")
out.append("="*78)

# ---------- 全 .text E8 扫描 → 调用方 ----------
tsec = [s for s in secs if s['name'] == '.text'][0]
t_base = IB + tsec['va']
t_lo, t_hi = t_base, t_base + tsec['vs']
t_off0 = tsec['pr']
t_len = tsec['rs']
callers = collections.defaultdict(list)   # target -> [site,...]
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

for fa in sorted(QUEUE):
    fe = None
    i = bisect.bisect_right(starts, fa) - 1
    fe = funcs[i][1] if i >= 0 and funcs[i][0] == fa else fa + 0x8000
    size = fe - fa
    out.append("")
    out.append("="*78)
    out.append("FUN %08X  (n=%d)  sec=%s" % (fa, size, sec_of(fa)))
    out.append("="*78)

    # (1) 调用方
    cl = callers.get(fa, [])
    out.append("[1] 调用方 E8: %d 处; 尾调 E9: %d 处" % (len(cl), len(jmp_callers.get(fa, []))))
    byp = collections.Counter()
    for s in cl:
        p = parent(s)
        byp[p[0]] += 1
    for pa, c in byp.most_common(8):
        pi = bisect.bisect_right(starts, pa) - 1
        pe = funcs[pi][1] if pi >= 0 else pa
        out.append("    <- %08X (父 %08X-…, n=%d) x%d" % (pa, pa, pe - pa, c))
    for s in jmp_callers.get(fa, [])[:4]:
        p = parent(s)
        out.append("    E9<- %08X (父 %08X)" % (s, p[0]))

    # (2)(3)(4)(5) 函数体解码
    body = rd(fa, size)
    callee = collections.Counter()
    iat_use = collections.Counter()
    immsec = collections.Counter()
    rdata_tgts = collections.Counter()
    datasec_tgts = collections.Counter()
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
        if m in ('call', 'jmp') or True:
            for mm in IAT_RE.finditer(ins.op_str):
                v = int(mm.group(1), 16)
                if v in imports:
                    iat_use[imports[v]] += 1
        # 立即数
        for tok in IMM_RE.findall(ins.op_str):
            v = int(tok, 16)
            if 0x400000 <= v < 0x600000 and ins.mnemonic not in ('call', 'jmp'):
                sn = sec_of(v)
                immsec[sn] += 1
                if sn == '.rdata':
                    rdata_tgts[v] += 1
                    s = cstr_off(va2off(v))
                    if s:
                        strs.setdefault(v, s)
                elif sn in ('.data', '.bss', '.data.'):
                    datasec_tgts[v] += 1
                # f32
                try:
                    f = struct.unpack('<f', struct.pack('<I', v))[0]
                    if 1e-4 <= abs(f) < 1e7:
                        f32[v] += 1
                except Exception:
                    pass
    out.append("[2] 指令数 %d; 被调方 unique %d, top:" % (nins, len(callee)))
    for t, c in callee.most_common(10):
        p = parent(t)
        insn = bisect.bisect_right(starts, t) - 1 >= 0 and funcs[bisect.bisect_right(starts, t)-1][0] == t
        out.append("    -> %08X x%s%s" % (t, c, "" if insn else "  [非函数起点]"))
    out.append("[3] IAT 使用: %s" % (dict(iat_use) if iat_use else "无"))
    out.append("[4] imm32→节: %s" % dict(immsec))
    if strs:
        out.append("    .rdata 字符串引用 (%d unique, 至多12):" % len(strs))
        for v, s in list(strs.items())[:12]:
            out.append("      %08X -> \"%s\"" % (v, s[:60]))
    if rdata_tgts:
        nonstr = [v for v in rdata_tgts if v not in strs]
        if nonstr:
            out.append("    .rdata 非字符串目标 (%d unique, 至多8): %s" % (
                len(nonstr), ' '.join('%08X(x%d)' % (v, rdata_tgts[v]) for v in nonstr[:8])))
    if datasec_tgts:
        out.append("    .data/.bss 全局目标 (%d unique, 至多10): %s" % (
            len(datasec_tgts), ' '.join('%08X(x%d)' % (v, datasec_tgts[v]) for v in sorted(datasec_tgts, key=datasec_tgts.get, reverse=True)[:10])))
    if f32:
        out.append("[5] f32 候选 (%d unique, 至多10): %s" % (
            len(f32), ' '.join('%08X=%g(x%d)' % (v, struct.unpack('<f', struct.pack('<I', v))[0], c) for v, c in f32.most_common(10))))

txt = '\n'.join(out)
open('D:/MeteorRE/evidence/semB_dump_20261028.txt', 'w', encoding='utf-8').write(txt)
print("written evidence/semB_dump_20261028.txt  lines=%d" % len(out))
