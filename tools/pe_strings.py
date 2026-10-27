#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
pe_strings.py — 直接从 PE 文件的原始字节里按 VA 区间抽取可打印串。
用途：绕开 Ghidra strings 工具的最小长度过滤，拿到字符串池的*完整有序*序列。

用法: python pe_strings.py <exe> <startVA-hex> <len-hex> [minlen]
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
        secs.append((nm, va, vs, pr, rs))
    return d, imgbase, secs


def va2off(v, imgbase, secs):
    r = v - imgbase
    for n, va, vs, pr, rs in secs:
        if va <= r < va + vs:
            return pr + (r - va)
    return None


def main():
    path = sys.argv[1]
    start = int(sys.argv[2], 16)
    ln = int(sys.argv[3], 16)
    minlen = int(sys.argv[4]) if len(sys.argv) > 4 else 3
    d, imgbase, secs = load(path)
    off = va2off(start, imgbase, secs)
    if off is None:
        print('VA 0x%x 不在任何节内' % start)
        return
    raw = d[off:off + ln]
    out = []
    buf = b''
    st = None
    for i, b in enumerate(raw):
        if 32 <= b < 127 or b in (9, 10, 13):
            if st is None:
                st = i
            buf += bytes([b])
        else:
            if buf:
                out.append((start + st, buf.decode('latin1')))
            buf = b''
            st = None
    if buf:
        out.append((start + st, buf.decode('latin1')))
    for a, s in out:
        if len(s) >= minlen:
            print('%08x : %s' % (a, s))


if __name__ == '__main__':
    main()
