# 《流星蝴蝶剑.net》追尾摄像机与粒子特效系统逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，基址: `0x00400000`)  
> **代码来源**: `11_Camera_View_Controller.c` 与 `12_Effect_Particle_System.c`（经 Ghidra 12.1.4 真实反编译）  
> **核心函数定位与状态**:
> - `[待重锚定推断]` `CameraController::UpdateTransform`（追尾摄像机球面坐标积分与跟随；原注 `0x004B6020` 实测为内存池节点分配器，**具体相机函数地址至今仍未锚定**）
> - `[待重锚定推断]` `CameraController::CheckSceneOcclusion`（摄像机防穿墙射线测试）

> ⚠️ **2026-10-28 更正**：§一 的 `180.0f / 40.0f / 5.0f` 三个"相机参数"**均未与相机函数绑定**，
> 其中 `180.0f` 已证伪为**移动速度**（见 **§二·补 A**）；`LineCheck 0x005644F0` 用于相机防穿墙
> 一说**无调用关系支持**（见 **§二·补 B**）。本节其余内容仍属重建推断。
> 已确证的相机实体只剩：控制台 `camera`(ID `0x39`)/`freecam` 命令、以及
> `UNLOCKCAMERA`/`CAMERAUP`/`CAMERADOWN`/`bAutoCamera` 等键位与选项（见 **§二·补 C/D**）。
> - `0x00560970`: 场景与脚本回调注册器（通过 `FUN_005714e0` 将 `"CreateEffect"` 绑定至回调实现 `0x0056C9B0`）
> - `0x00560BF0`: `EffectManager` 标量删除析构器（调用 `0x00560C10` 销毁实例；原注 `0x00560AA0` 实为 `0x00560970` 内部偏移；粒子动力学更新待重锚定）
> - `0x0056E490`: `EffectManager::LoadPonEFFile`（`PonEF V1.00` 二进制粒子描述符加载器）

---

## 一、 第三人称追尾摄像机管线（重建推断参数 · 真实入口待重锚定）

> [!WARNING]
> **真实度降级说明**: 下述 $180.0f$、 $40.0f$、 $5.0f$ 常数在 `.rdata` 节物理存在（`0x005A84C0`, `0x005A8E7C`, `0x005A8F74`），但经反汇编实测，原标注的 `0x004B6020` 实为内存池链表分配器（分配 0x20 字节节点，全程无浮点运算）。因此本节描述属于**尚未与摄像机函数绑定的重建工程推断**（注：`40.0f` 在 `0x004D05EB` 处实测已绑定到角色受击判定，`180.0f` 与 `5.0f` 在场景几何计算中亦有引用，但均未落在该内存池分配例程内）。

1. **球面极坐标系统**:
   - 摄像机目标点: 角色胸口重心（脚底 $+ 25.0f$）。
   - 标准跟随距离: `METEOR_CAMERA_MAX_DISTANCE` = $180.0f$。
   - 视角仰角俯仰限制: 限制在 $[-45^\circ, +75^\circ]$ 之间，避免镜头翻转。
2. **场景防穿墙遮挡算法 (Anti-Clipping)**:
   - 从角色重心点向摄像机理想目标点发射一条射线，调用 `SceneWorld::LineCheck` (`0x005644F0`)。
   - 若射线在半途击中 BSP 场景面，摄像机立即前移至碰撞点前留出 `5.0f`（`METEOR_CAMERA_RAY_CLEARANCE`）的安全距离，最近允许贴近至 `40.0f`。
   - 射线离开阻挡面后，镜头以平滑指数衰减曲线恢复至理想 $180.0f$ 距离。

---

## 二、 粒子特效引擎 (`PonEF V1.00` @ `0x0056E490`)

`Meteor.exe` 内置了完整的轻量级 3D 粒子发射引擎：

1. **文件头与魔数**:
   - 二进制字符串基准: `"PonEF V1.00"`（内存虚拟地址 `0x005D1890`）。
   - 粒子类型包含：聚能光环、喷射火星、拖尾带（Ribbon）、扩散爆破、下落雨滴等。
2. **对象生命周期与析构 (`0x00560BF0` / `0x00560C10`) [粒子动力学更新待重锚定]**:
   - `0x00560BF0` 为 `EffectManager` 标量删除析构器，调用 `0x00560C10` 析构实体并回收内存。
   - 活跃粒子池容量上限与每帧重力/阻尼衰减更新例程待进一步物理重锚定。
