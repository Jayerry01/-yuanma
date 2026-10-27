// EvPipe.java — for each sender function, find its owning vtable(s) and that vtable's slot-3 target.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class EvPipe extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/evpipe.txt"));
        log("=== EVENT PIPE: resolve slot-3 target per sender class ===");

        Memory mem = currentProgram.getMemory();
        long codeLo = 0x401000L, codeHi = 0x5a72bdL;

        // rebuild the raw map: address -> function entry? then find runs
        Map<Long, String> entryAt = new LinkedHashMap<Long, String>();
        for (MemoryBlock blk : mem.getBlocks()) {
            if (!blk.isInitialized() || blk.isExecute()) continue;
            if (blk.getName().equals("rsrc") || blk.getName().equals("tdb")) continue;
            long off = 0, size = blk.getSize();
            while (off + 4 <= size) {
                int v;
                try { v = mem.getInt(blk.getStart().add(off)); } catch (Exception e) { off += 4; continue; }
                long lv = v & 0xffffffffL;
                if (lv >= codeLo && lv <= codeHi) {
                    Function f = null;
                    try { f = currentProgram.getFunctionManager().getFunctionAt(toAddr(lv)); } catch (Exception e2) {}
                    if (f != null) entryAt.put(blk.getStart().add(off).getOffset(), f.getName());
                }
                off += 4;
            }
        }
        log("function-entry-like words found: " + entryAt.size());

        // build runs
        List<Long> keys = new ArrayList<Long>(entryAt.keySet());
        Map<Long, List<String>> vtables = new LinkedHashMap<Long, List<String>>();
        // group by contiguous 4-byte steps
        Set<Long> inRun = new HashSet<Long>();
        for (Long k : keys) {
            if (inRun.contains(k)) continue;
            List<String> vals = new ArrayList<String>();
            long cur = k;
            while (entryAt.containsKey(cur)) { vals.add(entryAt.get(cur)); inRun.add(cur); cur += 4; }
            if (vals.size() >= 4) vtables.put(k, vals);
        }
        log("runs(>=4): " + vtables.size());

        // reverse index: function name -> list of (vtableBase, slotIndex)
        Map<String, List<String>> belongs = new HashMap<String, List<String>>();
        for (Map.Entry<Long, List<String>> e : vtables.entrySet()) {
            List<String> vs = e.getValue();
            for (int i = 0; i < vs.size(); i++) {
                belongs.computeIfAbsent(vs.get(i), k -> new ArrayList<String>())
                       .add(String.format("0x%08x/slot%d", e.getKey(), i));
            }
        }

        long[] senders = { 0x4cb260L, 0x4d0ac0L, 0x4cf5b0L, 0x4cd200L, 0x4ceb50L, 0x4d0540L };
        for (long s : senders) {
            Function f = getFunctionAt(toAddr(s));
            String nm = (f == null ? ("0x" + Long.toHexString(s)) : f.getName());
            log("");
            log("###### sender " + nm + " (0x" + Long.toHexString(s) + ") ######");
            List<String> b = belongs.get(nm);
            if (b == null) { log("  NOT FOUND in any scanned vtable run"); continue; }
            log("  membership (" + b.size() + "): " + b);
            for (String desc : b) {
                long base = Long.parseLong(desc.split("/")[0].substring(2), 16);
                int slot = Integer.parseInt(desc.split("/slot")[1]);
                // slot 3 of THIS vtable
                try {
                    int v3 = mem.getInt(toAddr(base + 0xc));
                    Function f3 = getFunctionAt(toAddr(v3 & 0xffffffffL));
                    int v0 = mem.getInt(toAddr(base));
                    Function f0 = getFunctionAt(toAddr(v0 & 0xffffffffL));
                    log("    base=0x" + Long.toHexString(base) + " (sender at slot " + slot + ")" +
                        "  -> vtable[0]=" + (f0 == null ? "?" : f0.getName()) +
                        "   vtable[3]=" + String.format("0x%08x %s", v3, (f3 == null ? "(no func)" : f3.getName())));
                } catch (Exception ex) { log("    base=0x" + Long.toHexString(base) + " read fail"); }
            }
        }

        // Full list of ALL runs so nothing hides
        log("");
        log("=== ALL RUNS (base, n, slot0, slot1, slot2, slot3) ===");
        for (Map.Entry<Long, List<String>> e : vtables.entrySet()) {
            List<String> v = e.getValue();
            log(String.format("  0x%08x n=%-4d s0=%-18s s1=%-18s s2=%-18s s3=%-18s",
                e.getKey(), v.size(), v.get(0), v.get(1), v.get(2), v.get(3)));
        }

        pw.flush(); pw.close();
        log("=== EVPIPE DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
