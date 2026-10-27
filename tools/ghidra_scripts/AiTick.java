// AiTick: walk up from the thunk client and name the entry call of 0x40A2A0.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class AiTick extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    Set<Long> callersOf(long va) {
        Set<Long> s = new LinkedHashSet<>();
        for (Reference r : getReferencesTo(toAddr(va))) {
            if (!r.getReferenceType().isCall() && !r.getReferenceType().isJump()) continue;
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            s.add(c == null ? r.getFromAddress().getOffset() : c.getEntryPoint().getOffset());
        }
        return s;
    }

    void head(long va, int n) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("     <none>"); return; }
        w("     [" + f.getName() + " size=" + f.getBody().getNumAddresses() + "]");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getEntryPoint(), true);
        Address end = f.getBody().getMaxAddress();
        int k = 0;
        while (it.hasNext() && k < n) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            byte[] b = null;
            try { b = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (b != null) for (int i = 0; i < b.length && i < 6; i++) hex.append(String.format("%02x ", b[i] & 0xff));
            w(String.format("       %s  %-20s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            k++;
        }
    }

    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();

        w("================ A: upward chain from 0x408DA0 ================");
        Set<Long> lvl1 = callersOf(0x408DA0L);
        w("  callers of 0x408DA0: " + lvl1.size());
        for (long a : lvl1) w("     " + String.format("%08X", a) + "  "
            + (fm.getFunctionContaining(toAddr(a)) == null ? "?" : fm.getFunctionContaining(toAddr(a)).getName()));

        Set<Long> lvl2 = new LinkedHashSet<>();
        for (long a : lvl1) {
            w("  -- callers of " + String.format("%08X", a));
            for (long b : callersOf(a)) { w("       " + String.format("%08X", b)); lvl2.add(b); }
        }
        w("  level-2 total: " + lvl2.size());

        Set<Long> lvl3 = new LinkedHashSet<>();
        for (long a : lvl2) for (long b : callersOf(a)) lvl3.add(b);
        w("  level-3 total: " + lvl3.size());
        for (long a : lvl3) w("     " + String.format("%08X", a));

        w("");
        w("================ B: the first call inside 0x40A2A0 ================");
        w("  0x00406ED0 head:");
        head(0x406ED0L, 16);

        w("");
        w("================ C: 0x005D5A00 (hub's global) ================");
        Function g = null;
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(0x5D5A00L))) {
            Function c = fm.getFunctionContaining(r.getFromAddress());
            w("     " + r.getFromAddress() + " " + r.getReferenceType() + " in "
                + (c == null ? "?" : c.getName() + "@" + c.getEntryPoint()));
            n++;
        }
        if (n == 0) w("     none");

        w("");
        w("================ D: 0x408DA0 head ================");
        head(0x408DA0L, 24);

        File out = new File("D:/MeteorRE/evidence/ai_tick.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