3. **渲染模式 (`0x0056EC40`)**:
   - 采用 D3D 视口面向公告板（Camera-Facing Billboard）四边形。
   - 混合模式统一采用 `D3DBLEND_ONE, D3DBLEND_ONE`（加法发光混合）或 `D3DBLEND_SRCALPHA, D3DBLEND_INVSRCALPHA`（常规透明度混合）。

---

## 二·补、入口锚定（2026-10-28）：两条证伪 + 一套新锚

> **相机数学函数本身仍未锚定**，
> 但先把两条站不住的旧记载撤掉，并把确实存在的控制台与配置面坐实。

### A. ❌ 证伪：`METEOR_CAMERA_MAX_DISTANCE = 180.0f`

`0x005A84C0` 确实是 `180.0f`（字节 `00 00 34 43`），但**它不是相机距离，是移动速度**：

```asm
004ccb87  mov eax,[ESP+0x10c]
004ccb8e  test eax,eax
004ccb90  jz 0x004ccb9a
004ccb92  d905c0a85a00  FLD float ptr [0x005aa8c0]   ; 260.0  ← 旗标为真
004ccb98  eb06          JMP 0x004ccba0
004ccb9a  d905c0845a00  FLD float ptr [0x005a84c0]   ; 180.0  ← 旗标为假
004ccba0  d9442430      FLD float ptr [ESP+0x30]
004ccba4  d8c9          FMUL ST1                      ; 方向 × 速度
004ccbbd  d806          FADD float ptr [ESI]          ; += 位置
004ccbbf  d95c240c      FSTP float ptr [ESP+0xc]
```

即 `新位置 = 位置 + 方向 × (旗标 ? 260.0 : 180.0)`。
量级与 `docs/02` 已确证的 `Jump2Velocity = 282` 同族，属**速度**常量。

> 📌 **与 `docs/02` 对账（2026-10-28）**：`docs/02` §? 第 84 行与常量表第 241 行**早已正确记载**
> 这对常量 —— 「**空中冲刺初速度**」，`260.0f`(`0x005AA8C0`) 参数非 0 / `180.0f`(`0x005A84C0`) 参数 0，
> 调用点 `0x004CF5D8`（Case 0 空中冲刺）、`0x4CF5E8` / `0x4CF5EC`。
> 本轮在 `0x4CCB92` / `0x4CCB9A`（旗标取自 `[ESP+0x10c]`）找到的是**同一对常量的第二个站点**，
> 两侧互相印证。**错的只有 `docs/09`**，现已更正。

`180.0f` 全部 4 个读取点：`0x4CCB9C`、`0x4CD4C7`（均在玩家控制器）、
`0x4FD40A`、`0x4FD41B`（行为系统）—— **没有一处落在相机区**。

同理，`40.0f`（`0x5A8E7C`）有 10 个读取点、`5.0f`（`0x5A8F74`）有 12 个，
分布同样在玩家/行为/场景侧。**§一.1 的三个常数全部未与相机函数绑定。**

### B. ❌ 不支持：`SceneWorld::LineCheck (0x005644F0)` 用于相机防穿墙

`0x5644F0` 是真函数（`83ec18 578bf9 897c240c`），用 `tools/scan_call.py` 查得
**9 个直接调用点**：

```
0x4C13AA  0x4CCAC1  0x4CCF5B  0x4CF318  0x4CF38C
0x4F08D5  0x4F6841  0x4F6F0A  0x564A1B
```

全部位于**玩家控制器 / 场景**代码（`0x4C1xxx`–`0x4CFxxx`、`0x4F0xxx`、`0x564xxx`），
无一可归为相机。其中 `0x4CCAC1` 与上面那个 `180.0f` 站点 `0x4CCB9C` **同属一个函数**，
说明 `LineCheck` 主要用于**移动碰撞**，不是镜头射线。

### C. ✅ 新锚一：控制台命令表（`0x4B6280`–`0x4B6560`）

与 `ChangeBehavior` 同构的线性 `strcmp`（`MOV EDI,串` + `MOV ECX,长度` + `CMPSB.REPE`），
命中即返回数字命令 ID。命令名池 `0x5C9800`–`0x5C9894`：

