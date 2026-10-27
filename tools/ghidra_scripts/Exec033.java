// Exec033.java — resolve the concrete receiver class of the command dispatcher and its slot-122 handler.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class Exec033 extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/exec033.txt"));
        Memory mem = currentProgram.getMemory();
        long codeLo = 0x401000L, codeHi = 0x5a72bdL;
        long TARGET = 0x004bb800L;
        log("=== resolve concrete receiver class for FUN_004bb800 ===");

        // find base B where mem[B+0x20] == TARGET
        for (MemoryBlock blk : mem.getBlocks()) {
            if (!blk.isInitialized() || blk.isExecute()) continue;
            long off = 0, size = blk.getSize();
            while (off + 4 <= size) {
                long a = blk.getStart().add(off).getOffset();
                try {
                    int v = mem.getInt(toAddr(a));
                    if ((v & 0xffffffffL) == TARGET) {
                        long base = a - 0x20;
                        log("found base candidate 0x" + Long.toHexString(base) + " (mem[0x" + Long.toHexString(base) + "+0x20] == 0x4bb800)");
                        // sanity: base should be preceded by >= 8 consecutive function pointers
                        int ok = 0;
                        for (int i = 1; i <= 8; i++) {
                            int pv = mem.getInt(toAddr(base - 4L * i));
                            Function ff = getFunctionAt(toAddr(pv & 0xffffffffL));
                            if (ff != null) ok++;
                        }
                        log("   preceding valid function pointers: " + ok + "/8");
                        if (ok >= 6) {
                            log("   --- slot map of this class ---");
                            for (int s : new int[] {0,1,2,3,8,18,19,26,28,31,41,46,48,49,51,59,60,77,84,87,90,106,112,120,121,122}) {
                                int vv = mem.getInt(toAddr(base + 4L * s));
                                Function fv = getFunctionAt(toAddr(vv & 0xffffffffL));
                                log(String.format("     slot %-4d (0x%08x) = 0x%08x %s", s, base + 4L*s, vv, (fv==null?"(no func)":fv.getName())));
                            }
                            log("   *** cmd 0x33 handler -> slot 122 = " + String.format("0x%08x", mem.getInt(toAddr(base + 0x1e8L))));
                            int v122 = mem.getInt(toAddr(base + 0x1e8L));
                            Function h = getFunctionAt(toAddr(v122 & 0xffffffffL));
                            if (h != null) { log("      -> " + h.getName() + "  size=" + h.getBody().getNumAddresses()); dumpAsm(h); }
                        }
                    }
                } catch (Exception e) { /* skip */ }
                off += 4;
            }
        }
        pw.flush(); pw.close();
        log("=== EXEC033 DONE ===");
    }
    void dumpAsm(Function f) {
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (ii.hasNext() && n < 60) {
            Instruction ins = ii.next();
            log("        " + ins.getAddress() + "  " + ins.toString());
            n++;
        }
        log("        ... (total " + f.getBody().getNumAddresses() + " bytes)");
    }
    void log(String s) { println(s); pw.println(s); }
}
