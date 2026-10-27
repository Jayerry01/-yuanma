// 数据段指针表扫描：以「表级命中率」判定引用证据，而不是「数据段出现 4 字节 .text 地址」。
// 输出：D:\MeteorProjects\_private\ghidra_scripts\ptrtables_v4.json
// 判据：连续 4 字节槽位（值落在 .text 内）构成的 run，长度>=4，且命中已知函数入口比例 >=50% → 可信指针表
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class ScanPointerTables extends GhidraScript {

    static final long TEXT_LO = 0x00401000L;
    static final long TEXT_HI = 0x005A62BDL;   // .text 节尾（0x401000 + 0x1A62BD）
    static final int MIN_RUN = 4;
    static final double TRUST_RATIO = 0.5;

    static class Run {
        long addr;
        int len;
        int hits;
        long[] vals;
        boolean trusted() { return len > 0 && (double) hits / len >= TRUST_RATIO; }
    }

    @Override
    public void run() throws Exception {
        Set<Long> funcs = new HashSet<>();
        ArrayList<long[]> ranges = new ArrayList<>();
        FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(true);
        while (fit.hasNext()) {
            Function f = fit.next();
            if (f.isExternal()) continue;
            funcs.add(f.getEntryPoint().getOffset());
            AddressSetView b = f.getBody();
            if (b == null) continue;
            Iterator<AddressRange> ri = b.getAddressRanges();
            while (ri.hasNext()) {
                AddressRange r = ri.next();
                ranges.add(new long[]{r.getMinAddress().getOffset(), r.getMaxAddress().getOffset()});
            }
        }
        ranges.sort((x, y) -> Long.compare(x[0], y[0]));

        // holes（>=16B 的未归属区）
        ArrayList<long[]> holes = new ArrayList<>();
        long cur = TEXT_LO;
        for (long[] r : ranges) {
            if (r[0] > cur && r[0] - cur >= 16) holes.add(new long[]{cur, r[0] - 1});
            cur = Math.max(cur, r[1] + 1);
        }
        if (TEXT_HI - cur >= 16) holes.add(new long[]{cur, TEXT_HI - 1});
        println("HOLES " + holes.size());

        Memory mem = currentProgram.getMemory();
        ArrayList<Run> runs = new ArrayList<>();
        int scannedBlocks = 0;
        for (MemoryBlock blk : mem.getBlocks()) {
            if (blk.isExecute()) continue;
            if (!blk.isInitialized()) continue;
            long s = blk.getStart().getOffset();
            long e = blk.getEnd().getOffset();
            if (e - s > 4_000_000L) continue;
            long start = (s + 3) & ~3L;              // 4 字节对齐
            int n = (int) ((e - start + 1) / 4);
            if (n < MIN_RUN) continue;
            byte[] buf = new byte[n * 4];
            try {
                mem.getBytes(toAddr(start), buf);
            } catch (Exception ex) {
                println("SKIP block " + blk.getName() + " " + ex);
                continue;
            }
            scannedBlocks++;
            int i = 0;
            while (i < n) {
                long v = u32(buf, i);
                if (v < TEXT_LO || v >= TEXT_HI) { i++; continue; }
                int j = i;
                while (j < n) {
                    long w = u32(buf, j);
                    if (w < TEXT_LO || w >= TEXT_HI) break;
                    j++;
                }
                int len = j - i;
                if (len >= MIN_RUN) {
                    Run r = new Run();
                    r.addr = start + (long) i * 4;
                    r.len = len;
                    r.vals = new long[len];
                    int hits = 0;
                    for (int k = 0; k < len; k++) {
                        long w = u32(buf, i + k);
                        r.vals[k] = w;
                        if (funcs.contains(w)) hits++;
                    }
                    r.hits = hits;
                    runs.add(r);
                }
                i = j;
            }
        }

        int trusted = 0;
        long trustedSlots = 0;
        Set<Long> distinct = new HashSet<>();
        for (Run r : runs) {
            if (r.trusted()) {
                trusted++;
                trustedSlots += r.len;
                for (long v : r.vals) distinct.add(v);
            }
        }
        println("BLOCKS scanned=" + scannedBlocks + " runs=" + runs.size() + " trusted=" + trusted
                + " trustedSlots=" + trustedSlots + " distinctTargets=" + distinct.size());

        try (PrintWriter pw = new PrintWriter(new FileWriter(
                "D:\\MeteorProjects\\_private\\ghidra_scripts\\ptrtables_v4.json"))) {
            pw.print("{\"text\":[");
            pw.print(TEXT_LO + "," + TEXT_HI);
            pw.print("],\"holes\":[");
            for (int k = 0; k < holes.size(); k++) {
                if (k > 0) pw.print(",");
                pw.print("[" + holes.get(k)[0] + "," + holes.get(k)[1] + "]");
            }
            pw.print("],\"runs\":[");
            boolean first = true;
            for (Run r : runs) {
                if (!first) pw.print(",");
                first = false;
                pw.print("{\"a\":" + r.addr + ",\"n\":" + r.len + ",\"h\":" + r.hits + ",\"v\":[");
                for (int k = 0; k < r.len; k++) {
                    if (k > 0) pw.print(",");
                    pw.print(r.vals[k]);
                }
                pw.print("]}");
            }
            pw.print("]}");
        }
        println("WROTE ptrtables_v4.json");
    }

    private long u32(byte[] b, int i) {
        int o = i * 4;
        return (b[o] & 0xFFL) | ((b[o + 1] & 0xFFL) << 8) | ((b[o + 2] & 0xFFL) << 16) | ((b[o + 3] & 0xFFL) << 24);
    }
}
