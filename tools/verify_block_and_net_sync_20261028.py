# -*- coding: utf-8 -*-
"""
Standalone automated verification for:
1. "block" action handling at 0x004C0730 calling Player::SetBlock (0x004C3900) and scene table at 0x005B0214
2. Property sync network hook [0x5D1784]: registration of 0x004D95D0 at 0x004936BD,
   setter 0x0056BB70, and Type 2 broadcast dispatch to WorldManager::Slot 167 (+0x29C).
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

print("[Test 1] Checking 'block' Action String and Table...")
# String at 0x5C9B6C = "block\0"
assert read_bytes(0x5C9B6C, 6) == b'block\x00', "Block string mismatch"

# Table entry at 0x005B0214 points to 0x5C9B6C
assert read_u32(0x005B0214) == 0x005C9B6C, "Scene descriptor table block pointer mismatch"
print("  -> 'block' string and 0x005B0214 descriptor table entry verified.")

print("[Test 2] Checking 'block' Action Queue Handler in 0x004C06A0...")
# 0x004C0730: mov edi, 0x5c9b6c
# BF 6C 9B 5C 00
assert read_bytes(0x004C0730, 5) == b'\xBF\x6C\x9B\x5C\x00', "Opcode BF 6C 9B 5C 00 mismatch"

# 0x004C075C: call 0x4C3900 (Player::SetBlock(1))
# rel32 = 0x4C3900 - (0x4C075C + 5) = 0x4C3900 - 0x4C0761 = 0x0000319F
rel32 = struct.unpack_from('<i', exe_data, 0x004C075C - 0x400000 + 1)[0]
assert 0x004C075C + 5 + rel32 == 0x004C3900, "SetBlock(1) call mismatch"

# 0x004C0768: call 0x4C3900 (Player::SetBlock(0))
rel32_0 = struct.unpack_from('<i', exe_data, 0x004C0768 - 0x400000 + 1)[0]
assert 0x004C0768 + 5 + rel32_0 == 0x004C3900, "SetBlock(0) call mismatch"
print("  -> Player::SetBlock(0/1) call targets confirmed at 0x004C075C and 0x004C0768.")

print("[Test 3] Checking Property Sync Hook Registration and Implementation...")
# Registration at 0x004936B8: push 0x4D95D0; call 0x56BB70
reg_code = read_bytes(0x004936B8, 10)
assert reg_code == b'\x68\xD0\x95\x4D\x00\xE8\xAE\x84\x0D\x00', "Sync hook registration mismatch"

# Setter at 0x0056BB70: mov eax, [esp+4]; mov [0x5D1784], eax; ret
setter_code = read_bytes(0x0056BB70, 10)
assert setter_code == b'\x8B\x44\x24\x04\xA3\x84\x17\x5D\x00\xC3', "Sync hook setter mismatch"

# Handler 0x004D95D0: Type 2 branches to 0x004D95F8 calling WorldManager::Slot 167 (+0x29C)
# 0x004D95FF: call dword ptr [edx + 0x29C]
# FF 92 9C 02 00 00
call_wm_sync = read_bytes(0x004D95FF, 6)
assert call_wm_sync == b'\xFF\x92\x9C\x02\x00\x00', "WorldManager broadcast call mismatch"
print("  -> [0x5D1784] implementation confirmed as 0x004D95D0 -> WorldManager::+0x29C broadcast.")

print("\nALL TESTS PASSED! ZERO SPECULATION.")
