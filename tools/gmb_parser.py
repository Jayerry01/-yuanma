#!/usr/bin/env python3
"""
gmb_parser.py - Binary parser for Meteor 2002 GMDL V1.00 graphic mesh files
Reconstructed from GModel loader in Meteor.exe.
"""

import struct
import os
import sys
import json

class GmbParser:
    def __init__(self, filepath):
        self.filepath = filepath
        with open(filepath, 'rb') as f:
            self.data = f.read()
        self.offset = 0

    def parse(self):
        magic = self.data[:10]
        if not magic.startswith(b'GMDL V1.0'):
            raise ValueError(f"Invalid GMB magic: {magic}")
        self.offset = 10

        tex_count = struct.unpack('<I', self.data[self.offset:self.offset+4])[0]
        self.offset += 4

        textures = []
        for _ in range(tex_count):
            str_len = struct.unpack('<I', self.data[self.offset:self.offset+4])[0]
            self.offset += 4
            tex_name = self.data[self.offset:self.offset+str_len].decode('ascii', errors='ignore')
            self.offset += str_len
            textures.append(tex_name)

        return {
            "magic": magic.decode('ascii', errors='ignore').strip('\x00'),
            "texture_count": tex_count,
            "textures": textures,
            "data_bytes_remaining": len(self.data) - self.offset,
            "total_size": len(self.data)
        }

def main():
    sn01_gmb = r"C:\Program Files (x86)\Meteor\sn01\sn01.gmb"
    if not os.path.exists(sn01_gmb):
        print(f"[-] File not found: {sn01_gmb}")
        sys.exit(1)

    parser = GmbParser(sn01_gmb)
    info = parser.parse()
    print(f"[+] Successfully parsed sn01.gmb:")
    print(f"    Textures ({info['texture_count']}): {info['textures'][:5]} ...")
    print(f"    Model payload: {info['data_bytes_remaining']} bytes")

    out_dir = r"D:\MeteorRE\extracted_assets"
    os.makedirs(out_dir, exist_ok=True)
    out_json = os.path.join(out_dir, "sn01_gmb_header.json")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(info, f, indent=2)
    print(f"[+] Wrote GMB metadata to {out_json}")

if __name__ == "__main__":
    main()
