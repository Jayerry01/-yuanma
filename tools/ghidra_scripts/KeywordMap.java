// KeywordMap: dump the token->id mapper that references "action"/"attack"/"angervalue".
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class KeywordMap extends GhidraScript {

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

    void dump(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("  (none at " + Long.toHexString(va) + ")"); return; }
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
            String extra = "";
            for (int op = 0; op < ins.getNumOperands(); op++) {
                Address da = null;
                try { da = ins.getAddress(op); } catch (Exception e) {}
                if (da != null && da.getOffset() >= 0x5C0000L && da.getOffset() < 0x5E0000L) {
                    extra = "   ; \"" + cstr(da.getOffset(), 24) + "\"";
                }
            }
            w(String.format("   %s  %-20s %s%s", ins.getAddress(), hex.toString().trim(), ins.toString(), extra));
            n++;
        }
        if (n >= max) w("   ... truncated");
    }

    public void run() throws Exception {
        w("================ A: inventory 0x57A000..0x57C000 ================");
        FunctionIterator fi = currentProgram.getFunctionManager().getFunctions(toAddr(0x57A000L), true);
        while (fi.hasNext()) {
            Function f = fi.next();
            long ep = f.getEntryPoint().getOffset();
            if (ep > 0x57C000L) break;
            w(String.format("  %08X  size=%-5d %s", ep, f.getBody().getNumAddresses(), f.getName()));
        }

        w("");
        w("================ B: FUN_0057A770 ================");
        dump(0x57A770L, 80);

        w("");
        w("================ C: callers of 0x57A770 ================");
        for (Reference r : getReferencesTo(toAddr(0x57A770L))) {
            Function c = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
            w(String.format("   %s  %-20s in %s", r.getFromAddress(), r.getReferenceType(),
                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
        }

        File out = new File("D:/MeteorRE/evidence/keywordmap.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
