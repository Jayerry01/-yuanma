// Setterslot.java - find the vtable slot holding FUN_004d0500, then all virtual callers of that slot
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Setterslot extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/setterslot.txt")));

        out.println("########## A: find slots holding 0x004d0500 ##########");
        long[] bases = {0x005aa660L, 0x005aa6a8L};
        String[] offs = new String[2];
        for (int b = 0; b < bases.length; b++) {
            for (int s = 0; s < 220; s++) {
                int v;
                try { v = mem.getInt(toAddr(bases[b] + s * 4L)); } catch (Exception e) { break; }
                if ((v & 0xffffffffL) == 0x004d0500L) {
                    out.println(String.format("  base 0x%08x slot %3d (+0x%03x) -> 0x004d0500",
                        bases[b], s, s * 4));
                    offs[b] = String.format("+ 0x%x]", s * 4);
                }
            }
        }

        out.println("\n########## B: virtual call sites for each slot offset ##########");
        for (String needle : offs) {
            if (needle == null) continue;
            out.println("\n  ---- scanning CALL [... " + needle + " ----");
            int n = 0;
            for (Function f : lst.getFunctions(true)) {
                InstructionIterator it = lst.getInstructions(f.getBody(), true);
                while (it.hasNext()) {
                    Instruction i = it.next();
                    String t = i.toString();
                    if (!t.startsWith("CALL dword ptr [")) continue;
                    if (!t.contains(needle)) continue;
                    out.println("    " + i.getAddress() + "  " + t + "   in " + f.getName()
                        + " size=" + f.getBody().getNumAddresses());
                    n++;
                }
            }
            out.println("    total = " + n);
        }
        out.close();
        println("DONE -> setterslot.txt");
    }
}
