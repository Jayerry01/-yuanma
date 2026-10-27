// Caller.java - who drives the movement samplers, and what else runs alongside
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class Caller extends GhidraScript {
    PrintWriter out;
    Set<Long> visited = new HashSet<>();

    void dump(long va, int max) throws Exception {
        Address a = toAddr(va);
        Function f = getFunctionContaining(a);
        if (f == null) { out.println("   no func at " + Long.toHexString(va)); return; }
        if (!visited.add(f.getEntryPoint().getOffset())) return;
        out.println("\n===== CALLER " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
            if (max > 0 && ++n >= max) { out.println("  ..."); break; }
        }
    }

    void callersOf(long va, int depth, int maxLines) throws Exception {
        Address a = toAddr(va);
        Function f = getFunctionContaining(a);
        out.println("\n######## callers of " + (f == null ? Long.toHexString(va) : f.getName()) + " ########");
        for (Reference r : getReferencesTo(f == null ? a : f.getEntryPoint())) {
            if (r.getReferenceType().isCall() || r.getReferenceType().isJump()) {
                Function c = getFunctionContaining(r.getFromAddress());
                out.println("  " + r.getFromAddress() + " -> " + (c == null ? "?" : c.getName()
                    + " size=" + c.getBody().getNumAddresses()));
            }
        }
        if (depth > 0) {
            for (Reference r : getReferencesTo(f == null ? a : f.getEntryPoint())) {
                Function c = getFunctionContaining(r.getFromAddress());
                if (c != null && !visited.contains(c.getEntryPoint().getOffset())) {
                    dump(c.getEntryPoint().getOffset(), maxLines);
                    callersOf(c.getEntryPoint().getOffset(), depth - 1, maxLines);
                }
            }
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/callers.txt")));
        callersOf(0x004cb260L, 1, 0);   // movement sampler
        callersOf(0x00503020L, 1, 0);   // its twin
        out.close();
        println("DONE -> callers.txt");
    }
}
