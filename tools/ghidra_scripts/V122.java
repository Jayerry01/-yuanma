// V122.java - raw bytes at the disputed sites + PUSH imm8 census in FUN_004cb820
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class V122 extends GhidraScript {
    PrintWriter out;
    Memory mem;

    String hex(long from, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            try {
                sb.append(String.format("%02x ", mem.getByte(toAddr(from + i)) & 0xff));
            } catch (Exception e) { sb.append("?? "); }
        }
        return sb.toString().trim();
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/verify122.txt")));

        out.println("########## A: raw bytes at disputed sites ##########");
        long[][] ranges = {
            {0x004cb876L, 16}, {0x004cb890L, 16}, {0x004cba30L, 16},
            {0x004cbb00L, 16}, {0x004cbebeL, 24},
        };
        for (long[] r : ranges) {
            out.println(String.format("  @0x%08x  %s", r[0], hex(r[0], (int) r[1])));
        }

        out.println("\n########## B: every PUSH imm8 (opcode 6A) inside FUN_004cb820 ##########");
        Function f = getFunctionContaining(toAddr(0x004cb820L));
        Address a = f.getBody().getMinAddress(), b = f.getBody().getMaxAddress();
        int n = 0;
        for (long p = a.getOffset(); p <= b.getOffset() - 1; p++) {
            int op = mem.getByte(toAddr(p)) & 0xff;
            if (op == 0x6A) {
                int imm = mem.getByte(toAddr(p + 1)) & 0xff;
                out.println(String.format("  0x%08x  push 0x%02x   (%s)", p, imm,
                    (imm >= 0x20 && imm < 0x7f) ? "'" + (char) imm + "'" : ""));
                n++;
            }
        }
        out.println("  total push-imm8 = " + n);

        out.println("\n########## C: slot tables, two bases ##########");
        long[][] slots = {{0x005aa660L, 13}, {0x005aa660L, 10}, {0x005aa660L, 11}, {0x005aa660L, 12},
                          {0x005aa6a8L, 13}, {0x005aa6a8L, 24}};
        for (long[] s : slots) {
            int v = mem.getInt(toAddr(s[0] + s[1] * 4L));
            long p = v & 0xffffffffL;
            Function g = getFunctionContaining(toAddr(p));
            out.println(String.format("  base 0x%08x slot %2d (+0x%02x) @0x%08x -> 0x%08x  %s",
                s[0], s[1], s[1] * 4, s[0] + s[1] * 4L, p,
                g == null ? "?" : g.getName() + " size=" + g.getBody().getNumAddresses()));
        }

        out.println("\n########## D: direct E8 callers of FUN_004cbce0 ##########");
        int cc = 0;
        for (Reference r : getReferencesTo(toAddr(0x004cbce0L))) {
            if (r.getReferenceType().isCall()) { out.println("   " + r.getFromAddress()); cc++; }
        }
        out.println("  direct call count = " + cc);

        out.close();
        println("DONE -> verify122.txt");
    }
}
