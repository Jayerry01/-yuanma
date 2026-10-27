// Slots10.java - FUN_004cc130 fan-out + resolve slots 51..60 on 12 weapon vtables
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Slots10 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    long[] vt = {0x005aab00L, 0x005aae10L, 0x005aac50L, 0x005aacc0L, 0x005aada0L, 0x005aabe0L,
                 0x005aad30L, 0x005aab70L, 0x005aae80L, 0x005aaef0L, 0x005aafe8L, 0x005aaf70L};

    String tgt(long base, int slot) {
        try {
            int v = mem.getInt(toAddr(base + slot * 4L));
            long p = v & 0xffffffffL;
            Function f = getFunctionContaining(toAddr(p));
            return String.format("0x%08x %s", p,
                f == null ? "?" : f.getName() + "(" + f.getBody().getNumAddresses() + ")");
        } catch (Exception e) { return "unreadable"; }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/slots10.txt")));

        out.println("########## A: fan-out calls in FUN_004cc130 with disp 0xcc..0xf0 ##########");
        Function f = getFunctionContaining(toAddr(0x004cc130L));
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        int n = 0;
        for (int i = 0; i < buf.size(); i++) {
            Instruction ins = buf.get(i);
            String t = ins.toString();
            if (!t.startsWith("CALL dword ptr [")) continue;
            for (int op = 0; op < ins.getNumOperands(); op++)
                for (Object o : ins.getOpObjects(op)) {
                    long d = -1;
                    if (o instanceof Scalar) d = ((Scalar) o).getUnsignedValue();
                    if (d < 0xcc || d > 0xf0) continue;
                    n++;
                    out.println(String.format("  %d) %s  %-34s  disp=0x%02x -> slot %d",
                        n, ins.getAddress(), t, d, d / 4));
                    for (int k = Math.max(0, i - 4); k < i; k++)
                        out.println("        ctx " + buf.get(k).getAddress() + "  " + buf.get(k));
                }
        }
        out.println("  total fan-out sites = " + n);

        out.println("\n########## B: slots 51..60 on each weapon vtable (distinct-count test) ##########");
        for (int k = 0; k < vt.length; k++) {
            Set<String> distinct = new LinkedHashSet<>();
            StringBuilder row = new StringBuilder();
            for (int s = 51; s <= 60; s++) {
                String tt = tgt(vt[k], s);
                distinct.add(tt.split(" ")[0]);
                row.append(String.format("\n      slot %2d (+0x%02x)  %s", s, s * 4, tt));
            }
            out.println(String.format("\n  type %2d vtable 0x%08x  distinct=%d/10", k, vt[k], distinct.size()));
            out.println(row);
        }

        out.println("\n########## C: same range on the PlayerController base 0x5aa6a8 ##########");
        Set<String> dd = new LinkedHashSet<>();
        for (int s = 51; s <= 60; s++) {
            String tt = tgt(0x005aa6a8L, s);
            dd.add(tt.split(" ")[0]);
            out.println(String.format("      slot %2d (+0x%02x)  %s", s, s * 4, tt));
        }
        out.println("  distinct = " + dd.size() + "/10");
        out.close();
        println("DONE -> slots10.txt");
    }
}
