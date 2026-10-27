// CmdScan.java — find functions that compare against command constants (0x33/0xd/7/…)
// and check RET arity of candidate slot-3 handlers.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class CmdScan extends GhidraScript {
    PrintWriter pw;
    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/cmdscan.txt"));
        log("=== CMD SCAN ===");

        // ---- part 1: RET arity of candidates ----
        int[] cands = { 0x4c8a70, 0x4c8bd0, 0x4c9180, 0x4a9770, 0x4d1630 };
        log("");
        log("### candidate slot-3 handlers: return instructions (arity check) ###");
        for (int c : cands) {
            Function f = getFunctionAt(toAddr(c));
            if (f == null) { log("  0x" + Integer.toHexString(c) + " NO FUNCTION"); continue; }
            List<String> rets = new ArrayList<String>();
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (ii.hasNext()) {
                Instruction ins = ii.next();
                if (ins.getMnemonicString().startsWith("RET") || ins.getMnemonicString().equals("JMP")) {
                    rets.add(ins.getAddress() + " " + ins.toString());
                }
            }
            log("  " + f.getName() + " (0x" + Long.toHexString(c) + ") exits: " + rets);
        }

        // ---- part 2: functions whose CMP immediates include command ids ----
        log("");
        log("### functions containing CMP with immediate == 0x33 ###");
        Map<String, Set<Long>> perFunc = new HashMap<String, Set<Long>>();
        Map<String, Integer> size = new HashMap<String, Integer>();
        Map<String, Long> addrOf = new HashMap<String, Long>();
        InstructionIterator it = currentProgram.getListing().getInstructions(
            currentProgram.getMemory().getExecuteSet(), true);
        long scanned = 0;
        while (it.hasNext()) {
            Instruction ins = it.next();
            scanned++;
            String mn = ins.getMnemonicString();
            if (!mn.equals("CMP") && !mn.equals("SUB") && !mn.equals("ADD")) continue;
            for (int o = 0; o < ins.getNumOperands(); o++) {
                Object[] obs = ins.getOpObjects(o);
                for (Object ob : obs) {
                    if (!(ob instanceof Scalar)) continue;
                    long v = ((Scalar) ob).getValue();
                    if (v <= 0x200) {
                        Function f = currentProgram.getFunctionManager().getFunctionContaining(ins.getAddress());
                        if (f == null) continue;
                        String nm = f.getName();
                        perFunc.computeIfAbsent(nm, k -> new TreeSet<Long>()).add(v);
                        size.put(nm, (int) f.getBody().getNumAddresses());
                        addrOf.put(nm, f.getEntryPoint().getOffset());
                    }
                }
            }
        }
        log("instructions scanned: " + scanned + "   functions with small cmp immediates: " + perFunc.size());
        log("");
        log("--- functions whose cmp-set includes 0x33 (sorted by size desc) ---");
        List<String> hits = new ArrayList<String>();
        for (Map.Entry<String, Set<Long>> e : perFunc.entrySet()) {
            if (e.getValue().contains(0x33L)) hits.add(e.getKey());
        }
        hits.sort((a, b) -> size.get(b) - size.get(a));
        for (String nm : hits) {
            Set<Long> s = perFunc.get(nm);
            boolean hasD = s.contains(0xdL), has7 = s.contains(7L);
            String tail = s.size() > 40 ? ("n=" + s.size()) : s.toString();
            log(String.format("  %-22s @0x%08x size=%-6d hasD=%s has7=%s  set=%s",
                nm, addrOf.get(nm), size.get(nm), hasD, has7, tail));
        }
        log("");
        log("--- functions whose cmp-set includes BOTH 0x33 and 0xd and 7 ---");
        int shown = 0;
        for (String nm : hits) {
            Set<Long> s = perFunc.get(nm);
            if (s.contains(0xdL) && s.contains(7L)) {
                log(String.format("  %-22s @0x%08x size=%-6d set=%s", nm, addrOf.get(nm), size.get(nm),
                    (s.size() > 40 ? ("n=" + s.size()) : s.toString())));
                shown++;
            }
        }
        if (shown == 0) log("  (none)");

        pw.flush(); pw.close();
        log("=== CMD SCAN DONE ===");
    }
    void log(String s) { println(s); pw.println(s); }
}
