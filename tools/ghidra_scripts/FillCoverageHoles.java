import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.TreeSet;

public class FillCoverageHoles extends GhidraScript {
    static final long TEXT_LO = 0x00401000L;
    static final long TEXT_HI = 0x005A7000L;

    @Override
    public void run() throws Exception {
        // 1. Gather current function bodies -> sorted intervals
        ArrayList<long[]> ivs = new ArrayList<>();
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            if (f.isExternal()) continue;
            AddressSetView b = f.getBody();
            Iterator<AddressRange> ri = b.getAddressRanges();
            while (ri.hasNext()) {
                AddressRange r = ri.next();
                ivs.add(new long[]{r.getMinAddress().getOffset(), r.getMaxAddress().getOffset()});
            }
        }
        ivs.sort((a, b2) -> Long.compare(a[0], b2[0]));
        // 2. Holes = gaps >= 16 bytes
        ArrayList<long[]> holes = new ArrayList<>();
        long cur = TEXT_LO;
        for (long[] iv : ivs) {
            if (iv[0] > cur && iv[0] - cur >= 16) holes.add(new long[]{cur, iv[0] - 1});
            cur = Math.max(cur, iv[1] + 1);
        }
        if (TEXT_HI - cur >= 16) holes.add(new long[]{cur, TEXT_HI - 1});

        // 3. Candidates
        TreeSet<Long> candidates = new TreeSet<>();
        // (a) reference targets landing inside holes
        ReferenceManager rm = currentProgram.getReferenceManager();
        ReferenceIterator rit = rm.getReferenceIterator(toAddr(0x00400000L));
        int xrefCand = 0;
        while (rit.hasNext()) {
            Reference r = rit.next();
            long to = r.getToAddress().getOffset();
            if (to > 0x00800000L) break;
            if (to >= TEXT_LO && to < TEXT_HI && inHoles(holes, to)) {
                if (candidates.add(to)) xrefCand++;
            }
        }
        // (b) prologues inside holes
        ghidra.program.model.mem.Memory mem = currentProgram.getMemory();
        for (long[] h : holes) {
            int len = (int)(h[1] - h[0] + 1);
            if (len < 8) continue;
            byte[] buf = new byte[len];
            try { mem.getBytes(toAddr(h[0]), buf); } catch (Exception e) { continue; }
            for (int i = 0; i + 2 < len; i++) {
                int b0 = buf[i] & 0xFF, b1 = buf[i+1] & 0xFF, b2 = buf[i+2] & 0xFF;
                if (b0 == 0x55 && b1 == 0x8B && b2 == 0xEC) candidates.add(h[0] + i);
                else if (i + 4 < len && b0 == 0x8B && b1 == 0xFF && b2 == 0x55) candidates.add(h[0] + i);
            }
        }
        int totalCand = candidates.size();

        // 4. Create functions
        int created = 0, failed = 0, already = 0;
        for (long c : candidates) {
            Address a = toAddr(c);
            if (currentProgram.getFunctionManager().getFunctionAt(a) != null) { already++; continue; }
            disassemble(a);
            Function nf = createFunction(a, null);
            if (nf != null) created++; else failed++;
        }
        println("CANDIDATES xref=" + xrefCand + " total=" + totalCand + " already=" + already + " created=" + created + " failed=" + failed);

        // 5. Dump v2
        String out = "D:\\MeteorProjects\\_private\\ghidra_scripts\\fresh_functions_v2.json";
        PrintWriter pw = new PrintWriter(new FileWriter(out));
        FunctionIterator it2 = currentProgram.getFunctionManager().getFunctions(true);
        StringBuilder sb = new StringBuilder("[\n");
        long totalBody = 0; int n = 0;
        while (it2.hasNext()) {
            Function f = it2.next();
            if (f.isExternal()) continue;
            long size = 0;
            AddressSetView set = f.getBody();
            if (set != null) { totalBody += set.getNumAddresses(); size = set.getNumAddresses(); }
            if (n > 0) sb.append(",\n");
            sb.append("{\"a\":\"").append(f.getEntryPoint().toString())
              .append("\",\"n\":\"").append(f.getName().replace("\\","\\\\").replace("\"","\\\""))
              .append("\",\"s\":").append(size)
              .append(",\"t\":").append(f.isThunk() ? "1" : "0").append("}");
            n++;
        }
        sb.append("\n]");
        pw.print(sb.toString()); pw.close();
        println("DUMPED_V2 internal=" + n + " totalBodyBytes=" + totalBody);
    }

    static boolean inHoles(ArrayList<long[]> holes, long a) {
        int lo = 0, hi = holes.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            long[] h = holes.get(mid);
            if (a < h[0]) hi = mid - 1;
            else if (a > h[1]) lo = mid + 1;
            else return true;
        }
        return false;
    }
}
