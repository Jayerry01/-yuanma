// InputObj.java - vtable 0x5aa660 slots 6..20, resolve + dump
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class InputObj extends GhidraScript {
    PrintWriter out;
    long base = 0x005aa660L;

    long ptr(int slot) throws Exception {
        return currentProgram.getMemory().getInt(toAddr(base + slot * 4L)) & 0xffffffffL;
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/inputobj.txt")));
        out.println("########## vtable 0x5aa660 slots 0..22 ##########");
        for (int s = 0; s <= 22; s++) {
            long p = ptr(s);
            String d = "";
            Function f = getFunctionContaining(toAddr(p));
            if (f != null) d = f.getName() + " size=" + f.getBody().getNumAddresses();
            out.println(String.format("  slot %2d (+0x%02x)  -> 0x%08x  %s", s, s * 4, p, d));
        }

        out.println("\n########## FULL DUMP of slots 10,11,12,13 ##########");
        for (int s = 10; s <= 13; s++) {
            long p = ptr(s);
            Function f = getFunctionContaining(toAddr(p));
            if (f == null) { out.println("\n slot " + s + " no func"); continue; }
            out.println("\n== slot " + s + " -> " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " ==");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
                if (++n > 200) { out.println("  ... truncated"); break; }
            }
        }
        out.close();
        println("DONE -> inputobj.txt");
    }
}
