# 15_COMMUNITY_PATCHES_NETWORKING_AND_ANTICHEAT.md

> 本文档深度剖析《流星蝴蝶剑.net》（Meteor.exe）社区联机插件、反作弊防炸房补丁的底层二进制逆向原理，并完整归类收录流星资源网（`lxres.com`）全板块评分前二十与热门前二十资源生态。

---

## 一、流星网络通信底层架构与联机插件实现原理

### 1.1 原版 Meteor.exe 网络通信机制与现代系统困境
《流星蝴蝶剑.net》发布于 2002 年，其网络底层深度依赖 **Microsoft DirectPlay 7/8** 与 **Winsock UDP 广播**：
1. **局域网发现广播**：客户端在大厅搜索房间时，向 `255.255.255.255:7000` 发送 UDP 广播探测包；主机端监听 UDP 7000/9800 端口，收到后应答主机配置（房间名、版本、当前人数、地图 ID 等）。
2. **客户端权威同步（Client-Authoritative P2P Mesh）**：游戏运行中，每位玩家计算自身的物理位移、按键输入和动作状态，通过 UDP 报文高频广播给房间内的所有其他客户端。主机（Server/Host）仅负责全局事件仲裁（胜负判定、比分计算、NPC 同步与胜局重置）。
3. **现代系统致命困境**：
   - **DirectPlay 废弃与 Win10/11 兼容性**：DirectPlay 接口在现代 Windows 中已退役，若未手动开启“旧版组件-DirectPlay”，客户端启动直接白屏崩溃或提示网络初始化失败。
   - **多层 NAT 与公网广播阻断**：现代家庭宽带大多处于运营商级 NAT（CGNAT）或多层家用路由器之后，UDP 广播数据包绝不可跨网段路由，导致外网玩家根本搜不到房间。
   - **注册表序列号冲突**：原版依赖注册表键值 `HKEY_LOCAL_MACHINE\SOFTWARE\InterServ\Meteor` 中的 Serial 序列号。如果两个客户端安装包使用了相同的注册表 Dump 导入，联机时会报“序列号被占用”直接断开。

---

### 1.2 皎月联机插件与虚拟对战平台的实现原理
社区主流联机解决方案（如 `皎月联机插件`、`DE官方对战平台`、`游侠对战平台`）采用以下三层技术栈实现穿透联机：

#### 机制 A：虚拟二层网卡隧道组网（TAP/TUN Virtual Adapter）
- **驱动层注入**：安装微型虚拟以太网驱动（基于 TAP-Windows 或 Wintun）。
- **私有虚拟局域网（VLAN）**：房间创建时，平台为进入同一房间的所有玩家动态分配同一 C 段虚拟 IP（例如 `10.88.x.x`）。
- **广播帧捕获与隧道封装**：当 `Meteor.exe` 向 `255.255.255.255:7000` 广播时，虚拟网卡截获以太网广播帧，用户态守护进程将其打包，利用 UDP 打洞（STUN/ICE 穿透）或高带宽服务器中继，定向分发给房间内的每个节点。远端虚拟网卡解包后向本地协议栈注入，使 `Meteor.exe` 认为收到了真实的局域网广播。

#### 机制 B：Winsock API Hook / 本地协议代理（Winsock Wrapper）
- **API 拦截点**：通过挂钩 `wsock32.dll` / `ws2_32.dll` 中的关键导出函数：
  - `sendto()`：检测目的地址是否为 `INADDR_BROADCAST` 或 `255.255.255.255`。若是，将数据包克隆 $N$ 份，替换目标 IP 为平台下发的对端玩家 P2P 外网映射端口或中继节点端口。
  - `recvfrom()`：当收到外网转发过来的数据报文时，将源 IP 篡改为虚拟房间内的对应玩家地址，伪造无缝局域网环境。
  - `bind()` / `getsockname()`：重定向本地绑定端口，解决同一内网多台电脑同时建房的端口占用冲突。

#### 机制 C：DLL 劫持与内存运行时扩展（`avifil32.dll` / `snmpapi.dll`）
- **Windows 加载顺序劫持**：Windows 加载动态链接库时，默认优先搜索当前应用程序所在目录。流星社区利用此机制，将补丁 DLL 命名为系统库名 `avifil32.dll`（用于 AVI 录屏导出）或 `snmpapi.dll`（SNMP 管理库）。
- **运行时挂钩**：在 `DllMain(DLL_PROCESS_ATTACH)` 中启动主线程：
  1. 转发真实的系统导出函数到 `C:\Windows\System32\avifil32.dll`，防止破坏原功能。
  2. 在 `Meteor.exe` 进程空间内安装 IAT Hook 或 MinHook，挂钩窗口消息处理函数 `PeekMessageA` / `GetMessageA`。
  3. 捕获热键呼出控制台（如 `~`、`F1`-`F12`），调用内部接口实现局内切图、踢人、切换模式，无需重退大厅。

---

## 二、反外挂与防炸房补丁的底层逆向原理

### 2.1 常见外挂作弊机理与防御补丁的二进制 Hook 点

| 外挂类型 | 作弊原理与底层特征 | 防御补丁实现机制（血饮版 / 综合补丁 / 滴风） | 对应 Meteor.exe 逆向代码位置 |
| :--- | :--- | :--- | :--- |
| **无限气 (Chi Hack)** | 内存修改器（幽魂、CE）循环将 `[Player + 0x...Chi]` 强写为 100，无限释放大绝招。 | **消耗校验与静默反制**：Hook 攻击结算与大招判定点。记录释放绝招时的气量时间戳。若检测到连续绝招间隔 $< 60$ 帧且气量不减，强制将造成伤害归零（攻击无效），多次违规直接调用 `skick` 踢出。 | `Player::UseSuperSkill` / 绝招扣气点 `0x004C...` |
| **秒杀 / 改攻击力** | 篡改武器基础倍率或在客户端计算伤害时强改伤害数值为 9999。 | **双向伤害上限裁剪**：Hook `ComputeDamage` (`0x004D5B70`)。根据当前武器类型和动画 Pose 动作 ID，硬编码或查表校验最大合法单击伤害（如大刀单次不超过 120）。若传来的伤害值超过理论上限，直接裁剪为合法值或将受击者免伤。 | `0x004D5B70` (`ComputeDamage`) |
| **招招破防** | 强行在攻击数据包中植入破防标志位（Ignore Guard Flag），使轻击也能击穿防御。 | **姿态属性对齐校验**：校验发起攻击的 Pose ID 是否具备合法的破防属性（`0x005B0214` 属性表）。非破防招式若携带破防标志，直接将破防位抹零，强制进入正常格挡姿态。 | `Player::SetBlock` (`0x004C3900`) & `0x004C06A0` |
| **改 POS / 飞天瞬移** | 直接覆写自身 `Vec3` 坐标或篡改重力常数，实现全图瞬移与空中漫步。 | **速度位移梯度审查**：主机插件在每个 Tick 计算目标位移距离 $\Delta D = \|P_t - P_{t-1}\|$。若 $\Delta D > V_{max} \times \Delta t + \epsilon$（超出最大允许移动速度），判定为非法位移，拒绝同步并将其物理状态置死或强拉回 $P_{t-1}$。 | `0x004D95D0` (网络属性同步) / `0x004D8CF0` (`Slot 200`) |
| **卡武器 / 假武器** | 客户端伪造背包数据，指虎动作打出长枪判定，或隐藏武器模型。 | **武器模型与动作合法性交叉验证**：检测换武器动作帧。若判定当前执行的动作 Pose 所属武器类型与实际挂载的武器 ID 不一致，直接将非法攻击者杀死或踢出。 | `Weapon::Attach` / `0x004FF200` 招式构建器 |

---

### 2.2 防炸房（Crash Exploit）与防光影崩溃的二进制防护
在早期对战平台中，恶意玩家常利用原版流星引擎的内存越界漏洞炸毁整个房间，主流防炸补丁的技术实现如下：

1. **聊天文本与马甲名缓冲区溢出防御**：
   - **漏洞成因**：原版在解析网络数据包中的玩家昵称和聊天文本时，使用了无长度限制的 `strcpy` / `sprintf` 拷贝至定长栈缓冲区，超长文本直接覆写函数返回地址引发 DEP 崩溃。
   - **补丁修复**：在数据包反序列化入口处拦截，执行截断保护：`if (len > 16) buf[16] = '\0';`，过滤特殊格式化占位符（如 `%s`, `%n`）。
2. **PonEF 光影特效炸房防御（特效池溢出）**：
   - **漏洞成因**：流星的粒子与光效系统 `PonEF`（位于 `0x00566348`）拥有固定大小的内存对象池（通常为 256~512 个槽位）。攻击者连续广播大量释放全屏特效的数据包，对象池耗尽时引擎返回空指针，渲染循环解引用空指针引发非法访问崩溃。
   - **补丁修复**：在 `PonEF::Spawn` 入口挂钩，对单秒内特效创建速率施加速率限制（Rate Limiting），并严格增加非空校验，当特效池饱和时丢弃后续特效，避免崩溃。
3. **VEH (Vectored Exception Handling) 全局崩溃接管**：
   - 防炸补丁通过调用 `AddVectoredExceptionHandler(1, SafeVectoredHandler)` 注册顶层向量化异常处理程序。
   - 当任何未预期的内存非法访问（`0xC0000005`）发生时，捕获当前异常线程上下文，重置指令指针 `EIP` 跳出受损的解析循环，丢弃异常数据包，保持主机主线程稳定运行。

---

### 2.3 四方阵空气墙补丁的物理层实现机制
- **设计痛点**：四方阵（SN06）作为流星最热门的竞技对战地图，边缘掉落悬崖即死，常导致比赛因跌落而中断。
- **实现原理**：
  1. **BSP 碰撞几何体重构**：作者在 `SN06.des` 场景描述符或地图网格碰撞体中，在四方阵四周边缘添加了 4 堵高约 50 单位的垂直不可见碰撞面（Invisible Collision Mesh）。
  2. **法向碰撞响应**：当玩家坐标推进至边缘时，物理引擎的碰撞检测函数（`CheckCollision`）检测到接触空气墙网格，计算法向反射反作用力，阻断向外的速度分量。
  3. **联机纯客户端兼容性**：由于流星各客户端独立计算自身受击与碰撞，安装空气墙补丁的玩家在己方客户端无法滑落悬崖，且不会改变场景内武器刷新点坐标，从而可与原版玩家无缝同房联机。

---

## 三、流星资源网（lxres.com）全板块热门与评分 Top 20 深度分类清单

