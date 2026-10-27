import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.app.decompiler.*;
import java.io.*;

public class DecompFunc extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) { printf("usage: DecompFunc <hexaddr>\n"); return; }
        long off = Long.parseLong(args[0].replace("0x","").replace("0X",""), 16);
        Address addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(off);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { printf("NO FUNCTION at %s\n", addr); return; }

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        DecompileResults res = di.decompileFunction(f, 120, monitor);
        if (!res.decompileCompleted()) { printf("DECOMP FAILED %s\n", f.getName()); di.dispose(); return; }
        String c = res.getDecompiledFunction().getC();
        String out = "D:/MeteorProjects/_private/ghidra_scripts/decomp_" + String.format("%08x", off) + ".c";
        try (PrintWriter pw = new PrintWriter(new FileOutputStream(out))) { pw.print(c); }
        printf("DECOMP OK %s (%d chars) -> %s\n", f.getName(), c.length(), out);
        di.dispose();
    }
}
