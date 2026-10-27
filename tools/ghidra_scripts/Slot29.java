// Slot29.java - resolve and dump slot 29 (+0x74) on both bases
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class Slot29 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    String at(long base, int s) throws Exception {
        long a = base + s * 4L;
        int v = mem.getInt(toAddr(a));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        return String.format("  base 0x%08x slot %2d (+0x%02x) @0x%08x -> 0x%08x  %s",
            base, s, s * 4, a, p, f == null ? "?" : f.getName() + " size=" + f.getBody().getNumAddresses());
    }

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/slot29.txt")));

        out.println("########## A: slot 29 on both candidate bases ##########");
        out.println(at(0x005aa6a8L, 29));
        out.println(at(0x005aa660L, 29));
        out.println(at(0x005a9fe0L, 29));

        int v = mem.getInt(toAddr(0x005aa6a8L + 29 * 4L));
        long p = v & 0xffffffffL;
        Function f = getFunctionContaining(toAddr(p));
        out.println("\n########## B: body of 0x" + Long.toHexString(p) + " ##########");
        if (f == null) { out.println("  (not a function)"); out.close(); return; }
        out.println("  " + f.getName() + " size=" + f.getBody().getNumAddresses());

        Set<String> stores = new TreeSet<>();
        Set<String> calls = new TreeSet<>();
        int n = 0, jt = 0;
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            n++;
            StringBuilder b = new StringBuilder();
            try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
            if (n <= 200) out.println("  " + i.getAddress() + "  " + String.format("%-30s", b.toString().trim()) + "  " + i.toString());
            String t = i.toString();
            if (t.startsWith("MOV dword ptr [") && t.indexOf('[') < t.indexOf(',')) stores.add(t);
            if (t.startsWith("CALL")) calls.add(t);
            if (t.contains("*0x4 +")) jt++;
        }
        if (n > 200) out.println("  ... (" + (n - 200) + " more)");
        out.println("\n########## C: summary ##########");
        out.println("  instructions=" + n + "  indexed-jumps=" + jt);
        for (String s : stores) out.println("  W " + s);
        for (String c : calls) out.println("  C " + c);
        out.close();
        println("DONE -> slot29.txt");
    }
}
