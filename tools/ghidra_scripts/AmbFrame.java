import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class AmbFrame extends GhidraScript {
    @Override
    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        Address a = toAddr(0x00574190L);
        Function f = getFunctionContaining(a);
        sb.append("=== per-frame parser @0x574190 ===\n");
        if (f == null) { sb.append("NOT IN FUNCTION\n"); }
        else {
            sb.append("func ").append(f.getName()).append(" entry=0x").append(f.getEntryPoint())
              .append(" size=").append(f.getBody().getNumAddresses()).append("\n\n");
            InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                sb.append("  ").append(ins.getAddress()).append("  ").append(ins.toString()).append("\n");
            }
        }
        java.io.PrintWriter w = new java.io.PrintWriter(new java.io.OutputStreamWriter(
            new java.io.FileOutputStream("D:/MeteorProjects/_private/ghidra_scripts/ambframe.txt"), "UTF-8"));
        w.print(sb.toString()); w.close();
        println("done");
    }
}
