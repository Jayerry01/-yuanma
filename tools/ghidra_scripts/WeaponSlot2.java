// WeaponSlot2: read vtable[2] (+0x8) of all 12 weapon controllers — the anger-spend entry.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class WeaponSlot2 extends GhidraScript {

    long[] VT = {
        0x5aab00L, 0x5aae10L, 0x5aac50L, 0x5aacc0L, 0x5aada0L, 0x5aabe0L,
        0x5aad30L, 0x5aab70L, 0x5aae80L, 0x5aaef0L, 0x5aafe8L, 0x5aaf70L
    };
    String[] NAME = { "Sword", "Knife", "Gun", "Dart", "Hammer", "Blade",
                      "Guillotines", "Lance", "Brach", "HeavenLance", "Gloves", "NinjaSword" };
    long[] TARGET = { 10, 20, 50, 60, 100, 5, 30, 40, 80, 150 };

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    long dword(Memory mem, long va) {
        try { return mem.getInt(toAddr(va)) & 0xffffffffL; } catch (Exception e) { return -1; }
    }

    String tailHex(Memory mem, Function f) {
        StringBuilder s = new StringBuilder();
        try {
            Address a = f.getBody().getMaxAddress();
            for (int i = 3; i >= 0; i--) s.append(String.format("%02x ", mem.getByte(a.subtract(i)) & 0xff));
        } catch (Exception e) { return "?"; }
        return s.toString().trim();
    }

    void dumpFn(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("    (no fn at " + Long.toHexString(va) + ")"); return; }
        w(String.format("    --- %s entry=%s size=%d tail=%s", f.getName(), f.getEntryPoint(),
            f.getBody().getNumAddresses(), tailHex(currentProgram.getMemory(), f)));
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
            String mark = "";
            for (int op = 0; op < ins.getNumOperands(); op++)
                for (Object o : ins.getOpObjects(op))
                    if (o instanceof Scalar) {
                        long v = ((Scalar) o).getUnsignedValue();
                        for (long t : TARGET) if (v == t) mark = "   <<< " + v;
                    }
            w(String.format("     %s  %-18s %s%s", ins.getAddress(), hex.toString().trim(), ins.toString(), mark));
            n++;
        }
        if (n >= max) w("     ... truncated");
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();

        w("================ weapon vtable[2] (+0x8) ================");
        List<Long> uniq = new ArrayList<>();
        for (int i = 0; i < VT.length; i++) {
            long t = dword(mem, VT[i] + 8);
            Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(t));
            w(String.format("  %-12s vt=%08X  [+0x8]=%08X  %s", NAME[i], VT[i], t,
                (f == null ? "<none>" : f.getName() + " size=" + f.getBody().getNumAddresses())));
            if (!uniq.contains(t)) uniq.add(t);
        }
        w("  distinct targets: " + uniq.size());

        w("");
        w("================ bodies of distinct targets ================");
        for (long t : uniq) {
            w("");
            dumpFn(t, 110);
        }

        File out = new File("D:/MeteorRE/evidence/weapon_slot2.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