| 命令 | 名字 VA | 命令 ID |
|---|---|---|
| `AI` | `0x5C9860` | `0x18` (24) |
| `mnet` | `0x5C987C` | `0x2F` (47) |
| `kick` | `0x5C986C` | `0x30` (48) |
| `skick` | `0x5C9864` | `0x37` (55) |
| `kill` | `0x5C9858` | `0x38` (56) |
| **`camera`** | `0x5C9850` | **`0x39` (57)** |
| `serverinfo` | `0x5C9844` | `0x3A` (58) |
| `record` | `0x5C7644` | `0x3B` (59) |
| `replay` | `0x5C983C` | `0x3C` (60) |
| `save` | `0x5C9834` | `0x3D` (61) |
| `load` | `0x5C982C` | `0x3E` (62) |
| `loadsn` | `0x5C9808` | `0x01` (1) |
| **`freecam`** | `0x5C9800` | `0x03` (3) |
| `cheat` | `0x5C9810` | `0x2E` (46) |
| `closeserver` | `0x5C9818` | `0x40` (64) |

池内另有（ID 未抽出）：`dcam` `0x5C97F8`、`loadsn`、`host`、
`quit` `0x5C9874`、`position` `0x5C9884`、`fps` `0x5C68A0`。

> `cheat` 分支前有一段门禁：`0x4B658B mov ecx,[EDX+0x2134]` → `test ecx,ecx` → `jno`，
> 不满足则跳过整个 `cheat` 比较 —— 部分命令需要开关才生效。

**`camera` 命令的输出串是 `"Switch Extra Camera."`（`0x5C98AC`）** ——
原版存在一个 **Extra Camera（额外/备用镜头）切换**，由控制台命令驱动。
另有 `freecam` 命令。控制台脚本文件名 `default.mrc`（`0x5C9890`，mIRC 风格）。

> `position`（`0x4B63D8`）就是 §三.4 建议的「原版内置 Position HUD」开关，
> 现在有了地址，可直接用于行为录制对照。

### D. ✅ 新锚二：键位 / 选项名表（`0x5C7A00`–`0x5C7B94`）

| 类别 | 名字 |
|---|---|
| 动作键 | `FORWARD` `BACKWARD` `LEFTSTEP` `RIGHTSTEP` `LEFTTURN` `RIGHTTURN` `DROPITEM` `DROPWEAPON` `SWITCHWEAPON` |
| **相机键** | **`UNLOCKCAMERA`** `0x5C7A2C` · **`CAMERADOWN`** `0x5C7A3C` · **`CAMERAUP`** `0x5C7A48` |
| 相机选项 | `bReverseMouse` `0x5C7ABC` · `bDragMouse` `0x5C7AB0` · **`bAutoCamera`** `0x5C7AF0` |
| 锁定选项 | `bLockFlag` `0x5C7AD8` · `bAutoLock` `0x5C7AE4` |
| 音视频 | `MusicVolume` `AudioVolume` `bCDMusic` `b3DAudio` `bHighAudio` |
| 显示 | `bShowName` `s_heigth` `s_width` `tex_quality` |

消费点集中在两个函数：**`0x45B8xx`**（`0x45B834`/`0x45B8E4`/`0x45B994`/`0x45BAF4`）
与 **`0x45D8xx`**（`0x45D859`/`0x45D880`/`0x45D8A7`/`0x45D8F5`）—— 配置读写/键位设置 UI。

⇒ **原版相机至少有 5 个可调项**：`UNLOCKCAMERA`（解锁镜头）、
`CAMERAUP`/`CAMERADOWN`（俯仰）、`bAutoCamera`、`bReverseMouse`、`bDragMouse`；
锁定相关为 `bLockFlag` / `bAutoLock`。

### E. ✅ 新锚三：相机对象本体（`主对象 +0x2488`）

顺着 `camera`（命令 ID `0x39`）找到它的处理分支 `0x4B6A05`–`0x4B6A3F`：

```asm
004b6a05  mov esi,dword ptr [esi]
004b6a07  mov ebx,dword ptr [EBP+0x2488]     ; ← 取对象首 dword（= vtable 指针）
004b6a0d  lea edi,[EBP+0x2488]               ; ← 取对象地址（注意是 LEA，不是解引用）
004b6a13  push esi
004b6a14  call 0x0050915b                    ; 参数转换
004b6a1c  mov ecx,edi                        ; this = &主对象[0x2488]
004b6a1e  push eax
004b6a1f  call dword ptr [EBX+0x1cc]         ; ← vtable[115] = SwitchExtraCamera
004b6a25  test eax,eax
004b6a27  jz 0x004b785b                      ; 返回 0 → 静默退出
004b6a2d  mov edx,dword ptr [EBP]            ; 主对象 vtable
004b6a30  push 0x0
004b6a32  push 0x5c98ac ="Switch Extra Camera."
004b6a37  mov ecx,ebp
004b6a39  call dword ptr [EDX+0xfc]          ; ← vtable[63] = 输出消息
004b6a3f  jmp 0x004b785b
```

