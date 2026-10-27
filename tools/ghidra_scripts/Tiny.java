// Tiny.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class Tiny extends GhidraScript {
    PrintWriter out;
    long[] t = {0x004bc0c0L, 0x004bc0e0L, 0x004bc0f0L, 0x004bc100L, 0x004bc150L, 0x004bc110L};

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/tiny.txt")));
        for (long va : t) {
            Function f = getFunctionContaining(toAddr(va));
            if (f == null) { out.println("no func @ " + Long.toHexString(va)); continue; }
            out.println("\n== " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " ==");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
            }
        }
        out.close();
        println("DONE -> tiny.txt");
    }
}
