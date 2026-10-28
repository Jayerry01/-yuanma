// CameraVtable: confirm the camera object's vtable (0x005AA658) and identify the
// per-frame Update among its 8 candidate virtual methods. Dumps disasm + xref-to.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import java.io.*;

public class CameraVtable extends GhidraScript {
    String hex(long va, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            try { byte b = currentProgram.getMemory().getByte(toAddr(va + i));
                  sb.append(String.format("%02x", b & 0xff)); } catch (Exception e) { break; }
        }
        return sb.toString();
    }
    String cstr(long va, int max) {
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < max; i++) {
            try { byte c = currentProgram.getMemory().getByte(toAddr(va + i));
                  if (c == 0) break;
                  t.append((c >= 32 && c < 127) ? (char)(c & 0xff) : '.'); } catch (Exception e) { break; }
        }
        return t.toString();
    }
    void dump(StringBuilder sb, long start, long end, String title) {
        sb.append("########## ").append(title).append("  ")
          .append(String.format("%08X-%08X", start, end)).append(" ##########\n");
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(toAddr(start), true);
        long n = 0;
        while (it.hasNext() && n < 5000) {
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
                                if (s.length() > 0) body = body.replace(String.format("0x%x", v),
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
        sb.append("===== CAMERA VTABLE 0x005AA658 DEEP DIVE =====\n\n");

        // camera ctor that writes MOV [ECX],0x005AA658 at 0x00502B3E
        dump(sb, 0x00502B00L, 0x00502C80L, "CAMERA_CTOR @0x00502B3E (MOV [ECX],0x005AA658)");

        // 8 candidate virtual methods of camera vtable 0x005AA658
        // [69]=004D0AC0 [85]=004CF540 [87]=004CB790 [99]=004CE540
        // [111]=004CC0A0 [115]=004CB800 [126]=004D0DB0 [130]=004CE2F0
        long[][] meth = {
            {0x004D0AC0L, 0x004D0D00L, "vslot69  @0x004D0AC0"},
            {0x004CF540L, 0x004CF7A0L, "vslot85  @0x004CF540"},
            {0x004CB790L, 0x004CBA00L, "vslot87  @0x004CB790"},
            {0x004CE540L, 0x004CE8A0L, "vslot99  @0x004CE540"},
            {0x004CC0A0L, 0x004CC400L, "vslot111 @0x004CC0A0"},
            {0x004CB800L, 0x004CBA00L, "vslot115 @0x004CB800 (SwitchExtraCamera)"},
            {0x004D0DB0L, 0x004D1000L, "vslot126 @0x004D0DB0"},
            {0x004CE2F0L, 0x004CE540L, "vslot130 @0x004CE2F0"},
        };
        for (long[] m : meth) dump(sb, m[0], m[1], m[2]);

        sb.append("===== XREF-TO (callers) =====\n\n");
        long[] all = {0x00502B3EL,0x004D0AC0L,0x004CF540L,0x004CB790L,0x004CE540L,
                      0x004CC0A0L,0x004CB800L,0x004D0DB0L,0x004CE2F0L};
        for (long a : all) xrefTo(sb, a, "0x" + String.format("%08X", a));

        String outDir = "D:/MeteorRE/evidence";
        new File(outDir).mkdirs();
        PrintWriter pw = new PrintWriter(new FileOutputStream(outDir + "/camera_vtable.txt", false));
        pw.print(sb.toString());
        pw.close();
        println("CameraVtable done -> evidence/camera_vtable.txt (" + sb.length() + " chars)");
    }
}
