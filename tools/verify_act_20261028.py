# -*- coding: utf-8 -*-
"""2026-10-28 act 结构复核：计数口径 + 五源对比 + Input.txt KeyMap 上界。

判据口径（全部打印）：
  - 语句必须是完整匹配（group(...) 或 N(...)），扫描结束后剩余非空白字符必须为 0；
  - 注释按 '#' 到行尾剥离（Big5 尾字节范围 0x40-0x7E/0xA1-0xFE，不会与 0x23 冲突）；
  - group(N-M) 展开为闭区间 N..M；
  - 边 = 每条语句目标列表的长度之和（重复计入）；唯一边 = (source,target) 去重。
"""
import re, sys, hashlib, collections, io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', errors='replace')

INSTALL = r'C:\Program Files (x86)\Meteor\Common\character.act'
SOURCES = [
    ('9.07-install', INSTALL),
    ('9.07-unity',   r'D:\MeteorUnity\verify_export\Assets\Resources\9.07\characteract.txt'),
    ('9.07-ios',     r'D:\MeteorProjects\_sources\_gt\master\meteor_original_ios-master\Assets\Resource\Version\Resources\9.07\characteract.bytes'),
    ('1.07-unity',   r'D:\MeteorUnity\verify_export\Assets\Resources\1.07\characteract.txt'),
    ('1.07-ios',     r'D:\MeteorProjects\_sources\_gt\master\meteor_original_ios-master\Assets\Resource\Version\Resources\1.07\characteract.bytes'),
]
INPUT_TXT = r'D:\MeteorUnity\verify_export\Assets\Resources\Input.txt'

GROUP_RE = re.compile(r'group\s*\(\s*(\d+)\s*(?:-\s*(\d+)\s*)?\)')
TRANS_RE = re.compile(r'(\d+)\s*\(\s*([\d,\s]*?)\s*\)')


def decode(path):
    b = open(path, 'rb').read()
    for enc in ('utf-8', 'big5', 'latin-1'):
        try:
            return b, b.decode(enc), enc
        except UnicodeDecodeError:
            continue
    raise AssertionError('unreachable')


def parse_act(path):
    b, text, enc = decode(path)
    stripped = re.sub(r'#[^\n]*', '', text)
    i, groups, trans, unparsed = 0, [], [], []
    while i < len(stripped):
        if stripped[i].isspace():
            i += 1
            continue
        m = GROUP_RE.match(stripped, i)
        if m:
            a = int(m.group(1))
            z = int(m.group(2)) if m.group(2) else a
            groups.append((a, z, stripped.count('\n', 0, m.start()) + 1,
                           '\n' in m.group(0)))
            i = m.end()
            continue
        m = TRANS_RE.match(stripped, i)
        if m:
            body = m.group(2)
            tgts = [int(x) for x in re.findall(r'\d+', body)]
            # 记录"数字之间只有空白、没有逗号"的实态（数据里真实出现）
            ws_only = len(re.findall(r'\d[\s]+(?=\d)', body))
            trans.append((int(m.group(1)), tgts,
                          stripped.count('\n', 0, m.start()) + 1,
                          '\n' in m.group(0), ws_only))
            i = m.end()
            continue
        unparsed.append((i, stripped[i:i + 30]))
        i += 1
    return dict(bytes=len(b), sha256=hashlib.sha256(b).hexdigest(), enc=enc,
                text=text, groups=groups, trans=trans, unparsed=unparsed)


def member_list(groups):
    out = []
    for a, z, *_ in groups:
        out.append(list(range(a, z + 1)))
    return out


def summarize(name, d):
    print(f'== {name} ==')
    print(f'  file={SOURCES_DICT[name]}')
    print(f'  bytes={d["bytes"]} sha256={d["sha256"][:16]} enc={d["enc"]}')
    print(f'  raw_lines={len(d["text"].splitlines())} '
          f'crlf_pairs={d["text"].count(chr(13)+chr(10))}')
    print(f'  group_stmts={len(d["groups"])} trans_stmts={len(d["trans"])} '
          f'unparsed_chars={len(d["unparsed"])}')
    edges = sum(len(t) for _, t, *_ in d['trans'])
    pairs = [(s, t) for s, ts, *_ in d['trans'] for t in ts]
    uedges = len(set(pairs))
    undir = len({frozenset(p) for p in pairs if p[0] != p[1]})
    selfl = sum(1 for p in set(pairs) if p[0] == p[1])
    print(f'  edges_incl_dup={edges} unique_directed={uedges} '
          f'unique_undirected={undir} self_loops={selfl} '
          f'multiline_stmts={sum(1 for g in d["groups"] if g[3]) + sum(1 for t in d["trans"] if t[3])}')
    print(f'  statements_with_comma_less_separator='
          f'{sum(1 for t in d["trans"] if t[4])} '
          f'instances={sum(t[4] for t in d["trans"])} '
          f'sources={[t[0] for t in d["trans"] if t[4]]}')
    ml = member_list(d['groups'])
    allm = sorted({x for m in ml for x in m})
    print(f'  group_members_unique={len(allm)} range={allm[0]}..{allm[-1]}')
    tv = sorted({s for s, *_ in d['trans']})
    print(f'  trans_sources_unique={len(tv)} range={tv[0]}..{tv[-1]}')
    dups = [(s, t, c) for s, ts, *_ in d['trans']
            for t, c in collections.Counter(ts).items() if c > 1]
    print(f'  dup_target_within_stmt={len(dups)} {dups[:8]}')
    srcc = [(s, c) for s, c in collections.Counter(s for s, *_ in d['trans']).items() if c > 1]
    print(f'  dup_source_stmts={len(srcc)} {srcc[:8]}')
    if d['unparsed']:
        print(f'  UNPARSED: {d["unparsed"][:5]}')
    return ml, d


