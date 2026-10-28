# -*- coding: utf-8 -*-
import sys, re
sys.stdout.reconfigure(encoding='utf-8')

PATH = 'D:/MeteorRE/INVESTIGATION.md'
text = open(PATH, 'r', encoding='utf-8').read()

# 1. 更新硬口径统计
old_stat = """   硬口径：已命名 4,701/11,140 = **42.20%**（按引用语料判据；2026-10-28 批次C 后重算）；
   ≥33B 非平凡未命名 **1,928 个 / 209,677 B**（D+E 两段；F 段 ≤32B 53,614 B 不计入，
   旧数 485,096 B 系误把 F 计入已修正）。批次：~~A = U6 残差语义化 179 洞~~ ✅ **已完成**
   （2026-10-28，§二.23：三桶台账 `evidence/u6_semA_20261028.txt`，跳转表 29 +
   DirectInput DIDATAFORMAT + EH thunk 定性细化 + C3 通道误报修正）→
   ~~B(>1KB,36)~~ ✅ **已完成**（2026-10-28，§二.24：三桶台账 `evidence/u6_semB_20261028.txt`，
   渲染提交族 6 兄弟 + 光栅化 10 函数矩阵 + 连招表三胞胎 + menu.res 加载器；
   semqueue B 段 UNNAMED 清零）→ ~~C(301-1000B,331)~~ ✅ **已完成**（2026-10-28，§二.25：
   三桶台账 `evidence/u6_semC_20261028.txt`，嵌入 libjpeg + jquant2 + 33³ 反色立方体 +
   AI/网络栈 + CRT 24 标准名 + STL 模板大账；C 段 UNNAMED 清零）→
   D(101-300B,825) → E(33-100B,1103) → F(<=32B,4511 批量签名分类)。"""

new_stat = """   硬口径：已命名 5,526/11,140 = **49.61%**（按引用语料判据；2026-10-28 批次D 后重算）；
   ≥33B 非平凡未命名 **1,103 个 / 66,217 B**（仅剩 E 段；F 段 ≤32B 53,614 B 不计入）。
   批次：~~A = U6 残差语义化 179 洞~~ ✅ **已完成**（2026-10-28，§二.23：三桶台账 `evidence/u6_semA_20261028.txt`）→
   ~~B(>1KB,36)~~ ✅ **已完成**（2026-10-28，§二.24：三桶台账 `evidence/u6_semB_20261028.txt`）→
   ~~C(301-1000B,331)~~ ✅ **已完成**（2026-10-28，§二.25：三桶台账 `evidence/u6_semC_20261028.txt`）→
   ~~D(101-300B,825)~~ ✅ **已完成**（2026-10-28，§二.26：三桶总账 `evidence/u6_semD_20261028.txt`，
   9大子系统分簇台账，semqueue D 段 UNNAMED 清零）→
   **E(33-100B,1103)** ← 下一步攻坚目标 → F(<=32B,4511 批量签名分类)。"""

assert old_stat in text, "未找到 old_stat 匹配"
text = text.replace(old_stat, new_stat)

# 2. 插入 §二.26
sec26 = """
26. **批次D：101-300B 未命名函数 825 个全定性（2026-10-28，`evidence/u6_semD_20261028.txt`）**：
    143,460 B，801 份伪码 + 24 份 Capstone 汇编补读，由 9 大子系统簇（A 渲染59/B UI36/C 几何153/D 物理40/E 脚本39/F CRT136/G 图像82/H 网络98/I 场景182）分三波全量判读落地。
    核心要点：① **渲染与 DirectDraw 表面**：DDSURFACEDESC2 124B 结构初始化（`0x41B090` 族）、纯软光栅扫描线斜率四重奏（`0x428920` 族，微分 dx/dy, dz/dy）、16bpp RGB565/555 像素打包、Sutherland-Hodgman 视锥半空间裁剪（`0x41A040`）；
    ② **UI 与文字渲染**：Windows GDI 字形轮廓度量（`0x434E00`，MAT2 与 GLYPHMETRICS）、WinMM 底层混音器调节（`0x4327B0`，MIXERLINE/CONTROL）、3D 向量叉积与法线归一化（`0x430E80/F30`）、"server.cfg" 服务器配置读取（`0x45A770`）；
    ③ **物理与战斗控制**：控制台指令解析前缀（`0x4A1540`，串池 "Command "）、角色阴影贴花生成（`0x4A81C0`，"shadow1"）、三级伤害与受击部位掩码分派（`0x4A7E80`，0xF/0xF0/0xF00）、SAT 碰撞对动态分配、飞行道具抛物线轨迹步进；
    ④ **脚本 VM 与 AI 决策**：PScript VM 栈帧出入栈调度（`0x4E6050` 族）、STL vector 12B（Vector3）路点列表内存后移、AI 寻路路径点序列遍历与启发式估算、AI 动作槽回调分派（`0x4ED6E0`）；
    ⑤ **3D 骨骼模型与场景图**：场景与骨骼节点树双向链表层次遍历与驱动（`0x4620E0` 等，调用 49 次）、节点递归虚析构与内存回收、网格材质索引与文本表面动态绑定；
    ⑥ **音频系统与 DirectSound3D**：DirectSound3D 空间音频初始化（`0x505160`，"DirectSound3D"）、64 字节硬件混音声道槽动态分配与抢占（`0x5054E0` 族）、20 字节声音全局缓冲区数组管理、音频帧驱动高精度定时器；
    ⑦ **多媒体与 3DNow! SIMD**：AMD 3DNow! 多媒体扩展指令集（`femms` 快速退出与 64 位寄存器运算）、Mipmap 金字塔逐级子纹理分配、33³ 颜色前缀和立方体索引；
    ⑧ **网络栈与场景粒子**：嵌入式 libjpeg 解码状态流转（`0x540090` 族）、网络心跳超时与掉线判定、网络同步协议消息字段序列化、场景 AABB 包围盒中心计算与屏幕投影（`0x5603F0`）、PVS 可见集位掩码团簇查询（`0x561BB0` 族）、粒子特效样条发射器步进（`0x584D80` 族，n=10 画像组）。
    semqueue D 段 UNNAMED 完全清零。"""

pos25 = text.find('    semqueue C 段 UNNAMED 清零。\n')
assert pos25 != -1, "未找到 pos25"
insert_pos = pos25 + len('    semqueue C 段 UNNAMED 清零。\n')
text = text[:insert_pos] + sec26 + text[insert_pos:]

# 3. 更新证据索引
sec_ev = """- **批次D（101-300B 未命名函数语义化）**：`tools/semD_scan_20261028.py` →
  `evidence/semD_dump_20261028.txt`（825 函数五类证据+23 画像组，4,287 行）+
  `evidence/semD_pseudo/`（801 份伪码）+ 9 大子系统分簇台账（`evidence/semD_cluster[A-I]_table.tsv`）→
  三桶总账 **`evidence/u6_semD_20261028.txt`**（§二.26；semqueue 825 行 UNNAMED→NAMED；
  覆盖 143,460 B，D 段未命名完全清零）
"""

pos_ev = text.find('- **批次C（301-1000B 未命名函数语义化）**：')
assert pos_ev != -1, "未找到 pos_ev"
end_ev = text.find('- 控制台派发链：', pos_ev)
text = text[:end_ev] + sec_ev + text[end_ev:]

open(PATH, 'w', encoding='utf-8').write(text)
print("INVESTIGATION.md 更新成功")
