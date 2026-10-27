// Source.java - FUN_004ce230 (A.slot19) the value source; confirm slot19 binding
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Source extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/source.txt")));

        out.println("########## slot bindings ##########");
        int[] slots = {19, 75};
        for (int s : slots) {
            int v = mem.getInt(toAddr(0x005aa6a8L + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            out.println(String.format("  A.slot %d (+0x%02x) -> 0x%08x  %s", s, s * 4, p,
                f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
        }

        out.println("\n########## FUN_004ce230 full body ##########");
        Function f = getFunctionContaining(toAddr(0x004ce230L));
        if (f != null) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) { Instruction i = it.next(); out.println("   " + i.getAddress() + "  " + i.toString()); }
        }

        out.println("\n########## who writes [A+0x35c] (the gate) ##########");
        for (Function g : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(g.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (t.startsWith("MOV") && t.contains("[ESI + 0x35c]") || t.startsWith("MOV") && t.contains("[EDI + 0x35c]")) {
                    out.println("   " + i.getAddress() + "  " + t + "   in " + g.getName()
                        + " size=" + g.getBody().getNumAddresses());
                }
            }
        }
        out.close();
        println("DONE -> source.txt");
    }
}
