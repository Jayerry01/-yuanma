// CameraDeepDive: decompile the camera system's non-virtual implementation functions
// and harvest xref-to (callers) for all camera-related functions, so we can identify
// the per-frame Camera_Update entry and who invokes it.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import java.io.*;

public class CameraDeepDive extends GhidraScript {

    String hex(long va, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            try {
                byte b = currentProgram.getMemory().getByte(toAddr(va + i));
                sb.append(String.format("%02x", b & 0xff));
            } catch (Exception e) { break; }
        }
        return sb.toString();
    }

    String cstr(long va, int max) {
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < max; i++) {
            try {
                byte c = currentProgram.getMemory().getByte(toAddr(va + i));
                if (c == 0) break;
                t.append((c >= 32 && c < 127) ? (char) (c & 0xff) : '.');
            } catch (Exception e) { break; }
        }
        return t.toString();
    }

    // raw disasm of [start,end) with string-pointer annotation
    void dump(StringBuilder sb, long start, long end, String title) {
        sb.append("########## ").append(title).append("  ")
          .append(String.format("%08X-%08X", start, end)).append(" ##########\n");
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(toAddr(start), true);
        long n = 0;
        while (it.hasNext() && n < 6000) {
            Instruction ins = it.next();
            long va = ins.getAddress().getOffset();
            if (va >= end) break;
            int len = (int) ins.getLength();
            String bytes = hex(va, len);
            String body = ins.toString();
            try {
                for (int i = 0; i < ins.getNumOperands(); i++) {
                    Object[] ops = ins.getOpObjects(i);
                    for (Object o : ops) {
                        if (o instanceof ghidra.program.model.scalar.Scalar) {
                            long v = ((ghidra.program.model.scalar.Scalar) o).getUnsignedValue();
                            if (v >= 0x5c0000L && v < 0x5d4000L) {
                                String s = cstr(v, 40);
                                if (s.length() > 0)
                                    body = body.replace(String.format("0x%x", v),
                                            String.format("0x%x =\"%s\"", v, s));
                            }
                        }
                    }
                }
            } catch (Exception e) {}
            sb.append(String.format("%08X  %-12s %s\n", va, bytes, body));
            n++;
        }
        sb.append("\n");
    }

    // xref-to: who calls / references this address
    void xrefTo(StringBuilder sb, long va, String label) {
        sb.append("--- XREF_TO ").append(label).append(" (0x")
          .append(String.format("%08X", va)).append(") ---\n");
        ghidra.program.model.symbol.ReferenceIterator refs =
            currentProgram.getReferenceManager().getReferencesTo(toAddr(va));
        boolean any = false;
        while (refs.hasNext()) {
            Reference r = refs.next();
            long from = r.getFromAddress().getOffset();
            sb.append(String.format("    0x%08X  %s\n", from, r.getReferenceType().toString()));
            any = true;
        }
        if (!any) sb.append("    (no references found)\n");
        sb.append("\n");
    }

    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append("===== CAMERA DEEP DIVE =====\n\n");

        // --- Part 1: disasm of the 9 non-virtual camera implementation functions ---
        // (these are NOT in any of the 18 vtables; likely plain funcs called from render loop)
        long[][] dis = {
            {0x005706C0L, 0x00570B4EL}, // FUN_005706C0 1190B
            {0x00560970L, 0x00560BB5L}, // FUN_00560970 625B
            {0x00560C10L, 0x00560E4DL}, // FUN_00560C10 573B
            {0x0056EC40L, 0x0056EE2EL}, // FUN_0056EC40 494B
            {0x0056C9B0L, 0x0056CAE7L}, // FUN_0056C9B0 347B
            {0x004B6020L, 0x004B612BL}, // FUN_004B6020 267B
            {0x0050915BL, 0x00509266L}, // FUN_0050915B 11B
            {0x005714E0L, 0x005714E8L}, // FUN_005714E0 8B
        };
        for (long[] d : dis) {
            dump(sb, d[0], d[1], "FUN_" + String.format("%08X", d[0]));
        }

        // --- Part 2: xref-to for all camera-related functions (callers = per-frame hint) ---
        long[] cam = {
            0x005706C0L, 0x0056E490L, 0x00560970L, 0x00560C10L, 0x0056EC40L, 0x004CE540L,
            0x0056C9B0L, 0x00492D80L, 0x004F3D50L, 0x004B6020L, 0x004F25B0L, 0x00496980L,
            0x004A62B0L, 0x00462270L, 0x004F1530L, 0x00463020L, 0x004A5540L, 0x004BB4B0L,
            0x004CB800L, 0x0050915BL, 0x005714E0L, 0x004DC040L, 0x004E4070L
        };
        sb.append("===== XREF-TO (callers) =====\n\n");
        for (long c : cam) {
            xrefTo(sb, c, "FUN_" + String.format("%08X", c));
        }

        // also dump the forwarder 0x492D80 body again with xrefs for completeness
        dump(sb, 0x00492D80L, 0x00492EC4L, "FORWARDER FUN_00492D80");

        String outDir = "D:/MeteorRE/evidence";
        new File(outDir).mkdirs();
        PrintWriter pw = new PrintWriter(new FileOutputStream(outDir + "/camera_deepdive.txt", false));
        pw.print(sb.toString());
        pw.close();
        println("CameraDeepDive done -> evidence/camera_deepdive.txt (" + sb.length() + " chars)");
    }
}
