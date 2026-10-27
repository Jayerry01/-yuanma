// KeyTable: decode the 36-byte property-name records and find the table base reference.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class KeyTable extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String cstr(long va, int max) {
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < max; i++) {
            try {
                byte c = currentProgram.getMemory().getByte(toAddr(va + i));
                if (c == 0) break;
                t.append((c >= 32 && c < 127) ? (char) (c & 0xff) : '.');
            } catch (Exception e) { break; }
        }
        return t.toString();
    }

    void refs(long va, String label) {
        w("-- refs to " + label + " (" + String.format("%08X", va) + ")");
        int n = 0;
        for (Reference r : getReferencesTo(toAddr(va))) {
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            w(String.format("     %s  %-20s in %s", r.getFromAddress(), r.getReferenceType(),
                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
            n++;
        }
        if (n == 0) w("     none");
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();

        w("================ A: 36-byte record walk from 0x5D1900 ================");
        w("  (name inline at +0, 4-byte tail at +0x20; stride 0x24)");
        for (int i = 0; i < 10; i++) {
            long base = 0x5D1900L + (long) i * 0x24;
            StringBuilder tail = new StringBuilder();
            for (int k = 0x20; k < 0x24; k++) {
                try { tail.append(String.format("%02x ", mem.getByte(toAddr(base + k)) & 0xff)); }
                catch (Exception e) { tail.append("?? "); }
            }
            long id = 0;
            try { id = mem.getInt(toAddr(base + 0x20)) & 0xffffffffL; } catch (Exception e) {}
            w(String.format("   %08X  name=\"%-20s\"  +0x20=%s (int=%d)", base, cstr(base, 32), tail.toString().trim(), id));
        }

        w("");
        w("================ B: table-base candidates ================");
        refs(0x5D1900L, "\"const\"");
        refs(0x5D190CL, "\"function call\\n\"");
        refs(0x5D191CL, "\"TEXT:%s\"");
        refs(0x5D1930L, "\"action\"");
        refs(0x5D1954L, "\"attack\"");

        w("");
        w("================ C: .data around 0x5AEE88..0x5AEF00 ================");
        for (long a = 0x5AEE88L; a < 0x5AEF00L; a += 4) {
            long v = 0;
            try { v = mem.getInt(toAddr(a)) & 0xffffffffL; } catch (Exception e) { continue; }
            String tag = "";
            if (v >= 0x5C0000L && v < 0x5E0000L) tag = "-> \"" + cstr(v, 28) + "\"";
            else if (v >= 0x400000L && v < 0x600000L) {
                Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(v));
                tag = (f != null ? "-> " + f.getName() : "-> <?>");
            }
            w(String.format("   [%08X] = %08X %s", a, v, tag));
        }

        File out = new File("D:/MeteorRE/evidence/keytable.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
