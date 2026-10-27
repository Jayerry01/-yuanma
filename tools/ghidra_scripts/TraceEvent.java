// TraceEvent.java — who points at 0x4c8a70 (vtable slot?), and how each sender loads `this`.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.util.*;
import java.io.*;
import java.util.*;

public class TraceEvent extends GhidraScript {
    PrintWriter pw;

    public void run() throws Exception {
        pw = new PrintWriter(new FileWriter("D:/MeteorProjects/_private/ghidra_scripts/trace_event.txt"));
        log("=== TRACE EVENT: slot-3 receiver identification ===");

        // ---------- A. references TO 0x4c8a70 ----------
        Address target = toAddr(0x4c8a70L);
        Function pf = getFunctionAt(target);
        log("function at 0x4c8a70: " + (pf == null ? "NONE" : pf.getName() + " size=" + pf.getBody().getNumAddresses()));
        log("");
        log("=== A. XREFS (memory/code refs) TO 0x4c8a70 ===");
        ReferenceIterator rit = currentProgram.getReferenceManager().getReferencesTo(target);
        int n = 0;
        while (rit.hasNext() && n < 60) {
            Reference r = rit.next();
            Address from = r.getFromAddress();
            Data d = currentProgram.getListing().getDefinedDataContaining(from);
            Instruction ins = currentProgram.getListing().getInstructionContaining(from);
            Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
            log("  from 0x" + from +
                "  type=" + r.getReferenceType() +
                (d != null ? ("  inData=" + d.getAddress() + " (" + d.getDataType().getName() + ")") : "") +
                (ins != null ? ("  inInstr=" + ins.toString()) : "") +
                (f != null ? ("  [in " + f.getName() + "]") : ""));
            n++;
        }
        log("  (total shown: " + n + ")");

        // If any refs come from vtable-ish data, print the 8 slots around them
        log("");
        log("=== A2. context: candidate vtables containing a pointer to 0x4c8a70 ===");
        List<Address> cands = new ArrayList<Address>();
        rit = currentProgram.getReferenceManager().getReferencesTo(target);
        while (rit.hasNext()) {
            Reference r = rit.next();
            if (r.getReferenceType().isData()) {
                Data d = currentProgram.getListing().getDefinedDataContaining(r.getFromAddress());
                if (d != null) {
                    Address base = d.getAddress();
                    long off = r.getFromAddress().subtract(base);
                    log("  vtable candidate base=0x" + base + "  slotOffset=0x" + Long.toHexString(off) +
                        "  slotIndex=" + (off / 4));
                    cands.add(base);
                }
            }
        }
        Memory mem = currentProgram.getMemory();
        for (Address base : cands) {
            log("  --- dump vtable 0x" + base + " (12 slots) ---");
            for (int i = 0; i < 12; i++) {
                Address a = base.add(i * 4);
                try {
                    int v = mem.getInt(a);
                    Function fv = currentProgram.getFunctionManager().getFunctionAt(toAddr(v & 0xffffffffL));
                    log(String.format("    [%2d] 0x%08x  %s", i, v, (fv == null ? "(no func)" : fv.getName())));
                } catch (Exception e) {
                    log("    [" + i + "] unreadable");
                }
            }
        }

        // ---------- B. how does each sender load `this`? ----------
        log("");
        log("=== B. senders: instruction context of (*vtable + 0xc) call ===");
        int[] senders = { 0x4cb260, 0x4d0ac0, 0x4cf5b0, 0x4cd200, 0x4ceb50 };
        for (int sa : senders) {
            Function f = getFunctionAt(toAddr(sa));
            if (f == null) { log("  sender 0x" + Integer.toHexString(sa) + ": NO FUNCTION"); continue; }
            log("");
            log("  ###### sender " + f.getName() + " (0x" + Long.toHexString(sa) + ") ######");
            InstructionIterator ii = currentProgram.getListing().getInstructions(f.getBody(), true);
            List<Instruction> all = new ArrayList<Instruction>();
            while (ii.hasNext()) all.add(ii.next());
            for (int i = 0; i < all.size(); i++) {
                Instruction ins = all.get(i);
                String s = ins.toString();
                if (s.contains("0xc") || s.contains("CALL") || s.contains("MOV EAX,dword ptr [ECX]")) {
                    // print window around indirect call instructions
                }
                java.lang.reflect.Field df = null;
                // detect indirect call
                if (ins.getFlowType().isCall() && ins.getFlowType().isIndirect()) {
                    int lo = Math.max(0, i - 14);
                    for (int j = lo; j <= i; j++) {
                        Address ja = all.get(j).getAddress();
                        // mark memory operand aliases
                        String line = all.get(j).toString();
                        for (Object o : all.get(j).getReferencesFrom()) {
                            Reference rr = (Reference) o;
                            if (rr.getReferenceType().isData()) {
                                Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(rr.getToAddress());
                                line += "   ; <= " + rr.getToAddress() + (sym != null ? " " + sym.getName() : "");
                            }
                        }
                        log("    " + ja + "  " + line);
                    }
                    log("    ---------------------------------------------");
                }
            }
        }

        pw.flush();
        pw.close();
        log("=== TRACE DONE ===");
    }

    void log(String s) { println(s); pw.println(s); }
}
