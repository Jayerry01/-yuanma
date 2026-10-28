# -*- coding: utf-8 -*-
import sys, struct, capstone

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def get_str(va):
    rva = va - 0x400000
    if 0 <= rva < len(exe_data):
        end = exe_data.find(b'\x00', rva)
        if end != -1:
            return exe_data[rva:end].decode('ascii', errors='ignore')
    return ''

print("=== Strings in 0x00570000 - 0x00573500 ===")
for va in range(0x00570000, 0x00573500):
    rva = va - 0x400000
    ptr = struct.unpack_from('<I', exe_data, rva)[0]
    if 0x005C0000 <= ptr <= 0x005D5000:
        s = get_str(ptr)
        if len(s) >= 3 and any(c.isalpha() for c in s):
            print(f"0x{va:08X} -> \"{s}\"")
