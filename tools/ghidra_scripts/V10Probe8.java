import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.disassemble.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.util.task.*;
import java.io.*;
import java.util.*;

public class V10Probe8 extends GhidraScript {
    static class H { long s, e; int n; String kind; }

    public void run() throws Exception {
        String base = "D:/MeteorProjects/_private/ghidra_scripts/";
        String csvPath = base + "holes_v10.csv";
        String outPath = base + "v10_probe8_out.csv";

        List<H> ambig = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(csvPath));
        String line = br.readLine();
        while ((line = br.readLine()) != null) {
            String[] p = line.split(",");
            if (p.length < 4) continue;
            if (!"AMBIG".equals(p[3])) continue;
            if (Integer.parseInt(p[2]) <= 100) continue;
            H h = new H();
            h.s = Long.parseLong(p[0]); h.e = Long.parseLong(p[1]); h.n = Integer.parseInt(p[2]); h.kind = p[3];
            ambig.add(h);
        }
        br.close();

        Program program = currentProgram;
        Listing listing = program.getListing();
        FunctionManager fm = program.getFunctionManager();
        TaskMonitor mon = monitor;
        AddressSpace sp = program.getAddressFactory().getDefaultAddressSpace();

        PrintWriter pw = new PrintWriter(new FileWriter(outPath));
        pw.println("addr,n,verdict,codePct,bad,lastMnem,created");

        Disassembler dis = Disassembler.getDisassembler(program, mon, null);
        int codeCand = 0, created = 0, data = 0;
        for (H h : ambig) {
            Address a = sp.getAddress(h.s);
            Address e = a.add(h.n - 1);
            dis.disassemble(a, new AddressSet(a, e), true);

            long codeBytes = 0, badBytes = 0, dataBytes = 0;
            Address cur = a;
            String lastMnem = "";
            while (cur.compareTo(e) <= 0) {
                CodeUnit cu = listing.getCodeUnitAt(cur);
                if (cu == null) { badBytes += 1; cur = cur.add(1); continue; }
                int len = cu.getLength();
                if (cu instanceof Instruction) {
                    Instruction ins = (Instruction) cu;
                    String m = ins.getMnemonicString();
                    if (m.equals("??")) badBytes += len;
                    else { codeBytes += len; lastMnem = m; }
                } else { dataBytes += len; }
                cur = cur.add(len);
            }
            long denom = (codeBytes + dataBytes + badBytes);
            double codePct = denom > 0 ? codeBytes * 100.0 / denom : 0;
            boolean term = lastMnem.equals("RET") || lastMnem.equals("RETN") ||
                           lastMnem.equals("JMP") || lastMnem.startsWith("J");
            String verdict = (badBytes > 5 && codePct < 60) ? "DATA"
                           : (codePct > 60 && term) ? "CODE_CANDIDATE"
                           : (codePct > 60) ? "CODE_CANDIDATE" : "DATA";
            String crt = "";
            if ("CODE_CANDIDATE".equals(verdict)) {
                codeCand++;
                if (fm.getFunctionAt(a) == null) {
                    try {
                        Function f = fm.createFunction(null, a, new AddressSet(a, e), SourceType.USER_DEFINED);
                        if (f != null) { created++; crt = "CREATED"; }
                    } catch (Exception ex) { crt = "CREATE_FAIL"; }
                } else crt = "EXISTS";
            } else data++;
            pw.println(String.format("%08X,%d,%s,%.0f,%d,%s,%s", h.s, h.n, verdict, codePct, badBytes, lastMnem, crt));
        }
        pw.close();
        printf("CODE_CANDIDATE=%d CREATED=%d DATA=%d\n", codeCand, created, data);
    }
}
