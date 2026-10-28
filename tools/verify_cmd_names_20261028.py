# -*- coding: utf-8 -*-
"""2026-10-28 控制台指令名表复核。

判据口径（全部打印）：
  - 名表 = 反汇编 0x4B63B0..0x4B6940 的 repe cmpsb 链；每条 = (mov edi,串地址 /
    mov ecx,比较长度 / jne 后的 mov eax,id)，长度必须等于 len(串)+1（含 NUL 精确匹配）；
  - 执行器 = 0x4B6940 的 `dec eax; cmp eax,0x3f; ja default; jmp [eax*4+0x4B7878]`，
    跳表 64 项，指向 default(0x4B785B) 的槽 = 无处理器；
  - 名字的"存在"只认两种证据：映射器条目（最强）或全文件 NUL 结尾精确串（打印 VA）；
    子串命中不作为命中（例如 ip 会命中大量无关串）。
"""
import re, struct, sys, hashlib, io
import capstone

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

EXE = r'C:\Program Files (x86)\Meteor\Meteor.exe'
b = open(EXE, 'rb').read()
print(f'== target == {EXE}')
print(f'  bytes={len(b)} sha256={hashlib.sha256(b).hexdigest()[:16]}')
e_lfanew = struct.unpack_from('<I', b, 0x3c)[0]
nsect = struct.unpack_from('<H', b, e_lfanew + 6)[0]
opt = e_lfanew + 24
sect_off = opt + struct.unpack_from('<H', b, e_lfanew + 20)[0]
sects = []
for i in range(nsect):
    nm = b[sect_off:sect_off + 8].rstrip(b'\0').decode()
    vs, va, rs, ro = struct.unpack_from('<IIII', b, sect_off + 8)
    sects.append((nm, va, vs, ro, rs))
    sect_off += 40
print('  sections (name, RVA, rawptr, rawsize):',
      [(n, hex(va), hex(ro), hex(rs)) for n, va, vs, ro, rs in sects])


def cstr(va):
    o = va - 0x400000
    return b[o:b.index(b'\0', o)].decode('latin-1')


def va_off(va):
    # 本 PE 的节 RVA 与 PointerToRawData 逐节相等（.text 0x1000/0x1000 等），
    # 且 imagebase=0x400000，故 文件偏移 = VA - 0x400000。用节表断言该等价关系。
    rva = va - 0x400000
    for nm, vbase, vsize, roff, rsize in sects:
        if vbase <= rva < vbase + max(vsize, rsize):
            assert roff == vbase, (nm, hex(roff), hex(vbase))
            return rva
    return None


# ---- region string inventory ----
print('\n== 区域字符串清单 [0x5C9710,0x5C98A0) ==')
region_lo, region_hi = 0x5C9730, 0x5C9884
region_names = []
i = 0x5C9710 - 0x400000
end = 0x5C98A0 - 0x400000
while i < end:
    if 32 <= b[i] < 127:
        j = i
        while j < end and 32 <= b[j] < 127:
            j += 1
        s = b[i:j].decode('latin-1')
        va = 0x400000 + i
        inreg = region_lo <= va <= region_hi
        if inreg:
            region_names.append(s)
        print(f'  {va:08x} {"REGION" if inreg else "      "} {s!r}')
        i = j
    else:
        i += 1
print(f'  region [0x{region_lo:08X},0x{region_hi:08X}] string count = {len(region_names)}')

# ---- mapper disassembly ----
print('\n== 映射器 0x4B63B0..0x4B6940 ==')
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
LO, HI = 0x4B63B0, 0x4B6940
ins = [x for x in md.disasm(b[va_off(LO):va_off(HI)], LO)]


def val(o):
    try:
        return int(o, 0)
    except ValueError:
        return None


