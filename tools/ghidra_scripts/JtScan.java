// JtScan.java — list functions containing computed jumps (jump tables); flag RET 0xc ones.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class JtScan extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/jtscan.txt"));
        log("=== JUMP-TABLE SCAN ===");
        FunctionIterator fi = currentProgram.getFunctionManager().getFunctions(true);
        List<Object[]> rows = new ArrayList<Object[]>();
        while (fi.hasNext()) {
            Function f = fi.next();
            int sz = (int) f.getBody().getNumAddresses();
            if (sz < 40) continue;
            boolean jt = false, retC = false;
            String jtLine = "";
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                String s = ins.toString();
                if (ins.getMnemonicString().equals("JMP") && s.contains("[") && s.contains("*")) { jt = true; jtLine = s; }
                if (ins.getMnemonicString().equals("RET") && s.contains("0xc")) retC = true;
            }
            if (jt) rows.add(new Object[] { f.getName(), f.getEntryPoint().getOffset(), sz, retC, jtLine });
        }
        rows.sort((a, b) -> ((Integer) b[2]) - ((Integer) a[2]));
        log("functions with computed jumps: " + rows.size());
        log("");
        log("  (all, sorted by size desc; RET0xC = takes 3 args = matches (cmd,buf,len))");
        for (Object[] r : rows) {
            log(String.format("  %-22s @0x%08x size=%-7d RET0xC=%-5s  %s", r[0], r[1], r[2], r[3], r[4]));
        }
        log("");
        log("--- only those WITH RET 0xc ---");
        for (Object[] r : rows) {
            if (Boolean.TRUE.equals(r[3])) log(String.format("  %-22s @0x%08x size=%-7d", r[0], r[1], r[2]));
        }
        pw.flush(); pw.close();
        log("=== JT SCAN DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
