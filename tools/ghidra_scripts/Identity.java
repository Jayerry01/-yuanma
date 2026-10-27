// Identity.java — who is member_0x2410? dump the 5 writers, their xrefs, the 0x2414 flag relationship,
// and the virtual-slot usage fingerprint of the injected object.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class Identity extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/identity.txt"));
        Memory mem = currentProgram.getMemory();

        long[] writers = { 0x487450L, 0x4878f0L, 0x4890a0L, 0x489150L, 0x489570L };

        log("==================== A: the five writers of member_0x2410 ====================");
        for (long w : writers) {
            Function f = getFunctionAt(toAddr(w));
            if (f == null) { log("!! no func at 0x" + Long.toHexString(w)); continue; }
            log("");
            log("### " + f.getName() + "  size=" + f.getBody().getNumAddresses());
            log("--- lines touching 0x2410 / 0x2414 (with +/-6 instruction context) ---");
            contextLines(f, 6);
            log("--- xrefs TO this writer ---");
            dumpXrefs(f.getEntryPoint(), 30);
        }

        log("");
        log("==================== B: decompile the small setters ====================");
        long[] small = { 0x4878f0L, 0x4890a0L, 0x489150L, 0x489570L, 0x489420L, 0x489550L, 0x489d20L, 0x48fa10L };
        for (long s : small) {
            Function f = getFunctionAt(toAddr(s));
            if (f == null) continue;
            log("");
            log("### " + f.getName() + " size=" + f.getBody().getNumAddresses());
            decomp(f, 40);
        }

        log("");
        log("==================== C: virtual-slot fingerprint of the injected object ====================");
        TreeMap<Long, Integer> slotHits = new TreeMap<Long, Integer>();
        TreeMap<Long, String> slotWhere = new TreeMap<Long, String>();
        InstructionIterator ii = currentProgram.getListing().getInstructions(mem.getExecuteSet(), true);
        while (ii.hasNext()) {
            Instruction first = ii.next();
            String s0 = first.toString();
            if (s0.indexOf("0x2410") < 0) continue;
            Function owner = currentProgram.getFunctionManager().getFunctionContaining(first.getAddress());
            InstructionIterator jj = currentProgram.getListing().getInstructions(first.getAddress(), true);
            // look at the next 10 instructions in address order
            int guard = 0;
            Instruction prev = null;
            while (jj.hasNext() && guard < 12) {
                Instruction ins = jj.next();
                guard++;
                String mn = ins.getMnemonicString();
                if (mn.equals("CALL")) {
                    String s = ins.toString();
                    int k = s.indexOf('[');
                    int plus = s.indexOf('+', k < 0 ? 0 : k);
                    if (k >= 0 && plus > k) {
                        String hex = s.substring(plus + 1).replaceAll("[^0-9a-fA-F].*", "");
                        try {
                            long disp = Long.parseLong(hex.trim(), 16);
                            if (disp <= 0x400L && (disp % 4) == 0) {
                                long slot = disp / 4;
                                Integer c = slotHits.get(slot);
                                slotHits.put(slot, c == null ? 1 : c + 1);
                                if (!slotWhere.containsKey(slot))
                                    slotWhere.put(slot, (owner == null ? "?" : owner.getName()) + " @0x" + ins.getAddress());
                            }
                        } catch (Exception e) { /* ignore */ }
                    }
                    break;
                }
            }
        }
        log("slot -> call-site count / example (only first CALL within 12 insns after reading 0x2410)");
        for (Long slot : slotHits.keySet()) {
            log(String.format("  slot %-4d (+0x%-4x)  x%-3d  %s", slot, slot * 4, slotHits.get(slot), slotWhere.get(slot)));
        }

        pw.flush();
        pw.close();
        log("=== IDENTITY DONE ===");
    }

    void contextLines(Function f, int ctx) {
        ArrayList<Instruction> all = new ArrayList<Instruction>();
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ii.hasNext()) all.add(ii.next());
        for (int i = 0; i < all.size(); i++) {
            String s = all.get(i).toString();
            if (s.indexOf("0x2410") < 0 && s.indexOf("0x2414") < 0) continue;
            int lo = Math.max(0, i - ctx), hi = Math.min(all.size() - 1, i + ctx);
            log("   ---- @0x" + all.get(i).getAddress() + " ----");
            for (int j = lo; j <= hi; j++) log("    0x" + all.get(j).getAddress() + "  " + all.get(j).toString());
        }
    }

    void dumpXrefs(Address a, int max) {
        ghidra.program.model.symbol.ReferenceIterator ri = currentProgram.getReferenceManager().getReferencesTo(a);
        int n = 0;
        while (ri.hasNext() && n < max) {
            ghidra.program.model.symbol.Reference r = ri.next();
            Function f = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            log("    from 0x" + r.getFromAddress() + "  [" + (f == null ? "?" : f.getName()) + "]  " + r.getReferenceType());
            n++;
        }
        if (n == 0) log("    (none)");
    }

    void decomp(Function f, int maxLines) {
        try {
            ghidra.app.decompiler.DecompInterface di = new ghidra.app.decompiler.DecompInterface();
            di.openProgram(currentProgram);
            ghidra.app.decompiler.DecompileResults dr = di.decompileFunction(f, 60, getMonitor());
            if (dr == null) { log("    <decompile null>"); return; }
            String c = dr.getDecompiledFunction().getC();
            if (c == null) { log("    <decompile failed: " + dr.getErrorMessage() + ">"); return; }
            String[] lines = c.split("\\n");
            int n = Math.min(lines.length, maxLines);
            for (int i = 0; i < n; i++) log("    " + lines[i]);
        } catch (Exception e) {
            log("    <decompile error: " + e + ">");
        }
    }

    void log(String s) {
        println(s);
        pw.println(s);
    }
}
