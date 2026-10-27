// Sites.java - context for the four +0x174 call sites
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class Sites extends GhidraScript {
    PrintWriter out;
    Listing lst;

    void ctx(long at, int before, int after) throws Exception {
        Function f = getFunctionContaining(toAddr(at));
        if (f == null) { out.println("  no func for " + Long.toHexString(at)); return; }
        List<Instruction> buf = new ArrayList<>();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) buf.add(it.next());
        int idx = -1;
        for (int i = 0; i < buf.size(); i++) if (buf.get(i).getAddress().getOffset() == at) { idx = i; break; }
        out.println("\n== " + f.getName() + " size=" + f.getBody().getNumAddresses()
            + "   site 0x" + Long.toHexString(at) + " ==");
        if (idx < 0) { out.println("  (site not found in body)"); return; }
        int lo = Math.max(0, idx - before), hi = Math.min(buf.size() - 1, idx + after);
        for (int k = lo; k <= hi; k++)
            out.println((k == idx ? "  >> " : "     ") + buf.get(k).getAddress() + "  " + buf.get(k).toString());
    }

    public void run() throws Exception {
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/sites.txt")));
        ctx(0x004bb849L, 22, 6);
        ctx(0x004dcc40L, 14, 6);
        ctx(0x004efb69L, 12, 6);
        ctx(0x0048c55eL, 10, 5);
        out.close();
        println("DONE -> sites.txt");
    }
}
