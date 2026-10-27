// SlotFamily.java - find the vtable holding 0x4bc100 at slot 122, dump slots 116..128
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class SlotFamily extends GhidraScript {
    PrintWriter out;

    String describe(long va) {
        if (va == 0) return "NULL";
        try {
            Function f = getFunctionContaining(toAddr(va));
            if (f != null) return f.getName() + " size=" + f.getBody().getNumAddresses();
        } catch (Exception e) { }
        return "(not in a function)";
    }

    String readPtr(Address a) {
        try {
            return String.format("0x%08x", currentProgram.getMemory().getInt(a) & 0xffffffffL);
        } catch (Exception e) { return "????"; }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/slotfamily.txt")));
        Memory mem = currentProgram.getMemory();

        out.println("########## A: pointers to 0x004bc100 (slot 122 candidate) ##########");
        List<Long> bases = new ArrayList<>();
        for (MemoryBlock b : mem.getBlocks()) {
            if (!b.isInitialized() || !b.isRead()) continue;
            long start = b.getStart().getOffset(), end = b.getEnd().getOffset();
            if (end - start > 8 * 1024 * 1024) continue;
            for (long a = start; a < end - 4; a += 4) {
                int v;
                try { v = mem.getInt(toAddr(a)); } catch (Exception e) { break; }
                if ((v & 0xffffffffL) == 0x004bc100L) {
                    long base = a - 0x1E8L;
                    out.println("  ptr@0x" + Long.toHexString(a) + "  => vtable base would be 0x"
                        + Long.toHexString(base) + "   (block " + b.getName() + ")");
                    bases.add(base);
                }
            }
        }
        if (bases.isEmpty()) out.println("  none found");

        out.println("\n########## B: slot 116..128 of each candidate base ##########");
        for (long base : bases) {
            out.println("\n-- base 0x" + Long.toHexString(base) + " --");
            for (int s = 112; s <= 128; s++) {
                Address a = toAddr(base + s * 4L);
                String p = readPtr(a);
                String mark = (s == 120 || s == 121 || s == 122) ? "  <==" : "";
                out.println(String.format("   slot %3d (+0x%03x)  %s  %s%s",
                    s, s * 4, p, describe(Long.parseUnsignedLong(p.substring(2), 16)), mark));
            }
        }

        out.close();
        println("DONE -> slotfamily.txt");
    }
}
