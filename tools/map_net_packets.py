# -*- coding: utf-8 -*-
import struct
import sys

sys.stdout.reconfigure(encoding='utf-8')

exe_path = r'D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe'
with open(exe_path, 'rb') as f:
    data = f.read()

# Find callers of 0x00402BD0
callers = []
for i in range(0x1000, 0x1A8000 - 5):
    if data[i] == 0xE8:
        rel = struct.unpack('<i', data[i+1:i+5])[0]
        va = 0x400000 + i
        target = va + 5 + rel
        if target == 0x00402BD0:
            callers.append(va)

print(f"Analyzing {len(callers)} NetClient::SendBuffer call sites for Packet IDs:")

# Check 30 bytes before each call site for packet ID assignment or push
packet_types = []
for va in callers:
    raw = va - 0x400000
    chunk = data[raw-30:raw]
    # Look for push imm8 (6A xx) or mov byte ptr [..], imm8 (C6 .. xx)
    # or mov [esp+..], imm
    found_id = None
    for j in range(len(chunk)-3):
        if chunk[j] == 0x6A: # push imm8
            imm = chunk[j+1]
            found_id = ('push', imm)
        elif chunk[j] == 0xC6 and chunk[j+1] in [0x44, 0x45, 0x00, 0x01]: # mov byte ptr [reg+disp], imm8
            imm = chunk[j+3] if chunk[j+1] in [0x44, 0x45] else chunk[j+2]
            found_id = ('mov_byte', imm)
    packet_types.append((hex(va), found_id))

print(f"Sample of analyzed call sites (first 30):")
for va, pkt in packet_types[:30]:
    print(f"  VA {va}: Packet Tag candidate: {pkt}")
