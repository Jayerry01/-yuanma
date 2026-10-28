# -*- coding: utf-8 -*-
# 批次B 辅助识别: 批次B 函数体高频出现的 0x508xxx-0x50Bxxx 小助手, 解码+定位
import json, struct, bisect, collections, sys
sys.stdout.reconfigure(encoding='utf-8')
from capstone import *

PE = json.load(open('D:/MeteorRE/_pe.json'))
IB = PE['ib']
EXE = open(r'C:\Program Files (x86)\Meteor\Meteor.exe', 'rb').read()
secs = PE['secs']

def va2off(va):
    for s in secs:
        base = IB + s['va']
        if base <= va < base + s['vs']:
            return s['pr'] + (va - base)
    return None

def rd(va, n):
    o = va2off(va)
    return EXE[o:o+n] if o is not None else b''

FF = json.load(open('D:/MeteorProjects/_private/ghidra_scripts/fresh_functions_v14.json'))
funcs = sorted([(int(f['a'], 16), int(f['a'], 16) + int(f['s'])) for f in FF])
starts = [a for a, e in funcs]

HELPERS = [0x5089FD, 0x508AE6, 0x508B38, 0x5095F5, 0x5099A7, 0x509980,
           0x509CE0, 0x50A85C, 0x50AB32, 0x50ADD7, 0x50BE69, 0x50E6B0]

# E8 caller count for each helper
tsec = [s for s in secs if s['name'] == '.text'][0]
t_base = IB + tsec['va']
data = EXE[tsec['pr']:tsec['pr'] + tsec['rs']]
HSET = set(HELPERS)
cnt = collections.Counter()
for i in range(len(data) - 5):
    if data[i] != 0xE8:
        continue
    rel = struct.unpack('<i', data[i+1:i+5])[0]
    tgt = t_base + i + 5 + rel
    if tgt in HSET:
        cnt[tgt] += 1

md = Cs(CS_ARCH_X86, CS_MODE_32)
out = ["="*78, "批次B 共享辅助函数识别 (0x508xxx-0x50Exxx)", "="*78]
for h in HELPERS:
    i = bisect.bisect_right(starts, h) - 1
    is_start = i >= 0 and funcs[i][0] == h
    fe = funcs[i][1] if is_start else h + 0x60
    out.append("")
    out.append("--- %08X (n=%d, %s) E8调用方 %d 处" % (
        h, fe - h, "函数起点" if is_start else "函数中段(父 %08X)" % funcs[i][0], cnt[h]))
    body = rd(h, min(fe - h, 0x50))
    for ins in md.disasm(body, h):
        out.append("    %08X  %-14s %s %s" % (ins.address, ins.bytes.hex(), ins.mnemonic, ins.op_str))
        if ins.mnemonic in ('ret', 'jmp') and ins.address > h + 4:
            break

txt = '\n'.join(out)
open('D:/MeteorRE/evidence/semB_helpers_20261028.txt', 'w', encoding='utf-8').write(txt)
print("written, lines=%d" % len(out))
