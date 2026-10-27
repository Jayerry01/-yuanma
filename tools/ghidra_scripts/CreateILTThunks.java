// 批量建立 ILT / 增量链接 thunk：形状 B8 <imm32> E9 <rel32>，尾部 CC 对齐。
// 前置校验：目标不在任何既有函数体内 + 首字节模式复核（第三轮的教训）。
// 用法：-postScript CreateILTThunks.java <ilt_candidates.txt>
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class CreateILTThunks extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: CreateILTThunks.java <candidates.txt>");
            return;
        }
        Memory mem = currentProgram.getMemory();
        int created = 0, already = 0, badPattern = 0, failed = 0;
        int lineNo = 0;
        try (BufferedReader r = new BufferedReader(
                new InputStreamReader(new FileInputStream(new File(args[0])), StandardCharsets.UTF_8))) {
            String line;
            while ((line = r.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;
                lineNo++;
                long off = Long.parseLong(line.replaceFirst("^0[xX]", ""), 16);
                Address a = toAddr(off);

                Function exist = getFunctionContaining(a);
                if (exist != null) {
                    already++;
                    continue;
                }
                byte[] b = new byte[6];
                try {
                    mem.getBytes(a, b);
                } catch (Exception ex) {
                    badPattern++;
                    continue;
                }
                if ((b[0] & 0xFF) != 0xB8 || (b[5] & 0xFF) != 0xE9) {
                    badPattern++;
                    continue;
                }
                Function f = createFunction(a, "thunk_ilt_" + String.format("%08X", off));
                if (f != null) {
                    created++;
                } else {
                    failed++;
                }
            }
        }
        println("ILT lines=" + lineNo + " created=" + created + " already=" + already
                + " badPattern=" + badPattern + " failed=" + failed);
    }
}
