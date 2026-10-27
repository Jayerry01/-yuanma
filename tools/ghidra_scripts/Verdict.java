// Verdict.java - settle 0.11's unit (0x549b00 body) and the slot base for cmd 0x1d
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Verdict extends GhidraScript {
    PrintWriter out;

    String name(Memory mem, long base, int slot) throws Exception {
        int v = mem.getInt(toAddr(base + slot * 4L));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        return String.format("base 0x%08x slot %2d (+0x%03x) -> 0x%08x  %s",
            base, slot, slot * 4, p, f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses());
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/verdict.txt")));

        out.println("########## A: FUN_00549b00 body (does it return seconds or a ratio?) ##########");
        Function f = getFunctionContaining(toAddr(0x00549b00L));
        out.println("  size=" + f.getBody().getNumAddresses());
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) { Instruction i = it.next(); out.println("   " + i.getAddress() + "  " + i.toString()); }

        out.println("\n########## B: slot +0x7c (+0x104/+0x108) on BOTH candidate bases ##########");
        out.println("  " + name(mem, 0x005aa658L, 31));
        out.println("  " + name(mem, 0x005aa6a8L, 31));
        out.println("  " + name(mem, 0x005aa658L, 65));
        out.println("  " + name(mem, 0x005aa658L, 66));
        out.println("  " + name(mem, 0x005aa6a8L, 65));
        out.println("  " + name(mem, 0x005aa6a8L, 66));

        out.println("\n########## C: what actually sits at 0x5AA6D4 / 0x5AA724 ##########");
        for (long a : new long[]{0x005aa6d4L, 0x005aa724L}) {
            int v = mem.getInt(toAddr(a));
            long p = v & 0xffffffffL;
            Function g = getFunctionContaining(toAddr(p));
            out.println(String.format("  [0x%08x] = 0x%08x  %s", a, p, g == null ? "?" : g.getName() + " size=" + g.getBody().getNumAddresses()));
        }
        out.close();
        println("DONE -> verdict.txt");
    }
}
