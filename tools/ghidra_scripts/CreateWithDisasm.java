// 先反汇编再建函数：用于处理 createFunction 只出 1 字节体的情况。
// 用法：-postScript CreateWithDisasm.java <list.txt>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class CreateWithDisasm extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: CreateWithDisasm.java <list.txt>");
            return;
        }
        int created = 0, already = 0, failed = 0;
        try (BufferedReader r = new BufferedReader(
                new InputStreamReader(new FileInputStream(new File(args[0])), StandardCharsets.UTF_8))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                Address a = toAddr(Long.parseLong(line.replaceFirst("^0[xX]", ""), 16));
                if (getFunctionContaining(a) != null) {
                    already++;
                    continue;
                }
                disassemble(a);
                Function f = createFunction(a, null);
                if (f != null) created++;
                else failed++;
            }
        }
        println("DISASM_CREATE created=" + created + " already=" + already + " failed=" + failed);
    }
}
