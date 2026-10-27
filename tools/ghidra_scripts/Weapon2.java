// Weapon2.java - per-weapon ctor -> vtable write -> slot 21
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Weapon2 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    long[] ctors = {0x004dd320L, 0x004e0770L, 0x004de920L, 0x004df140L, 0x004e0030L, 0x004de1d0L,
                    0x004df8e0L, 0x004dda70L, 0x004e0e80L, 0x004e18c0L, 0x004e3720L, 0x004e2e60L};

    String slotInfo(long base, int s) {
        try {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            return String.format("+0x%03x slot %2d -> 0x%08x  %s", s * 4, s, p,
                f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses());
        } catch (Exception e) { return "slot " + s + " unreadable"; }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/weapon2.txt")));

        for (int k = 0; k < ctors.length; k++) {
            long c = ctors[k];
            Function f = getFunctionContaining(toAddr(c));
            out.println("\n########## type " + k + "  ctor 0x" + Long.toHexString(c)
                + "  " + (f == null ? "(no func)" : "size=" + f.getBody().getNumAddresses()) + " ##########");
            if (f == null) continue;

            Set<Long> vt = new LinkedHashSet<>();
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                // vfptr stores look like: MOV dword ptr [reg ...],0x5aXXXX
                if (t.startsWith("MOV dword ptr [") && t.contains(",0x5a")) {
                    for (int op = 1; op < i.getNumOperands(); op++)
                        for (Object o : i.getOpObjects(op))
                            if (o instanceof Scalar) {
                                long v = ((Scalar) o).getUnsignedValue();
                                if (v >= 0x005a0000L && v < 0x005b0000L) {
                                    vt.add(v);
                                    out.println("   vfptr store @" + i.getAddress() + "  " + t);
                                }
                            }
                }
                if (++n > 400) break;
            }
            if (vt.isEmpty()) { out.println("   (no 0x5aXXXX store in first 400 insns)"); continue; }
            for (long b : vt) {
                out.println("   vtable candidate 0x" + Long.toHexString(b));
                out.println("      " + slotInfo(b, 0));
                out.println("      " + slotInfo(b, 21));
                out.println("      " + slotInfo(b, 22));
            }
        }
        out.close();
        println("DONE -> weapon2.txt");
    }
}
