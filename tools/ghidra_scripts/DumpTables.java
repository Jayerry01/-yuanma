// DumpTables.java — recover action tables from Meteor.exe
// Reads:
//   DAT_005e0068 / 74 / 78  as int** pointer arrays (handler tables)
//   DAT_00667588            as 0x14-stride config table (first 48 entries)
//   function containing 0x4559e4 (the "handler addr" used by state 2)
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class DumpTables extends GhidraScript {
    String OUT = "D:/MeteorProjects/_private/ghidra_scripts/tables_dump.txt";
    StringBuilder sb = new StringBuilder();
    Program program;
    Memory mem;

    long readU32(Address a) {
        try {
            byte[] b = new byte[4];
            mem.getBytes(a, b);
            return (b[0]&0xff) | ((b[1]&0xff)<<8) | ((b[2]&0xff)<<16) | ((long)(b[3]&0xff)<<24);
        } catch (Exception e) { return -1; }
    }

    String hex(long v) { return String.format("0x%08x", v & 0xffffffffL); }

    void dumpPtrTable(String name, long va, int count) {
        sb.append("==== "+name+" @ "+hex(va)+" (as "+count+" int* entries) ====\n");
        Address base = toAddr(va);
        // determine image range for code detection
        Address textStart = toAddr(0x401000L);
        Address textEnd   = toAddr(0x5A72BDL);
        for (int i = 0; i < count; i++) {
            Address a = base.add(i*4);
            long ptr = readU32(a);
            if (ptr == 0 || ptr == -1) { sb.append(String.format("  [%3d] null\n", i)); continue; }
            Address pa = toAddr(ptr);
            Function f = program.getFunctionManager().getFunctionAt(pa);
            boolean inText = pa.compareTo(textStart)>=0 && pa.compareTo(textEnd)<=0;
            String tag = f!=null ? ("FUN_"+String.format("%08x", ptr)) : (inText ? "code?" : "data");
            sb.append(String.format("  [%3d] -> %s   %s\n", i, hex(ptr), tag));
        }
        sb.append("\n");
    }

    void dumpConfigTable(long va, int entries) {
        sb.append("==== DAT_00667588 @ "+hex(va)+" (0x14 stride, "+entries+" entries) ====\n");
        Address base = toAddr(va);
        for (int i = 0; i < entries; i++) {
            Address e = base.add(i*0x14);
            long f0 = readU32(e.add(0x00));
            long f4 = readU32(e.add(0x04));
            long f8 = readU32(e.add(0x08));
            long fc = readU32(e.add(0x0c));
            sb.append(String.format("  [%2d] +0=%s +4=%s +8=%s +c=%s\n", i, hex(f0), hex(f4), hex(f8), hex(fc)));
        }
        sb.append("\n");
    }

    void funcContaining(long va) {
        Address a = toAddr(va);
        Function f = program.getFunctionManager().getFunctionContaining(a);
        sb.append("==== function containing "+hex(va)+" ====\n");
        if (f != null) sb.append("  FUN_"+String.format("%08x", f.getEntryPoint().getOffset())+"  name="+f.getName()+"\n");
        else sb.append("  (no function contains this address)\n");
        sb.append("\n");
    }

    public void run() throws Exception {
        program = currentProgram;
        mem = program.getMemory();
        dumpPtrTable("DAT_005e0068", 0x5e0068L, 64);
        dumpPtrTable("DAT_005e0074", 0x5e0074L, 64);
        dumpPtrTable("DAT_005e0078", 0x5e0078L, 64);
        dumpConfigTable(0x667588L, 48);
        funcContaining(0x4559e4L);
        funcContaining(0x453308L);
        try (PrintWriter pw = new PrintWriter(new FileOutputStream(OUT))) {
            pw.print(sb.toString());
        }
        printf("DUMP DONE -> %s (chars=%d)\n", OUT, sb.length());
    }
}
