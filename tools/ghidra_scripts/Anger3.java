import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import java.util.*;
import java.util.regex.*;

public class Anger3 extends GhidraScript {

    @Override
    public void run() throws Exception {
        Pattern memPat = Pattern.compile("\\[([A-Z0-9]+)\\s*\\+\\s*0x([0-9a-fA-F]+)\\]");
        Pattern cmpPat = Pattern.compile("CMP\\s+.*?,0x(64|3c)\\b", Pattern.CASE_INSENSITIVE);

        Map<String, List<String>> byOff = new TreeMap<>();
        Map<String, Set<String>> vals = new TreeMap<>();
        int total = 0;

        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            String t = ins.toString();
            if (!cmpPat.matcher(t).find()) continue;
            Matcher m = memPat.matcher(t);
            if (!m.find()) continue;
            String off = m.group(2).toLowerCase();
            String val = t.substring(t.lastIndexOf("0x") + 2).toLowerCase();
            total++;
            byOff.computeIfAbsent(off, k -> new ArrayList<>()).add(ins.getAddress() + "  " + t);
            vals.computeIfAbsent(off, k -> new TreeSet<>()).add(val);
        }

        StringBuilder sb = new StringBuilder();
        sb.append("== CMP [reg + off], 0x64 | 0x3c ==\ntotal sites: ").append(total).append("\n\n");

        sb.append("== displacements seeing BOTH 0x64 and 0x3c ==\n");
        for (Map.Entry<String, Set<String>> e : vals.entrySet()) {
            if (e.getValue().contains("64") && e.getValue().contains("3c")) {
                sb.append("  *** +0x").append(e.getKey()).append(" ***\n");
                for (String s : byOff.get(e.getKey())) sb.append("      ").append(s).append("\n");
            }
        }

        sb.append("\n== all displacements by frequency ==\n");
        List<Map.Entry<String, List<String>>> all = new ArrayList<>(byOff.entrySet());
        all.sort((a, b) -> b.getValue().size() - a.getValue().size());
        for (Map.Entry<String, List<String>> e : all) {
            sb.append(String.format("  +0x%-8s x%-3d  values=%s%n",
                e.getKey(), e.getValue().size(), vals.get(e.getKey())));
        }

        java.io.PrintWriter w = new java.io.PrintWriter(new java.io.OutputStreamWriter(
            new java.io.FileOutputStream("D:/MeteorProjects/_private/ghidra_scripts/anger.txt"), "UTF-8"));
        w.print(sb.toString()); w.close();
        println("total=" + total + " offsets=" + byOff.size());
    }
}
