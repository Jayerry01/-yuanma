// Slot8.java — verify 0x4a9770 is the shared slot-3 dispatcher; find its forwarding target slot 8.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class Slot8 extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/slot8.txt"));
        Memory mem = currentProgram.getMemory();
        log("=== SLOT8: verify dispatcher 0x4a9770 ===");

        // 1. asm of 0x4a9770
        Function f = getFunctionAt(toAddr(0x4a9770L));
        log("");
        log("### asm of FUN_004a9770 (size " + f.getBody().getNumAddresses() + ") ###");
        InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            String line = ins.getAddress() + "  " + ins.toString();
            for (Object o : ins.getReferencesFrom()) {
                Reference rr = (Reference) o;
                Symbol sy = currentProgram.getSymbolTable().getPrimarySymbol(rr.getToAddress());
                line += "   ; <= " + rr.getToAddress() + (sy != null ? " " + sy.getName() : "");
            }
            log("  " + line);
        }

        // 2. xrefs to 0x4a9770
        log("");
        log("### XREFS to 0x4a9770 (callers) ###");
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(toAddr(0x4a9770L));
        int n = 0;
        while (rit.hasNext() && n < 40) {
            Reference r = rit.next();
            Instruction ins = currentProgram.getListing().getInstructionContaining(r.getFromAddress());
            Function cf = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            log("  from 0x" + r.getFromAddress() + " type=" + r.getReferenceType() +
                (ins != null ? ("  " + ins.toString()) : "") + (cf != null ? ("  [in " + cf.getName() + "]") : ""));
            n++;
        }

        // 3. sender slot indices assuming vfptr base 0x005aa6a8
        log("");
        log("### sender positions relative to candidate vfptr bases ###");
        long[] senders = { 0x4cb260L, 0x4cd200L, 0x4ceb50L, 0x4cf5b0L, 0x4d0540L, 0x4d0ac0L };
        long[] bases = { 0x5aa658L, 0x5aa65cL, 0x5aa660L, 0x5aa6a8L, 0x5aa88cL };
        Map<Long, List<String>> entryAtAddr = new HashMap<Long, List<String>>();
        for (long s : senders) {
            for (long b : bases) {
                long a = b;
                boolean found = false;
                long maxA = b + 600; // scan forward
                while (a < maxA) {
                    try {
                        int v = mem.getInt(toAddr(a));
                        if ((v & 0xffffffffL) == s) {
                            log(String.format("  sender 0x%08x is at 0x%08x = base 0x%08x + slot %d",
                                s, a, b, (a - b) / 4));
                            found = true;
                            break;
                        }
                    } catch (Exception e) { break; }
                    a += 4;
                }
                if (found) break;
            }
        }

        // 4. rank functions occupying slot 8 (offset 0x20) most often
        log("");
        log("### functions occupying SLOT 8 (offset 0x20) across all vtable runs ###");
        long codeLo = 0x401000L, codeHi = 0x5a72bdL;
        Map<Long, String> entryAt = new LinkedHashMap<Long, String>();
        for (MemoryBlock blk : mem.getBlocks()) {
            if (!blk.isInitialized() || blk.isExecute()) continue;
            long off = 0, size = blk.getSize();
            while (off + 4 <= size) {
                int v;
                try { v = mem.getInt(blk.getStart().add(off)); } catch (Exception e) { off += 4; continue; }
                long lv = v & 0xffffffffL;
                if (lv >= codeLo && lv <= codeHi) {
                    Function ff = null;
                    try { ff = currentProgram.getFunctionManager().getFunctionAt(toAddr(lv)); } catch (Exception e2) {}
                    if (ff != null) entryAt.put(blk.getStart().add(off).getOffset(), ff.getName());
                }
                off += 4;
            }
        }
        Set<Long> seen = new HashSet<Long>();
        Map<String, Integer> slot8 = new HashMap<String, Integer>();
        Map<String, String> addrByName = new HashMap<String, String>();
        for (Long k : entryAt.keySet()) {
            if (seen.contains(k)) continue;
            long cur = k;
            List<String> vs = new ArrayList<String>();
            while (entryAt.containsKey(cur)) { vs.add(entryAt.get(cur)); seen.add(cur); cur += 4; }
            if (vs.size() < 9) continue;
            String nm = vs.get(8);
            slot8.put(nm, slot8.getOrDefault(nm, 0) + 1);
        }
        List<Map.Entry<String, Integer>> l = new ArrayList<>(slot8.entrySet());
        l.sort((a, b) -> b.getValue() - a.getValue());
        for (int i = 0; i < Math.min(25, l.size()); i++) {
            Map.Entry<String, Integer> e = l.get(i);
            Function gf = null;
            try { gf = getFunctionAt(toAddr(Long.parseLong(e.getKey().replace("FUN_", "").replace("thunk_FUN_", ""), 16))); } catch (Exception ex) {}
            log(String.format("  %-24s slot8 in %3d vtables   size=%s",
                e.getKey(), e.getValue(), (gf == null ? "?" : String.valueOf(gf.getBody().getNumAddresses()))));
        }

        pw.flush(); pw.close();
        log("=== SLOT8 DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
