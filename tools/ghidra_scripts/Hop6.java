// Hop6.java - FUN_004d03f0 (166 B): forward / state / dispatch?
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class Hop6 extends GhidraScript {
    public void run() throws Exception {
        Listing lst = currentProgram.getListing();
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/hop6.txt")));
        Function f = getFunctionContaining(toAddr(0x004d03f0L));
        out.println("########## FUN_004d03f0 size=" + f.getBody().getNumAddresses() + " ##########");
        Set<String> stores = new TreeSet<>();
        Set<String> calls = new TreeSet<>();
        int n = 0, jt = 0;
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            n++;
            StringBuilder b = new StringBuilder();
            try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
            out.println("  " + i.getAddress() + "  " + String.format("%-30s", b.toString().trim()) + "  " + i.toString());
            String t = i.toString();
            if (t.startsWith("MOV dword ptr [") && t.indexOf('[') < t.indexOf(',')) stores.add(t);
            if (t.startsWith("CALL")) calls.add(t + "  @" + i.getAddress());
            if (t.contains("*0x4 +")) jt++;
        }
        out.println("\n########## SUMMARY ##########");
        out.println("  instructions=" + n + "  indexed-jumps=" + jt);
        for (String s : stores) out.println("  W " + s);
        for (String c : calls) out.println("  C " + c);
        out.close();
        println("DONE -> hop6.txt");
    }
}
