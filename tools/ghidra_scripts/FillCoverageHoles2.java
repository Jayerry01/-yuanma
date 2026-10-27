import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSetView;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.TreeSet;

// Round 2: force-create functions at every vtable slot target (from vtables.json)
// plus FPO prologues (83 EC xx / 81 EC xx) preceded by 90/CC padding inside holes.
public class FillCoverageHoles2 extends GhidraScript {
    static final long TEXT_LO = 0x00401000L;
    static final long TEXT_HI = 0x005A7000L;

    @Override
    public void run() throws Exception {
        // 1. holes from current bodies
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
        ArrayList<long[]> holes = new ArrayList<>();
        long cur = TEXT_LO;
        for (long[] iv : ivs) {
            if (iv[0] > cur && iv[0] - cur >= 16) holes.add(new long[]{cur, iv[0] - 1});
            cur = Math.max(cur, iv[1] + 1);
        }
        if (TEXT_HI - cur >= 16) holes.add(new long[]{cur, TEXT_HI - 1});

        TreeSet<Long> candidates = new TreeSet<>();

        // (a) all vtable methods from vtables.json
        int vtCount = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader("D:\\MeteorRE\\symbols\\vtables.json"));
            StringBuilder raw = new StringBuilder(); String line;
            while ((line = br.readLine()) != null) raw.append(line);
            br.close();
            String s = raw.toString();
            java.util.regex.Matcher m = java.util.regex.Pattern.compile("\"0x([0-9a-fA-F]{6,8})\"").matcher(s);
            // methods appear in "methods" arrays; the "address" field (vtable location, in .rdata) also matches.
            // Filter: only keep targets inside .text.
            while (m.find()) {
                long v = Long.parseLong(m.group(1), 16);
                if (v >= TEXT_LO && v < TEXT_HI) { if (candidates.add(v)) vtCount++; }
            }
        } catch (Exception e) { println("vtables.json read error: " + e); }

        // (b) FPO prologues inside holes: preceded by 90/CC run (>=2) or hole start, starts with 83 EC / 81 EC / 8B 01? (too loose) -> 83 EC, 81 EC, 56 8B F1, 53 8B D9, 57 8B FF, 55 8B FF(no)...
        ghidra.program.model.mem.Memory mem = currentProgram.getMemory();
        int proCount = 0;
        for (long[] h : holes) {
            int len = (int)(h[1] - h[0] + 1);
            if (len < 8) continue;
            byte[] buf = new byte[len];
            try { mem.getBytes(toAddr(h[0]), buf); } catch (Exception e) { continue; }
            for (int i = 0; i + 2 < len; i++) {
                int b0 = buf[i] & 0xFF, b1 = buf[i+1] & 0xFF;
                boolean fpo = (b0 == 0x83 && b1 == 0xEC) || (b0 == 0x81 && b1 == 0xEC)
                           || (b0 == 0x56 && b1 == 0x8B && (buf[i+2]&0xFF) == 0xF1)
                           || (b0 == 0x53 && b1 == 0x8B && (buf[i+2]&0xFF) == 0xD9)
                           || (b0 == 0x8B && b1 == 0xFF);
                if (!fpo) continue;
                boolean padBefore = i == 0 || ((buf[i-1]&0xFF) == 0x90 || (buf[i-1]&0xFF) == 0xCC);
                if (!padBefore) continue;
                if (candidates.add(h[0] + i)) proCount++;
            }
        }
        println("CANDIDATES2 vtable=" + vtCount + " prologue=" + proCount + " total=" + candidates.size());

        int created = 0, failed = 0, already = 0;
        for (long c : candidates) {
            Address a = toAddr(c);
            if (currentProgram.getFunctionManager().getFunctionAt(a) != null) { already++; continue; }
            disassemble(a);
            Function nf = createFunction(a, null);
            if (nf != null) created++; else failed++;
        }
        println("CREATED2 created=" + created + " already=" + already + " failed=" + failed);

        String out = "D:\\MeteorProjects\\_private\\ghidra_scripts\\fresh_functions_v3.json";
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
        println("DUMPED_V3 internal=" + n + " totalBodyBytes=" + totalBody);
    }
}
