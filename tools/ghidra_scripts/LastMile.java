// LastMile.java - identify FUN_004cd3b0 and the doubles it compares against
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class LastMile extends GhidraScript {
    PrintWriter out;
    Memory mem;

    double dbl(long va) {
        try { return Double.longBitsToDouble(mem.getLong(toAddr(va))); }
        catch (Exception e) { return Double.NaN; }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/lastmile.txt")));

        out.println("########## A: constants ##########");
        for (long va : new long[]{0x005aa8e8L, 0x005a84b8L, 0x005a9d50L, 0x005aa8b0L}) {
            out.println(String.format("  0x%08x  double = %s   raw=%016x", va, dbl(va), mem.getLong(toAddr(va))));
        }

        out.println("\n########## B: FUN_004cd3b0 first 70 instructions ##########");
        Function f = getFunctionContaining(toAddr(0x004cd3b0L));
        out.println("  size=" + f.getBody().getNumAddresses());
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("   " + i.getAddress() + "  " + i.toString());
            if (++n >= 70) { out.println("   ..."); break; }
        }

        out.println("\n########## C: who reads the deadline field +0x28 on the clock? ##########");
        // FP compare against [reg + 0x28]
        Listing lst = currentProgram.getListing();
        for (Function g : lst.getFunctions(true)) {
            InstructionIterator gi = lst.getInstructions(g.getBody(), true);
            while (gi.hasNext()) {
                Instruction i = gi.next();
                String t = i.toString();
                if ((t.startsWith("FCOMP") || t.startsWith("FCOMI")) && t.contains("+ 0x28]")) {
                    out.println("   " + i.getAddress() + "  " + t + "   in " + g.getName());
                }
            }
        }
        out.println("  (none listed above => no direct FP compare on +0x28)");

        out.close();
        println("DONE -> lastmile.txt");
    }
}