### 3.1 【主客户端】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [流星蝴蝶剑9.07完整版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/448.html) | 昱泉国际 | 409.28 | 4★ | 2019-11-01 22:06:34 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/448.html) | 更新如下：1、在安装包中集成“图像增强补丁6.2.9”2、在安装包中集成“人物全开选项”3... |
| 02 | [流星蝴蝶剑1.07完整版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/193.html) | 昱泉国际 | 409.29 | 3★ | 2019-11-01 22:49:57 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/193.html) | 更新如下：1、在安装包中集成“图像增强补丁6.2.9”2、在安装包中集成“人物全开选项”3... |
| 03 | [流星蝴蝶剑NET（永恒经典版1.0）1.07、1.08、9.07全版本完美精装](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/375.html) | 流星驿站 | 515.03 | 3★ | 2010-10-11 19:23:50 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/375.html) | 引用	源于古龙的同名武侠小说《流星·蝴蝶·剑》，为古龙代表作品，数次被改编成影视作品。同名... |
| 04 | [流星蝴蝶剑·幽魂隐龙精简版v1.4.2](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/189.html) | 幽魂网、隐龙轩 | 40.2 | 3★ | 2011-06-12 22:46:25 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/189.html) | 杀毒软件扫描：卡巴斯基通过，360通过。-------------------------... |
| 05 | [流星蝴蝶剑9.08完整版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1265.html) | 昱泉国际 | 409.62 | 3★ | 2019-11-01 23:10:25 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1265.html) | 更新如下：1、在安装包中集成“图像增强补丁6.2.9”2、在安装包中集成“人物全开选项”3... |
| 06 | [流星蝴蝶剑.net_官方iso文件含升级补丁](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1340.html) | 昱泉国际 | 607.74 | 3★ | 2017-07-03 12:00:00 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1340.html) | [说明]流星蝴蝶剑官方升级补丁整合版。包含1.02到9.08所有的升级补丁。安装程序是IS... |
| 07 | [流星蝴蝶剑9.07官方场景光影增强版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1772.html) | 昱泉国际 | 407.404 | 4★ | 2020-05-22 02:06:08 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1772.html) | 地图光影制作：墨香 &#124;&#124; 图像补丁：滴风居士 &#124;&#124;... |
| 08 | [流星蝴蝶剑1.08完整版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/639.html) | 昱泉国际 | 409.65 | 3★ | 2019-11-01 22:58:27 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/639.html) | 更新如下：1、在安装包中集成“图像增强补丁6.2.9”2、在安装包中集成“人物全开选项”3... |
| 09 | [安卓版流星蝴蝶剑.net V0.3.1.0](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1467.html) | 悟空 | 167.62 | 4★ | 2020-10-17 07:57:42 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1467.html) | 为pc版流星蝴蝶剑.net移植版，为安卓版！可在运行安卓系统的手机平板上运行！ |
| 10 | [《流星蝴蝶剑》完美版 主客户端 9.07完整版 精装珍藏版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/779.html) | 支雅游戏 | 484.93 | 3★ | 2012-09-09 13:45:25 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/779.html) | 《流星蝴蝶剑》完美版简介《流星蝴蝶剑》完美版，是在《流星蝴蝶剑》9.07完整版的基础上创建... |
| 11 | [流星蝴蝶剑9.07与1.07完整版（2024贺岁版）](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1936.html) | 〓冰茶〓 | 529 | 3★ | 2024-01-14 21:35:14 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1936.html) | 上个9.07完整版发布于2007年，由于时过境迁发现安装包不兼容win8 win10  故... |
| 12 | [狼の诱惑纯净版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/598.html) | 诱惑の冰狼封月 | 45.63 | 3★ | 2011-07-07 22:52:58 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/598.html) | 流星蝴蝶剑狼の诱惑永恒珍藏版（复刻版）说明本版有以下特点:1.优化fps游戏速度提升.2.... |
| 13 | [流星蝴蝶剑.NET 官方全版本](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/31.html) | 昱泉国际 | 450.84 | 3★ | 2019-06-14 20:49:59 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/31.html) | 《流星蝴蝶剑.net》是昱泉国际由六人组成的“泰坦小组”（成员分别为：Jim, Ray, ... |
| 14 | [火影忍者疾风传版v2.0](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/729.html) | 艾克斯 | 179.83 | 3★ | 2013-08-09 00:48:24 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/729.html) | 前言：好久不见。本人网店事物繁忙所以很是愧疚现在才发布出来。本人网店网址http://sh... |
| 15 | [论剑社区2011流星蝴蝶剑9.07精简版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/533.html) | ㊣飞刀问情 | 38.07 | 4★ | 2010-12-31 16:02:18 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/533.html) | 1.去掉了忍刀气烟雾，大锤小必烟雾。提高FPS!2.经在百度吧投票后应广大玩友要求，恢复了... |
| 16 | [茅山道士精装版1.4](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/594.html) | yatelanda | 55.85 | 3★ | 2012-03-14 00:26:50 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/594.html) | 茅山道士精装版1.4原本两个月前就做好了，只是本人去了外地，所以迟迟未公布。今天回来正好上... |
| 17 | [流星蝴蝶剑9.07 高清无损版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4757.html) | 张大侠 | 888.45 | 4★ | 2026-10-07 21:09:20 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4757.html) | 26-10-07版本更新：紫禁之巅地图修复，全新超大地图，新增死亡点，新增武器道具。适合单... |
| 18 | [≮荣●誉≯1.07强化版本](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/374.html) | 朩狆嘸亾 | 58.05 | 3★ | 2010-08-16 00:04:04 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/374.html) | 本精简版作者：朩狆嘸亾联系QQ：1303036598建议使用迅雷下载1.保留了四方阵炎硫岛... |
| 19 | [焉雨精简版v1.5](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/203.html) | ゛越狱兔﹎☆ | 39.68 | 3★ | 2011-06-29 18:11:34 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/203.html) | 注：游戏版本为9.07焉雨精简版v1.5说明：1.【防踢】防255踢大厅、防血刀踢场、防A... |
| 20 | [狼の诱惑精简版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/48.html) | 狼の诱惑 | 47.38 | 3★ | 2009-03-21 16:56:39 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/48.html) | *直接双击打开选择盘符安装。*完成安装后会提示导入注册表，选择确定，导入。*如果注册表被锁... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [[安卓]流星X_联机优化版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/2616.html) | 段靓仔想去东莞 | 196.38 | 5★ | 2024-05-19 04:53:09 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/2616.html) | 流星X (联机优化版)--------------服务器反作弊检测: 无限气 锁血 变速齿... |
| 02 | [流星蝴蝶剑9.07完整版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/448.html) | 昱泉国际 | 409.28 | 4★ | 2019-11-01 22:06:34 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/448.html) | 更新如下：1、在安装包中集成“图像增强补丁6.2.9”2、在安装包中集成“人物全开选项”3... |
| 03 | [论剑社区2011流星蝴蝶剑9.07精简版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/533.html) | ㊣飞刀问情 | 38.07 | 4★ | 2010-12-31 16:02:18 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/533.html) | 1.去掉了忍刀气烟雾，大锤小必烟雾。提高FPS!2.经在百度吧投票后应广大玩友要求，恢复了... |
| 04 | [流星蝴蝶剑单机精简版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1281.html) | 酒葒铯の吢 | 16.9 | 4★ | 2017-01-10 12:00:00 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1281.html) | 注意：只有一张地图！新系统首次运行先点击流星蝴蝶剑注册列表后才能进入游戏，32位系统点击3... |
| 05 | [安卓版流星蝴蝶剑.net V0.3.1.0](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1467.html) | 悟空 | 167.62 | 4★ | 2020-10-17 07:57:42 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1467.html) | 为pc版流星蝴蝶剑.net移植版，为安卓版！可在运行安卓系统的手机平板上运行！ |
| 06 | [浩方【圣剑门】V9.07岛斗版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1606.html) | 【圣剑门】剑魂 | 91.26 | 4★ | 2019-06-06 21:30:40 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1606.html) | 适合浩方岛斗玩家、全是浩方玩家喜欢的地图 |
| 07 | [【枪战版】烈酒杀意1.0正式版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1708.html) | 烈酒×杀意 | 338.83 | 4★ | 2020-01-06 00:17:46 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1708.html) | 1、火枪+副武器+道具 利用地图优势作战思路：火枪移动速度慢除了用副武器不可破防，可以去加... |
| 08 | [流星蝴蝶剑9.07官方场景光影增强版](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1772.html) | 昱泉国际 | 407.404 | 4★ | 2020-05-22 02:06:08 | [直达](https://www.lxres.com/ZhuKeHuDuan/GuanFangYuanBan/1772.html) | 地图光影制作：墨香 &#124;&#124; 图像补丁：滴风居士 &#124;&#124;... |
| 09 | [流星蝴蝶剑珍藏版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1873.html) | 地球人 | 195.74 | 4★ | 2020-11-07 21:02:43 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1873.html) | 此版本基于他人版本进一步优化删除多余文件，力求最洁净，武器光影地图简约美观，画质补丁已经最... |
| 10 | [流星蝴蝶剑-地图版-267地图](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/2486.html) | 无名 | 4.33 | 4★ | 2023-09-26 02:09:34 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/2486.html) | 地图版保留了官方的所有地图整合了资源网的所有地图及个别错误地图没加进去想玩新地图的小伙伴下... |
| 11 | [流星蝴蝶剑.李白语音版5.1](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/3210.html) | 张大侠 | 727.15 | 4★ | 2025-11-02 20:34:52 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/3210.html) | 2025/11月更新：  （李白语音版）：1.优化语音协调。2.添加角色死亡武器掉落音效（... |
| 12 | [流星蝴蝶剑9.07 高清无损版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4757.html) | 张大侠 | 888.45 | 4★ | 2026-10-07 21:09:20 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4757.html) | 26-10-07版本更新：紫禁之巅地图修复，全新超大地图，新增死亡点，新增武器道具。适合单... |
| 13 | [流星蝴蝶剑2026](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4785.html) | 来参加我的银趴 | 447.53 | 4★ | 2025-12-07 16:53:09 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4785.html) | 推荐浩方平台使用  分辨率推荐设置 1920X1080 或者2560X1440 或者128... |
| 14 | [流星蝴蝶剑V1.08.3超清全新版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4789.html) | 唐家笑三少 | 1669.27 | 4★ | 2026-01-04 14:40:51 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4789.html) | 本版主要特色：1、所有过场CG均1080P超清处理；2、所有UI高清重制；3、所有地图超清... |
| 15 | [流星蝴蝶剑18关完结。](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4809.html) | 余音 | 未知 | 4★ | 2026-05-18 20:29:28 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4809.html) | 在原版基础上添加至18关。 |
| 16 | [流星蝴蝶剑9.07 绿色竞技版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4826.html) | 他妈的二等兵甘 | 210.84 | 4★ | 2026-10-18 21:59:33 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4826.html) | 版本说明 (QQ群:1078023536)1.该版本以流星蝴蝶剑9.07官方原版制作，未改... |
| 17 | [流星群侠录.觉醒版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4827.html) | 张大侠 | 842.91 | 4★ | 2026-10-08 07:45:03 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/4827.html) | 长枪，大锤，大刀，长剑，指虎，双刺小绝范围提升，大招伤害或范围提升。 飞镖，飞轮，大招范围... |
| 18 | [清风门精简版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1.html) | 清风门 | 32.27 | 3★ | 2009-03-21 17:03:19 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/1.html) | *直接双击打开选择盘符安装。*完成安装后会提示导入注册表，选择确定，导入。*如果注册表被锁... |
| 19 | [“流星五鼠版”重制版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/27.html) | 锦毛鼠♂白玉堂 | 77.09 | 3★ | 2020-02-09 23:14:21 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/27.html) | 要求：①FPS（很高，在确保完美画质的同时不放过任何提高机会）、原创（角色选择界面、八门阵... |
| 20 | [流星反作弊SP1版](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/34.html) | 天剑 | 33.27 | 3★ | 2009-03-21 17:19:56 | [直达](https://www.lxres.com/ZhuKeHuDuan/WanJiaZiZhi/34.html) | 此为9.08.1版本你还在为比赛时对手修改文件或者开外挂而烦恼吗？流星蝴蝶剑反作弊SP1发... |

---

### 3.2 【单机任务】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [武林搜剑录精装版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/955.html) | 寻小布 | 603.2 | 3★ | 2012-04-04 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/955.html) | 新版本说明(2014-02-06)：更新部分关卡bug，降低游戏难度，更换部分地图，修改部... |
| 02 | [流星新单机《七夜听雪》](https://www.lxres.com/DanJiRenWu/DuLiYunXing/42.html) | 青云无间 | 199.1 | 3★ | 2009-04-10 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/42.html) | 沧月流星之七夜听雪是以昱泉公司出品的正式版流星为基础修改而成具体操作使用和原正式版是一样的... |
| 03 | [流星蝴蝶剑官方单机任务+流星后传](https://www.lxres.com/DanJiRenWu/DuLiYunXing/787.html) | 昱泉国际,轩辕逍遥文 | 517.79 | 3★ | 2012-02-19 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/787.html) | ※欢迎安装流星蝴蝶剑流星蝴蝶剑后传※本版本集聚昱泉国际出品的流星蝴蝶剑官方9.07完整版和... |
| 04 | [《宿仇壹》重制版--新增全过场动画、经典武侠单机任务](https://www.lxres.com/DanJiRenWu/DuLiYunXing/269.html) | 流星之夕 | 606 | 3★ | 2019-08-16 13:59:09 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/269.html) | 流星蝴蝶剑《宿仇壹》介绍：《宿仇壹》是流星蝴蝶剑经典单机《宿仇系列》的第一部，初版制作于2... |
| 05 | [《宿仇4》巅峰流星单机巨作](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2237.html) | 流星之夕 | 1.75 | 3★ | 2023-01-21 10:30:22 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2237.html) | 《宿仇4》十月最新版本大更新！全新的成就系统共20个隐藏挑战新奖励、新剧情、全面关卡难度调... |
| 06 | [血蝴蝶Ⅱ](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2084.html) | LC罗西尼 | 597+529 | 4★ | 2021-08-05 15:46:22 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2084.html) | 借君三十年，繁花万里好江山 |
| 07 | [新单机《八荒神石》](https://www.lxres.com/DanJiRenWu/FuGaiYunXing/605.html) | 踏剑飞扬 | 112.59 | 3★ | 2015-08-20 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/FuGaiYunXing/605.html) | ======任务说明========最近忙了些别的，，新单机迟迟才发1这部新单机招式迅猛，... |
| 08 | [宿仇之路（宿仇3）V3.42全自由多结局分支单机任务](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1545.html) | 流星之夕 | 1.92 | 3★ | 2019-03-16 19:22:55 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1545.html) | 从2017年11月2日开始制作，到2019年2月2日完成，2月6日公布。制作这游戏共花了一... |
| 09 | [流星蝴蝶剑后传](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1183.html) | 轩辕逍遥文 | 175.69 | 3★ | 2011-04-06 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1183.html) | 欢迎安装流星蝴蝶剑后传第一关剧情中毒后的星和冷燕奄奄一息，就在这时候一只蝴蝶飞过奇迹出现，... |
| 10 | [流星经典大作《宿仇贰》V2.21正式版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1133.html) | 流星之夕 | 545.7 | 3★ | 2019-05-17 08:09:17 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1133.html) | 故事简介：当年冰龙城一役，江湖上武艺最强的大魔头冰龙帮帮主凤冰龙被晓和夕两人奋力击败后，凤... |
| 11 | [真武林江湖群侠传1-30+金龙版[测试版]](https://www.lxres.com/DanJiRenWu/DuLiYunXing/713.html) | ZMJ_123 | 719.3 | 3★ | 2010-06-17 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/713.html) | 【真武林江湖群侠传】--流星史上唯一的真正革命性最强超级AI!!!!你的江湖，你的梦想，尽... |
| 12 | [《灭神记》单机任务](https://www.lxres.com/DanJiRenWu/DuLiYunXing/565.html) | 奇迹_飞扬 | 276.19 | 3★ | 2011-03-24 20:44:24 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/565.html) | 《灭神记》单机任务终于低调震撼发布了。其实说实话，做部单机任务是挺不容易的，得自己弄武器，... |
| 13 | [《刀神》正式版(更新新手难度)](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2313.html) | Cruiser、R | 1380.88 | 4★ | 2023-05-03 20:22:18 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2313.html) | 回复星友的部分问题：1.刀神作者Cruiser、R已明确表示不再制作《刀神》系列作品，关于... |
| 14 | [流星蝴蝶剑《誉满天下》V2.0](https://www.lxres.com/DanJiRenWu/DuLiYunXing/620.html) | 浮起的尘沙 | 214.56 | 4★ | 2011-04-30 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/620.html) | ******该版本为《流星蝴蝶剑》原版改编，进入游戏为1.07的版本，没有做太多的测试，据... |
| 15 | [流星蝴蝶剑特别版《江湖末路》全套珍藏集](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2189.html) | 『流星奇迹』_兵兵 | 1124.25 | 4★ | 2023-01-01 00:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2189.html) | 如游玩过程中遇到BUG，请联系作者进行修复！联系QQ：765739946，QQ交流群：38... |
| 16 | [大型单机-秦时明月](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1116.html) | 三页先生 | 595.37 | 3★ | 2010-08-21 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1116.html) | 在国产动漫的夜空中，夜色漫漫无边突然一轮明月升起在神州大地上洒下光辉她就是秦时明月现在一颗... |
| 17 | [黑神话-悟空](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2231.html) | 清净一笑 | 1373.20 | 3★ | 2022-04-14 20:43:49 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2231.html) | 一般支持win10系统. 其他系统没有试过.(家里穷啊)解压文件,  找到"黑神话悟空.e... |
| 18 | [《真武林江湖群侠传1-24金牌搜图版》单机任务](https://www.lxres.com/DanJiRenWu/DuLiYunXing/122.html) | ZMJ_123 | 375.38 | 3★ | 2008-03-01 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/122.html) | 【真武林江湖群侠传】--流星史上唯一的真正革命性最强超级AI!!!!你的江湖，你的梦想，尽... |
| 19 | [寻梦录](https://www.lxres.com/DanJiRenWu/DuLiYunXing/671.html) | 寻 | 414.79 | 3★ | 2008-06-17 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/671.html) | 游戏终于完工了.......！！版本的漏洞也修复完毕（不过如有问题的还帮建议下QQ7867... |
| 20 | [仙剑4血战洛阳修正版](https://www.lxres.com/DanJiRenWu/FuGaiYunXing/155.html) | 慠眡兲芐-曾彬 | 23.81 | 3★ | 2015-07-28 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/FuGaiYunXing/155.html) | 这个原作品是“qiqi13”做的仙剑血战洛阳的，我下载完了，还可以只是没“仙剑”那些光影，... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [七夜听雪四合一自改招式版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2558.html) | P.E.M. | 238.00 | 4★ | 2023-12-10 22:21:41 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2558.html) | 本人将我的自改招式三个版本（资源网可以搜到）与原版的七夜听雪（老版本）进行了融合，使得七夜... |
| 02 | [流星蝴蝶剑《誉满天下》V2.0](https://www.lxres.com/DanJiRenWu/DuLiYunXing/620.html) | 浮起的尘沙 | 214.56 | 4★ | 2011-04-30 12:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/620.html) | ******该版本为《流星蝴蝶剑》原版改编，进入游戏为1.07的版本，没有做太多的测试，据... |
| 03 | [腥风起2](https://www.lxres.com/DanJiRenWu/DuLiYunXing/4761.html) | 嘎嘎鸭鸭 | 402.28 | 4★ | 2025-11-15 21:47:56 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/4761.html) | 由于罗西尼大佬已退坑，自己续写腥风起第二部，剧情承接第一部的结局。新人作者风格比较偏向恶搞... |
| 04 | [精品剧情单机——怪侠一枝梅](https://www.lxres.com/DanJiRenWu/DuLiYunXing/4760.html) | hm瓜瓜，yue温开 | 未知 | 4★ | 2025-09-12 01:58:46 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/4760.html) | 本作由原唐人电视剧《怪侠一枝梅》改编。在保留流星基础玩法的同时加入全新的剧情与更高级别的流... |
| 05 | [官方任务黑暗重置版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1887.html) | 小孩丶多吃点 | 131.72 | 4★ | 2020-11-30 23:06:10 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/1887.html) | 对黑暗版进行了重置，电脑人的难度依旧甩了原版几十条街，画风还是黑暗风格，非常炫酷。如过电脑... |
| 06 | [血蝴蝶Ⅱ](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2084.html) | LC罗西尼 | 597+529 | 4★ | 2021-08-05 15:46:22 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2084.html) | 借君三十年，繁花万里好江山 |
| 07 | [流星蝴蝶剑《前传》](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2090.html) | LC罗西尼 | 197 | 4★ | 2021-08-18 19:11:55 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2090.html) | 流星蝴蝶剑官方剧情的前传版 |
| 08 | [《血画符前传》新动作招式整合版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2153.html) | Cruiser、R | 891.79 | 4★ | 2023-03-19 21:06:05 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2153.html) | 自东晋十六国，五胡乱华以来，鲜卑拓拔氏一统中国北方起，至北魏孝文帝拓拔宏大力推广鲜卑民族汉... |
| 09 | [流星蝴蝶剑特别版《江湖末路》全套珍藏集](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2189.html) | 『流星奇迹』_兵兵 | 1124.25 | 4★ | 2023-01-01 00:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2189.html) | 如游玩过程中遇到BUG，请联系作者进行修复！联系QQ：765739946，QQ交流群：38... |
| 10 | [寒风侠客行重置版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2204.html) | 蝴蝶不列生 | 565.09 | 4★ | 2026-01-02 19:30:50 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2204.html) | 此版本选用了以《血蝴蝶二》动作库为基础的《流星搜剑录【联机任务】》动作库，将其中的部分动作... |
| 11 | [飞鹤翎（双难度版）](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2238.html) | 花之宫つ瑞穗 | 917.88 | 4★ | 2024-07-24 21:59:26 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2238.html) | 一．版本阐明：1.《飞鹤翎》属于9.08系列，小型趣味性单机闯关模式版本。该版本共9关，直... |
| 12 | [《七夜听雪》翻新版V1.0](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2287.html) | 凉笙绎挽歌 | 397.69 | 4★ | 2022-07-22 21:59:15 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2287.html) | 简介：版本原作者：青云无间特别声明：此版本无任何打赏渠道，也不做任何商业用途，仅供娱乐。版... |
| 13 | [《刀神》正式版(更新新手难度)](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2313.html) | Cruiser、R | 1380.88 | 4★ | 2023-05-03 20:22:18 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2313.html) | 回复星友的部分问题：1.刀神作者Cruiser、R已明确表示不再制作《刀神》系列作品，关于... |
| 14 | [【明月系列之中期3部合集】](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2473.html) | 老太爷子 | 1228.88 | 4★ | 2023-04-07 20:39:27 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2473.html) | 近日收到评论说，明月时间线混乱，看不懂。特意将三部进行时间排列，虽然相隔时间有所长短，但是... |
| 15 | [仙剑奇侠传4《终局》全语音重制版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2409.html) | 『流星奇迹』_兵兵 | 676.63 | 4★ | 2023-07-07 01:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2409.html) | 如游玩过程中遇到BUG，请联系作者进行修复！联系QQ：765739946，QQ交流群：38... |
| 16 | [《夜行人1：血影星河》V3.1](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2437.html) | 凉笙绎挽歌 | 1437.64 | 4★ | 2023-03-08 21:32:58 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2437.html) | 剧情简介：元朝末年，天下大乱。“夜行人”——一个江湖上突然出现的杀手组织，他们以“夜游神”... |
| 17 | [单机任务【满江红·一】V1.02修复，全语音过场动画版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2457.html) | 一贫 | 2.67 | 4★ | 2023-03-13 23:30:25 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2457.html) | 【温馨提示：拙作文件过大（压缩后2.67G），因为加入了全程过场动画。不想要动画的同学，请... |
| 18 | [《鹤仙传奇》夕修正式版（3-29更新）](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2458.html) | 可雪儿、流星之夕 | 773 | 4★ | 2023-03-29 12:43:46 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2458.html) | 创作背景：a.）此版本属于9.07系列，是《花女传说》的姊妹篇（并非续篇），创作历时共花费... |
| 19 | [《梦回江湖》龙年贺岁全套精装典藏版（2024 ）](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2491.html) | 【大鹏展翅】 | 3112.14 | 4★ | 2024-03-09 11:04:35 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2491.html) | 我的武侠梦欢迎来到《梦回江湖》全套精装典藏版—制作人：宁鹏QQ：765855982天下风云... |
| 20 | [《杀手·伊人君》重制版](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2495.html) | 『流星奇迹』_兵兵 | 565.33 | 4★ | 2023-07-07 00:00:00 | [直达](https://www.lxres.com/DanJiRenWu/DuLiYunXing/2495.html) | 如游玩过程中遇到BUG，请联系作者进行修复！联系QQ：765739946，QQ交流群：38... |

---

### 3.3 【补丁工具】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [流星蝴蝶剑无限气通用版](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/25.html) | ㄣ幽魂★天角星 | 14.17 | 3★ | 2012-10-21 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/25.html) | 运行此工具和流星，点击界面上的按钮或按快捷键进行无限气的开启和关闭。无限气开启后虽然看不见... |
| 02 | [单机无限气(单机任务专用)](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/356.html) | 佚名 | 6.98 | 3★ | 2010-08-17 00:09:25 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/356.html) | 有的人想玩单机任务，但是觉得电脑人太厉害，所以想开个无限气外挂来对付他们。但是用了“通用版... |
| 03 | [流星隐藏命令开启器v2.0(通用版)](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/9.html) | ㄣ幽魂★天角星 | 19.15 | 3★ | 2015-08-12 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/9.html) | 将内存修改型和文件修改型集合到一起，自动化，支持1.00至9.08的所有版本。可根据自己的... |
| 04 | [图像增强补丁6.5.9](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/1362.html) | 滴风 | 3.75 | 4★ | 2024-11-14 20:42:08 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/1362.html) | 此版本依然支持DirectX9模式，图像渲染效率提高5倍以上，现代硬件渲染10万个面的地图... |
| 05 | [皎月联机插件](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2228.html) | 小狼 | 蓝揍云为准 | 3★ | 2026-09-11 21:24:30 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2228.html) | 联机工具(支持所有带联机功能的游戏)用于日常跟小伙伴们一起联机打游戏。 |
| 06 | [流星版本转换补丁](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/102.html) | ㄣ幽魂★天角星 | 4.01 | 3★ | 2014-08-16 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/102.html) | 点击相应按钮即可在流星1.07版、1.08版、9.07版之间任意转换版本。自带隐藏命令开启... |
| 07 | [流星蝴蝶剑全版本辅助工具（单机）](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2028.html) | 画笔 | 5.60 | 3★ | 2021-06-03 15:39:39 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2028.html) | 流星全版本隐藏命令状态显示不动如山五倍攻击[email protected] |
| 08 | [流星蝴蝶剑多版本多功能修改器](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2534.html) | 画笔 | 5.80 | 4★ | 2023-09-07 16:16:03 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2534.html) | 流行单机版本修改器使用前请仔细查看使用说明（重点） |
| 09 | [流星蝴蝶剑.NET 注册表补丁](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/161.html) | 漠之北 | 19.12 | 3★ | 2019-07-19 22:00:28 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/161.html) | 作用：解决游戏无法打开，联机时显示序列号被占用，单机任务和局域网络按钮无法点击！更新：1）... |
| 10 | [流星指令器 第三代 v1.0.0.3](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/1734.html) | 蝶衣 | 812 | 3★ | 2020-09-03 15:10:20 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/1734.html) | 流星指令器，最快捷最方便的流星蝴蝶剑专用按键精灵，如今已经到第三代了！ |
| 11 | [选血选时选局次选人数修改工具](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/45.html) | ㄣ幽魂★天角星 | 14.53 | 3★ | 2012-04-24 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/45.html) | --请将此补丁放置于流星目录下运行--用于流星1.00～9.08版，可自动识别版本；只允许... |
| 12 | [人物全开补丁](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/32.html) | 佚名 | 769 | 3★ | 2008-11-01 14:19:03 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/32.html) | 可实现单机任务全部显示和区域网20个人物全部可选 |
| 13 | [忍刀去烟补丁](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/43.html) | 佚名 | 2.05 | 3★ | 2008-11-01 14:03:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/43.html) | 将文件复制到游戏根目录下的SFX文件夹中覆盖即可！可以去掉忍刀“下上上A”放出的烟雾！ |
| 14 | [一叶流星蝴蝶剑按键辅助正式版](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/747.html) | 一叶成林 | 1.05 | 3★ | 2009-05-20 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/747.html) | 纯粹出于对流星蝴蝶剑的喜爱制作了这个程序使用说明：F1~F8武器快捷键F9和F10剔除和限... |
| 15 | [互动游戏对战平台 Version 4.70](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1684.html) | 互动游戏对战平台 | 7.62 | 3★ | 2019-12-12 22:55:39 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1684.html) | 1.修正上一版本中几个小BUG2.更新红警反作弊补丁3.更新流星反作弊补丁4.更新工具包文... |
| 16 | [超强流星辅助工具](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/609.html) | ==嗜血== | 14.14 | 3★ | 2011-09-21 12:22:25 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/609.html) | 本软件使用说明;功能1，F1F2F3F4F5一键换双武器，把游戏中把ctrl设为换武器，在... |
| 17 | [流星蝴蝶剑.net 单机修改器](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1489.html) | 杰龙 | 399.62 | 3★ | 2018-05-06 20:44:17 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1489.html) | 软件用途：可以修改昱泉国际官方流星蝴蝶剑.net单机任务的回合时间、主角血量、武器。如有问... |
| 18 | [流星As脚本引擎2.7.7](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/2262.html) | 滴风 | 10.26 | 4★ | 2026-03-16 23:12:25 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/2262.html) | # 流星.net As脚本引擎   ## 版本 2.7.3 ## 介绍 As脚本引擎可以运... |
| 19 | [流星蝴蝶剑机器人2.0](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/266.html) | 江边之鸟 | 185.33 | 3★ | 2010-06-14 02:08:29 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/266.html) | 操作提示1、输入并保存游戏路径；2、游戏运行中、按F9键加入加强机器人,允许多次加入；3、... |
| 20 | [流星小跳辅助-加强版](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/546.html) | hi | 724.34 | 3★ | 2011-04-20 14:18:51 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/546.html) | 流星小跳辅助---加强版更新说明：灵敏度更加好，解决之前的可能有时会失效的弊端下载过之前的... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [流星按键辅助修正版3.1](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/511.html) | 邪神メ鬼见愁 | 608.04 | 4★ | 2011-03-03 21:08:22 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/511.html) | 请删除流星按键3.0辅助。更新按键房主功能，增加人物切换功能，增加圣诞武器切换；增加圣诞武... |
| 02 | [图像增强补丁6.5.9](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/1362.html) | 滴风 | 3.75 | 4★ | 2024-11-14 20:42:08 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/1362.html) | 此版本依然支持DirectX9模式，图像渲染效率提高5倍以上，现代硬件渲染10万个面的地图... |
| 03 | [道具导出插件(gmc_fmc_des)](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1405.html) | yish | 5.6 | 4★ | 2017-10-26 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/1405.html) | 此版用于导出[流星道具模型（gmc），动画（fmc），描述（des)等多个文件]流星道具模... |
| 04 | [流星As脚本引擎2.7.7](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/2262.html) | 滴风 | 10.26 | 4★ | 2026-03-16 23:12:25 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/2262.html) | # 流星.net As脚本引擎   ## 版本 2.7.3 ## 介绍 As脚本引擎可以运... |
| 05 | [3DRDX中文版_1.8](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2356.html) | 中原慕容秋(汉化) | 1.81 | 4★ | 2022-10-15 17:22:20 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2356.html) | 3DRipperDX  1.8 免安装版-------------------------... |
| 06 | [人物宝典v2.0](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2528.html) | 支雅游戏 | 601.59 | 4★ | 2023-08-21 06:53:17 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/2528.html) | 人物宝典 v 2.0 已经做出来了，模型和皮肤贴图直接打包了，用的时候才会提取出来。有些星... |
| 07 | [流星蝴蝶剑多版本多功能修改器](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2534.html) | 画笔 | 5.80 | 4★ | 2023-09-07 16:16:03 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/2534.html) | 流行单机版本修改器使用前请仔细查看使用说明（重点） |
| 08 | [流星蝴蝶剑单机实用工具最终版](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/4759.html) | 天使の守护者 | 1.70 | 4★ | 2025-12-21 20:24:20 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/4759.html) | F2 正切所有武器   F3  反切所有武器   F8  丢出所有武器F4  预设当前武器... |
| 09 | [AS单机任务制作--写对话助手(带按键跳过对话功能)](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4765.html) | 神仙鱼、 | 5.13 | 4★ | 2026-03-09 00:34:39 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4765.html) | 注：使用此【对话助手】的作者可以注明一下出处来源，推广一下这个【对话助手】，让更多想写单机... |
| 10 | [流星蝴蝶剑.net mod管理工具_v3.2.0](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4788.html) | 过山河。 | 5009 | 4★ | 2026-10-22 01:00:00 | [直达](https://www.lxres.com/BuDingGongJu/YouXiZengQiang/4788.html) | 流星蝴蝶剑.net 多mod管理编辑工具，支持pvk加密（带期限），支持编辑、创建地图 |
| 11 | [【英雄】DE官方对战平台](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/4815.html) | de888.cc | 3.71 | 4★ | 2026-09-18 09:57:34 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/4815.html) | 【DE】官方对战平台  正式上线。现已可以下载及正常游玩了！并且平台内的所有游戏免费向玩家... |
| 12 | [流星隐藏命令开启器v2.0(通用版)](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/9.html) | ㄣ幽魂★天角星 | 19.15 | 3★ | 2015-08-12 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/9.html) | 将内存修改型和文件修改型集合到一起，自动化，支持1.00至9.08的所有版本。可根据自己的... |
| 13 | [反作弊2.8a版](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/11.html) | 浪客剑心 | 105.62 | 3★ | 2008-09-09 15:33:44 | [直达](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/11.html) | 此文件是在大家应该都熟悉的2.5e反作弊的基础上修改的。功能比原来多了些，所有招试都不会有... |
| 14 | [[乖乖无情]反作弊补丁](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/16.html) | 乖乖こ无情 | 15.94 | 3★ | 2009-03-21 02:21:07 | [直达](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/16.html) | 解压到流星根目录里，然后运行下，更新，记得把根目录里的DLL文件全删掉版本特色1。只能用k... |
| 15 | [1.08防踢补丁](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/19.html) | 杀手阿一，浪客剑心，东湖居士 | 614.97 | 3★ | 2009-03-21 15:48:35 | [直达](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/19.html) | __版权_____版权:杀手阿一，浪客剑心，东湖居士网站:http://meteor.sk... |
| 16 | [流星AI同步补丁](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/22.html) | ㄣ幽魂★天角星 | 8.79 | 3★ | 2009-05-29 21:06:24 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/22.html) | 先运行流星，然后按快捷键F1开启，使用命令“adddummyxyz”添加机器人适用版本：1... |
| 17 | [1.07反作弊补丁](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/23.html) | 佚名 | 965.16 | 3★ | 2009-03-21 15:42:00 | [直达](https://www.lxres.com/BuDingGongJu/FanGuaBuDing/23.html) | 流星蝴蝶剑单挑精简版1.07反作弊版一、介绍完成安装后如果不能游戏请在流星目录里面找到1.... |
| 18 | [游戏辅助快速逃跑工具](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/24.html) | 乖乖こ无情 | 16.82 | 3★ | 2009-04-12 17:27:11 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/24.html) | 使用前提是在开启隐藏命令以后!隐藏命令开启：http://www.lxres.com/sh... |
| 19 | [流星蝴蝶剑无限气通用版](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/25.html) | ㄣ幽魂★天角星 | 14.17 | 3★ | 2012-10-21 12:00:00 | [直达](https://www.lxres.com/BuDingGongJu/FuZhuGongJu/25.html) | 运行此工具和流星，点击界面上的按钮或按快捷键进行无限气的开启和关闭。无限气开启后虽然看不见... |
| 20 | [流星语音补丁](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/30.html) | 國寶2005 | 642.07 | 3★ | 2008-09-09 14:53:21 | [直达](https://www.lxres.com/BuDingGongJu/ShiYongGongJu/30.html) | 本套件可讓你的流星人員使用語音音效，由於不想用外掛方式來解決男女差異的問題，且為了能正常上... |

---

### 3.4 【地图下载】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [雪域冰封](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/641.html) | 漠之北 | 9.72 | 3★ | 2013-02-06 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/641.html) | 名称：雪域冰封类型：四方阵美化特点：能与官方四方阵联网对战更新：修正客场背景旋转、或者消失... |
| 02 | [《大理城》洛阳地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/75.html) | saoye666 | 6.85 | 3★ | 2009-03-22 02:54:27 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/75.html) | 本地图制作精细，风格突出，每一个细节都做的很完美，而且很注重色调，所以作者消耗了大量的时间... |
| 03 | [《风雪四方、遗忘之谷、地狱方阵、仙水阵》地图](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/56.html) | 国宝 | 8.33 | 3★ | 2008-11-11 00:34:17 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/56.html) | ·直接解压至流星跟目录。·进入游戏选择地图时即可看见新地图。 |
| 04 | [秘境·不死传说](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/270.html) | 南美∈野猪 | 7.33 | 3★ | 2010-06-16 22:59:40 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/270.html) | 此版是秘境第3个版本了.秘境2·遗忘奇迹因为有BUG暂未解决.所以先发布了3版如有人发现B... |
| 05 | [【山间村落】流星蝴蝶剑新地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/997.html) | 天平 | 14.34 | 3★ | 2013-12-25 21:16:24 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/997.html) | 地图名称：山间村落压缩格式：zip压缩文件大小：15.0M左右地图作者：摇晃de天平整合发... |
| 06 | [秘境·不死传说二](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/252.html) | 南美∈野猪 枫泣魂 | 5.93 | 3★ | 2010-06-16 23:02:39 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/252.html) | 《秘境·不死传说测试版二》__文件说明________________sn33文件夹是地图... |
| 07 | [《秘境·遗忘奇迹》地图](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/201.html) | 南美∈野猪 | 10.23 | 3★ | 2008-11-30 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/201.html) | ≡≡≡《秘境★遗忘奇迹》≡≡≡感谢那些曾经支持我的朋友门.Z.Z.YF.YZ.KK.BB.... |
| 08 | [【四方美化(动态)】海滩四方](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/364.html) | 哑弹 | 6.71 | 3★ | 2010-10-10 23:32:56 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/364.html) | 将文件解压到流星根目录覆盖即可！注意备份源文件以免出错 |
| 09 | [《DJ洛阳城》地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/576.html) | 世人看我太疯癫★ | 10.25 | 3★ | 2011-07-28 11:28:28 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/576.html) | 《DJ洛阳》洛阳地图就是把你下好的这东西，解压出来，在把所有的文件点复制在找到你流星蝴蝶剑... |
| 10 | [《远古遗迹》新地图](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/490.html) | 木鱼、Jun、星月邪魂 | 9.67 | 3★ | 2010-12-12 00:39:09 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/490.html) | 运行安装程序，安装到流星蝴蝶剑目录下。设计策划：木鱼美术：Jun模型：星月邪魂 |
| 11 | [古扬州城正式版](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/958.html) | 滴风 | 11.32 | 3★ | 2015-01-18 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/958.html) | 地图名称：古扬州城作者：滴风此为正式版。地图移植自剑网三的扬州城。较之前的版本，叶子更美观... |
| 12 | [四方：血腥镇压之地](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/612.html) | 逆花 | 4.68 | 3★ | 2011-09-01 13:33:34 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/612.html) | 1.强烈建议以免出现问题，把流星目录下的SN06.PAK备份，原因是通过某个简介版本做的地... |
| 13 | [CF地图运输船移植流星完整版](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1052.html) | 萝卜 | 1.35 | 3★ | 2011-07-25 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1052.html) | 备份meteor.res然后直接全都扔进流星主目录里然后进入游戏后地图列表拉到最下面选运输... |
| 14 | [《高山流水》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/510.html) | 世人看我太疯癫★ | 6.28 | 3★ | 2011-02-01 21:42:35 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/510.html) | 《高山流水》四方就是把你下好的这东西，解压出来，在把所有的文件点复制在找到你流星蝴蝶剑的目... |
| 15 | [新地图《琼华派》](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/782.html) | 踏剑飞扬 | 15.79 | 3★ | 2012-03-30 22:03:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/782.html) | 文件放到根目录，替换源文件贴图导入ctexture.pak里如果红树不想要毒，把sn23文... |
| 16 | [新地图《忘幽谷》](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/173.html) | 【大鹏展翅】 | 8.6 | 3★ | 2009-06-06 01:38:14 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/173.html) | 本地图可使用AI加入NPC，这是本人制作的第二部地图第一部地图是《山谷阵》..... |
| 17 | [蓬莱御剑堂](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/797.html) | 星月邪魂 | 7.03 | 3★ | 2012-04-01 12:17:13 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/797.html) | 作者：星月邪魂蓬莱御剑堂很久以前做的一个地图，差不多和火鬼殿是一个时期的，这次整理了一下，... |
| 18 | [《镇妖塔》地图](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/278.html) | 漠之北 | 5.71 | 3★ | 2009-12-07 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/278.html) | 将此目录所以文件覆盖到流星目录下即可。 |
| 19 | [《秘境·极限跳跃》地图](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/163.html) | 南美∈野猪 | 19.73 | 3★ | 2009-08-25 22:14:27 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/163.html) | 极限跳跃地图，通过轻功来过关；游戏内有很多地面是会持续伤血或者直接死亡的，请小心；后期的地... |
| 20 | [《童话圣诞夜》地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/26.html) | bbtl123 | 1.94 | 3★ | 2009-03-22 02:48:35 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/26.html) | 将所有文件覆盖至游戏目录即可。部分修改版地图无法与其他玩家进行互联对战，解决办法为：1.让... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [秦时明月四方阵](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/317.html) | 排骨饭 | 1.16 | 4★ | 2010-08-05 11:46:22 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/317.html) | 作者：排骨饭安装：把sn06.pak文件复制到流星安装目录下，启动游戏进入四方阵地图 |
| 02 | [【暗卐魂】异型](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/480.html) | 伤魂血魄 | 5.28 | 4★ | 2010-12-26 12:07:25 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/480.html) | 使用方法将文件解压到流星根目录覆盖即可！注意备份源文件以免出错 |
| 03 | [湛蓝四方阵](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/642.html) | Delty`听寒 | 406.22 | 4★ | 2011-08-22 14:51:41 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/642.html) | 解压至流星根目录覆盖原文件即可。作者：Delty`听寒 |
| 04 | [大雄宝殿](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1216.html) | 龙葵-千秋霸业 | 2.41 | 4★ | 2016-06-27 12:00:00 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1216.html) | 解压全部文件到流星蝴蝶剑根目录即可，游戏开场往下拉就可以看到地图了大雄宝殿的风格作者：龙葵... |
| 05 | [播仙镇5.0](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1687.html) | 小坤 | 8.51 | 4★ | 2020-09-12 20:06:30 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1687.html) | 拷贝到流星蝴蝶剑根目录即可！ |
| 06 | [天龙洛阳(正常)-修复](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1720.html) | 烛火OP | 21.61 | 4★ | 2022-09-03 19:39:08 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/1720.html) | 把所有文件拷贝到流星根目录即可！ |
| 07 | [武林至尊擂台](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/2283.html) | 星河星魂,墨香 | 12.56 | 4★ | 2022-07-19 19:20:20 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/2283.html) | 地图提取、整理、导出、BUG修复：星河星魂 &#124;&#124; 地图光影、BUG检查... |
| 08 | [《盘龙阵》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/2361.html) | 世人看我太疯癫★我笑他人神经病∵ | 6.57 | 4★ | 2022-10-19 20:32:51 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/2361.html) | 复制后粘贴在流星蝴蝶剑的目录里面，替换文件在合并后就有效果了。 |
| 09 | [《流星塔》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/3198.html) | 世人看我太疯癫★我笑他人神经病∵ | 8.47 | 4★ | 2024-09-21 22:09:14 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/3198.html) | 《流星塔》     四方阵地图把这下好的文件，用WinRAR解压，在把所有的文件点复制找到... |
| 10 | [【瑶城地图】](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/3231.html) | 一贫 | 57 | 4★ | 2025-01-03 23:28:48 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/3231.html) | 元旦在家无聊做的地图。用单个素材自行布局拼的，添加了白天夜晚两种光影。安装方法不再赘述。因... |
| 11 | [冰火两重天--炎硫岛](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4745.html) | 张大侠 | 32.32 | 4★ | 2025-06-16 16:33:22 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4745.html) | 解压后将文件复制到流星目录进行替换。 |
| 12 | [《避邪阵》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/3239.html) | 世人看我太疯癫★我笑他人神经病∵ | 6.29 | 4★ | 2025-02-19 23:04:43 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/3239.html) | 《避邪阵》 四方阵地图 把这下好的文件，用WinRAR解压，在把所有的文件点复制 找到流星... |
| 13 | [【困龙谷】](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4763.html) | 一贫 | 12 | 4★ | 2025-09-21 02:23:17 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4763.html) | 制作动机：晚上刷B站，看到一个水族箱的视频，于是按照它的布局制作了本地图。安装方法：默认为... |
| 14 | [《避邪阵》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4770.html) | 世人看我太疯癫★我笑他人神经病∵ | 6.29 | 4★ | 2025-10-10 22:26:02 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4770.html) | 《避邪阵》     四方阵地图把这下好的文件，用WinRAR解压，在把所有的文件点复制找到... |
| 15 | [《青苔阵》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4771.html) | 世人看我太疯癫★我笑他人神经病∵ | 12.89 | 4★ | 2025-10-10 22:28:38 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4771.html) | 《青苔阵》     四方阵地图把这下好的文件，用WinRAR解压，在把所有的文件点复制找到... |
| 16 | [《齐山双佛阵》四方阵地图](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4773.html) | 世人看我太疯癫★我笑他人神经病∵ | 12.89 | 4★ | 2025-10-10 22:34:02 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4773.html) | 《齐山双佛阵》     四方阵地图把这下好的文件，用WinRAR解压，在把所有的文件点复制... |
| 17 | [试炼四方阵加龙纹孟星魂](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4777.html) | 参加我得银趴 | 9.70 | 4★ | 2025-10-15 21:29:25 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4777.html) | 希望流星蝴蝶剑越来越好 |
| 18 | [【地图】官方22图合一](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4783.html) | 一贫 | 30 | 4★ | 2025-11-01 00:14:55 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4783.html) | 解压后覆盖流星根目录即可。局域网列表最后一个名为《官方22图合一》的即是。出生点只设置了一... |
| 19 | [【地图】东海龙宫](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4784.html) | 一贫 | 9 | 4★ | 2025-11-01 14:43:20 | [直达](https://www.lxres.com/DiTuXiaZai/WanJiaZiZhi/4784.html) | 制作动机：依然是仿造B站某UP的水族箱视频，按照它的布局制作了本地图。安装方法：默认为SN... |
| 20 | [龙纹岩壁四方阵](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4793.html) | 唐家笑三少 | 12.05 | 4★ | 2026-01-03 03:14:57 | [直达](https://www.lxres.com/DiTuXiaZai/YuanBanMeiHua/4793.html) | 本图为资源网银趴的地图改版，看起来也蛮舒服，喜欢的星友拿去用。 |

---

### 3.5 【人物武器】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [冷燕-黑色诱惑](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/96.html) | 佚名 | 130.31 | 3★ | 2011-07-23 12:00:00 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/96.html) | 不懂怎么用的请看教程 |
| 02 | [大约40把武器皮肤合集](https://www.lxres.com/RenWuWuQi/WuQiMeiHua/166.html) | yanjou | 4.4 | 3★ | 2009-06-07 20:29:12 | [直达](https://www.lxres.com/RenWuWuQi/WuQiMeiHua/166.html) | 全部大概有40多把我可能以后没什么时间玩流星了,所以这些东西送给有需要的人吧.......... |
| 03 | [【光效动态武器】炎龙之髓](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/517.html) | 【极限Meteor】哑弹 | 458.98 | 3★ | 2010-11-22 00:47:41 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/517.html) | 【光效动态武器】炎龙之髓安装方法作者：【极限Meteor】哑弹第一步放置模型：直接复制cm... |
| 04 | [《孟星魂龙纹装》人物皮肤](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/87.html) | 夜狼尘 | 332.07 | 3★ | 2009-03-29 23:35:24 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/87.html) | 还不懂怎么用的请看教程http://www.lxres.com/help.asp |
| 05 | [流星蝴蝶剑所有武器新模型等等](https://www.lxres.com/RenWuWuQi/WuQiMeiHua/815.html) | 世人看我太疯癫★ | 26.17 | 3★ | 2012-07-17 19:12:41 | [直达](https://www.lxres.com/RenWuWuQi/WuQiMeiHua/815.html) | 《所有流星武器模型皮肤》收集内加宝石..等.等...模型！先把流星目里面的（cmodel）... |
| 06 | [《仙剑三魔剑》武器皮肤、模型](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/81.html) | Pokia,哑巴 | 208.9 | 3★ | 2009-03-29 17:50:48 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/81.html) | 武器皮肤(剑)添加到ctexture.pak里cmodel的文件拖放进流星cmodel文件... |
| 07 | [【动态光效】寒冰剑](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/548.html) | 仇家、追杀 | 4.79 | 3★ | 2011-01-01 20:24:27 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/548.html) | 作者仇家、追杀所属团队极限Meteor把cmodel文件夹里面的文件复制到流星蝴蝶剑安装目... |
| 08 | [一梦江湖（成女&剑）修正版](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1994.html) | 绿苑茶儿 | 1.56 | 3★ | 2023-04-04 23:12:59 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1994.html) | 模型来源：一梦江湖（成女）安装：把pmodel文件夹拷贝到流星根目录，把ptexture.... |
| 09 | [赵云和武器](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/152.html) | 慠眡兲芐 | 1.42 | 3★ | 2009-08-25 21:47:48 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/152.html) | 皮肤是355赵云皮肤不知道谁做的武器我添加了龙的图形还有不知名做的特效我用了组合成赵云武器... |
| 10 | [《流星蝴蝶剑》人物头皮肤](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/718.html) | 世人看我太疯癫★ | 10.75 | 3★ | 2011-12-21 21:32:43 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/718.html) | 《流星蝴蝶剑》全套人物头皮肤就是把你下好的这东西，这个文件ptexture.pak点复制找... |
| 11 | [【动态】闪电黄金轮回锤](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/407.html) | 哑弹 | 2.95 | 3★ | 2010-10-25 13:21:58 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/407.html) | 把cmodel文件夹直接覆盖到流星目录下，把ctexture文件夹里面的图片添加到流星目录... |
| 12 | [生死5旗袍【完美版】1.0](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/2088.html) | 小坤 | 3.28 | 3★ | 2021-08-24 17:27:08 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/2088.html) | 进入游戏选择凤凰即可 |
| 13 | [四武器：剑、忍刀、双刺、匕首](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/630.html) | 踏剑飞扬 | 1019.72 | 3★ | 2011-08-28 16:42:40 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/630.html) | 姜云帆四把武器，其他武器陆续更新w*_*文件放入游戏的cmodel里，，jpg文件导入ct... |
| 14 | [双头血匕首皮肤模型](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/120.html) | 冷月,友情岁月 | 3.24 | 3★ | 2012-02-05 18:05:36 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/120.html) | 把压缩包里面的w1_1.GMC文件复制到流星根目录下cmodel文件夹内替换，吃红宝石就能... |
| 15 | [寒紫月匕首—动态](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/431.html) | 哑弹 | 9.15 | 3★ | 2010-10-19 12:55:21 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/431.html) | 把cmodel文件夹直接覆盖到流星目录下，把ctexture文件夹里面的图片添加到流星目录... |
| 16 | [《迷糊-皮肤大集合》人物皮肤](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/100.html) | 【古墓派】迷糊 | 1.75 | 3★ | 2009-04-09 19:31:00 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/100.html) | 凤凤g兔女郎高寄萍g火舞高寄萍g夜精灵老伯g大圣老香g圣斗士(头没改)冷燕g美少女战士铁胡... |
| 17 | [《冷燕龙纹装》人物皮肤](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/587.html) | 夜狼尘 | 1.19 | 3★ | 2011-07-02 14:40:08 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/587.html) | 把nw001b01.tga和nw001f01.JPG这两个文件放到流星根目录ptextur... |
| 18 | [CS狙击枪](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/218.html) | 哑巴 | 158.91 | 3★ | 2009-09-23 23:21:36 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/218.html) | 按照压缩包的说明安装，进入游戏后选择中庸属性的“火铳”。 |
| 19 | [【动态】雪泓之刃](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/606.html) | sszzb512 | 2.32 | 3★ | 2011-09-01 13:47:33 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/606.html) | 请把“cmodel文件夹”里的文件放到流星目录里的“cmodel文件夹”。把“ctextu... |
| 20 | [死神-内心里的虚-黑崎一护套装](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/211.html) | 傲视天下-曾彬 | 700.45 | 3★ | 2009-09-24 00:22:07 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/211.html) | 后缀为GMC的文件是武器模型文件拖放进流星cmodel文件夹即可后缀为skc的文件是人物模... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [斩岩刀+斩岩枪](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/292.html) | 枫泣魂 | 306.87 | 4★ | 2010-04-14 00:32:05 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/292.html) | 斩岩刀+斩岩枪使用方法将cmodel文件夹里面的4个文件复制到流星蝴蝶剑相应的文件夹cte... |
| 02 | [黑色镰刀——长枪](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/367.html) | 【锤比标大】——哑巴 | 29.21 | 4★ | 2010-08-18 14:56:11 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/367.html) | 【锤比标大】——哑巴作品——黑色镰刀——长枪造型不错，这个可以有。。。哈哈ㄣ幽魂★轮回司 |
| 03 | [帕克](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/408.html) | 宇智波佐助 | 95.41 | 4★ | 2010-10-30 22:46:46 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/408.html) | 把p1.skc、p1_300.skc、p1_800.skc复制到流星安装目录下的pmode... |
| 04 | [修正后的美女](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/574.html) | 曙光-剑诀 | 1.45 | 4★ | 2011-03-24 12:58:19 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/574.html) | p0.skcp，0_300.skc，p0_800.skc，P0.bnc四个文件覆盖流星pm... |
| 05 | [超强pos](https://www.lxres.com/RenWuWuQi/POSE/788.html) | 『流星奇迹』_红双 | 25.11 | 4★ | 2012-03-10 18:15:06 | [直达](https://www.lxres.com/RenWuWuQi/POSE/788.html) | 把P0.POS放进pmodel的文件就可以了，拿去玩单机任务吧，孟星魂秒杀所有电脑人，这下... |
| 06 | [齿枪](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/948.html) | 太阳依然和谐 | 1.81 | 4★ | 2012-11-02 11:09:57 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/948.html) | 此为普通属性长枪，用之前请先备份。此武器严格控制在边界盒之内，无范围问题，请放心使用。请将... |
| 07 | [月白装【王强，老孟】](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/1059.html) | 龍翼夜灬星月 | 319.69 | 4★ | 2013-06-08 09:06:01 | [直达](https://www.lxres.com/RenWuWuQi/RenWuMeiHua/1059.html) | 月白装【王强，老孟】转自其他网站，融合 |
| 08 | [三套装](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1076.html) | 魔域 | 438.41 | 4★ | 2013-06-24 20:23:17 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1076.html) | 本次修改了孟星魂三套服装及人物头像模型：主体可应用于盟主.暗杀【蝴蝶.流星】希望大家喜欢，... |
| 09 | [【NEW】流星新武器之剑（共4种-凝碧-凝霞-凝青-凝霜）【鸢尾花的遗忘】](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1310.html) | 鸢尾花的遗忘 | 4.55 | 4★ | 2017-02-25 12:00:00 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1310.html) | 此说明为流星武器安装通用说明：模型文件★武器都是有模型和贴图组成（文件后缀为.gmc.gm... |
| 10 | [武器模型眼枪](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1430.html) | □ | 321.51 | 4★ | 2017-11-22 12:00:00 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1430.html) | 武器模型眼枪作者：□ |
| 11 | [圣诞麋鹿锤](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1439.html) | □ | 642.12 | 4★ | 2017-11-14 12:00:00 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1439.html) | 圣诞麋鹿锤 |
| 12 | [追龍赤牙（大刀）](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1473.html) | 佚名 | 1.58 | 4★ | 2018-04-20 22:22:48 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1473.html) | 安装方法：将cmodel文件夹里的文件覆盖到流星目录的cmodel文件夹中去将ctextu... |
| 13 | [新流星-孟星魂](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1539.html) | 漠之北 | 2.6 | 4★ | 2019-01-07 21:11:38 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1539.html) | 把“pmodel”文件夹拷贝到“流星根目录”，把“ptexture.pak”文件夹中的文件... |
| 14 | [六道培因—畜生道(男)](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1547.html) | 绿苑茶儿 | 416.12 | 4★ | 2019-02-08 17:44:48 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1547.html) | 模型绑定：绿苑茶儿模型來源:火影忍者疾风传 激斗忍者大战（畜生道） |
| 15 | [無名人物Pose優化包](https://www.lxres.com/RenWuWuQi/POSE/1599.html) | Zack | 141.3 | 4★ | 2019-05-11 21:38:46 | [直达](https://www.lxres.com/RenWuWuQi/POSE/1599.html) | ＊自定義屬性魍魎的效果：1）怒氣凍結（無法使用任何怒氣Pose，無限怒氣外掛失效 ）2）防... |
| 16 | [剑网三明教_杀手](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1673.html) | 中原慕容秋 | 1.63 | 4★ | 2019-11-28 23:37:23 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1673.html) | 安装：把pmodel文件夹拷贝到流星根目录，把ptexture.pak文件夹中的贴图导入到... |
| 17 | [天国九州镇(变形前和变形后)](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1796.html) | 魔域 | 870.78 | 4★ | 2020-07-18 21:28:47 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiWuQi/1796.html) | 模型提取自天下3网游，自行替换原文件即可(注意备份) |
| 18 | [刀妹.玉剑仙](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1871.html) | 明天，明天！ | 798.96 | 4★ | 2020-11-05 22:18:36 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/1871.html) | 安装：将“模型”文件夹中的文件拷贝到流星根目录下的“pmodel”文件夹中，将“贴图”文件... |
| 19 | [狂热者mod](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/2016.html) | Marine | 416.08 | 4★ | 2021-05-22 21:22:29 | [直达](https://www.lxres.com/RenWuWuQi/ZiZhiRenWu/2016.html) | 把skc文件 放入pmodel 文件夹。把贴图放入ptexture 压缩包里。默认是替换的... |
| 20 | [全近战武器攻击判定修改第三弹](https://www.lxres.com/RenWuWuQi/POSE/2149.html) | 路人 | 24.72 | 4★ | 2021-11-04 20:42:06 | [直达](https://www.lxres.com/RenWuWuQi/POSE/2149.html) | 近战武器修改第三版。修改了所有武器被防有利帧，并修改前版一些问题。 |

---

### 3.6 【主题光影】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [《真·雷神》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/206.html) | heiseqiyue5 | 12.27 | 4★ | 2009-09-19 22:19:30 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/206.html) | 将所有文件覆盖到流星目录即可。请注意备份文件。 |
| 02 | [《真·雷神强化版》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/195.html) | heiseqiyue5 | 12.75 | 3★ | 2009-11-09 22:33:30 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/195.html) | 将所有文件覆盖到流星目录即可。请注意备份文件。 |
| 03 | [新光影特效☆烈火焚天](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/602.html) | 奇人lx梦魂 | 23.09 | 2★ | 2011-05-03 19:01:07 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/602.html) | 新光影特效☆烈火焚天根据武侠风格而做的，很不错。这也是给我单机任务做的。此光影适合用来拍视... |
| 04 | [光影特效完结、](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1792.html) | 余音 | 25.37 | 4★ | 2022-01-13 18:25:36 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1792.html) | 修复所有已知问题，特效基于滴风图像补丁6.2以上，会替换一些武器和p0孟星魂人物pos自带... |
| 05 | [倾城之恋-圣梦蝶效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/521.html) | 【梦幻流星】梦魂 | 28.09 | 3★ | 2011-03-03 22:20:11 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/521.html) | 将ETexture.pak与TexturePatch.pak放进流星目录里。进入游戏就可以... |
| 06 | [盘凰特效-天外飞仙](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/199.html) | 盘凰 | 9.14 | 3★ | 2009-11-09 22:16:42 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/199.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 07 | [《黄金》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/158.html) | 面壁 | 9.36 | 3★ | 2009-09-04 15:45:48 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/158.html) | 很黄很暴力！强烈推荐！ |
| 08 | [盘凰特效-仙剑神曲](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/116.html) | QQ.759194013 | 7.8 | 3★ | 2009-05-13 20:47:41 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/116.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件）本补丁包含特效：所有大小绝招。注：特效文... |
| 09 | [《流星Online》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/119.html) | 杀戮苍穹 | 27.2 | 3★ | 2009-03-21 11:28:53 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/119.html) | 此主题包由隱龍軒&#124;殺戮蒼穹制作主要修改了游戏界面，背景音乐，开场动画等几个小方面... |
| 10 | [动态光效闪电之翼](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/491.html) | 仇家、追杀 | 2.29 | 3★ | 2010-12-01 22:26:16 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/491.html) | 【动态光效闪电之翼】安装方法本道具属于额外制作，安装好了之后请自己放进地图，在地图中的添加... |
| 11 | [《佐助招式美化超炫版》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/141.html) | 415398417 | 3.21 | 3★ | 2008-11-11 00:40:11 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/141.html) | 本补丁包含全部武器特效 |
| 12 | [《幻蝴》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/4.html) | eq2003eq | 5.03 | 3★ | 2008-11-15 19:21:12 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/4.html) | 将所有文件覆盖至游戏目录即可。 |
| 13 | [《火影忍者》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/74.html) | 星梦——魔翼 | 5.91 | 3★ | 2009-03-21 11:26:56 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/74.html) | 把texture和music这两个文件夹拷贝到流星根目录并覆盖! |
| 14 | [光影特效高清版](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/2290.html) | 『流星奇迹』_兵兵 | 51.99 | 3★ | 2023-03-30 00:00:00 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/2290.html) | 将原版特效和部分流星资源网中其他特效包的贴图全部高清化。将每张贴图都进行精心修改，你将不会... |
| 15 | [《魔兽争霸》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/128.html) | xuejun567 | 5.29 | 3★ | 2009-03-21 11:30:16 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/128.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件 |
| 16 | [AI-孙悟空和特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/446.html) | 慠眡兲芐 | 17.04 | 3★ | 2010-11-13 12:39:48 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/446.html) | 用法全部覆盖到1.08流星目录1共2个特效局域网输入AISWK界王拳状态孙悟空攻击方式比较... |
| 17 | [《霸气纵横》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/132.html) | 霸刀无敌 | 612 | 3★ | 2008-11-15 18:22:47 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/132.html) | 本补丁包含全部武器特效 |
| 18 | [招式光影效果美化第四版](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/144.html) | 〓冰茶〓 | 688.22 | 3★ | 2009-03-21 15:32:22 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/144.html) | __说明___________将所有文件覆盖至游戏目录即可。（请注意备份原文件）__作者的... |
| 19 | [灵·翼美化（苍雷版）](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/359.html) | 灵翼 | 4.5 | 3★ | 2010-10-13 13:47:51 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/359.html) | 主色调：苍紫色附带音乐：雷光一闪简介：暗色调的美化，给人沉重的压迫感，在忍烧方面有很强的创... |
| 20 | [若爱特效之龙与魔法阵](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1048.html) | 若爱。请深爱 | 8.33 | 3★ | 2013-04-17 23:40:27 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1048.html) | 准备是版本和特效一起出的，版本体积方面还没有弄好，所以前把特效放出来，ps：希望下载这个特... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [招式光影效果美化第一版](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/135.html) | 〓冰茶〓 | 647 | 4★ | 2008-11-01 13:48:36 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/135.html) | 招式光影效果美化·将ETexture.pak覆盖到流星根目录即可。·建议备份原文件。 |
| 02 | [《真·雷神》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/206.html) | heiseqiyue5 | 12.27 | 4★ | 2009-09-19 22:19:30 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/206.html) | 将所有文件覆盖到流星目录即可。请注意备份文件。 |
| 03 | [指虎加攻击小绝特效修改](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/922.html) | a53132863 | 429.18 | 4★ | 2012-11-17 18:56:30 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/922.html) | 指虎加攻击小绝特效修改将PowUPSlf.ef文件覆盖到SFX里请先备份 |
| 04 | [光影特效完结、](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1792.html) | 余音 | 25.37 | 4★ | 2022-01-13 18:25:36 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/1792.html) | 修复所有已知问题，特效基于滴风图像补丁6.2以上，会替换一些武器和p0孟星魂人物pos自带... |
| 05 | [《幻蝴》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/4.html) | eq2003eq | 5.03 | 3★ | 2008-11-15 19:21:12 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/4.html) | 将所有文件覆盖至游戏目录即可。 |
| 06 | [《仿古界面》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/36.html) | 石头 | 1.89 | 3★ | 2015-06-06 12:00:00 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/36.html) | “《流星蝴蝶剑.net》仿古界面”使用方法：分别将压缩包里的“image”、“textur... |
| 07 | [《火影忍者》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/74.html) | 星梦——魔翼 | 5.91 | 3★ | 2009-03-21 11:26:56 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/74.html) | 把texture和music这两个文件夹拷贝到流星根目录并覆盖! |
| 08 | [《火影精简版》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/83.html) | 415398417 | 12.07 | 3★ | 2009-03-21 11:25:22 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/83.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 09 | [《雷神》特效](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/85.html) | AntaresY | 585.98 | 3★ | 2008-11-15 18:13:36 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/85.html) | 精心修改的流星光影效果包，目前在小组内评价很好，综合了很多效果包，提取精华，加上自己的创作... |
| 10 | [《苍穹》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/101.html) | 殺戮蒼穹 | 18.41 | 3★ | 2008-08-05 12:00:00 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/101.html) | 苍穹主题包作者殺戮蒼穹本主体包直接解压在流星的主要文件夹。由于本主题是修改原文件，所以会覆... |
| 11 | [《仙剑怀古风格》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/106.html) | 〓冰茶〓 | 877.5 | 3★ | 2009-03-21 11:34:58 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/106.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 12 | [《鬼泣4》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/110.html) | lianzhao | 1.82 | 3★ | 2009-03-21 11:23:45 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/110.html) | 直接复制texture文件夹到游戏目录覆盖。注意备份。 |
| 13 | [《蓝色蝶恋》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/113.html) | 〓冰茶〓 | 933.53 | 3★ | 2009-03-21 11:55:13 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/113.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 14 | [《笑傲江湖》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/115.html) | 寻梅 | 3.41 | 3★ | 2009-03-21 11:38:43 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/115.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 15 | [盘凰特效-仙剑神曲](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/116.html) | QQ.759194013 | 7.8 | 3★ | 2009-05-13 20:47:41 | [直达](https://www.lxres.com/ZhuTiGuangYing/GuangYingMeiHua/116.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件）本补丁包含特效：所有大小绝招。注：特效文... |
| 16 | [《流星Online》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/119.html) | 杀戮苍穹 | 27.2 | 3★ | 2009-03-21 11:28:53 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/119.html) | 此主题包由隱龍軒&#124;殺戮蒼穹制作主要修改了游戏界面，背景音乐，开场动画等几个小方面... |
| 17 | [《恨_写轮眼》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/124.html) | eq2003eq | 5.2 | 3★ | 2009-03-21 11:50:03 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/124.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 18 | [《无双大蛇》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/126.html) | wo6363271 | 9.13 | 3★ | 2009-03-21 11:33:18 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/126.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件） |
| 19 | [《魔兽争霸》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/128.html) | xuejun567 | 5.29 | 3★ | 2009-03-21 11:30:16 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/128.html) | 将所有文件覆盖至游戏目录即可。（请注意备份原文件 |
| 20 | [《影视人物》主题包](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/129.html) | 狂龙 | 16.14 | 3★ | 2009-03-21 11:41:52 | [直达](https://www.lxres.com/ZhuTiGuangYing/ZhuTiMeiHua/129.html) | 无聊啊！狂龙本人是个非常喜欢玩RPG游戏的菜鸟～而且也非常喜欢看武侠小说！放暑假了！为了纪... |

---

### 3.7 【资料教程】资源榜单与生态归类

#### 1. 热门榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [阿一修改宝典V0.99](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/39.html) | 杀手阿一 | 1.25 | 3★ | 2008-10-22 15:23:04 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/39.html) | 流星蝴蝶剑相关修改，相关资料 |
| 02 | [大刀极限连招](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/1374.html) | 无聊啊 | 342.91 | 3★ | 2017-04-07 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/1374.html) | 大刀极限连招解压后拷贝到流星根目录 |
| 03 | [魔尊修改宝典V1.1](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/138.html) | 魔尊 | 906.98 | 3★ | 2008-11-01 13:46:52 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/138.html) | 流星蝴蝶剑相关修改，相关资料 |
| 04 | [流星蝴蝶剑.net 个人地图制作心得2.0.1最终版](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1931.html) | 过山河。 | 65.8 | 4★ | 2022-09-05 01:07:46 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1931.html) | 个人制作地图的基本心得，包含涉及到地图制作的很多问题。详细参考docx文件，带索引关键字查... |
| 05 | [幻风修改宝典V1.15](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/33.html) | 幻风 | 558.06 | 3★ | 2008-11-01 13:44:59 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/33.html) | 流星蝴蝶剑相关修改，相关资料 |
| 06 | [《流星蝴蝶剑》官方壁纸](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/6.html) | 昱泉国际 | 2.09 | 3★ | 2015-08-21 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/6.html) | 昱泉公司发布的24张《流星蝴蝶剑》官方壁纸。 |
| 07 | [流星天书 V1.0](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1274.html) | 佚名 | 263.68 | 3★ | 2017-02-10 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1274.html) | 流星天书V1.0 |
| 08 | [人物贴图美化教程](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1575.html) | 烈酒×杀意 | 207 | 2★ | 2019-03-18 23:29:41 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1575.html) | 人物贴图美化教程 |
| 09 | [[9.07]剑扫地教程+飘绝教程](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/389.html) | 伤魂血魄 | 7.32 | 3★ | 2010-10-02 13:54:48 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/389.html) | 方法将*.mrc文件放到流星目录下， S*的文件放在music里 替换 原文件进入游戏选择... |
| 10 | [地图制作教程](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1148.html) | 罗布 | 149.28 | 4★ | 2013-09-08 11:23:39 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1148.html) | 你想学地图制作吗？你想在流星蝴蝶剑中完成自己的创作吗？这份制作教程是我中午抽空做出来的时长... |
| 11 | [流星笔记](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/607.html) | 漠之北 | 7.09 | 3★ | 2011-09-10 12:46:20 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/607.html) | 内置软件：UltraEdit-32、ACDSEE、Dup2.09、给右键增加“用记事本打开... |
| 12 | [超帅皮肤、地图，内附预览图](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/752.html) | 小二逼 | 35.62 | 3★ | 2012-05-16 11:14:15 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/752.html) | 超帅皮肤、地图，内附预览图.zip┃┣━冷艳┃┣━冷艳绿鳞丝绸装.zip┃┣━小二逼冷艳红... |
| 13 | [50张轻功教学图片_优ya出品](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1290.html) | 优ya | 4.47 | 3★ | 2017-01-30 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1290.html) | 50张轻功教学图片 |
| 14 | [mc修改全教程](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/2423.html) | 拔苗组长 | 19.45 | 3★ | 2022-12-21 10:59:25 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/2423.html) | 流星界面是根目录里的MC文件夹里的mcb文件控制的，界面UI中的各元素对象，其大小、位置、... |
| 15 | [洛阳城轻功教学](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/59.html) | 七夜の格杀勿论 | 717.23 | 3★ | 2009-04-26 23:37:34 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/59.html) | 录象名称洛阳城轻功教学飞支持版本9.07游戏模式其他视角人物七夜の格杀勿论录象性质教学 |
| 16 | [Game Expert](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/123.html) | 董雪强 | 725.86 | 3★ | 2009-04-14 18:42:24 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/123.html) | 一、功能描述GameExpert是一个用来在游戏中帮助您快速通关的工具软件，可以用它来查找... |
| 17 | [流星蝴蝶剑-凤凤专辑](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/2618.html) | 太刀小妹 | 176.21 | 3★ | 2024-05-20 21:58:10 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/2618.html) | B站视频https://www.bilibili.com/video/BV14J4m1N7... |
| 18 | [新动作制作教程](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/973.html) | 罗布 | 198 | 3★ | 2013-10-01 20:39:26 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/973.html) | 你想动手制作动画吗？你想随心所欲用招式吗？	本教程满足你所有要求~~~~~~	此教程虽为无... |
| 19 | [流星修改宝典-Final(Part1-2)](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1203.html) | ADSL12203 | 21.37 | 3★ | 2014-04-08 23:23:48 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1203.html) | 作者：LX_ADSL(旧名：ADSL12203)教程：进阶综合应用基本上，要学这宝典前，必... |
| 20 | [流星修改宝典-NPC篇](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1221.html) | ADSL12203 | 3.7 | 3★ | 2014-03-09 12:10:59 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1221.html) | 作者：LX_ADSL(旧名：ADSL12203)教程：NPC制作及修改,任务编写及制作,R... |

