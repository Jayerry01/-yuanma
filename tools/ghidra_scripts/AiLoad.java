// AiLoad: xref the NPC-script / waypoint loader strings — the real AI anchors.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class AiLoad extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String arity(Function f) {
        if (f == null) return "?";
        try {
            Address mx = f.getBody().getMaxAddress();
            Memory m = currentProgram.getMemory();
            byte last = m.getByte(mx);
            if ((last & 0xff) == 0xC3) return "RET(0)";
            if ((last & 0xff) == 0xC2) {
                int lo = m.getByte(mx.subtract(2)) & 0xff;
                int hi = m.getByte(mx.subtract(1)) & 0xff;
                return "RET 0x" + Integer.toHexString(lo | (hi << 8));
            }
            return String.format("ends %02x", last & 0xff);
        } catch (Exception e) { return "?"; }
    }

    void refs(long va, String txt) {
        w("  -- \"" + txt + "\" @ " + String.format("%08X", va));
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(va))) {
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            w(String.format("     %s %-14s in %s %s", r.getFromAddress(), r.getReferenceType(),
                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint()),
                (c == null ? "" : "size=" + c.getBody().getNumAddresses() + " " + arity(c))));
            n++;
        }
        if (n == 0) w("     none");
    }

    void dump(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("     <none>"); return; }
        w("     [" + f.getName() + " entry=" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses() + "]");
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
            String ex = "";
            for (int op = 0; op < ins.getNumOperands(); op++) {
                Address da = null;
                try { da = ins.getAddress(op); } catch (Exception e) {}
                if (da != null && da.getOffset() >= 0x5C0000L && da.getOffset() < 0x5D4000L) {
                    StringBuilder t = new StringBuilder();
                    for (int i = 0; i < 28; i++) {
                        try { byte c = currentProgram.getMemory().getByte(toAddr(da.getOffset() + i));
                              if (c == 0) break; t.append((char) (c & 0xff)); } catch (Exception e) { break; }
                    }
                    ex = "   ; \"" + t + "\"";
                }
            }
            w(String.format("       %s  %-20s %s%s", ins.getAddress(), hex.toString().trim(), ins.toString(), ex));
            n++;
        }
    }

    public void run() throws Exception {
        w("================ A: string xrefs ================");
        refs(0x5C9B18L, "Load NPC %s.pst error");
        refs(0x5C9BBCL, "Waypoints %d");
        refs(0x5C9BECL, "%s.wp");
        refs(0x5C9AECL, "Level\\%s_.pst");
        refs(0x5C9AFCL, "Load %s.wp error");
        refs(0x5C9FF0L, "RemoveNPC");

        w("");
        w("================ B: bodies ================");
        for (long va : new long[] { 0x5C9B18L, 0x5C9BBCL }) {
            w("");
            w("  === xref target of " + String.format("%08X", va) + " ===");
            for (Reference r : getReferencesTo(toAddr(va))) {
                Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
                if (c != null) dump(c.getEntryPoint().getOffset(), 55);
                break;
            }
        }

        File out = new File("D:/MeteorRE/evidence/ai_load.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
