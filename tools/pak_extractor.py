#!/usr/bin/env python3
"""
pak_extractor.py - Complete PAK archive unpacker for Meteor 2002
Target: C:\\Program Files (x86)\\Meteor\\*.pak
Format: Standard PKZIP container archives.
"""

import os
import sys
import glob
import zipfile

METEOR_DIR = r"C:\Program Files (x86)\Meteor"
OUTPUT_DIR = r"D:\MeteorRE\extracted_assets"

def extract_all_paks():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    pak_files = glob.glob(os.path.join(METEOR_DIR, "*.pak"))
    print(f"[*] Found {len(pak_files)} .pak files in {METEOR_DIR}")
    
    total_files = 0
    total_bytes = 0
    manifest = []

    for pak_path in sorted(pak_files):
        pak_name = os.path.basename(pak_path)
        print(f"[*] Processing {pak_name}...")
        try:
            with zipfile.ZipFile(pak_path, 'r') as zf:
                file_list = zf.namelist()
                print(f"    -> Contains {len(file_list)} files")
                for info in zf.infolist():
                    out_path = os.path.join(OUTPUT_DIR, pak_name.replace(".pak", ""), info.filename)
                    os.makedirs(os.path.dirname(out_path), exist_ok=True)
                    zf.extract(info, os.path.join(OUTPUT_DIR, pak_name.replace(".pak", "")))
                    total_files += 1
                    total_bytes += info.file_size
                    manifest.append({
                        "pak": pak_name,
                        "file": info.filename,
                        "size": info.file_size,
                        "compressed": info.compress_size
                    })
        except Exception as e:
            print(f"[-] Error extracting {pak_name}: {e}")

    print(f"\n[+] Successfully extracted {total_files} files ({total_bytes / (1024*1024):.2f} MB uncompressed)")
    
    import json
    with open(os.path.join(OUTPUT_DIR, "pak_manifest.json"), "w", encoding="utf-8") as f:
        json.dump(manifest, f, indent=2, ensure_ascii=False)
    print(f"[+] Wrote manifest to {os.path.join(OUTPUT_DIR, 'pak_manifest.json')}")

if __name__ == "__main__":
    extract_all_paks()
