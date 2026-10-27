// Anger.java - find a memory displacement that is compared against BOTH 100 and 60
// (the CheckPos signature), i.e. the original's AngryValue field and its spend sites.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.util.*;

public class Anger extends GhidraScript {

    static class Hit {
        long off; String addr; String mnem; String text;
        Hit(long o, String a, String m, String t){off=o;addr=a;mnem=m;text=t;}
    }

    @Override
    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        List<Hit> hits = new ArrayList<>();

        for (Instruction ins = getFirstInstruction(); ins != null; ins = getNextInstruction(ins, true)) {
            String mn = ins.getMnemonicString();
            if (!mn.startsWith("CMP") && !mn.startsWith("SUB") && !mn.startsWith("ADD")) continue;
            int n = ins.getNumOperands();
            if (n < 2) continue;
            // operand 0 memory, operand 1 scalar
            if ((ins.getOperandType(0) & OperandType.DYNAMIC) == 0
                && (ins.getOperandType(0) & OperandType.ADDRESS) == 0) continue;
            if (!ins.getOpObjects(0).getClass().getSimpleName().isEmpty()) {
                // need a scalar ref + memory ref
            }
            Scalar sc = null;
            for (Object o : ins.getOpObjects(1)) if (o instanceof Scalar) sc = (Scalar) o;
            if (sc == null) continue;
            long v = sc.getUnsignedValue();
            if (v != 100 && v != 60) continue;
            // displacement from the memory operand's scalar/register
            long disp = Long.MIN_VALUE;
            for (Object o : ins.getOpObjects(0)) {
                if (o instanceof Scalar) disp = ((Scalar) o).getSignedValue();
            }
            if (disp == Long.MIN_VALUE) continue;
            hits.add(new Hit(disp, ins.getAddress().toString(), mn, ins.toString()));
        }

        Map<Long, List<Hit>> byOff = new TreeMap<>();
        for (Hit h : hits) byOff.computeIfAbsent(h.off, k -> new ArrayList<>()).add(h);

        sb.append("== displacements compared against 100 or 60 (CMP/SUB/ADD, immediate) ==\n");
        for (Map.Entry<Long, List<Hit>> e : byOff.entrySet()) {
            Set<Long> vals = new TreeSet<>();
            for (Hit h : e.getValue()) {
                for (Object o : new String[]{""}) {}
            }
            sb.append(String.format("  +0x%x  : %d site(s)%n", e.getKey(), e.getValue().size()));
            for (Hit h : e.getValue()) sb.append("      ").append(h.addr).append("  ").append(h.text).append("\n");
        }

        // highlight offsets that see both 100 and 60
        sb.append("\n== offsets seeing BOTH 100 and 60 ==\n");
        for (Map.Entry<Long, List<Hit>> e : byOff.entrySet()) {
            boolean has100 = false, has60 = false;
            for (Hit h : e.getValue()) {
                if (h.text.contains("0x64") || h.text.contains(",100")) has100 = true;
                if (h.text.contains("0x3c") || h.text.contains(",60")) has60 = true;
            }
            if (has100 && has60) sb.append(String.format("  *** +0x%x ***%n", e.getKey()));
        }

        write("D:/MeteorProjects/_private/ghidra_scripts/anger.txt", sb.toString());
        println("hits=" + hits.size() + " distinct offsets=" + byOff.size());
    }

    void write(String path, String s) throws Exception {
        java.io.PrintWriter w = new java.io.PrintWriter(new java.io.OutputStreamWriter(
            new java.io.FileOutputStream(path), "UTF-8"));
        w.print(s); w.close();
    }
}
