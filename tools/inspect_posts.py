# -*- coding: utf-8 -*-
import urllib.request
import re
import sys
from bs4 import BeautifulSoup

sys.stdout.reconfigure(encoding='utf-8')

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'}

def fetch(url):
    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            return resp.read().decode('utf-8', errors='ignore')
    except Exception as e:
        print(f"Error fetching {url}: {e}")
        return ""

def parse_post(url):
    html = fetch(url)
    soup = BeautifulSoup(html, 'html.parser')
    title = soup.find('h1') or soup.find('title')
    title_text = title.get_text(strip=True) if title else "Unknown"
    
    # Try finding the post description/content
    # usually in e-content or info div
    content = ""
    for div in soup.find_all('div'):
        cl = div.get('class', [])
        if any('content' in c or 'text' in c or 'info' in c or 'intro' in c for c in cl):
            t = div.get_text('\n', strip=True)
            if len(t) > len(content) and len(t) < 4000:
                content = t
    if not content:
        content = soup.get_text('\n', strip=True)[:1500]
    return title_text, content

targets = [
    ("皎月联机插件", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2228.html"),
    ("DE官方对战平台", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/4815.html"),
    ("流星血饮版综合补丁(反作弊/防炸)", "https://www.lxres.com/BuDingGongJu/FanGuaBuDing/1287.html"),
    ("流星As脚本引擎2.7.7", "https://www.lxres.com/BuDingGongJu/YouXiZengQiang/2262.html"),
    ("流星MOD管理工具v3.2.0", "https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4788.html"),
    ("四方阵边缘空气墙补丁", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1197.html"),
    ("反作弊综合补丁(招招防秒杀/破防)", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1266.html"),
]

for name, u in targets:
    t, c = parse_post(u)
    print(f"==================================================")
    print(f"Target: {name} ({u})")
    print(f"Title: {t}")
    print(f"Content Sample:\n{c[:800]}\n")
