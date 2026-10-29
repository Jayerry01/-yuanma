#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""E 段 152 项队列 · 第二批 2a：SMALL_ARITH_OR_PREDICATE 18 项定名。

判据：evidence/semE_pseudo/<addr>.c 的**花括号配对本函数体**（排除 Ghidra 附带函数）。
规则：证据落到具体系数/常量/库调用/虚表槽，不接受"未发现反证"；
     空桩按地址后缀区分以保持名称唯一；地址统一 0x + 大写；双向集合断言。

输出：evidence/semE_batch2a_arith_named_20261029.tsv
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REAUDIT = os.path.join(ROOT, "evidence", "semE_getter_reaudit_20261029.tsv")
OUT = os.path.join(ROOT, "evidence", "semE_batch2a_arith_named_20261029.tsv")

T = [
    ("0x004153B0", "RgbToLuma_Store_768", "COLOR_MATH", "HIGH",
     "*(float *)(DAT_005D5A0C+0x768) = param_3*0.114 + param_2*0.587 + param_1*0.299"
     " —— ITU-R BT.601 亮度系数（0.299R+0.587G+0.114B），写入全局 +0x768"),
    ("0x00421B00", "Flag_0x200000_By_IdParity", "BIT_SELECT", "MEDIUM",
     "return ((in_ID & 1) != 1) * 0x200000 ^ (in_ID & 1) * 0x200000"
     " —— 按 ID 最低位二选一互斥产出 0 / 0x200000（Ghidra 对标志位选择的近似表达）"),
    ("0x00428D40", "FixedDiv_64_Shift16", "FIXED_POINT", "HIGH",
     "__alldiv(param_1 << 0x10, ((int)param_1 >> 0x1f) << 0x10 | param_1 >> 0x10, param_2, param_2 >> 0x1f)"
     " —— 32 位左移 16 位后做 64 位除法（16.16 定点除）"),
    ("0x00428D70", "FixedDiv_64_Shift8", "FIXED_POINT", "HIGH",
     "__alldiv(param_1 << 8, ((int)param_1 >> 0x1f) << 8 | param_1 >> 0x18, …) —— 8.24 定点除"),
    ("0x00428DA0", "FixedDiv_64_Shift23", "FIXED_POINT", "HIGH",
     "__alldiv(param_1 << 0x17, ((int)param_1 >> 0x1f) << 0x17 | param_1 >> 9, …) —— 23.9 定点除"),
    ("0x00473D80", "VirtualCall_IsZero_SlotA0", "VIRTUAL_CALL", "MEDIUM",
     "(**(code **)(*DAT_005E0370 + 0xA0))(DAT_005E0370, param_1..3) == 0 —— 全局单例 vtable 槽 0xA0"),
    ("0x00478E70", "Compute_Align16or32_Then_Dispatch", "SIZE_COMPUTE", "HIGH",
     "DAT_005E04A0 = ((param_1 < 0x18) - 1 & 0x10) + 0x10 —— 穷举可验：p1<0x18 → 0x10，否则 0x20；"
     "再 (*(code *)PTR_FUN_005C80B4)(DAT_005E04A0)"),
    ("0x00483800", "VirtualCall_Void_Sub36C54_Slot14C", "VIRTUAL_CALL", "MEDIUM",
     "(**(code **)(**(int **)(param_1 + 0x36C54) + 0x14C))(*(int **)(param_1 + 0x36C54), param_2..4)；无返回值"),
    ("0x004A1D30", "Is_Whitespace_Char", "CTYPE", "HIGH",
     "param_1 为 ' ' / '\\r' / '\\n' / '\\t' 之一返回 1，否则 0（CRT isspace 的非 locale 简化形态）"),
    ("0x004AD500", "VirtualCall_Void_Sub250_Slot18", "VIRTUAL_CALL", "MEDIUM",
     "(**(code **)(**(int **)(param_1 + 0x250) + 0x18))(param_1, param_2..5)；无返回值"),
    ("0x0050F143", "Stub_Return_Zero_50F143", "STUB", "HIGH", "函数体仅 return 0;"),
    ("0x00514AC3", "Get_FPU_ControlWord", "FPU", "HIGH", "return (int)in_FPUControlWord; —— 返回 x87 控制字"),
    ("0x00514AE6", "Stub_Return_Void_514AE6", "STUB", "HIGH", "函数体仅 return;（无副作用）"),
    ("0x00514F7F", "Compose_LongDouble_From_Halves", "FLOAT_MATH", "MEDIUM",
     "local_c = (double)CONCAT26((param_2 + 0x3FE) * 0x10 | param_1._6_2_ & 0x800F, (undefined6)param_1);"
     " return (float10)local_c; —— 由两段拼装 80 位扩展精度"),
    ("0x0052C460", "Get_Global_If_Three_Ready", "PREDICATE", "MEDIUM",
     "DAT_0072329C != 0 && DAT_00723270 != 0 && DAT_00723264 != 0 时返回 DAT_0072326C，否则 0"),
    ("0x00591140", "AlignDown4_Two_Globals", "ALIGN", "HIGH",
     "DAT_0072C1AC += (DAT_0072C1AC - DAT_0072C1A8 >> 2) * -4；DAT_0072C198 同式"
     " —— 两个全局各自按 4 字节向下对齐收缩"),
    ("0x00593DD4", "Stub_Return_Void_593DD4", "STUB", "HIGH", "函数体仅 return;（无副作用）"),
    ("0x00596800", "Stub_Return_Void_596800", "STUB", "HIGH", "函数体仅 return;（无副作用）"),
]


def main():
    expect = set()
    with open(REAUDIT, errors="replace") as f:
        for i, line in enumerate(f):
            if i == 0:
                continue
            c = line.rstrip("\n").split("\t")
            if len(c) >= 3 and c[2] == "SMALL_ARITH_OR_PREDICATE":
                expect.add(c[0].upper().replace("0X", "0x"))
    got = {a for a, *_ in T}
    missing, extra = sorted(expect - got), sorted(got - expect)
    if missing or extra:
        print("!! 集合不等：缺 %d 项、多 %d 项" % (len(missing), len(extra)))
        for a in missing:
            print("   MISSING:", a)
        for a in extra:
            print("   EXTRA  :", a)
        sys.exit(1)
    print("集合断言通过：18 项双向差为空（SMALL_ARITH_OR_PREDICATE）")

    with open(OUT, "w", errors="replace") as f:
        f.write("Addr\tOldLabel\tReauditClass\tNewName\tFamily\tConfidence\tEvidence\n")
        for a, name, fam, conf, ev in T:
            f.write("%s\tInline_Getter_Setter\tSMALL_ARITH_OR_PREDICATE\t%s\t%s\t%s\t%s\n"
                    % (a, name, fam, conf, ev))
    conf = {}
    for _, _, _, c_, _ in T:
        conf[c_] = conf.get(c_, 0) + 1
    print("置信: HIGH=%d  MEDIUM=%d  UNRESOLVED=%d"
          % (conf.get("HIGH", 0), conf.get("MEDIUM", 0), conf.get("UNRESOLVED", 0)))
    print("输出: %s" % OUT)


if __name__ == "__main__":
    main()
