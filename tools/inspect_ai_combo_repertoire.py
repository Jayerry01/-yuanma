# -*- coding: utf-8 -*-
import sys, capstone, struct

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def get_code(va, size):
    rva = va - 0x400000
    return exe_data[rva:rva+size]

def get_str(va):
    rva = va - 0x400000
    end = exe_data.find(b'\x00', rva)
    return exe_data[rva:end].decode('ascii', errors='ignore')

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
code = get_code(0x004FF200, 0x005005A3 - 0x004FF200)

print("Scanning weapon repertoire entries in FUN_004ff200...")
current_weapon = None
combos = []

for insn in md.disasm(code, 0x004FF200):
    for op in insn.op_str.split():
        if op.startswith('0x5ca1') or op.startswith('0x5ca2'):
            try:
                imm = int(op.rstrip(','), 16)
                s = get_str(imm)
                if s:
                    combos.append((insn.address, s))
                    print(f"0x{insn.address:08X}: Combo String \"{s}\" (ptr 0x{imm:08X})")
            except:
                pass

print(f"\nTotal combo string registrations in FUN_004ff200: {len(combos)}")
