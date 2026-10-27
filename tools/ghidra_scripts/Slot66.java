// Slot66.java - read A.vtable[66] (+0x108) and dump it; also slots 96, 80 for context
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Slot66 extends GhidraScript {
    PrintWriter out;
    long base = 0x005aa6a8L;

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/slot66.txt")));

        out.println("########## A: A.vtable selected slots ##########");
        int[] want = {58, 65, 66, 80, 96};
        for (int s : want) {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            out.println(String.format("  slot %2d (+0x%03x) @0x%08x -> 0x%08x  %s",
                s, s * 4, base + s * 4L, p,
                f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
        }

        out.println("\n########## B: dump slot 66 target ##########");
        int v = mem.getInt(toAddr(base + 66 * 4L));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        if (f == null) out.println("  no func");
        else {
            out.println("  " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses());
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("   " + i.getAddress() + "  " + i.toString());
                if (++n > 110) { out.println("   ..."); break; }
            }
        }
        out.close();
        println("DONE -> slot66.txt");
    }
}
