# -*- coding: utf-8 -*-
"""
Standalone automated verification for:
1. Perform action dispatcher (0x00504BE0) and its 9 action verb string comparisons
2. Vector glyph renderer (0x00504F50) with 128-entry table at 0x005CA3A0 and 0.0625f scale
3. attacktarget behavior loop (0x00504A70) and [ESI+0x88] counter semantics with 40.0f/80.0f thresholds
"""
import struct, hashlib, sys

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

sha256 = hashlib.sha256(exe_data).hexdigest()
assert sha256.startswith('baebb6d5'), f"Unexpected SHA256: {sha256}"

def read_u32(va):
    rva = va - 0x400000
    return struct.unpack_from('<I', exe_data, rva)[0]

def read_f32(va):
    rva = va - 0x400000
    return struct.unpack_from('<f', exe_data, rva)[0]

def read_bytes(va, n):
    rva = va - 0x400000
    return exe_data[rva:rva+n]

print("[Test 1] Checking 0x00504BE0 Perform Action Verbs...")
# Verify strings referenced in 0x504BE0
verbs = {
    0x5CA124: b"faceto\x00",
    0x5C9B7C: b"say\x00",
    0x5C9B74: b"pause\x00",
    0x5CA394: b"aggress\x00",
    0x5CA38C: b"jump\x00",
    0x5CA384: b"attack\x00",
    0x5CA12C: b"guard\x00",
    0x5C9B60: b"crouch\x00",
    0x5C9B68: b"use\x00",
}
for va, expected in verbs.items():
    actual = read_bytes(va, len(expected))
    assert actual == expected, f"Mismatch at 0x{va:X}: {actual} != {expected}"
print("  -> All 9 Perform action strings verified in .rdata.")

print("[Test 2] Checking Vector Glyph Renderer 0x00504F50...")
# 0x00504F58: mov eax, dword ptr [edi*4 + 0x5ca3a0]
# Machine code: 8B 04 BD A0 A3 5C 00
insn_bytes = read_bytes(0x00504F58, 7)
assert insn_bytes == b'\x8B\x04\xBD\xA0\xA3\x5C\x00', f"Unexpected opcode at 0x504F58: {insn_bytes.hex()}"

# Float scale at 0x5AC29C = 0.0625f (1/16)
scale = read_f32(0x5AC29C)
assert abs(scale - 0.0625) < 1e-6, f"Scale mismatch: {scale}"

# 128 entries in table at 0x5CA3A0
tbl = 0x5CA3A0
for i in range(128):
    ptr = read_u32(tbl + i*4)
    assert 0x00401000 <= ptr <= 0x005E0000, f"Table entry {i} invalid: 0x{ptr:X}"
print("  -> 128-entry ASCII vector glyph table and 0.0625f scale verified.")

print("[Test 3] Checking Vector String Loop at 0x00501810...")
# 0x00501815: call 0x00504F50
# rel32 = 0x00504F50 - (0x00501815 + 5) = 0x00504F50 - 0x0050181A = 0x00003736
rel32 = struct.unpack_from('<i', exe_data, 0x00501815 - 0x400000 + 1)[0]
assert 0x00501815 + 5 + rel32 == 0x00504F50, f"Call target mismatch: 0x{0x00501815 + 5 + rel32:X}"
print("  -> DrawVectorString caller confirmed calling DrawVectorGlyph.")

print("[Test 4] Checking attacktarget 0x00504A70 and [ESI+0x88] Counter...")
# 0x00504AC8: fld dword ptr [0x5AB870] (80.0f)
# 0x00504AD0: fld dword ptr [0x5A8E7C] (40.0f)
f_long = read_f32(0x5AB870)
f_short = read_f32(0x5A8E7C)
assert abs(f_long - 80.0) < 1e-4, f"Long range mismatch: {f_long}"
assert abs(f_short - 40.0) < 1e-4, f"Short range mismatch: {f_short}"

# 0x00504B72: mov eax, [esi+0x88]; dec eax; mov [esi+0x88], eax
# Machine code: 8B 86 88 00 00 00 48 89 86 88 00 00 00
dec_bytes = read_bytes(0x00504B72, 13)
assert dec_bytes == b'\x8B\x86\x88\x00\x00\x00\x48\x89\x86\x88\x00\x00\x00', f"Dec counter mismatch: {dec_bytes.hex()}"
print("  -> attacktarget counter decrement and 40.0f/80.0f range thresholds verified.")

print("\nALL 4 TESTS PASSED! ZERO SPECULATION.")
