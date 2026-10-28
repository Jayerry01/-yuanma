# -*- coding: utf-8 -*-
import json
import sys

sys.stdout.reconfigure(encoding='utf-8')

with open(r'D:\MeteorRE\evidence\lxres_top20_all_categories.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

for cat in ['补丁工具', '单机任务', '地图下载', '人物武器', '主题光影']:
    d = data[cat]
    print(f"\n==========================================")
    print(f"=== {cat} ===")
    print("HOT Top 10:")
    for i, it in enumerate(d['top_20_hot'][:10]):
        print(f"  {i+1:02d}. {it['title']} ({it['author']}, {it['size']}) -> {it['url']}")
    print("SCORE Top 10:")
    for i, it in enumerate(d['top_20_score'][:10]):
        print(f"  {i+1:02d}. {it['title']} ({it['author']}, {it['size']}, {it['rating_star']}★) -> {it['url']}")
