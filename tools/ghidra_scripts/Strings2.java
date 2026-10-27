// Strings2.java - full string scan in a VA range + dump FUN_0045a450
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class Strings2 extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/strings2.txt")));

        out.println("########## A: strings 0x5c0000-0x5d4000 ##########");
        Address start = toAddr(0x005c0000L), end = toAddr(0x005d4000L);
        Listing lst = currentProgram.getListing();
        DataIterator di = lst.getDefinedData(start, true);
        int n = 0;
        while (di.hasNext()) {
            Data d = di.next();
            if (d.getAddress().compareTo(end) >= 0) break;
            DataType dt = d.getDataType();
            if (dt instanceof AbstractStringDataType || dt instanceof TerminatedStringDataType
                || dt instanceof StringDataType || dt instanceof UnicodeDataType) {
                Object v = d.getValue();
                if (v != null) {
                    String s = v.toString().replace("\n", "\\n");
                    if (s.length() > 1) { out.println(d.getAddress() + " : \"" + s + "\""); n++; }
                }
            }
        }
        out.println("count=" + n);

        out.println("\n########## B: DUMP FUN_0045a450 ##########");
        Function f = getFunctionContaining(toAddr(0x0045a450L));
        if (f == null) out.println("not found");
        else {
            out.println("entry=" + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                out.println("  " + i.getAddress() + "  " + i.toString());
            }
        }

        out.close();
        println("DONE -> strings2.txt");
    }
}
