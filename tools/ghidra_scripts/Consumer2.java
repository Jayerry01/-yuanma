// Consumer2.java — slot 15 turned out to be a loader/serialiser, not a matcher. This pass characterises
// the last candidate, slot 19 = FUN_004CC130 (1174 B), plus resolves the new target GameApp vtable[133].
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Consumer2 extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/consumer2.txt"));
        Memory mem = currentProgram.getMemory();

        log("==================== A: GameApp vtable[133] (called @0x004c953a) ====================");
        long t133 = 0x5a9068L + 0x214L;
        int v133 = mem.getInt(toAddr(t133));
        Function f133 = getFunctionAt(toAddr(v133 & 0xffffffffL));
        log(String.format("  mem[0x%08x] = 0x%08x  %s", t133, v133,
            f133 == null ? "(NO FUNCTION)" : f133.getName() + " size=" + f133.getBody().getNumAddresses()));
        if (f133 != null) {
            InstructionIterator ii = currentProgram.getListing().getInstructions(f133.getBody(), true);
            int n = 0;
            while (ii.hasNext() && n < 30) { Instruction ins = ii.next(); log("    0x" + ins.getAddress() + "  " + ins.toString()); n++; }
            InstructionIterator ri = currentProgram.getListing().getInstructions(f133.getBody(), true);
            while (ri.hasNext()) {
                Instruction ins = ri.next();
                if (ins.getMnemonicString().startsWith("RET")) log("      RET: " + ins.getAddress() + "  " + ins.toString());
            }
        }

        log("");
        log("==================== B: slot 19 = FUN_004CC130 ====================");
        Function f = getFunctionAt(toAddr(0x4cc130L));
        if (f == null) {
            log("!! none");
        } else {
            log(f.getName() + "  size=" + f.getBody().getNumAddresses());
            log("--- head 35 ---");
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (ii.hasNext() && n < 35) { Instruction ins = ii.next(); log("  0x" + ins.getAddress() + "  " + ins.toString()); n++; }
            log("--- CALL sites ---");
            InstructionIterator ci = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ci.hasNext()) {
                Instruction ins = ci.next();
                if (!ins.getMnemonicString().equals("CALL")) continue;
                Address[] fl = ins.getFlows();
                Function tf = (fl.length > 0 ? getFunctionAt(fl[0]) : null);
                log("  0x" + ins.getAddress() + "  " + ins.toString()
                    + (tf == null ? "" : "   -> " + tf.getName() + " size=" + tf.getBody().getNumAddresses()));
            }
            log("--- RET sites ---");
            InstructionIterator ri = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ri.hasNext()) {
                Instruction ins = ri.next();
                if (ins.getMnemonicString().startsWith("RET")) log("  0x" + ins.getAddress() + "  " + ins.toString());
            }
            log("--- constants ---");
            TreeMap<Long, Integer> imm = new TreeMap<Long, Integer>();
            InstructionIterator ki = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ki.hasNext()) {
                Instruction ins = ki.next();
                for (int o = 0; o < ins.getNumOperands(); o++) {
                    for (Object ob : ins.getOpObjects(o)) {
                        if (ob instanceof Scalar) {
                            long v = ((Scalar) ob).getValue();
                            if (v > 1 && v < 0x10000) imm.put(v, imm.get(v) == null ? 1 : imm.get(v) + 1);
                        }
                    }
                }
            }
            for (Long v : imm.keySet()) log(String.format("    0x%-6x %-6d x%d", v, v, imm.get(v)));
            log("--- any computed jump / switch? ---");
            InstructionIterator ji = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ji.hasNext()) {
                Instruction ins = ji.next();
                String mn = ins.getMnemonicString();
                if (mn.equals("JMP") && ins.getFlows().length == 0) log("    indirect JMP: 0x" + ins.getAddress() + "  " + ins.toString());
                Object[] ops = ins.getOpObjects(0);
                for (Object ob : ops) {
                    if (ob instanceof Address && ins.getMnemonicString().equals("JMP"))
                        log("    JMP target: 0x" + ins.getAddress() + "  " + ins.toString());
                }
            }
            log("--- backward jumps (loops) ---");
            InstructionIterator bi = currentProgram.getListing().getInstructions(f.getBody(), true);
            int loops = 0;
            while (bi.hasNext()) {
                Instruction ins = bi.next();
                Address[] fl = ins.getFlows();
                if (fl.length > 0 && ins.getMnemonicString().startsWith("J") && fl[0].compareTo(ins.getAddress()) < 0) {
                    log("    0x" + ins.getAddress() + "  " + ins.toString());
                    if (++loops > 12) { log("    ..."); break; }
                }
            }
        }

        pw.flush();
        pw.close();
        log("=== CONSUMER2 DONE ===");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
