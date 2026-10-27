// GameApp4.java - slots 214..228 of GameApp vtable 0x5a9068; dump targets of 220..223
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class GameApp4 extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/gameapp4.txt")));
        Memory mem = currentProgram.getMemory();
        long base = 0x005a9068L;

        out.println("########## GameApp vtable 0x5a9068 slots 214..228 ##########");
        for (int s = 214; s <= 228; s++) {
            Address a = toAddr(base + s * 4L);
            int v = mem.getInt(a);
            long p = v & 0xffffffffL;
            String d = "";
            Function f = getFunctionContaining(toAddr(p));
            if (f != null) d = f.getName() + " size=" + f.getBody().getNumAddresses();
            out.println(String.format("  slot %3d (+0x%03x)  @0x%08x  -> 0x%08x  %s",
                s, s * 4, base + s * 4L, p, d));
        }

        out.println("\n########## FULL DUMP of slots 220..223 targets ##########");
        for (int s = 220; s <= 223; s++) {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            if (f == null) { out.println("\n slot " + s + " -> 0x" + Long.toHexString(p) + " (no func)"); continue; }
            out.println("\n== slot " + s + " -> " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " ==");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
                if (++n > 260) { out.println("  ... truncated"); break; }
            }
        }
        out.close();
        println("DONE -> gameapp4.txt");
    }
}
