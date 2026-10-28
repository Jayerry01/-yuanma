# -*- coding: utf-8 -*-
"""U1 数据等价预备：1559(招名/按键) x PoseMap/P0.POS(招名->pose) x character.act(pose->组) x Input.txt(InputString->KeyMap id)

核心待验假设 H1: Input.txt 的 KeyMap id == character.act 中 group() 行的 1-based 文件序。
判定依据全部打印；不采样的行不省略。
输出: evidence/u1_chain_20261028_out.txt
"""
import re, sys, io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

ACT     = r'C:\Program Files (x86)\Meteor\Common\character.act'
POS     = r'C:\Program Files (x86)\Meteor\pmodel\P0.POS'
POSEMAP = r'C:\Program Files (x86)\Meteor\ddfix_assets\PoseMap.txt'
EXTRACT = r'D:\MeteorRE\evidence\pose_table_1758_extract.txt'
LX1559  = r'D:\MeteorRE\evidence\lxres_raw_20261028\1559.txt'
INPUT   = r'D:\MeteorUnity\verify_export\Assets\Resources\Input.txt'
OUT     = r'D:\MeteorRE\evidence\u1_chain_20261028_out.txt'

rep = []
def P(*a):
    s = ' '.join(str(x) for x in a)
    rep.append(s)

# ---------- 1. character.act ----------
act_raw = open(ACT, 'rb').read().decode('big5', 'replace')
groups = []          # (ordinal1based, begin, end, raw, comment)
stmts = {}           # pose -> [targets]
unparsed = []
pend = None
buf = ''
for ln in act_raw.splitlines():
    s = ln.strip()
    if not s:
        continue
    if s.startswith('#'):
        if buf:
            unparsed.append(buf); buf = ''
        pend = s[1:].strip()
        continue
    if buf:
        buf += s
    else:
        buf = s
    if buf.endswith(')'):
        t, buf = buf, ''
    else:
        continue
    s = t
    m = re.match(r'group\((\d+)(?:-(\d+))?\)$', s)
    if m:
        b = int(m.group(1)); e = int(m.group(2) or m.group(1))
        groups.append([len(groups) + 1, b, e, s, pend])
        pend = None
        continue
    m = re.match(r'(\d+)\(([\d,\s]*)\)$', s)
    if m:
        stmts.setdefault(int(m.group(1)), []).extend(
            int(x) for x in m.group(2).replace(' ', '').split(',') if x)
        continue
    unparsed.append(s)

P('=' * 100)
P('SECTION 0: 输入口径')
P('  act     :', ACT, len(act_raw.splitlines()), 'lines')
P('  P0.POS  :', POS)
P('  PoseMap :', POSEMAP, '(ddfix 社区文件, 三叔整理, UTF8 BOM — 非原版数据, 仅旁证)')
P('  extract :', EXTRACT, '(lxres 1758 社区表抽取 — 非原版数据)')
P('  1559    :', LX1559, '(lxres 招式表 — 非原版数据)')
P('  Input   :', INPUT, '(MeteorUnity 移植工程数据 — 非原版数据)')
P('  判定假设 H1: Input.txt KeyMap id == act group() 行 1-based 文件序')
P('=' * 100)

P('SECTION A: character.act 解析')
uniq_dir = set()
self_loops = 0
for k, ts in stmts.items():
    for t in ts:
        uniq_dir.add((k, t))
        if k == t:
            self_loops += 1
P('  group() 总数 =', len(groups), ' (期望 160)')
P('  语句( pose(targets) )总数 =', len(stmts), '个源 pose / 边: 含重边',
  sum(len(v) for v in stmts.values()), ' 去重有向', len(uniq_dir), ' 自环', self_loops)
P('  [口径注] 旧台账 1,699 含重边系旧脚本对 2 条跨行语句未折叠的伪影; 折叠后含重边 =',
  sum(len(v) for v in stmts.values()))
