// Deadline.java - settle the +/-4 site, then hunt the 0x48 clock's readers
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class Deadline extends GhidraScript {
    PrintWriter out;
    Memory mem;

    String hex(long from, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            try { sb.append(String.format("%02x ", mem.getByte(toAddr(from + i)) & 0xff)); }
            catch (Exception e) { sb.append("?? "); }
        }
        return sb.toString().trim();
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/deadline.txt")));
        Listing lst = currentProgram.getListing();

        out.println("########## A: raw bytes 0x4cbbb0..0x4cbbd8 ##########");
        for (long p = 0x004cbbb0L; p < 0x004cbbd8L; p += 8) {
            out.println(String.format("  @0x%08x  %s", p, hex(p, 8)));
        }
        out.println("  listing:");
        InstructionIterator it0 = lst.getInstructions(toAddr(0x004cbbb0L), true);
        while (it0.hasNext()) {
            Instruction i = it0.next();
            if (i.getAddress().getOffset() > 0x004cbbd8L) break;
            out.println("    " + i.getAddress() + "  " + i.toString());
        }

        out.println("\n########## B: timer-module functions 0x549000..0x549e00 (+FP compare flag) ##########");
        for (Function f : lst.getFunctions(true)) {
            long e = f.getEntryPoint().getOffset();
            if (e < 0x00549000L || e > 0x00549e00L) continue;
            boolean fcmp = false;
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                String t = it.next().toString();
                if (t.contains("FCOM") || t.contains("FUCOM") || t.contains("FCOMP")) { fcmp = true; break; }
            }
            out.println(String.format("  0x%08x  %-16s size=%-5d FPcmp=%s",
                e, f.getName(), f.getBody().getNumAddresses(), fcmp ? "YES" : ""));
        }

        out.println("\n########## C: all sites touching [reg + 0xe8] ##########");
        Map<String, List<String>> byFunc = new TreeMap<>();
        for (Function f : lst.getFunctions(true)) {
            List<Instruction> buf = new ArrayList<>();
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) buf.add(it.next());
            boolean inClass = false;
            for (Instruction i : buf) {
                String t = i.toString();
                if (t.contains("0x2e8") || t.contains("0x34c") || t.contains("0x348")) inClass = true;
            }
            for (Instruction i : buf) {
                String t = i.toString();
                if (!t.contains("+ 0xe8]")) continue;
                String key = f.getName() + " size=" + f.getBody().getNumAddresses()
                    + (inClass ? "  [A-CLASS]" : "");
                byFunc.computeIfAbsent(key, k -> new ArrayList<>())
                      .add("    " + i.getAddress() + "  " + t);
            }
        }
        out.println("functions with +0xe8 access: " + byFunc.size());
        for (Map.Entry<String, List<String>> e : byFunc.entrySet()) {
            out.println("  == " + e.getKey() + "  hits=" + e.getValue().size());
            int n = 0;
            for (String s : e.getValue()) { out.println(s); if (++n >= 8) { out.println("    ..."); break; } }
        }

        out.close();
        println("DONE -> deadline.txt");
    }
}
