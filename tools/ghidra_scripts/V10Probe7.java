import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.*;

public class V10Probe7 extends GhidraScript {
    static class H { long s, e; int n; String kind; }

    public void run() throws Exception {
        String base = "D:/MeteorProjects/_private/ghidra_scripts/";
        String csvPath = base + "holes_v10.csv";
        String outPath = base + "v10_probe7_out.csv";

        List<H> potential = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(csvPath));
        String line = br.readLine(); // header
        while ((line = br.readLine()) != null) {
            String[] p = line.split(",");
            if (p.length < 4) continue;
            if (!"POTENTIAL_ENTRY".equals(p[3])) continue;
            H h = new H();
            h.s = Long.parseLong(p[0]); h.e = Long.parseLong(p[1]);
            h.n = Integer.parseInt(p[2]); h.kind = p[3];
            potential.add(h);
        }
        br.close();

        Program program = currentProgram;
        FunctionManager fm = program.getFunctionManager();
        AddressSpace sp = program.getAddressFactory().getDefaultAddressSpace();

        PrintWriter pw = new PrintWriter(new FileWriter(outPath));
        pw.println("addr,action,result,note");
        int created = 0, failed = 0, skipped = 0;
        for (H h : potential) {
            Address a = sp.getAddress(h.s);
            if (fm.getFunctionAt(a) != null) { skipped++; pw.println(String.format("%08X,skip,EXISTS,", h.s)); continue; }
            Function f = null;
            try {
                AddressSet as = new AddressSet(a, a.add(h.n - 1));
                f = fm.createFunction(null, a, as, SourceType.USER_DEFINED);
            } catch (Exception ex) { f = null; }
            if (f != null) { created++; pw.println(String.format("%08X,create,OK,body=%d", h.s, f.getBody().getNumAddresses())); }
            else { failed++; pw.println(String.format("%08X,create,FAIL,", h.s)); }
        }
        pw.close();
        printf("CREATED=%d FAILED=%d SKIPPED=%d\n", created, failed, skipped);
    }
}
