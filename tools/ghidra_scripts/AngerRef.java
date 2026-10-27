// AngerRef: who reads "angervalue" / "KEY_angervalue", and what the key table looks like.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;

public class AngerRef extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    void refs(long va) {
        w("=== refs to " + String.format("%08X", va) + " ===");
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(va))) {
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            w(String.format("   %s  %-22s in %s", r.getFromAddress(), r.getReferenceType(),
                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
            n++;
        }
        if (n == 0) w("   none");
        w("");
    }

    void dumpFn(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("  (no fn at " + Long.toHexString(va) + ")"); return; }
        w("  --- " + f.getName() + " entry=" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
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
            w(String.format("   %s  %-20s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();

        w("================ A: string refs ================");
        refs(0x5D1978L);  // attacktype
        refs(0x5D199CL);  // attackvalue
        refs(0x5D19C0L);  // angertype
        refs(0x5D19E4L);  // angervalue
        refs(0x5D239CL);  // KEY_angervalue
        refs(0x5D23ACL);  // KEY_angertype

        w("================ B: KEY_ table layout around 0x5D2300..0x5D2400 ================");
        for (long a = 0x5D2300L; a < 0x5D2400L; a += 4) {
            long v = 0;
            try { v = mem.getInt(toAddr(a)) & 0xffffffffL; } catch (Exception e) { continue; }
            String tag = "";
            if (v >= 0x5C0000L && v < 0x5E0000L) {
                // likely a char* ; print a few bytes
                StringBuilder t = new StringBuilder();
                for (int i = 0; i < 24; i++) {
                    try {
                        byte c = mem.getByte(toAddr(v + i));
                        if (c == 0) break;
                        t.append((char) (c & 0xff));
                    } catch (Exception e) { break; }
                }
                tag = "-> \"" + t + "\"";
            }
            w(String.format("   [%08X] = %08X %s", a, v, tag));
        }

        File out = new File("D:/MeteorRE/evidence/anger_ref.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
