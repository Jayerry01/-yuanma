// VPtrWrites.java — list all constructor writes of a vptr inside the big vtable region.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class VPtrWrites extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/vptr_writes.txt"));
        log("=== VPTR WRITES into region 0x5aa640..0x5aa8d0 ===");
        long lo = 0x5aa640L, hi = 0x5aa8d0L;
        Listing listing = currentProgram.getListing();
        Map<Long, Integer> hits = new TreeMap<Long, Integer>();
        InstructionIterator it = listing.getInstructions(currentProgram.getMemory().getExecuteSet(), true);
        long n = 0;
        while (it.hasNext()) {
            Instruction ins = it.next();
            n++;
            Address at = ins.getAddress();
            for (int o = 0; o < ins.getNumOperands(); o++) {
                Object[] opObjs = ins.getOpObjects(o);
                for (Object oo : opObjs) {
                    if (oo instanceof Scalar) {
                        long v = ((Scalar) oo).getValue();
                        if (v >= lo && v <= hi) {
                            Function f = currentProgram.getFunctionManager().getFunctionContaining(at);
                            log("  0x" + at + "  " + ins.toString() + (f != null ? "   [in " + f.getName() + "]" : ""));
                            hits.put(v, hits.getOrDefault(v, 0) + 1);
                        }
                    }
                }
            }
        }
        log("");
        log("=== distinct vptr values written, ranked ===");
        List<Map.Entry<Long, Integer>> l = new ArrayList<>(hits.entrySet());
        l.sort((a, b) -> b.getValue() - a.getValue());
        for (Map.Entry<Long, Integer> e : l) {
            log(String.format("  0x%08x written %d time(s)", e.getKey(), e.getValue()));
        }
        log("instructions scanned: " + n);
        pw.flush(); pw.close();
        log("=== VPTR WRITES DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
