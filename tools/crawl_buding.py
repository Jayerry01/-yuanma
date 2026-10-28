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

# Crawl BuDingGongJu (Tools & Patches) listing
url = "https://www.lxres.com/BuDingGongJu/"
html = fetch(url)
soup = BeautifulSoup(html, 'html.parser')

print("=== Patches & Tools Top Items ===")
items = []
for a in soup.find_all('a', href=True):
    href = a['href']
    title = a.get_text(strip=True)
    if '/BuDingGongJu/' in href and href.endswith('.html') and title:
        items.append((title, href))

# Deduplicate
seen = set()
for title, href in items:
    if href not in seen:
        seen.add(href)
        print(f"{title} | https://www.lxres.com{href}")

