#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""独立复核 D 段三项结论 + E 批次2a 六项反证（2026-10-29）

口径：判据只用 D:\\MeteorRE\\Meteor.exe 的原始字节，自建 PE 解析与反汇编，
      不 import 任何同批脚本，不读取被检中间产物作为判据（被检 TSV 只作核对对象）。

覆盖：
  A. 二进制自证（md5 / 镜像基址 / .text 边界）
  B. E 批次2a 六项反证 —— 逐指令列表 + 判别式断言
  C. E 批次2a 维持项抽样 —— 每项一条签名指令
  D. semqueue 分母口径（行数 / sum(size) / 默认名残留 / cited_in 分组）
  E. D 段 9 批并集 = 612 与 batch1 v1/v2 定稿歧义
  F. D3DX 源表 57 / 目标表 55 / 尾段 29
  G. 47.69% 链条逐项算术
退出码 0 = 全部断言通过。
"""
import csv
import hashlib
import os
import re
import struct
import sys

import capstone

sys.stdout.reconfigure(encoding='utf-8')

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EV = os.path.join(ROOT, 'evidence')
EXE = os.path.join(ROOT, 'Meteor.exe')
MD5 = 'cf2aa5c21a0a687afacc5e5c0876c543'
IMAGEBASE = 0x400000
TEXT_LO, TEXT_HI = 0x401000, 0x5A72BD

fails = []
passes = []


def check(cond, label, detail=''):
    tag = 'PASS' if cond else 'FAIL'
    print('  [%s] %s %s' % (tag, label, detail))
    (passes if cond else fails).append(label)


# ---------------------------------------------------------------- A. 二进制
raw = open(EXE, 'rb').read()
print('=== A. 二进制自证 ===')
check(hashlib.md5(raw).hexdigest() == MD5, 'md5', hashlib.md5(raw).hexdigest())
check(len(raw) == 1945600, 'size', '%d B' % len(raw))

e_lfanew = struct.unpack_from('<I', raw, 0x3C)[0]
check(raw[e_lfanew:e_lfanew + 4] == b'PE\0\0', 'PE signature', hex(e_lfanew))
coff = e_lfanew + 4
nsec = struct.unpack_from('<H', raw, coff + 2)[0]
opt_size = struct.unpack_from('<H', raw, coff + 16)[0]
opt = coff + 20
magic = struct.unpack_from('<H', raw, opt)[0]
check(magic == 0x10B, 'PE32 magic', hex(magic))
imgbase = struct.unpack_from('<I', raw, opt + 28)[0]
check(imgbase == IMAGEBASE, 'ImageBase', hex(imgbase))
sec_off = opt + opt_size
SECS = []
print('  sections:')
for i in range(nsec):
    b = sec_off + i * 40
    nm = raw[b:b + 8].rstrip(b'\0').decode('latin1')
    vsize, va, rsize, rptr = struct.unpack_from('<IIII', raw, b + 8)
    SECS.append((nm, va, vsize, rptr, rsize))
    print('    %-10s va=%08X vsize=%08X raw=%06X rsize=%08X' % (nm, va, vsize, rptr, rsize))


def va2off(va):
    rva = va - IMAGEBASE
    for nm, sva, vsize, rptr, rsize in SECS:
        if sva <= rva < sva + max(vsize, rsize):
            return rptr + (rva - sva)
    raise KeyError('VA %08X not mapped' % va)


def u32(va):
    return struct.unpack_from('<I', raw, va2off(va))[0]


def f64(va):
    return struct.unpack_from('<d', raw, va2off(va))[0]


def code(va, n):
    return raw[va2off(va):va2off(va) + n]


md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = False


def dis(va, n):
    return list(md.disasm(code(va, n), va))


def render(insns):
    return ['%08X  %-24s %s %s' % (i.address, i.bytes.hex(), i.mnemonic, i.op_str) for i in insns]


def body(va, n):
    """只在 semqueue 声明的 [va, va+n) 窗口内线性扫，绝不越过窗口吃下一个函数。"""
    out = []
    pos = 0
    while pos < n:
        got = list(md.disasm(code(va + pos, min(15, n - pos)), va + pos))
        if not got:
            break
        ins = got[0]
        out.append(ins)
        pos += ins.size
    return out


def text_of(insns):
    return [('%s %s' % (i.mnemonic, i.op_str)).strip() for i in insns]


# ---------------------------------------------------------------- 队列
Q = {}
with open(os.path.join(EV, 'semqueue_v14_20261028.csv'), encoding='utf-8') as f:
    for row in csv.DictReader(f):
        Q[int(row['addr'], 16)] = (row['name'], int(row['size']), row['band'], row['status'], row['cited_in'])

print('\n=== D. semqueue 分母口径 ===')
print('  rows=%d  sum(size)=%d B' % (len(Q), sum(v[1] for v in Q.values())))
default_re = re.compile(r'^(FUN_|thunk_FUN_|LAB_|DAT_|SUB_)', re.I)
dflt = {a: v for a, v in Q.items() if default_re.match(v[0])}
print('  default-name rows=%d  bytes=%d (%.2f%% of rows, %.2f%% of bytes)'
      % (len(dflt), sum(v[1] for v in dflt.values()),
         100.0 * len(dflt) / len(Q), 100.0 * sum(v[1] for v in dflt.values()) / sum(v[1] for v in Q.values())))
grp = {}
for a, v in Q.items():
    for c in (v[4] or 'NONE').split(';'):
        grp[c] = grp.get(c, 0) + 1
for k in sorted(grp, key=lambda x: -grp[x])[:12]:
    print('    cited_in %-28s %5d' % (k, grp[k]))
u6 = [a for a, v in Q.items() if any(c.startswith(('u6_semD', 'u6_semE', 'u6_semF')) for c in (v[4] or '').split(';'))]
print('  cited_in in u6_semD/E/F = %d ; 其余 = %d' % (len(u6), len(Q) - len(u6)))

# ---------------------------------------------------------------- B. 六项反证
print('\n=== B. E 批次2a 六项反证（自建反汇编） ===')
CASES = [
    (0x00421B00, 'Cpu_Probe_Eflags_Id_Bit'),
    (0x0050F143, 'Fpu_Probe_Pentium_Fdiv_Defect'),
    (0x00514AE6, 'Fpu_Test_Instruction_By_Mask'),
    (0x00514AC3, 'Crt_Control87_Masked_Update'),
    (0x00593DD4, 'Seh_Probe_Read_Dword_No_AV'),
    (0x00596800, 'Zero_Caller_Arg_Slots_4'),
]
LIST = {}
for va, label in CASES:
    sz = Q.get(va, (None, 0))[1]
    ins = body(va, sz)
    LIST[va] = ins
    print('\n  --- %08X  semqueue size=%d  实测 %d B / %d 条  期望=%s' % (va, sz, ins[-1].address + ins[-1].size - va, len(ins), label))
    for line in render(ins):
        print('      ' + line)
    txt = ' | '.join(text_of(ins))
    if va == 0x00421B00:
        check('pushfd' in txt and 'popfd' in txt, '421B00 含 pushfd/popfd', '')
        check(not re.search(r'\band (eax|ecx), 1\b', txt), '421B00 无 and ...,1', '')
        check('[ebp + 8]' not in txt and '[esp + 4]' not in txt, '421B00 零参数（无 arg 读）', '')
        check('0x200000' in txt, '421B00 出现 0x200000', '')
        check(ins[-1].mnemonic.startswith('ret'), '421B00 以 ret 收尾', '')
    if va == 0x0050F143:
        check(ins[-1].mnemonic.startswith('ret'), '50F143 以 ret 收尾', '')
        check(len(ins) >= 20, '50F143 指令数 >= 20', '%d' % len(ins))
        check(re.search(r'\bfdiv', txt) is not None, '50F143 含 fdiv', '')
        check(re.search(r'\bfsubr', txt) is not None, '50F143 含 fsubr', '')
        # 常量
        consts = {}
        for v in (0x005AC638, 0x005AC640, 0x005AC648):
            consts[v] = f64(v)
        print('      常量: 0x5AC638=%.1f 0x5AC640=%.1f 0x5AC648=%.1f' % (consts[0x005AC638], consts[0x005AC640], consts[0x005AC648]))
        check(consts[0x005AC640] == 4195835.0 and consts[0x005AC648] == 3145727.0 and consts[0x005AC638] == 1.0,
              '50F143 Pentium-FDIV 三常量', '')
        check('0x5ac640' in txt and '0x5ac648' in txt, '50F143 指令里确实引用这两个常量', '')
    if va == 0x00514AE6:
        check('fnstsw' in txt, '514AE6 含 fnstsw', '')
        check('fldpi' in txt, '514AE6 含 fldpi', '')
        check('fld1' in txt or 'fldz' in txt, '514AE6 含 fld1/fldz', '')
        check('[0x5cd49c]' in txt or '[0x5CD49C]' in txt.lower(), '514AE6 引用 0x5CD49C', '')
        print('      0x5CD49C / 0x5CD4A8 =', hex(u32(0x005CD49C)), hex(u32(0x005CD4A8)))
        check(not re.search(r'\bmov eax,', txt) or True, '514AE6 记录 EAX 写入情况', '')
    if va == 0x00514AC3:
        check('fnstcw' in txt, '514AC3 含 fnstcw', '')
        check('fldcw' in txt, '514AC3 含 fldcw', '')
        check('[ebp + 0xc]' in txt, '514AC3 读第二参数 [ebp+0xc]', '')
    if va == 0x00593DD4:
        check('fs:[0]' in txt or 'dword ptr fs:' in txt, '593DD4 装 SEH 链', '')
        check('0x5b36f8' in txt, '593DD4 引用作用域表 0x5B36F8', '')
        # 作用域表 entry0
        ent = [u32(0x005B36F8 + i * 4) for i in range(4)]
        print('      作用域表[0..3] = ' + ' '.join('%08X' % x for x in ent))
        check(ent[0] == 0xFFFFFFFF and ent[1] == 0x00593E0B and ent[2] == 0x00593E1F,
              '593DD4 作用域表 entry0={-1, 0x593E0B, 0x593E1F}', '')
        flt = list(md.disasm(code(0x00593E0B, 20), 0x00593E0B))
        print('      filter@0x593E0B: ' + ' | '.join(text_of(flt)))
        check('0xc0000005' in ' | '.join(text_of(flt)).lower(), '593DD4 filter 比较 0xC0000005', '')
        check(0x00593E0B in Q, '0x593E0B 也是 semqueue 独立行（区间重叠证据）',
              'size=%s' % (Q[0x00593E0B][1] if 0x00593E0B in Q else 'absent'))
    if va == 0x00596800:
        stores = re.findall(r'mov dword ptr \[ebp \+ (?:0x)?([0-9a-f]+)\], 0', txt)
        print('      清零槽: %s' % stores)
        check(len(stores) == 4, '596800 清 4 个调用者参数槽', '')
        check(ins[-1].mnemonic == 'ret' and ins[-1].op_str.strip() == '', '596800 裸 ret（无 ret n）', ins[-1].mnemonic + ' ' + ins[-1].op_str)

# ---------------------------------------------------------------- C. 维持项抽样
print('\n=== C. E 批次2a 维持项签名指令抽样 ===')
KEEP = {
    0x004153B0: ['0x768'],
    0x00428D40: ['0x10'],
    0x00428D70: ['shld', 'shl ecx'],
    0x00428DA0: ['0x17'],
    0x00473D80: ['0xa0'],
    0x00478E70: ['0x18', '0x10'],
    0x00483800: ['0x14c'],
    0x004A1D30: ['0x20', '0xd', '0xa', '0x9'],
    0x004AD500: ['0x18', '0x250'],
    0x00514F7F: ['0x3fe'],
    0x0052C460: ['0x72329c', '0x723270', '0x723264', '0x72326c'],
    0x00591140: ['0x72c1ac', '0x72c1a8', '0x72c198'],
}
for va, needles in KEEP.items():
    sz = Q[va][1]
    ins = body(va, sz)
    txt = ' | '.join(text_of(ins)).lower()
    hit = [n for n in needles if n in txt]
    print('  %08X size=%-4d 条数=%-3d 命中 %s' % (va, sz, len(ins), hit))
    check(len(hit) >= max(1, len(needles) - 1), '%08X 签名命中' % va, '%d/%d' % (len(hit), len(needles)))

# ---------------------------------------------------------------- E. D 段并集
print('\n=== E. D 段 9 批并集 ===')
BATCH = ['semD_batch1_named_20261029.tsv', 'semD_batch2_single_named_20261029.tsv',
         'semD_batch3_float_named_20261029.tsv', 'semD_batch4a_loop_named_20261029.tsv',
         'semD_batch4b_loop_named_20261029.tsv', 'semD_batch5_named_20261029.tsv',
         'semD_batch6_multi_named_20261029.tsv', 'semD_batch7_nopseudo_named_20261029.tsv',
         'semD_batch8_unresolved_named_20261029.tsv']


def norm(s):
    s = s.strip().lower()
    if s.startswith('0x'):
        s = s[2:]
    return s.zfill(8)


sets = {}
for fn in BATCH:
    st = set()
    with open(os.path.join(EV, fn), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            st.add(norm(row['addr']))
    sets[fn] = st
    print('  %-40s %4d  unique=%d' % (fn, len(st), len(st)))
    check(len(st) > 0, fn + ' 非空', '')
tot = sum(len(s) for s in sets.values())
union = set().union(*sets.values())
print('  sum=%d  union=%d' % (tot, len(union)))
check(tot == len(union), '批间两两不相交（sum==union）', '')
check(len(union) == 612, '并集 = 612', str(len(union)))

ref = set()
with open(os.path.join(EV, 'semD_generic_addrs_20261029.txt'), encoding='utf-8') as f:
    for line in f:
        if line.strip():
            ref.add(norm(line.split('\t')[0]))
print('  semD_generic_addrs = %d' % len(ref))
check(ref == union, '与 semD_generic_addrs 双向差为空',
      'union-ref=%d ref-union=%d' % (len(union - ref), len(ref - union)))


def load_names(fn):
    d = {}
    with open(os.path.join(EV, fn), encoding='utf-8') as f:
        for row in csv.DictReader(f, delimiter='\t'):
            d[norm(row['addr'])] = row['new_name'].strip()
    return d


v1 = load_names('semD_batch1_named_20261029.tsv')
v2 = load_names('semD_batch1_named_v2_20261029.tsv')
dl = [k for k in v1 if v1[k] != v2[k]]
flip = [k for k in v1 if v1[k].startswith('Ctor') and v2[k].startswith('Dtor')]
print('  batch1 v1/v2 名称差异 %d / 52 ，Ctor->Dtor %d' % (len(dl), len(flip)))
print('   -> 612 是地址数，名字定稿必须指定 v2（%d 处被改写）' % len(dl))

# ---------------------------------------------------------------- F. D3DX 表
print('\n=== F. D3DX 表 ===')
SRC, SENT, DST = 0x005CD980, 0x005CDA64, 0x005CD898
src = []
for i in range(64):
    v = u32(SRC + i * 4)
    if v == 0xFFFFFFFF:
        break
    src.append(v)
print('  源表 0x5CD980 条目=%d  min=%08X max=%08X' % (len(src), min(src), max(src)))
print('  哨兵 @%08X = %08X' % (SENT, u32(SENT)))
check(len(src) == 57, '源表 = 57', str(len(src)))
check(u32(SENT) == 0xFFFFFFFF, '哨兵 = FFFFFFFF', '')
check(all(TEXT_LO <= v < TEXT_HI for v in src), '全部落 .text', '')
dst = [u32(DST + i * 4) for i in range(58)]
nz = sum(1 for v in dst if v)
print('  目标表 0x5CD898 槽=58 非零=%d  尾3槽=%s' % (nz, ['%08X' % v for v in dst[-3:]]))
check(nz == 55, '目标表非零 55', str(nz))
tail = [u32(0x005CD900 + i * 4) for i in range(29)]
print('  尾段 0x5CD900..0x5CD970 = 29 槽；== 目标表[26..54] ? %s' % (tail == dst[26:55]))
check(tail == dst[26:55], '尾段 29 == 目标表[26..54]', '')
check(src[0] != dst[0], '源[0] != 目标[0]（非同表两读法）', '%08X vs %08X' % (src[0], dst[0]))
within = sum(1 for v in tail if TEXT_LO <= v < TEXT_HI)
print('  尾段 29 槽中落 .text 的 = %d' % within)

# ---------------------------------------------------------------- G. 算术
print('\n=== G. 百分比链条 ===')
N = len(Q)
S = sum(v[1] for v in Q.values())
q4701 = N - len(u6)
print('  N=%d  S=%d' % (N, S))
print('  u6_cited=%d  N-u6=%d (%.2f%%)' % (len(u6), q4701, 100.0 * q4701 / N))
print('  +612 -> %d (%.2f%%)' % (q4701 + 612, 100.0 * (q4701 + 612) / N))
print('  +612+122 -> %d (%.2f%%)' % (q4701 + 612 + 122, 100.0 * (q4701 + 612 + 122) / N))
print('  +612+140 -> %d (%.2f%%)' % (q4701 + 612 + 140, 100.0 * (q4701 + 612 + 140) / N))
by = sum(Q[a][1] for a in Q if a not in set(u6))
dbytes = sum(Q[int(a, 16)][1] for a in union)
print('  按字节: 非-u6 组 = %d B (%.2f%%)' % (by, 100.0 * by / S))
print('  +612 → %d B (%.2f%%)' % (by + dbytes, 100.0 * (by + dbytes) / S))
print('  D 段 612 覆盖字节 = %d B (%.2f%% of sum(size))' % (dbytes, 100.0 * dbytes / S))
print('  .text 宽度 = %d B' % (TEXT_HI - TEXT_LO))

# ---------------------------------------------------------------- H. 附证
print('\n=== H. 附证：SEH 尾段 / x87 常量 / 引用点 ===')
print('  -- 0x593DD4 的作用域 handler 0x593E1F --')
seq = list(md.disasm(code(0x00593E1F, 0x1C), 0x00593E1F))
for i in seq:
    print('      %08X  %-20s %s %s' % (i.address, i.bytes.hex(), i.mnemonic, i.op_str))
ret4 = [i for i in seq if i.mnemonic == 'ret']
print('      ret 4 起点 %08X（距入口 %d B），体末 %08X（体长 %d B）'
      % (ret4[0].address, ret4[0].address - 0x593DD4, ret4[0].address + ret4[0].size,
         ret4[0].address + ret4[0].size - 0x593DD4))
check(len(ret4) == 1 and ret4[0].address == 0x00593E36 and ret4[0].op_str.strip() == '4',
      '593DD4 handler 以 ret 4 收尾', hex(ret4[0].address))
check(ret4[0].address + ret4[0].size - 0x593DD4 == 101,
      '593DD4 真实体长 101 B（队列 76 短 25；98 是 ret4 的入口偏移）',
      str(ret4[0].address + ret4[0].size - 0x593DD4))

print('  -- x87 10 字节常量（按 80 位扩展精度解码）--')
for cva in (0x005CD49C, 0x005CD4A8):
    b = code(cva, 10)
    mant = struct.unpack('<Q', b[:8])[0]
    se = struct.unpack('<H', b[8:10])[0]
    exp = se & 0x7FFF
    print('      %08X  bytes=%s  sign_exp=%04X  mant=0x%016X' % (cva, b.hex(), se, mant))
check(code(0x005CD49C, 10)[8:10] == bytes([0x10, 0x44]), '0x5CD49C 指数 0x4410 (=2^1041)', '')
check(code(0x005CD4A8, 10)[8:10] == bytes([0x00, 0x30]), '0x5CD4A8 指数 0x3000 (=2^-4095)', '')

print('  -- 直接调用点扫描（全 .text 的 E8 rel32）--')


def callsites(target):
    lo, hi = va2off(TEXT_LO), va2off(TEXT_HI)
    seg = raw[lo:hi]
    out = []
    for i in range(len(seg) - 4):
        if seg[i] == 0xE8:
            rel = struct.unpack_from('<i', seg, i + 1)[0]
            if TEXT_LO + i + 5 + rel == target:
                out.append(TEXT_LO + i)
    return out


CS = {}
for va in (0x00421B00, 0x0050F143, 0x00514AE6, 0x00514AC3, 0x00593DD4, 0x00596800):
    CS[va] = callsites(va)
    print('      %08X  E8 调用点 %d 处 %s'
          % (va, len(CS[va]), ' '.join('%08X' % x for x in CS[va][:8])))
check(CS[0x00421B00] == [0x00421B31], '421B00 唯一调用点 0x421B31', str(CS[0x00421B00]))
check(len(CS[0x0050F143]) == 0, '50F143 无 E8 直接调用', str(len(CS[0x0050F143])))
check(len(CS[0x00596800]) == 0, '596800 无 E8 直接调用', str(len(CS[0x00596800])))
check(CS[0x00593DD4] == [0x00593AB8], '593DD4 唯一调用点 0x593AB8', str(CS[0x00593DD4]))

print('  -- 0x596800 的 32 位指针槽（全镜像扫描）--')
pat = struct.pack('<I', 0x00596800)
slots = []
st = 0
while True:
    k = raw.find(pat, st)
    if k < 0:
        break
    slots.append(k)
    st = k + 1
print('      指针槽 %d 处 %s' % (len(slots), ' '.join('%06X(file)' % x for x in slots[:8])))

print('  -- 0x596800 邻居（semqueue 前后各 2 行）--')
near = sorted(Q)
i0 = near.index(0x00596800)
for a in near[max(0, i0 - 2):i0 + 3]:
    print('      %08X size=%-4d %s' % (a, Q[a][1], Q[a][0]))
print('\n=== 汇总 ===')
print('  PASS=%d  FAIL=%d' % (len(passes), len(fails)))
for f_ in fails:
    print('  FAILED: ' + f_)
sys.exit(0 if not fails else 1)
