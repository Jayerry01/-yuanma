// Hop4.java - the +0x1b4 terminal on the PlayerController, and who owns [+0x348]
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class Hop4 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    void dump(long va, int max) throws Exception {
        Function f = getFunctionContaining(toAddr(va));
        if (f == null) { out.println("  no func " + Long.toHexString(va)); return; }
        out.println("\n===== " + f.getName() + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
            if (max > 0 && ++n >= max) { out.println("  ..."); break; }
        }
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/hop4.txt")));

        out.println("########## A: PlayerController slot 109 (+0x1b4) on base 0x5AA6A8 ##########");
        int v = mem.getInt(toAddr(0x005aa6a8L + 109 * 4L));
        long p = v & 0xffffffffL;
        out.println("  -> 0x" + Long.toHexString(p));
        dump(p, 12);

        out.println("\n########## B: who WRITES [reg+0x348] (the sub-object) ##########");
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (!t.startsWith("MOV dword ptr [")) continue;
                if (!t.contains("+ 0x348]")) continue;
                if (t.indexOf('[') > t.indexOf(',')) continue; // must be store
                out.println("  " + i.getAddress() + "  " + t + "   in " + f.getName()
                    + " size=" + f.getBody().getNumAddresses());
            }
        }

        out.println("\n########## C: what class is at +0x348? dump the writer's context ##########");
        Function w = getFunctionContaining(toAddr(0x004cafb0L));
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(w.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        for (int i = 0; i < buf.size(); i++) {
            if (buf.get(i).toString().contains("+ 0x348]")) {
                int lo = Math.max(0, i - 10), hi = Math.min(buf.size() - 1, i + 6);
                out.println("  --- site " + buf.get(i).getAddress() + " ---");
                for (int k = lo; k <= hi; k++)
                    out.println((k == i ? "  >> " : "     ") + buf.get(k).getAddress() + "  " + buf.get(k).toString());
            }
        }
        out.close();
        println("DONE -> hop4.txt");
    }
}
