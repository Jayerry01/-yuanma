// Terminus2.java — NO decompiler (it hangs on this body). Pure listing evidence:
// dump vtable 0x5aa660 neighbourhood, all key slots bound by ctor 0x4c8730, and full asm of slot13 = FUN_004c8eb0.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Terminus2 extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/terminus2.txt"));
        Memory mem = currentProgram.getMemory();

        long VF = 0x5aa660L;
        log("==================== A: vtable 0x005aa660 key slots ====================");
        long[] slots = { 0L, 1L, 2L, 3L, 4L, 8L, 12L, 13L, 14L, 15L, 16L, 17L, 18L, 20L, 122L, 223L };
        for (long s : slots) {
            long addr = VF + s * 4L;
            int v = mem.getInt(toAddr(addr));
            Function f = getFunctionAt(toAddr(v & 0xffffffffL));
            log(String.format("  slot %-4d (+0x%-4x) @0x%08x = 0x%08x  %s", s, s * 4, addr, v,
                f == null ? "(NO FUNCTION / not 4-aligned)" : f.getName() + "  size=" + f.getBody().getNumAddresses()));
        }

        log("");
        log("==================== B: slot 13 target = FUN_004c8eb0 : FULL listing ====================");
        Function f13 = getFunctionAt(toAddr(0x4c8eb0L));
        if (f13 == null) {
            log("!! no function at 0x4c8eb0");
        } else {
            log(f13.getName() + "  size=" + f13.getBody().getNumAddresses());
            InstructionIterator ii = currentProgram.getListing().getInstructions(f13.getBody(), true);
            int n = 0;
            while (ii.hasNext() && n < 200) {
                Instruction ins = ii.next();
                log("  0x" + ins.getAddress() + "  " + ins.toString());
                n++;
            }
            log("--- RET / tail exits ---");
            InstructionIterator ri = currentProgram.getListing().getInstructions(f13.getBody(), true);
            while (ri.hasNext()) {
                Instruction ins = ri.next();
                String mn = ins.getMnemonicString();
                if (mn.startsWith("RET") || mn.equals("JMP")) log("    " + ins.getAddress() + "  " + ins.toString());
            }
            log("--- calls inside ---");
            InstructionIterator ci = currentProgram.getListing().getInstructions(f13.getBody(), true);
            while (ci.hasNext()) {
                Instruction ins = ci.next();
                if (!ins.getMnemonicString().equals("CALL")) continue;
                Address[] flows = ins.getFlows();
                Function tf = (flows.length > 0 ? getFunctionAt(flows[0]) : null);
                log("    0x" + ins.getAddress() + "  CALL " + ins.toString()
                    + (tf == null ? "" : "   -> " + tf.getName() + " size=" + tf.getBody().getNumAddresses()));
            }
            log("--- xrefs TO slot13 target ---");
            dumpXrefs(f13.getEntryPoint(), 40);
        }

        log("");
        log("==================== C: who writes vfptr 0x5aa660 ====================");
        InstructionIterator ii2 = currentProgram.getListing().getInstructions(mem.getExecuteSet(), true);
        int hits = 0;
        while (ii2.hasNext() && hits < 40) {
            Instruction ins = ii2.next();
            boolean found = false;
            for (int o = 0; o < ins.getNumOperands() && !found; o++) {
                for (Object ob : ins.getOpObjects(o)) {
                    if (ob instanceof Scalar && ((Scalar) ob).getValue() == VF) found = true;
                }
            }
            if (!found) continue;
            Function f = currentProgram.getFunctionManager().getFunctionContaining(ins.getAddress());
            log("  0x" + ins.getAddress() + "  " + ins.toString() + "   [" + (f == null ? "?" : f.getName()) + "]");
            hits++;
        }

        log("");
        log("==================== D: ctor 0x4c8730 head + size=vtable relation ====================");
        Function ctor = getFunctionAt(toAddr(0x4c8730L));
        if (ctor != null) {
            log(ctor.getName() + " size=" + ctor.getBody().getNumAddresses());
            log("--- first 30 insns ---");
            InstructionIterator ci = currentProgram.getListing().getInstructions(ctor.getBody(), true);
            int n = 0;
            while (ci.hasNext() && n < 30) { Instruction ins = ci.next(); log("  0x" + ins.getAddress() + "  " + ins.toString()); n++; }
            log("--- max member displacement written (estimate object size) ---");
            TreeMap<Long, String> disp = new TreeMap<Long, String>();
            InstructionIterator di = currentProgram.getListing().getInstructions(ctor.getBody(), true);
            while (di.hasNext()) {
                Instruction ins = di.next();
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof Scalar) {
                            long v = ((Scalar) ob).getValue();
                            if (v > 0x100L && v < 0x200L && v % 4 == 0) disp.put(v, "0x" + ins.getAddress() + "  " + ins.toString());
                        }
                    }
                }
            }
            int k = 0;
            for (Long d : disp.descendingKeySet()) {
                log("    0x" + Long.toHexString(d) + "  " + disp.get(d));
                if (++k >= 8) break;
            }
            log("--- xrefs TO ctor 0x4c8730 ---");
            dumpXrefs(ctor.getEntryPoint(), 40);
        }

        pw.flush();
        pw.close();
        log("=== TERMINUS2 DONE ===");
    }

    void dumpXrefs(Address a, int max) {
        ghidra.program.model.symbol.ReferenceIterator ri = currentProgram.getReferenceManager().getReferencesTo(a);
        int n = 0;
        while (ri.hasNext() && n < max) {
            ghidra.program.model.symbol.Reference r = ri.next();
            Function f = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            log("    from 0x" + r.getFromAddress() + "  [" + (f == null ? "?" : f.getName()) + "]  " + r.getReferenceType());
            n++;
        }
        if (n == 0) log("    (none)");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
