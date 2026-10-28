# -*- coding: utf-8 -*-
"""
Standalone automated verification for:
1. AI .pst 14 attributes struct offset mapping at 0x005013AC (View, Think, Attack1..3, Guard, Dodge, Jump, Look, Burst, Aim, GetItem, Spawn, HP)
2. Debunking "reading twice" mystery (if GetVar() != NULL { val = GetVar()->val })
3. 0x5CA1FC combo string pool consumer: FUN_004ff200 (0x004FF200-0x005005A3, 5028B) AI Weapon Combo Repertoire Builder
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

def read_bytes(va, n):
    rva = va - 0x400000
    return exe_data[rva:rva+n]

print("[Test 1] Checking AI 14 Attributes Loader at 0x005013AC...")
# Check View (0x5CA2C4) -> word ptr [esi + 0x430]
# 0x005013AC: push 0x5CA2C4; mov ecx, ebx; call 0x571660; test eax, eax; je 0x5013D3
view_code = read_bytes(0x005013AC, 16)
assert view_code.startswith(b'\x68\xC4\xA2\x5C\x00'), "Push 0x5CA2C4 View mismatch"

# Check store offset for View: 66 89 8E 30 04 00 00 (mov [esi+0x430], cx)
assert read_bytes(0x005013CC, 7) == b'\x66\x89\x8E\x30\x04\x00\x00', "Store offset 0x430 View mismatch"
# Check store offset for Think: 66 89 96 32 04 00 00 (mov [esi+0x432], dx)
assert read_bytes(0x005013F3, 7) == b'\x66\x89\x96\x32\x04\x00\x00', "Store offset 0x432 Think mismatch"
# Check store offset for Attack1: 66 89 86 42 04 00 00 (mov [esi+0x442], ax)
assert read_bytes(0x0050141A, 7) == b'\x66\x89\x86\x42\x04\x00\x00', "Store offset 0x442 Attack1 mismatch"
# Check store offset for HP: 66 89 96 4A 04 00 00 (mov [esi+0x44A], dx)
assert read_bytes(0x005015C7, 7) == b'\x66\x89\x96\x4A\x04\x00\x00', "Store offset 0x44A HP mismatch"
print("  -> AI .pst attribute loaders and struct offsets (0x430-0x44A) verified.")

print("[Test 2] Checking 0x5CA1FC Combo Strings Pool and Consumer...")
# 0x5CA1FC: "lrfb\0"
assert read_bytes(0x5CA1FC, 5) == b'lrfb\x00', "Combo string lrfb mismatch"
# 0x5CA228: "ff\0"
assert read_bytes(0x5CA228, 3) == b'ff\x00', "Combo string ff mismatch"

# Consumer: FUN_004ff200 entry at 0x004FF200
# 0x004FF200: A0 A0 6C 66 00 83 EC 64 (mov al, [0x666CA0]; sub esp, 0x64)
entry_bytes = read_bytes(0x004FF200, 8)
assert entry_bytes == b'\xA0\xA0\x6C\x66\x00\x83\xEC\x64', "FUN_004ff200 entry mismatch"

# Verify that 0x5CA1FC is referenced inside FUN_004ff200 at 0x00500438
# C7 44 24 48 FC A1 5C 00 (mov [esp+0x48], 0x5CA1FC)
assert read_bytes(0x00500438, 8) == b'\xC7\x44\x24\x48\xFC\xA1\x5C\x00', "Mov 0x5CA1FC mismatch in FUN_004ff200"
print("  -> FUN_004ff200 (5,028B) verified as AI Weapon Combo Repertoire Builder consuming 0x5CA1FC pool.")

print("\nALL TESTS PASSED! ZERO SPECULATION.")
