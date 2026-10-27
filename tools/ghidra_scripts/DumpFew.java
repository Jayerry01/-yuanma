// DumpFew.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpFew extends GhidraScript {
    PrintWriter out;
    long[] targets = {0x00503020L, 0x0047ae40L, 0x00549490L, 0x00412120L, 0x00411e10L};

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/dumpfew.txt")));
        for (long va : targets) {
            Function f = getFunctionContaining(toAddr(va));
            if (f == null) { out.println("no func at " + Long.toHexString(va)); continue; }
            out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " =====");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
            }
        }
        out.close();
        println("DONE -> dumpfew.txt");
    }
}
