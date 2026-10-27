// Slot24.java - A.vtable slots 20..30, resolve
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Slot24 extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/slot24.txt")));
        Memory mem = currentProgram.getMemory();
        long base = 0x005aa6a8L;
        out.println("########## A vtable 0x5aa6a8 slots 18..34 ##########");
        for (int s = 18; s <= 34; s++) {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            String d = "";
            Function f = getFunctionContaining(toAddr(p));
            if (f != null) d = f.getName() + " size=" + f.getBody().getNumAddresses();
            out.println(String.format("  slot %2d (A+0x%02x)  -> 0x%08x  %s", s, s * 4, p, d));
        }
        out.println("\n########## dump slot 24 target ##########");
        int v = mem.getInt(toAddr(base + 24 * 4L));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        if (f == null) out.println(" no func");
        else {
            out.println(" " + f.getName() + " size=" + f.getBody().getNumAddresses());
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("   " + i.getAddress() + "  " + i.toString());
                if (++n > 90) { out.println("   ..."); break; }
            }
        }
        out.close();
        println("DONE -> slot24.txt");
    }
}
