// Consts.java - the five constants in FUN_004cfb00's packing math
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import java.io.*;

public class Consts extends GhidraScript {
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/consts.txt")));
        long[] f32 = {0x005a8f7cL, 0x005a8b80L, 0x005a84c8L, 0x005a83e8L};
        for (long a : f32)
            out.println(String.format("  float  @0x%08x = %s   raw=%08x", a,
                Float.intBitsToFloat(mem.getInt(toAddr(a))), mem.getInt(toAddr(a))));
        long d = 0x005a8460L;
        out.println(String.format("  double @0x%08x = %s   raw=%016x", d,
            Double.longBitsToDouble(mem.getLong(toAddr(d))), mem.getLong(toAddr(d))));

        out.println("\n  cmd 0x04 dispatch entry (from cmd_dispatch_map): kind=inline, lines=2");
        out.println("  -- check the dispatcher's inline case 4 --");
        Function f = getFunctionContaining(toAddr(0x004bb800L));
        var it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            var i = it.next();
            long off = i.getAddress().getOffset();
            if (off >= 0x004bbfe8L - 0x200 && off <= 0x004bbfe8L) { /* jump table area */ }
        }
        out.close();
        println("DONE -> consts.txt");
    }
}
