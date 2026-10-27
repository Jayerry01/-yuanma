// Final.java - sender vtable 0x5aa6a8 key slots + string at 0x5c9c34 + slot 31 target
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class Final extends GhidraScript {
    PrintWriter out;
    long base = 0x005aa6a8L;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/final.txt")));
        Memory mem = currentProgram.getMemory();

        out.println("########## A: string @0x5c9c34 ##########");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 40; i++) {
            byte b = mem.getByte(toAddr(0x005c9c34L + i));
            if (b == 0) break;
            sb.append((char) (b & 0xff));
        }
        out.println("  \"0x5c9c34\" = \"" + sb + "\"");

        out.println("\n########## B: sender vtable 0x5aa6a8 key slots ##########");
        int[] slots = {31, 37, 40, 67, 109, 111, 39, 65};
        for (int s : slots) {
            int v = mem.getInt(toAddr(base + s * 4L));
            long p = v & 0xffffffffL;
            String d = "";
            Function f = getFunctionContaining(toAddr(p));
            if (f != null) d = f.getName() + " size=" + f.getBody().getNumAddresses();
            out.println(String.format("  slot %3d (vb+0x%02x / this+0x%03x)  -> 0x%08x  %s",
                s, s * 4, s * 4, p, d));
        }

        out.println("\n########## C: dump slot 31 target (attack request) ##########");
        int v31 = mem.getInt(toAddr(base + 31 * 4L));
        long p31 = v31 & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p31));
        if (f == null) out.println("  no func at 0x" + Long.toHexString(p31));
        else {
            out.println("  " + f.getName() + " @" + f.getEntryPoint()
                + " size=" + f.getBody().getNumAddresses());
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            int n = 0;
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("   " + i.getAddress() + "  " + i.toString());
                if (++n > 120) { out.println("   ... truncated"); break; }
            }
        }
        out.close();
        println("DONE -> final.txt");
    }
}
