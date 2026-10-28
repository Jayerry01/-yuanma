# -*- coding: utf-8 -*-
import sys, capstone

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def get_str(va):
    rva = va - 0x400000
    if rva < 0 or rva >= len(exe_data):
        return f"<0x{va:X}>"
    end = exe_data.find(b'\x00', rva)
    if end == -1:
        end = rva + 32
    return exe_data[rva:end].decode('ascii', errors='ignore')

def get_code(va, size):
    rva = va - 0x400000
    return exe_data[rva:rva+size]

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
code = get_code(0x00504BE0, 0x00504F60 - 0x00504BE0)

with open(r'D:\MeteorRE\evidence\disasm_504be0.txt', 'w', encoding='utf-8') as f_out:
    for insn in md.disasm(code, 0x00504BE0):
        comment = ""
        for op in insn.op_str.split():
            if op.startswith('0x5c') or op.startswith('0x5d'):
                try:
                    imm = int(op.rstrip(','), 16)
                    s = get_str(imm)
                    comment += f' ; "{s}"'
                except:
                    pass
        f_out.write(f"0x{insn.address:08X}: {insn.mnemonic:8s} {insn.op_str:<30s}{comment}\n")
print("Written disasm_504be0.txt successfully.")
