# -*- coding: utf-8 -*-
import urllib.request
import re
import sys
from bs4 import BeautifulSoup

sys.stdout.reconfigure(encoding='utf-8')

categories = [
    ("主客户端", "https://www.lxres.com/ZhuKeHuDuan/"),
    ("补丁工具", "https://www.lxres.com/BuDingGongJu/"),
    ("单机任务", "https://www.lxres.com/DanJiRenWu/"),
    ("地图下载", "https://www.lxres.com/DiTuXiaZai/"),
    ("人物武器", "https://www.lxres.com/RenWuWuQi/"),
    ("主题光影", "https://www.lxres.com/ZhuTiGuangYing/"),
    ("资料教程", "https://www.lxres.com/ZiLiaoJiaoCheng/"),
]

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'}

def fetch(url):
    try:
        req = urllib.request.Request(url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            return resp.read().decode('utf-8', errors='ignore')
    except Exception as e:
        print(f"Error fetching {url}: {e}")
        return ""

# Analyze specific tools and plugins
tool_urls = [
    ("皎月联机插件", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2228.html"),
    ("流星MOD管理工具", "https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4788.html"),
    ("DE官方对战平台", "https://www.lxres.com/BuDingGongJu/ShiYongGongJu/4815.html"),
]

for name, u in tool_urls:
    html = fetch(u)
    print(f"\n=== Tool: {name} ({u}) ===")
    soup = BeautifulSoup(html, 'html.parser')
    content = soup.find('div', class_='content') or soup.find('div', id='content') or soup.find('article')
    if content:
        text = content.get_text('\n', strip=True)
        print(text[:1000])
    else:
        # Fallback to regex text
        print("Raw snippet:")
        print(re.sub(r'<[^>]+>', ' ', html)[:1000])

