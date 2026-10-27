// Cmd3035.java - name the cmd 0x30 / 0x35 landing slots
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Cmd3035 extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/cmd3035.txt")));
        long base = 0x005aa6a8L;
        for (int s = 14; s <= 20; s++) {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            out.println(String.format("  slot %2d (+0x%02x) -> 0x%08x  %s", s, s * 4, p,
                f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
        }
        out.println("\n== slot 16 (cmd 0x30 target) ==");
        int a = mem.getInt(toAddr(base + 16 * 4L));
        Function fa = getFunctionContaining(toAddr(a & 0xffffffffL));
        if (fa != null) {
            InstructionIterator it = lst.getInstructions(fa.getBody(), true);
            int n = 0;
            while (it.hasNext() && n++ < 40) out.println("   " + it.next());
        }
        out.println("\n== slot 18 (cmd 0x35 target) ==");
        int b = mem.getInt(toAddr(base + 18 * 4L));
        Function fb = getFunctionContaining(toAddr(b & 0xffffffffL));
        if (fb != null) {
            InstructionIterator it = lst.getInstructions(fb.getBody(), true);
            int n = 0;
            while (it.hasNext() && n++ < 40) out.println("   " + it.next());
        }
        out.close();
        println("DONE -> cmd3035.txt");
    }
}
