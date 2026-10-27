// Probe 2: name cmd 0x0F's two GameApp slots and confirm FUN_004D03F0's receiver class.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Cmd0fName extends GhidraScript {

    StringBuilder sb = new StringBuilder();
    void w(String s) { sb.append(s).append("\n"); }

    long dword(Memory mem, long va) {
        try { return mem.getInt(toAddr(va)) & 0xffffffffL; } catch (Exception e) { return -1; }
    }

    String fn(FunctionManager fm, long va) {
        if (va <= 0 || va == 0xffffffffL) return "<none>";
        Function f = fm.getFunctionContaining(toAddr(va));
        if (f == null) return "<no function>";
        return f.getName() + " size=" + f.getBody().getNumAddresses();
    }

    void dumpBody(long va, int max) {
        Function f = currentProgram.getFunctionManager().getFunctionContaining(toAddr(va));
        if (f == null) { w("  (no function at " + Long.toHexString(va) + ")"); return; }
        Listing lst = currentProgram.getListing();
        Address end = f.getBody().getMaxAddress();
        InstructionIterator it = lst.getInstructions(f.getEntryPoint(), true);
        int n = 0;
        while (it.hasNext() && n < max) {
            Instruction ins = it.next();
            if (ins.getAddress().compareTo(end) > 0) break;
            byte[] b = null;
            try { b = ins.getBytes(); } catch (Exception e) {}
            StringBuilder hex = new StringBuilder();
            if (b != null) for (int i = 0; i < b.length && i < 8; i++) hex.append(String.format("%02x ", b[i] & 0xff));
            w(String.format("  %s  %-24s %s", ins.getAddress(), hex.toString().trim(), ins.toString()));
            n++;
        }
        if (n >= max) w("  ... (truncated)");
    }

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();

        long GA = 0x5A9068L;   // GameApp main vfptr (confirmed earlier)

        w("================ A: GameApp slots used by cmd 0x0F ================");
        long s83 = dword(mem, GA + 0x14C);
        long s123 = dword(mem, GA + 0x1EC);
        w(String.format("slot 83  (+0x14C) mem[%08X] = %08X -> %s", GA + 0x14C, s83, fn(fm, s83)));
        w(String.format("slot 123 (+0x1EC) mem[%08X] = %08X -> %s", GA + 0x1EC, s123, fn(fm, s123)));
        // control: known GameApp slots
        w(String.format("control slot 172 (+0x2B0) = %08X -> %s", dword(mem, GA + 0x2B0), fn(fm, dword(mem, GA + 0x2B0))));
        w(String.format("control slot 218 (+0x368) = %08X -> %s", dword(mem, GA + 0x368), fn(fm, dword(mem, GA + 0x368))));

        w("");
        w("================ B: body of GameApp slot 83 ================");
        dumpBody(s83, 60);
        w("");
        w("================ C: body of GameApp slot 123 ================");
        dumpBody(s123, 70);

        w("");
        w("================ D: cmd 0x35 trampoline 0x4BB96E ================");
        dumpBody(0x4BB96E, 24);

        w("");
        w("================ E: FUN_004D03F0 receiver check ================");
        w("  (its PUSH 0x4 ; CALL [EDX+0x12C] must land on 0x4D0500 if this is the 0x5AA6A8 class)");
        w(String.format("  mem[0x5AA7D4] = %08X -> %s", dword(mem, 0x5AA7D4), fn(fm, dword(mem, 0x5AA7D4))));

        w("");
        w("================ F: does 0x4F1A60 ever touch +0xDC ? ================");
        Function f0f = fm.getFunctionContaining(toAddr(0x4F1A60));
        if (f0f != null) {
            boolean touched = false;
            InstructionIterator it = currentProgram.getListing().getInstructions(f0f.getEntryPoint(), true);
            Address end = f0f.getBody().getMaxAddress();
            while (it.hasNext()) {
                Instruction ins = it.next();
                if (ins.getAddress().compareTo(end) > 0) break;
                String s = ins.toString();
                if (s.contains("0xdc") || s.contains("0xDC")) { w("  " + ins.getAddress() + "  " + s); touched = true; }
            }
            if (!touched) w("  no +0xDC reference anywhere in FUN_004F1A60  => cmd 0x0F does NOT set the move state");
        }

        File out = new File("D:/MeteorRE/evidence/cmd0f_name.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
