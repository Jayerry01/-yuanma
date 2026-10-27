// Sched.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class Sched extends GhidraScript {
    PrintWriter out;
    long[] t = {0x005498c0L, 0x00549a90L};

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/sched.txt")));
        for (long va : t) {
            Function f = getFunctionContaining(toAddr(va));
            if (f == null) { out.println("no func " + Long.toHexString(va)); continue; }
            out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " =====");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
                if (++n > 140) { out.println("  ... truncated"); break; }
            }
        }
        out.close();
        println("DONE -> sched.txt");
    }
}