entries, cur, after_jne = [], None, False
for x in ins:
    m, o = x.mnemonic, x.op_str
    if m == 'mov' and o.startswith('edi, '):
        cur = {'addr': x.address, 'str': val(o.split(', ')[1]), 'id': None}
        after_jne = False
    elif m == 'mov' and o.startswith('ecx, ') and cur is not None and 'len' not in cur:
        cur['len'] = val(o.split(', ')[1])
    elif m == 'jne':
        after_jne = True
    elif after_jne and cur is not None and cur['id'] is None:
        if m == 'mov' and o.startswith('eax, '):
            cur['id'] = val(o.split(', ')[1])
        elif m == 'xor' and o == 'eax, eax':
            cur['id'] = 0
        if cur['id'] is not None:
            entries.append(cur)
            cur, after_jne = None, False

print(f'  entries={len(entries)}  (chain order = address order, first match wins)')
ok_len = 0
for e in entries:
    s = cstr(e['str'])
    good = (e['len'] == len(s) + 1)
    ok_len += good
    print(f'  {e["addr"]:08x} id=0x{e["id"]:02x}({e["id"]:2d}) len={e["len"]:2d} '
          f'actual={len(s)+1:2d} {"OK" if good else "BAD"} {e["str"]:08x} {s!r} '
          f'{"REGION" if region_lo <= e["str"] <= region_hi else "OUTSIDE"}')
print(f'  length-including-NUL matches: {ok_len}/{len(entries)}')
name_by_id, nodead = {}, []
for e in entries:
    s = cstr(e['str'])
    if s in (cstr(x['str']) for x in entries[:entries.index(e)]):
        nodead.append((s, e['id'], 'DEAD(duplicate name, first match wins)'))
    name_by_id.setdefault(e['id'], []).append(s)
print('  duplicate names:', nodead)
ids = set(name_by_id)
print(f'  distinct ids={len(ids)}  unmapped ids in 1..0x40:',
      [hex(x) for x in range(1, 0x41) if x not in ids])

# ---- vtable anchors ----
print('\n== vtable 锚点 ==')
for tgt in (0x4B63B0, 0x4B6940):
    pat = struct.pack('<I', tgt)
    hits = []
    i = 0
    while True:
        i = b.find(pat, i)
        if i < 0:
            break
        hits.append(0x400000 + i)
        i += 1
    print(f'  abs32 refs to 0x{tgt:08X}: {[hex(h) for h in hits]}')
print('  0x5A9178 - 0x110 = 0x%X (mapper slot)' % (0x5A9178 - 0x110))
print('  0x5A9174 - 0x10C = 0x%X (executor slot)' % (0x5A9174 - 0x10C))

# ---- executor jump table ----
print('\n== 执行器跳表 0x4B7878 (64 x u32) ==')
JT = 0x4B7878
DEF = 0x4B785B
handled, default = [], []
for k in range(0x40):
    tgt = struct.unpack_from('<I', b, va_off(JT) + k * 4)[0]
    (default if tgt == DEF else handled).append((k + 1, tgt))
print(f'  handled ids={len(handled)} default ids={len(default)}')
print('  default ids:', [hex(i) for i, _ in default])
print('  handled id -> handler:')
print('   ', ' '.join(f'{i:02x}:{t:08x}' for i, t in handled))

# ---- community list ----
print('\n== 社区名单核对（docs/12 笔记 44 名 + box off = 45） ==')
community = ['pose', 'weapon', 'loadch', 'loadmych', 'loadmyno', 'disarm', 'reset',
             'dropw', 'switch', 'moveto', 'position', 'box', 'wave', 'mhp', 'ang',
             'win', 'lose', 'cheat', 'testserver', 'test', 'loadsnp', 'loadsn',
             'joins', 'freecam', 'play', 'editai', 'host', 'IP', 'lag', 'shows',
             'mnet', 'FPS', 'kick', 'skick', 'kill', 'camera', 'msense', 'minverse',
             'elight', 'quit', 'record', 'AI', 'adddummy', 'adddummy2', 'box off']
