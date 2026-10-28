# -*- coding: utf-8 -*-
import struct
import sys

sys.stdout.reconfigure(encoding='utf-8')

exe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(exe_path, 'rb') as f:
    data = f.read()

def disasm_func(start_va, length=300):
    raw_start = start_va - 0x400000
    chunk = data[raw_start : raw_start + length]
    print(f"\n==========================================")
    print(f"Disassembly of 0x{start_va:08X} (len: {length})")
    offset = 0
    while offset < len(chunk):
        va = start_va + offset
        b = chunk[offset]
        if b == 0x48:
            print(f"  0x{va:08X}: dec eax")
            offset += 1
        elif b == 0x74:
            tgt = va + 2 + struct.unpack('<b', chunk[offset+1:offset+2])[0]
            print(f"  0x{va:08X}: jz 0x{tgt:08X}")
            offset += 2
        elif b == 0x0F and chunk[offset+1] == 0x85:
            rel = struct.unpack('<i', chunk[offset+2:offset+6])[0]
            tgt = va + 6 + rel
            print(f"  0x{va:08X}: jnz 0x{tgt:08X}")
            offset += 6
        elif b == 0xE8:
            rel = struct.unpack('<i', chunk[offset+1:offset+5])[0]
            tgt = va + 5 + rel
            print(f"  0x{va:08X}: call 0x{tgt:08X}")
            offset += 5
        elif b == 0xFF and chunk[offset+1] == 0x90:
            disp = struct.unpack('<I', chunk[offset+2:offset+6])[0]
            slot = disp // 4
            print(f"  0x{va:08X}: call [eax + 0x{disp:X}] (vtable slot {slot})")
            offset += 6
        elif b == 0xC2:
            imm = struct.unpack('<H', chunk[offset+1:offset+3])[0]
            print(f"  0x{va:08X}: ret 0x{imm:X}")
            offset += 3
        elif b == 0xC3:
            print(f"  0x{va:08X}: ret")
            offset += 1
        else:
            offset += 1

disasm_func(0x004D95D0, 200)
disasm_func(0x004D8CF0, 250)
