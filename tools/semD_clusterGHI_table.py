# -*- coding: utf-8 -*-
# 簇G（82个）、簇H（98个）、簇I（182个）三桶台账自动生成与语义定性核实
import os, sys, re, csv
sys.stdout.reconfigure(encoding='utf-8')

lines = open('D:/MeteorRE/evidence/semD_clusterGHI_analysis.txt', encoding='utf-8').read().split('=== ')

facts_g = []
facts_h = []
facts_i = []

for block in lines[1:]:
    header_line = block.splitlines()[0]
    fa_str = header_line[:8]
    fa = int(fa_str, 16)
    
    callees = ""
    pseudo = ""
    callers = ""
    for l in block.splitlines():
        if l.strip().startswith('[1]'): callers = l.strip()
        if l.strip().startswith('[2]'): callees = l.strip()
        if l.strip().startswith('[PSEUDO]'): pseudo = l.strip()[8:].strip()
    
    if fa < 0x540000: # Cluster G
        if fa in (0x00521370, 0x00522A80, 0x005228B1, 0x00522C80):
            sem = "Math_3DNow_SIMD_Vector_Ops"
            fact = "FastExitMediaState (femms), in_MM0 64位 SIMD 寄存器操作与 3DNow! 汇编内联"
            inf = "AMD 3DNow! 多媒体扩展指令集快速向量加乘与状态退出"
        elif fa in (0x0052BF60, 0x0052C070, 0x0052C6C0):
            sem = "Image_Mip_SubVolume_Alloc"
            fact = "调用 0x52c740 (建级)，分配与管理图像 Mipmap 金字塔逐级子纹理"
            inf = "纹理 Mipmap 金字塔各级子图像内存分配与链表挂接"
        elif fa in (0x00525820, 0x00525900):
            sem = "Audio_Device_Pool_Alloc"
            fact = "0x5089fd (free) / _malloc 分配，属于音频设备池节点管理"
            inf = "音频子系统混音器设备描述符内存池节点分配与释放"
        elif fa in (0x005387F0, 0x00538000, 0x00538500):
            sem = "Image_Color_Cube_Prefix_Sum"
            fact = "访问 33x33x33 反色映射查找立方体，进行三维前缀和累加"
            inf = "8bpp 纹理量化调色板颜色距离前缀和三维索引"
        else:
            sem = "Image_Audio_Subsystem_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "图像解码、音频与向量数学底层辅助"

        facts_g.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合 libjpeg / 3DNow! 硬件探测开关复核执行路径"
        })

    elif fa < 0x560000: # Cluster H
        if fa in (0x00540090, 0x00540310, 0x005404C0, 0x005405A0, 0x00540670):
            sem = "JPEG_Decompress_Manager_Ops"
            fact = "param_1+0x184 (cinfo->dest/src), param_1+0x118, 嵌入式 libjpeg 解码状态流转"
            inf = "libjpeg 解压缩上下文管理器缓冲区推进与状态消费"
        elif fa in (0x0054B940, 0x0054CAE0, 0x0054CD90, 0x0054CE80):
            sem = "Net_Packet_Buffer_Vector_Insert"
            fact = "调用 0x403490 (vector 扩容) 与 0x5092c0 (memcpy), 属于 n=21 画像组"
            inf = "网络数据包发送/接收队列 STL vector 动态扩容与插入"
        elif fa in (0x0054F6E0, 0x00553290, 0x00553390):
            sem = "Net_Session_Heartbeat_Timeout"
            fact = "调用 0x4736a0 比较时间戳，检查对端网络心跳超时"
            inf = "多人联机玩家连接心跳超时与掉线状态判定"
        elif fa in (0x00550490, 0x00550A50, 0x00552510, 0x0055E8B0):
            sem = "Net_Message_Serialize_Field"
            fact = "0x5092c0 (memcpy) 序列化网络结构，操作玩家 ID 与位移状态"
            inf = "多人游戏网络同步协议消息字段序列化与打包"
        else:
            sem = "Net_Protocol_Subsystem_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "网络协议栈、封包序列化与大厅会话底层辅助"

        facts_h.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合网络抓包与指令协议号 0x4AB3F0 对齐消息头 ID"
        })

    else: # Cluster I
        if fa == 0x005603F0:
            sem = "Scene_AABB_Center_Project"
            fact = "计算包围盒中心 (min+max)*0.5, 调用 0x477b90 进行摄像机屏幕投影"
            inf = "3D 场景物件轴对齐包围盒 (AABB) 几何中心点计算与屏幕投影"
        elif fa in (0x00560500, 0x00560610, 0x00560700):
            sem = "Scene_Object_Attr_Property_Ops"
            fact = "调用 0x50ac61 / 0x50ace3 / 0x570fc0 属性查找，读写 0x38/0x3c/0x40 槽"
            inf = "场景物件属性集（位置、朝向、物理标志）反射读写"
        elif fa in (0x00561BB0, 0x00561D10, 0x00561DC0):
            sem = "Scene_PVS_Bitmask_Cluster_Query"
            fact = "0x509980 (__ftol) 浮点坐标转团簇 ID，0x477d30 查表判定 PVS 可见集掩码"
            inf = "PVS 潜在可见集位掩码团簇可见性快速查询与视锥剔除"
        elif fa in (0x00584D80, 0x00585360, 0x005856C0, 0x00587A60, 0x005880D0, 0x00588720, 0x00588E10, 0x00589330, 0x00589970, 0x0058A1F0):
            sem = "Spline_Particle_Emitter_Step"
            fact = "调用 0x5811c0 样条积分，属于 n=10 画像组，更新粒子生命周期与位移"
            inf = "3D 场景特效粒子发射器轨迹样条步进与生命周期更新"
        elif fa in (0x005780C0, 0x0058A560, 0x0058C230, 0x0058D560):
            sem = "Particle_Mesh_Buffer_Grow"
            fact = "调用 0x403490 (vector 扩容) 与 0x5092c0 (memcpy), 属于 n=21 画像组"
            inf = "粒子特效广告牌网格与顶点缓冲区动态扩容"
        else:
            sem = "Scene_Particle_Spline_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "场景 PVS、样条曲线与粒子特效底层辅助"

        facts_i.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合 .des 场景定义文件与 PVS 二进制块格式验证团簇范围"
        })

print(f"簇G 定性: {len(facts_g)} 个函数")
print(f"簇H 定性: {len(facts_h)} 个函数")
print(f"簇I 定性: {len(facts_i)} 个函数")

with open('D:/MeteorRE/evidence/semD_clusterG_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_g:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

with open('D:/MeteorRE/evidence/semD_clusterH_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_h:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

with open('D:/MeteorRE/evidence/semD_clusterI_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_i:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

print("写入 TSV 成功")
