// TimerProbe: settle what 0.11 measures.
// A) timer module inventory (0x549800..0x549C00) with arity
// B) full bodies with bytes: ctor / set / advance / ratio / predicates
// C) who writes [obj+0x38] inside the module
// D) full bodies of 0x4CF540 (slot 85) and 0x4CF5B0 (slot 86)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class TimerProbe extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String tail(Function f) {
        if (f == null) return "?";
        try {
            Address a = f.getBody().getMaxAddress();
            byte[] b = new byte[3];
            for (int i = 0; i < 3; i++) b[i] = currentProgram.getMemory().getByte(a.subtract(2 - i));
            // last byte
            byte last = currentProgram.getMemory().getByte(a);
            if ((last & 0xff) == 0xC3) return "RET (0 args)";
            if ((last & 0xff) == 0xC2) {
                int n = (b[1] & 0xff) | ((b[2] & 0xff) << 8);
                return "RET 0x" + Integer.toHexString(n) + " (" + (n / 4) + " args)";
            }
            return "ends with " + String.format("%02x", last & 0xff);
        } catch (Exception e) { return "?err"; }
    }

    void dumpFn(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("  (no function at " + Long.toHexString(va) + ")"); return; }
        w("  --- " + f.getName() + " entry=" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses()
          + " tail=" + tail(f) + " ---");
        Listing lst = currentProgram.getListing();
        Address end = f.getBody().getMaxAddress();
        InstructionIterator it = lst.getInstructions(f.getEntryPoint(), true);
        int n = 0;
        while (it.hasNext() && n < max) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            byte[] b = null;
            try { b = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (b != null) for (int i = 0; i < b.length && i < 8; i++) hex.append(String.format("%02x ", b[i] & 0xff));
            w(String.format("   %s  %-24s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
        if (n >= max) w("   ... truncated at " + max);
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();

        w("================ A: timer module inventory 0x549800..0x549C00 ================");
        FunctionIterator fi = fm.getFunctions(toAddr(0x549800L), true);
        while (fi.hasNext()) {
            Function f = fi.next();
            long ep = f.getEntryPoint().getOffset();
            if (ep > 0x549C00L) break;
            w(String.format("  %08X  size=%-4d  %-18s %s", ep, f.getBody().getNumAddresses(), f.getName(), tail(f)));
        }

        w("");
        w("================ B: full bodies ================");
        long[] targets = { 0x5498C0L, 0x549950L, 0x5499A0L, 0x549A90L, 0x549B00L, 0x549B80L };
        for (long t : targets) {
            Function f = fm.getFunctionContaining(toAddr(t));
            if (f == null) continue;
            if (f.getEntryPoint().getOffset() != t) { w("  (0x" + Long.toHexString(t) + " is inside " + f.getName() + ")"); continue; }
            w("");
            dumpFn(t, 90);
        }

        w("");
        w("================ C: writes to [reg+0x38] inside the module ================");
        int hits = 0;
        InstructionIterator it = currentProgram.getListing().getInstructions(toAddr(0x549800L), true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            long a = ins.getAddress().getOffset();
            if (a > 0x549C00L) break;
            String s = ins.toString();
            if (s.contains("+ 0x38]")) {
                Function c = fm.getFunctionContaining(ins.getAddress());
                w(String.format("  %s  %-30s in %s", ins.getAddress(), s, (c == null ? "?" : c.getName())));
                hits++;
            }
        }
        if (hits == 0) w("  none");

        w("");
        w("================ D: slot 85 (0x4CF540) and slot 86 (0x4CF5B0) ================");
        w("");
        dumpFn(0x4CF540L, 70);
        w("");
        dumpFn(0x4CF5B0L, 220);

        w("");
        w("================ E: callers of the ratio function and of slot 85 ================");
        for (long t : new long[] { 0x549B00L, 0x4CF540L }) {
            w("  -- callers of 0x" + Long.toHexString(t));
            for (Reference r : getReferencesTo(toAddr(t))) {
                Function c = fm.getFunctionContaining(r.getFromAddress());
                w(String.format("     %s  %s  in %s", r.getFromAddress(), r.getReferenceType(),
                    (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
            }
        }

        File out = new File("D:/MeteorRE/evidence/timerprobe.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
