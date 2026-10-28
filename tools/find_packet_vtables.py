# -*- coding: utf-8 -*-
import struct
import sys

sys.stdout.reconfigure(encoding='utf-8')

exe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(exe_path, 'rb') as f:
    data = f.read()

# Look for occurrences where a pointer to a vtable is stored into [ecx] or [esp+disp]
# In x86: C7 01 <vtable_va> (mov [ecx], vtable) or C7 44 24 disp <vtable_va>
# Let's search .rdata for pointers to functions around 0x0047B... / 0x00481...
# Functions: 0x0047BAC0, 0x0047BBF0, 0x0047B550, 0x00481610, 0x00481750

target_funcs = [0x0047BAC0, 0x0047BBF0, 0x0047B550, 0x00481610, 0x00481750]

rdata_start = 0x5A8000
rdata_raw = rdata_start - 0x400000

vtables = []
for i in range(0x1000, len(data) - 32, 4):
    u = struct.unpack('<I', data[i:i+4])[0]
    if u in target_funcs:
        # Check if surrounding words are also code pointers in .text (0x401000..0x5A8000)
        va = 0x400000 + i
        # scan backwards to find start of vtable
        start = i
        while start >= 4:
            prev_u = struct.unpack('<I', data[start-4:start])[0]
            if 0x00401000 <= prev_u <= 0x005A8000:
                start -= 4
            else:
                break
        vt_va = 0x400000 + start
        if vt_va not in vtables:
            vtables.append(vt_va)

print(f"Found {len(vtables)} candidate packet vtables:")
for vt in vtables[:20]:
    raw = vt - 0x400000
    slots = [struct.unpack('<I', data[raw+k*4:raw+(k+1)*4])[0] for k in range(6)]
    slots_str = ' '.join(f"0x{s:08X}" for s in slots)
    print(f"  Vtable 0x{vt:08X}: {slots_str}")
