import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.app.decompiler.*;
import java.io.*;

public class DecompMany extends GhidraScript {

    @Override
    public void run() throws Exception {
        DecompInterface decomplib = new DecompInterface();
        decomplib.openProgram(currentProgram);

        if (getScriptArgs().length == 0) {
            println("NO ARGS");
            return;
        }
        String outDir = "D:/MeteorProjects/_private/ghidra_scripts/";
        java.util.List<String> toks = new java.util.ArrayList<String>();
        for (String a : getScriptArgs()) {
            for (String t2 : a.split("[,\\s]+")) {
                t2 = t2.trim();
                if (!t2.isEmpty()) toks.add(t2);
            }
        }
        int ok = 0, fail = 0;
        for (String t : toks) {
            t = t.trim();
            if (t.isEmpty()) continue;
            Address addr;
            try {
                addr = toAddr(t);
            } catch (Exception e) {
                println("BADADDR " + t);
                fail++;
                continue;
            }
            Function func = currentProgram.getFunctionManager().getFunctionAt(addr);
            if (func == null) {
                println("NO FUNCTION at " + t);
                fail++;
                continue;
            }
            DecompileResults results = decomplib.decompileFunction(func, 120, monitor);
            if (results == null || !results.decompileCompleted()) {
                println("DECOMP FAIL " + t);
                fail++;
                continue;
            }
            String c = results.getDecompiledFunction().getC();
            String fname = outDir + "decomp_" + t.replace("0x", "") + ".c";
            try (FileWriter w = new FileWriter(new File(fname))) { w.write(c); }
            println("DECOMP OK " + t + " -> " + fname + " (" + c.length() + " chars)");
            ok++;
        }
        decomplib.dispose();
        println("SUMMARY ok=" + ok + " fail=" + fail);
    }
}