**结论（硬）**：

- 相机对象**以值内嵌**于主游戏对象，偏移 **`+0x2488`**
  （判据：`LEA EDI,[EBP+0x2488]` 作 `this` 传入，同时 `MOV EBX,[EBP+0x2488]` 取出首 dword 当 vtable）
- **该对象 vtable 的 `+0x1CC`（vtable[115]）就是「切换备用镜头」**
- 返回值非 0 时才打印提示，说明切换**可能失败**（例如备用镜头不存在）
- 主对象 `EBP` 的 `vtable[0xFC]`（vtable[63]）是控制台消息输出

`0x2488` 这一偏移在镜像中共出现 139 次；其中 modrm 为 `[EBP+disp32]`
（`0x85 / 0x8d / 0x95 / 0x9d / 0xb5 / 0xbd`）的有 32 处，属同一对象访问。

> ⚠️ 在 `0x4B6B00`–`0x4B7200` 区间统计到 16 个虚表槽被调用
> （`+0x010 +0x024 +0x028 +0x088 +0x090 +0x094 +0x0A0 +0x0A4 +0x0A8 +0x0B8 +0x0EC
> +0x114 +0x12C +0x16C +0x19C +0x244`），但**该统计受寄存器复用污染**
> （EAX/EBX/ECX/EDX/ESI/EDI 都被 `[EBP+0x2488]` 装载过），
> 不能直接当作相机对象的方法表，仅登记备查。

**经交叉验证后，可确认属于相机对象的槽位目前只有 3 个**：

| 槽 | 偏移 | 调用点 | 语义 |
|---|---|---|---|
| `vtable[69]` | `+0x114` | `0x492D96`（转发器）、`0x48D1C4` 附近另有 `+0x18C` | 见下 |
| `vtable[99]` | `+0x18C` | `0x48D1C4`、`0x48D223` | 未定性 |
| `vtable[115]` | `+0x1CC` | `0x4B6A1F` | **SwitchExtraCamera** |

**转发器 `0x492D80`**（外层对象的方法，它把调用扇出给相机与一组同类对象）：

```asm
00492d87  mov edi,ecx                    ; EDI = 外层 this
00492d8a  mov eax,dword ptr [EDI+0x2488] ; 相机对象 vptr
00492d90  lea ecx,[EDI+0x2488]           ; this = &camera
00492d96  call dword ptr [EAX+0x114]     ; ← camera vtable[69]
00492d9c  mov eax,dword ptr [EDI+0x2960] ; ← 另一条链表
00492da2  mov esi,dword ptr [eax]
00492da6  jz 0x00492dc0
00492da8  mov ecx,dword ptr [esi+0x8]
00492dae  call dword ptr [EDX+0x114]     ; ← 对链表每个元素调同一个 vtable[69]
00492db4  mov esi,dword ptr [esi]        ; 链表 next
00492dbc  cmp esi,eax
00492dbe  jnz 0x00492da8
```

⇒ 相机对象**不是孤例**：`[EDI+0x2960]` 上挂着一条用 `+0x0` 作 `next` 的链表，
链上每个元素也会被调 `vtable[69]`。这符合"多镜头/多视口"或"多个可切换相机"的形态。
（此处 `vtable[69]` 以 `[EBP+0x2488]` 对象虚表 **`0x5A9FE0`** 计 = `0x004F0C50`，详见 §F。）

**虚表候选池**：`.rdata` 中 ≥60 项连续代码指针的虚表共 **18 张**，其中 >115 项的有 7 张：

| 虚表 VA | 项数 | `vtable[99]` | `vtable[115]` |
|---|---|---|---|
| `0x005A84D0` | 346 | `0x00462270` | `0x00463020` |
| `0x005AAB00` | 283 | `0x004DC040` | `0x004E4070`（3 字节 `RET 0x4` 桩） |
| `0x005A9068` | 260 | `0x00496980` | `0x00492D80`（**即上面的转发器**） |
| `0x005A9FE0` | 225 | `0x004F1530` | `0x004BB4B0` |
| `0x005AB180` | 185 | `0x004F3D50` | `0x004F25B0` |
| `0x005A98A8` | 158 | `0x004A5540` | `0x004A62B0` |
| `0x005AA658` | 150 | `0x004CE540` | `0x004CB800` |

