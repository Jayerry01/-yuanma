// DumpStringsV2 - resolve the full 16-keyword string table used by FUN_004d1740
// Pure static string read from program memory. No analysis dependencies.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;

public class DumpKW extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        String[] addrs = new String[] {
            "0x005c91fc","0x005c9cdc","0x005c9c48","0x005c9c54","0x005c9cbc",
            "0x005c9cc4","0x005c9c74","0x005c9c84","0x005c9cb0","0x005c9c90",
            "0x005c9c9c","0x005c9c64","0x005c9cd4","0x005c9ca8","0x005c9c7c",
            "0x005c9c5c","0x005c9c44","0x005c67d0"
        };
        StringBuilder sb = new StringBuilder();
        sb.append("==== 16 keyword string table ====\n");
        for (String sa : addrs) {
            Address a = toAddr(sa);
            StringBuilder s = new StringBuilder();
            // read until NUL, cap 64
            for (int i = 0; i < 64; i++) {
                try {
                    byte b = mem.getByte(a.add(i));
                    if (b == 0) break;
                    if (b >= 0x20 && b < 0x7f) s.append((char) b);
                    else { s.append('?'); }
                } catch (Exception e) { s.append("<oob>"); break; }
            }
            sb.append(sa).append(" : \"").append(s.toString()).append("\"\n");
        }
        println(sb.toString());
        java.io.File f = new java.io.File("D:/MeteorProjects/_private/ghidra_scripts/keywords16.txt");
        java.io.FileWriter w = new java.io.FileWriter(f);
        w.write(sb.toString());
        w.close();
        println("DUMPKW DONE -> keywords16.txt");
    }
}
