// LastHop.java — final hop: (1) decompile GameApp slot223 impl 0x489510, (2) its gate slot218,
// (3) trace every write to member offset 0x2410 program-wide, (4) inspect GameApp ctor 0x486610.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class LastHop extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/lasthop2.txt"));
        Memory mem = currentProgram.getMemory();

        long GAMEAPP_VFPTR = 0x5a9068L;

        log("==================== PASS 1: slot 218 (the gate) ====================");
        int s218 = mem.getInt(toAddr(GAMEAPP_VFPTR + 0x368L));
        log("GameApp vfptr 0x005a9068 : slot218 @0x" + Long.toHexString(GAMEAPP_VFPTR + 0x368L)
            + " = 0x" + Integer.toHexString(s218));
        Function g218 = getFunctionAt(toAddr(s218 & 0xffffffffL));
        if (g218 == null) {
            log("  !! NO FUNCTION at that address");
        } else {
            log("  -> " + g218.getName() + "  entry=0x" + g218.getEntryPoint()
                + "  size=" + g218.getBody().getNumAddresses());
            log("  --- full asm ---");
            dumpAsm(g218, 80);
            log("  --- xrefs TO gate ---");
            dumpXrefs(g218.getEntryPoint(), 40);
            log("  --- decompile ---");
            decomp(g218, 200);
        }

        log("");
        log("==================== PASS 2: FUN_00489510 (slot223 impl) ====================");
        Function h = getFunctionAt(toAddr(0x489510L));
        if (h == null) {
            log("!! no function at 0x489510");
        } else {
            log(h.getName() + "  entry=0x" + h.getEntryPoint() + "  size=" + h.getBody().getNumAddresses());
            log("--- asm ---");
            dumpAsm(h, 40);
            log("--- xrefs TO 0x489510 ---");
            dumpXrefs(h.getEntryPoint(), 40);
            log("--- decompile ---");
            decomp(h, 200);
        }

        log("");
        log("==================== PASS 3: every instruction touching displacement 0x2410 ====================");
        InstructionIterator ii = currentProgram.getListing().getInstructions(mem.getExecuteSet(), true);
        int hits = 0;
        while (ii.hasNext() && hits < 120) {
            Instruction ins = ii.next();
            String s = ins.toString();
            if (s.indexOf("0x2410") < 0) continue;
            Function f = currentProgram.getFunctionManager().getFunctionContaining(ins.getAddress());
            log("  0x" + ins.getAddress() + "  " + s + "    [" + (f == null ? "(no func)" : f.getName()) + "]");
            hits++;
        }
        log("  (hits listed: " + hits + ")");

        log("");
        log("==================== PASS 4: GameApp ctor FUN_00486610 ====================");
        Function ctor = getFunctionAt(toAddr(0x486610L));
        if (ctor == null) {
            log("!! no ctor at 0x486610");
        } else {
            log(ctor.getName() + "  size=" + ctor.getBody().getNumAddresses());
            log("--- calls emitted inside ctor (first 120) ---");
            InstructionIterator ci = currentProgram.getListing().getInstructions(ctor.getBody(), true);
            int nc = 0;
            while (ci.hasNext() && nc < 120) {
                Instruction ins = ci.next();
                String mn = ins.getMnemonicString();
                if (!mn.equals("CALL")) continue;
                Address[] flows = ins.getFlows();
                String tgt = (flows.length > 0 ? "" + flows[0] : "?");
                Function tf = (flows.length > 0 ? getFunctionAt(flows[0]) : null);
                log("  0x" + ins.getAddress() + "  CALL " + tgt
                    + (tf == null ? "" : "  (" + tf.getName() + " size=" + tf.getBody().getNumAddresses() + ")"));
                nc++;
            }
            log("--- vtable-pointer constants (>=0x5a0000 <0x5c0000) inside ctor ---");
            InstructionIterator vi = currentProgram.getListing().getInstructions(ctor.getBody(), true);
            while (vi.hasNext()) {
                Instruction ins = vi.next();
                String s = ins.toString();
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof ghidra.program.model.scalar.Scalar) {
                            long v = ((ghidra.program.model.scalar.Scalar) ob).getValue();
                            if (v >= 0x5a0000L && v < 0x5c0000L) {
                                log("  0x" + ins.getAddress() + "  " + s);
                            }
                        }
                    }
                }
            }
            log("--- decompile ctor (head) ---");
            decomp(ctor, 400);
        }

        pw.flush();
        pw.close();
        log("=== LAST HOP DONE ===");
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
