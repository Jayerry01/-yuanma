# -*- coding: utf-8 -*-
"""2026-10-28 复核：.pos 数据实况 vs 二进制 37 词法表 vs 社区 pose 表(1758)/字段表(2207)。

输出全部写入 evidence/verify_pos_20261028_out.txt（UTF-8），控制台只打印摘要。
口径：
  * 文件集 = pmodel/*.POS（Windows 大小写不敏感，先按 realpath 去重）
  * 去 # 注释后按行解析；depth1 = pose 体内顶层键，depth2 = attack/drag/nextpose 等子块键
  * 关键词“是否使用”= 全文正则 \\b词\\b（大小写不敏感），注释也算文本（若注释命中会在输出里点名）
"""
import collections
import glob
import os
import re

PMODEL = r"C:/Program Files (x86)/Meteor/pmodel"
ACT = r"C:/Program Files (x86)/Meteor/Common/character.act"
OUT = os.path.join(os.path.dirname(__file__), "..", "evidence", "verify_pos_20261028_out.txt")

LEX37 = ["action", "attack", "attacktype", "attackvalue", "angertype", "angervalue",
         "blend", "bone", "checkfriend", "color", "defensemove", "defensevalue",
         "defensepose", "drag", "effecttype", "effectid", "end", "hit", "link",
         "loopstart", "loopend", "name", "nextpose", "pose", "start", "source",
         "speed", "time", "targettype", "targetvalue", "targetspeed", "targetpose",
         "targetposefront", "targetposeback", "targetposeright", "targetposeleft",
         "targetmove"]
NESTED_VALUE_KEYS = {"start", "end", "time", "speed", "color"}


def uniq_files(pattern):
    seen, out = set(), []
    for p in sorted(glob.glob(pattern)):
        rp = os.path.normcase(os.path.realpath(p))
        if rp in seen:
            continue
        seen.add(rp)
        out.append(p)
    return out


def parse_pos(path):
    raw = open(path, "rb").read()
    txt = raw.decode("latin-1").replace("\r", "")
    poses = {}
    top = collections.Counter()
    nested = collections.Counter()
    links = {}
    cur = None
    depth = 0
    nocomment = []
    for ln in txt.split("\n"):
        s = ln.split("#")[0].strip()
        if s:
            nocomment.append(s)
        if not s:
            continue
        m = re.match(r"^pose\s+(\d+)$", s, re.I)
        if m and depth == 0:
            cur = int(m.group(1))
            poses.setdefault(cur, [])
            top["pose"] += 1
            continue
        if s == "{":
            depth += 1
            continue
        if s == "}":
            depth -= 1
            if depth == 0:
                cur = None
            continue
        if cur is None:
            continue
        k = s.split()[0].lower()
        if depth == 1:
            poses[cur].append(k)
            top[k] += 1
            if k == "link":
                v = s[len(s.split()[0]):].strip()
                if v.isdigit():
                    links[cur] = int(v)
        elif depth == 2:
            nested[k] += 1
        if depth == 0:
            pass
    return {
        "bytes": len(raw),
        "poses": poses,
        "top": top,
        "nested": nested,
        "links": links,
        "text": "\n".join(nocomment),
    }


