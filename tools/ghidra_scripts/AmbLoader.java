// AmbLoader.java - dump the real read sequence of AmbLoader.LoadAmb @ 0x00574460
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class AmbLoader extends GhidraScript {

    void dump(StringBuilder sb, long va, int maxInstr) throws Exception {
        Address a = toAddr(va);
        Function f = getFunctionAt(a);
        if (f == null) f = getFunctionContaining(a);
        sb.append("\n===== 0x").append(Long.toHexString(va)).append(" =====\n");
        if (f == null) { sb.append("  NOT A FUNCTION\n"); return; }
        sb.append("  func: ").append(f.getName()).append("  entry=0x").append(f.getEntryPoint())
          .append("  size=").append(f.getBody().getNumAddresses()).append("\n");
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        int n = 0;
        while (it.hasNext() && n < maxInstr) {
            Instruction ins = it.next();
            sb.append("  ").append(ins.getAddress()).append("  ").append(ins.toString()).append("\n");
            n++;
        }
        sb.append("  ... total dumped: ").append(n).append("\n");
    }

    @Override
    public void run() throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append("=== AmbLoader.LoadAmb analysis ===\n");
        sb.append("image base = ").append(currentProgram.getImageBase()).append("\n");

        dump(sb, 0x00574460L, 900);

        // who calls it
        sb.append("\n=== callers of 0x00574460 ===\n");
        Address t = toAddr(0x00574460L);
        for (ghidra.program.model.symbol.Reference r : getReferencesTo(t)) {
            Function cf = getFunctionContaining(r.getFromAddress());
            sb.append("  from ").append(r.getFromAddress())
              .append("  type=").append(r.getReferenceType())
              .append("  in ").append(cf == null ? "?" : cf.getName() + "@0x" + Long.toHexString(cf.getEntryPoint().getOffset()))
              .append("\n");
        }

        java.io.PrintWriter w = new java.io.PrintWriter(new java.io.OutputStreamWriter(
            new java.io.FileOutputStream("D:/MeteorProjects/_private/ghidra_scripts/ambloader.txt"), "UTF-8"));
        w.print(sb.toString()); w.close();
        println("done");
    }
}
