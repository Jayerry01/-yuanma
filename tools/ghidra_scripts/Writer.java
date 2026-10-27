// Writer.java - who writes the 3-state selector [A+0xdc]?
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class Writer extends GhidraScript {
    PrintWriter out;
    Listing lst;

    void ctx(long entry, String needle) throws Exception {
        Function f = getFunctionContaining(toAddr(entry));
        if (f == null) { out.println("  no func @ " + Long.toHexString(entry)); return; }
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        out.println("\n== context in " + f.getName() + " size=" + f.getBody().getNumAddresses() + " ==");
        for (int i = 0; i < buf.size(); i++) {
            if (!buf.get(i).toString().contains(needle)) continue;
            int lo = Math.max(0, i - 6), hi = Math.min(buf.size() - 1, i + 6);
            out.println("  --- hit @" + buf.get(i).getAddress() + " ---");
            for (int k = lo; k <= hi; k++)
                out.println((k == i ? "  >> " : "     ") + buf.get(k).getAddress() + "  " + buf.get(k).toString());
        }
    }

    public void run() throws Exception {
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/writer.txt")));

        out.println("########## A: every write to [reg + 0xdc] ##########");
        Set<Long> funcs = new LinkedHashSet<>();
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (!t.startsWith("MOV")) continue;
                if (!t.contains("+ 0xdc]")) continue;
                // only stores: destination operand is the memory ref
                if (!t.startsWith("MOV dword ptr [") && !t.startsWith("MOV byte ptr [")) continue;
                if (t.indexOf('[') > 0 && t.indexOf(',') > 0 && t.indexOf('[') < t.indexOf(',')) {
                    // store (memory is first operand)
                } else continue;
                boolean aClass = false;
                Function g = f;
                InstructionIterator ait = lst.getInstructions(g.getBody(), true);
                while (ait.hasNext()) { String s2 = ait.next().toString();
                    if (s2.contains("0x2e8") || s2.contains("0x34c") || s2.contains("0x348")) { aClass = true; break; } }
                out.println("  " + i.getAddress() + "  " + t + "   in " + f.getName()
                    + " size=" + f.getBody().getNumAddresses() + (aClass ? "  [A-CLASS]" : ""));
                if (aClass) funcs.add(f.getEntryPoint().getOffset());
            }
        }
        out.println("A-class writer functions: " + funcs.size());

        out.println("\n########## B: context in each A-class writer ##########");
        for (long e : funcs) ctx(e, "+ 0xdc]");

        out.println("\n########## C: A.slot[32] target (FUN_004cf5b0 case 0 calls it) ##########");
        int v = currentProgram.getMemory().getInt(toAddr(0x005aa6a8L + 32 * 4L));
        long p = v & 0xffffffffL;
        Function f32 = getFunctionContaining(toAddr(p));
        out.println("  slot 32 -> 0x" + Long.toHexString(p) + "  "
            + (f32 == null ? "?" : f32.getName() + " size=" + f32.getBody().getNumAddresses()));
        if (f32 != null) ctx(f32.getEntryPoint().getOffset(), "+ 0xdc]");

        out.close();
        println("DONE -> writer.txt");
    }
}