`0x5A9068` 那张的 `vtable[115]` 就是转发器本身 ⇒ **它是「外层对象」的虚表**，
相机对象的虚表是**另外 17 张之一**，尚未指认。

> ❌ **RTTI 不可用**：全镜像 `.?AV` 类描述符只有 14 个，全是 STL
> （`exception` / `ios` / `streambuf` / `bad_alloc` …），**游戏代码关闭了 RTTI（`/GR-`）**，
> 无法靠类名反查虚表归属。

### F. 未知与最新闭合（2026-10-28 逆向闭环）

| 项 | 状态 | 证明细节 |
|---|---|---|
| ~~`camera`(`0x39`) 的处理分支~~ | ✅ **闭合（双向核验通过）** | `0x4B6A05`–`0x4B6A3F`，调 CameraManager (`0x5A9FE0`) Slot 115 (`+0x1CC` = `0x4BB4B0`)；`0x4BB4B0` 取 `cameras[current_idx]` 尾跳 `jmp [edx+0x44]`（内层相机 Slot 17 = **`0x004F6C70`**，25 字节模式设置器 `SetExtraMode(0/1)`，写入 `camera+0xA0`）；字符串 `0x5C98AC` "Switch Extra Camera." |
| ~~相机对象 vtable 具体是 18 张中的哪一张~~ | ✅ **闭合** | 构造链反查全解：<br>① `BaseCamera`：构造 `0x004F58F0`（0x78B），vtable = **`0x005AB670`**<br>② `ChaseCamera`（追尾相机）：构造 `0x004F5D60`（0xA8B），vtable = **`0x005AB710`**<br>③ `ExtraCamera`（战斗锁视/自由附加相机）：构造 `0x004F7200`（0xB0B），vtable = **`0x005AB7A8`**<br>外层 CameraManager（`[0x6659b8] + 0x2488`）构造 `0x004B96C0`，主虚表 = **`0x005A9FE0`**（`+0x10` 辅虚表 `0x005A9FAC`） |
| ~~追尾相机的**每帧 Update** 方法~~ | ✅ **闭合** | **`ChaseCamera` 虚表 `0x005AB710` Slot 1（`+0x04`）= `0x004F5FA0`**（3,248 字节大函数）。读取高精度计时器（异常串 `0x5C9F9C` "performance counter Error!"），结合跟踪角色 `[esi + 0x80]` 矩阵与视线做障碍裁剪平滑更新；外层 CameraManager 驱动入口为 `Slot 1 (+0x04) = 0x004B9F80` |
| `[EBP+0x2488]` 每实例相机对象的虚表 | ✅ **闭合** | = **`0x005A9FE0`**（CameraManager，其 slot[115]=`0x4BB4B0` 与实读一致）。`0x005AA658`–run 内部 `0x5AA6A8` 起为**控制器类子虚表**（其 slot[75]=`0x4D0500` SetState，同簇含 `0x4D0AC0` ProcessDamage、`0x4CB820` 命令处理〔semqueue 归 07_INPUT〕），故该 run 是玩家控制器类（多子表背靠背），非相机类。 |
| ~~`[EDI+0x2960]` 链表元素类型~~ | ✅ **彻底闭合（2026-10-28 晚解密）** | 证实为 **`std::list<CameraManager*>`（副视口 / 多机位相机管理器链表）**：<br>① 构造于 GameApp 构造函数 `0x00487A67`（`call 0x4A8840`），析构于 `0x00488234`（调各节点 `vtable[0](1)` 虚析构）；<br>② 注册接口 `GameApp::AddCamera(CameraManager*)` = `GameApp` 虚表 `0x005A9068` Slot 145 (`0x005A92AC` = `0x00488330`)；<br>③ 注销接口 `GameApp::RemoveCamera(CameraManager*)` = `GameApp` 虚表 Slot 146 (`0x005A92B0` = `0x004882A0`)；<br>④ 扇出循环共 7 处（`0x492D80` slot[69] `0x004F0C50`、slot[70] `0x492F80`、slot[53] `0x4932AC`、slot[51] `0x4932F8`、slot[38] `0x493351`、slot[88] `0x488146`、slot[45] `0x4881FC`），全量按“先调 `[EDI+0x2488]` 主相机，再遍历 `[EDI+0x2960]` 调副相机同槽虚方法”进行同步驱动。 |
| 追尾相机每帧 Update = `0x004F5FA0`（`0x005AB710` Slot1） | ✅ **闭合** | 297 条 x87 FPU 指令 + 引用 `"performance counter Error!"`@`0x5C9F9C`，与 §F 第 250 行一致。 |
| ~~`40.0f` / `5.0f` 的真实归属~~ | ✅ **闭合（2026-10-28）**：<br>① `40.0f`（`0x5A8E7C`）：在 `ChaseCamera::Update`（`0x004F6BF0`）作为**追尾相机防穿墙最小视距下界（Min Distance Clamp = 40.0f）**，与 `0x004F6B90` 处的最大裁剪界限 `70.0f`（`0x5A8E78`）配对；在 AI 系统（`0x00504AD0`）中作为常规近战攻击判定距离门限。<br>② `5.0f`（`0x5A8F74`）：在 `ExtraCamera::Update`（`0x004F6E8D`）作为角速度平滑乘数（Damping Factor = 5.0f）；在射线求交中作为碰撞安全缓冲距离（Clearance Buffer = 5.0f，见 `tools/verify_camera_floats_40_5_20261028.py`） |
| ~~`freecam`(`0x03`) / `dcam` 的处理分支~~ | ✅ **闭合**（2026-10-28）：<br>① `freecam` (cmd 3)：`0x4B65D1` 匹配字符串，跳表 `0x4B7878` case 3 分支到 **`0x004B6B47`**，调用 CameraManager (`0x5A9FE0`) Slot 103 (`+0x19C` = `0x4BC300`) 传参 `2` 进入自由相机模式，实例挂于 `[esi+0x3D0]`<br>② `dcam` (cmd 4)：`0x4B65EE` 匹配字符串，跳表 `0x4B7878` case 4 分支到 **`0x004B6A44`** |
| ~~特效 `PonEF` 加载器 `0x0056E490` 的调用方~~ | ✅ **闭合**（2026-10-28）：全 .text 唯一调用方确认为 **`0x00566348`**（隶属于特效管理器 `EffectSystem` 的加载接口 `0x005662F0`） |

