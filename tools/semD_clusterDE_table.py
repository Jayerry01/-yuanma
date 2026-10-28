# -*- coding: utf-8 -*-
# 簇D（40个）与 簇E（39个）三桶台账自动生成与语义定性核实
import os, sys, re, csv
sys.stdout.reconfigure(encoding='utf-8')

lines = open('D:/MeteorRE/evidence/semD_clusterDE_analysis.txt', encoding='utf-8').read().split('=== ')

facts_d = []
facts_e = []

for block in lines[1:]:
    header_line = block.splitlines()[0]
    fa_str = header_line[:8]
    fa = int(fa_str, 16)
    is_cluster_d = "[Cluster D]" in header_line
    
    callees = ""
    pseudo = ""
    callers = ""
    for l in block.splitlines():
        if l.strip().startswith('[1]'): callers = l.strip()
        if l.strip().startswith('[2]'): callees = l.strip()
        if l.strip().startswith('[PSEUDO]'): pseudo = l.strip()[8:].strip()
    
    if is_cluster_d:
        if fa == 0x004A1540:
            sem = "Console_Cmd_Format_String"
            fact = "读取串池 s_Command__005c96b0 ('Command '), 格式化控制台指令"
            inf = "控制台命令解析与格式化字符串装配"
        elif fa == 0x004A81C0:
            sem = "Actor_Shadow_Projector"
            fact = "读取串池 s_shadow1_005c96d4 ('shadow1'), 连通 0x4054e0/0x405660 贴花投影"
            inf = "角色/物件脚底投影阴影贴花生成器"
        elif fa == 0x004A7E80:
            sem = "Combat_Hit_Mask_Dispatcher"
            fact = "调用虚表 *(piVar1 + 0x80) 传递掩码 param_3&0xf, &0xf0, &0xf00"
            inf = "战斗打击盒命中属性分级与伤害类型掩码分派"
        elif fa in (0x004A2E10, 0x004A3C90, 0x004A4450):
            sem = "Physics_SAT_Pair_Alloc"
            fact = "operator_new 分配碰撞对结构体，调用 0x4e8a20 / 0x4b4a30 构造"
            inf = "SAT 碰撞检测实体对（Collider Pair）动态创建"
        elif fa == 0x004B0055:
            sem = "Combat_Projectile_Trajectory"
            fact = "调用 0x549b00 弹道计算，0x509980 (__ftol) 整数截断，0x4acae0 命中检测"
            inf = "飞行道具抛物线轨迹计算与命中步进"
        elif fa in (0x004B4E80, 0x004B31B0):
            sem = "Combat_Weapon_Hitbox_Query"
            fact = "调用 0x4b5fc0 进行武器打击盒与受击盒交叉查询"
            inf = "武器挥动打击范围与受击盒碰撞求交"
        elif fa in (0x004A69B0, 0x004A7D50, 0x004AABB0, 0x004AAC40):
            sem = "Combat_Combo_Buffer_Ops"
            fact = "0x49c640 / operator_new，扩容 0x42c/0x434 连招表槽位"
            inf = "连招指令输入缓冲队列增删与扩容"
        elif fa in (0x004A05B0, 0x004A0740, 0x004A16A0):
            sem = "Actor_State_Register"
            fact = "0x5092c0 (memcpy) / 0x403490 (vector 扩容), param_1+0x10 名字串登记"
            inf = "角色/控制器名字与基础状态注册"
        else:
            sem = "Physics_Combat_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "物理与战斗控制底层辅助"
            
        facts_d.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合武器 .pst 与动作 .act 标签复核命中掩码位定义"
        })
    else: # Cluster E
        if fa in (0x004E77E3, 0x004E79C3):
            sem = "CRT_Vector_OutOfRange_Throw"
            fact = "调用 0x509166 (__CxxThrowException@8), 0x49be20 异常信息构造"
            inf = "STL vector 越界访问 C++ 运行时异常抛出"
        elif fa in (0x004E7A60, 0x004E7B40, 0x004E7CF0):
            sem = "Script_Vector3_Buffer_Shift"
            fact = "(param_4 - param_2) / 0xc (12B = sizeof Vector3), 连续内存块向后搬运"
            inf = "路点/向量列表插入时的 12 字节 Vector3 缓冲区元素后移"
        elif fa in (0x004EBA00, 0x004EBA70, 0x004EBB40):
            sem = "AI_Path_Waypoint_Eval"
            fact = "*(param_1 + 0x80) 路点计数, *(param_1 + 0x84) short 数组节点查找, 0x4054e0 标志位写入"
            inf = "AI 寻路路径点序列遍历与距离启发式估算"
        elif fa == 0x004ED6E0:
            sem = "AI_Action_Callback_Invoke"
            fact = "param_1[0xc1] 激活检查, 调用虚表 *(param_1+0x8c) 与 *(param_1+0xa8) 驱动动作槽"
            inf = "AI 决策动作触发回调函数分派器"
        elif fa == 0x004F0BA0:
            sem = "Actor_Item_Pickup_Trigger"
            fact = "调用角色虚表 *(param_1 + 0x44) 与目标 *(piVar1 + 0x1e0) 触发拾取"
            inf = "角色接近地面道具/箱子掉落物时的拾取事件触发"
        elif fa == 0x004E2A40:
            sem = "AI_Target_State_Check"
            fact = "检查目标实体虚表 *(param_2 + 0x94) 返回值与 param_1 状态匹配"
            inf = "AI 锁定目标的存活与可攻击状态门控检查"
        elif fa in (0x004E5BB0, 0x004E6970, 0x004E6A30, 0x004E6AE0, 0x004E6BF0, 0x004E74E0):
            sem = "Script_VM_Stack_Frame_Ops"
            fact = "调用 0x4e6050 栈帧操作 / 0x402e90 节点释放 / 0x54cc30 栈指针调整"
            inf = "PScript 虚拟机运行时栈帧构建、局部变量分配与作用域退出"
        else:
            sem = "Script_AI_Helper"
            fact = f"callees={callees[:50]} pseudo={pseudo[:40]}"
            inf = "脚本虚拟机与 AI 决策底层辅助"

        facts_e.append({
            'addr': f"0x{fa:08X}",
            'name': sem,
            'fact': fact,
            'inf': inf,
            'unknown': "需结合 .pst 脚本操作码对齐指令栈顶布局"
        })

print(f"簇D 定性: {len(facts_d)} 个函数")
print(f"簇E 定性: {len(facts_e)} 个函数")

with open('D:/MeteorRE/evidence/semD_clusterD_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_d:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

with open('D:/MeteorRE/evidence/semD_clusterE_table.tsv', 'w', encoding='utf-8') as f:
    f.write("Addr\tSemanticName\tConfirmedFact\tInference\tOpenUnknown\n")
    for r in facts_e:
        f.write(f"{r['addr']}\t{r['name']}\t{r['fact']}\t{r['inf']}\t{r['unknown']}\n")

print("写入 TSV 成功")
