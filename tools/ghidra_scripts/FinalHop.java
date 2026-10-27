// FinalHop.java — resolve singleton->vtable[223] candidates and verify arity (expect RET 0x8).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class FinalHop extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/finalhop.txt"));
        Memory mem = currentProgram.getMemory();
        log("=== final hop: singleton->vtable[223] ===");
        long[] vfptrs = { 0x5a9068L, 0x5a9444L };
        for (long v : vfptrs) {
            long t = v + 0x37cL;
            int val = mem.getInt(toAddr(t));
            Function f = getFunctionAt(toAddr(val & 0xffffffffL));
            log(String.format("vfptr 0x%08x : slot223 @0x%08x = 0x%08x %s", v, t, val,
                (f == null ? "(NO FUNCTION)" : f.getName() + " size=" + f.getBody().getNumAddresses())));
            if (f != null) {
                InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
                while (ii.hasNext()) {
                    Instruction ins = ii.next();
                    String mn = ins.getMnemonicString();
                    if (mn.startsWith("RET") || mn.equals("JMP")) log("      exit: " + ins.getAddress() + "  " + ins.toString());
                }
                log("      --- asm ---");
                ii = currentProgram.getListing().getInstructions(f.getBody(), true);
                int n = 0;
                while (ii.hasNext() && n < 40) { Instruction ins = ii.next(); log("        " + ins.getAddress() + "  " + ins.toString()); n++; }
            }
        }
        pw.flush(); pw.close();
        log("=== FINAL HOP DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