---

## 三、 参考实现索引：iOS/安卓源码侧的摄像机与特效（2026-10-28）

> 第一节标题里「重建推断参数 · 真实入口待重锚定」是本域此前的自认状态。补充一条可查的线索：
> 第三方重写工程有**完整的摄像机与特效模板实现**，可作为结构假设源。

### 1. 摄像机

| 文件 | 大小 | 作用 |
|---|---|---|
| `.../Assets/Meteor/CameraFollow.cs` | **19,747 B** | 第三人称追尾（对应本域主相机管线） |
| `.../Assets/Meteor/CameraFree.cs` | 14,556 B | 自由视角（观战/调试） |

`CameraFollow` 是本域第一节「追尾摄像机管线」的直接对照物：阻尼、俯仰限位、绕目标旋转的
实现顺序可直接比对。**但相机参数（距离/高度/阻尼系数）与物理常量同性质——重写者调过，
不能当原版值。**

### 2. 特效模板（对应 `PonEF V1.00` @ `0x0056E490`）

| 文件 | 大小 | 作用 |
|---|---|---|
| `.../Assets/Meteor/SFXTemplate/SFXUnit.cs` | **32,062 B** | 特效实例与生命周期 |
| `.../Assets/Meteor/SFXTemplate/SfxMeshGenerator.cs` | 14,021 B | 程序化网格特效（拖尾/刀光） |
| `.../Assets/Meteor/SFXTemplate/SFXEffectPlay.cs` | 13,284 B | 播放调度 |

另有 `.../Assets/Meteor/SkillEvent/CharPoseShadow.cs`（角色残影）。

### 3. 用法与边界

| 项 | 说明 |
|---|---|
| 可用 | 结构、状态划分、参数**种类**（有哪些可调项） |
| 不可用 | 具体数值（重写者自调，见 `docs/00` 第三节物理常量对照） |
| 验证顺序 | 先锚 `0x0056E490` 的入口与调用方（是否随特效 id 派发）→ 再比对模板字段数 |
| 与已解数据的关系 | `Meteor_res_音效招式对照.json`（315 条技能特效名）是 Windows 侧实测，**优先于**源码 |

### 4. 备注

本域与 `docs/04` 的「HitBox 扫掠 / SAT 管线」不同：那部分已有字节级实锚（`0x005706C0`），
本域目前**只有结构与模板**，缺的是入口锚定与参数实测。若要推进，建议先做
`CameraFollow` 的等价行为录制（用原版内置 Position HUD 对照），再把参数逐项落表。
