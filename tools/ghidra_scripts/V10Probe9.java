import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.*;

public class V10Probe9 extends GhidraScript {
    public void run() throws Exception {
        String base = "D:/MeteorProjects/_private/ghidra_scripts/";
        String csvPath = base + "v10_probe8_out.csv";

        List<Long> addrs = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(csvPath));
        String line = br.readLine(); // header
        while ((line = br.readLine()) != null) {
            String[] p = line.split(",");
            if (p.length < 7) continue;
            if ("CODE_CANDIDATE".equals(p[2]) && "CREATE_FAIL".equals(p[6])) {
                addrs.add(Long.parseLong(p[0], 16));
            }
        }
        br.close();

        Program program = currentProgram;
        FunctionManager fm = program.getFunctionManager();
        AddressSpace sp = program.getAddressFactory().getDefaultAddressSpace();

        int created = 0, failed = 0, exists = 0;
        for (long va : addrs) {
            Address a = sp.getAddress(va);
            if (fm.getFunctionAt(a) != null) { exists++; printf("%08X EXISTS\n", va); continue; }
            Function f = null;
            try {
                f = fm.createFunction(null, a, (AddressSetView) null, SourceType.USER_DEFINED);
            } catch (Exception ex) { f = null; }
            if (f != null) { created++; printf("%08X CREATED body=%d\n", va, f.getBody().getNumAddresses()); }
            else { failed++; printf("%08X STILL_FAIL\n", va); }
        }
        printf("RECOVERED=%d FAILED=%d EXISTS=%d\n", created, failed, exists);
    }
}
