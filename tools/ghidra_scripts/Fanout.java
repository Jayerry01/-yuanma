// Fanout.java — before round 7 assumes "+0xCC..+0xF0 ten slots of ONE object = weapon-type dispatch",
// verify the dispatch register identity. Dump the whole fan-out window 0x4cc419..0x4cc549 with every
// instruction that SETS eax/edx, so we can tell whether one object or two are being called.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class Fanout extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/fanout.txt"));
        Function f = getFunctionAt(toAddr(0x4cc130L));
        if (f == null) { log("!! no func"); pw.flush(); pw.close(); return; }

        log("### fan-out window 0x004cc3f0 .. 0x004cc560 inside FUN_004cc130");
        Address lo = toAddr(0x4cc3f0L), hi = toAddr(0x4cc560L);
        InstructionIterator ii = currentProgram.getListing().getInstructions(lo, true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            if (ins.getAddress().compareTo(hi) > 0) break;
            String s = ins.toString();
            String mn = ins.getMnemonicString();
            String tag = "";
            if (mn.equals("MOV") && (s.contains("EAX,") || s.contains("EDX,") || s.contains("ECX,"))) tag = "  <-- REG SET";
            if (mn.equals("CALL")) tag = "  <=== CALL";
            log("  0x" + ins.getAddress() + "  " + s + tag);
        }

        log("");
        log("### and the earlier part of the body, for where the object pointers come from");
        Address lo2 = f.getBody().getMinAddress(), hi2 = toAddr(0x4cc420L);
        InstructionIterator ji = currentProgram.getListing().getInstructions(lo2, true);
        int n = 0;
        while (ji.hasNext() && n < 60) {
            Instruction ins = ji.next();
            if (ins.getAddress().compareTo(hi2) > 0) break;
            log("  0x" + ins.getAddress() + "  " + ins.toString());
            n++;
        }

        pw.flush();
        pw.close();
        log("=== FANOUT DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
