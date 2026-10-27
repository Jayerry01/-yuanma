// PstApiTable: locate the pointer arrays that reference the .pst builtin / behavior name pool.
// Strategy: for each known pool string, find every data address holding a pointer to it,
// then cluster those pointer slots to reveal table base + stride + true order.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.util.task.TaskMonitor;
import java.io.*;
import java.util.*;

public class PstApiTable extends GhidraScript {

    // pool strings discovered from raw bytes at 0x5C9FB8 / 0x5CA0E8 / 0x5CA17C / 0x5CA284
    static final String[] BUILTIN = {
        "OnInit","OnUpdate","Print","Say","Call","UpdateAIAttrib","RemoveNPC","AddNPC",
        "GameOver","Rand","SetTarget","IsPerforming","StopPerform","PlayerPerform","Perform",
        "ChangeBehavior","DisableWaypoints","EnableWaypoints","GetGameTime","GetLeader",
        "GetEnemy","GetTeam","GetMaxHP","GetHP","GetSelf","GetAnyChar","GetChar"
    };
    static final String[] BEHAVIOR = {
        "dodge","attacktarget","patrol","follow","run","idle","wait","faceto","guard","waypoint","char"
    };
    static final String[] AIGOAL = {
        "AttackGoal","FastLook","GetItem","AvoidObstacle","Dodge","Kill","Combat",
        "RandomRun","Follow","Patrol","GotoGoal","Wait","Init"
    };
    static final String[] AIATTR = {
        "Spawn","Aim","Burst","Look","Attack3","Attack2","Attack1","Think","View","HP"
    };

    long findStr(Memory mem, String s) throws Exception {
        byte[] pat = s.getBytes("US-ASCII");
        Address start = toAddr(0x5c0000L);
        Address end = toAddr(0x5d4000L);
        Address cur = start;
        while (cur != null && cur.compareTo(end) < 0) {
            Address hit = mem.findBytes(cur, end, pat, null, true, TaskMonitor.DUMMY);
            if (hit == null) return -1;
            long idx = hit.getOffset();
            // must be NUL terminated
            try {
                byte nx = mem.getByte(toAddr(idx + pat.length));
                if (nx == 0) return idx;
            } catch (Exception e) { }
            cur = toAddr(idx + 1);
        }
        return -1;
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        ReferenceManager rm = currentProgram.getReferenceManager();
        Listing lst = currentProgram.getListing();
        StringBuilder sb = new StringBuilder();

        String[][] groups = { BUILTIN, BEHAVIOR, AIGOAL, AIATTR };
        String[] gname = { "A: builtin/hook", "B: behavior (lowercase)", "C: AI goal (Capitalized)", "D: AI attribute" };

        for (int g = 0; g < groups.length; g++) {
            String[] set = groups[g];
            sb.append("########## ").append(gname[g]).append("  n=").append(set.length).append(" ##########\n");
            TreeMap<Long, String> slot2name = new TreeMap<Long, String>();
            HashMap<Long, String> va2name = new HashMap<Long, String>();
            for (String s : set) {
                long va = findStr(mem, s);
                if (va < 0) { sb.append("  !! not found: ").append(s).append("\n"); continue; }
                va2name.put(va, s);
                Address a = toAddr(va);
                ReferenceIterator it = rm.getReferencesTo(a);
                int cnt = 0;
                while (it.hasNext()) {
                    Reference r = it.next();
                    Address from = r.getFromAddress();
                    // only data references (not code) count for table membership
                    boolean isCode = false;
                    try { isCode = lst.getInstructionAt(from) != null; } catch (Exception e) {}
                    if (isCode) continue;
                    slot2name.put(from.getOffset(), s);
                    cnt++;
                }
                sb.append(String.format("  %-18s va=%08X  dataPtrSlots=%d%n", s, va, cnt));
            }
            sb.append("\n  -- pointer slots (sorted) --\n");
            Long prev = null;
            for (Map.Entry<Long, String> e : slot2name.entrySet()) {
                long k = e.getKey();
                long delta = (prev == null) ? 0 : (k - prev);
                sb.append(String.format("    %08X  %-18s  delta=%s%n", k, e.getValue(),
                        (prev == null) ? "-" : ("+" + Long.toHexString(delta))));
                prev = k;
            }
            sb.append("\n");
        }

        File out = new File("D:/MeteorRE/evidence/pst_api_table.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
