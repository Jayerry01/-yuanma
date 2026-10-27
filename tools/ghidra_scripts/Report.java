// Report.java - classify FUN_004cff40 (674 B): pure report vs state machine
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class Report extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/report40.txt")));

        Function f = getFunctionContaining(toAddr(0x004cff40L));
        out.println("########## FUN_004cff40 size=" + f.getBody().getNumAddresses() + " ##########");

        Set<String> writes = new TreeSet<>();
        Set<String> calls = new TreeSet<>();
        Set<String> dataRefs = new TreeSet<>();
        int switches = 0, insn = 0;

        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction i = it.next();
            insn++;
            StringBuilder b = new StringBuilder();
            try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
            out.println("  " + i.getAddress() + "  " + String.format("%-34s", b.toString().trim()) + "  " + i.toString());

            String t = i.toString();
            if (t.startsWith("MOV dword ptr [") && t.indexOf('[') < t.indexOf(',')) writes.add(t);
            if (t.startsWith("CALL")) calls.add(t);
            if (t.startsWith("JMP dword ptr [") && t.contains("*0x4")) switches++;
            for (int op = 0; op < i.getNumOperands(); op++)
                for (Object o : i.getOpObjects(op))
                    if (o instanceof Address) {
                        long a = ((Address) o).getOffset();
                        if (a >= 0x005c0000L && a < 0x005f0000L) dataRefs.add(String.format("0x%08x", a));
                    }
        }

        out.println("\n########## SUMMARY ##########");
        out.println("  instructions = " + insn);
        out.println("  indexed jumps (jump tables) = " + switches);
        out.println("  memory stores (state writes) = " + writes.size());
        for (String w : writes) out.println("    W " + w);
        out.println("  call sites = " + calls.size());
        for (String c : calls) out.println("    C " + c);
        out.println("  data refs in 0x5C0000-0x5EFFFF = " + dataRefs.size());
        for (String d : dataRefs) {
            long a = Long.parseLong(d.substring(2), 16);
            Data dd = lst.getDataAt(toAddr(a));
            String val = "";
            if (dd != null) val = String.valueOf(dd.getValue());
            out.println("    D " + d + "   " + (val.length() > 60 ? val.substring(0, 60) + "..." : val));
        }
        out.close();
        println("DONE -> report40.txt");
    }
}
