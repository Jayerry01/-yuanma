// Terminus.java — member_0x2410 is built by FUN_004C8730 with size 0x118. Resolve its vfptr, dump slot 13,
// and apply the pre-declared stop rule (if slot13 target is itself a pure router, STOP).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;

public class Terminus extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/terminus.txt"));
        Memory mem = currentProgram.getMemory();

        log("==================== A: full asm of the setter FUN_004890a0 (slot 211) ====================");
        Function setter = getFunctionAt(toAddr(0x4890a0L));
        if (setter != null) dumpAsm(setter, 60);

        log("");
        log("==================== B: constructor FUN_004C8730 (builds the 0x118 object) ====================");
        Function ctor = getFunctionAt(toAddr(0x4c8730L));
        if (ctor == null) {
            log("!! no function at 0x4c8730");
        } else {
            log(ctor.getName() + "  size=" + ctor.getBody().getNumAddresses());
            log("--- head asm (first 40) ---");
            dumpAsm(ctor, 40);
            log("--- vtable-pointer constants written inside ctor ---");
            InstructionIterator vi = currentProgram.getListing().getInstructions(ctor.getBody(), true);
            while (vi.hasNext()) {
                Instruction ins = vi.next();
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof Scalar) {
                            long v = ((Scalar) ob).getValue();
                            if (v >= 0x5a0000L && v < 0x5c0000L) {
                                log("  0x" + ins.getAddress() + "  " + ins.toString());
                            }
                        }
                    }
                }
            }
            log("--- xrefs TO ctor ---");
            dumpXrefs(ctor.getEntryPoint(), 20);
            log("--- decompile ctor ---");
            decomp(ctor, 120);
        }

        log("");
        log("==================== C: read slot 13 from every vfptr found in B ====================");
        Function ctor2 = getFunctionAt(toAddr(0x4c8730L));
        if (ctor2 != null) {
            InstructionIterator vi = currentProgram.getListing().getInstructions(ctor2.getBody(), true);
            java.util.TreeSet<Long> seen = new java.util.TreeSet<Long>();
            while (vi.hasNext()) {
                Instruction ins = vi.next();
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof Scalar) {
                            long v = ((Scalar) ob).getValue();
                            if (v >= 0x5a0000L && v < 0x5c0000L) seen.add(v);
                        }
                    }
                }
            }
            for (Long vp : seen) {
                log("### candidate vfptr 0x" + Long.toHexString(vp));
                try {
                    int v13 = mem.getInt(toAddr(vp + 0x34L));
                    Function f13 = getFunctionAt(toAddr(v13 & 0xffffffffL));
                    log(String.format("    slot13 (+0x34) @0x%08x = 0x%08x  %s", vp + 0x34L, v13,
                        f13 == null ? "(NO FUNCTION)" : f13.getName() + " size=" + f13.getBody().getNumAddresses()));
                    if (f13 != null) {
                        InstructionIterator ii = currentProgram.getListing().getInstructions(f13.getBody(), true);
                        int nc = 0;
                        while (ii.hasNext()) nc++;
                        log("    instruction count = " + nc);
                        if (nc <= 30) {
                            log("    --- full asm (router candidate) ---");
                            dumpAsm(f13, 30);
                        } else {
                            log("    --- head asm (first 25) ---");
                            dumpAsm(f13, 25);
                            log("    --- RET sites ---");
                            InstructionIterator ri = currentProgram.getListing().getInstructions(f13.getBody(), true);
                            while (ri.hasNext()) {
                                Instruction ins = ri.next();
                                String mn = ins.getMnemonicString();
                                if (mn.startsWith("RET")) log("      " + ins.getAddress() + "  " + ins.toString());
                            }
                        }
                        log("    --- decompile ---");
                        decomp(f13, 80);
                    }
                } catch (Exception e) {
                    log("    read fail: " + e);
                }
            }
        }

        pw.flush();
        pw.close();
        log("=== TERMINUS DONE ===");
    }

    void dumpAsm(Function f, int max) {
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (ii.hasNext() && n < max) {
            Instruction ins = ii.next();
            log("    0x" + ins.getAddress() + "  " + ins.toString());
            n++;
        }
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

    void decomp(Function f, int maxLines) {
        try {
            ghidra.app.decompiler.DecompInterface di = new ghidra.app.decompiler.DecompInterface();
            di.openProgram(currentProgram);
            ghidra.app.decompiler.DecompileResults dr = di.decompileFunction(f, 60, getMonitor());
            if (dr == null) { log("    <decompile null>"); return; }
            String c = dr.getDecompiledFunction().getC();
            if (c == null) { log("    <decompile failed: " + dr.getErrorMessage() + ">"); return; }
            String[] lines = c.split("\\n");
            int n = Math.min(lines.length, maxLines);
            for (int i = 0; i < n; i++) log("    " + lines[i]);
            log("    ...(total " + lines.length + " lines)");
        } catch (Exception e) {
            log("    <decompile error: " + e + ">");
        }
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
