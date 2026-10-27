// Table.java - dump FUN_0045a450 (table provider) + rest of FUN_004bc710 + FUN_004f1960 head
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class Table extends GhidraScript {
    PrintWriter out;
    Listing lst;

    void dump(long va, int max) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("no func " + Long.toHexString(va)); return; }
        out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
            if (max > 0 && ++n >= max) { out.println("  ..."); break; }
        }
    }

    void from(long va, long startAt, int max) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        boolean go = false;
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            if (i.getAddress().getOffset() >= startAt) go = true;
            if (!go) continue;
            out.println("  " + i.getAddress() + "  " + i.toString());
            if (++n >= max) { out.println("  ..."); break; }
        }
    }

    public void run() throws Exception {
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/table.txt")));
        dump(0x0045a450L, 90);
        out.println("\n##### FUN_004bc710 from 0x4bc81a #####");
        from(0x004bc710L, 0x004bc81aL, 70);
        out.println("\n##### FUN_004f1960 head #####");
        dump(0x004f1960L, 25);
        out.close();
        println("DONE -> table.txt");
    }
}
