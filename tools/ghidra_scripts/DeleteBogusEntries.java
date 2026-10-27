// 清理第三轮误建的伪函数，并重建被它们截断的既有函数边界。
// 用法：-postScript DeleteBogusEntries.java <bogus_entries_v3.txt> <truncated_parents_v3.txt>
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class DeleteBogusEntries extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: DeleteBogusEntries.java <bogus.txt> <parents.txt>");
            return;
        }
        List<String> bogus = readLines(new File(args[0]));
        List<String> parents = readLines(new File(args[1]));
        FunctionManager fm = currentProgram.getFunctionManager();

        int removed = 0;
        for (String line : bogus) {
            if (line.trim().isEmpty()) continue;
            Address a = toAddr(Long.parseLong(line.trim().replaceFirst("^0[xX]", ""), 16));
            Function f = fm.getFunctionAt(a);
            if (f != null) {
                removeFunction(f);
                removed++;
            }
        }
        println("bogus removed = " + removed + " / " + bogus.size());

        int restored = 0;
        int failed = 0;
        for (String line : parents) {
            String[] p = line.split("\t");
            if (p.length < 3) continue;
            Address a = toAddr(Long.parseLong(p[0].replaceFirst("^0[xX]", ""), 16));
            Function f = fm.getFunctionAt(a);
            if (f != null) removeFunction(f);
            CreateFunctionCmd cmd = new CreateFunctionCmd(a);
            if (cmd.applyTo(currentProgram, monitor)) {
                restored++;
            } else {
                failed++;
                println("restore failed @ " + a);
            }
        }
        println("parents restored = " + restored + " , failed = " + failed);
    }

    private List<String> readLines(File f) throws Exception {
        List<String> out = new ArrayList<>();
        try (BufferedReader r = new BufferedReader(
                new InputStreamReader(new FileInputStream(f), StandardCharsets.UTF_8))) {
            String s;
            while ((s = r.readLine()) != null) out.add(s);
        }
        return out;
    }
}
