# -*- coding: utf-8 -*-
import urllib.request
import time
import json
import re
import sys
from bs4 import BeautifulSoup

sys.stdout.reconfigure(encoding='utf-8')

HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
    'Referer': 'https://www.lxres.com/',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8'
}

CATEGORIES = [
    ('主客户端', '001', '/ZhuKeHuDuan/'),
    ('单机任务', '002', '/DanJiRenWu/'),
    ('补丁工具', '003', '/BuDingGongJu/'),
    ('地图下载', '004', '/DiTuXiaZai/'),
    ('人物武器', '005', '/RenWuWuQi/'),
    ('主题光影', '006', '/ZhuTiGuangYing/'),
    ('资料教程', '008', '/ZiLiaoJiaoCheng/'),
]

def fetch_page(url, retries=3):
    for i in range(retries):
        try:
            time.sleep(0.4)
            req = urllib.request.Request(url, headers=HEADERS)
            with urllib.request.urlopen(req, timeout=12) as resp:
                return resp.read().decode('utf-8', errors='ignore')
        except Exception as e:
            print(f"[Retry {i+1}/{retries}] Error fetching {url}: {e}")
            time.sleep(1.0)
    return ""

def parse_items(html):
    if not html:
        return []
    soup = BeautifulSoup(html, 'html.parser')
    ul = soup.find('ul', class_='librarylist')
    if not ul:
        return []
    
    results = []
    for li in ul.find_all('li'):
        main_a = [a for a in li.find_all('a') if '/writer/' not in a.get('href', '')]
        if not main_a:
            continue
        title = main_a[0].get_text(strip=True)
        href = main_a[0].get('href', '')
        
        writer_a = li.find('a', href=lambda h: h and '/writer/' in h)
        writer = writer_a.get_text(strip=True) if writer_a else '未知'
        
        s_div = li.find('div', class_='s')
        s_text = s_div.get_text(' ', strip=True) if s_div else ''
        
        # Extract size and date from s_text
        size_m = re.search(r'大小：([^\s]+)', s_text)
        size = size_m.group(1) if size_m else '未知'
        
        date_m = re.search(r'更新：([0-9\-]+(?:\s+[0-9:]+)?)', s_text)
        date = date_m.group(1) if date_m else '未知'
        
        em = s_div.find('em') if s_div else None
        star_cls = em.get('class', [''])[0] if em else ''
        star_num = star_cls.replace('lstar', '') if star_cls else '0'
        
        u_div = li.find('div', class_='u')
        desc = u_div.get_text(strip=True) if u_div else ''
        
        results.append({
            'title': title,
            'url': f"https://www.lxres.com{href}" if href.startswith('/') else href,
            'author': writer,
            'size': size,
            'rating_star': star_num,
            'update_date': date,
            'description': desc
        })
    return results

def crawl_category_ranking(cat_name, cat_code):
    print(f"\n==================================================")
    print(f"Crawling Category: {cat_name} (Code: {cat_code})")
    
    # 1. Top 20 热门 (/h/00X_1.html, /h/00X_2.html)
    hot_items = []
    for page in [1, 2]:
        url = f"https://www.lxres.com/h/{cat_code}_{page}.html"
        html = fetch_page(url)
        items = parse_items(html)
        hot_items.extend(items)
        print(f"  [热门] Page {page}: fetched {len(items)} items")
    hot_items = hot_items[:20]
    
    # 2. Top 20 评分 (/s/00X_1.html, /s/00X_2.html)
    score_items = []
    for page in [1, 2]:
        url = f"https://www.lxres.com/s/{cat_code}_{page}.html"
        html = fetch_page(url)
        items = parse_items(html)
        score_items.extend(items)
        print(f"  [评分] Page {page}: fetched {len(items)} items")
    score_items = score_items[:20]
    
    return {
        'category': cat_name,
        'code': cat_code,
        'top_20_hot': hot_items,
        'top_20_score': score_items
    }

if __name__ == '__main__':
    all_data = {}
    for name, code, path in CATEGORIES:
        data = crawl_category_ranking(name, code)
        all_data[name] = data
        
    out_json = r'D:\MeteorRE\evidence\lxres_top20_all_categories.json'
    with open(out_json, 'w', encoding='utf-8') as f:
        json.dump(all_data, f, ensure_ascii=False, indent=2)
    print(f"\nSaved all crawled data to {out_json}")
