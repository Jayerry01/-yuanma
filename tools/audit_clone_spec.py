# -*- coding: utf-8 -*-
import re
import os
import glob
import sys

sys.stdout.reconfigure(encoding='utf-8')

# 1. Load all docs
docs_dir = r'D:\MeteorRE\docs'
docs_files = glob.glob(os.path.join(docs_dir, '*.*'))
docs_content = {}
for df in docs_files:
    fname = os.path.basename(df)
    with open(df, 'r', encoding='utf-8', errors='ignore') as f:
        docs_content[fname] = f.read()

all_docs = '\n'.join(docs_content.values())
docs_hex = set(re.findall(r'0x[0-9a-fA-F]{6,8}', all_docs.lower()))

# 2. Parse CLONE_SPEC.md
spec_path = r'D:\MeteorRE\CLONE_SPEC.md'
with open(spec_path, 'r', encoding='utf-8', errors='ignore') as f:
    spec_lines = f.readlines()

sections = []
current_sec = None
current_body = []
start_line = 1

for idx, line in enumerate(spec_lines, 1):
    m = re.match(r'^(#{1,3})\s+(.*)', line)
    if m:
        level, title = m.groups()
        if current_sec:
            sections.append({
                'level': current_sec[0],
                'title': current_sec[1],
                'start_line': current_sec[2],
                'end_line': idx - 1,
                'body': ''.join(current_body)
            })
        current_sec = (level, title.strip(), idx)
        current_body = []
    else:
        current_body.append(line)

if current_sec:
    sections.append({
        'level': current_sec[0],
        'title': current_sec[1],
        'start_line': current_sec[2],
        'end_line': len(spec_lines),
        'body': ''.join(current_body)
    })

print(f"Total sections: {len(sections)}")

# Analyze each section
for i, s in enumerate(sections):
    addrs = set(re.findall(r'0x[0-9a-fA-F]{6,8}', s['body'].lower()))
    in_docs = addrs.intersection(docs_hex)
    not_in_docs = addrs.difference(docs_hex)
    has_unity = bool(re.search(r'Unity|C#|\.cs|MeteorRebuild', s['body'], re.IGNORECASE))
    
    print(f"\n[{i:02d}] {s['level']} {s['title']} (L{s['start_line']}-L{s['end_line']})")
    print(f"     Addrs total: {len(addrs)} | In docs: {len(in_docs)} | Not in docs: {len(not_in_docs)} | Unity/C#: {has_unity}")
    if not_in_docs:
        print(f"     Not in docs sample: {sorted(list(not_in_docs))[:8]}")
