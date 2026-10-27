#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
scan_call.py — 在 PE 的 .text 里找出所有**直接调用**（E8 rel32）指向指定 VA 的位置。
用途：Ghidra 的引用账本对旧二进制常不完整；且「某函数有没有被调用」是判定
      一个地址到底是不是真入口的硬依据。

用法: python scan_call.py <exe> <targetVA-hex[,targetVA-hex...]>

注意（踩过的坑）：
  E8 指令的目标 VA = 0x400000 + (文件偏移) + 5 + rel32，
  不能拿「文件偏移 + 5 + rel」直接跟 VA 比 —— 必须先加 imageBase 换算。
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
    targets = set(int(x, 16) for x in sys.argv[2].split(','))
    d, imgbase, secs = load(path)
    # 只在可执行段里扫
    regions = [(pr, rs, imgbase + va) for nm, va, vs, pr, rs in secs
               if rs and nm in ('.text',)]
    if not regions:
        regions = [(pr, rs, imgbase + va) for nm, va, vs, pr, rs in secs if rs]
    hits = {t: [] for t in targets}
    for pr, rs, base in regions:
        blob = d[pr:pr + rs]
        i = 0
        L = len(blob)
        while i < L - 5:
            if blob[i] == 0xE8:
                rel = struct.unpack_from('<i', blob, i + 1)[0]
                tgt = base + i + 5 + rel
                if tgt in targets:
                    hits[tgt].append(base + i)
            i += 1
    for t in sorted(targets):
        print('目标 0x%08X -> %d 个直接调用点' % (t, len(hits[t])))
        for c in sorted(set(hits[t])):
            print('    from 0x%08X' % c)


if __name__ == '__main__':
    main()
