// Probe: is the cmd 0x0F arity mismatch caused by a wrong receiver class?
// Reads +0x12C on three vtable bases and dumps whatever sits there.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Vt12cProbe extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    long dword(Memory mem, long va) {
        try { return mem.getInt(toAddr(va)) & 0xffffffffL; }
        catch (Exception e) { return -1; }
    }

    String fn(FunctionManager fm, long va) {
        if (va <= 0 || va == 0xffffffffL) return "<none>";
        Function f = fm.getFunctionContaining(toAddr(va));
        if (f == null) return "<no function>";
        return f.getName() + " entry=" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses();
    }

    void dumpBody(Function f, int max) {
        if (f == null) { w("  (null)"); return; }
        Listing lst = currentProgram.getListing();
        Address a = f.getEntryPoint();
        Address end = f.getBody().getMaxAddress();
        int n = 0;
        InstructionIterator it = lst.getInstructions(a, true);
        while (it.hasNext() && n < max) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            byte[] b = null;
            try { b = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (b != null) for (int i = 0; i < b.length && i < 8; i++)
                hex.append(String.format("%02x ", b[i] & 0xff));
            w(String.format("  %s  %-24s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
        if (n >= max) w("  ... (truncated at " + max + ")");
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();

        long[] bases = { 0x5A9FE0L, 0x5AA6A8L, 0x5AA658L };
        String[] names = { "dispatcher 0x5A9FE0", "inputObj   0x5AA6A8", "canonical  0x5AA658" };

        w("================ A: +0x12C on three bases ================");
        long dispTgt = -1;
        for (int i = 0; i < bases.length; i++) {
            long b = bases[i];
            long slot = b + 0x12C;
            long t = dword(mem, slot);
            w(String.format("%s : mem[%08X] = %08X  -> %s", names[i], slot, t, fn(fm, t)));
            if (i == 0) dispTgt = t;
            long t3 = dword(mem, b + 0x0C);
            w(String.format("        slot3  mem[%08X] = %08X  -> %s", b + 0x0C, t3, fn(fm, t3)));
        }

        w("");
        w("================ B: sanity anchors on 0x5A9FE0 ================");
        long[][] san = { {0x5A9FE0L + 0x1E8, 0x4BC100L}, {0x5A9FE0L + 0x07C, 0x4BC710L} };
        for (long[] p : san) {
            long v = dword(mem, p[0]);
            w(String.format("mem[%08X] = %08X  %s  (expected %08X)",
                p[0], v, (v == p[1] ? "OK" : "MISMATCH"), p[1]));
        }

        w("");
        w("================ C: dword run 0x5A9FE0+0x100 .. +0x160 ================");
        for (long off = 0x100; off <= 0x160; off += 4) {
            long v = dword(mem, 0x5A9FE0L + off);
            w(String.format("  +0x%03X  mem[%08X] = %08X  -> %s", off, 0x5A9FE0L + off, v, fn(fm, v)));
        }

        w("");
        w("================ D: body of the 0x5A9FE0+0x12C target ================");
        Function f12c = (dispTgt > 0) ? fm.getFunctionContaining(toAddr(dispTgt)) : null;
        w("  target = " + Long.toHexString(dispTgt) + "  " + fn(fm, dispTgt));
        dumpBody(f12c, 120);

        w("");
        w("================ E: immediate 0x5A9FE0 written anywhere? ================");
        int hits = 0;
        InstructionIterator all = currentProgram.getListing().getInstructions(true);
        while (all.hasNext() && hits < 40) {
            Instruction ins = all.next();
            for (int op = 0; op < ins.getNumOperands(); op++) {
                Object[] objs = ins.getOpObjects(op);
                for (Object o : objs) {
                    if (o instanceof Scalar) {
                        long v = ((Scalar) o).getUnsignedValue();
                        if (v == 0x5A9FE0L) {
                            Function c = fm.getFunctionContaining(ins.getAddress());
                            w(String.format("  %s  %-22s in %s", ins.getAddress(), ins.toString(),
                                (c == null ? "?" : c.getName() + "@" + c.getEntryPoint())));
                            hits++;
                        }
                    }
                }
            }
        }
        if (hits == 0) w("  no immediate 0x5A9FE0 found (vtable base may be built by lea/copy)");

        w("");
        w("================ F: summary ================");
        w("  dispatcher +0x12C target : " + Long.toHexString(dispTgt) + "  " + fn(fm, dispTgt));

        File out = new File("D:/MeteorRE/evidence/vt12c.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
