import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.AddressSetView;
import java.io.PrintWriter;
import java.io.FileWriter;

public class DumpFunctionsV10 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = "D:\\MeteorProjects\\_private\\ghidra_scripts\\fresh_functions_v10.json";
        PrintWriter pw = new PrintWriter(new FileWriter(out));
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        StringBuilder sb = new StringBuilder();
        sb.append("[\n");
        long totalBody = 0;
        int n = 0, ext = 0;
        while (it.hasNext()) {
            Function f = it.next();
            boolean isExt = f.isExternal();
            if (isExt) { ext++; continue; }
            long size = 0;
            AddressSetView set = f.getBody();
            if (set != null) { totalBody += set.getNumAddresses(); size = set.getNumAddresses(); }
            if (n > 0) sb.append(",\n");
            sb.append("{\"a\":\"").append(f.getEntryPoint().toString())
              .append("\",\"n\":\"").append(f.getName().replace("\\", "\\\\").replace("\"", "\\\""))
              .append("\",\"s\":").append(size)
              .append(",\"t\":").append(f.isThunk() ? "1" : "0").append("}");
            n++;
        }
        sb.append("\n]");
        pw.print(sb.toString());
        pw.close();
        println("DUMPED internal=" + n + " external=" + ext + " totalBodyBytes=" + totalBody);
    }
}
