// Terminus3.java — the queue at member+0x28 (8-byte entries) is written by slot13. Find who CONSUMES it:
// dump all slots of vfptr 0x5aa660, then for every substantial method look for iteration over begin(0x28)/end(0x2c)
// with an 8-byte step (the vector walk).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Terminus3 extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/terminus3.txt"));
        Memory mem = currentProgram.getMemory();

        long VF = 0x5aa660L;
        log("==================== A: full slot map of vfptr 0x005aa660 ====================");
        TreeMap<Long, Long> portMethods = new TreeMap<Long, Long>(); // slot -> target
        for (long s = 0; s < 150; s++) {
            long addr = VF + s * 4L;
            long v;
            try { v = mem.getInt(toAddr(addr)) & 0xffffffffL; } catch (Exception e) { break; }
            Function f = getFunctionAt(toAddr(v));
            if (f == null) continue;
            long sz = f.getBody().getNumAddresses();
            portMethods.put(s, v);
            log(String.format("  slot %-4d (+0x%-4x) = 0x%08x %-16s size=%d", s, s * 4, v, f.getName(), sz));
        }

        log("");
        log("==================== B: methods that walk the queue (read 0x28/0x2c with +8 step) ====================");
        for (Long slot : portMethods.keySet()) {
            Function f = getFunctionAt(toAddr(portMethods.get(slot)));
            if (f == null) continue;
            if (f.getBody().getNumAddresses() < 40) continue;
            // count evidence inside body
            int readBegin = 0, readEnd = 0, step8 = 0, cmpLoop = 0;
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                String s = ins.toString();
                if (s.contains("+ 0x28]") || s.contains("+0x28]")) readBegin++;
                if (s.contains("+ 0x2c]") || s.contains("+0x2c]")) readEnd++;
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof Scalar && ((Scalar) ob).getValue() == 8L) {
                            if (ins.getMnemonicString().equals("ADD") || ins.getMnemonicString().equals("SUB")
                                || ins.getMnemonicString().equals("LEA") || ins.getMnemonicString().equals("IMUL"))
                                step8++;
                        }
                    }
                }
                if (ins.getMnemonicString().startsWith("J") && ins.getFlows().length > 0) {
                    Address t = ins.getFlows()[0];
                    if (t.compareTo(ins.getAddress()) < 0) cmpLoop++;   // backward jump = loop
                }
            }
            if (readBegin == 0 && readEnd == 0) continue;
            log(String.format("  ### slot %-4d %s size=%-6d  readBegin(0x28)=%-3d readEnd(0x2c)=%-3d step8=%-3d backjumps=%-3d",
                slot, f.getName(), f.getBody().getNumAddresses(), readBegin, readEnd, step8, cmpLoop));
        }

        log("");
        log("==================== C: head listing of the two heaviest methods ====================");
        long[] heavy = { 0x4c94a0L, 0x4c91a0L };
        for (long h : heavy) {
            Function f = getFunctionAt(toAddr(h));
            if (f == null) continue;
            log("### " + f.getName() + " size=" + f.getBody().getNumAddresses());
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (ii.hasNext() && n < 45) {
                Instruction ins = ii.next();
                log("  0x" + ins.getAddress() + "  " + ins.toString());
                n++;
            }
            log("  ---- lines touching 0x28 / 0x2c / 0x34 ----");
            InstructionIterator ji = currentProgram.getListing().getInstructions(f.getBody(), true);
            int k = 0;
            while (ji.hasNext() && k < 40) {
                Instruction ins = ji.next();
                String s = ins.toString();
                if (s.contains("0x28]") || s.contains("0x2c]") || s.contains("0x30]") || s.contains("0x34]")) {
                    log("    0x" + ins.getAddress() + "  " + s);
                    k++;
                }
            }
            log("");
        }

        pw.flush();
        pw.close();
        log("=== TERMINUS3 DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
