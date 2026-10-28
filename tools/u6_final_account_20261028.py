# -*- coding: utf-8 -*-
# U6 终账: v12 函数边界残差逐洞分类, 目标 = .text 每字节都有归属标签
# 口径: 合并区间(_verify_v12 同源) 截断到 .text [0x401000, 0x5A72BD)
# 引用枚举通道(零命中=在这些通道上零命中, 非绝对无引用):
#   C1 E8/E9 rel32 落点;  C2 EB/70-7F rel8 落点;  C3 全文件 4-LE 立即数/指针 == 洞内地址
# 判定依据全部随行打印; 否定结论附解码终点
import json, struct, collections, bisect, io, csv, hashlib, sys

VER = sys.argv[1] if len(sys.argv) > 1 else 'v14'  # 默认使用最终闭合口径 v14，亦可显式传入 v12/v13/v14
BASE = r"D:/MeteorProjects/_private/ghidra_scripts/"
BIN  = r"C:\Program Files (x86)\Meteor\Meteor.exe"
OUT_TXT = r"D:\MeteorRE\evidence\u6_final_account_%s_20261028.txt" % VER
OUT_CSV = r"D:\MeteorRE\evidence\u6_holes_%s_20261028.csv" % VER
IB = 0x400000
TEXT_LO, TEXT_HI = 0x401000, 0x5A72BD
TEXT_LEN = TEXT_HI - TEXT_LO

data = open(BIN, 'rb').read()
raw = open(BASE + 'fresh_functions_%s.json' % VER, 'rb').read()
sha = hashlib.sha256(raw).hexdigest()
fns = json.loads(raw.decode('utf-8'))
if fns and 'r' in fns[0]:
    ivs = []
    for e in fns:
        for s0, e0 in e['r']:
            ivs.append((int(s0, 16), int(e0, 16) + 1))
    ivs.sort()
else:
    ivs = sorted((int(e['a'], 16), int(e['a'], 16) + int(e['s'])) for e in fns)
m = []
for s, e in ivs:
    if m and s <= m[-1][1]: m[-1][1] = max(m[-1][1], e)
    else: m.append([s, e])
m = [(s, e) for s, e in m if e > TEXT_LO and s < TEXT_HI]

holes = []
cur = TEXT_LO
for s, e in m:
    if s > cur: holes.append((cur, s))
    cur = max(cur, e)
if cur < TEXT_HI: holes.append((cur, TEXT_HI))
hstarts = [h[0] for h in holes]

def hole_of(va):
    i = bisect.bisect_right(hstarts, va) - 1
    if i < 0: return -1
    s, e = holes[i]
    return i if s <= va < e else -1

# ---- 引用扫描(三通道, 全文件) ----
refs = collections.defaultdict(list)   # hole idx -> [site VA,...]
n = len(data)
i = 0
while i < n - 5:
    op = data[i]
    if op in (0xE8, 0xE9):
        t = i + IB + 5 + struct.unpack_from('<i', data, i + 1)[0]
        h = hole_of(t)
        if h >= 0: refs[h].append(i + IB)
        i += 5
    else:
        i += 1
i = 0
while i < n - 2:
    op = data[i]
    if op == 0xEB or 0x70 <= op <= 0x7F:
        t = i + IB + 2 + struct.unpack_from('<b', data, i + 1)[0]
        h = hole_of(t)
        if h >= 0: refs[h].append(i + IB)
    i += 1
step = 1
for i in range(0, n - 4):
    v = struct.unpack_from('<I', data, i)[0]
    if TEXT_LO <= v < TEXT_HI:
        h = hole_of(v)
        if h >= 0 and len(refs[h]) < 8: refs[h].append(i + IB)

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
md = Cs(CS_ARCH_X86, CS_MODE_32)

def decode_best(b, va):
    best = (0, 0, 0)  # (frac, off, depth)
    for off in range(4):
        depth = 0
        for ins in md.disasm(b[off:], va + off):
            depth += ins.size
            if ins.mnemonic == 'invalid': break
        frac = depth / max(1, len(b) - off)
        if frac > best[0]: best = (frac, off, depth)
    return best

