// Gate.java - dump the 3-byte variant
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;

public class Gate extends GhidraScript {
    public void run() throws Exception {
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/gate.txt")));
        for (long va : new long[]{0x004e40d0L, 0x004f5860L, 0x004e4070L}) {
            Function f = getFunctionContaining(toAddr(va));
            out.println("\n== 0x" + Long.toHexString(va) + " " + (f == null ? "?" : f.getName()
                + " size=" + f.getBody().getNumAddresses()) + " ==");
            if (f == null) continue;
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                StringBuilder b = new StringBuilder();
                try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
                out.println("   " + i.getAddress() + "  " + String.format("%-20s", b.toString().trim()) + "  " + i.toString());
            }
        }
        out.close();
        println("DONE -> gate.txt");
    }
}
