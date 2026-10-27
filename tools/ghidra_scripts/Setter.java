// Setter.java - FUN_004d0500 as the state setter; who calls it and with what
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class Setter extends GhidraScript {
    PrintWriter out;
    Listing lst;

    void ctx(Function f, long at) throws Exception {
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        int idx = -1;
        for (int i = 0; i < buf.size(); i++) if (buf.get(i).getAddress().getOffset() == at) { idx = i; break; }
        if (idx < 0) { out.println("    (site " + Long.toHexString(at) + " not in " + f.getName() + ")"); return; }
        int lo = Math.max(0, idx - 6), hi = Math.min(buf.size() - 1, idx + 3);
        for (int k = lo; k <= hi; k++)
            out.println((k == idx ? "   >> " : "      ") + buf.get(k).getAddress() + "  " + buf.get(k).toString());
    }

    public void run() throws Exception {
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/setter.txt")));

        out.println("########## A: FUN_004d0500 full body ##########");
        Function f = getFunctionContaining(toAddr(0x004d0500L));
        out.println("  " + f.getName() + " size=" + f.getBody().getNumAddresses());
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) { Instruction i = it.next(); out.println("   " + i.getAddress() + "  " + i.toString()); }

        out.println("\n########## B: callers of FUN_004d0500 ##########");
        int n = 0;
        for (Reference r : getReferencesTo(f.getEntryPoint())) {
            if (!r.getReferenceType().isCall()) continue;
            Function c = getFunctionContaining(r.getFromAddress());
            out.println("\n  call at " + r.getFromAddress() + "  in "
                + (c == null ? "?" : c.getName() + " size=" + c.getBody().getNumAddresses()));
            if (c != null) ctx(c, r.getFromAddress().getOffset());
            n++;
        }
        out.println("\n  total call sites = " + n);

        out.println("\n########## C: FUN_004cafb0 context around 0x4cb0a7 (reset) ##########");
        Function rst = getFunctionContaining(toAddr(0x004cafb0L));
        ctx(rst, 0x004cb0a7L);

        out.close();
        println("DONE -> setter.txt");
    }
}
