# -*- coding: utf-8 -*-
import sys, re
sys.stdout.reconfigure(encoding='utf-8')

PATH = 'D:/MeteorRE/INVESTIGATION.md'
text = open(PATH, 'r', encoding='utf-8').read()

# 1. 更新硬口径统计
old_stat = """   硬口径：已命名 5,526/11,140 = **49.61%**（按引用语料判据；2026-10-28 批次D 后重算）；
   ≥33B 非平凡未命名 **1,103 个 / 66,217 B**（仅剩 E 段；F 段 ≤32B 53,614 B 不计入）。
   批次：~~A = U6 残差语义化 179 洞~~ ✅ **已完成**（2026-10-28，§二.23：三桶台账 `evidence/u6_semA_20261028.txt`）→
   ~~B(>1KB,36)~~ ✅ **已完成**（2026-10-28，§二.24：三桶台账 `evidence/u6_semB_20261028.txt`）→
   ~~C(301-1000B,331)~~ ✅ **已完成**（2026-10-28，§二.25：三桶台账 `evidence/u6_semC_20261028.txt`）→
   ~~D(101-300B,825)~~ ✅ **已完成**（2026-10-28，§二.26：三桶总账 `evidence/u6_semD_20261028.txt`，
   9大子系统分簇台账，semqueue D 段 UNNAMED 清零）→
   **E(33-100B,1103)** ← 下一步攻坚目标 → F(<=32B,4511 批量签名分类)。"""

new_stat = """   硬口径：已命名 6,629/11,140 = **59.51%**（按引用语料判据；2026-10-28 批次E 后重算）；
   ≥33B 非平凡未命名 **0 个 / 0 B（全部歼灭，非平凡函数实现 100% 全量语义覆盖）**！
   全库剩余仅 F 段 ≤32B 极微型桩（4,511 个，53,614 B，平均仅 11.8B）。
   批次：~~A = U6 残差语义化 179 洞~~ ✅ **已完成**（2026-10-28，§二.23：三桶台账 `evidence/u6_semA_20261028.txt`）→
   ~~B(>1KB,36)~~ ✅ **已完成**（2026-10-28，§二.24：三桶台账 `evidence/u6_semB_20261028.txt`）→
   ~~C(301-1000B,331)~~ ✅ **已完成**（2026-10-28，§二.25：三桶台账 `evidence/u6_semC_20261028.txt`）→
   ~~D(101-300B,825)~~ ✅ **已完成**（2026-10-28，§二.26：三桶总账 `evidence/u6_semD_20261028.txt`）→
   ~~E(33-100B,1103)~~ ✅ **已完成**（2026-10-28，§二.27：三桶总账 `evidence/u6_semE_20261028.txt`，
   E 段 UNNAMED 清零，非平凡函数 100% 覆盖）→ F(<=32B,4511 批量签名分类桩）。"""

assert old_stat in text, "未找到 old_stat 匹配"
text = text.replace(old_stat, new_stat)

# 2. 插入 §二.27
sec27 = """
27. **批次E：33-100B 未命名函数 1,103 个全定性（2026-10-28，`evidence/u6_semE_20261028.txt`）**：
    66,217 B，1,025 份伪码 + 78 份 Capstone 指令补读，由 9 大子系统分簇台账（`evidence/semE_cluster[A-I]_table.tsv`）全量落地。
    核心要点：① **高密同画像组大规模收口**：STL deque_free_node 释放族（`0x402e90`，n=47）、CRT free 包装器（`0x5089fd`，n=12）、C++ 异常展开与越界重抛（`__CxxThrowException@8`，n=11）、MSVCRT __sbh 小堆块桶管理（n=11）、场景状态写入族（`0x5778a0`，n=19）；
    ② **底层硬件与系统服务**：Win32 KERNEL32!LeaveCriticalSection 临界区解锁、WS2_32!#18 (htons/ntohs) 网络端口大端转换、AMD 3DNow! femms 多媒体状态退出；
    ③ **图形与几何微运算**：三维向量叉积与三角形表面法向量归一化、粒子特效样条曲线时间微分积分步进（`0x5811c0` 族）、顶点/时间浮点定点化截断（`__ftol`）；
    ④ **里程碑达成**：`Meteor.exe` 中所有 $\ge 33$ 字节的非平凡未命名函数（B+C+D+E 四个批次合计 2,295 个函数，431,482 字节）已实现 **100% 完整全量定性**！全库剩余仅 F 段 $\le 32$ 字节的极微型桩（4,511 个，平均每函数 11.8 字节，纯虚表跳转/return 0/单个 move）。"""

pos26 = text.find('    semqueue D 段 UNNAMED 完全清零。\n')
assert pos26 != -1, "未找到 pos26"
insert_pos = pos26 + len('    semqueue D 段 UNNAMED 完全清零。\n')
text = text[:insert_pos] + sec27 + text[insert_pos:]

# 3. 更新证据索引
sec_ev = """- **批次E（33-100B 未命名函数语义化）**：`tools/semE_scan_20261028.py` →
  `evidence/semE_dump_20261028.txt`（1,103 函数五类证据+27 画像组，5,752 行）+
  `evidence/semE_pseudo/`（1,025 份伪码）+ 9 大子系统分簇台账（`evidence/semE_cluster[A-I]_table.tsv`）→
  三桶总账 **`evidence/u6_semE_20261028.txt`**（§二.27；semqueue 1,103 行 UNNAMED→NAMED；
  覆盖 66,217 B，E 段未命名清零，实现非平凡函数 100% 语义全覆盖）
"""

pos_ev = text.find('- **批次D（101-300B 未命名函数语义化）**：')
assert pos_ev != -1, "未找到 pos_ev"
end_ev = text.find('- 控制台派发链：', pos_ev)
text = text[:end_ev] + sec_ev + text[end_ev:]

open(PATH, 'w', encoding='utf-8').write(text)
print("INVESTIGATION.md 批次E 更新成功")
