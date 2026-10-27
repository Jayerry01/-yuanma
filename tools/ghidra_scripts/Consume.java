// Consume.java — Fun_004C94A0 (1062 B) is the top consumer candidate for the 8-byte intent queue.
// Pure listing (NO decompiler — it hangs). Goal: find the decision point (where intent becomes action)
// and any constants matching a combo/move table (ring size, frame tolerance).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Consume extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/consume.txt"));
        Memory mem = currentProgram.getMemory();

        long F = 0x4c94a0L;
        Function f = getFunctionAt(toAddr(F));
        if (f == null) { log("!! no function at 0x4c94a0"); pw.flush(); pw.close(); return; }
        log("### " + f.getName() + "  size=" + f.getBody().getNumAddresses());

        log("");
        log("==================== A: all CALL / indirect CALL sites ====================");
        InstructionIterator ci = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ci.hasNext()) {
            Instruction ins = ci.next();
            String mn = ins.getMnemonicString();
            if (!mn.equals("CALL")) continue;
            Address[] flows = ins.getFlows();
            Function tf = (flows.length > 0 ? getFunctionAt(flows[0]) : null);
            log("  0x" + ins.getAddress() + "  " + ins.toString()
                + (tf == null ? "" : "   -> " + tf.getName() + " size=" + tf.getBody().getNumAddresses()));
        }

        log("");
        log("==================== B: RET sites (arity) ====================");
        InstructionIterator ri = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ri.hasNext()) {
            Instruction ins = ri.next();
            if (ins.getMnemonicString().startsWith("RET")) log("  0x" + ins.getAddress() + "  " + ins.toString());
        }

        log("");
        log("==================== C: every numeric constant in the body ====================");
        TreeMap<Long, Integer> imm = new TreeMap<Long, Integer>();
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            for (int o = 0; o < ins.getNumOperands(); o++) {
                for (Object ob : ins.getOpObjects(o)) {
                    if (ob instanceof Scalar) {
                        long v = ((Scalar) ob).getValue();
                        if (v > 1 && v < 0x10000) {
                            Integer c = imm.get(v);
                            imm.put(v, c == null ? 1 : c + 1);
                        }
                    }
                }
            }
        }
        log("constant -> occurrences (looking for ring size / frame tolerance / table stride)");
        for (Long v : imm.keySet()) {
            String note = "";
            if (v == 8L) note = "  <-- queue entry size";
            if (v == 12L) note = "  <-- frame tolerance candidate";
            if (v == 32L) note = "  <-- ring size candidate";
            if (v == 0x20L) note = "  <-- 32";
            if (v == 300L) note = "  <-- 0x12c, seen in ctor";
            log(String.format("  0x%-6x %-6d x%-3d%s", v, v, imm.get(v), note));
        }

        log("");
        log("==================== D: the GameApp callback @0x004c953a with context ====================");
        long CALLADDR = 0x4c953aL;
        contextAround(f, CALLADDR, 22);

        log("");
        log("==================== E: the queue walk @0x004c9748 with context ====================");
        contextAround(f, 0x4c9748L, 40);

        log("");
        log("==================== F: comparison sites against members 0x100-0x118 (config fields) ====================");
        InstructionIterator fi = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (fi.hasNext()) {
            Instruction ins = fi.next();
            String s = ins.toString();
            if (s.contains("0x104]") || s.contains("0x108]") || s.contains("0x10c]") || s.contains("0x110]")
                || s.contains("0x114]") || s.contains("0x2c]") || s.contains("0x30]") || s.contains("0x34]")) {
                log("  0x" + ins.getAddress() + "  " + s);
            }
        }

        pw.flush();
        pw.close();
        log("=== CONSUME DONE ===");
    }

    void contextAround(Function f, long addr, int ctx) {
        ArrayList<Instruction> all = new ArrayList<Instruction>();
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ii.hasNext()) all.add(ii.next());
        for (int i = 0; i < all.size(); i++) {
            if (!all.get(i).getAddress().equals(toAddr(addr))) continue;
            int lo = Math.max(0, i - ctx), hi = Math.min(all.size() - 1, i + ctx);
            for (int j = lo; j <= hi; j++) {
                String mk = (j == i) ? ">>>" : "   ";
                log("  " + mk + " 0x" + all.get(j).getAddress() + "  " + all.get(j).toString());
            }
            return;
        }
        log("  (address not inside body)");
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
