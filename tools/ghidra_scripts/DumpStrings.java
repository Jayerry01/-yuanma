// DumpStrings.java — read null/printable-terminated ASCII strings at given VAs
// Args: comma-or-space separated hex VAs, e.g. 0x5c67d0,0x5c9cd4
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class DumpStrings extends GhidraScript {
    String OUT = "D:/MeteorProjects/_private/ghidra_scripts/strings_dump.txt";

    String readStr(long va, Memory mem) {
        try {
            Address a = toAddr(va);
            byte[] b = new byte[64];
            mem.getBytes(a, b);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 64; i++) {
                int c = b[i] & 0xff;
                if (c == 0) break;
                if (c >= 0x20 && c < 0x7f) sb.append((char) c);
                else break;
            }
            return sb.toString();
        } catch (Exception e) { return "<ERR " + e.getMessage() + ">"; }
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        // build list: script args + always include the B-option unresolved DATs
        List<String> toks = new ArrayList<String>();
        for (String s : getScriptArgs()) {
            String t = s.trim();
            if (!t.isEmpty()) toks.add(t);
        }
        StringBuilder sb = new StringBuilder();
        sb.append("==== resolved strings ====\n");
        for (String t : toks) {
            String hex = t.startsWith("0x") || t.startsWith("0X") ? t.substring(2) : t;
            long va;
            try { va = Long.parseLong(hex, 16); }
            catch (Exception e) { sb.append(t + " : <bad hex>\n"); continue; }
            String s = readStr(va, mem);
            sb.append(String.format("0x%08x : \"%s\"\n", va, s));
        }
        try (PrintWriter pw = new PrintWriter(new FileOutputStream(OUT))) {
            pw.print(sb.toString());
        }
        printf("STRINGS DONE -> %s\n", OUT);
        println(sb.toString());
    }
}
