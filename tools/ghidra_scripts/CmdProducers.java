// CmdProducers.java - find every call site of the form: PUSH cmd ; ... ; CALL [reg + 0xc]
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.util.*;

public class CmdProducers extends GhidraScript {
    PrintWriter out;

    public void run() throws Exception {
        out = new PrintWriter(new BufferedWriter(new FileWriter(
            "D:/MeteorProjects/_private/ghidra_scripts/cmdprod.txt")));
        Listing lst = currentProgram.getListing();

        out.println("########## command emission sites (PUSH cmd ... CALL [reg+0xc]) ##########");
        int total = 0;
        for (Function f : lst.getFunctions(true)) {
            List<Instruction> buf = new ArrayList<>();
            InstructionIterator it = lst.getInstructions(f.getBody(), true);
            while (it.hasNext()) buf.add(it.next());
            for (int i = 0; i < buf.size(); i++) {
                Instruction ins = buf.get(i);
                String t = ins.toString();
                if (!t.startsWith("PUSH 0x")) continue;
                Object[] objs = ins.getOpObjects(0);
                if (objs.length != 1 || !(objs[0] instanceof Scalar)) continue;
                long v = ((Scalar) objs[0]).getUnsignedValue();
                if (v > 0x60) continue;
                // look ahead up to 4 instructions for CALL [reg + 0xc]
                boolean hit = false;
                String callLine = "";
                for (int k = i + 1; k < Math.min(i + 5, buf.size()); k++) {
                    String ct = buf.get(k).toString();
                    if (ct.startsWith("CALL dword ptr [") && ct.contains("+ 0xc]")) {
                        hit = true; callLine = buf.get(k).getAddress() + " " + ct; break;
                    }
                    if (ct.startsWith("RET") || ct.startsWith("JMP")) break;
                }
                if (!hit) continue;
                out.println(String.format("  cmd 0x%-3x  push@%s  call@%s   in %s size=%d",
                    v, ins.getAddress(), callLine.split(" ")[0], f.getName(), f.getBody().getNumAddresses()));
                total++;
            }
        }
        out.println("TOTAL = " + total);

        out.println("\n########## per-command counts ##########");
        out.close();
        println("DONE -> cmdprod.txt");
    }
}
