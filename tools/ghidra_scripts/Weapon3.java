// Weapon3.java - dump two 51-byte ctor thunks
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;

public class Weapon3 extends GhidraScript {
    PrintWriter out;

    void d(long va) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        out.println("\n== 0x" + Long.toHexString(va) + " " + (f == null ? "?" : f.getName()
            + " size=" + f.getBody().getNumAddresses()) + " ==");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            StringBuilder b = new StringBuilder();
            try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
            out.println("  " + i.getAddress() + "  " + String.format("%-32s", b.toString().trim()) + "  " + i.toString());
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/weapon3.txt")));
        d(0x004dd320L);
        d(0x004e0770L);
        out.close();
        println("DONE -> weapon3.txt");
    }
}
