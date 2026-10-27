// Weapon.java - the 12-weapon factory: extract candidate vtables and slot 21
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Weapon extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    String slotInfo(long base, int s) {
        try {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            return String.format("slot %2d -> 0x%08x  %s", s, p,
                f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses());
        } catch (Exception e) { return "slot " + s + " ?? (unreadable)"; }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/weapon.txt")));

        Function f = getFunctionContaining(toAddr(0x004e3d80L));
        if (f == null) { out.println("no func at 0x4e3d80"); out.close(); return; }
        out.println("########## A: FUN_004e3d80 (factory) body, " + f.getBody().getNumAddresses() + " B ##########");

        Set<Long> cand = new LinkedHashSet<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
            for (int op = 0; op < i.getNumOperands(); op++) {
                for (Object o : i.getOpObjects(op)) {
                    long v = -1;
                    if (o instanceof Scalar) v = ((Scalar) o).getUnsignedValue();
                    else if (o instanceof Address) v = ((Address) o).getOffset();
                    if (v >= 0x005a0000L && v < 0x005b0000L) cand.add(v);
                }
            }
            if (++n > 130) { out.println("  ..."); break; }
        }

        out.println("\n########## B: candidate data addresses found, with slot 0 and slot 21 ##########");
        for (long c : cand) {
            int v0 = mem.getInt(toAddr(c));
            long p0 = v0 & 0xffffffffL;
            Function g = getFunctionContaining(toAddr(p0));
            out.println(String.format("\n  cand 0x%08x -> [0] = 0x%08x  %s", c, p0,
                g == null ? "(not code)" : g.getName() + " size=" + g.getBody().getNumAddresses()));
            if (g != null) {
                out.println("     " + slotInfo(c, 0));
                out.println("     " + slotInfo(c, 21));
                out.println("     " + slotInfo(c, 22) + "   (neighbour)");
            }
        }
        out.close();
        println("DONE -> weapon.txt");
    }
}
