# -*- coding: utf-8 -*-
import urllib.request
import re
import sys
from bs4 import BeautifulSoup

sys.stdout.reconfigure(encoding='utf-8')

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
    'Referer': 'https://www.lxres.com/'
}

test_urls = [
    ("阿一修改宝典V0.99", "https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/39.html"),
    ("魔尊修改宝典V1.1", "https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/138.html"),
    ("个人地图制作心得2.0.1", "https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1931.html"),
    ("mc修改全教程", "https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/2423.html"),
    ("流星修改宝典-Final", "https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1203.html"),
]

for title, u in test_urls:
    print(f"\n==================================================")
    print(f"Checking: {title} ({u})")
    req = urllib.request.Request(u, headers=headers)
    try:
        html = urllib.request.urlopen(req, timeout=10).read().decode('utf-8', errors='ignore')
        soup = BeautifulSoup(html, 'html.parser')
        
        # Look for download links
        down_links = []
        for a in soup.find_all('a'):
            h = a.get('href', '')
            t = a.get_text(strip=True)
            if any(k in h.lower() for k in ['down', 'pan.baidu', 'lanzou', '123pan', 'quark', 'drive', 'file', '.rar', '.zip', '.7z', '.exe', '.pdf', '.chm', '.doc']) or '下载' in t:
                down_links.append((t, h))
        print("Download links found:")
        for t, h in down_links:
            print(f"  {t} -> {h}")
            
        # Also let's inspect the article text content
        content = ""
        for div in soup.find_all(['div', 'article', 'section']):
            cl = ' '.join(div.get('class', []))
            id_ = div.get('id', '')
            if any(k in cl.lower() or k in id_.lower() for k in ['content', 'text', 'intro', 'article']):
                text = div.get_text('\n', strip=True)
                if len(text) > len(content):
                    content = text
        print(f"Content length: {len(content)}")
        print(f"Content sample:\n{content[:500]}\n")
    except Exception as e:
        print(f"Error: {e}")
