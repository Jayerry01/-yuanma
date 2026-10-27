// Weapon5.java - derive each weapon ctor from its singleton getter, then vtable -> slot 21
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;

public class Weapon5 extends GhidraScript {
    PrintWriter out;
    Memory mem;
    Listing lst;

    // the 12 singleton getters, in factory dispatch order (type 0..11)
    long[] getters = {0x004dd320L, 0x004e0770L, 0x004de920L, 0x004df140L, 0x004e0030L, 0x004de1d0L,
                      0x004df8e0L, 0x004dda70L, 0x004e0e80L, 0x004e18c0L, 0x004e3720L, 0x004e2e60L};

    public void run() throws Exception {
        mem = currentProgram.getMemory();
        lst = currentProgram.getListing();
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/weapon5.txt")));

        out.println("########## per-type: getter -> ctor -> vtable -> slot 21 ##########");
        for (int k = 0; k < getters.length; k++) {
            Function g = getFunctionContaining(toAddr(getters[k]));
            long ctor = 0;
            long objAddr = 0;
            InstructionIterator it = lst.getInstructions(g.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                String t = i.toString();
                if (t.startsWith("MOV ECX,0x")) {
                    try { objAddr = Long.parseLong(t.substring(12), 16); } catch (Exception e) { }
                }
                if (t.startsWith("CALL 0x") && !t.contains("0x005089bc")) {
                    try { ctor = Long.parseLong(t.substring(8), 16); } catch (Exception e) { }
                }
            }
            Function cf = ctor == 0 ? null : getFunctionContaining(toAddr(ctor));
            Long vt = null;
            if (cf != null) {
                InstructionIterator ci = lst.getInstructions(cf.getBody(), true);
                while (ci.hasNext()) {
                    Instruction i = ci.next();
                    String t = i.toString();
                    if (t.startsWith("MOV dword ptr [") && t.contains(",0x5a")) {
                        for (int op = 1; op < i.getNumOperands(); op++)
                            for (Object o : i.getOpObjects(op))
                                if (o instanceof Scalar) {
                                    long v = ((Scalar) o).getUnsignedValue();
                                    if (v >= 0x005a0000L && v < 0x005b0000L) vt = v;
                                }
                    }
                }
            }
            if (vt == null) {
                out.println(String.format("  type %2d getter 0x%08x obj 0x%08x ctor %s : NO vtable found",
                    k, getters[k], objAddr, ctor == 0 ? "?" : "0x" + Long.toHexString(ctor)));
                continue;
            }
            int v21 = mem.getInt(toAddr(vt + 21 * 4L));
            long p21 = v21 & 0xffffffffL;
            Function f21 = getFunctionContaining(toAddr(p21));
            out.println(String.format("  type %2d getter 0x%08x obj 0x%08x ctor 0x%08x size=%-4d vtable 0x%08x slot21 -> 0x%08x %s",
                k, getters[k], objAddr, ctor, cf.getBody().getNumAddresses(), vt, p21,
                f21 == null ? "?" : f21.getName() + " size=" + f21.getBody().getNumAddresses()));
        }

        out.println("\n########## sword (type 0) slot 21 body, byte level ##########");
        int v21 = mem.getInt(toAddr(0x005aab00L + 21 * 4L));
        Function f = getFunctionContaining(toAddr(v21 & 0xffffffffL));
        if (f != null) {
            out.println("  " + f.getName() + " size=" + f.getBody().getNumAddresses());
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction i = it.next();
                StringBuilder b = new StringBuilder();
                try { for (byte x : i.getBytes()) b.append(String.format("%02x ", x & 0xff)); } catch (Exception e) { }
                out.println("   " + i.getAddress() + "  " + String.format("%-24s", b.toString().trim()) + "  " + i.toString());
            }
        }
        out.close();
        println("DONE -> weapon5.txt");
    }
}
