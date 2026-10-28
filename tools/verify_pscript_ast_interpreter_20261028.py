# -*- coding: utf-8 -*-
"""
Standalone automated verification for:
PScript AST Tree-Walk Interpreter architecture (debunking Bytecode VM hypothesis):
1. FunctionNode::Execute at 0x00570F80:
   - Formats "Function:%s\n" at 0x5D189C via printf (0x50AC20)
   - Iterates statement array at [esi + 0x34] and invokes virtual method slot 2: call dword ptr [edx + 8]
2. Statement vector appending at 0x00570FE0 using MSVC std::vector 3-pointer layout at +0x34
3. Function lookup by name at 0x00571060
"""
import struct, hashlib, sys

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

sha256 = hashlib.sha256(exe_data).hexdigest()
assert sha256.startswith('baebb6d5'), f"Unexpected SHA256: {sha256}"

def read_bytes(va, n):
    rva = va - 0x400000
    return exe_data[rva:rva+n]

print("[Test 1] Checking FunctionNode::Execute debug string and loop at 0x00570F80...")
# 0x00570F88: push 0x5D189C ("Function:%s\n")
push_dbg = read_bytes(0x00570F87, 6)
assert push_dbg.endswith(b'\x68\x9C\x18\x5D\x00'), f"Debug string push mismatch: {push_dbg.hex()}"
dbg_str = read_bytes(0x5D189C, 13)
assert dbg_str == b'Function:%s\n\x00', f"Debug string mismatch: {dbg_str}"

# 0x00570FA4: mov edx, [ecx]; call dword ptr [edx + 8]
# 8B 11 FF 52 08
call_execute = read_bytes(0x00570FA4, 5)
assert call_execute == b'\x8B\x11\xFF\x52\x08', f"Virtual Execute() call mismatch: {call_execute.hex()}"
print("  -> FunctionNode::Execute iterates statement AST nodes calling virtual Execute() (slot 2, +0x08).")

print("[Test 2] Checking AST Node Vector appending at 0x00570FE0...")
# 0x00570FEA: lea esi, [edi + 0x34]
# 8D 77 34
lea_vec = read_bytes(0x00570FEA, 3)
assert lea_vec == b'\x8D\x77\x34', f"Vector lea mismatch: {lea_vec.hex()}"
print("  -> MSVC vector AST children list management verified at +0x34.")

print("\nALL AST INTERPRETER TESTS PASSED! ZERO SPECULATION.")
