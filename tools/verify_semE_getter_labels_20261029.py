#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""对账任务 #19：E 段 Inline_Getter_Setter 标签批量再判读。

判据：evidence/semE_pseudo/<addr>.c（Ghidra 伪码，被测二进制的直接产物）。
规则全部落到伪码可观察事实上（是否写虚表指针、是否调库函数、具名调用个数），
不依赖任何先前台账的标签结论。分类无法落定时一律降级为 UNRESOLVED，不猜。

输出：evidence/semE_getter_reaudit_20261029.tsv
"""
import os
import re
import glob
import collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
E_TSV = os.path.join(ROOT, "evidence", "semE_cluster*_table.tsv")
PSEUDO = os.path.join(ROOT, "evidence", "semE_pseudo")
OUT = os.path.join(ROOT, "evidence", "semE_getter_reaudit_20261029.tsv")

VTABLE_WRITE = re.compile(r"\*\s*param_\d+\s*=\s*&PTR_FUN_0")
LIBCALL = re.compile(r"\b(_strncpy|_strcpy|_strcat|_memcpy|_memset|_malloc|_free|_sprintf|_strlen)\s*\(")
CALL = re.compile(r"\bFUN_00[0-9a-f]{6}\s*\(")
# 成员访问：Ghidra 伪码常见形态 param_1[3] / *(type *)(param_1 + 0x10) / ((int)param_1 + 4)
MEMBER_ACCESS = re.compile(
    r"param_\d+\s*\["
    r"|\*\s*\(\s*\w+[\w ]*\*\s*\)\s*\(\s*\(?\s*(?:int\s*)?param_\d+"
    r"|\(\s*\(\s*int\s*\)\s*param_\d+\s*[-+]"
)
RETURN_MEMBER = re.compile(r"return\s+[^;]*param_\d+")
# 仅匹配 Ghidra 明确的间接调用形态 (*(code *)...)( 或 (*(...))(
INDIRECT_CALL = re.compile(r"\(\*\s*(?:code\s*\*+)|\[\*\s*\(\s*code")
LOOP = re.compile(r"\bdo\s*\{|\bwhile\s*\(|\bfor\s*\(")


def body_only(text):
    """剥掉函数签名，只留函数体——否则签名里的 FUN_00xxxxxx( 会被当成一次自调用。"""
    i = text.find("{")
    return text[i:] if i >= 0 else text


def read_pseudo(addr):
    name = addr.lower().replace("0x", "") + ".c"
    p = os.path.join(PSEUDO, name)
    if not os.path.isfile(p):
        return None
    with open(p, "r", errors="replace") as f:
        return f.read()


def classify(raw, self_addr=None):
    """返回 (新分类, 证据串)。"""
    if raw is None:
        return "NO_PSEUDO", ""
    body = body_only(raw)
    calls = {c for c in CALL.findall(body)}
    if self_addr:
        own = self_addr.lower().replace("0x", "")
        calls = {c for c in calls if not c.lower().startswith("fun_" + own)}
    n_calls = len(calls)
    vt = VTABLE_WRITE.search(body)
    lib = LIBCALL.search(body)
    stmts = [l for l in body.splitlines()
             if l.strip() and not l.strip().startswith(("}", "{")) and not l.strip().startswith("undefined")]
    n_stmt = len(stmts)
    indirect = len(INDIRECT_CALL.findall(body))

    loop = LOOP.search(body)

    if vt:
        ev = "vtable write: %s" % vt.group(0).strip()
        return "CTOR_VTABLE_WRITE", ev
    if lib:
        ev = "lib call: %s" % lib.group(1)
        if loop:
            ev += "; loop body"
        return "LIB_STRING_OR_MEM_HELPER", ev
    if loop:
        # 含循环体即不可能是"单行内联访问器"；典型为内联 memcpy/遍历/链表操作
        return "LOOP_BODY_NOT_ACCESSOR", "loop: %s" % loop.group(0).strip()
    if n_calls >= 2:
        ev = "%d named calls: %s" % (n_calls, ",".join(sorted(calls)[:3]))
        return "MULTI_CALL_HELPER", ev
    if n_calls == 1:
        ev = "1 named call: %s" % sorted(calls)[0]
        # 单调用 + 立刻返回 = 转发壳；单调用 + 成员访问 = 带副作用的包装
        if RETURN_MEMBER.search(body) or MEMBER_ACCESS.search(body):
            ev += "; member access"
            return "CALL_WITH_MEMBER_ACCESS", ev
        return "SINGLE_CALL_FORWARD", ev
    if n_calls == 0:
        if indirect:
            return "INDIRECT_CALL_DISPATCH", "%d indirect call sites" % indirect
        if RETURN_MEMBER.search(body) and n_stmt <= 3:
            return "ACCESSOR_OR_PREDICATE_CANDIDATE", "0 calls, %d stmts, returns member/global" % n_stmt
        if MEMBER_ACCESS.search(body) and n_stmt <= 3:
            return "ACCESSOR_OR_PREDICATE_CANDIDATE", "0 calls, %d stmts, member access" % n_stmt
        if n_stmt <= 3:
            return "SMALL_ARITH_OR_PREDICATE", "0 calls, %d stmts" % n_stmt
        return "UNRESOLVED", "0 calls, %d stmts" % n_stmt
    return "UNRESOLVED", ""


def main():
    addrs = []
    for tsv in sorted(glob.glob(E_TSV)):
        with open(tsv, "r", errors="replace") as f:
            for i, line in enumerate(f):
                if i == 0:
                    continue
                cols = line.rstrip("\n").split("\t")
                if len(cols) >= 2 and cols[1] == "Inline_Getter_Setter":
                    addrs.append(cols[0])
    addrs = sorted(set(addrs))

    rows = []
    stat = collections.Counter()
    for a in addrs:
        body = read_pseudo(a)
        cls, ev = classify(body, a)
        stat[cls] += 1
        rows.append((a, cls, ev))

    with open(OUT, "w", errors="replace") as f:
        f.write("Addr\tOldLabel\tReauditClass\tEvidence\n")
        for a, cls, ev in rows:
            f.write("%s\tInline_Getter_Setter\t%s\t%s\n" % (a, cls, ev))

    print("E 段 Inline_Getter_Setter 标签再判读 —— 共 %d 项" % len(addrs))
    print("-" * 58)
    for cls, n in stat.most_common():
        print("%-28s %5d  (%5.1f%%)" % (cls, n, 100.0 * n / len(addrs)))
    print("-" * 58)
    hold = stat["ACCESSOR_OR_PREDICATE_CANDIDATE"]
    print("标签成立(纯访问器)         %5d  (%5.1f%%)" % (hold, 100.0 * hold / len(addrs)))
    print("标签不成立(需改名/降级)    %5d  (%5.1f%%)" % (len(addrs) - hold, 100.0 * (len(addrs) - hold) / len(addrs)))
    print("输出: %s" % OUT)


if __name__ == "__main__":
    main()
