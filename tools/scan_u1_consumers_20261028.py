import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import va
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_MEM

WRITERS = {
    0x4CAC4A: 'W ctor init',
    0x4CAE43: 'W dtor free',
    0x4CC239: 'W tick clear',
    0x4CC245: 'W tick clear',
    0x4CBCF4: 'W FUN_004CBCE0 append',
    0x4CFD90: 'W FUN_004CFD70 m/a append',
}
VFT_CALL = {
    0x4CB1C1: 'call [vft+0x2E8] slot186',
    0x4CB1F7: 'call [vft+0x2E8] slot186',
    0x4CB22D: 'call [vft+0x2E8] slot186',
    0x4CBC90: 'FUN_004CBC90 gate [this+0x3C4]',
}

DISPS = {0x2E8: 'S1vec', 0x2EC: 'S1b', 0x2F0: 'S1c', 0x2F4: 'S2', 0x2F8: 'F2F8', 0x2FC: 'F2FC', 0x3C4: 'GATE3C4'}

md = Cs(CS_ARCH_X86, CS_MODE_32)
md.detail = True
md.skipdata = True

START_VA = 0x401000
FO = 4096
N = 1732608
data = va.data[FO:FO + N]

hits = []
n_dec = 0
for insn in md.disasm(data, START_VA):
    n_dec += 1
    try:
        ops = insn.operands
    except Exception:
        continue
    is_call = insn.mnemonic == 'call'
    for op in ops:
        if op.type == X86_OP_MEM and op.mem.disp in DISPS:
            tag = DISPS[op.mem.disp]
            if insn.address in WRITERS:
                cls = WRITERS[insn.address]
            elif is_call and insn.address in VFT_CALL:
                cls = VFT_CALL[insn.address]
            elif is_call:
                cls = 'CALL-scalar'
            elif insn.mnemonic == 'lea':
                cls = 'LEA-ptr'
            elif insn.mnemonic.startswith('mov') or insn.mnemonic.startswith('push'):
                cls = 'READ/WRITE'
            else:
                cls = 'other'
            hits.append((insn.address, tag, cls, insn.mnemonic, insn.op_str, insn.bytes.hex()))

from collections import Counter
print('=== instructions decoded (linear+skipdata):', n_dec)
print('=== total hits:', len(hits))
print('=== by tag:', dict(Counter(h[1] for h in hits)))
print('=== by class:', dict(Counter(h[2] for h in hits)))
print()
for a, tag, cls, m, o, b in hits:
    mark = '' if cls.startswith('W ') or cls.startswith('call [vft') else '  <<<'
    print('0x%08X %-7s %-22s %-9s %-34s %s%s' % (a, tag, cls, m, o, b, mark))
