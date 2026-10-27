// Scan23D4.java - readers of GameApp +0x23D4/+0x23D8 ; dump FUN_00487450 and FUN_00411190
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class Scan23D4 extends GhidraScript {
    PrintWriter out;

    void dumpFunc(long va, int contextPad) throws Exception {
        Address a = toAddr(va);
        Function f = getFunctionContaining(a);
        if (f == null) { out.println("no function at " + Long.toHexString(va)); return; }
        out.println("\n===== DUMP " + f.getName() + " @ " + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/scan23d4.txt")));

        out.println("########## A: all instructions touching +0x23D4 / +0x23D8 ##########");
        Listing lst = currentProgram.getListing();
        int n = 0;
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String t = ins.toString();
                if (t.contains("0x23d4") || t.contains("0x23d8") || t.contains("0x23D4") || t.contains("0x23D8")) {
                    out.println("  " + ins.getAddress() + "  " + t
                        + "   in " + f.getName() + " size=" + f.getBody().getNumAddresses());
                    n++;
                }
            }
        }
        out.println("total " + n);

        dumpFunc(0x00487450L, 0);
        dumpFunc(0x00411190L, 0);
        dumpFunc(0x00523780L, 0);

        out.close();
        println("DONE -> scan23d4.txt");
    }
}
