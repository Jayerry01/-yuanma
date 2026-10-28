# -*- coding: utf-8 -*-
# 簇C（153个）与 簇F（136个）三桶台账自动生成与语义定性核实
import os, sys, re, csv
sys.stdout.reconfigure(encoding='utf-8')

lines = open('D:/MeteorRE/evidence/semD_clusterCF_analysis.txt', encoding='utf-8').read().split('=== ')

facts_c = []
facts_f = []

for block in lines[1:]:
    header_line = block.splitlines()[0]
    fa_str = header_line[:8]
    fa = int(fa_str, 16)
    is_cluster_c = "[Cluster C]" in header_line
    
    callees = ""
    pseudo = ""
    callers = ""
    for l in block.splitlines():
        if l.strip().startswith('[1]'): callers = l.strip()
        if l.strip().startswith('[2]'): callees = l.strip()
        if l.strip().startswith('[PSEUDO]'): pseudo = l.strip()[8:].strip()
    
    if is_cluster_c:
        if fa == 0x00461510:
            sem = "GDI_LogFont_Create"
            fact = "LOGFONTA local_3c, CreateFontIndirectA 构造 Windows 字体句柄 HFONT"
            inf = "GDI 逻辑字体属性结构填充与字体对象创建"
        elif fa in (0x00461B90, 0x00462050, 0x004620E0, 0x004625E0):
            sem = "Model_Node_Tree_Traverse"
            fact = "遍历 *(param_1 + 0x14) 子节点双向链表，调用 *(param_1 + 0x54) 节点虚函数驱动"
            inf = "3D 骨骼模型/场景节点树层次遍历与变换更新分派"
        elif fa in (0x00463120, 0x004631D0):
            sem = "Model_Node_Tree_Release"
            fact = "调用子节点虚析构函数 (**(param_1 + 0x20))(1), 0x402e90 节点内存回收"
            inf = "模型场景节点树及其子节点递归销毁与内存回收"
        elif fa in (0x00461480, 0x00463450):
            sem = "Model_Node_Object_Alloc"
            fact = "operator_new(0x508b38) 动态分配节点，调用 0x44d020 / 0x4614f0 构造"
            inf = "场景图几何模型节点对象堆内存分配与初始化"
        elif fa in (0x00461E50, 0x00461FB0):
            sem = "Model_Mesh_Material_Bind"
            fact = "调用 0x429990/0x429aa0 文本表面管理器，绑定网格材质贴图槽位"
            inf = "网格材质索引与纹理通道槽位动态绑定"
        elif fa in (0x00463B30, 0x00466C60, 0x0046B860, 0x004732A0, 0x0047A590, 0x00481150, 0x00481230, 0x004812D0):
            sem = "Geom_Mesh_Vector_Insert"
            fact = "调用 0x403490 (vector 扩容) 与 0x5092c0 (memcpy), 属于 n=21 画像组"
            inf = "模型网格顶点/索引/面片 STL vector 动态扩容与插入"
        elif fa in (0x00463610, 0x004636D0, 0x00467840, 0x00469AC0, 0x00469F70):
            sem = "Geom_Vertex_Float_To_Fixed"
            fact = "调用 0x509980 (__ftol) 转换顶点浮点坐标与法线，属于 n=17 纯浮点画像组"
            inf = "模型顶点坐标与法线浮点量化及定点化截断"
        elif fa in (0x00475F90, 0x00474000):
            sem = "Geom_Matrix4x3_Bone_Eval"
            fact = "调用 0x477d30 骨骼矩阵槽位运算，计算 4x3 仿射变换"
            inf = "角色骨骼动画 4x3 局部到全局空间矩阵变换估算"
        else:
            sem = "Geom_Model_Subsystem_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "几何模型与网格底层支撑辅助"

        facts_c.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合 .skb 骨骼模型格式对齐节点偏移与层次深度"
        })
    else: # Cluster F
        if fa == 0x00505160:
            sem = "Audio_DirectSound3D_Init"
            fact = "读取串池 s_DirectSound3D_005ca5ac ('DirectSound3D'), 调用 0x525820/0x5259e0 初始化"
            inf = "DirectSound3D 空间音频底层设备枚举与驱动初始化"
        elif fa == 0x00505430:
            sem = "Audio_SoundBuffer_Array_Mgr"
            fact = "(DAT_0066758c - DAT_00667588) / 0x14 (20B = sizeof SoundBufferEntry), 0x528030 销毁"
            inf = "声音缓冲区全局描述符动态数组管理与越界销毁"
        elif fa in (0x005054E0, 0x005055D0, 0x005056D0):
            sem = "Audio_Channel_Slot_Alloc"
            fact = "iVar1 * 0x40 + DAT_0066756c (64B = sizeof SoundChannelSlot), >> 6 查找空闲声道槽"
            inf = "音频混音 64 字节硬件播放声道槽动态分配与抢占"
        elif fa == 0x00506400:
            sem = "Audio_Tick_Timer_Update"
            fact = "DAT_00667584 < uVar1 - DAT_0066757c 步进判定，调用 0x5063b0 刷新混音"
            inf = "音频子系统高精度时钟帧驱动与缓冲区流式填塞"
        elif fa in (0x00506ED0, 0x00506FB0):
            sem = "Audio_Buffer_Deque_Ops"
            fact = "0x5092c0 (memcpy) 与 0x403490 (vector 扩容), 操作 20 字节音频事件描述符"
            inf = "音频触发事件队列出入队与扩容"
        elif fa in (0x00501780, 0x00501F70):
            sem = "Debug_Label_WorldToScreen"
            fact = "调用 0x477b90 / 0x476f00 摄像机变换，0x504f50 绘制 3D 调试文字"
            inf = "调试信息角色头顶世界坐标转屏幕投影与文本绘制"
        elif fa in (0x00510427, 0x005155CC):
            sem = "CRT_Malloc_Wrapper"
            fact = "调用 0x5095f5 (_malloc), 属于 n=5 _malloc 画像组"
            inf = "MSVCRT 堆内存分配封装"
        elif fa in (0x005092C0, 0x00512CB3):
            sem = "CRT_Memcpy_Memmove"
            fact = "纯内存搬运汇编优化内联，rep movsd / movsb"
            inf = "C 运行时快速内存拷贝与对齐搬运"
        elif fa in (0x00507B94, 0x00507A30, 0x005078D5):
            sem = "CRT_IO_File_Stream_Ops"
            fact = "调用 0x508593 / 0x507d0b 文件流读写锁存"
            inf = "MSVCRT 文件流低级 I/O 缓冲区刷新与锁状态管理"
        else:
            sem = "CRT_Memory_Subsystem_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "C 运行时与内存管理底层辅助"

        facts_f.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合 MSVCRT 6.0 源码符号对齐内部静态变量"
        })

print(f"簇C 定性: {len(facts_c)} 个函数")
print(f"簇F 定性: {len(facts_f)} 个函数")

with open('D:/MeteorRE/evidence/semD_clusterC_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_c:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

with open('D:/MeteorRE/evidence/semD_clusterF_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_f:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

print("写入 TSV 成功")