rows = []
for idx, (s, e) in enumerate(holes):
    ln = e - s
    b = data[s - IB:e - IB]
    cc = b.count(0xCC); np_ = b.count(0x90); z = b.count(0x00)
    padish = (cc + np_ + z) * 100.0 / ln
    zr = 0; cur2 = 0
    for j in range(0, ln - 3, 4):
        v = struct.unpack_from('<I', b, j)[0]
        if TEXT_LO <= v < TEXT_HI or 0x5A8000 <= v < 0x5C4000:
            cur2 += 1; zr = max(zr, cur2)
        else: cur2 = 0
    frac, off, depth = decode_best(b, s)
    r = refs.get(idx, [])
    nr = len(set(r))
    if zr >= 4: kind = 'POINTER_TABLE'
    elif padish >= 95: kind = 'PADDING'
    elif frac >= 0.95: kind = 'ORPHAN_REACHABLE' if nr > 0 else 'ORPHAN_UNREFERENCED'
    elif z * 100.0 / ln >= 70: kind = 'DATA_ZERO'
    elif frac >= 0.60: kind = 'PARTIAL_CODE'
    else: kind = 'DATA_UNDECODED'
    rows.append({'s': s, 'e': e, 'n': ln, 'cc': cc, 'np': np_, 'z': z,
                 'padish': round(padish, 1), 'run': zr,
                 'frac': round(frac, 3), 'off': off, 'depth': depth,
                 'refs': nr, 'ref0': (hex(r[0]) if r else ''), 'kind': kind})

tally = collections.Counter(r['kind'] for r in rows)
bsum = collections.defaultdict(int)
for r in rows: bsum[r['kind']] += r['n']
total_hole = sum(r['n'] for r in rows)
merged_cov = TEXT_LEN - total_hole

L = []
w = L.append
w('# U6 终账: .text 逐字节归属 (2026-10-28, %s)' % VER)
w('# 输入: %sfresh_functions_%s.json  SHA-256=%s' % (BASE, VER, sha))
w(f'# 二进制: {BIN}  .text=[0x{TEXT_LO:X},0x{TEXT_HI:X}) {TEXT_LEN} B')
w('# 口径: 函数区间合并(与 _verify_v12 同源) → 残差洞逐洞分类; 引用通道 C1=E8/E9 rel32, C2=EB/Jcc rel8, C3=全文件 4-LE 值==洞内地址(每洞记前 8 处)')
w('# 判据: POINTER_TABLE=4LE可指针连排>=4; PADDING=CC/90/00合计>=95%; frac=capstone 最佳起点(0..3)线性解码覆盖率; ORPHAN_REACHABLE=解码>=95%且被引用; ORPHAN_UNREFERENCED=解码>=95%且三通道零引用; DATA_ZERO=零字节>=70%; 其余 PARTIAL_CODE/DATA_UNDECODED 附解码终点')
w('')
w(f'函数 {len(fns)} 个; 合并覆盖 {merged_cov} B = {merged_cov*100.0/TEXT_LEN:.4f}%; 残差 {total_hole} B = {total_hole*100.0/TEXT_LEN:.4f}% ({len(holes)} 洞)')
w('')
w('== 残差构成(逐字节归属终账) ==')
order = ['POINTER_TABLE', 'DATA_ZERO', 'PADDING', 'ORPHAN_REACHABLE', 'ORPHAN_UNREFERENCED', 'PARTIAL_CODE', 'DATA_UNDECODED']
for k in order:
    w(f'  {k:20s} {tally[k]:5d} 洞  {bsum[k]:8d} B  ({bsum[k]*100.0/TEXT_LEN:.4f}% of .text)')
w(f'  {"TOTAL":20s} {len(holes):5d} 洞  {total_hole:8d} B  → 覆盖+残差 = {merged_cov+total_hole} = {TEXT_LEN} (100% 收口)')
w('')
for k in order:
    sub = [r for r in rows if r['kind'] == k]
    sub.sort(key=lambda r: -r['n'])
    w(f'== {k}  top{min(20,len(sub))}/{len(sub)} (按体量) ==')
    for r in sub[:20]:
        w('  %08X-%08X %6d B  CC%%=%3d 90%%=%3d 00%%=%3d pad=%5.1f%% run=%d dec=%3d%%@off%d depth=%d refs=%d %s'
          % (r['s'], r['e'], r['n'], r['cc']*100//r['n'], r['np']*100//r['n'], r['z']*100//r['n'],
             r['padish'], r['run'], r['frac']*100, r['off'], r['depth'], r['refs'], r['ref0']))
    w('')

w('== ORPHAN_REACHABLE 全列(有引用的孤儿代码 = 潜在漏建函数) ==')
for r in sorted([r for r in rows if r['kind'] == 'ORPHAN_REACHABLE'], key=lambda r: -r['n']):
    w('  %08X-%08X %6d B  refs=%d first=%s dec=%3d%%' % (r['s'], r['e'], r['n'], r['refs'], r['ref0'], r['frac']*100))
w('')

with open(OUT_TXT, 'w', encoding='utf-8') as f:
    f.write('\n'.join(L) + '\n')
with open(OUT_CSV, 'w', newline='', encoding='utf-8') as f:
    cw = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
    cw.writeheader()
    for r in rows: cw.writerow(r)
print('written', OUT_TXT, len(L), 'lines;', OUT_CSV, len(rows), 'holes')
print('kinds:', dict(tally))
print('bytes:', {k: bsum[k] for k in order})
print('coverage+residual =', merged_cov + total_hole, '=', TEXT_LEN)
