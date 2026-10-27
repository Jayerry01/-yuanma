// Landing.java - verify the third base and dump FUN_004bc710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class Landing extends GhidraScript {
    PrintWriter out;
    Memory mem;

    void rd(long addr) throws Exception {
        int v = mem.getInt(toAddr(addr));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        out.println(String.format("  [0x%08x] = 0x%08x  %s", addr, p,
            f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/landing.txt")));

        out.println("########## A: the three candidate bases, slot 31 (+0x7c) ##########");
        rd(0x005aa658L + 0x7CL);
        rd(0x005aa6a8L + 0x7CL);
        rd(0x005a9fe0L + 0x7CL);

        out.println("\n########## B: the +0x104 / +0x154 correction ##########");
        out.println("  canonical base 0x5AA658:");
        rd(0x005aa658L + 0x104L);
        rd(0x005aa658L + 0x154L);
        out.println("  subobject base 0x5AA6A8:");
        rd(0x005aa6a8L + 0x104L);

        out.println("\n########## C: case 0x33 cross-check (why 0x5A9FE0 is the base) ##########");
        out.println("  0x5A9FE0 + 0x1E8 (slot 122) should be FUN_004BC100:");
        rd(0x005a9fe0L + 0x1E8L);

        out.println("\n########## D: FUN_004bc710 full body ##########");
        Function f = getFunctionContaining(toAddr(0x004bc710L));
        out.println("  " + f.getName() + " size=" + f.getBody().getNumAddresses());
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("   " + i.getAddress() + "  " + i.toString());
            if (++n > 150) { out.println("   ..."); break; }
        }

        out.println("\n########## E: references to FUN_004bc710 ##########");
        for (Reference r : getReferencesTo(f.getEntryPoint())) {
            Function c = getFunctionContaining(r.getFromAddress());
            out.println("   " + r.getFromAddress() + " " + r.getReferenceType()
                + "  in " + (c == null ? "?" : c.getName()));
        }
        out.close();
        println("DONE -> landing.txt");
    }
}