P('  未解析行 =', len(unparsed), unparsed[:5])
gpos = {}
for o, b, e, raw, c in groups:
    for p in range(b, e + 1):
        gpos.setdefault(p, []).append(o)
dup_gpos = {p: v for p, v in gpos.items() if len(v) > 1}
P('  pose 归属多组的 pose 数 =', len(dup_gpos), dup_gpos)
by_ord = {o: (b, e, c) for o, b, e, raw, c in groups}

# ---------- 2. P0.POS comments ----------
pos_c = {}
data = open(POS, 'rb').read()
for m in re.finditer(rb'(\d+)\s+#([^\r\n]*)', data):
    i = int(m.group(1)); t = m.group(2).decode('big5', 'replace')
    if i in pos_c and pos_c[i] != t:
        P('  !! P0.POS 注释自冲突 pose', i, pos_c[i], '|', t)
    pos_c[i] = t
P('  P0.POS 注释 pose 数 =', len(pos_c), ' id 范围',
  min(pos_c), '-', max(pos_c))

# ---------- 3. PoseMap (community) ----------
pm_sec = None
pm = {}   # pose -> (section, name, keys, airflag)
for ln in open(POSEMAP, encoding='utf-8-sig'):
    ln = ln.rstrip('\n').lstrip('﻿').strip()
    if not ln:
        continue
    if ln.startswith(';'):
        pm_sec = ln.lstrip(';').strip()
        continue
    m = re.match(r'(\d+)\s+(\S+)\s*(.*)$', ln)
    if not m:
        P('  !! PoseMap 未解析行:', repr(ln))
        continue
    pid = int(m.group(1)); name = m.group(2); rest = m.group(3).strip()
    air = ('空中' in rest) or ('(空)' in rest) or ('（空）' in rest)
    pm[pid] = (pm_sec, name, rest, air)
P('  PoseMap 行数 =', len(pm), ' 分区:', sorted(set(v[0] for v in pm.values()), key=lambda x: str(x)))

# ---------- 4. extract 1758 (community) ----------
ex = {}
for ln in open(EXTRACT, encoding='utf-8'):
    ln = ln.strip()
    if not ln:
        continue
    m = re.match(r'(\d+)\s+(.*)$', ln)
    if m:
        ex[int(m.group(1))] = m.group(2)
P('  extract(1758) 行数 =', len(ex))

# ---------- 5. Input.txt ----------
chains = {}   # idx -> dict(ids, ids_air, inputstring, desc)
rows = open(INPUT, encoding='utf-8').read().splitlines()
data_rows = [r for r in rows if r.strip() and not r.startswith('Idx') and not r.startswith('ID')]
for r in data_rows:
    f = [x.strip() for x in r.split('\t')]
    idx = int(f[0])
    ids = [int(x) for x in f[1].strip('"').split(',') if x]
    air = [int(x) for x in f[2].strip('"').split(',') if x] if len(f) > 2 else []
    ins = f[3] if len(f) > 3 else ''
    desc = f[5] if len(f) > 5 else ''
    chains[idx] = dict(ids=ids, air=air, ins=ins, desc=desc)
allids = sorted(set(sum([c['ids'] + c['air'] for c in chains.values()], [])))
P('  Input.txt 链数 =', len(chains), ' 引用 id 数 =', len(allids),
  ' min', min(allids), ' max', max(allids))
P('  id 超出 1..%d 的:' % len(groups), [i for i in allids if i < 1 or i > len(groups)])
missing = [i for i in range(1, len(groups) + 1) if i not in allids]
P('  未被任何链引用的组号 =', missing)

# ---------- 6. 1559 ----------
WSEC = {'飞镖': '飛鏢', '火铳': '火銃', '飞轮': '飛輪', '双刺': '雙刺', '匕首': '匕首',
        '轻剑': '劍', '长枪': '槍', '大刀': '刀', '重锤': '錘', '乾坤刀': '乾坤',
        '指虎': '指虎', '忍刀': '忍刀'}
