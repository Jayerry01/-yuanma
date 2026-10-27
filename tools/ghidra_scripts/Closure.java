// Closure.java - slot of FUN_004cd3b0, its callers, and dump slot 65 (FUN_004cf540)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class Closure extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/closure.txt")));
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();

        out.println("########## A: which slot of 0x5aa6a8 holds FUN_004cd3b0 ##########");
        long base = 0x005aa6a8L;
        for (int s = 0; s < 200; s++) {
            int v;
            try { v = mem.getInt(toAddr(base + s * 4L)); } catch (Exception e) { break; }
            if ((v & 0xffffffffL) == 0x004cd3b0L) {
                out.println(String.format("  slot %d (+0x%03x) -> 0x004cd3b0", s, s * 4));
            }
        }

        out.println("\n########## B: callers of FUN_004cd3b0 ##########");
        int c = 0;
        for (Reference r : getReferencesTo(toAddr(0x004cd3b0L))) {
            Function f = getFunctionContaining(r.getFromAddress());
            out.println("  " + r.getFromAddress() + " " + r.getReferenceType()
                + "  in " + (f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
            c++;
        }
        out.println("  total refs = " + c);

        out.println("\n########## C: slot 65 target (FUN_004cf540) ##########");
        Function g = getFunctionContaining(toAddr(0x004cf540L));
        if (g != null) {
            out.println("  " + g.getName() + " size=" + g.getBody().getNumAddresses());
            InstructionIterator it = lst.getInstructions(g.getBody(), true);
            while (it.hasNext()) { Instruction i = it.next(); out.println("   " + i.getAddress() + "  " + i.toString()); }
        }

        out.println("\n########## D: FCOMP sites on clock fields (+0x10 / +0x28 / +0x40) ##########");
        for (Function f : lst.getFunctions(true)) {
            long e = f.getEntryPoint().getOffset();
            if (e < 0x004ca000L || e > 0x004d1000L) continue;
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (t.startsWith("FCOMP") && (t.contains("+ 0x10]") || t.contains("+ 0x28]") || t.contains("+ 0x40]"))) {
                    out.println("   " + i.getAddress() + "  " + t + "   in " + f.getName());
                }
            }
        }
        out.close();
        println("DONE -> closure.txt");
    }
}