def main():
    files = uniq_files(os.path.join(PMODEL, "*.POS"))
    all_top = collections.Counter()
    all_nested = collections.Counter()
    per_file = []
    total_poses = 0
    p0 = None
    for p in files:
        r = parse_pos(p)
        per_file.append((os.path.basename(p), r["bytes"], len(r["poses"])))
        total_poses += len(r["poses"])
        all_top.update(r["top"])
        all_nested.update(r["nested"])
        if os.path.basename(p).upper() == "P0.POS":
            p0 = r

    act_txt = open(ACT, "rb").read().decode("big5", "replace")

    lines = []
    ap = lines.append
    ap("== 文件集（去重后） ==")
    ap(f"pmodel/*.POS 文件数 {len(files)}；pose 块总数 {total_poses}")
    for name, b, n in per_file:
        ap(f"  {name:16s} {b:8d} B  pose={n}")
    ap("")

    ap("== 关键词使用统计（25 个 .POS 合计） ==")
    ap("词\t顶层\t嵌套\t状态")
    for k in LEX37:
        t, n = all_top.get(k, 0), all_nested.get(k, 0)
        state = "used" if (t or n) else "ZERO"
        ap(f"{k}\t{t}\t{n}\t{state}")
    zero = [k for k in LEX37 if not all_top.get(k, 0) and not all_nested.get(k, 0)]
    ap(f"零使用关键词 {len(zero)} 个: {zero}")
    ap("")

    ap("== 零使用关键词全文复核（\\b词\\b, 含注释; 范围 25 .POS + character.act） ==")
    for k in zero:
        hits = []
        for p in files:
            r = open(p, "rb").read().decode("latin-1")
            m = len(re.findall(r"\b" + k + r"\b", r, re.I))
            if m:
                hits.append((os.path.basename(p), m))
        m = len(re.findall(r"\b" + k + r"\b", act_txt, re.I))
        if m:
            hits.append(("character.act", m))
        ap(f"{k}\t{hits if hits else '0 hits'}")
    ap("")

    ap("== P0.POS 概况 ==")
    ap(f"bytes {p0['bytes']}  pose 块 {len(p0['poses'])}  id 范围 {min(p0['poses'])}..{max(p0['poses'])}")
    gaps = [i for i in range(0, max(p0['poses']) + 1) if i not in p0['poses']]
    ap(f"缺号 {len(gaps)}: {gaps}")
    ap(f"顶层键 {dict(sorted(p0['top'].items()))}")
    ap(f"嵌套键 {dict(sorted(p0['nested'].items()))}")
    nosc = sorted(k for k, v in p0["poses"].items() if "source" not in v)
    ap(f"无 source 的 pose 块 {len(nosc)}: {nosc}")
    onlylink = sorted(k for k, v in p0["poses"].items() if v and set(v) <= {"link"})
    ap(f"只含 Link 的 pose 块 {len(onlylink)}: {onlylink[:60]}")
    ap(f"Link 非空 {len(p0['links'])} 条")
    ap("")

    # 社区表 1758 对照
    apex = os.path.join(os.path.dirname(__file__), "..", "evidence", "pose_table_1758_extract.txt")
    tab, tablink = {}, {}
    for ln in open(apex, encoding="utf-8"):
        i, name = ln.rstrip("\n").split("\t", 1)
        i = int(i)
        tab[i] = name
        m = re.match(r"^(\d+)\b", name)
        if m:
            tablink[i] = int(m.group(1))
    ap("== 社区 pose 表(1758) vs P0.POS ==")
    ap(f"1758 行数 {len(tab)}  id {min(tab)}..{max(tab)}; P0 {len(p0['poses'])} 块")
    ap(f"1758 独有 id {sorted(set(tab) - set(p0['poses']))}")
    ap(f"P0 独有 id {sorted(set(p0['poses']) - set(tab))}")
    ap(f"自动衔接(1758) {len(tablink)} 条; Link(P0) {len(p0['links'])} 条")
    both = sorted(set(tablink) & set(p0["links"]))
    agree = [k for k in both if tablink[k] == p0["links"][k]]
    ap(f"交集 {len(both)}，一致 {len(agree)}，不一致 {len(both) - len(agree)}")
    for k in both:
        if tablink[k] != p0["links"][k]:
            ap(f"  DIFF pose {k}: P0.Link={p0['links'][k]}  1758={tablink[k]}")
    ap(f"仅 P0 有 Link（1758 未标）: {sorted(set(p0['links']) - set(tablink))}")
    ap(f"仅 1758 标衔接（P0 无 Link）: {sorted(set(tablink) - set(p0['links']))}")
    ap("")

    # attack 子块 bone 值里的 weapon/effect
    ap("== attack.bone 值中的 weapon/effect（2207 把它们列为参数） ==")
    for p in files:
        r = open(p, "rb").read().decode("latin-1")
        w = len(re.findall(r'"weapon"', r, re.I))
        e = len(re.findall(r'"effect"', r, re.I))
        if w or e:
            ap(f"  {os.path.basename(p):16s} \"weapon\"={w}  \"effect\"={e}")
    ap("  说明：二者只作为 bone 列表的取值出现，不是独立关键字（37 词表中无 weapon/effect）。")

    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    open(OUT, "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print("written", os.path.abspath(OUT))
    print("zero-keywords", zero)
    print("P0 poses", len(p0["poses"]), "links", len(p0["links"]), "1758 rows", len(tab))


if __name__ == "__main__":
    main()
