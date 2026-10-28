# -*- coding: utf-8 -*-
import json
import sys

sys.stdout.reconfigure(encoding='utf-8')

with open(r'D:\MeteorRE\evidence\lxres_top20_all_categories.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

md_lines = []
md_lines.append("# 15_COMMUNITY_PATCHES_NETWORKING_AND_ANTICHEAT.md")
md_lines.append("")
md_lines.append("> 本文档深度剖析《流星蝴蝶剑.net》（Meteor.exe）社区联机插件、反作弊防炸房补丁的底层二进制逆向原理，并完整归类收录流星资源网（`lxres.com`）全板块评分前二十与热门前二十资源生态。")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("## 一、流星网络通信底层架构与联机插件实现原理")
md_lines.append("")
md_lines.append("### 1.1 原版 Meteor.exe 网络通信机制与现代系统困境")
md_lines.append("《流星蝴蝶剑.net》发布于 2002 年，其网络底层深度依赖 **Microsoft DirectPlay 7/8** 与 **Winsock UDP 广播**：")
md_lines.append("1. **局域网发现广播**：客户端在大厅搜索房间时，向 `255.255.255.255:7000` 发送 UDP 广播探测包；主机端监听 UDP 7000/9800 端口，收到后应答主机配置（房间名、版本、当前人数、地图 ID 等）。")
md_lines.append("2. **客户端权威同步（Client-Authoritative P2P Mesh）**：游戏运行中，每位玩家计算自身的物理位移、按键输入和动作状态，通过 UDP 报文高频广播给房间内的所有其他客户端。主机（Server/Host）仅负责全局事件仲裁（胜负判定、比分计算、NPC 同步与胜局重置）。")
md_lines.append("3. **现代系统致命困境**：")
md_lines.append("   - **DirectPlay 废弃与 Win10/11 兼容性**：DirectPlay 接口在现代 Windows 中已退役，若未手动开启“旧版组件-DirectPlay”，客户端启动直接白屏崩溃或提示网络初始化失败。")
md_lines.append("   - **多层 NAT 与公网广播阻断**：现代家庭宽带大多处于运营商级 NAT（CGNAT）或多层家用路由器之后，UDP 广播数据包绝不可跨网段路由，导致外网玩家根本搜不到房间。")
md_lines.append("   - **注册表序列号冲突**：原版依赖注册表键值 `HKEY_LOCAL_MACHINE\\SOFTWARE\\InterServ\\Meteor` 中的 Serial 序列号。如果两个客户端安装包使用了相同的注册表 Dump 导入，联机时会报“序列号被占用”直接断开。")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("### 1.2 皎月联机插件与虚拟对战平台的实现原理")
md_lines.append("社区主流联机解决方案（如 `皎月联机插件`、`DE官方对战平台`、`游侠对战平台`）采用以下三层技术栈实现穿透联机：")
md_lines.append("")
md_lines.append("#### 机制 A：虚拟二层网卡隧道组网（TAP/TUN Virtual Adapter）")
md_lines.append("- **驱动层注入**：安装微型虚拟以太网驱动（基于 TAP-Windows 或 Wintun）。")
md_lines.append("- **私有虚拟局域网（VLAN）**：房间创建时，平台为进入同一房间的所有玩家动态分配同一 C 段虚拟 IP（例如 `10.88.x.x`）。")
md_lines.append("- **广播帧捕获与隧道封装**：当 `Meteor.exe` 向 `255.255.255.255:7000` 广播时，虚拟网卡截获以太网广播帧，用户态守护进程将其打包，利用 UDP 打洞（STUN/ICE 穿透）或高带宽服务器中继，定向分发给房间内的每个节点。远端虚拟网卡解包后向本地协议栈注入，使 `Meteor.exe` 认为收到了真实的局域网广播。")
md_lines.append("")
md_lines.append("#### 机制 B：Winsock API Hook / 本地协议代理（Winsock Wrapper）")
md_lines.append("- **API 拦截点**：通过挂钩 `wsock32.dll` / `ws2_32.dll` 中的关键导出函数：")
md_lines.append("  - `sendto()`：检测目的地址是否为 `INADDR_BROADCAST` 或 `255.255.255.255`。若是，将数据包克隆 $N$ 份，替换目标 IP 为平台下发的对端玩家 P2P 外网映射端口或中继节点端口。")
md_lines.append("  - `recvfrom()`：当收到外网转发过来的数据报文时，将源 IP 篡改为虚拟房间内的对应玩家地址，伪造无缝局域网环境。")
md_lines.append("  - `bind()` / `getsockname()`：重定向本地绑定端口，解决同一内网多台电脑同时建房的端口占用冲突。")
md_lines.append("")
md_lines.append("#### 机制 C：DLL 劫持与内存运行时扩展（`avifil32.dll` / `snmpapi.dll`）")
md_lines.append("- **Windows 加载顺序劫持**：Windows 加载动态链接库时，默认优先搜索当前应用程序所在目录。流星社区利用此机制，将补丁 DLL 命名为系统库名 `avifil32.dll`（用于 AVI 录屏导出）或 `snmpapi.dll`（SNMP 管理库）。")
md_lines.append("- **运行时挂钩**：在 `DllMain(DLL_PROCESS_ATTACH)` 中启动主线程：")
md_lines.append("  1. 转发真实的系统导出函数到 `C:\\Windows\\System32\\avifil32.dll`，防止破坏原功能。")
md_lines.append("  2. 在 `Meteor.exe` 进程空间内安装 IAT Hook 或 MinHook，挂钩窗口消息处理函数 `PeekMessageA` / `GetMessageA`。")
md_lines.append("  3. 捕获热键呼出控制台（如 `~`、`F1`-`F12`），调用内部接口实现局内切图、踢人、切换模式，无需重退大厅。")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("## 二、反外挂与防炸房补丁的底层逆向原理")
md_lines.append("")
md_lines.append("### 2.1 常见外挂作弊机理与防御补丁的二进制 Hook 点")
md_lines.append("")
md_lines.append("| 外挂类型 | 作弊原理与底层特征 | 防御补丁实现机制（血饮版 / 综合补丁 / 滴风） | 对应 Meteor.exe 逆向代码位置 |")
md_lines.append("| :--- | :--- | :--- | :--- |")
md_lines.append("| **无限气 (Chi Hack)** | 内存修改器（幽魂、CE）循环将 `[Player + 0x...Chi]` 强写为 100，无限释放大绝招。 | **消耗校验与静默反制**：Hook 攻击结算与大招判定点。记录释放绝招时的气量时间戳。若检测到连续绝招间隔 $< 60$ 帧且气量不减，强制将造成伤害归零（攻击无效），多次违规直接调用 `skick` 踢出。 | `Player::UseSuperSkill` / 绝招扣气点 `0x004C...` |")
md_lines.append("| **秒杀 / 改攻击力** | 篡改武器基础倍率或在客户端计算伤害时强改伤害数值为 9999。 | **双向伤害上限裁剪**：Hook `ComputeDamage` (`0x004D5B70`)。根据当前武器类型和动画 Pose 动作 ID，硬编码或查表校验最大合法单击伤害（如大刀单次不超过 120）。若传来的伤害值超过理论上限，直接裁剪为合法值或将受击者免伤。 | `0x004D5B70` (`ComputeDamage`) |")
md_lines.append("| **招招破防** | 强行在攻击数据包中植入破防标志位（Ignore Guard Flag），使轻击也能击穿防御。 | **姿态属性对齐校验**：校验发起攻击的 Pose ID 是否具备合法的破防属性（`0x005B0214` 属性表）。非破防招式若携带破防标志，直接将破防位抹零，强制进入正常格挡姿态。 | `Player::SetBlock` (`0x004C3900`) & `0x004C06A0` |")
md_lines.append("| **改 POS / 飞天瞬移** | 直接覆写自身 `Vec3` 坐标或篡改重力常数，实现全图瞬移与空中漫步。 | **速度位移梯度审查**：主机插件在每个 Tick 计算目标位移距离 $\\Delta D = \\|P_t - P_{t-1}\\|$。若 $\\Delta D > V_{max} \\times \\Delta t + \\epsilon$（超出最大允许移动速度），判定为非法位移，拒绝同步并将其物理状态置死或强拉回 $P_{t-1}$。 | `0x004D95D0` (网络属性同步) / `0x004D8CF0` (`Slot 200`) |")
md_lines.append("| **卡武器 / 假武器** | 客户端伪造背包数据，指虎动作打出长枪判定，或隐藏武器模型。 | **武器模型与动作合法性交叉验证**：检测换武器动作帧。若判定当前执行的动作 Pose 所属武器类型与实际挂载的武器 ID 不一致，直接将非法攻击者杀死或踢出。 | `Weapon::Attach` / `0x004FF200` 招式构建器 |")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("### 2.2 防炸房（Crash Exploit）与防光影崩溃的二进制防护")
md_lines.append("在早期对战平台中，恶意玩家常利用原版流星引擎的内存越界漏洞炸毁整个房间，主流防炸补丁的技术实现如下：")
md_lines.append("")
md_lines.append("1. **聊天文本与马甲名缓冲区溢出防御**：")
md_lines.append("   - **漏洞成因**：原版在解析网络数据包中的玩家昵称和聊天文本时，使用了无长度限制的 `strcpy` / `sprintf` 拷贝至定长栈缓冲区，超长文本直接覆写函数返回地址引发 DEP 崩溃。")
md_lines.append("   - **补丁修复**：在数据包反序列化入口处拦截，执行截断保护：`if (len > 16) buf[16] = '\\0';`，过滤特殊格式化占位符（如 `%s`, `%n`）。")
md_lines.append("2. **PonEF 光影特效炸房防御（特效池溢出）**：")
md_lines.append("   - **漏洞成因**：流星的粒子与光效系统 `PonEF`（位于 `0x00566348`）拥有固定大小的内存对象池（通常为 256~512 个槽位）。攻击者连续广播大量释放全屏特效的数据包，对象池耗尽时引擎返回空指针，渲染循环解引用空指针引发非法访问崩溃。")
md_lines.append("   - **补丁修复**：在 `PonEF::Spawn` 入口挂钩，对单秒内特效创建速率施加速率限制（Rate Limiting），并严格增加非空校验，当特效池饱和时丢弃后续特效，避免崩溃。")
md_lines.append("3. **VEH (Vectored Exception Handling) 全局崩溃接管**：")
md_lines.append("   - 防炸补丁通过调用 `AddVectoredExceptionHandler(1, SafeVectoredHandler)` 注册顶层向量化异常处理程序。")
md_lines.append("   - 当任何未预期的内存非法访问（`0xC0000005`）发生时，捕获当前异常线程上下文，重置指令指针 `EIP` 跳出受损的解析循环，丢弃异常数据包，保持主机主线程稳定运行。")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("### 2.3 四方阵空气墙补丁的物理层实现机制")
md_lines.append("- **设计痛点**：四方阵（SN06）作为流星最热门的竞技对战地图，边缘掉落悬崖即死，常导致比赛因跌落而中断。")
md_lines.append("- **实现原理**：")
md_lines.append("  1. **BSP 碰撞几何体重构**：作者在 `SN06.des` 场景描述符或地图网格碰撞体中，在四方阵四周边缘添加了 4 堵高约 50 单位的垂直不可见碰撞面（Invisible Collision Mesh）。")
md_lines.append("  2. **法向碰撞响应**：当玩家坐标推进至边缘时，物理引擎的碰撞检测函数（`CheckCollision`）检测到接触空气墙网格，计算法向反射反作用力，阻断向外的速度分量。")
md_lines.append("  3. **联机纯客户端兼容性**：由于流星各客户端独立计算自身受击与碰撞，安装空气墙补丁的玩家在己方客户端无法滑落悬崖，且不会改变场景内武器刷新点坐标，从而可与原版玩家无缝同房联机。")
md_lines.append("")
md_lines.append("---")
md_lines.append("")
md_lines.append("## 三、流星资源网（lxres.com）全板块热门与评分 Top 20 深度分类清单")
md_lines.append("")

for cat_idx, (cat_name, cat_data) in enumerate(data.items(), 1):
    md_lines.append(f"### 3.{cat_idx} 【{cat_name}】资源榜单与生态归类")
    md_lines.append("")
    md_lines.append(f"#### 1. 热门榜 Top 20")
    md_lines.append("| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |")
    md_lines.append("| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |")
    for i, it in enumerate(cat_data['top_20_hot']):
        title = it['title'].replace('|', '&#124;')
        author = it['author'].replace('|', '&#124;')
        size = it['size']
        star = f"{it['rating_star']}★"
        date = it['update_date']
        url = it['url']
        desc = it['description'].replace('|', '&#124;').replace('\n', ' ')
        desc_short = desc[:45] + '...' if len(desc) > 45 else desc
        md_lines.append(f"| {i+1:02d} | [{title}]({url}) | {author} | {size} | {star} | {date} | [直达]({url}) | {desc_short} |")
    
    md_lines.append("")
    md_lines.append(f"#### 2. 评分榜 Top 20")
    md_lines.append("| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |")
    md_lines.append("| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |")
    for i, it in enumerate(cat_data['top_20_score']):
        title = it['title'].replace('|', '&#124;')
        author = it['author'].replace('|', '&#124;')
        size = it['size']
        star = f"{it['rating_star']}★"
        date = it['update_date']
        url = it['url']
        desc = it['description'].replace('|', '&#124;').replace('\n', ' ')
        desc_short = desc[:45] + '...' if len(desc) > 45 else desc
        md_lines.append(f"| {i+1:02d} | [{title}]({url}) | {author} | {size} | {star} | {date} | [直达]({url}) | {desc_short} |")
    md_lines.append("")
    md_lines.append("---")
    md_lines.append("")

doc_path = r'D:\MeteorRE\docs\15_COMMUNITY_PATCHES_NETWORKING_AND_ANTICHEAT.md'
with open(doc_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(md_lines))

print(f"Generated complete document: {doc_path} (Total lines: {len(md_lines)})")