mapper_names = {cstr(e['str']): e for e in entries}
mapper_ci = {}
for nm, e in mapper_names.items():
    mapper_ci.setdefault(nm.lower(), []).append(nm)
print(f'  community list = {len(community)} names')


def section_of(va):
    rva = va - 0x400000
    for nm, vbase, vsize, roff, rsize in sects:
        if vbase <= rva < vbase + max(vsize, rsize):
            return nm
    return None


def real_string_occurrences(name):
    """只认：所在节区不是 .text，且前一字节为 NUL（或文件首）的 NUL 结尾精确串。"""
    pat = name.encode('latin-1') + b'\0'
    out, i = [], 0
    while True:
        i = b.find(pat, i)
        if i < 0:
            break
        va = 0x400000 + i
        sec = section_of(va)
        prev = b[i - 1] if i > 0 else 0
        if sec != '.text' and prev == 0:
            out.append((va, sec))
        i += 1
    return out


exact_mapper, case_mapper, str_only, absent = [], [], [], []
for n in community:
    if n in mapper_names:
        va = mapper_names[n]['str']
        exact_mapper.append((n, va, region_lo <= va <= region_hi))
    elif n.lower() in mapper_ci:
        real = mapper_ci[n.lower()][0]
        va = mapper_names[real]['str']
        case_mapper.append((n, real, va, region_lo <= va <= region_hi))
    elif real_string_occurrences(n):
        str_only.append((n, real_string_occurrences(n)))
    else:
        absent.append(n)
hits = exact_mapper + [(n, va, r) for n, _, va, r in case_mapper]
print(f'  A) exact mapper entries: {len(exact_mapper)}/{len(community)}')
for n, va, inreg in exact_mapper:
    print(f'     {n:12s} {va:08x} {"REGION" if inreg else "outside-region"}')
print(f'  B) case-insensitive mapper hits: {len(case_mapper)}')
for n, real, va, inreg in case_mapper:
    print(f'     {n!r} -> {real!r} {va:08x} {"REGION" if inreg else "outside-region"}')
print(f'  C) standalone non-.text string but NOT in mapper: {len(str_only)}')
for n, occ in str_only:
    print(f'     {n:12s} {[(hex(v), s) for v, s in occ]}')
print(f'  D) absent (no non-.text NUL-terminated occurrence): {len(absent)} {absent}')
for n in absent:
    ci = len(re.findall(re.escape(n.encode()), b, re.I))
    print(f'     {n}: case-insensitive byte-substring occurrences={ci} '
          f'(substring/instruction-immediate not accepted as hit)')
print()
print('== 与用户 41/45 主张的对账 ==')
inreg = [n for n, va, r in hits if r]
outreg = [(n, va) for n, va, r in hits if not r]
print(f'  45 名清单命中（映射器，含大小写回退）: {len(hits)}/45')
print(f'  其中落在连续区 0x5C9730-0x5C9884 : {len(inreg)}')
print(f'  其中在区段外                  : {len(outreg)} -> ' +
      ', '.join(f'{n}@{va:08X}' for n, va in outreg))
print(f'  未命中                        : {len(absent)} -> {absent}')
regname_set = set(region_names)
print(f'  区段内 42 串 == 映射器名字集合: {regname_set <= set(mapper_names)} '
      f'(coverage {len(regname_set & set(mapper_names))}/{len(regname_set)})')
print(f'  映射器唯一名字总数={len(mapper_names)} '
      f'(48 条目 - host 重复 1)；其中区段内 {len(regname_set)}、区段外 '
      f'{len(set(mapper_names) - regname_set)}')
print('  cheat -> id 0x2E，执行器跳表该槽=default(0x4B785B)：映射存在但无处理器')
print('  host  -> 先后注册 0x3F(0x4B6551) 与 0x07(0x4B6B84)，首命中 0x3F，0x07 不可达')
