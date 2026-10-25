#!/usr/bin/env python3
"""
Meteor.exe Byte-to-Capstone Instruction Verification Tool
Verifies exact virtual addresses, opcodes, and disassembly from Meteor.exe.
"""
import sys
import json
import struct
from pathlib import Path
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parent.parent
PE_JSON = ROOT / "_pe.json"
EXE_BIN = ROOT / "Meteor.exe"

def load_pe():
    with open(PE_JSON, "r", encoding="utf-8") as f:
        pe_info = json.load(f)
    with open(EXE_BIN, "rb") as f:
        exe_bytes = f.read()
    return pe_info, exe_bytes

def va_to_offset(va, pe_info):
    ib = pe_info["ib"]
    rva = va - ib
    for s in pe_info["secs"]:
        if s["va"] <= rva < s["va"] + s["vs"]:
            return rva - s["va"] + s["pr"]
    return None

def verify_address(va, count=1):
    pe_info, exe_bytes = load_pe()
    off = va_to_offset(va, pe_info)
    if off is None:
        print(f"[ERROR] VA 0x{va:08X} is outside mapped PE sections.")
        return False

    chunk = exe_bytes[off : off + 32 * count]
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    instructions = list(md.disasm(chunk, va))
    
    if not instructions:
        print(f"[ERROR] VA 0x{va:08X} failed to disassemble (invalid opcode).")
        return False

    print(f"Disassembly at VA 0x{va:08X} (File Offset 0x{off:06X}):")
    for i, insn in enumerate(instructions[:count]):
        hex_bytes = " ".join(f"{b:02X}" for b in insn.bytes)
        print(f"  [{i}] 0x{insn.address:08X}: {hex_bytes:<16}  {insn.mnemonic:<8} {insn.op_str}")
    return True

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python verify_insn.py <VA_HEX> [COUNT]")
        print("Example: python verify_insn.py 0x004CB2F7 3")
        sys.exit(1)

    target_va = int(sys.argv[1], 16)
    insn_count = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    success = verify_address(target_va, insn_count)
    sys.exit(0 if success else 1)
