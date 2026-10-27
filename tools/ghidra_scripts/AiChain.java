// AiChain: identify the tick's dispatch slot, the hub, and what 0x40D040 actually is.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class AiChain extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String arity(Function f) {
        if (f == null) return "?";
        try {
            Address mx = f.getBody().getMaxAddress();
            byte last = currentProgram.getMemory().getByte(mx);
            if ((last & 0xff) == 0xC3) return "RET(0)";
            if ((last & 0xff) == 0xC2) {
                int lo = currentProgram.getMemory().getByte(mx.subtract(2)) & 0xff;
                int hi = currentProgram.getMemory().getByte(mx.subtract(1)) & 0xff;
                return "RET 0x" + Integer.toHexString(lo | (hi << 8));
            }
            return String.format("ends %02x", last & 0xff);
        } catch (Exception e) { return "?"; }
    }

    void refs(long va, String label) {
        w("  -- refs to " + label + " (" + String.format("%08X", va) + ")");
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(va))) {
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            long from = r.getFromAddress().getOffset();
            String where = (from >= 0x5A0000L && from < 0x600000) ? "  [DATA]" : "";
            w(String.format("     %s %-20s in %s%s", r.getFromAddress(), r.getReferenceType(),
                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint()), where));
            n++;
        }
        if (n == 0) w("     none");
    }

    void range(long a, long b) {
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(toAddr(a), true);
        int n = 0;
        while (it.hasNext() && n < 200) {
            Instruction ins = it.next();
            long p = ins.getAddress().getOffset();
            if (p > b) break;
            byte[] by = null;
            try { by = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (by != null) for (int i = 0; i < by.length && i < 6; i++) hex.append(String.format("%02x ", by[i] & 0xff));
            w(String.format("     %s  %-20s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
    }

    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();

        w("================ A: the thunk that dispatches 0x40A2A0 ================");
        Function th = fm.getFunctionContaining(toAddr(0x408EF0L));
        w("  0x408EF0 in " + (th == null ? "?" : th.getName() + " entry=" + th.getEntryPoint()
            + " size=" + th.getBody().getNumAddresses()));
        refs(0x408EF0L, "thunk 0x408EF0");

        w("");
        w("================ B: the hub FUN_0040BBE0 ================");
        Function hub = fm.getFunctionContaining(toAddr(0x40BBE0L));
        w("  hub: entry=" + hub.getEntryPoint() + " size=" + hub.getBody().getNumAddresses() + " " + arity(hub));
        Set<String> callers = new LinkedHashSet<>();
        for (Reference r : getReferencesTo(toAddr(0x40BBE0L))) {
            Function c = fm.getFunctionContaining(r.getFromAddress());
            callers.add(c == null ? "?" : c.getName() + "@" + c.getEntryPoint());
        }
        w("  distinct callers: " + callers.size());
        for (String s : callers) w("     " + s);

        w("");
        w("================ C: what is at 0x40D040 (inside FUN_0040CD10) ================");
        Function cd = fm.getFunctionContaining(toAddr(0x40CD10L));
        w("  FUN_0040CD10: entry=" + cd.getEntryPoint() + " size=" + cd.getBody().getNumAddresses()
          + " " + arity(cd));
        w("  0x40D040 offset inside = +0x" + Long.toHexString(0x40D040L - 0x40CD10L));
        w("  bytes 0x40D030..0x40D060:");
        range(0x40D030L, 0x40D060L);
        w("  is 0x40D040 a branch target? (search JMP/Jcc to it in this function)");
        int hits = 0;
        InstructionIterator it = currentProgram.getListing().getInstructions(cd.getEntryPoint(), true);
        Address end = cd.getBody().getMaxAddress();
        while (it.hasNext()) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            for (int op = 0; op < ins.getNumOperands(); op++)
                for (Object o : ins.getOpObjects(op))
                    if (o instanceof ghidra.program.model.scalar.Scalar) {
                        long v = ((ghidra.program.model.scalar.Scalar) o).getUnsignedValue();
                        if (v == 0x40D040L) { w("     " + ins.getAddress() + "  " + ins); hits++; }
                    }
        }
        if (hits == 0) w("     no instruction references 0x40D040 by immediate");

        w("");
        w("================ D: heads ================");
        for (long va : new long[] { 0x40A2A0L, 0x40BBE0L, 0x40C040L, 0x40CD10L }) {
            w("");
            w("  --- head of " + String.format("%08X", va));
            Function f = fm.getFunctionContaining(toAddr(va));
            if (f == null) { w("     <none>"); continue; }
            int n = 0;
            InstructionIterator i2 = currentProgram.getListing().getInstructions(f.getEntryPoint(), true);
            Address e2 = f.getBody().getMaxAddress();
            while (i2.hasNext() && n < 30) {
                Instruction ins = i2.next();
                if (ins.getAddress().compareTo(e2) > 0) break;
                byte[] by = null;
                try { by = ins.getBytes(); } catch (Exception x) {}
                StringBuilder hex = new StringBuilder();
                if (by != null) for (int i = 0; i < by.length && i < 6; i++) hex.append(String.format("%02x ", by[i] & 0xff));
                w(String.format("     %s  %-20s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
                n++;
            }
        }

        File out = new File("D:/MeteorRE/evidence/ai_chain.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
