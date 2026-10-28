# -*- coding: utf-8 -*-
import sys, struct, capstone

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def read_u32(va):
    rva = va - 0x400000
    return struct.unpack_from('<I', exe_data, rva)[0]

def get_str(va):
    rva = va - 0x400000
    end = exe_data.find(b'\x00', rva)
    return exe_data[rva:end].decode('ascii', errors='ignore')

print("=== 1. Table around 0x005B0214 ===")
for i in range(-5, 10):
    va = 0x005B0214 + i*4
    ptr = read_u32(va)
    s = get_str(ptr) if 0x400000 <= ptr < 0x600000 else ''
    print(f"VA 0x{va:08X}: ptr=0x{ptr:08X} -> \"{s}\"")

print("\n=== 2. Callers of FUN_004c06a0 (Block caller) ===")
target = 0x004C06A0
for va in range(0x00401000, 0x005A72BD):
    rva = va - 0x400000
    if exe_data[rva] == 0xE8:
        rel = struct.unpack_from('<i', exe_data, rva + 1)[0]
        if va + 5 + rel == target:
            print(f"Call to 0x{target:08X} from 0x{va:08X}")
    elif exe_data[rva] == 0xE9:
        rel = struct.unpack_from('<i', exe_data, rva + 1)[0]
        if va + 5 + rel == target:
            print(f"Jmp to 0x{target:08X} from 0x{va:08X}")

print("\n=== 3. Inspecting [0x5D1784] (Property sync hook) ===")
# Search references to 0x5D1784
for va in range(0x00401000, 0x005A72BD):
    rva = va - 0x400000
    ptr = struct.unpack_from('<I', exe_data, rva)[0]
    if ptr == 0x005D1784:
        print(f"Reference to 0x005D1784 at 0x{va:08X}")
