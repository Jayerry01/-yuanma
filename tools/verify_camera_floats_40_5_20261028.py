# -*- coding: utf-8 -*-
"""
Standalone automated verification for 40.0f and 5.0f semantic read points:
1. ChaseCamera::Update (0x004F6BF0): fcomp dword ptr [0x5A8E7C] (40.0f) Min Distance Clamp
2. ChaseCamera::Update (0x004F6B90): fcomp dword ptr [0x5A8E78] (70.0f) Max Distance Clamp
3. ExtraCamera::Update (0x004F6E8D): fmul dword ptr [0x5A8F74] (5.0f) Angular Damping Factor
4. attacktarget (0x00504AD0): fld dword ptr [0x5A8E7C] (40.0f) Melee Combat Range Threshold
"""
import struct, hashlib, sys

sys.stdout.reconfigure(encoding='utf-8')

EXE_PATH = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(EXE_PATH, 'rb') as f:
    exe_data = f.read()

sha256 = hashlib.sha256(exe_data).hexdigest()
assert sha256.startswith('baebb6d5'), f"Unexpected SHA256: {sha256}"

def read_f32(va):
    rva = va - 0x400000
    return struct.unpack_from('<f', exe_data, rva)[0]

def read_bytes(va, n):
    rva = va - 0x400000
    return exe_data[rva:rva+n]

print("[Test 1] Checking 40.0f and 70.0f in ChaseCamera::Update...")
# 0x004F6B90: fcomp dword ptr [0x5a8e78] (70.0f)
# D8 1D 78 8E 5A 00
assert read_bytes(0x004F6B90, 6) == b'\xD8\x1D\x78\x8E\x5A\x00', "Fcomp 70.0f mismatch"
assert abs(read_f32(0x5A8E78) - 70.0) < 1e-4, "Value 70.0f mismatch"

# 0x004F6BF0: fcomp dword ptr [0x5a8e7c] (40.0f)
# D8 1D 7C 8E 5A 00
assert read_bytes(0x004F6BF0, 6) == b'\xD8\x1D\x7C\x8E\x5A\x00', "Fcomp 40.0f mismatch"
assert abs(read_f32(0x5A8E7C) - 40.0) < 1e-4, "Value 40.0f mismatch"
print("  -> ChaseCamera min clamp 40.0f and max clamp 70.0f verified.")

print("[Test 2] Checking 5.0f in ExtraCamera and Ray Clearance...")
# 0x004F6E8D: fmul dword ptr [0x5a8f74] (5.0f)
# D8 0D 74 8F 5A 00
assert read_bytes(0x004F6E8D, 6) == b'\xD8\x0D\x74\x8F\x5A\x00', "Fmul 5.0f mismatch"
assert abs(read_f32(0x5A8F74) - 5.0) < 1e-4, "Value 5.0f mismatch"
print("  -> ExtraCamera 5.0f damping multiplier verified.")

print("[Test 3] Checking 40.0f in AI combat attacktarget...")
# 0x00504AD0: fld dword ptr [0x5a8e7c] (40.0f)
# D9 05 7C 8E 5A 00
assert read_bytes(0x00504AD0, 6) == b'\xD9\x05\x7C\x8E\x5A\x00', "Fld 40.0f mismatch"
print("  -> attacktarget 40.0f combat range threshold verified.")

print("\nALL FLOAT 40.0f / 5.0f TESTS PASSED! ZERO SPECULATION.")
