# -*- coding: utf-8 -*-
import struct
import re
import sys

sys.stdout.reconfigure(encoding='utf-8')

exe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(exe_path, 'rb') as f:
    data = f.read()

# PE parsing
e_lfanew = struct.unpack_from('<I', data, 0x3C)[0]
num_sections = struct.unpack_from('<H', data, e_lfanew + 6)[0]
opt_hdr_size = struct.unpack_from('<H', data, e_lfanew + 20)[0]
image_base = struct.unpack_from('<I', data, e_lfanew + 24 + 28)[0]
sec_table_offset = e_lfanew + 24 + opt_hdr_size

text_raw_start = 0
text_raw_end = 0
text_va_start = 0

for i in range(num_sections):
    sec = data[sec_table_offset + i*40 : sec_table_offset + (i+1)*40]
    name = sec[:8].strip(b'\x00').decode('latin-1')
    va = struct.unpack_from('<I', sec, 12)[0]
    raw_size = struct.unpack_from('<I', sec, 16)[0]
    raw_ptr = struct.unpack_from('<I', sec, 20)[0]
    if name == '.text':
        text_raw_start = raw_ptr
        text_raw_end = raw_ptr + raw_size
        text_va_start = image_base + va
        print(f"Found .text: Raw [0x{raw_ptr:X}..0x{raw_ptr+raw_size:X}], VA [0x{image_base+va:X}]")

# Search for disp32 = 0x000005E0 (e0 05 00 00) and 0x000002E8 (e8 02 00 00)
pat_5e0 = re.compile(b'\xe0\x05\x00\x00')
pat_2e8 = re.compile(b'\xe8\x02\x00\x00')

m5e0 = [m.start() for m in pat_5e0.finditer(data) if text_raw_start <= m.start() < text_raw_end]
m2e8 = [m.start() for m in pat_2e8.finditer(data) if text_raw_start <= m.start() < text_raw_end]

print(f"\n[Verified] Total .text hits for +0x5E0 (PoseId): {len(m5e0)}")
print(f"[Verified] Total .text hits for +0x2E8 (DirectionBuffer): {len(m2e8)}")

print("\n--- Top hits for +0x5E0 (PoseId access in PlayerController / Combat) ---")
for m in m5e0[:8]:
    va = text_va_start + (m - text_raw_start)
    # Print 8 bytes before and 4 bytes after
    instr_context = data[m-3 : m+4].hex(' ')
    print(f"  VA 0x{va:08X} (File 0x{m:06X}): bytes: {instr_context}")

print("\n--- Top hits for +0x2E8 (DirectionBuffer / Key Buffer) ---")
for m in m2e8[:8]:
    va = text_va_start + (m - text_raw_start)
    instr_context = data[m-3 : m+4].hex(' ')
    print(f"  VA 0x{va:08X} (File 0x{m:06X}): bytes: {instr_context}")
