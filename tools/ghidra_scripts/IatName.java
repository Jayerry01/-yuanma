// IatName: name the two time IAT slots, read the constants, and find slot-85 callers.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class IatName extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    String nm(SymbolTable st, long va) {
        Symbol s = st.getPrimarySymbol(toAddr(va));
        if (s != null) return s.getName();
        // fall back: what does the pointer point at
        return "<?>";
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        SymbolTable st = currentProgram.getSymbolTable();
        FunctionManager fm = currentProgram.getFunctionManager();

        w("================ A: IAT slots used by the timer ================");
        long[] slots = { 0x5a81d4L, 0x5a81d8L, 0x5a81dcL, 0x5a81e0L };
        for (long s : slots) {
            long tgt = 0;
            try { tgt = mem.getInt(toAddr(s)) & 0xffffffffL; } catch (Exception e) {}
            w(String.format("mem[%08X] = %08X   symbol=%s   target-symbol=%s",
                s, tgt, nm(st, s), nm(st, tgt)));
        }

        w("");
        w("================ B: numeric constants ================");
        long[][] consts = {
            {0x5aa8e8L, 0}, {0x5aa8ecL, 0},
            {0x5a84b8L, 0}, {0x5a84bcL, 0},
            {0x5a9d50L, 0}, {0x5a9d54L, 0},
            {0x5aa93cL, 0}, {0x5aa940L, 0},
            {0x5a83f4L, 0}
        };
        for (long[] c : consts) {
            long lo = 0, hi = 0;
            try { lo = mem.getInt(toAddr(c[0])) & 0xffffffffL; } catch (Exception e) {}
            try { hi = mem.getInt(toAddr(c[0] + 4)) & 0xffffffffL; } catch (Exception e) {}
            double asF = Float.intBitsToFloat((int) lo);
            double asD = Double.longBitsToDouble((hi << 32) | lo);
            w(String.format("  %08X  dwords=%08X %08X   float=%s   double=%s",
                c[0], lo, hi, fmt(asF), fmt(asD)));
        }

        w("");
        w("================ C: who calls slot 85 / slot 86 (+0x154 / +0x158) ================");
        for (long off : new long[] { 0x154, 0x158 }) {
            w("  -- CALL [reg + 0x" + Long.toHexString(off) + "] sites");
            InstructionIterator it = currentProgram.getListing().getInstructions(true);
            int n = 0;
            while (it.hasNext() && n < 60) {
                Instruction ins = it.next();
                String s = ins.toString();
                if (s.startsWith("CALL") && s.contains("+ 0x" + Long.toHexString(off) + "]")) {
                    Function c = fm.getFunctionContaining(ins.getAddress());
                    w(String.format("     %s  %-26s in %s", ins.getAddress(), s,
                        (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
                    n++;
                }
            }
            if (n == 0) w("     none");
        }

        File out = new File("D:/MeteorRE/evidence/iat_time.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }

    String fmt(double d) {
        if (Double.isNaN(d) || Double.isInfinite(d)) return "-";
        if (Math.abs(d) > 1e10 || (Math.abs(d) < 1e-6 && d != 0)) return String.format("%.6e", d);
        return String.format("%.6f", d);
    }
}
