import struct, json, sys, os

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
pe = json.load(open(os.path.join(HERE, '_pe.json')))
data = open(os.path.join(HERE, 'Meteor.exe'), 'rb').read()
IB = pe['ib']

def off(va):
    r = va - IB
    for s in pe['secs']:
        if s['va'] <= r < s['va'] + max(s['vs'], s['rs']):
            d = r - s['va']
            if d >= s['rs']:
                raise ValueError('VA 0x%X in %s beyond raw size (bss)' % (va, s['name']))
            return s['pr'] + d, s['name']
    raise ValueError('VA 0x%X not in any section' % va)

def dword(va):
    o, sec = off(va)
    return struct.unpack_from('<I', data, o)[0], sec

def dump(va, n):
    o, sec = off(va)
    return data[o:o + n].hex(' '), sec

if __name__ == '__main__':
    mode = sys.argv[1]
    if mode == 'dw':
        for a in sys.argv[2:]:
            v, sec = dword(int(a, 16))
            print('0x%08X  %s  0x%08X  (%s)' % (int(a, 16), data[off(int(a,16))[0]:off(int(a,16))[0]+4].hex(' '), v, sec))
    elif mode == 'hex':
        va = int(sys.argv[2], 16); n = int(sys.argv[3], 0) if len(sys.argv) > 3 else 16
        h, sec = dump(va, n)
        print('0x%08X (%s) %s' % (va, sec, h))
