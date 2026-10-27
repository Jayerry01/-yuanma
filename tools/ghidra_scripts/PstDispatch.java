// PstDispatch: disassemble the .pst builtin/behavior dispatcher and the AI attribute parser.
// Prints address + raw bytes + mnemonic + operands so every quote is byte-verifiable.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import java.io.*;

public class PstDispatch extends GhidraScript {

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

    void dump(StringBuilder sb, long start, long end, String title) {
        sb.append("########## ").append(title).append("  ").append(String.format("%08X-%08X", start, end))
          .append(" ##########\n");
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(toAddr(start), true);
        long n = 0;
        while (it.hasNext() && n < 4000) {
            Instruction ins = it.next();
            long va = ins.getAddress().getOffset();
            if (va >= end) break;
            int len = (int) ins.getLength();
            String bytes = hex(va, len);
            String body = ins.toString();
            // resolve any immediate that looks like a string pointer in 0x5c0000-0x5d4000
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
            } catch (Exception e) { }
            sb.append(String.format("%08X  %-22s  %s%n", va, bytes, body));
            n++;
        }
        sb.append("\n");
    }

    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        // builtin / behavior dispatcher region
        dump(sb, 0x4F8860L, 0x4F9420L, "A: .pst builtin+behavior dispatcher (0x4F8860-0x4F9420)");
        // Perform handler (action names: faceto / guard / ...)
        dump(sb, 0x4F94A0L, 0x4F9720L, "B: Perform handler - action names (0x4F94A0-0x4F9720)");
        // SetTarget handler (target kinds: char / waypoint)
        dump(sb, 0x4F9AD0L, 0x4F9CA0L, "C: SetTarget handler - target kinds (0x4F9AD0-0x4F9CA0)");
        // AI attribute parser region
        dump(sb, 0x501350L, 0x5014D0L, "D: AI attribute parser (0x501350-0x5014D0)");
        // scene-item VM registration (second, independent builtin set)
        dump(sb, 0x5609E0L, 0x560AE0L, "I: scene-item VM builtin registration (0x5609E0-0x560AE0)");
        // central action-name dispatcher (shared by Perform() and player input)
        dump(sb, 0x504C40L, 0x504F60L, "G: central action-name dispatcher (0x504C40-0x504F60)");
        // player input -> action name
        dump(sb, 0x4C0680L, 0x4C0810L, "H: player input -> action name (0x4C0680-0x4C0810)");
        // J: OnStart hook - NPC .pst loader site
        dump(sb, 0x4BFB90L, 0x4BFC00L, "J: OnStart in NPC .pst loader (0x4BFB90-0x4BFC00)");
        // K: OnStart hook - second site (behavior region)
        dump(sb, 0x5038A0L, 0x503960L, "K: OnStart 2nd site (0x5038A0-0x503960)");
        // L: scene-item callback name construction (sprintf "%s_OnIdle" etc.)
        dump(sb, 0x563E10L, 0x563F60L, "L: scene callback name builder (0x563E10-0x563F60)");
        // M: SetTarget handler - the 0x666858 table consumer
        dump(sb, 0x4F9B30L, 0x4F9CE0L, "M: SetTarget handler / 0x666858 consumer (0x4F9B30-0x4F9CE0)");
        // N: SetTarget prologue - where does the slot index come from
        dump(sb, 0x4F9AD0L, 0x4F9B40L, "N: SetTarget prologue (0x4F9AD0-0x4F9B40)");
        // O: Distance builtin - reveals the actor position offset
        dump(sb, 0x4F9CA0L, 0x4F9D20L, "O: Distance builtin (0x4F9CA0-0x4F9D20)");
        // P: who reads 180.0f - camera distance or 180 degrees?
        dump(sb, 0x4CCB70L, 0x4CCBD0L, "P1: 180.0f site A (player ctrl 0x4CCB70-0x4CCBD0)");
        dump(sb, 0x4CD4A0L, 0x4CD4E0L, "P2: 180.0f site B (player ctrl 0x4CD4A0-0x4CD4E0)");
        dump(sb, 0x4FD3D0L, 0x4FD440L, "P3: 180.0f site C/D (0x4FD3D0-0x4FD440)");
        // Q: console command dispatcher (freecam / camera / position ...)
        dump(sb, 0x4B6280L, 0x4B6560L, "Q: console command dispatcher (0x4B6280-0x4B6560)");
        // R: console command dispatch + camera handler
        dump(sb, 0x4B6560L, 0x4B6B00L, "R: cmd dispatch + camera handler (0x4B6560-0x4B6B00)");
        // S: more console handlers - collect vtable calls on the camera object [EBP+0x2488]
        dump(sb, 0x4B6B00L, 0x4B7200L, "S: more cmd handlers / camera obj vtables (0x4B6B00-0x4B7200)");
        // T: candidate construction site of the +0x2488 object
        dump(sb, 0x48D150L, 0x48D260L, "T: +0x2488 obj ctor candidate (0x48D150-0x48D260)");
        // U: the forwarder that touches +0x2488
        dump(sb, 0x492D80L, 0x492E20L, "U: +0x2488 forwarder (0x492D80-0x492E20)");
        // behavior object tables: what lives at the pushed 0x50xxxx targets
        dump(sb, 0x503960L, 0x503D40L, "E: behavior objects 0x503960-0x503D40");
        dump(sb, 0x504550L, 0x504AC0L, "F: behavior objects 0x504550-0x504AC0");

        File out = new File("D:/MeteorRE/evidence/pst_dispatch.txt");
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(out), "UTF-8"))) {
            pw.print(sb.toString());
        }
        println("wrote " + out.getAbsolutePath());
    }
}
