// RangeDump.java - dump address ranges + FUN_0045a450
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class RangeDump extends GhidraScript {
    PrintWriter out;

    void range(long from, long to) throws Exception {
        Address a = toAddr(from), b = toAddr(to);
        out.println("\n===== RANGE " + Long.toHexString(from) + " - " + Long.toHexString(to) + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(a, true);
        while (it.hasNext()) {
            Instruction i = it.next();
            if (i.getAddress().compareTo(b) > 0) break;
            Function f = getFunctionContaining(i.getAddress());
            out.println("  " + i.getAddress() + "  " + i.toString()
                + (f == null ? "" : "    [" + f.getName() + "]"));
        }
    }

    void func(long va) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("no func " + Long.toHexString(va)); return; }
        out.println("\n===== FUNC " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/rangedump.txt")));
        range(0x004160f0L, 0x00416300L);
        range(0x00417140L, 0x00417240L);
        func(0x0045a450L);
        out.close();
        println("DONE -> rangedump.txt");
    }
}
