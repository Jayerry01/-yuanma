// ButtonSampler.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;

public class ButtonSampler extends GhidraScript {
    PrintWriter out;

    void func(long va) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("no func " + Long.toHexString(va)); return; }
        out.println("\n===== " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/buttonsampler.txt")));
        func(0x004cb5f0L);
        func(0x004cb820L);
        out.close();
        println("DONE -> buttonsampler.txt");
    }
}
