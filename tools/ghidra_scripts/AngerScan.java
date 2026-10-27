// AngerScan: functions that use several of {10,20,50,60,100} as immediates or as float constants.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class AngerScan extends GhidraScript {

    static final long[] IV = { 10, 20, 50, 60, 100 };
    static final long[] FV = { 0x41200000L, 0x41A00000L, 0x42480000L, 0x42700000L, 0x42C80000L };

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    boolean isInt(long v) { for (long x : IV) if (v == x) return true; return false; }
    boolean isFlt(long bits) { for (long x : FV) if ((bits & 0xffffffffL) == x) return true; return false; }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();

        Map<Function, Set<String>> hits = new LinkedHashMap<>();
        Map<Function, List<String>> detail = new LinkedHashMap<>();

        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            Function f = fm.getFunctionContaining(ins.getAddress());
            if (f == null) continue;

            for (int op = 0; op < ins.getNumOperands(); op++) {
                // 1) plain immediates
                for (Object o : ins.getOpObjects(op)) {
                    if (!(o instanceof Scalar)) continue;
                    long v = ((Scalar) o).getUnsignedValue();
                    if (isInt(v)) {
                        hits.computeIfAbsent(f, k -> new LinkedHashSet<>()).add("i" + v);
                        detail.computeIfAbsent(f, k -> new ArrayList<>())
                              .add(ins.getAddress() + "  " + ins + "   [imm " + v + "]");
                    }
                }
                // 2) direct memory operand whose dword is one of the float constants
                Address da = null;
                try { da = ins.getAddress(op); } catch (Exception e) {}
                // fall back to scalar-as-address form
                if (da == null) {
                    for (Object o : ins.getOpObjects(op)) {
                        if (o instanceof Scalar) {
                            long v = ((Scalar) o).getUnsignedValue();
                            if (v >= 0x400000L && v < 0x700000L) { da = toAddr(v); break; }
                        }
                    }
                }
                if (da != null) {
                    try {
                        long bits = mem.getInt(da) & 0xffffffffL;
                        if (isFlt(bits)) {
                            float fv = Float.intBitsToFloat((int) bits);
                            hits.computeIfAbsent(f, k -> new LinkedHashSet<>()).add("f" + (int) fv);
                            detail.computeIfAbsent(f, k -> new ArrayList<>())
                                  .add(ins.getAddress() + "  " + ins + "   [data " + da + " = " + fv + "f]");
                        }
                    } catch (Exception e) {}
                }
            }
        }

        w("================ A: functions with >=3 distinct target values ================");
        List<Function> cand = new ArrayList<>();
        for (Map.Entry<Function, Set<String>> e : hits.entrySet())
            if (e.getValue().size() >= 3) cand.add(e.getKey());

        cand.sort((a, b) -> hits.get(b).size() - hits.get(a).size());
        for (Function f : cand) {
            w(String.format("  %s @%s  size=%-5d  values=%s", f.getName(), f.getEntryPoint(),
                f.getBody().getNumAddresses(), hits.get(f)));
        }
        if (cand.isEmpty()) w("  none");

        w("");
        w("================ B: detail for the top 12 ================");
        int n = 0;
        for (Function f : cand) {
            if (n++ >= 12) break;
            w("");
            w("  --- " + f.getName() + " @" + f.getEntryPoint() + "  values=" + hits.get(f));
            List<String> d = detail.get(f);
            int m = 0;
            for (String s : d) {
                if (m++ >= 14) { w("      ..."); break; }
                w("      " + s);
            }
        }

        w("");
        w("================ C: functions touching ANY float 60.0f or 100.0f ================");
        int c = 0;
        for (Map.Entry<Function, Set<String>> e : hits.entrySet()) {
            Set<String> v = e.getValue();
            if ((v.contains("f100") || v.contains("f10") && v.contains("f60")) || v.contains("f60")) {
                Function f = e.getKey();
                w(String.format("  %s @%s size=%-5d values=%s", f.getName(), f.getEntryPoint(),
                    f.getBody().getNumAddresses(), v));
                c++;
            }
        }
        if (c == 0) w("  none");

        File out = new File("D:/MeteorRE/evidence/anger_scan.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
