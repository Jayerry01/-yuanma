// Count12c.java - exact census of +0x12c call sites, bucketed by module
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class Count12c extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        Listing lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/count12c.txt")));

        int callAll = 0, anyAll = 0;
        Map<String, Integer> callBucket = new TreeMap<>();
        Map<String, Integer> anyBucket = new TreeMap<>();
        List<String> callSites = new ArrayList<>();

        for (Function f : lst.getFunctions(true)) {
            long e = f.getEntryPoint().getOffset();
            String mod = String.format("0x%02x0000-0x%02xffff", (e >> 16) & 0xff, (e >> 16) & 0xff);
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (!t.contains("+ 0x12c]")) continue;
                anyAll++;
                anyBucket.merge(mod, 1, Integer::sum);
                if (t.startsWith("CALL dword ptr [")) {
                    callAll++;
                    callBucket.merge(mod, 1, Integer::sum);
                    callSites.add("    " + i.getAddress() + "  " + t + "   in " + f.getName()
                        + " size=" + f.getBody().getNumAddresses());
                }
            }
        }

        out.println("########## A: call-form  CALL dword ptr [reg + 0x12c]  ##########");
        out.println("  TOTAL = " + callAll);
        for (Map.Entry<String, Integer> e : callBucket.entrySet())
            out.println("    module " + e.getKey() + " : " + e.getValue());
        for (String s : callSites) out.println(s);

        out.println("\n########## B: any-form instructions containing + 0x12c]  ##########");
        out.println("  TOTAL = " + anyAll);
        for (Map.Entry<String, Integer> e : anyBucket.entrySet())
            out.println("    module " + e.getKey() + " : " + e.getValue());

        out.println("\n########## C: the 0x48xxxx bucket only, call-form only  ##########");
        int only48 = 0;
        for (String s : callSites) {
            long a = Long.parseLong(s.trim().split("\\s+")[0], 16);
            if (a >= 0x00480000L && a < 0x00490000L) only48++;
        }
        out.println("  call-form inside 0x480000-0x48ffff = " + only48);

        out.close();
        println("DONE -> count12c.txt");
    }
}
