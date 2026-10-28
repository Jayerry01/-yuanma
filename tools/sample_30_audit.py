# -*- coding: utf-8 -*-
import csv, random, os

random.seed(20261028)

bands = {
    'B_>1000B': [],
    'C_301-1000B': [],
    'D_101-300B': [],
    'E_33-100B': [],
    'F_<=32B': []
}

with open(r'D:\MeteorRE\evidence\semqueue_v14_20261028.csv', 'r', encoding='utf-8') as f:
    reader = csv.DictReader(f)
    for row in reader:
        b = row.get('band')
        if b in bands:
            bands[b].append(row)

sample_counts = {
    'B_>1000B': 3,
    'C_301-1000B': 5,
    'D_101-300B': 7,
    'E_33-100B': 7,
    'F_<=32B': 8
}

samples = []
for b, count in sample_counts.items():
    s = random.sample(bands[b], count)
    samples.extend(s)

print(f"Total sampled: {len(samples)}")
results = []
for i, row in enumerate(samples, 1):
    addr = row['addr']
    size = int(row['size'])
    band = row['band']
    name = row['name']
    cited = row.get('cited_in', '')
    
    # Check if there is pseudo code
    pseudo_paths = [
        f"D:/MeteorRE/evidence/semB_pseudo/{addr.lower()}.c",
        f"D:/MeteorRE/evidence/semC_pseudo/{addr.lower()}.c",
        f"D:/MeteorRE/evidence/semD_pseudo/{addr.lower()}.c",
        f"D:/MeteorRE/evidence/semE_pseudo/{addr.lower()}.c",
    ]
    has_pseudo = any(os.path.exists(p) for p in pseudo_paths)
    
    results.append({
        'idx': i,
        'addr': addr,
        'size': size,
        'band': band,
        'name': name,
        'has_pseudo': has_pseudo,
        'cited': cited
    })

for r in results:
    print(f"#{r['idx']:02d} | {r['band']} | 0x{r['addr']} | {r['size']:4d}B | Name: {r['name']} | Pseudo: {r['has_pseudo']} | Cited: {r['cited'][:30]}")
