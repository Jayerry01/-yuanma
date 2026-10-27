// 按引用者证据队列批量建函数（v6）。
// 前置校验：目标不在任何既有函数体内（第三轮截断教训）。
// 用法：-postScript CreateQueuedFunctions.java <queue.txt>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class CreateQueuedFunctions extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: CreateQueuedFunctions.java <queue.txt>");
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
                Function f = createFunction(a, null);
                if (f != null) created++;
                else failed++;
            }
        }
        println("QUEUE created=" + created + " already=" + already + " failed=" + failed);
    }
}
