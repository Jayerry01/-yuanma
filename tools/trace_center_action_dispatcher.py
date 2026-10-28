# -*- coding: utf-8 -*-
"""
Trace and reverse engineer the Center Action Dispatcher in Meteor.exe around 0x00504B80 - 0x00505100.
Extracts:
1. Target action name strings (VA and string text)
2. Branch conditions and checks
3. Downstream target calls (vtable slot or function VA)
4. Parameter registers and structures
"""
import sys, struct, capstone

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def get_str(va):
    rva = va - 0x400000
    if rva < 0 or rva >= len(exe_data):
        return f"<invalid VA 0x{va:X}>"
    end = exe_data.find(b'\x00', rva)
    if end == -1:
        end = rva + 32
    return exe_data[rva:end].decode('ascii', errors='ignore')

def get_code(va, size):
    rva = va - 0x400000
    return exe_data[rva:rva+size]

print("=== Scanning 0x00504B00 - 0x00505100 ===")
code = get_code(0x00504B80, 0x00505080 - 0x00504B80)
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True

current_str = None
branches = []

for insn in md.disasm(code, 0x00504B80):
    # Check if instruction loads an immediate that points into .rdata (0x5C0000 - 0x5D5000)
    for op in insn.operands:
        if op.type == capstone.x86.X86_OP_IMM:
            imm = op.imm
            if 0x005C0000 <= imm <= 0x005D5000:
                s = get_str(imm)
                if s and len(s) >= 2:
                    current_str = (imm, s)
                    print(f"\n[0x{insn.address:08X}] String ref: 0x{imm:08X} -> \"{s}\"")
    
    # Print call or vtable call
    if insn.mnemonic == 'call':
        print(f"  0x{insn.address:08X}: {insn.mnemonic:8s} {insn.op_str}")
    elif insn.mnemonic in ['jmp', 'je', 'jne', 'ja', 'jb']:
        # print jump
        pass