DIRMAP = {'↑': 'W', '↓': 'S', '←': 'A', '→': 'D', '前': 'W', '後': 'S', '后': 'S',
          '上': 'W', '下': 'S', '左': 'A', '右': 'D'}
def norm_keys(k):
    """1559/ PoseMap 按键串 -> InputString; 返回 (code, air, raw_note)"""
    t = k.replace(' ', '').replace('·', '').replace('、', '').replace('（', '(').replace('）', ')')
    air = ('空中' in t) or ('(空)' in t) or t.endswith('空')
    t = t.replace('(空中)', '').replace('空中', '').replace('(空)', '')
    while t.endswith('空'):
        t = t[:-1]
    if not t.endswith('A'):
        return None, air, t
    body = t[:-1]
    code = ''
    for ch in body:
        d = DIRMAP.get(ch)
        if d is None:
            return None, air, t
        code += d
    return code + 'J', air, t

lines1559 = [l.rstrip('\n') for l in open(LX1559, encoding='utf-8')]
WSEC = set(WSEC) if isinstance(WSEC, set) else WSEC
ROW_RE = re.compile(r'^(\S+)\s+([↑↓←→][↑↓←→ ]*A|A)(?:\s+(.*))?$')
HDR = {'招式名称', '招式按键', '需连招式', '武学名称', '备注', '地面招式', '空中招式'}
moves = []
cur_w = None; cur_area = None
for l in lines1559:
    l = l.strip()
    if l in WSEC:
        cur_w = l; continue
    if l == '地面招式':
        cur_area = '地面'; continue
    if l == '空中招式':
        cur_area = '空中'; continue
    if (not l) or l in HDR or '招式按键' in l:
        continue
    m = ROW_RE.match(l)
    if m and m.group(1) not in HDR and m.group(1) not in WSEC \
            and not set(m.group(1)) <= set('↑↓←→前後后左右上下'):
        moves.append(dict(w=cur_w, area=cur_area, name=m.group(1),
                          keys=m.group(2), rest=(m.group(3) or '').split()))

P('  1559 解析移动数 =', len(moves), ' 武器分区:',
  sorted(set(m['w'] for m in moves), key=lambda x: str(x)))

# ---------- SECTION B: 每条链解码 ----------
P('=' * 100)
P('SECTION B: Input.txt 20 链逐一解码 (id -> act 组 -> pose -> 名称) — 判定依据: H1 文件序')
for idx in sorted(chains):
    c = chains[idx]
    P('-' * 100)
    P('链 %2d  InputString=%-6s  Desc=%s   ground=%s air=%s' %
      (idx, c['ins'], c['desc'], c['ids'], c['air']))
    for tag, lst in (('G', c['ids']), ('A', c['air'])):
        for gid in lst:
            if gid not in by_ord:
                P('   %s %-3d !! 无此组号' % (tag, gid)); continue
            b, e, com = by_ord[gid]
            poses = range(b, e + 1)
            names = []
            for p in poses:
                nm = []
                if p in pm: nm.append('PM:' + pm[p][1] + '[' + pm[p][2] + ']')
                if p in pos_c: nm.append('POS:' + pos_c[p])
                if p in ex: nm.append('EX:' + ex[p])
                names.append('p%d(%s)' % (p, ' / '.join(nm) if nm else '无名'))
            P('   %s %-3d group(%d-%d)%s %s' %
              (tag, gid, b, e, (' #' + com) if com else '', ' | '.join(names)))

