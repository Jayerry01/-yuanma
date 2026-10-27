// Combo.java - 12-state table, float constants, rest of FUN_004cf5b0
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Combo extends GhidraScript {
    PrintWriter out;
    Memory mem;

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/combo.txt")));

        out.println("########## A: the two duration floats ##########");
        for (long va : new long[]{0x005aa93cL, 0x005aa940L, 0x005aa934L, 0x005aa944L}) {
            int i = mem.getInt(toAddr(va));
            out.println(String.format("  0x%08x  float = %s   raw=%08x",
                va, Float.intBitsToFloat(i), i));
        }

        out.println("\n########## B: 12-entry byte index @0x4cf75c and jump table @0x4cf74c ##########");
        StringBuilder idx = new StringBuilder();
        for (int i = 0; i < 12; i++) idx.append(mem.getByte(toAddr(0x004cf75cL + i)) & 0xff).append(" ");
        out.println("  index bytes: " + idx);
        for (int i = 0; i < 12; i++) {
            int v = mem.getInt(toAddr(0x004cf74cL + i * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            out.println(String.format("  case %2d -> 0x%08x  %s", i, p,
                (f != null && f.getEntryPoint().getOffset() == 0x004cf5b0L) ? "(in-func)" : ""));
        }

        out.println("\n########## C: FUN_004cf5b0 from 0x4cf636 to end ##########");
        Function f = getFunctionContaining(toAddr(0x004cf5b0L));
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        boolean go = false;
        while (it.hasNext()) {
            Instruction i = it.next();
            if (i.getAddress().getOffset() >= 0x004cf636L) go = true;
            if (go) out.println("   " + i.getAddress() + "  " + i.toString());
        }
        out.close();
        println("DONE -> combo.txt");
    }
}
