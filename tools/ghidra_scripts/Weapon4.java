// Weapon4.java - weapon type 0 real ctor -> vtable -> slot 21
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Weapon4 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    String slotInfo(long base, int s) throws Exception {
        int v = mem.getInt(toAddr(base + s * 4L));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        return String.format("+0x%03x slot %2d -> 0x%08x  %s", s * 4, s, p,
            f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses());
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/weapon4.txt")));

        out.println("########## A: static object 0x666640 first dwords ##########");
        for (int k = 0; k < 3; k++) {
            int v = mem.getInt(toAddr(0x00666640L + k * 4L));
            out.println(String.format("  [0x%08x] = 0x%08x", 0x00666640L + k * 4L, v));
        }

        out.println("\n########## B: ctor FUN_004dd170 body (vtable write?) ##########");
        Function f = getFunctionContaining(toAddr(0x004dd170L));
        out.println("  " + (f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses()));
        Set<Long> vt = new LinkedHashSet<>();
        if (f != null) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("   " + i.getAddress() + "  " + i.toString());
                for (int op = 0; op < i.getNumOperands(); op++)
                    for (Object o : i.getOpObjects(op))
                        if (o instanceof Scalar) {
                            long v = ((Scalar) o).getUnsignedValue();
                            if (v >= 0x005a0000L && v < 0x005b0000L) vt.add(v);
                        }
                if (++n > 90) { out.println("   ..."); break; }
            }
        }

        out.println("\n########## C: candidate vtables from the ctor, slot 21 ##########");
        for (long b : vt) {
            out.println("\n  candidate 0x" + Long.toHexString(b));
            out.println("     " + slotInfo(b, 0));
            out.println("     " + slotInfo(b, 21));
            out.println("     " + slotInfo(b, 22));
        }
        out.close();
        println("DONE -> weapon4.txt");
    }
}
