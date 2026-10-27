// Dispatch.java — the fan-out IS a switch (every case JMPs to 0x004cc54f). Find the selector: dump the
// region between the early prologue and the first case, looking for CMP / JZ comparisons and any state
// field read that drives the case choice.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class Dispatch extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/dispatch.txt"));
        log("### region 0x004cc200 .. 0x004cc430 — the selector logic");
        Address lo = toAddr(0x4cc200L), hi = toAddr(0x4cc430L);
        InstructionIterator ii = currentProgram.getListing().getInstructions(lo, true);
        int n = 0;
        while (ii.hasNext() && n < 400) {
            Instruction ins = ii.next();
            if (ins.getAddress().compareTo(hi) > 0) break;
            String mn = ins.getMnemonicString();
            String tag = "";
            if (mn.startsWith("CMP") || mn.startsWith("J") || mn.equals("TEST")) tag = "   <== SELECT";
            log("  0x" + ins.getAddress() + "  " + ins.toString() + tag);
            n++;
        }
        pw.flush();
        pw.close();
        log("=== DISPATCH DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
