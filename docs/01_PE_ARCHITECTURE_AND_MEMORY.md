# 《流星蝴蝶剑.net》(Meteor.exe 2002) PE 架构与内存全景逆向分析

## 一、 二进制基本指标 (PE Specification)

- **目标二进制**: `C:\Program Files (x86)\Meteor\Meteor.exe`
- **文件体积**: 1,945,600 字节 (1.86 MiB / 1.95 MB)
- **SHA-256 哈希**: `baebb6d59e6da61e03660c57c31f842f8a3ec157f07d1e2f9bf8d78373a58619`
- **MD5 哈希**: `cf2aa5c21a0a687afacc5e5c0876c543`
- **架构**: x86 32-bit Little-Endian (PE32)
- **基地址 (ImageBase)**: `0x00400000` (固定装载基址，无 ASLR / DEP 随机化保护)
- **编译器/链接器**: Microsoft Visual C++ 6.0 / Visual Studio 98 SP5
- **调用约定**: 
  - C++ 类成员函数一律采用 `__thiscall` (ECX 传递 `this` 指针，被调用者栈平衡)
  - 导出/全局 API 函数采用 `__cdecl` 或 `__stdcall`

---

## 二、 内存节表 (Section Layout)

| 节区名 (Name) | 虚拟地址 (VA) | 虚拟大小 (VSize) | 文件偏移 (RawOffset) | 原始大小 (RawSize) | 权限 (Flags) | 用途说明 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Headers** | `0x00400000` | `0x00001000` | `0x00000000` | `0x00001000` | `R--` | DOS / PE 头与节表 |
| **.text** | `0x00401000` | `0x001A62BD` | `0x00001000` | `0x001A7000` | `R-X` | 机器指令执行段 (含 8,754 个程序过程) |
| **.rdata** | `0x005A8000` | `0x0001BE0E` | `0x001A8000` | `0x0001C000` | `R--` | 只读数据、虚函数表 (113 个 VTables)、字符串字面量 |
| **.data** | `0x005C4000` | `0x0022EEF4` | `0x001C4000` | `0x00012000` | `RW-` | 全局变量、未初始化 BSS 缓冲段 |
| **.data1** | `0x007F3000` | `0x000008E0` | `0x001D6000` | `0x00001000` | `RW-` | 扩展动态数据段 |
| **.rsrc** | `0x007F4000` | `0x00003FC8` | `0x001D7000` | `0x00004000` | `R--` | 图标、对话框、版本信息资源 |

---

## 三、 关键全局指针与核心单例 (Core Globals)

| 虚拟内存地址 | 类型 | 标识符 / 符号名 | 占用大小 | 说明 |
| :--- | :--- | :--- | :--- | :--- |
| `0x006659B8` | `GameApp*` | `g_pGameApp` | 4 字节指针 | 游戏全局根单例指针 (`sizeof(GameApp) = 0x2970`) |
| `0x005AA658` | `VTable` | `PlayerController::vftable` | 150 个方法指针 | 角色控制器的虚函数入口表 |
| `0x005A9068` | `VTable` | `GameApp::vftable` | 260 个方法指针 | 主应用程序与渲染管线的虚函数表 |
| `0x005AAB00` | `VTable` | `SceneWorld::vftable` | 283 个方法指针 | 场景 BSP 与物理空间查询的虚函数表 |
| `0x005AA940` | `float` | `kJumpSpeedHigh` | 4 字节 (375.0f) | 默认标准跳跃 / 疾走跳跃初始垂直线速度 |
| `0x005AA93C` | `float` | `kJumpSpeedLow` | 4 字节 (282.0f) | 轻跳 / 小跳初始垂直线速度 |
| `0x005A83F4` | `float` | `kWallJumpUpBias` | 4 字节 (1.0f) | 蹬墙跳法线 Y 轴补偿偏置常数 |
