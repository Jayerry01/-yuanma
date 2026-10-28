#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""E 段 91 项 UNRESOLVED 的人工判读落盘（对账任务 #19 后半）。

判据：evidence/semE_pseudo/<addr>.c —— 被测二进制的直接产物，逐条人工阅读后定名。
每条都附伪码中可指认的证据串（库函数名 / 域常量 / 偏移 / 算术形态），可回溯。
无法定名的一律显式降级为 EXPLICIT_UNKNOWN，不猜。

输入：evidence/semE_getter_reaudit_20261029.tsv 中 ReauditClass == UNRESOLVED 的地址
输出：evidence/semE_unresolved_adjudicated_20261029.tsv
"""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "evidence", "semE_getter_reaudit_20261029.tsv")
OUT = os.path.join(ROOT, "evidence", "semE_unresolved_adjudicated_20261029.tsv")
PSEUDO = os.path.join(ROOT, "evidence", "semE_pseudo")

# (addr, 新名, 族, 置信, 证据串) —— 全部来自逐条阅读伪码
M = [
    ("0x00404A10", "List_Node_Push_Tail", "LIST_LINK", "MEDIUM",
     "param_1[1]==0 时首节点；否则 (*(param_1[1]+0x130)=param_2; *(param_2+0x134)=param_1[1]; param_1[1]=param_2; *(param_2+0x130)=0) 双向链接尾插"),
    ("0x00410AB0", "Id_Handle_Lookup_dom01", "HANDLE_TABLE_LOOKUP", "HIGH",
     "(param_1 & 0xff000000)==0x1000000 && (param_1 & 0xffffff)<0x800 -> DAT_007e33c0[idx]"),
    ("0x00410AF0", "Id_Handle_Lookup_dom03", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x03000000, 上界 0x1400, 表 DAT_007e5be0"),
    ("0x00410B30", "Id_Handle_Lookup_dom04", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x04000000, 上界 0x10, 表 DAT_007f0620；param_1==0 回退读 DAT_005d5a0c+0x6c8"),
    ("0x00410B70", "Id_Handle_Lookup_dom06", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x06000000, 上界 0x18, 表 DAT_007eac00"),
    ("0x00410BA0", "Id_Handle_Lookup_dom05", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x05000000, 上界 0x100, 表 DAT_007efde0"),
    ("0x00410BE0", "Id_Handle_Lookup_dom11", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x11000000, 上界 0x100, 表 DAT_007f0200"),
    ("0x00410CE0", "Get_Active_Obj_Id_Flagged", "GLOBAL_QUERY", "MEDIUM",
     "DAT_005d5a0c -> +0x6c8 -> +0x14 -> *puVar1 | 0x2000000；三级空检查"),
    ("0x0041FCC0", "Array2D_Store_Pixel_16or32bpp", "INDEXED_ACCESS", "MEDIUM",
     "DAT_007eabe0==0x10 时写 u16 (stride DAT_007e28b0)，否则写 u32"),
    ("0x00428CF0", "FixedPoint_Interp_Slope_Setup", "FIXED_POINT", "HIGH",
     "DAT_007e2c84 = ((x2-x1)*0x10000)/iVar2；DAT_007e2334 = x1<<0x10；16.16 定点斜率"),
    ("0x0042A010", "Id_Handle_Lookup_dom10", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x10000000, 上界 0x801, 表 DAT_007ddf40；param_1==0 返回 DAT_005d5b04"),
    ("0x0042A550", "Vec3_Compare_Lexicographic", "COMPARE", "HIGH",
     "按 param_6/3/5/2/4/1 三级字典序返回 1/-1/0"),
    ("0x00430650", "Id_Handle_Lookup_dom0A", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x0a000000, 上界 8, 表 DAT_007efdc0"),
    ("0x00430680", "Id_Handle_Lookup_dom0B", "HANDLE_TABLE_LOOKUP", "HIGH",
     "域 0x0b000000, 上界 0x10, 表 DAT_007efd80"),
    ("0x00434EC0", "Mode_Predicate_Via_Callback", "INDIRECT_CALL", "MEDIUM",
     "(*DAT_005e021c)() 间接调用 + param_2/param_1 分支返回 0..3"),
    ("0x00443130", "Sleep_Backoff_By_Level", "LIB_WRAPPER", "HIGH",
     "param_1<0x15 -> Sleep(0)；否则 Sleep(1 << ((param_1-0x14)&0x1f))"),
    ("0x0044F0E0", "Set_4_Consecutive_Fields_2b4", "FIELD_SET", "MEDIUM",
     "写 +0x2b4/+0x2b8/+0x2bc/+0x2c0 四个连续 dword，返回 1"),
    ("0x00478190", "Vec4_MulAdd_Accumulate", "FLOAT_MATH", "HIGH",
     "this+0x30..0x3c += param_2 * this+0x10..0x1c（四分量乘加累加）"),
    ("0x0047ECC0", "Vec3_Distance", "FLOAT_MATH", "HIGH",
     "SQRT(Σ(p2[i]-p1[i])²) 三分量欧氏距离"),
    ("0x0047F260", "Set_4_Consecutive_Fields_a8", "FIELD_SET", "MEDIUM",
     "写 +0xa8/+0xac/+0xb0/+0xb4 四个连续 dword"),
    ("0x00481EE0", "Indexed_U16_Array_Set_Guarded", "INDEXED_ACCESS", "MEDIUM",
     "0<=param_2<this+0x4c 且 this+0xc 非空时写 *(this+0xc + param_2*2)=param_3，返回 1/0"),
    ("0x004835E0", "Virtual_Call_Bool_Eq0_slot94", "VIRTUAL_CALL", "MEDIUM",
     "(**(code**)(*(this+0x36c54)+0x94))(...) == 0"),
    ("0x00483610", "Virtual_Call_Bool_Eq0_slot9C", "VIRTUAL_CALL", "MEDIUM",
     "子对象 this+0x36c54，vtable 槽 0x9c"),
    ("0x00483770", "Virtual_Call_Bool_Eq0_slotC8", "VIRTUAL_CALL", "MEDIUM",
     "vtable 槽 200(0xc8)"),
    ("0x004837A0", "Virtual_Call_Bool_Eq0_slotCC", "VIRTUAL_CALL", "MEDIUM",
     "vtable 槽 0xcc"),
    ("0x004837D0", "Virtual_Call_Bool_Eq0_slotFC", "VIRTUAL_CALL", "MEDIUM",
     "vtable 槽 0xfc，4 参"),
    ("0x00483850", "Virtual_Call_Bool_Eq0_slot118", "VIRTUAL_CALL", "MEDIUM",
     "vtable 槽 0x118，4 参"),
    ("0x00483920", "SetField_Then_VirtualCall_130", "VIRTUAL_CALL", "MEDIUM",
     "写 this+0x367b0=param_2 后调 vtable 槽 0x130"),
    ("0x00483AE0", "Release_SubObject_If_Set", "SUBOBJECT_LIFECYCLE", "MEDIUM",
     "this+0x2c 非空时调其 vtable 槽 2(slot +8) 后置 0，返回 1"),
    ("0x00485810", "Crc32_Update_Byte", "CHECKSUM", "HIGH",
     "uVar1=*param_2; idx=(param_1 ^ (byte)uVar1); *param_2 = DAT_005c8d00[idx] ^ (uVar1>>8) —— 标准 CRC32 表驱动"),
    ("0x00489180", "Virtual_Dispatch_TryElse_3d0", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x3d0 真 -> 槽 0x34c(1) 返回 1；否则槽 0x364 假 -> 槽 0x3d4()"),
    ("0x004A7F00", "Forward_To_SubObj_Virtual_80", "VIRTUAL_CALL", "MEDIUM",
     "转发到 *(this-0x30) 的 vtable 槽 0x80(param_2, param_3!=0, 0x10, 0)"),
    ("0x004B1490", "Virtual_Query_Then_Act_124_e0", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x124(param_2) 真 -> 槽 0xe0(param_2)"),
    ("0x004B1700", "Virtual_Query_Then_Act_124_d8", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x124(param_2) 真 -> 槽 0xd8(param_2)"),
    ("0x004BC280", "Virtual_Id_Translate_Then_Get", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x9c(param_2) 结果 -0x65c 后交槽 0xd0 取值"),
    ("0x004BCF70", "Virtual_Sequence_3Calls_A", "VIRTUAL_CALL", "MEDIUM",
     "子对象 this+0x921 槽 2() -> 槽 0x40(0) -> 槽 200(this+0x8fe)"),
    ("0x004BCFB0", "Virtual_Sequence_3Calls_B", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x3c() -> 槽 0x40(1) -> 槽 0x228(this+0x8fe,1)"),
    ("0x004BD070", "Virtual_Sequence_3Calls_C", "VIRTUAL_CALL", "MEDIUM",
     "槽 0x228(...,0) -> 槽 0x40(1) -> 槽 0x3c()（上一条的逆序）"),
    ("0x004E8B30", "Bind_SubObject_If_Valid", "SUBOBJECT_LIFECYCLE", "MEDIUM",
     "param_2 非空且调其槽 1(param_1) 真 -> this+4 = param_2"),
    ("0x004E8B60", "Unbind_SubObject_If_Valid", "SUBOBJECT_LIFECYCLE", "MEDIUM",
     "this+4 存在且调其槽 2(this) 真 -> this+4 = 0"),
    ("0x004F19E0", "Forward_To_SubObj_Virtual_50", "VIRTUAL_CALL", "MEDIUM",
     "this+0x1a4 子对象槽 0x50(*(param_2+0x850))，返回 1/0"),
    ("0x004F2460", "Indexed_Record_Get_Guarded_48", "INDEXED_ACCESS", "MEDIUM",
     "容器 this+0x134 -> idx<(end-begin)/0x48 -> *(begin+0x28+idx*0x48)"),
    ("0x004FC610", "Plane_Side_Test_Dot", "FLOAT_MATH", "HIGH",
     "(p2-p)*n 三分量点积 > 0 返回 1（平面/朝向判定）"),
    ("0x004FD580", "Reset_Fields_With_Sentinel", "FIELD_RESET", "MEDIUM",
     "清 +0xb0/+0xb4/+0xbc/+0xc0，+0xc4=0xffffffff 哨兵"),
    ("0x004FDD10", "AlignDown_Then_Reset", "FIELD_RESET", "MEDIUM",
     "+0xa8 += ((+0xa8 - +0xa4)>>2)*-4（按 4 对齐收缩）；+0xc4=0xffffffff"),
    ("0x00502E10", "Init_Struct_Defaults_18f", "FIELD_RESET", "MEDIUM",
     "初始化 18 个字段，含 float 常量 0x40a00000(5.0)、0x40400000(3.0)"),
    ("0x005056A0", "Indexed_Record_Ptr_Or_Null_40", "INDEXED_ACCESS", "MEDIUM",
     "idx=param_1-1 < (DAT_00667570-DAT_0066756c)>>6 -> base+idx*0x40；首字节为 0 返回 0"),
    ("0x00508B46", "SEH_Unwind_Thunk", "EXCEPTION", "HIGH",
     "ExceptionList = *(void**)ExceptionList; (*UNRECOVERED_JUMPTABLE)() —— SEH 展开"),
    ("0x0050CADB", "HeapAlloc_Init_Buffer_140", "LIB_WRAPPER", "HIGH",
     "HeapAlloc(DAT_007f1d6c,0,0x140) 后初始化 DAT_007f1d50..68 全局缓冲"),
    ("0x00511043", "Const_Id_Remap_4case", "CONST_MAP", "HIGH",
     "0x3a4->0x411 / 0x3a8->0x804 / 0x3b5->0x412 / 0x3b6->0x404，其余 0"),
    ("0x00514FA8", "Float_Classify_Special", "FLOAT_MATH", "HIGH",
     "0x7ff00000(inf)/0xfff00000(-inf)/指数位 0x7ff8(NaN)/0x7ff0(denormal) 分类返回 0..4"),
    ("0x00515706", "Float_Approx_Equal_1e7", "FLOAT_MATH", "HIGH",
     "|a-b| 与 1.1920929e-07 比较，非 NaN 判定"),
    ("0x00515900", "Vec2_Barycentric_Combine", "FLOAT_MATH", "HIGH",
     "*p1 = (p4-p2)*p6 + (p3-p2)*p5 + p2 两分量线性组合"),
    ("0x00529C00", "Float_To_Int16_Saturate", "FLOAT_MATH", "HIGH",
     "SUB84(x+6.7553994e+15) 后钳位 [-0x8000, 0x7fff] 饱和转换"),
    ("0x00530EB0", "Const_Id_Classify_7case", "CONST_MAP", "HIGH",
     "0x1900/0x1907/0x1908/0x1909/0x190a/0x80e0/0x80e1 -> 1..4，其余 0"),
    ("0x0053A1C0", "Fptr_Call_Pair_1e", "FPTR_CALL", "MEDIUM",
     "(*DAT_007dc850)(param_1,0x1e,1)==1 后 (*DAT_007dc854)(*(param_1+0xe)-0xc,1)"),
    ("0x0053DC70", "Reset_Self_And_SubObj_Fields", "FIELD_RESET", "MEDIUM",
     "清自身 +0x7c/+0xc4/+0x17c，及子对象 +0xc/+0xd/+0x14/+0xa0"),
    ("0x00544370", "Virtual_Emit_With_Counters", "VIRTUAL_CALL", "MEDIUM",
     "this+0x1a0 槽 3(param_2, *p3, param_5+*p6*4)；两个计数器各 +1"),
    ("0x0054F630", "Hash_Indexed_Slot_Get", "INDEXED_ACCESS", "MEDIUM",
     "this+0x2c + ((*p3*3 + (*(u16*)(p2+1) + *(u16*)(p3+1)*2)*2 + *p2) % 0x32)*4"),
    ("0x00553830", "Reset_Fields_With_Sentinel_ff", "FIELD_RESET", "MEDIUM",
     "清 7 个字段，含 +1=0xff 哨兵与 +0x586"),
    ("0x005548D0", "Socket_Send_Wrapper", "SOCKET", "HIGH",
     "send(*param_1,param_2,param_3,0)；WSAGetLastError()==0x2733(WSAEWOULDBLOCK) 时返回 0"),
    ("0x00554920", "Socket_Recv_Wrapper", "SOCKET", "HIGH",
     "recv(...)+ 同上错误码处理"),
    ("0x00554A70", "GetHostName_Wrapper", "SOCKET", "HIGH",
     "gethostname(param_1,param_2) 失败置空串返回 0"),
    ("0x00558B60", "Set_Range_Bounds_By_Threshold", "FIELD_SET", "MEDIUM",
     "param_2<50000 走本地上下界(+0x28)，否则远端(+0x2c+49999)"),
    ("0x00558D40", "Range_Contains_Check", "PREDICATE", "MEDIUM",
     "param_2<50000 判 [0,+0x28)，否则判 [50000,+0x2c+50000)"),
    ("0x0055A2E0", "Indexed_Int_Array_Set_Guarded", "INDEXED_ACCESS", "MEDIUM",
     "0<=p2<3 且 0<=p3<0xd 时 this+0x120+p2*4 = p3，越界写 0"),
    ("0x0055C4F0", "Indexed_Ptr_Get_DualRange_10", "INDEXED_ACCESS", "MEDIUM",
     "本地 idx*0x10+this+0x618；远端 (idx-50000)*0x10+this+0x61c"),
    ("0x0056AEE0", "Indexed_Record_Ptr_54", "INDEXED_ACCESS", "MEDIUM",
     "子表 this+0x120 -> *(sub+0xd4) + idx*0x54，上界 +0xec"),
    ("0x0056AF20", "Indexed_Record_Ptr_24", "INDEXED_ACCESS", "MEDIUM",
     "*(sub+0xd8) + idx*0x24，上界 +0xe4"),
    ("0x0056AF90", "Triple_Flag_All_Set", "PREDICATE", "MEDIUM",
     "sub+0x1d/0x1e/0x1f 三个 char 标志全非零返回 1"),
    ("0x0056B310", "Indexed_Record_Ptr_2b0", "INDEXED_ACCESS", "MEDIUM",
     "*(sub+0x44)+8 + idx*0x2b0，上界 +0x40"),
    ("0x0056D7A0", "Get_Vec3_Fields_1e0", "FIELD_GET", "MEDIUM",
     "拷出 this+0x1e0/0x1e4/0x1e8 三个连续 dword"),
    ("0x0056D7D0", "Get_Vec3_Fields_1ec", "FIELD_GET", "MEDIUM",
     "拷出 this+0x1ec/0x1f0/0x1f4"),
    ("0x00572DB0", "Indexed_Ptr_Get_DualRange_24", "INDEXED_ACCESS", "MEDIUM",
     "本地 this+0x7c + idx*0x24；远端 this+0x80 + (idx*9-450000)*4"),
    ("0x0057DB40", "Timestep_Delta_Update", "FLOAT_MATH", "MEDIUM",
     "delta = param_2 - this+0x168；写 +0x30、半值 +0x3c、+0x164/+0x24 更新时间戳"),
    ("0x0057E4F0", "Get_Vec3_Fields_22c", "FIELD_GET", "MEDIUM",
     "拷出 this+0x22c/0x230/0x234"),
    ("0x0057E520", "Get_Vec3_Fields_220", "FIELD_GET", "MEDIUM",
     "拷出 this+0x220/0x224/0x228"),
    ("0x0057E550", "Indexed_Record_Ptr_1c", "INDEXED_ACCESS", "MEDIUM",
     "*(param_3+0x120) 上界 +8 -> this+0x1a4 + idx*0x1c"),
    ("0x00581D00", "Link_SubObj_Then_Notify", "SUBOBJECT_LIFECYCLE", "MEDIUM",
     "写 this[0x7b]+0x10=param_2，回指 +8=this，再调 vtable 槽 0x38"),
    ("0x00592370", "Virtual_BinOp_NE", "VIRTUAL_BINOP", "HIGH",
     "两操作数の槽 1() 取 +8 后 != 比较，写 this+8"),
    ("0x00592410", "Virtual_BinOp_LE", "VIRTUAL_BINOP", "HIGH", "同上结构，<= 比较"),
    ("0x005924B0", "Virtual_BinOp_LT", "VIRTUAL_BINOP", "HIGH", "同上结构，< 比较"),
    ("0x00592550", "Virtual_BinOp_GE", "VIRTUAL_BINOP", "HIGH", "操作数反向，<= 即 >="),
    ("0x005925F0", "Virtual_BinOp_GT", "VIRTUAL_BINOP", "HIGH", "操作数反向，< 即 >"),
    ("0x00592A00", "Virtual_BinOp_Sub", "VIRTUAL_BINOP", "HIGH", "a - b"),
    ("0x00592BE0", "Virtual_BinOp_Mul", "VIRTUAL_BINOP", "HIGH", "a * b"),
    ("0x00592C70", "Virtual_BinOp_Div", "VIRTUAL_BINOP", "HIGH", "a / b"),
    ("0x00592D00", "Virtual_BinOp_Mod", "VIRTUAL_BINOP", "HIGH", "a % b"),
    ("0x0059377C", "Float_Is_NaN_Or_Inf", "FLOAT_MATH", "HIGH",
     "指数位 0x7ff8(NaN) 或 0x7ff0 且尾数非零(Inf)"),
    ("0x00593D45", "Float_Is_Integer_Stub", "FLOAT_MATH", "HIGH",
     "ROUND(in_ST0)==in_ST0 判定，函数体无副作用（桩）"),
    ("0x005958E5", "Zero_3_Fields_Return_0", "FIELD_RESET", "MEDIUM",
     "*param_1=0; param_1[1]=0; param_1[2]=0; return 0"),
]


def main():
    un = set()
    with open(SRC, errors="replace") as f:
        for i, line in enumerate(f):
            if i == 0:
                continue
            c = line.rstrip("\n").split("\t")
            if len(c) >= 3 and c[2] == "UNRESOLVED":
                un.add(c[0])

    mapped = {a.lower() for a, *_ in M}
    missing = sorted(un - mapped)
    extra = sorted(mapped - un)
    if missing or extra:
        print("!! 地址集不一致：未在映射中的 %d 项，映射中多余的 %d 项" % (len(missing), len(extra)))
        for a in missing[:10]:
            print("   MISSING:", a)
        for a in extra[:10]:
            print("   EXTRA  :", a)

    with open(OUT, "w", errors="replace") as f:
        f.write("Addr\tOldLabel\tNewName\tFamily\tConfidence\tEvidence\n")
        for addr, name, fam, conf, ev in M:
            f.write("%s\tInline_Getter_Setter\t%s\t%s\t%s\t%s\n" % (addr, name, fam, conf, ev))

    fam = {}
    conf = {}
    for _, _, f_, c_, _ in M:
        fam[f_] = fam.get(f_, 0) + 1
        conf[c_] = conf.get(c_, 0) + 1
    print("E 段 UNRESOLVED 人工判读 —— 共 %d 项（UNRESOLVED 集合 %d 项）" % (len(M), len(un)))
    print("-" * 60)
    for k, v in sorted(fam.items(), key=lambda x: -x[1]):
        print("  %-24s %3d" % (k, v))
    print("-" * 60)
    print("  置信: HIGH=%d  MEDIUM=%d" % (conf.get("HIGH", 0), conf.get("MEDIUM", 0)))
    print("  显式降级 UNKNOWN: %d" % len([1 for _, n, *_ in M if n == "EXPLICIT_UNKNOWN"]))
    print("输出: %s" % OUT)


if __name__ == "__main__":
    main()
