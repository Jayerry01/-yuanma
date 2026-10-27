// Reader.java - context around +0xe8 sites in A-class functions; dump FP timer predicates + callers
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class Reader extends GhidraScript {
    PrintWriter out;
    Listing lst;

    void ctx(long entry, int before, int after) throws Exception {
        Function f = getFunctionContaining(toAddr(entry));
        if (f == null) { out.println("  no func @ " + Long.toHexString(entry)); return; }
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        out.println("\n== " + f.getName() + " size=" + f.getBody().getNumAddresses() + " ==");
        for (int i = 0; i < buf.size(); i++) {
            if (!buf.get(i).toString().contains("+ 0xe8]")) continue;
            int lo = Math.max(0, i - before), hi = Math.min(buf.size() - 1, i + after);
            out.println("  --- hit @" + buf.get(i).getAddress() + " ---");
            for (int k = lo; k <= hi; k++) {
                out.println((k == i ? "  >> " : "     ") + buf.get(k).getAddress() + "  " + buf.get(k).toString());
            }
        }
    }

    void dump(long va) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("no func " + Long.toHexString(va)); return; }
        out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) { Instruction i = it.next(); out.println("  " + i.getAddress() + "  " + i.toString()); }
        out.println("  -- callers:");
        for (Reference r : getReferencesTo(f.getEntryPoint())) {
            if (!r.getReferenceType().isCall()) continue;
            Function c = getFunctionContaining(r.getFromAddress());
            out.println("     " + r.getFromAddress() + "  in " + (c == null ? "?" :
                c.getName() + " size=" + c.getBody().getNumAddresses()));
        }
    }

    public void run() throws Exception {
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/reader.txt")));

        for (long e : new long[]{0x004cada0L, 0x004cafb0L, 0x004cc130L, 0x004cd3b0L, 0x0048a4f0L})
            ctx(e, 8, 8);

        dump(0x00549950L);
        dump(0x005499a0L);
        out.close();
        println("DONE -> reader.txt");
    }
}