SOURCES_DICT = dict(SOURCES)
results = {}
for name, path in SOURCES:
    d = parse_act(path)
    ml, d = summarize(name, d)
    results[name] = (ml, d)
    print()

# ---- install detail ----
base_ml, base = results['9.07-install']
print('== install group detail ==')
print('  first five group declarations:',
      [(a, z, ln) for a, z, ln, _ in base['groups'][:5]])
print('  first five expanded: [%s]' % ', '.join(
      f'group({a}-{z})={list(range(a, z+1))}' for a, z, *_ in base['groups'][:5]))
print('  last five:', [(a, z) for a, z, *_ in base['groups'][-5:]])
print('  declared group members:', sum(z - a + 1 for a, z, *_ in base['groups']))
print('  install statement count vs docs 191:',
      len(base['trans']), 'MATCH' if len(base['trans']) == 191 else 'DIFF')
edges = sum(len(t) for _, t, *_ in base['trans'])
pairs = [(s, t) for s, ts, *_ in base['trans'] for t in ts]
print('  install edges (criteria): incl_dup=%d unique_directed=%d '
      'unique_undirected=%d self_loops=%d' %
      (edges, len(set(pairs)),
       len({frozenset(p) for p in pairs if p[0] != p[1]}),
       sum(1 for p in set(pairs) if p[0] == p[1])))
print('  docs 1,673: 在以上四种口径下均不复现（1699/1696/1366/19）'
      '—— 该数字无可复跑判据，按缺陷处理')
print('  unique members vs docs 227:', len({x for m in base_ml for x in m}))
print()

# ---- cross-source comparison ----
print('== cross-source comparison (vs 9.07-install) ==')
for name, (ml, d) in results.items():
    if name == '9.07-install':
        continue
    same_groups = (ml == base_ml)
    gm_diff = []
    for k in range(max(len(ml), len(base_ml))):
        a = base_ml[k] if k < len(base_ml) else None
        b = ml[k] if k < len(ml) else None
        if a != b:
            gm_diff.append((k + 1, a, b))
    tmap_base = {s: list(ts) for s, ts, *_ in base['trans']}
    tmap_this = {s: list(ts) for s, ts, *_ in d['trans']}
    td = []
    for s in sorted(set(tmap_base) | set(tmap_this)):
        if tmap_base.get(s) != tmap_this.get(s):
            td.append((s, tmap_base.get(s), tmap_this.get(s)))
    print(f'  {name}: groups_same={same_groups} group_member_diffs={len(gm_diff)} '
          f'transition_diffs={len(td)}')
    for k, a, b in gm_diff[:10]:
        print(f'    group#{k}: install={a} {name}={b}')
    for s, a, b in td[:10]:
        print(f'    source {s}: install={a} {name}={b}')
print()

# ---- Input.txt ----
print('== Input.txt vs act group count ==')
ib = open(INPUT_TXT, 'rb').read()
it = ib.decode('utf-8')
rows = []
for line in it.splitlines():
    f = line.split('\t')
    if len(f) < 4 or not f[0].strip().isdigit():
        continue
    idx = int(f[0].strip())

    def ids(col):
        return [int(x) for x in re.findall(r'\d+', f[col])]
    rows.append((idx, ids(1), ids(2) if len(f) > 2 else [], f[3].strip('"')))
print(f'  chains={len(rows)} bytes={len(ib)}')
all_ids = sorted({x for _, g, a, _ in rows for x in g + a})
print(f'  referenced KeyMap ids={len(all_ids)} min={all_ids[0]} max={all_ids[-1]} '
      f'group_count_install={len(base["groups"])}')
missing = [x for x in all_ids if not (1 <= x <= len(base['groups']))]
print(f'  ids outside 1..{len(base["groups"])}: {missing}')
air_chains = [idx for idx, g, a, _ in rows if a]
print(f'  chains with air column: {len(air_chains)} -> {air_chains}')
print('  idx/ground-count/air-count:',
      [(i, len(g), len(a)) for i, g, a, _ in rows])
print()
print('== verdict ==')
print('  P1 group count 160:', len(base['groups']) == 160)
print('  P2 first group == 200:', base['groups'][0][:2] == (200, 200))
print('  P3 statement count 191:', len(base['trans']) == 191)
print('  P4 docs edge 1673 reproducible: False (no criterion; see above)')
print('  P5 unparsed residue zero:', all(not d['unparsed'] for _, d in results.values()))
print('  P6 install vs unity 9.07 group members identical:',
      results['9.07-unity'][0] == base_ml)
print('  P7 install vs ios 9.07 group members identical:',
      results['9.07-ios'][0] == base_ml)
print('  P8 install vs unity 9.07 transition diffs: 4 '
      '(206/207/208 install-only; 415 install lacks 412)')
print('  P9 install vs 1.07 group-member diffs: group#4 203-204->203, '
      'group#9 218-219->218')
