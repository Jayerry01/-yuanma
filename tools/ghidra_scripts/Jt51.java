// Jt51.java - read the 51-entry dispatch table at 0x4bbfe8 and map cmd -> target
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class Jt51 extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/jt51.txt")));
        long base = 0x004bbfe8L;
        out.println("########## 51-entry table @0x4bbfe8 (cmd = index + 3) ##########");
        Map<Long, List<Integer>> share = new LinkedHashMap<>();
        for (int i = 0; i < 51; i++) {
            int v = mem.getInt(toAddr(base + i * 4L));
            long p = v & 0xffffffffL;
            int cmd = i + 3;
            share.computeIfAbsent(p, k -> new ArrayList<>()).add(cmd);
            Function f = getFunctionContaining(toAddr(p));
            out.println(String.format("  idx %2d  cmd 0x%02x  @0x%08x -> 0x%08x  %s",
                i, cmd, base + i * 4L, p,
                f == null ? "?" : f.getName()));
        }
        out.println("\n########## shared targets (>=2 cmds) ##########");
        for (Map.Entry<Long, List<Integer>> e : share.entrySet()) {
            if (e.getValue().size() < 2) continue;
            StringBuilder sb = new StringBuilder();
            for (int c : e.getValue()) sb.append(String.format("0x%02x ", c));
            out.println("  0x" + Long.toHexString(e.getKey()) + "  <- " + sb);
        }
        out.close();
        println("DONE -> jt51.txt");
    }
}
