# -*- coding: utf-8 -*-
import os, re, sys

sys.stdout.reconfigure(encoding='utf-8')

docs_dir = r'D:\MeteorRE\docs'
results = {}

for f in sorted(os.listdir(docs_dir)):
    if f.endswith('.md'):
        path = os.path.join(docs_dir, f)
        with open(path, 'r', encoding='utf-8') as fp:
            text = fp.read()
        
        q_marks = len(re.findall(r'❓', text))
        todos = len(re.findall(r'TODO|待办|待定|尚未|未证实|未指认|存疑', text, re.I))
        results[f] = {'q': q_marks, 'todo': todos, 'lines': len(text.splitlines())}

print("=== DOCS INVENTORY ===")
for f, info in results.items():
    print(f"{f:40s} | Lines: {info['lines']:5d} | QuestionMarks: {info['q']:2d} | PendingWords: {info['todo']:3d}")

print("\n=== EXACT OPEN ITEMS WITH QUESTION MARKS ===")
for f in sorted(os.listdir(docs_dir)):
    if f.endswith('.md'):
        path = os.path.join(docs_dir, f)
        with open(path, 'r', encoding='utf-8') as fp:
            for i, line in enumerate(fp, 1):
                if '❓' in line:
                    print(f"{f}:{i} -> {line.strip()}")
