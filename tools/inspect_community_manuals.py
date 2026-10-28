# -*- coding: utf-8 -*-
import json
import urllib.request
import re
import sys
from bs4 import BeautifulSoup

sys.stdout.reconfigure(encoding='utf-8')

with open(r'D:\MeteorRE\evidence\lxres_top20_all_categories.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

keywords = [
    '阿一修改宝典', '魔尊修改宝典', '幻风修改宝典', '流星修改宝典',
    '个人地图制作心得', '地图制作教程', '新动作制作教程', 'mc修改全教程',
    '大刀极限连招', '扫地', '轻功'
]

matches = []
for cat, d in data.items():
    for item in d['top_20_hot'] + d['top_20_score']:
        for kw in keywords:
            if kw in item['title']:
                if not any(m['url'] == item['url'] for m in matches):
                    matches.append(item)

print(f"Total matching manuals found: {len(matches)}")
for m in matches:
    print(f"[{m['title']}] ({m['author']}) -> {m['url']}")
