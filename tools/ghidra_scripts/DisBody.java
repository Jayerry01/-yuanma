// DisBody - dump instruction listing for a function body to a text file.
// Resolves raw mnemonics so we can tell MOV vs OR for the keyword bit assignments.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;

public class DisBody extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outFile = "D:/MeteorProjects/_private/ghidra_scripts/dis_body.txt";
        String entryArg = "0x4d1740";
        if (args != null && args.length > 0 && args[0].trim().length() > 0) {
            entryArg = args[0].trim();
            if (args.length > 1 && args[1].trim().length() > 0) outFile = args[1].trim();
        }
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        Function f = fm.getFunctionAt(toAddr(entryArg));
        if (f == null) {
            println("NO FUNCTION at " + entryArg);
            return;
        }
        Address start = f.getEntryPoint();
        Address end = f.getBody().getMaxAddress();
        println("FUNC " + f.getName() + "  " + start + " .. " + end + "  size=" + f.getBody().getNumAddresses());
        StringBuilder sb = new StringBuilder();
        Instruction inst = listing.getInstructionAt(start);
        int n = 0;
        while (inst != null && inst.getAddress().compareTo(end) <= 0 && n < 40000) {
            String line = String.format("%s  %-8s %s",
                inst.getAddress().toString(),
                inst.getMnemonicString(),
                inst.toString().substring(inst.toString().indexOf(' ') >= 0
                    ? inst.toString().indexOf(' ') + 1 : 0).trim());
            sb.append(line).append("\n");
            n++;
            inst = inst.getNext();
        }
        java.io.FileWriter w = new java.io.FileWriter(outFile);
        w.write(sb.toString());
        w.close();
        println("DISBODY DONE  instrs=" + n + " -> " + outFile);
    }
}
