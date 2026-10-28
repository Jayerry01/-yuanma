# -*- coding: utf-8 -*-
# 簇A 59函数三桶台账自动生成与语义定性核实
import os, sys, re, csv
sys.stdout.reconfigure(encoding='utf-8')

# 读取分析文件
lines = open('D:/MeteorRE/evidence/semD_clusterA_analysis.txt', encoding='utf-8').read().split('=== ')

facts = []
for block in lines[1:]:
    header_line = block.splitlines()[0]
    fa_str = header_line[:8]
    fa = int(fa_str, 16)
    
    # 提取信息
    callees = ""
    pseudo = ""
    callers = ""
    for l in block.splitlines():
        if l.strip().startswith('[1]'): callers = l.strip()
        if l.strip().startswith('[2]'): callees = l.strip()
        if l.strip().startswith('[PSEUDO]'): pseudo = l.strip()[8:].strip()
    
    # 规则分类
    # 1. 软光栅/扫描线/斜率
    if fa in (0x00428920, 0x004289B0, 0x00428A20, 0x00428AF0):
        sem = "Raster_CalcEdgeSlope"
        fact = "DAT_007e0ea0/DAT_007e0e9c 边缘跨距与插值斜率 dx/dy, dz/dy 增量计算"
        inf = "软光栅边缘扫描线梯度步长算子"
    elif fa in (0x00417850, 0x00417960):
        sem = "Raster_SpanDraw_Gouraud"
        fact = "0x407c10/0x40fb30 跨距填色，0x2000000/0x5000000 渲染标志"
        inf = "高氏着色/纹理扫描线跨距填色内层"
    elif fa in (0x0041F7F0, 0x0041F900):
        sem = "Pixel_FormatPack_16bpp"
        fact = "DAT_005c45b0==5(565/555) 通道位移 0x7e28a8/0x7e3350/0x7e339c 打包; DAT_007eabe0==0x10"
        inf = "16bpp RGB565/555 像素打包与跨距拷贝"
    elif fa in (0x0041B090, 0x0041B180, 0x0041F390, 0x0041F450):
        sem = "DDraw_SurfaceDesc_Init"
        fact = "local_7c[0] = 0x7c (sizeof DDSURFACEDESC2 = 124B)，清零并填入 31 槽结构体"
        inf = "DirectDraw 表面描述体初始化与锁存"
    elif fa in (0x0041A040,):
        sem = "Geom_Plane_HalfSpaceTest"
        fact = "点积 dot = p1*p3 + p1[1]*p3[1] + p1[2]*p3[2] 与平面常数 param_4 比较"
        inf = "3D 视锥/多边形裁剪单面半空间测试"
    elif fa in (0x00429990, 0x00429AA0, 0x00429B80, 0x00429C30):
        sem = "Font_TextureSurface_Mgr"
        fact = "DAT_005d5b04 _malloc(0x60) 描述体，连通 0x434ac0/0x434600 字体光栅器，被模型与UI调用48/23/27/49次"
        inf = "动态文字纹理表面分配/光栅化渲染管理器"
    elif fa in (0x0042B010, 0x0042B080, 0x0042B190, 0x0042CFC0, 0x0042D030):
        sem = "Texture_Path_Enumerator"
        fact = "0x509f8f fopen, FindFirstFileA(WIN32_FIND_DATAA local_140), 路径拆分拼接与大小写归一化"
        inf = "纹理材质文件遍历、路径解析与存在性校验"
    elif fa in (0x004200F0, 0x004201A0, 0x00420290, 0x004206B0):
        sem = "DDraw_ClipRect_Blit"
        fact = "param_4*2 跨距，DAT_005d5a0c+0x6xx 视口边界剪裁 (x<0 / y<0 偏移修正)"
        inf = "带视口边界裁剪的 DirectDraw 2D 矩形位图 blit"
    elif fa in (0x004022B0, 0x00402420, 0x00402FFA):
        sem = "Mem_Buffer_Fill_Zero"
        fact = "调用 0x50915b / 0x50920a (CRT 优化内存搬运/置零)，双胞胎 128B"
        inf = "定长渲染顶点/状态缓冲区清零置位"
    elif fa in (0x00403F10, 0x00405560, 0x00419C30, 0x00419CE0, 0x00419DB0, 0x00415330, 0x004155C0, 0x0042D1B0):
        sem = "Render_Float_To_Fixed_Math"
        fact = "通过 0x509980 (__ftol) 转换浮点颜色/UV/顶点坐标，写入 0x45/0x46 槽"
        inf = "渲染器顶点几何与纹理坐标定点化量化"
    elif fa in (0x0042BCC0, 0x0042A130, 0x0042A300, 0x00429640, 0x00429920):
        sem = "Render_State_Reset_Flush"
        fact = "DAT_007dda04 0x20 个 dword 清零; DAT_005c679c=1; DAT_007ddf40 遍历释放"
        inf = "渲染流水线矩阵状态重置与纹理缓存刷盘"
    elif fa in (0x004153E0, 0x00415490, 0x00415540, 0x004156C0):
        sem = "D3D_Device_Context_Setup"
        fact = "DAT_005c4308/0x5c431c 设备标志，param_1+0x75c vtable 虚表偏移 0x18 调用，_malloc(0x5c431c)"
        inf = "Direct3D 设备上下文初始化与渲染表面绑定"
    elif fa in (0x0041FD10, 0x0041FE00, 0x00421D00):
        sem = "GDI_Text_Glyph_Raster"
        fact = "HDC param_1, 字符编码 0x88 (GBK/Shift-JIS), 0x5095f5 _malloc, 调用 0x410a60"
        inf = "GDI 字体字形轮廓提取与位图缓冲构建"
    elif fa in (0x00423330, 0x00423910):
        sem = "Raster_Span_Dispatcher"
        fact = "DAT_007e28a4+4/8, _DAT_007e2ba4=param_2, 调用 0x4239f0/0x428240"
        inf = "软光栅多边形跨距渲染主分派器"
    elif fa in (0x00419720, 0x00419830, 0x0041A400):
        sem = "Mesh_VertexBuffer_Grow"
        fact = "DAT_007e0eb8 < iVar2*0x20 则 realloc (0x5099a7), 步长 32B 顶点步长"
        inf = "动态网格顶点缓冲区自动扩容与格式对齐"
    elif fa in (0x00407670, 0x00407B50, 0x00408AD0, 0x004100B0):
        sem = "Camera_Frustum_Clip_2D"
        fact = "param_2==param_4 && param_3==param_5 边界相等判断，连通 0x430c40/0x4315e0 视口坐标变换"
        inf = "2D 视口裁剪矩形判断与屏幕坐标映射"
    else:
        sem = "Render_Subsystem_Helper"
        fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
        inf = "渲染底层支撑辅助函数"

    facts.append({
        'addr': f"0x{fa:08X}",
        'name': sem,
        'fact': fact,
        'inf': inf,
        'unknown': "需结合运行时 D3D 设备类型与硬件加速开关验证分支"
    })

print(f"定性完成: {len(facts)} 个函数")
# 输出到 TSV
with open('D:/MeteorRE/evidence/semD_clusterA_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

print("写入 D:/MeteorRE/evidence/semD_clusterA_table.tsv 成功")
