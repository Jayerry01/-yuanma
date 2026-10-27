// VtabMap.java — scan initialized data for vtable-like pointer arrays; rank functions by
// how many distinct vtables reference them, and specifically which occupy slot 3 (offset 0xc).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class VtabMap extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/vtab_map.txt"));
        log("=== VTABLE MAP ===");

        Memory mem = currentProgram.getMemory();
        long codeLo = 0x401000L, codeHi = 0x5a72bdL;

        // map: address(long) -> boolean : is it a function entry
        Map<Long, String> entries = new HashMap<Long, String>();

        // First: scan every initialized data byte position for a value that is a function entry
        List<Address> runStarts = new ArrayList<Address>();
        Map<Address, List<String>> vtables = new LinkedHashMap<Address, List<String>>();
        long totalWords = 0;

        for (MemoryBlock blk : mem.getBlocks()) {
            if (!blk.isInitialized()) { log("skip uninitialized block " + blk.getName()); continue; }
            if (blk.isExecute()) continue; // data sections only
            log("scanning block " + blk.getName() + " 0x" + blk.getStart() + " size=0x" + Long.toHexString(blk.getSize()));
            Address a = blk.getStart();
            long endOff = blk.getSize();
            long off = 0;
            // current run
            Address runStart = null;
            List<String> runVals = new ArrayList<String>();
            while (off + 4 <= endOff) {
                int v = 0;
                try { v = mem.getInt(a.add(off)); } catch (Exception e) { off += 4; continue; }
                long lv = v & 0xffffffffL;
                boolean isEntry = false;
                String fname = null;
                if (lv >= codeLo && lv <= codeHi) {
                    Function f = null;
                    try { f = currentProgram.getFunctionManager().getFunctionAt(toAddr(lv)); } catch (Exception e) {}
                    if (f != null) { isEntry = true; fname = f.getName(); }
                }
                totalWords++;
                if (isEntry) {
                    if (runStart == null) { runStart = a.add(off); runVals = new ArrayList<String>(); }
                    runVals.add(fname);
                } else {
                    if (runStart != null) {
                        if (runVals.size() >= 4) { vtables.put(runStart, runVals); }
                        runStart = null;
                    }
                }
                off += 4;
            }
            if (runStart != null && runVals.size() >= 4) vtables.put(runStart, runVals);
        }

        log("");
        log("scanned data words: " + totalWords);
        log("vtable candidates found (>=4 consecutive function pointers): " + vtables.size());

        // rank functions by number of distinct vtables referencing them
        Map<String, Integer> count = new HashMap<String, Integer>();
        Map<String, Set<Integer>> slots = new HashMap<String, Set<Integer>>();
        for (Map.Entry<Address, List<String>> e : vtables.entrySet()) {
            List<String> vs = e.getValue();
            for (int i = 0; i < vs.size(); i++) {
                String fn = vs.get(i);
                count.put(fn, (count.containsKey(fn) ? count.get(fn) : 0) + 1);
                slots.computeIfAbsent(fn, k -> new TreeSet<Integer>()).add(i);
            }
        }

        log("");
        log("=== TOP 40 functions shared across most vtables (candidates: shared virtuals) ===");
        List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(count.entrySet());
        list.sort((a, b) -> b.getValue() - a.getValue());
        for (int i = 0; i < Math.min(40, list.size()); i++) {
            Map.Entry<String, Integer> e = list.get(i);
            Set<Integer> ss = slots.get(e.getKey());
            String slotStr = ss.size() <= 8 ? ss.toString() : ("size=" + ss.size() + " first=" + ss.iterator().next());
            log(String.format("  %-24s in %3d vtables   slots=%s", e.getKey(), e.getValue(), slotStr));
        }

        log("");
        log("=== specifically: functions occupying SLOT 3 (offset 0xc) most often ===");
        Map<String, Integer> slot3 = new HashMap<String, Integer>();
        for (Map.Entry<Address, List<String>> e : vtables.entrySet()) {
            List<String> vs = e.getValue();
            if (vs.size() > 3) slot3.put(vs.get(3), (slot3.containsKey(vs.get(3)) ? slot3.get(vs.get(3)) : 0) + 1);
        }
        List<Map.Entry<String, Integer>> l3 = new ArrayList<Map.Entry<String, Integer>>(slot3.entrySet());
        l3.sort((a, b) -> b.getValue() - a.getValue());
        for (int i = 0; i < Math.min(25, l3.size()); i++) {
            Map.Entry<String, Integer> e = l3.get(i);
            log(String.format("  %-24s slot3 in %3d vtables", e.getKey(), e.getValue()));
        }

        log("");
        log("=== vtable list (first 60) : base -> slot0..slot3 ===");
        int k = 0;
        for (Map.Entry<Address, List<String>> e : vtables.entrySet()) {
            List<String> vs = e.getValue();
            log(String.format("  0x%s n=%-3d s0=%-16s s1=%-16s s2=%-16s s3=%-16s",
                e.getKey(), vs.size(), vs.get(0), vs.get(1), vs.get(2), vs.get(3)));
            if (++k >= 60) break;
        }

        pw.flush(); pw.close();
        log("=== VTAB MAP DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
