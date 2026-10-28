#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""E 段 152 项队列 · 第一批 31 项定名（29 单调用转发 + 2 构造器）。

判据：evidence/semE_pseudo/<addr>.c（花括号配对后的**本函数体**，排除 Ghidra 附带的后续函数）
      + evidence/semE_getter_reaudit_20261029.tsv 的再判读类别。
规则：证据必须落到"被调名+调用点"或"写入的 vtable 地址"；不接受"未发现反证"。
     构造器先过 ctor/dtor 判别：末次写自身 vtable = 构造器；
     首写自身 + (**vtable)(1) 释放成员 + 末尾回写基类 = 析构链。
地址格式统一 0x + 大写。集合与队列双向断言，不等即报错。

输出：evidence/semE_batch1_named_20261029.tsv
"""
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REAUDIT = os.path.join(ROOT, "evidence", "semE_getter_reaudit_20261029.tsv")
OUT = os.path.join(ROOT, "evidence", "semE_batch1_named_20261029.tsv")

# (Addr, NewName, Family, Confidence, Evidence)
D3 = "FUN_00518F77(1)（D3DX CPU 特性选表器）后经 (*(code *)PTR_FUN_%s)(6 参) 派发；" \
     "槽区 0x005CD900–0x005CD970 为 29 项连续函数指针，静态值自指、运行时改写 ⇒ 具体 D3DX API 不可静态判定"

T = [
    # ---- 构造器 2 项（ctor/dtor 判别已过）----
    ("0x00402850", "Ctor_StringBufObj_vt_5A83C8", "CTOR", "MEDIUM",
     "先 *param_1=&PTR_FUN_005A83D0，末次写 &PTR_FUN_005A83C8（末次写自身 vtable ⇒ 构造器）；"
     "_strncpy(param_1+3, *param_2, 0x100) + *(param_1+0x10B)=0；无 (**vtable)(1) 释放成员 ⇒ 非析构链"),
    ("0x004BD330", "Ctor_Obj_SubPtr_vt_5AA368", "CTOR", "MEDIUM",
     "*param_1=&PTR_FUN_005AA368（唯一一次即末次写自身 vtable）；param_1[4]=&PTR_LAB_005AA344；"
     "param_1[0x86]=8；无释放成员 ⇒ 构造器"),
    # ---- 单调用转发 29 项 ----
    ("0x00432AF0", "Mci_Stop_Device_If_Active", "MCI_IO", "HIGH",
     "FUN_00432B40()!=0 时 mciSendCommandA(DAT_005D5B40, 0x808(MCI_STOP), 0, 0)"),
    ("0x004738C0", "Get_Id_From_Handle_dom04_Flagged", "HANDLE_QUERY", "HIGH",
     "调 0x00410B30（已定名 Id_Handle_Lookup_dom04）；结果非空且 *(iVar1+0x14) 非空 → **(iVar1+0x14) | 0x2000000"),
    ("0x00474320", "Pack_RGBA_StoreGlobal_Then_Dispatch", "COLOR_DISPATCH", "MEDIUM",
     "DAT_005E07D0 = FUN_00475C50(p1&0xff, p2&0xff, p3&0xff, p4&0xff)（0..255 钳位打包）；"
     "再 (*(code *)PTR_FUN_005C7C6C)(p1..p4)"),
    ("0x0047B1F0", "QueryPerformanceCounter_Into_Field8", "TIMING", "HIGH",
     "FUN_0047B1D0(param_1) 非空且 DAT_005F16C8!=0 → QueryPerformanceCounter((LARGE_INTEGER *)(iVar1+8))"),
    ("0x0047D2C0", "Set_Defaults_m90_90_90_450", "CONFIG_SET", "MEDIUM",
     "FUN_0047D000(param_1, 0xC2B40000(-90.0), 0x42B40000(90.0), 0x42B40000(90.0), 0x43E10000(450.0))"),
    ("0x00490980", "Prep_Then_VirtualCall_Sub22A0_Slot3", "VIRTUAL_CALL", "MEDIUM",
     "FUN_004A9600(param_2,param_3) 后 (**(code **)(**(int **)(param_1+0x22A0)+0xC))(param_1,param_2,param_3)"),
    ("0x004B9670", "Set_Global_0066619C_Then_Rebuild", "STATE_SET", "MEDIUM",
     "DAT_0066619C = param_1；再调 FUN_00404830()"),
    ("0x004BA200", "Prep_Then_VirtualCall_Sub3A8_Slot10", "VIRTUAL_CALL", "MEDIUM",
     "FUN_004B2F10(param_2..4) 后 (**(code **)(**(int **)(param_1+0x3A8)+0x28))(param_1-0x10,…)"),
    ("0x00501090", "Query_Slot17_Then_FlagCheck", "VIRTUAL_CALL", "MEDIUM",
     "(**(code **)(*param_1+0x44))() 非 0 后取 FUN_00501130() 的低字节判真"),
    ("0x005063D0", "Call_0050B62D_Return_Identity", "PASSTHROUGH", "MEDIUM",
     "iVar1 = FUN_0050B62D()；return (iVar1*1000)/1000（整数恒等 ⇒ 语义为原样返回被调结果）"),
    ("0x0050C600", "EnterCriticalSection_Or_Call_0050DD18", "SYNC", "HIGH",
     "param_1<0x14 → FUN_0050DD18(param_1+0x1C)；否则 EnterCriticalSection((LPCRITICAL_SECTION)(param_2+0x20))"),
    ("0x005157F8", "D3DX_Thunk_Slot_005CD954", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd954"),
    ("0x005158D1", "D3DX_Thunk_Slot_005CD958", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd958"),
    ("0x00515A55", "D3DX_Thunk_Slot_005CD960", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd960"),
    ("0x00515B50", "D3DX_Thunk_Slot_005CD964", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd964"),
    ("0x00515F21", "D3DX_Thunk_Slot_005CD96C", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd96c"),
    ("0x0051603E", "D3DX_Thunk_Slot_005CD970", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd970"),
    ("0x00516B13", "D3DX_Thunk_Slot_005CD91C", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd91c"),
    ("0x00517003", "D3DX_Thunk_Slot_005CD938", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd938"),
    ("0x00517042", "D3DX_Thunk_Slot_005CD93C", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd93c"),
    ("0x005178CC", "D3DX_Thunk_Slot_005CD924", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd924"),
    ("0x005179D9", "D3DX_Thunk_Slot_005CD944", "D3DX_DISPATCH", "MEDIUM", D3 % "005cd944"),
    ("0x0052BC60", "Set_Param_600_603_Else_Error_509", "PARAM_SET", "MEDIUM",
     "0x600<param_1<0x603 → *(uint *)(&DAT_007DCBA4 + DAT_00723260*0x5C)=param_1，返回拼接 1；"
     "否则 FUN_00530D00(0x509) 取错码"),
    ("0x0052BCA0", "Get_Param_665_Or_668_Else_Error_504", "PARAM_GET", "MEDIUM",
     "param_1==0x665 → DAT_007DCB88；==0x668 → DAT_007DCB8C；否则 FUN_00530D00(0x504) 后返回 0"),
    ("0x005312A0", "Register_7_Labels_via_00531300", "TABLE_REGISTER", "MEDIUM",
     "FUN_00531300(&LAB_00531120, &LAB_00531250, &LAB_00531140, &LAB_00531180, "
     "&LAB_005311E0, &LAB_00531200, &LAB_00531220)"),
    ("0x005312D0", "Register_6_Labels_via_00531350", "TABLE_REGISTER", "MEDIUM",
     "FUN_00531350(&LAB_00531230, &LAB_00531250, &LAB_00531260, "
     "&LAB_00531200, &LAB_00531220, &LAB_00531280)"),
    ("0x00554710", "Socket_Bind_Wrapper", "SOCKET", "HIGH",
     "FUN_00554760(param_2,&local_10) 填 sockaddr 后 bind(*param_1,&local_10,0x10)；"
     "*param_1==0xffffffff 时返回 false"),
    ("0x00559080", "Pack_3Bytes_Then_Call_00579530", "PACK_FORWARD", "MEDIUM",
     "FUN_00579530(((param_3<<8 | param_2)<<8) | (param_1 & 0xff), 0)"),
    ("0x0055BC50", "Forward_0047DCF0_With_AlphaFF", "FORWARD", "MEDIUM",
     "FUN_0047DCF0(param_1, param_2, param_3, 0xff)"),
]


def main():
    # 队列：SINGLE_CALL_FORWARD ∪ CTOR_VTABLE_WRITE
    expect, cls_of = set(), {}
    with open(REAUDIT, errors="replace") as f:
        for i, line in enumerate(f):
            if i == 0:
                continue
            c = line.rstrip("\n").split("\t")
            if len(c) >= 3:
                cls_of[c[0]] = c[2]
                if c[2] in ("SINGLE_CALL_FORWARD", "CTOR_VTABLE_WRITE"):
                    expect.add(c[0].upper().replace("0X", "0x"))

    got = {a for a, *_ in T}
    missing, extra = sorted(expect - got), sorted(got - expect)
    if missing or extra:
        print("!! 集合不等：队列缺 %d 项、决策表多 %d 项" % (len(missing), len(extra)))
        for a in missing:
            print("   队列有而决策表无:", a)
        for a in extra:
            print("   决策表有而队列无:", a, "(当前类别=%s)" % cls_of.get(a, "?"))
        sys.exit(1)
    print("集合断言通过：31 项双向差为空（29 SINGLE_CALL_FORWARD + 2 CTOR_VTABLE_WRITE）")

    with open(OUT, "w", errors="replace") as f:
        f.write("Addr\tOldLabel\tReauditClass\tNewName\tFamily\tConfidence\tEvidence\n")
        for a, name, fam, conf, ev in T:
            f.write("%s\tInline_Getter_Setter\t%s\t%s\t%s\t%s\t%s\n"
                    % (a, cls_of.get(a, "?"), name, fam, conf, ev))

    conf, fam = {}, {}
    for _, _, f_, c_, _ in T:
        fam[f_] = fam.get(f_, 0) + 1
        conf[c_] = conf.get(c_, 0) + 1
    print("-" * 62)
    for k, v in sorted(fam.items(), key=lambda x: -x[1]):
        print("  %-18s %3d" % (k, v))
    print("-" * 62)
    print("  置信: HIGH=%d  MEDIUM=%d  UNRESOLVED=%d"
          % (conf.get("HIGH", 0), conf.get("MEDIUM", 0), conf.get("UNRESOLVED", 0)))
    print("输出: %s" % OUT)


if __name__ == "__main__":
    main()
