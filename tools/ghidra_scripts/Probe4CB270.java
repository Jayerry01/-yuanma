// Probe4CB270.java — why is there no function at 0x4CB270? Report container + neighborhood.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;

public class Probe4CB270 extends GhidraScript {
    public void run() throws Exception {
        long[] probes = { 0x4CB270L, 0x4CB268L, 0x4CB271L, 0x4CB26FL };
        for (long off : probes) {
            Address a = toAddr(off);
            Function f = currentProgram.getFunctionManager().getFunctionContaining(a);
            Function fAt = currentProgram.getFunctionManager().getFunctionAt(a);
            printf("0x%08x containing=%s at=%s\n", off,
                f == null ? "NONE" : (f.getName() + " entry=0x" + Long.toHexString(f.getEntryPoint().getOffset())),
                fAt == null ? "-" : fAt.getName());
        }
        // list every function whose body spans +-0x400 around 0x4CB270
        Address lo = toAddr(0x4CB270L - 0x400L);
        Address hi = toAddr(0x4CB270L + 0x400L);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(lo, true);
        java.util.List<String> hits = new java.util.ArrayList<String>();
        while (it.hasNext() && hits.size() < 40) {
            Function f = it.next();
            if (f.getEntryPoint().compareTo(hi) > 0) break;
            hits.add(String.format("  FUN_%08x size=%d body=0x%x..0x%x",
                f.getEntryPoint().getOffset(), (int)f.getBody().getNumAddresses(),
                f.getBody().getMinAddress().getOffset(), f.getBody().getMaxAddress().getOffset()));
        }
        printf("NEIGHBORHOOD FUNCS around 0x4cb270:\n");
        for (String s : hits) println(s);
    }
}
