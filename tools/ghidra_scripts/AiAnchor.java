// AiAnchor: verify the four AI entry candidates in the exe only.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class AiAnchor extends GhidraScript {

    long[] CAND = { 0x40A2A0L, 0x40B0C0L, 0x40C040L, 0x40D040L };
    String[] LABEL = { "UpdateDecisionTree?", "EvaluateTargetHostility?", "SelectComboAction?", "NavigateToWaypoint?" };

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String arity(Function f) {
        if (f == null) return "?";
        try {
            Address mx = f.getBody().getMaxAddress();
            byte last = currentProgram.getMemory().getByte(mx);
            if ((last & 0xff) == 0xC3) return "RET (0 args)";
            if ((last & 0xff) == 0xC2) {
                int lo = currentProgram.getMemory().getByte(mx.subtract(2)) & 0xff;
                int hi = currentProgram.getMemory().getByte(mx.subtract(1)) & 0xff;
                int n = lo | (hi << 8);
                return "RET 0x" + Integer.toHexString(n) + " (" + (n / 4) + " args)";
            }
            if ((last & 0xff) == 0xE9 || (last & 0xff) == 0xEB) return "tail JMP";
            return String.format("ends %02x", last & 0xff);
        } catch (Exception e) { return "?err"; }
    }

    int countCallers(long va) {
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(va))) {
            RefType t = r.getReferenceType();
            if (t.isCall() || t.isJump()) n++;
        }
        return n;
    }

    void dump(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("    <no function>"); return; }
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getEntryPoint(), true);
        Address end = f.getBody().getMaxAddress();
        int n = 0;
        while (it.hasNext() && n < max) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            byte[] b = null;
            try { b = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (b != null) for (int i = 0; i < b.length && i < 6; i++) hex.append(String.format("%02x ", b[i] & 0xff));
            w(String.format("     %s  %-20s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
        if (n >= max) w("     ...");
    }

    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();

        w("================ A: the four candidates ================");
        for (int i = 0; i < CAND.length; i++) {
            long va = CAND[i];
            Function f = fm.getFunctionContaining(toAddr(va));
            if (f == null) {
                w(String.format("  %08X  %-26s  *** NOT IN ANY FUNCTION ***", va, LABEL[i]));
                continue;
            }
            boolean isEntry = f.getEntryPoint().getOffset() == va;
            w(String.format("  %08X  %-26s  entry=%s  size=%-5d arity=%-16s callers=%d %s",
                va, LABEL[i], f.getEntryPoint(), f.getBody().getNumAddresses(), arity(f),
                countCallers(f.getEntryPoint().getOffset()),
                isEntry ? "" : "<<< NOT A FUNCTION ENTRY (inside " + f.getName() + ")"));
        }

        w("");
        w("================ B: function inventory 0x409000..0x410000 ================");
        FunctionIterator fi = fm.getFunctions(toAddr(0x409000L), true);
        int cnt = 0;
        while (fi.hasNext()) {
            Function f = fi.next();
            long ep = f.getEntryPoint().getOffset();
            if (ep >= 0x410000L) break;
            w(String.format("  %08X size=%-5d callers=%-3d %-18s %s", ep, f.getBody().getNumAddresses(),
                countCallers(ep), f.getName(), arity(f)));
            cnt++;
        }
        w("  total " + cnt);

        w("");
        w("================ C: callers of each candidate ================");
        for (int i = 0; i < CAND.length; i++) {
            w("  -- " + String.format("%08X", CAND[i]) + " " + LABEL[i]);
            int n = 0;
            for (Reference r : getReferencesTo(toAddr(CAND[i]))) {
                Function c = fm.getFunctionContaining(r.getFromAddress());
                w(String.format("     %s %-18s in %s", r.getFromAddress(), r.getReferenceType(),
                    (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
                n++;
            }
            if (n == 0) w("     none");
        }

        w("");
        w("================ D: head of each candidate ================");
        for (int i = 0; i < CAND.length; i++) {
            w("");
            w("  --- " + String.format("%08X", CAND[i]) + " " + LABEL[i]);
            dump(CAND[i], 45);
        }

        File out = new File("D:/MeteorRE/evidence/ai_anchor.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
