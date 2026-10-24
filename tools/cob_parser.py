#!/usr/bin/env python3
"""
cob_parser.py - Binary parser for Meteor 2002 COL V1.0 scene collision files
Reconstructed from SceneWorld collision loader (0x00562D00) and Sector Raycast (0x005644F0).

Format Structure:
  Header:
    Magic: 'COL V1.0\x00\x00' (10 bytes)
    grid_dim_x: uint32 (e.g. 26)
    grid_dim_y: uint32 (e.g. 12)
    grid_dim_z: uint32 (e.g. 7)
    total_sectors: uint32 (grid_dim_x * grid_dim_y * grid_dim_z = 2184)
    cell_size_x: float32 (100.0)
    cell_size_y: float32 (100.0)
    cell_size_z: float32 (100.0)
    grid_min_x: float32 (World bounding min X)
    grid_min_y: float32 (World bounding min Y)
    grid_min_z: float32 (World bounding min Z)
    grid_max_x: float32
    grid_max_y: float32
    grid_max_z: float32
"""

import struct
import os
import sys
import json

class CobParser:
    def __init__(self, filepath):
        self.filepath = filepath
        with open(filepath, 'rb') as f:
            self.data = f.read()
        self.offset = 0

    def parse(self):
        magic = self.data[:10]
        if not magic.startswith(b'COL V1.0'):
            raise ValueError(f"Invalid COB magic: {magic}")
        self.offset = 10

        self.grid_x, self.grid_y, self.grid_z, self.total_sectors = struct.unpack('<IIII', self.data[self.offset:self.offset+16])
        self.offset += 16

        self.cell_x, self.cell_y, self.cell_z = struct.unpack('<fff', self.data[self.offset:self.offset+12])
        self.offset += 12

        self.min_x, self.min_y, self.min_z = struct.unpack('<fff', self.data[self.offset:self.offset+12])
        self.offset += 12

        self.max_x, self.max_y, self.max_z = struct.unpack('<fff', self.data[self.offset:self.offset+12])
        self.offset += 12

        info = {
            "magic": magic.decode('ascii', errors='ignore').strip('\x00'),
            "grid_dimensions": [self.grid_x, self.grid_y, self.grid_z],
            "total_sectors": self.total_sectors,
            "cell_size": [self.cell_x, self.cell_y, self.cell_z],
            "world_min": [self.min_x, self.min_y, self.min_z],
            "world_max": [self.max_x, self.max_y, self.max_z],
            "file_size": len(self.data)
        }
        return info

def main():
    sn01_cob = r"C:\Program Files (x86)\Meteor\sn01\sn01.cob"
    if not os.path.exists(sn01_cob):
        print(f"[-] File not found: {sn01_cob}")
        sys.exit(1)

    parser = CobParser(sn01_cob)
    info = parser.parse()
    
    print("[+] Successfully parsed sn01.cob:")
    for k, v in info.items():
        print(f"    {k}: {v}")

    out_dir = r"D:\MeteorRE\extracted_assets"
    os.makedirs(out_dir, exist_ok=True)
    out_json = os.path.join(out_dir, "sn01_cob_header.json")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump(info, f, indent=2)
    print(f"[+] Wrote collision metadata to {out_json}")

if __name__ == "__main__":
    main()
