// DiInput.java - DirectInput device setup + GetDeviceState(0x24) usage; dump table loader
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class DiInput extends GhidraScript {
    PrintWriter out;

    void dump(long va, int max) throws Exception {
        Address a = toAddr(va);
        Function f = getFunctionContaining(a);
        if (f == null) { out.println("no func at " + Long.toHexString(va)); return; }
        out.println("\n===== DUMP " + f.getName() + " @" + f.getEntryPoint()
            + " size=" + f.getBody().getNumAddresses() + " =====");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext()) {
            Instruction i = it.next();
            out.println("  " + i.getAddress() + "  " + i.toString());
            if (max > 0 && ++n >= max) { out.println("  ... (truncated)"); break; }
        }
    }

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/diinput.txt")));

        // 1. DirectInputCreateA caller and its callers
        out.println("########## A: DirectInputCreateA caller chain ##########");
        SymbolTable st = currentProgram.getSymbolTable();
        Address iat = toAddr(0x005a8028L);
        for (Reference r : getReferencesTo(iat)) {
            Function f = getFunctionContaining(r.getFromAddress());
            out.println("  ref " + r.getFromAddress() + " in " + (f == null ? "?" : f.getName()));
        }
        dump(0x00411db0L, 0);
        Function fdb = getFunctionContaining(toAddr(0x00411db0L));
        if (fdb != null) {
            out.println("  -- callers of " + fdb.getName() + ":");
            for (Reference r : getReferencesTo(fdb.getEntryPoint())) {
                Function c = getFunctionContaining(r.getFromAddress());
                out.println("     " + r.getFromAddress() + " in " + (c == null ? "?" : c.getName() + " size=" + c.getBody().getNumAddresses()));
            }
        }

        // 2. DirectInput COM vtable offset usage: 0x1c Acquire / 0x24 GetDeviceState / 0x2c SetDataFormat / 0x34 SetCooperativeLevel
        out.println("\n########## B: DirectInput vtable-offset call sites ##########");
        Map<String, Set<String>> perFunc = new TreeMap<>();
        Listing lst = currentProgram.getListing();
        for (Function f : lst.getFunctions(true)) {
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                String t = ins.toString();
                if (!t.startsWith("CALL dword ptr [")) continue;
                for (String off : new String[]{"0x1c","0x24","0x2c","0x34","0x10","0x14","0x18"}) {
                    if (t.contains(",+" + off) || t.matches(".*\\+ " + off + "\\].*") || t.contains(" + " + off + "]")) {
                        perFunc.computeIfAbsent(f.getName() + " size=" + f.getBody().getNumAddresses(),
                            k -> new TreeSet<>()).add(off + "@" + ins.getAddress());
                    }
                }
            }
        }
        for (Map.Entry<String, Set<String>> e : perFunc.entrySet()) {
            Set<String> s = e.getValue();
            // want functions touching the device-state trio
            boolean has24 = s.stream().anyMatch(x -> x.startsWith("0x24@"));
            boolean hasSetup = s.stream().anyMatch(x -> x.startsWith("0x2c@") || x.startsWith("0x34@") || x.startsWith("0x1c@"));
            if (has24 || hasSetup) {
                out.println("  " + e.getKey() + "  ->  " + s);
            }
        }

        // 3. table loader
        dump(0x0045d730L, 90);

        out.close();
        println("DONE -> diinput.txt");
    }
}
