#!/usr/bin/env python3
"""
res_parser.py - Binary parser for Meteor 2002 Meteor.res (MTTM) resource index
Reconstructed from 0x004D2898 in Meteor.exe.
"""

import struct
import os
import sys
import json
import re

RES_PATH = r"C:\Program Files (x86)\Meteor\Meteor.res"

class ResParser:
    def __init__(self, filepath):
        self.filepath = filepath
        with open(filepath, 'rb') as f:
            self.data = f.read()

    def parse(self):
        magic = self.data[:38]
        if not magic.startswith(b'MTTM'):
            raise ValueError(f"Invalid RES magic: {magic}")

        # Scan all weapon / model identifiers in Meteor.res
        pattern = re.compile(b'(W[0-9]_[0-9][a-z]?|[a-zA-Z0-9_]{3,})')
        matches = [m.group(0).decode('ascii', errors='ignore') for m in pattern.finditer(self.data)]
        
        # Categorize resources
        weapons = [m for m in matches if re.match(r'^W[0-9]_[0-9]', m)]
        items = list(set([m for m in matches if m not in ['MTTM', 'Meteor', 'Resource', 'file', 'Version']]))

        return {
            "magic": magic.decode('ascii', errors='ignore').strip('\x00'),
            "file_size": len(self.data),
            "total_identifiers": len(matches),
            "unique_items": len(items),
            "weapons_indexed": sorted(list(set(weapons))),
            "all_sample_items": sorted(items)[:50]
        }

def main():
    if not os.path.exists(RES_PATH):
        print(f"[-] File not found: {RES_PATH}")
        sys.exit(1)

    parser = ResParser(RES_PATH)
    info = parser.parse()
    print(f"[+] Successfully parsed Meteor.res:")
    print(f"    Total identifiers: {info['total_identifiers']}")
    print(f"    Indexed weapon models: {len(info['weapons_indexed'])} ({info['weapons_indexed'][:10]}...)")

    out_dir = r"D:\MeteorRE\extracted_assets"
    os.makedirs(out_dir, exist_ok=True)
    out_json = os.path.join(out_dir, "meteor_res_catalog.json")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(info, f, indent=2)
    print(f"[+] Wrote resource catalog to {out_json}")

if __name__ == "__main__":
    main()
