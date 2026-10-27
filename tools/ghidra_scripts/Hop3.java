// Hop3.java - resolve vtable[17] (+0x44) on 0x5A9FE0 and what it returns
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Hop3 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    void slot(long base, int s) throws Exception {
        long a = base + s * 4L;
        int v = mem.getInt(toAddr(a));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        // print raw encoding of the vtable dword for provenance
        out.println(String.format("  base 0x%08x slot %3d (+0x%03x) @0x%08x -> 0x%08x  %s",
            base, s, s * 4, a, p, f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
    }

    void dump(long va, int max) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("  no func " + Long.toHexString(va)); return; }
        out.println("\n===== " + f.getName() + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            StringBuilder b = new StringBuilder();
            try {
                byte[] bs = i.getBytes();
                for (byte x : bs) b.append(String.format("%02x ", x & 0xff));
            } catch (Exception e) { b.append("??"); }
            out.println("  " + i.getAddress() + "  " + String.format("%-42s", b.toString().trim()) + "  " + i.toString());
            if (max > 0 && ++n >= max) { out.println("  ..."); break; }
        }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/hop3.txt")));

        out.println("########## A: slots on the command receiver base 0x5A9FE0 ##########");
        for (int s : new int[]{17, 109, 31, 122}) slot(0x005a9fe0L, s);

        out.println("\n########## B: body of slot 17 (+0x44) ##########");
        int v = mem.getInt(toAddr(0x005a9fe0L + 17 * 4L));
        long p = v & 0xffffffffL;
        dump(p, 40);

        out.println("\n########## C: body of slot 109 (+0x1b4) on the same base, for comparison ##########");
        int v2 = mem.getInt(toAddr(0x005a9fe0L + 109 * 4L));
        dump(v2 & 0xffffffffL, 30);

        out.close();
        println("DONE -> hop3.txt");
    }
}
