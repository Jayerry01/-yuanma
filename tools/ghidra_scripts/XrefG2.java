// XrefG2 - who reads/writes the result globals produced by FUN_004d1740?
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;
import java.util.TreeMap;

public class XrefG2 extends GhidraScript {
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        String[] targets = { "0x5d59a4", "0x5d59e8" };
        StringBuilder sb = new StringBuilder();
        for (String t : targets) {
            Address a = toAddr(t);
            sb.append("==== xrefs to ").append(t).append(" ====\n");
            TreeMap<String,String> lines = new TreeMap<String,String>();
            ReferenceIterator ri = rm.getReferencesTo(a);
            while (ri.hasNext()) {
                Reference r = ri.next();
                Address from = r.getFromAddress();
                Function f = fm.getFunctionContaining(from);
                Instruction ins = listing.getInstructionAt(from);
                String mnem = (ins == null) ? "?" : ins.getMnemonicString();
                String val = String.format("  %s  %-6s type=%-8s op=%d  in %s",
                    from.toString(), mnem, r.getReferenceType().toString(),
                    r.getOperandIndex(),
                    (f == null ? "<no func>" : f.getName()));
                lines.put(from.toString(), val);
            }
            for (String v : lines.values()) sb.append(v).append("\n");
            sb.append("  total: ").append(lines.size()).append("\n\n");
        }
        println(sb.toString());
        java.io.FileWriter w = new java.io.FileWriter("D:/MeteorProjects/_private/ghidra_scripts/xref_globals.txt");
        w.write(sb.toString());
        w.close();
        println("XREFG2 DONE -> xref_globals.txt");
    }
}