#### 2. 评分榜 Top 20
| 排名 | 资源名称 | 作者 | 文件大小 | 评级 | 更新日期 | 链接 | 核心特色与技术说明 |
| :---: | :--- | :--- | :--- | :---: | :--- | :--- | :--- |
| 01 | [地图制作教程](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1148.html) | 罗布 | 149.28 | 4★ | 2013-09-08 11:23:39 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/1148.html) | 你想学地图制作吗？你想在流星蝴蝶剑中完成自己的创作吗？这份制作教程是我中午抽空做出来的时长... |
| 02 | [流星蝴蝶剑.net 个人地图制作心得2.0.1最终版](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1931.html) | 过山河。 | 65.8 | 4★ | 2022-09-05 01:07:46 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/1931.html) | 个人制作地图的基本心得，包含涉及到地图制作的很多问题。详细参考docx文件，带索引关键字查... |
| 03 | [手机玩电脑流星蝴蝶剑联机教程](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/2451.html) | ace | 24.42 | 4★ | 2023-03-03 03:06:27 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/ShiPinJiaoCheng/2451.html) | 手机玩电脑流星蝴蝶剑联机教程a手机玩电脑流星蝴蝶剑联机教程 交流开黑群 174766469... |
| 04 | [《流星蝴蝶剑》官方壁纸](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/6.html) | 昱泉国际 | 2.09 | 3★ | 2015-08-21 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/6.html) | 昱泉公司发布的24张《流星蝴蝶剑》官方壁纸。 |
| 05 | [飞轮无限跳](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/8.html) | 龙·云枫 | 3.47 | 3★ | 2009-04-28 13:45:14 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/8.html) | ========录像说明========《飞轮无限跳》技巧由“七天微笑七天死亡”传授！有一... |
| 06 | [幻风修改宝典V1.15](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/33.html) | 幻风 | 558.06 | 3★ | 2008-11-01 13:44:59 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/33.html) | 流星蝴蝶剑相关修改，相关资料 |
| 07 | [阿一修改宝典V0.99](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/39.html) | 杀手阿一 | 1.25 | 3★ | 2008-10-22 15:23:04 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/39.html) | 流星蝴蝶剑相关修改，相关资料 |
| 08 | [WinHex 14.2 SR-3](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/51.html) | X-Ways Software Tech | 1003.67 | 3★ | 2008-04-23 12:00:00 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/51.html) | 个人认为，这个比UE好用多了，而且体积小，强烈推荐使用！WinHex是在其核心的一个普遍的... |
| 09 | [洛阳城轻功教学](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/59.html) | 七夜の格杀勿论 | 717.23 | 3★ | 2009-04-26 23:37:34 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/59.html) | 录象名称洛阳城轻功教学飞支持版本9.07游戏模式其他视角人物七夜の格杀勿论录象性质教学 |
| 10 | [轻功技巧合辑](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/62.html) | 佚名 | 43.06 | 3★ | 2009-04-22 01:26:46 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/62.html) | =======使用说明=======·将压缩包内的文件解压到流星根目录，然后更新游戏至1.... |
| 11 | [接管主机录象表演](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/73.html) | 佚名 | 37.44 | 3★ | 2009-04-10 01:52:19 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/73.html) | 传说中的接管主机外挂可惜本人没见过 |
| 12 | [JPG图片批量压缩助手](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/90.html) | 佚名 | 310.92 | 3★ | 2009-04-14 16:49:35 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/90.html) | 我一直用来压缩JPG格式图片，非常不错的软件。BMP位图压缩后貌似有损坏。 |
| 13 | [Trainer Maker Kit](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/112.html) | 佚名 | 825.26 | 3★ | 2009-04-21 02:03:05 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/112.html) | 外挂修改器制作。当然，你要有一点点编程基础。 |
| 14 | [Game Expert](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/123.html) | 董雪强 | 725.86 | 3★ | 2009-04-14 18:42:24 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/123.html) | 一、功能描述GameExpert是一个用来在游戏中帮助您快速通关的工具软件，可以用它来查找... |
| 15 | [魔尊修改宝典V1.1](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/138.html) | 魔尊 | 906.98 | 3★ | 2008-11-01 13:46:52 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/138.html) | 流星蝴蝶剑相关修改，相关资料 |
| 16 | [地图漏洞进入法](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/149.html) | 佚名 | 338.68 | 3★ | 2009-04-22 01:22:36 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/149.html) | =====使用说明=====·将压缩包内的文件解压到流星根目录，然后更新游戏至1.07版本... |
| 17 | [《流星·蝴蝶·剑》小说](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/170.html) | 古龙 | 341.93 | 3★ | 2009-08-24 11:11:35 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/170.html) | 流星的光芒虽短促，但天上还有什么星星能比它更灿烂、更辉煌！当流星出现的时候，就算是永恒不变... |
| 18 | [Trainer Maker Kit使用简单教程](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/192.html) | 佚名 | 2.14 | 3★ | 2009-10-29 13:22:50 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/WenBenZiLiao/192.html) | 汉化版学习用，制作修改器请用英文原版。原英文版下载地址：http://www.lxres.... |
| 19 | [[9.07]轻功录像](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/256.html) | ★筘子猪★ | 2.07 | 3★ | 2010-07-22 22:20:52 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/256.html) | 轻功录像支持版本9.07作者：★筘子猪★作者QQ9764787YY频道(189009)感谢... |
| 20 | [[9.07]★筘子猪★教地幻](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/279.html) | ★筘子猪★ | 252.62 | 3★ | 2010-05-28 08:08:29 | [直达](https://www.lxres.com/ZiLiaoJiaoCheng/DuiZhanJiaoXue/279.html) | ★筘子猪★总舵群(85833133)中国·互动歪歪总频道(5926262)本人QQ9764... |

---
