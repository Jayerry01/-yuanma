// Consts2.java
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import java.io.*;

public class Consts2 extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/consts.txt")));
        long[] f32 = {0x005a8f7cL, 0x005a8b80L, 0x005a84c8L, 0x005a83e8L};
        for (long a : f32) {
            int i = mem.getInt(toAddr(a));
            out.println(String.format("  float  @0x%08x = %s   raw=%08x", a, Float.intBitsToFloat(i), i));
        }
        long d = 0x005a8460L;
        long raw = mem.getLong(toAddr(d));
        out.println(String.format("  double @0x%08x = %s   raw=%016x", d, Double.longBitsToDouble(raw), raw));
        out.close();
        println("DONE -> consts.txt");
    }
}
