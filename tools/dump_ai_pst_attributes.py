# -*- coding: utf-8 -*-
import sys, capstone

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
code = get_code(0x005013AC, 0x00501600 - 0x005013AC)

attr_map = []
curr_name = None

for insn in md.disasm(code, 0x005013AC):
    for op in insn.op_str.split():
        if op.startswith('0x5c') or op.startswith('0x5d'):
            try:
                imm = int(op.rstrip(','), 16)
                s = get_str(imm)
                if s and len(s) >= 2:
                    curr_name = s
            except:
                pass
    if 'word ptr [esi +' in insn.op_str or 'dword ptr [esi +' in insn.op_str:
        # found store
        print(f"Attr: {curr_name:<10s} -> Store: {insn.op_str} at 0x{insn.address:08X}")
        attr_map.append((curr_name, insn.op_str))

print("\nTotal attributes mapped:", len(attr_map))
