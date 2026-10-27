#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
scan_ptr.py — 在 PE 的原始字节里搜索指向指定 VA 的 32 位小端指针。
用途：绕开 Ghidra 的引用账本（对 .data 段常不完整），直接找到指针数组的槽位。

用法: python scan_ptr.py <exe> <VA-hex[,VA-hex...]> [--min 0xVA] [--max 0xVA]
输出: 每个目标 VA 的所有指针槽位（文件内 VA，按 PE 节映射还原）
"""
import io, struct, sys


def load(path):
    d = io.open(path, 'rb').read()
    pe = struct.unpack_from('<I', d, 0x3c)[0]
    nsec = struct.unpack_from('<H', d, pe + 6)[0]
    optoff = pe + 0x18
    szopt = struct.unpack_from('<H', d, pe + 0x14)[0]
    imgbase = struct.unpack_from('<I', d, optoff + 28)[0]
    secoff = optoff + szopt
    secs = []
    for i in range(nsec):
        o = secoff + i * 40
        nm = d[o:o + 8].rstrip(b'\x00').decode('latin1')
        vs = struct.unpack_from('<I', d, o + 8)[0]
        va = struct.unpack_from('<I', d, o + 12)[0]
        rs = struct.unpack_from('<I', d, o + 16)[0]
        pr = struct.unpack_from('<I', d, o + 20)[0]
        secs.append((nm, va, vs, pr, min(rs, vs)))
    return d, imgbase, secs


def main():
    path = sys.argv[1]
    targets = [int(x, 16) for x in sys.argv[2].split(',')]
    lo = hi = None
    args = sys.argv[3:]
    for i, a in enumerate(args):
        if a == '--min':
            lo = int(args[i + 1], 16)
        elif a == '--max':
            hi = int(args[i + 1], 16)
    d, imgbase, secs = load(path)
    # build list of (rawOff, rawLen, sectionVA)
    regions = []
    for nm, va, vs, pr, rs in secs:
        if rs == 0:
            continue
        regions.append((pr, rs, imgbase + va, nm))
    for t in targets:
        pat = struct.pack('<I', t)
        hits = []
        for pr, rs, sva, nm in regions:
            blob = d[pr:pr + rs]
            off = 0
            while True:
                k = blob.find(pat, off)
                if k < 0:
                    break
                slot = sva + k
                if (lo is None or slot >= lo) and (hi is None or slot < hi):
                    hits.append((slot, nm))
                off = k + 1
        print('target 0x%08X -> %d slot(s)' % (t, len(hits)))
        for slot, nm in hits:
            print('    %08X  (%s)' % (slot, nm))


if __name__ == '__main__':
    main()
