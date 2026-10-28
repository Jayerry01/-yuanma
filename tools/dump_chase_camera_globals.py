# -*- coding: utf-8 -*-
import sys, capstone, struct

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

def read_f32(va):
    rva = va - 0x400000
    if 0 <= rva < len(exe_data) - 4:
        return struct.unpack_from('<f', exe_data, rva)[0]
    return None

def read_f64(va):
    rva = va - 0x400000
    if 0 <= rva < len(exe_data) - 8:
        return struct.unpack_from('<d', exe_data, rva)[0]
    return None

md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
md.detail = True
code = exe_data[0x004F5FA0-0x400000 : 0x004F5FA0-0x400000+3248]

print("Global memory accesses in ChaseCamera::Update (0x004F5FA0):")
for insn in md.disasm(code, 0x004F5FA0):
    for op in insn.operands:
        if op.type == capstone.x86.X86_OP_MEM:
            disp = op.mem.disp
            if 0x005A0000 <= disp <= 0x005E0000 and op.mem.base == 0 and op.mem.index == 0:
                f32_val = read_f32(disp)
                f64_val = read_f64(disp)
                print(f"0x{insn.address:08X}: {insn.mnemonic:6s} {insn.op_str:<32s} ; disp=0x{disp:08X} f32={f32_val} f64={f64_val}")
