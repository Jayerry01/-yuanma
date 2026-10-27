// TraceEv2.java — who uses vtable 0x005aa664, and dump sender asm bodies.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class TraceEv2 extends GhidraScript {
    PrintWriter pw;
    String OUT = "D:/MeteorProjects/_private/ghidra_scripts/";

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter(OUT + "trace_ev2.txt"));
        log("=== TRACE EV2 ===");

        // ---- who references the vtable address 0x005aa664 ----
        Address vtab = toAddr(0x005aa664L);
        log("");
        log("=== XREFS TO vtable 0x005aa664 ===");
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(vtab);
        int n = 0;
        while (rit.hasNext() && n < 80) {
            Reference r = rit.next();
            Address from = r.getFromAddress();
            Instruction ins = currentProgram.getListing().getInstructionContaining(from);
            Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
            log("  from 0x" + from + "  type=" + r.getReferenceType() +
                (ins != null ? ("  instr=" + ins.toString()) : "") +
                (f != null ? ("  [in " + f.getName() + "]") : ""));
            n++;
        }
        log("  (shown " + n + ")");

        // ---- also: any load of immediate 0x5aa664 anywhere ----
        log("");
        log("=== functions whose body mentions 5aa664 (immediate) ===");
        // covered by xrefs above

        // ---- dump asm bodies for senders & vtable members ----
        int[] targets = { 0x4cb260, 0x4d0ac0, 0x4cf5b0, 0x4cd200, 0x4c8a70, 0x4c8f60, 0x4c88a0 };
        for (int t : targets) {
            Function f = getFunctionAt(toAddr(t));
            if (f == null) { log("NO FUNCTION at 0x" + Integer.toHexString(t)); continue; }
            String fn = OUT + "dis_" + Integer.toHexString(t) + ".txt";
            PrintWriter fw = new PrintWriter(new FileWriter(fn));
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            int c = 0;
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                String line = ins.getAddress() + "  " + ins.toString();
                for (Object o : ins.getReferencesFrom()) {
                    Reference rr = (Reference) o;
                    Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(rr.getToAddress());
                    line += "   ; <= " + rr.getToAddress() + (sym != null ? " " + sym.getName() : "");
                }
                fw.println(line);
                c++;
            }
            fw.close();
            log("  dumped " + f.getName() + " -> dis_" + Integer.toHexString(t) + ".txt  instrs=" + c +
                "  size=" + f.getBody().getNumAddresses());
        }

        pw.flush(); pw.close();
        log("=== TRACE EV2 DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
