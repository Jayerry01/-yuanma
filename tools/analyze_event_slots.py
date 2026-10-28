# -*- coding: utf-8 -*-
import struct
import sys

sys.stdout.reconfigure(encoding='utf-8')

exe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(exe_path, 'rb') as f:
    data = f.read()

def get_u32(va):
    raw = va - 0x400000
    return struct.unpack('<I', data[raw:raw+4])[0]

jump_table = [get_u32(0x004D955C + i*4) for i in range(15)]

print(f"Analyzing 15 Event Slots in Jump Table 0x004D955C:")
for slot, va in enumerate(jump_table):
    raw = va - 0x400000
    chunk = data[raw:raw+60]
    # find call [eax + disp] or call [edx + disp]
    vcall = None
    for j in range(len(chunk)-5):
        if chunk[j] == 0xFF and (chunk[j+1] == 0x90 or chunk[j+1] == 0x92):
            disp = struct.unpack('<I', chunk[j+2:j+6])[0]
            vcall = (disp, disp // 4)
            break
    print(f"Slot {slot:02d} (VA 0x{va:08X}): calls WorldManager vtable disp 0x{vcall[0]:03X} (Slot {vcall[1]})" if vcall else f"Slot {slot:02d} (VA 0x{va:08X}): no vcall in first 60 bytes")
