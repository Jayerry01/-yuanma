// Singleton.java — find the singleton class vtable from its constructor 0x486610, then read slot 223.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;

public class Singleton extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/singleton.txt"));
        Memory mem = currentProgram.getMemory();
        log("=== singleton class resolution ===");
        Function ctor = getFunctionAt(toAddr(0x486610L));
        log("ctor FUN_00486610 size=" + ctor.getBody().getNumAddresses());
        log("");
        log("### vptr writes inside constructor ###");
        InstructionIterator ii = currentProgram.getListing().getInstructions(ctor.getBody(), true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            for (int o = 0; o < ins.getNumOperands(); o++) {
                for (Object ob : ins.getOpObjects(o)) {
                    if (ob instanceof Scalar) {
                        long v = ((Scalar) ob).getValue();
                        if (v >= 0x5a0000L && v < 0x5c0000L) {
                            log("  0x" + ins.getAddress() + "  " + ins.toString());
                        }
                    }
                }
            }
        }
        log("");
        log("### probe slot 223 (0x37c) of the biggest vtable candidates ###");
        long[] bases = { 0x5a84d0L, 0x5a9068L, 0x5a9268L, 0x5a9fe0L, 0x5ab180L, 0x5aab00L };
        for (long b : bases) {
            try {
                int v0 = mem.getInt(toAddr(b));
                int v223 = mem.getInt(toAddr(b + 0x37cL));
                int v222 = mem.getInt(toAddr(b + 0x378L));
                Function f0 = getFunctionAt(toAddr(v0 & 0xffffffffL));
                Function f222 = getFunctionAt(toAddr(v222 & 0xffffffffL));
                Function f223 = getFunctionAt(toAddr(v223 & 0xffffffffL));
                log(String.format("  base 0x%08x  s0=%s  s222(+0x378)=%s  s223(+0x37c)=0x%08x %s",
                    b, (f0 == null ? "?" : f0.getName()),
                    (f222 == null ? "?" : f222.getName()),
                    v223, (f223 == null ? "(no func)" : f223.getName() + " size=" + f223.getBody().getNumAddresses())));
            } catch (Exception e) { log("  base 0x" + Long.toHexString(b) + " read fail"); }
        }
        pw.flush(); pw.close();
        log("=== SINGLETON DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
