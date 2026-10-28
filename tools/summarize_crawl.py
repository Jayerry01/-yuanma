# -*- coding: utf-8 -*-
import json
import sys

sys.stdout.reconfigure(encoding='utf-8')

with open(r'D:\MeteorRE\evidence\lxres_top20_all_categories.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

for cat, d in data.items():
    print(f"\n==========================================")
    print(f"【{cat}】")
    print(f"--- Top 20 热门 (共 {len(d['top_20_hot'])} 项) ---")
    for i, it in enumerate(d['top_20_hot']):
        print(f"  {i+1:02d}. {it['title']} | 作者: {it['author']} | 大小: {it['size']} | 星级: {it['rating_star']}★ | 日期: {it['update_date']}")
    print(f"\n--- Top 20 评分 (共 {len(d['top_20_score'])} 项) ---")
    for i, it in enumerate(d['top_20_score']):
        print(f"  {i+1:02d}. {it['title']} | 作者: {it['author']} | 大小: {it['size']} | 星级: {it['rating_star']}★ | 日期: {it['update_date']}")
