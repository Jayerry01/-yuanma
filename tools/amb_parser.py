#!/usr/bin/env python3
"""
amb_parser.py - Binary parser for Meteor 2002 character.amb (BANIM) format
Reconstructed directly from FUN_00574460 in Meteor.exe

Header layout:
  Magic: 'BANIM' (5 bytes)
  num_bones: uint32 (e.g. 30)
  dummy_count: uint32 (e.g. 6)
  total_frames: uint32 (e.g. 17061)
  frame_rate: uint32 -> float (e.g. 30.0)

Per frame layout:
  For each frame:
    delimiter: int32 (must be -1 / 0xFFFFFFFF)
    frame_id: int32
    Bone 0: Vector3 (12 bytes) + Quaternion (16 bytes) = 28 bytes (Root Motion!)
    Bones 1..N-1: Quaternion (16 bytes each)
    Dummies 0..M-1: Vector3 (12 bytes) + Quaternion (16 bytes) + extra (8 bytes) = 36 bytes each
"""

import struct
import os
import sys
import json

AMB_PATH = r"C:\Program Files (x86)\Meteor\Common\character.amb"

class AmbParser:
    def __init__(self, filepath):
        self.filepath = filepath
        with open(filepath, 'rb') as f:
            self.data = f.read()
        self.offset = 0

    def read_bytes(self, n):
        res = self.data[self.offset : self.offset + n]
        self.offset += n
        return res

    def read_u32(self):
        val = struct.unpack('<I', self.data[self.offset : self.offset + 4])[0]
        self.offset += 4
        return val

    def read_i32(self):
        val = struct.unpack('<i', self.data[self.offset : self.offset + 4])[0]
        self.offset += 4
        return val

    def read_f32(self):
        val = struct.unpack('<f', self.data[self.offset : self.offset + 4])[0]
        self.offset += 4
        return val

    def parse_header(self):
        magic = self.read_bytes(5)
        if magic != b'BANIM':
            raise ValueError(f"Invalid AMB magic: {magic}")
        self.num_bones = self.read_u32()
        self.dummy_count = self.read_u32()
        self.total_frames = self.read_u32()
        self.frame_rate = float(self.read_u32())
        print(f"[*] BANIM Header:")
        print(f"    - Bones: {self.num_bones}")
        print(f"    - Dummies: {self.dummy_count}")
        print(f"    - Total Frames: {self.total_frames}")
        print(f"    - Frame Rate: {self.frame_rate} fps")

    def parse_root_motion(self, max_frames=None):
        if max_frames is None or max_frames > self.total_frames:
            max_frames = self.total_frames

        root_motion = []
        frame_size = 8 + 28 + (self.num_bones - 1) * 16 + self.dummy_count * 36

        for f in range(max_frames):
            delim = struct.unpack('<i', self.data[self.offset : self.offset + 4])[0]
            if delim != -1:
                # Synchronize or verify
                pass
            frame_idx = struct.unpack('<i', self.data[self.offset + 4 : self.offset + 8])[0]
            
            # Bone 0 (Root Bone) starts at offset + 8
            # Pos: 3 floats (x, y, z)
            pos_x, pos_y, pos_z = struct.unpack('<fff', self.data[self.offset + 8 : self.offset + 20])
            # Rot: 4 floats (x, y, z, w)
            rot_x, rot_y, rot_z, rot_w = struct.unpack('<ffff', self.data[self.offset + 20 : self.offset + 36])

            root_motion.append({
                "frame": f,
                "frame_idx": frame_idx,
                "pos": [pos_x, pos_y, pos_z],
                "rot": [rot_x, rot_y, rot_z, rot_w]
            })

            self.offset += frame_size

        return root_motion

def main():
    if not os.path.exists(AMB_PATH):
        print(f"[-] File not found: {AMB_PATH}")
        sys.exit(1)

    parser = AmbParser(AMB_PATH)
    parser.parse_header()
    
    print("[*] Extracting sample Root Motion frames (0..100)...")
    samples = parser.parse_root_motion(max_frames=100)
    
    out_dir = r"D:\MeteorRE\extracted_assets"
    os.makedirs(out_dir, exist_ok=True)
    out_json = os.path.join(out_dir, "character_amb_sample_root_motion.json")
    with open(out_json, "w", encoding="utf-8") as f:
        json.dump({
            "num_bones": parser.num_bones,
            "dummy_count": parser.dummy_count,
            "total_frames": parser.total_frames,
            "frame_rate": parser.frame_rate,
            "sample_frames": samples
        }, f, indent=2)
    print(f"[+] Sample Root Motion successfully extracted to {out_json}")

if __name__ == "__main__":
    main()
