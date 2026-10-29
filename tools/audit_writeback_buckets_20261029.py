#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""回写前的桶名审计（2026-10-29）

回答三个问题：
  A. GSL 引用集与已定名集合的重叠 —— 还有多少行真的没名字？
  B. 队列里的桶名（按体长分层发的名字）把哪些集合整体盖住了？
  C. 现行回写规则「已有非占位名不被弱名覆盖」会拦下多少行？

判据只读 semqueue v14 与各批次 TSV，不读 exe；全部断言通过时退出码 0。
"""
import collections
import csv
import os
import sys

sys.stdout.reconfigure(encoding='utf-8')

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EV = os.path.join(ROOT, 'evidence')
SEMQUEUE = os.path.join(EV, 'semqueue_v14_20261028.csv')
BUCKET_MIN = 50

fails = []


def check(cond, label, detail=''):
    print('  [%s] %s %s' % ('PASS' if cond else 'FAIL', label, detail))
    if not cond:
        fails.append(label)


Q = {}
for row in csv.DictReader(open(SEMQUEUE, encoding='utf-8')):
    Q[int(row['addr'], 16)] = row
print('semqueue 行数=%d  sum(size)=%d' % (len(Q), sum(int(r['size']) for r in Q.values())))


def norm(s):
    s = s.strip().lower()
    if s.startswith('0x'):
        s = s[2:]
    return int(s, 16)


def load(fn):
    out = set()
    path = os.path.join(EV, fn)
    for r in csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'):
        k = [x for x in r if x and x.lower() == 'addr'][0]
        try:
            out.add(norm(r[k]))
        except ValueError:
            pass
    return out


D = set()
for fn in sorted(os.listdir(EV)):
    if fn.startswith('semD_batch') and fn.endswith('_named_20261029.tsv'):
        D |= load(fn)
E = set()
for fn in ('semE_getter_reaudit_20261029.tsv', 'semE_batch1_named_20261029.tsv',
           'semE_batch2a_arith_named_20261029.tsv', 'semE_unresolved_adjudicated_20261029.tsv'):
    E |= load(fn)
print('D=%d  E=%d  D∪E=%d' % (len(D), len(E), len(D | E)))
check(len(D) == 612, 'D 段 = 612', str(len(D)))

# ---------------- A. 模板桶与 GSL 的关系
TPL = 'Scene_Particle_Spline_Helper'
tpl = [a for a in D if Q[a]['name'] == TPL]
tpl_all = [a for a in Q if Q[a]['name'] == TPL]
gsl_named = [a for a in tpl if Q[a]['name'] == TPL and False]  # placeholder, 见下
gsl_named = [a for a in tpl if Q[a]['name'] == TPL]  # 同 tpl
print('\n=== A. 模板桶拆分 ===')
print('  队列里共用该桶名 %d 行 / %d B（D 段内 %d 行）'
      % (len(tpl_all), sum(int(Q[a]['size']) for a in tpl_all), len(tpl)))
check(set(tpl_all) == set(tpl), '桶内 161 行全部落在 D 段', '%d' % len(tpl))
check(sum(1 for a in tpl_all if a not in D) == 0, '无一行在 D 段之外（即无一行待判）', '')

# GSL 命名（队列名之外的裁定名）
DNAME = {}
for fn in sorted(os.listdir(EV)):
    if fn.startswith('semD_batch') and fn.endswith('_named_20261029.tsv'):
        for r in csv.DictReader(open(os.path.join(EV, fn), encoding='utf-8'), delimiter='\t'):
            k = [x for x in r if x and x.lower() == 'addr'][0]
            DNAME[norm(r[k])] = r['new_name']

gsl_rows = [a for a in tpl if DNAME[a].lower().startswith('gsl_')]
fam = collections.Counter()
for a in tpl:
    n = DNAME[a]
    if n.lower().startswith('gsl_'):
        fam['Gsl_*'] += 1
    elif n.startswith(('Particle_', 'Scene_')):
        fam['Particle_/Scene_'] += 1
    elif n.startswith(('Ctor_', 'Dtor_')):
        fam['Ctor_/Dtor_'] += 1
    elif n.startswith('Struct_'):
        fam['Struct_*'] += 1
    elif n.startswith(('Crt_', 'EH_', 'Mem_', 'Str_')):
        fam['CRT/EH'] += 1
    else:
        fam['单例其他'] += 1
print('  桶内按 D 段裁定名分族: %s' % dict(fam))
check(len(gsl_rows) == 68, '桶内 Gsl_* = 68（不是 60）', str(len(gsl_rows)))
check(fam['Particle_/Scene_'] == 19, '真·粒子/场景 = 19', str(fam['Particle_/Scene_']))
check(len(tpl_all) - len(gsl_rows) == 93, '非 GSL 余 = 93（不是 101）',
      str(len(tpl_all) - len(gsl_rows)))
band = collections.Counter(Q[a]['band'] for a in tpl_all)
check(list(band) == ['D_101-300B'], '桶内 band 单一 = D_101-300B', str(dict(band)))

# ---------------- B. 桶名清单
print('\n=== B. 队列里 ≥%d 行共用的名字 ===' % BUCKET_MIN)
cnt = collections.Counter(r['name'] for r in Q.values())
buckets = {n: c for n, c in cnt.items() if c >= BUCKET_MIN}
for n, c in sorted(buckets.items(), key=lambda x: -x[1]):
    print('   %-42s %5d 行' % (n, c))
check(len(buckets) >= 14, '桶名 ≥14 个', str(len(buckets)))
check(buckets.get('Inline_Getter_Setter') == 261, 'Inline_Getter_Setter = 261', '')


def is_bucket(n):
    return (n.startswith(('FUN_', 'thunk_FUN_', 'LAB_', 'DAT_', 'SUB_'))
            or n in buckets)


# ---------------- C. 回写拦截率
print('\n=== C. 现行「非占位名不被覆盖」规则的拦截率 ===')
rows = []
for label, st in (('D 612', D), ('E 并集', E), ('D∪E', D | E)):
    blocked = [a for a in st if is_bucket(Q[a]['name'])]
    rows.append((label, len(st), len(blocked)))
    print('   %-8s 共 %4d，被拦 %4d (%.1f%%)，实际可改 %4d'
          % (label, len(st), len(blocked), 100.0 * len(blocked) / len(st), len(st) - len(blocked)))
check(rows[0][2] == 566, 'D 段被拦 566', str(rows[0][2]))
check(rows[1][2] == 261, 'E 段被拦 261（全部）', str(rows[1][2]))
check(rows[2][2] == 827, 'D∪E 被拦 827', str(rows[2][2]))

# E 段与桶名完全重合
inline = set(a for a in Q if Q[a]['name'] == 'Inline_Getter_Setter')
eg = load('semE_getter_reaudit_20261029.tsv')
print('   E getter_reaudit %d 行 vs 队列 Inline_Getter_Setter %d 行：交集 %d、落空 %d'
      % (len(eg), len(inline), len(eg & inline), len(eg - inline)))
check(eg == inline, 'E getter_reaudit 与桶名集合完全重合', '')

print('\n=== 汇总 ===')
print('  FAIL=%d' % len(fails))
for f in fails:
    print('   ' + f)
sys.exit(0 if not fails else 1)