# ---------- SECTION C: 1559 逐招 -> 预期链 vs 实际链 ----------
P('=' * 100)
P('SECTION C: 1559 每招预期链 (按键->InputString) vs 实际含其组之链 — 判定依据: 组号∈链id集')
stat = dict(HIT=0, MISS=0, AMBIG=0, NOPOSE=0, NOCODE=0)
misses = []
# 字节仲裁登记: P0.POS 注释 (pose->方向) 推翻社区表之处
ARBIT = {
    '忍瞬移－右': 'P0.POS#527=忍刀地右瞬移 → Input.txt DDJ 正确, 1559/PoseMap 的 后/右 互换',
    '忍瞬移－后': 'P0.POS#529=忍刀地後瞬移 → Input.txt SSJ 正确, 1559/PoseMap 的 后/右 互换',
    '忍瞬空－右': 'P0.POS#531=忍刀空右瞬移 → 同上',
    '忍瞬空－后': 'P0.POS#533=忍刀空後瞬移 → 同上',
}
# PoseMap 无键/缺行, 依 extract+act+链集合互补 人工定位 (判定依据逐条打印)
MANUAL = {
    '乘风':   (557, 'extract#557=双刺地[小绝]加速绕跑专用招 ↓↓↑A; act组#149=group(557)∈链17 SSWJ'),
    '合太极': (244, 'PoseMap#244=合太極起手(无键); extract#244 keys=↓←→A; act组#21=group(244)∈链15 SADJ; 链15 Desc=双刺大招'),
    '鬼弹':   (256, 'PoseMap#256=鬼彈 上下A（空）; P0.POS#256旁证'),
    '伏龙翔天破': (562, 'PoseMap#562/563无键; act组#154=group(562-563)∈链14 ADSJ; ADSJ 五成员中其余四招(腥风/伏虎腾翔跌/虎王虐袭杀/隐身)已各自HIT, 集合互补唯一'),
    '焚雷':   (216, 'P0.POS#217=鎗怒射擊(释出pose无group); P0.POS#216=鎗怒瞄準=触发组; act组#8=group(216)∈链8 SWWJ; 与落樱雪 group(203-204) 同形(起手+释出, 此处释出组缺)→触发组记 hit'),
    '刻铭':   (265, 'P0.POS#265=劍空重1 下插起手=触发pose, #342=劍下插 緩衝(PoseMap 误把缓冲当招); act组#47=group(265)∈链2 air'),
}
MANUAL2 = {('大刀', '空踢'): (338, 'P0.POS#338=一般空踢; 链1 Desc=所有重武器的空中A都是338动作; act组#59=group(338)∈链1 air'),
           ('重锤', '空踢'): (338, '同上: 重武器共用 338'), }
for mv in moves:
    code, airk, rawk = norm_keys(mv['keys'])
    air = (mv['area'] == '空中') or airk
    sec = WSEC.get(mv['w'], mv['w'])
    if mv['name'] in MANUAL or (mv['w'], mv['name']) in MANUAL2:
        key = mv['name'] if mv['name'] in MANUAL else (mv['w'], mv['name'])
        src = MANUAL.get(key) or MANUAL2[key]
        cands = [src[0]]
        P('MANUAL| %s %s %-8s keys=%-8s pose=%d 判据: %s' %
          (mv['w'], mv['area'], mv['name'], rawk, cands[0], src[1]))
    else:
        cands = [p for p, v in pm.items()
                 if v[0] == sec and (v[3] or ('空' in v[2].replace(' ', ''))) == air
                 and norm_keys(v[2])[0] == code] if code else []
    if not code:
        stat['NOCODE'] += 1
        P('NOCODE | %s %s %s keys=%r rest=%r' % (mv['w'], mv['area'], mv['name'], mv['keys'], mv['rest']))
        continue
    if not cands:
        stat['NOPOSE'] += 1
        misses.append((mv, code, air, [], 'PoseMap 无同区同键候选'))
        P('NOPOSE | %s %s %-8s keys=%-8s -> %-6s (PoseMap 该区无此键组合)' %
          (mv['w'], mv['area'], mv['name'], rawk, code))
        continue
    if len(cands) > 1:
        stat['AMBIG'] += 1
    ords = sorted(set(sum([gpos.get(p, []) for p in cands], [])))
    ch = [c for c in chains.values() if c['ins'] == code]
    if not ch:
        stat['MISS'] += 1
        misses.append((mv, code, air, ords, '无该 InputString 的链'))
        P('MISS   | %s %s %-8s keys=%-8s -> %-6s poses=%s ords=%s 无链' %
          (mv['w'], mv['area'], mv['name'], rawk, code, cands, ords))
        continue
    pool = set(ch[0]['air'] if air else ch[0]['ids'])
    ok = [o for o in ords if o in pool]
    # 实际包含这些组的所有链(按同 InputString 口径)
    ver = 'HIT' if ok else 'MISS'
    if ver == 'MISS' and mv['name'] in ARBIT:
        stat[ver] += 1
        P('%-6s | %s %s %-10s keys=%-9s -> %-6s poses=%s ords=%s 链%s=%s  [%s]' %
          (ver, mv['w'], mv['area'], mv['name'], rawk, code, cands, ords,
           'air' if air else 'gnd', sorted(pool), ARBIT[mv['name']]))
        continue
    stat[ver] += 1
    if ver == 'MISS':
        misses.append((mv, code, air, ords, '组号不在 %s 链 %s' %
                       (code, ch[0]['air'] if air else ch[0]['ids'])))
    P('%-6s | %s %s %-10s keys=%-9s -> %-6s poses=%s ords=%s 链%s=%s' %
      (ver, mv['w'], mv['area'], mv['name'], rawk, code, cands, ords,
       'air' if air else 'gnd', sorted(pool)))
