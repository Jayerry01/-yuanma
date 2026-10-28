# -*- coding: utf-8 -*-
import urllib.request
import re
import sys
import json

sys.stdout.reconfigure(encoding='utf-8')

url = 'https://www.lxres.com/'
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'}
req = urllib.request.Request(url, headers=headers)
try:
    with urllib.request.urlopen(req, timeout=10) as resp:
        html = resp.read().decode('utf-8', errors='ignore')
    print('Fetched index length:', len(html))
    
    # Save raw html for analysis
    with open(r'D:\MeteorRE\evidence\lxres_index.html', 'w', encoding='utf-8') as f:
        f.write(html)
        
    # Find categories, channels, top posts
    links = re.findall(r'<a\s+[^>]*href=["\']([^"\']+)["\'][^>]*>(.*?)</a>', html, re.DOTALL)
    seen = set()
    cleaned = []
    for href, text in links:
        t = re.sub(r'<[^>]+>', '', text).strip()
        if t and href not in seen and not href.startswith('javascript'):
            seen.add(href)
            cleaned.append((t, href))
            
    print(f"Total unique links found: {len(cleaned)}")
    for t, h in cleaned[:50]:
        print(f"{t} -> {h}")
except Exception as e:
    print('Error:', e)
