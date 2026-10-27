// GetAsync.java — docs/07 claim [06] says GetAsyncKeyState appears in only 2 contexts and takes no part
// in combat input. Cross-check: enumerate EVERY reader of the IAT slot 0x005a8258 and count calls per
// function, then report each owning function's identity signals.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class GetAsync extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/getasync.txt"));
        Memory mem = currentProgram.getMemory();

        long IAT = 0x5a8258L;
        log("=== all readers of IAT slot 0x005a8258 (GetAsyncKeyState) ===");
        TreeMap<String, int[]> per = new TreeMap<String, int[]>();
        TreeMap<String, String> entry = new TreeMap<String, String>();

        InstructionIterator ii = currentProgram.getListing().getInstructions(mem.getExecuteSet(), true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            boolean hit = false;
            for (int o = 0; o < ins.getNumOperands(); o++) {
                for (Object ob : ins.getOpObjects(o)) {
                    if (ob instanceof ghidra.program.model.scalar.Scalar
                        && ((ghidra.program.model.scalar.Scalar) ob).getValue() == IAT) hit = true;
                }
            }
            Address[] fl = ins.getFlows();
            if (!hit && fl.length > 0 && fl[0].getOffset() == IAT) hit = true;
            if (!hit) continue;

            Function f = currentProgram.getFunctionManager().getFunctionContaining(ins.getAddress());
            String name = (f == null ? "(none)@0x" + ins.getAddress() : f.getName());
            int[] n = per.get(name);
            if (n == null) per.put(name, new int[]{1});
            else n[0]++;
            if (f != null && !entry.containsKey(name))
                entry.put(name, "0x" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
        }

        for (String k : per.keySet()) {
            String head = (entry.containsKey(k) ? entry.get(k) : "scattered");
            log(String.format("  %-20s calls=%-3d  %s", k, per.get(k)[0], head));
        }

        log("");
        log("=== per-function detail for the owners worth naming ===");
        for (String k : per.keySet()) {
            String e = entry.get(k);
            if (e == null) continue;
            Address a = toAddr(Long.decode(e.substring(0, e.indexOf(' '))).longValue());
            Function f = getFunctionAt(a);
            if (f == null) continue;
            log("### " + k + "  " + e + "  calls=" + per.get(k)[0]);
            log("    --- xrefs TO this function ---");
            ghidra.program.model.symbol.ReferenceIterator ri =
                currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
            int n = 0;
            while (ri.hasNext() && n < 12) {
                ghidra.program.model.symbol.Reference r = ri.next();
                Function src = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
                log("      from 0x" + r.getFromAddress() + "  [" + (src == null ? "?" : src.getName()) + "]");
                n++;
            }
            if (n == 0) log("      (none)");
            log("    --- first 12 insns ---");
            InstructionIterator ji = currentProgram.getListing().getInstructions(f.getBody(), true);
            int m = 0;
            while (ji.hasNext() && m < 12) { Instruction ins = ji.next(); log("      0x" + ins.getAddress() + "  " + ins.toString()); m++; }
            log("");
        }

        pw.flush();
        pw.close();
        log("=== GETASYNC DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
