// GetAsync2.java — retry using the reference manager instead of operand scalars.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class GetAsync2 extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/getasync2.txt"));
        Memory mem = currentProgram.getMemory();

        long IAT = 0x5a8258L;
        log("=== symbol at 0x005a8258 ===");
        log("  " + getSymbolAt(toAddr(IAT)));
        log("  bytes: " + Integer.toHexString(mem.getInt(toAddr(IAT))));

        log("");
        log("=== all references TO 0x005a8258 ===");
        ReferenceIterator ri = currentProgram.getReferenceManager().getReferencesTo(toAddr(IAT));
        TreeMap<String, Integer> per = new TreeMap<String, Integer>();
        TreeMap<String, String> info = new TreeMap<String, String>();
        int total = 0;
        while (ri.hasNext()) {
            Reference r = ri.next();
            total++;
            Address from = r.getFromAddress();
            Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
            String name = (f == null ? "(none)" : f.getName());
            Integer c = per.get(name);
            per.put(name, c == null ? 1 : c + 1);
            if (f != null && !info.containsKey(name)) info.put(name, "0x" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
            log("  from 0x" + from + "  " + r.getReferenceType() + "  [" + name + "]");
        }
        log("  total refs = " + total);

        log("");
        log("=== per-function summary ===");
        for (String k : per.keySet()) {
            log(String.format("  %-22s refs=%-3d  %s", k, per.get(k), info.containsKey(k) ? info.get(k) : ""));
        }

        log("");
        log("=== head listing of each owner ===");
        for (String k : per.keySet()) {
            if (!info.containsKey(k)) continue;
            String v = info.get(k);
            Function f = getFunctionAt(toAddr(Long.decode(v.substring(0, v.indexOf(' '))).longValue()));
            if (f == null) continue;
            log("### " + k + "  " + v + "  refs=" + per.get(k));
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (ii.hasNext() && n < 14) { Instruction ins = ii.next(); log("    0x" + ins.getAddress() + "  " + ins.toString()); n++; }
            log("    RET: ");
            InstructionIterator ri2 = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ri2.hasNext()) {
                Instruction ins = ri2.next();
                if (ins.getMnemonicString().startsWith("RET")) log("      0x" + ins.getAddress() + "  " + ins.toString());
            }
            log("");
        }

        pw.flush();
        pw.close();
        log("=== GETASYNC2 DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
