import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;

public class AmbStr extends GhidraScript {
    String peek(long va, int n) {
        try {
            Address a = toAddr(va);
            byte[] b = new byte[n];
            Memory m = currentProgram.getMemory();
            m.getBytes(a, b);
            StringBuilder sb = new StringBuilder();
            for (byte x : b) {
                int v = x & 0xff;
                if (v == 0) { sb.append("\\0"); break; }
                if (v >= 32 && v < 127) sb.append((char) v);
                else sb.append(String.format("\\x%02x", v));
            }
            return sb.toString();
        } catch (Exception e) { return "<err " + e.getMessage() + ">"; }
    }

    @Override
    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append("=== string literals ===\n");
        long[] addrs = { 0x5d18b8L, 0x5d18c0L, 0x5c67acL, 0x5ca380L, 0x5c4580L, 0x5d18acL };
        for (long a : addrs) {
            sb.append(String.format("  0x%06x : \"%s\"%n", a, peek(a, 40)));
        }

        sb.append("\n=== FUN_00574190 head (0x574190-0x574220) ===\n");
        Address s = toAddr(0x00574190L);
        InstructionIterator it = currentProgram.getListing().getInstructions(s, true);
        Address limit = toAddr(0x00574220L);
        int n = 0;
        while (it.hasNext() && n < 60) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(limit) >= 0) break;
            sb.append("  ").append(ins.getAddress()).append("  ").append(ins.toString()).append("\n");
            n++;
        }

        java.io.PrintWriter w = new java.io.PrintWriter(new java.io.OutputStreamWriter(
            new java.io.FileOutputStream("D:/MeteorProjects/_private/ghidra_scripts/ambstr.txt"), "UTF-8"));
        w.print(sb.toString()); w.close();
        println("done");
    }
}
