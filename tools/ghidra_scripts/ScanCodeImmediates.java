// 代码立即数扫描：把「指令里的 .text 立即数」（典型 push imm32 / mov reg, imm32）
// 也作为引用证据渠道。数据表扫描看不见这类引用（运行时注册回调就靠它）。
// 输出：D:\MeteorProjects\_private\ghidra_scripts\codeimm_v4.json
import ghidra.app.script.GhidraScript;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.scalar.Scalar;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ScanCodeImmediates extends GhidraScript {

    static final long TEXT_LO = 0x00401000L;
    static final long TEXT_HI = 0x005A62BDL;

    @Override
    public void run() throws Exception {
        List<long[]> hits = new ArrayList<>();   // {target, from, opIndex}
        List<String> mnems = new ArrayList<>();
        int scanned = 0;
        InstructionIterator ii = currentProgram.getListing().getInstructions(true);
        while (ii.hasNext()) {
            Instruction ins = ii.next();
            if (ins == null) continue;
            scanned++;
            for (int op = 0; op < ins.getNumOperands(); op++) {
                int type = ins.getOperandType(op);
                if ((type & OperandType.DYNAMIC) != 0) continue;
                Object[] objs = ins.getOpObjects(op);
                for (Object o : objs) {
                    if (!(o instanceof Scalar)) continue;
                    long v = ((Scalar) o).getUnsignedValue();
                    if (v >= TEXT_LO && v < TEXT_HI) {
                        hits.add(new long[]{v, ins.getAddress().getOffset(), op});
                        mnems.add(ins.getMnemonicString());
                    }
                }
            }
        }
        println("INSN scanned=" + scanned + " immRefs=" + hits.size());

        try (PrintWriter pw = new PrintWriter(new FileWriter(
                "D:\\MeteorProjects\\_private\\ghidra_scripts\\codeimm_v4.json"))) {
            pw.print("{\"refs\":[");
            for (int i = 0; i < hits.size(); i++) {
                if (i > 0) pw.print(",");
                long[] h = hits.get(i);
                pw.print("{\"t\":" + h[0] + ",\"f\":" + h[1] + ",\"m\":\"" + mnems.get(i) + "\"}");
            }
            pw.print("]}");
        }
        println("WROTE codeimm_v4.json");
    }
}
