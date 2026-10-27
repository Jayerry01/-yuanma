// Slot3.java — resolve each candidate vfptr's slot-3 function and dump its signature/arity.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class Slot3 extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/slot3.txt"));
        Memory mem = currentProgram.getMemory();
        long[] vptrs = { 0x5aa658L, 0x5aa65cL, 0x5aa660L, 0x5aa6a8L, 0x5aa88cL };
        for (long v : vptrs) {
            long t3 = v + 0xc;
            int v3 = mem.getInt(toAddr(t3));
            Function f3 = getFunctionAt(toAddr(v3 & 0xffffffffL));
            log(String.format("vfptr=0x%08x  slot3@0x%08x = 0x%08x %s", v, t3, v3,
                (f3 == null ? "(NO FUNCTION)" : f3.getName())));
            if (f3 != null) {
                decompileToFile(f3);
            }
        }
        pw.flush(); pw.close();
        log("=== SLOT3 DONE ===");
    }

    void decompileToFile(Function f) {
        try {
            ghidra.app.decompiler.DecompInterface di = new ghidra.app.decompiler.DecompInterface();
            di.openProgram(currentProgram);
            ghidra.app.decompiler.DecompileResults dr = di.decompileFunction(f, 60, getMonitor());
            String c = (dr == null ? null : dr.getDecompiledFunction().getC());
            if (c == null) { log("    <decompile failed: " + (dr == null ? "null" : dr.getErrorMessage()) + ">"); return; }
            String[] lines = c.split("\\n");
            // signature line + first 25 body lines
            log("    signature: " + lines[1].trim());
            int n = Math.min(lines.length, 26);
            for (int i = 1; i < n; i++) log("      " + lines[i]);
            log("    ...(total " + lines.length + " lines)");
        } catch (Exception e) {
            log("    <decompile error: " + e + ">");
        }
    }
    void log(String s) { println(s); pw.println(s); }
}
