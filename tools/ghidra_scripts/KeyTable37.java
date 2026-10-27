// KeyTable37: dump the .pos grammar keyword table (37 records, stride 0x24, id at +0x20).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import java.io.*;

public class KeyTable37 extends GhidraScript {

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

    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        StringBuilder sb = new StringBuilder();

        long base = 0x5D1930L, end = 0x5D1E64L, stride = 0x24;
        int n = (int) ((end - base) / stride);
        sb.append("keyword table: base=0x5D1930 end=0x5D1E64 stride=0x24 count=").append(n).append("\n");
        long idTable = base + 0x20;
        sb.append("id table base (returned by mapper): 0x").append(Long.toHexString(idTable))
          .append("  stride=0x24\n\n");
        sb.append(String.format("%-4s %-10s %-22s %s%n", "idx", "record", "name", "id"));

        long angervalueBase = -1;
        for (int i = 0; i < n; i++) {
            long rec = base + i * stride;
            String nm = cstr(rec, 32);
            long id = 0;
            try { id = mem.getInt(toAddr(rec + 0x20)) & 0xffffffffL; } catch (Exception e) {}
            if (nm.equals("angervalue")) angervalueBase = rec;
            sb.append(String.format("%-4d %08X   %-22s 0x%X (%d)%n", i, rec, nm, id, id));
        }

        sb.append("\n");
        if (angervalueBase > 0) {
            sb.append("angervalue record at 0x").append(Long.toHexString(angervalueBase))
              .append("  idx=").append((angervalueBase - base) / stride).append("\n");
            // neighbours
            for (int k = -2; k <= 2; k++) {
                long rec = angervalueBase + k * stride;
                long id = 0;
                try { id = mem.getInt(toAddr(rec + 0x20)) & 0xffffffffL; } catch (Exception e) {}
                sb.append(String.format("   [%+d] %08X  %-18s id=0x%X%n", k, rec, cstr(rec, 32), id));
            }
        }

        File out = new File("D:/MeteorRE/evidence/keytable37.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
