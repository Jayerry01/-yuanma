// AttackTail.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class AttackTail extends GhidraScript {
    PrintWriter out;
    long[] t = {0x004cf4c0L, 0x004ce3c0L, 0x004d0d90L, 0x004ce2d0L};

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/attacktail.txt")));
        for (long va : t) {
            Function f = getFunctionContaining(toAddr(va));
            if (f == null) { out.println("no func " + Long.toHexString(va)); continue; }
            out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses() + " =====");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
            }
        }
        out.close();
        println("DONE -> attacktail.txt");
    }
}
