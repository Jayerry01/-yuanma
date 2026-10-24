import struct,json,sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
pe=json.load(open('_pe.json'));data=open('Meteor.exe','rb').read();ib=pe['ib']
secs={s['name']:s for s in pe['secs']}
t=secs['.text']; r=secs['.rdata']
tx=data[t['pr']:t['pr']+t['rs']]; tx_va=ib+t['va']
rd=data[r['pr']:r['pr']+r['rs']]; rd_va=ib+r['va']
md=Cs(CS_ARCH_X86,CS_MODE_32); md.detail=True
def rdval(va):
    o=va-rd_va
    if 0<=o<len(rd)-3:
        f=struct.unpack('<f',rd[o:o+4])[0]
        return '%g'%f
    return None
def dis(lo,hi):
    o=lo-tx_va; code=tx[o:o+(hi-lo)]
    for ins in md.disasm(code,lo):
        txt=ins.mnemonic+' '+ins.op_str
        found=[]
        for bp in range(len(ins.bytes)-3):
            cand=struct.unpack_from('<I',ins.bytes,bp)[0]
            if rd_va<=cand<rd_va+len(rd):
                v=rdval(cand)
                if v: found.append('%s@0x%X'%(v,cand))
        extra=('   ; '+', '.join(found)) if found else ''
        print('  0x%06X  %-24s %s%s'%(ins.address,ins.bytes.hex(),txt,extra))
if __name__=='__main__': dis(int(sys.argv[1],16),int(sys.argv[2],16))
