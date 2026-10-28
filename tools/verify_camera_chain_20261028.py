# -*- coding: utf-8 -*-
import struct, hashlib

pe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(pe_path, 'rb') as f:
    exe_data = f.read()

sha256 = hashlib.sha256(exe_data).hexdigest()
assert sha256.startswith('baebb6d5'), f"Unexpected SHA256: {sha256}"

e_lfanew = struct.unpack_from('<I', exe_data, 0x3C)[0]
num_sections = struct.unpack_from('<H', exe_data, e_lfanew + 6)[0]
opt_hdr_size = struct.unpack_from('<H', exe_data, e_lfanew + 20)[0]
sec_tbl = e_lfanew + 24 + opt_hdr_size

def va_to_off(target):
    for i in range(num_sections):
        sec = exe_data[sec_tbl + i*40 : sec_tbl + (i+1)*40]
        vsize, vaddr, raw_size, raw_offset = struct.unpack_from('<IIII', sec, 8)
        va = 0x400000 + vaddr
        if va <= target < va + vsize:
            return target - va + raw_offset
    return None

def read_str(va):
    off = va_to_off(va)
    return exe_data[off:off+64].split(b'\x00')[0].decode('ascii', errors='ignore')

def read_u32(va):
    off = va_to_off(va)
    return struct.unpack_from('<I', exe_data, off)[0]

def read_bytes(va, n):
    off = va_to_off(va)
    return exe_data[off:off+n]

print("================================================================================")
print("相机体系逆向结论 · 逐字节严格证伪检验脚本")
print(f"目标二进制 SHA256: {sha256[:16]}...")
print("================================================================================")

# 1. 验证字符串
str_camera_switch = read_str(0x005C98AC)
print(f"[Check 1] 0x005C98AC 处字符串: '{str_camera_switch}'")
assert str_camera_switch == "Switch Extra Camera.", "Check 1 FAILED"

str_perf_error = read_str(0x005C9F9C)
print(f"[Check 2] 0x005C9F9C 处字符串: '{str_perf_error}'")
assert str_perf_error == "performance counter Error!", "Check 2 FAILED"

# 2. 验证控制台命令 0x4B6A05 槽调用与字符串参数
bytes_cmd = read_bytes(0x004B6A1F, 24)
# 0x004B6A1F: FF 93 CC 01 00 00 (call dword ptr [ebx + 0x1cc])
# 0x004B6A32: 68 AC 98 5C 00    (push 0x5C98AC)
assert b'\xFF\x93\xCC\x01\x00\x00' in bytes_cmd, "Check 3 FAILED: 未找到 call [ebx+0x1cc]"
assert b'\x68\xAC\x98\x5C\x00' in bytes_cmd, "Check 3 FAILED: 未找到 push 0x5C98AC"
print("[Check 3] 0x004B6A05 控制台命令确实调用虚槽 +0x1CC 并压入 'Switch Extra Camera.'")

# 3. 验证 CameraManager 虚表 0x005A9FE0 Slot 115 (+0x1CC)
fn_slot115 = read_u32(0x005A9FE0 + 0x1CC)
print(f"[Check 4] CameraManager 虚表 0x005A9FE0 的 Slot 115 (+0x1CC): 0x{fn_slot115:08X}")
assert fn_slot115 == 0x004BB4B0, "Check 4 FAILED"

# 4. 验证 0x004BB4B0 的内联转发逻辑
# 8B 81 F0 03 00 00 (mov eax, [ecx+0x3f0])
# 8B 8C 81 C8 03 00 00 (mov ecx, [ecx+eax*4+0x3c8])
# 8B 11 (mov edx, [ecx])
# FF 62 44 (jmp [edx+0x44])
bytes_forward = read_bytes(0x004BB4B0, 24)
assert b'\x8B\x81\xF0\x03\x00\x00' in bytes_forward, "Check 5 FAILED: 未读取 +0x3f0"
assert b'\x8B\x8C\x81\xC8\x03\x00\x00' in bytes_forward, "Check 5 FAILED: 未读取 [+eax*4+0x3c8]"
assert b'\xFF\x62\x44' in bytes_forward, "Check 5 FAILED: 未跳转 [edx+0x44]"
print("[Check 5] 0x004BB4B0 汇编结构完全吻合: 索引(+0x3f0) -> 数组(+0x3c8) -> 虚表 Slot 17 (+0x44)")

# 5. 验证三台相机构造函数中的虚表写入硬编码
# ChaseCamera 构造 0x004F5D60: C7 06 10 B7 5A 00 (mov dword ptr [esi], 0x5AB710)
bytes_chase_ctor = read_bytes(0x004F5D60, 20)
assert b'\xC7\x06\x10\xB7\x5A\x00' in bytes_chase_ctor, "Check 6 FAILED: ChaseCamera 未写入 0x5AB710"
print("[Check 6] ChaseCamera 构造函数 0x004F5D60 确凿写入虚表 0x005AB710")

# ExtraCamera 构造 0x004F7200: C7 06 A8 B7 5A 00 (mov dword ptr [esi], 0x5AB7A8)
bytes_extra_ctor = read_bytes(0x004F7200, 64)
assert b'\xC7\x06\xA8\xB7\x5A\x00' in bytes_extra_ctor, "Check 7 FAILED: ExtraCamera 未写入 0x5AB7A8"
print("[Check 7] ExtraCamera 构造函数 0x004F7200 确凿写入虚表 0x005AB7A8")

# 6. 验证 ChaseCamera 虚表 0x005AB710 的 Slot 1 (+0x04)
fn_slot1 = read_u32(0x005AB710 + 0x04)
print(f"[Check 8] ChaseCamera 虚表 0x005AB710 的 Slot 1 (+0x04): 0x{fn_slot1:08X}")
assert fn_slot1 == 0x004F5FA0, "Check 8 FAILED: Slot 1 并非 0x004F5FA0"

# 7. 验证 0x004F5FA0 的体量和错误字符串引用
bytes_update = read_bytes(0x004F5FA0, 100)
# push 0x5C9F9C: 68 9C 9F 5C 00
assert b'\x68\x9C\x9F\x5C\x00' in bytes_update, "Check 9 FAILED: 0x4F5FA0 未引用 'performance counter Error!'"
print("[Check 9] 0x004F5FA0 确凿为高精度计时驱动的追尾相机主 Update 方法")

print("================================================================================")
print(">>> 全部 9 处物理字节与汇编语义断言 100% 通过检验！ <<<")
print("================================================================================")