P('-' * 100)
P('SECTION C 汇总:', stat, ' / 总', len(moves))

# ---------- SECTION D: act 语句 vs 1559 需连招式 抽查 ----------
P('=' * 100)
P('SECTION D: act 语句(连招边) 与 1559 需连招式 抽查 — 打印边, 不下自动化结论')
SAMPLE = [230, 231, 248, 249, 250, 279, 280, 281, 295, 296, 297, 407, 408, 409,
          461, 541, 542, 543, 262, 263, 315, 478, 200, 206, 218, 430, 432]
for k in SAMPLE:
    if k in stmts:
        P('  stmt %d -> %s' % (k, stmts[k]))
P('  语句覆盖的源 pose 数 =', len(stmts))

# ---------- SECTION E: 反例与特例清单 ----------
P('=' * 100)
P('SECTION E: 特例/反例登记')
P('  E1 无 group() 定义的 pose (仅出现在语句/PoseMap): ',
  sorted(set(list(stmts.keys()) + list(pm.keys())) - set(gpos.keys())))
P('  E2 同时出现在多条链的组号:')
own = {}
for idx in sorted(chains):
    for gid in chains[idx]['ids']:
        own.setdefault(gid, []).append((idx, 'G'))
    for gid in chains[idx]['air']:
        own.setdefault(gid, []).append((idx, 'A'))
for gid, v in sorted(own.items()):
    if len(v) > 1:
        b, e, com = by_ord.get(gid, ('?', '?', ''))
        raw = next((g[3] for g in groups if g[0] == gid), '?')
        P('    id %-3d %s chains=%s %s' % (gid, raw, v, pos_c.get(b, '')))
P('  E3 判定注记: extract 键位疑似错标 243(↑↓ vs ↑↑ 十字鞭), 215(↓↓↑ vs ↓↑ 炎狱) — 均被链成员+PoseMap+1559 三方推翻;')
P('     忍瞬移 后/右: P0.POS 字节注释(#527 右/#529 后/#531 空右/#533 空后) 支持 Input.txt, 推翻 1559+PoseMap(两表同源互传);')
P('     释出pose无组的招: 焚雷(217), 火铳族 217 同理; 语句可达但无触发组的 pose: 见 E1.')

open(OUT, 'w', encoding='utf-8').write('\n'.join(rep) + '\n')
print('written', OUT, len(rep), 'lines')
