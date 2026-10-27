// 删除指定的错误函数（建体过小 / 形状不符）。
// 用法：-postScript DeleteFunctions.java <list.txt>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class DeleteFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: DeleteFunctions.java <list.txt>");
            return;
        }
        int removed = 0, missing = 0;
        try (BufferedReader r = new BufferedReader(
                new InputStreamReader(new FileInputStream(new File(args[0])), StandardCharsets.UTF_8))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                Address a = toAddr(Long.parseLong(line.replaceFirst("^0[xX]", ""), 16));
                Function f = getFunctionAt(a);
                if (f == null) {
                    missing++;
                    continue;
                }
                removeFunction(f);
                removed++;
            }
        }
        println("DELETE removed=" + removed + " missing=" + missing);
    }
}
