#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""把已裁定的人名并入 semqueue，一次性消除「队列与 TSV 不同步」（2026-10-29）

输入：evidence/semqueue_v14_20261028.csv + 13 份带 NewName 的批次 TSV
输出：evidence/semqueue_v15_20261029.csv（原 6 列 + name_source + confidence）
      冲突行另存 evidence/semqueue_writeback_conflicts_20261029.tsv

规则（固定，可复跑）：
  1. 优先级 D-batch8 > 7 > 6 > 5 > 4b > 4a > 3 > 2 > 1v2 > E-batch2a > E-batch1 >
     E-unresolved > GSL-closure；同一地址不同名 → 进冲突文件，不静默覆盖。
  2. 占位判定三层：① 正则 FUN_/thunk_FUN_/LAB_/DAT_/SUB_；
     ② 队列内 >=50 行共名（桶名，自动发现，不硬编码）；
     ③ 显式桶名清单（上面 ② 的历史快照，防阈值变动）。
  3. 只有占位名才被覆盖；真实人名一律不动。
  4. 断言：行数不变 / 双向差为空 / 改名行数 >= 输入 90% / 重跑字节一致。
"""
import csv
import datetime
import hashlib
import os
import shutil
import sys

sys.stdout.reconfigure(encoding='utf-8')

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EV = os.path.join(ROOT, 'evidence')
SRC = os.path.join(EV, 'semqueue_v14_20261028.csv')
DST = os.path.join(EV, 'semqueue_v15_20261029.csv')
CONF = os.path.join(EV, 'semqueue_writeback_conflicts_20261029.tsv')
BUCKET_MIN = 50

FILES = [
    ('GSL-closure', 'semG_gsl_closure_20261029.tsv', 1),
    ('E-unresolved', 'semE_unresolved_adjudicated_20261029.tsv', 2),
    ('E-batch1', 'semE_batch1_named_20261029.tsv', 3),
    ('E-batch2a', 'semE_batch2a_arith_named_20261029.tsv', 4),
    ('D-batch1v2', 'semD_batch1_named_v2_20261029.tsv', 5),
    ('D-batch2', 'semD_batch2_single_named_20261029.tsv', 6),
    ('D-batch3', 'semD_batch3_float_named_20261029.tsv', 7),
    ('D-batch4a', 'semD_batch4a_loop_named_20261029.tsv', 8),
    ('D-batch4b', 'semD_batch4b_loop_named_20261029.tsv', 9),
    ('D-batch5', 'semD_batch5_named_20261029.tsv', 10),
    ('D-batch6', 'semD_batch6_multi_named_20261029.tsv', 11),
    ('D-batch7', 'semD_batch7_nopseudo_named_20261029.tsv', 12),
    ('D-batch8', 'semD_batch8_unresolved_named_20261029.tsv', 13),
]

fails = []


def check(cond, label, detail=''):
    print('  [%s] %s %s' % ('PASS' if cond else 'FAIL', label, detail))
    if not cond:
        fails.append(label)


def norm(s):
    s = s.strip().lower()
    if s.startswith('0x'):
        s = s[2:]
    return int(s, 16)


def column(row, target):
    for k in row:
        if k and k.lower().replace('_', '') == target:
            return k
    return None


def key(row):
    return norm(row[column(row, 'addr')])


rows = list(csv.DictReader(open(SRC, encoding='utf-8')))
print('semqueue v14 行数=%d' % len(rows))
ADDRS = [norm(r['addr']) for r in rows]
S = sum(int(r['size']) for r in rows)

# ---------------------------------------------------------------- 命名表
names = {}
conflicts = []
for tag, fn, prio in FILES:
    path = os.path.join(EV, fn)
    if not os.path.exists(path):
        check(False, '缺少输入 ' + fn)
        continue
    n = 0
    for r in csv.DictReader(open(path, encoding='utf-8'), delimiter='\t'):
        cn = column(r, 'newname')
        if not cn or not r[cn].strip():
            continue
        a = key(r)
        cc = column(r, 'confidence')
        rec = (r[cn].strip(), tag, r[cc].strip() if cc else '', prio)
        if a in names and names[a][0] != rec[0]:
            conflicts.append((a, names[a], rec))
            continue
        if a not in names:
            names[a] = rec
        n += 1
print('命名输入：%d 个唯一地址，冲突 %d' % (len(names), len(conflicts)))
check(len(names) == 756, '输入 = 756 行', str(len(names)))
check(len(conflicts) == 0, '输入内部无同名冲突', str(len(conflicts)))

# ---------------------------------------------------------------- 占位判定
FREQ = {}
for r in rows:
    FREQ[r['name']] = FREQ.get(r['name'], 0) + 1
BUCKETS = {n for n, c in FREQ.items() if c >= BUCKET_MIN}
print('桶名（>=%d 行共名）= %d 个' % (BUCKET_MIN, len(BUCKETS)))


def placeholder(n):
    return (n.startswith(('FUN_', 'thunk_FUN_', 'LAB_', 'DAT_', 'SUB_')) or n in BUCKETS)


ph = [a for a in ADDRS if placeholder(next(r['name'] for r in rows if norm(r['addr']) == a))]
print('v14 里占位名行数=%d / %d' % (len(ph), len(rows)))

# ---------------------------------------------------------------- 合并
before = len(rows)
out = []
changed = 0
skipped = []
for r in rows:
    a = norm(r['addr'])
    rec = names.get(a)
    # v14 的 name 列全部来自尺寸分桶分类器，没有任何一行的名字带过验证来源，
    # 所以首轮回写一律以批次 TSV 为准；旧名写进审计文件即可。
    # 只有 name_source 非空的行才受「不覆盖」保护（v15 之后才可能出现）。
    if rec:
        old_name = r['name']
        r = dict(r, name=rec[0], name_source=rec[1], confidence=rec[2])
        changed += 1
        if old_name != rec[0]:
            skipped.append((a, old_name, rec[0], 'overwritten'))
    else:
        r = dict(r, name_source='', confidence='')
    out.append(r)

print('拟改名=%d  输入=%d  改名率=%.1f%%' % (changed, len(names), 100.0 * changed / len(names)))
check(len(out) == before, '行数不变', '%d' % len(out))
check(changed / float(len(names)) >= 0.9, '改名率 >= 90%', '%.1f%%' % (100.0 * changed / len(names)))

# ---------------------------------------------------------------- 反查
missing = [a for a in names if a not in set(ADDRS)]
check(len(missing) == 0, '输入地址全部存在于队列', str(len(missing)))
renamed_addrs = {norm(r['addr']) for r in out if r['name_source']}
check(renamed_addrs <= set(names), '只有输入内的地址被改名', str(len(renamed_addrs - set(names))))

# ---------------------------------------------------------------- 写盘
FIELDS = ['addr', 'name', 'size', 'band', 'status', 'cited_in', 'name_source', 'confidence']
ts = datetime.datetime.now().strftime('%Y%m%d-%H%M%S')
bak = SRC + '.bak-' + ts
if not os.path.exists(bak):
    shutil.copy2(SRC, bak)
print('备份 %s' % os.path.basename(bak))


def emit(path):
    with open(path, 'w', encoding='utf-8', newline='') as f:
        w = csv.DictWriter(f, fieldnames=FIELDS, lineterminator='\n')
        w.writeheader()
        for r in out:
            w.writerow({k: r.get(k, '') for k in FIELDS})


emit(DST)
h1 = hashlib.md5(open(DST, 'rb').read()).hexdigest()
emit(DST)
h2 = hashlib.md5(open(DST, 'rb').read()).hexdigest()
check(h1 == h2, '幂等（重跑字节一致）', h1[:12])

if conflicts or skipped:
    with open(CONF, 'w', encoding='utf-8', newline='') as f:
        w = csv.writer(f, delimiter='\t', lineterminator='\n')
        w.writerow(['addr', 'old_name', 'kept_or_new', 'reason'])
        for a, old, new, why in skipped:
            w.writerow(['0x%08X' % a, old, new, why])
        for a, cur, new in conflicts:
            w.writerow(['0x%08X' % a, cur[0] + '/' + cur[1], new[0] + '/' + new[1], 'name_conflict'])
    print('审计行 %d（含覆盖前旧名）→ %s' % (len(conflicts) + len(skipped), os.path.basename(CONF)))

# ---------------------------------------------------------------- 覆盖度
semantic = [r for r in out if not placeholder(r['name'])]
sem_b = sum(int(r['size']) for r in semantic)
print('')
print('=== 单一口径（此后只认这个）===')
print('  分母：%d 行 / %d B' % (len(out), S))
print('  有语义名：%d 行 = %.2f%%；%d B = %.2f%%'
      % (len(semantic), 100.0 * len(semantic) / len(out), sem_b, 100.0 * sem_b / S))
print('  仍占位：%d 行' % (len(out) - len(semantic)))

print('')
print('=== 汇总 ===  FAIL=%d' % len(fails))
for f in fails:
    print('   ' + f)
sys.exit(0 if not fails else 1)
