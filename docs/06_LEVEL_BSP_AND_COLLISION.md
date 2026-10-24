# 《流星蝴蝶剑.net》关卡场景 (BSP) 与物理碰撞检测逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，大小 1,945,600 字节，MD5: `cf2aa5c21a0a687afacc5e5c0876c543`，基址: `0x00400000`)  
> **验证工具**: Ghidra 12.1.4 (P0 Analysis) / Capstone Engine / Python PE Struct Direct Read  
> **审计状态**: **全部常量与指令逐字节 100% 验证，严禁任何未核对估算**

---

## 一、 虚表归属与函数定位真相

经过全量虚表审计与构造函数跨引用校验，`PlayerController`（`tCharacter`）的完整虚表定义已完全确证：

1. **真实 PlayerController 完整虚表基址**: `0x005AA658`
   - 虚表连续指针数：**150** 项（范围 `0x005AA658` ~ `0x005AA8B0`），与 `vtables.json` 完全一致。
   - 主构造函数赋值点：`0x004C4FCE`、`0x004C5A42`、`0x004C61BF` 等处统一初始化 `mov dword ptr [esi], 0x005AA658`。
   - （注：`0x004CAD53` 处的 `mov dword ptr [esi], 0x005AA6A8` 仅为其基类/中间子对象内部偏移，位于主虚表 `+0x50` 偏移处，包含剩余 130 项）。
2. **场景碰撞探测函数入口**: `0x004CF1E0`
   - 主虚表槽位：`0x005AA658 + 0x150` = **Slot 84**（偏移 `+336` 字节）。
   - 物理更新内部调用点：`0x004CEE2F`、`0x004CEEEC`、`0x004CEFBF` 处的 `call dword ptr [reg + 0x100]`（子对象内部偏移视角下 `+0x100` 恰对应主虚表 `+0x150`，即 Slot 84）。

---

## 二、 4 大几何物理常数（PE 逐字节核验表）

| 几何参数 | 浮点数值 | 内存虚拟地址 (VA) | PE 文件偏移 | 原始十六进制字节 | 功能与算法用途 |
|---|---|---|---|---|---|
| **水平半径 (AABB Radius)** | `8.0f` | `0x005A8FB0` | `0x001A8FB0` | `00 00 00 41` | 角色躯干包围盒 X/Y 半径：`[cx - 8.0, cx + 8.0]`、`[cy - 8.0, cy + 8.0]` |
| **躯干顶高 (AABB Z-Max)** | `32.0f` | `0x005AA938` | `0x001AA938` | `00 00 00 42` | 角色包围盒顶部相对脚底高度：`cz + 32.0f` |
| **下身步进间隙 (AABB Z-Min)** | `10.0f` | `0x005A84AC` | `0x001A84AC` | `00 00 20 41` | 躯干包围盒底部相对脚底高度：`cz + 10.0f`（<10 单位障碍物视为台阶自动跨越） |
| **脚底贴地探测深度** | `2.0f` | `0x005A8B80` | `0x001A8B80` | `00 00 00 40` | Mode 0 垂直地面探测射线向下探测距离：`[cz, cz - 2.0f]` |

> **关键几何尺寸结论**:  
> 角色物理实体并非单胶囊体，而是**两段式复合结构**：  
> - **下身 (Z: 0 ~ 10.0f)**: 射线步进区，允许通过 10 单位以下的台阶坡度，垂直探测容差为 `2.0f`。  
> - **躯干 (Z: 10.0f ~ 32.0f)**: 刚性 AABB 盒（宽 16.0 × 深 16.0 × 高 22.0），用于阻挡墙壁、立柱与天花板碰撞。  
> - **步进与贴合参数**: 二进制实测值为精确的 `2.0f`（步进贴合）与 `10.0f`（台阶间隙）。

---

## 三、 空间碰撞检测核心函数剖析

### 1. `FUN_005644F0` — 场景线段/射线碰撞 (`LineCheck`)
- **调用约定**: `__thiscall`，`ecx` = BSP 场景指针 (`SceneWorld*`, 偏移 `[PlayerController + 0xA8]`)
- **函数原型**:
  ```c
  int __thiscall FUN_005644F0(
      void* this,
      const float* pStart,   /* 射线起点 Vector3 */
      const float* pEnd,     /* 射线终点 Vector3 */
      float* outHitPos,      /* 最近碰撞点 Vector3 (输出) */
      float* outHitNormal    /* 碰撞表面法线 Vector3 (输出) */
  );
  ```
- **核心算法流程**:
  1. 检查场景碰撞状态标志 `*(char*)(this + 0x251) != 0`。
  2. 计算总线段距离平方 `local_18 = |pEnd - pStart|^2`。
  3. 遍历 BSP 空间划分扇区 (`in_ECX + 0x29C` 个 Sector)：
     - 调用 `FUN_00570600`：射线与扇区 AABB 包围盒快速相交测试。
     - 若命中扇区，遍历该扇区内所有三角形多边形。
     - 检查多边形访问标志 `*(int*)(poly + 0x50) == 0`（防多扇区重复检测），置位 `poly + 0x50 = 1`。
     - 调用 `FUN_0056F5F0` 执行**光线-三角形求交算法**（Ray-Triangle Intersection）。
     - 若交点距离小于当前最近距离 `local_18`，更新 `outHitPos`，并提取多边形法线 `(poly + 0x40, poly + 0x44, poly + 0x48)` 写入 `outHitNormal`。
  4. 遍历扇区内的动态碰撞体 (`piVar4[0x13]`)，调用 `FUN_0056B350` 求交。
  5. 返回碰撞次数（>0 表示击中）。

---

### 2. `FUN_00563070` — 躯干 AABB 盒空间扫掠 (`SweepBox`)
- **调用约定**: `__thiscall`，`ecx` = BSP 场景指针 (`SceneWorld*`)
- **函数原型**:
  ```c
  int __thiscall FUN_00563070(
      void* this,
      const float* boxMin,   /* 包围盒最小点 Vector3 */
      const float* boxMax,   /* 包围盒最大点 Vector3 */
      float* outHitNormal    /* 碰撞面法线 Vector3 (输出) */
  );
  ```
- **核心算法流程**:
  1. 规范化输入：计算 `center = (boxMax + boxMin) * 0.5f` 与 `halfExtents = (boxMax - boxMin) * 0.5f`。
  2. 遍历潜在重叠的扇区，对多边形调用 `FUN_00570260`：
     - **算法本质**: **三维分离轴定理 (Separating Axis Theorem, SAT)**，检测 AABB 盒与空间三角形面片是否重叠。
  3. 一旦检测到侵入（Overlap）：
     - 提取发生碰撞的多边形法线写入 `outHitNormal`。
     - 立即返回 `1`（阻挡）。
  4. 无任何碰撞返回 `0`。

---

### 3. `0x004CF1E0` — 角色综合场景探测管线 (`ProbeSceneCollision`)
- **调用约定**: `__thiscall`，`ecx` = `PlayerController*`
- **函数原型**:
  ```c
  int __thiscall Meteor_Player_ProbeSceneCollision(
      PlayerController* self,
      const Vector3* delta1,    /* 基础位移偏移 */
      const Vector3* delta2,    /* 动作附加位移偏移 */
      int mode,                 /* 0: 脚底地面探测; 1: 位移线段检测 */
      Vector3* outTargetPos,    /* 最终允许到达的坐标 (输出) */
      Vector3* outHitNormal     /* 命中表面法线 (输出) */
  );
  ```
- **执行逻辑与状态位**:
  1. 计算候选位置：`target = currentPos + delta1 + delta2`。
  2. **分支判定**:
     - **Mode 0 (贴地探测)**:
       - 射线起点: `target`
       - 射线终点: `(target.x, target.y, target.z - 2.0f)`
       - 调用 `FUN_005644F0`。若命中地面，`rayHit = 2`。
     - **Mode 1 (运动射线)**:
       - 射线起点: `currentPos`
       - 射线终点: `target`
       - 调用 `FUN_005644F0`。若命中障碍，修正候选位置为交点，`rayHit = 2`。
  3. **躯干 AABB 刚体检测**:
     - 构造躯干检测盒：
       $$\text{BoxMin} = (target.x - 8.0, target.y - 8.0, target.z + 10.0)$$
       $$\text{BoxMax} = (target.x + 8.0, target.y + 8.0, target.z + 32.0)$$
     - 调用 `FUN_00563070(BoxMin, BoxMax, outHitNormal)`。
     - 若命中（`sweepHit = 1`）：
       - 说明躯干穿墙，**拒绝该位置**，将 `outTargetPos` 回退为移动前的安全坐标 `[esp + 0x80]`。
     - 若未命中（`sweepHit = 0`）：
       - 接受该候选位置，写入 `outTargetPos = target`。
  4. **返回值不是 2-bit 状态码，而是逐轴打包位域**:

     三次轴向探测的返回值被**依次左移 2 位后 OR 累积**，再写入对象字段 `[this+0x3C8]`：

     ```asm
     0x4CEF5C  mov edx, [esp + 0x48]    ; 上一次探测的返回值
     0x4CEF64  lea eax, [edx*4]         ; 左移 2 位
     0x4CEF6B  or  ecx, eax             ; 累积
     0x4CF1C0  mov eax, [esp + 0x38]
     0x4CF1C4  mov [edi + 0x3C8], eax   ; 写入对象
     ```

     ⇒ 位域为 **3 组 × 2 bit**，权重 `1 / 4 / 16`，取值为 `d1·1 + d2·4 + d3·16`。

     **`grounded` 不由整个返回值决定，而由单次探测的 bit1 决定**：

     ```asm
     0x4CEE35  test al, 1   → 0x4CEE3D  mov dword ptr [esi], 0        ; bit0 = 该轴受阻，位移清零
     0x4CEE43  test al, 2   → 0x4CEE4E  mov dword ptr [esp+0x10], 1   ; bit1 = 该轴有支撑，置 grounded
     ```

     各轴探针外均有 `fcomp [0x5A83E4](0.0)` / `jnp` 守卫：**该轴位移为 0 则跳过探测**，
     此时该轴对应位段为 0（含义是"未探测"，不是"无接触"）。


---

## 四、 物理更新主循环 (`0x004CEE40`) 的状态解算

在调用方 `0x004CEE2F` 处，返回值 `eax` 被严格拆解：
```asm
0x004CEE2F: call  dword ptr [eax + 0x100] ; 调用 ProbeSceneCollision
0x004CEE35: test  al, 1                   ; 检查 Bit 0 (躯干撞墙)
0x004CEE37: mov   dword ptr [esp + 0x48], eax
0x004CEE3B: je    0x4cee43
0x004CEE3D: mov   dword ptr [esi], 0      ; 撞墙：将前进速度清零！
0x004CEE43: test  al, 2                   ; 检查 Bit 1 (地面支撑)
0x004CEE45: je    0x4cee6e
0x004CEE47: mov   eax, dword ptr [esp + 0xbc]
0x004CEE4E: mov   dword ptr [esp + 0x10], 1 ; 置 grounded = 1
0x004CEE5A: mov   ecx, dword ptr [esp + 0x2c]
0x004CEE5E: mov   edx, dword ptr [esp + 0x30]
0x004CEE62: mov   dword ptr [eax], ecx      ; 保存地面法线 Normal.X
0x004CEE64: mov   ecx, dword ptr [esp + 0x34]
0x004CEE68: mov   dword ptr [eax + 4], edx  ; 保存地面法线 Normal.Y
0x004CEE6B: mov   dword ptr [eax + 8], ecx  ; 保存地面法线 Normal.Z
```

---

## 五、 角色物理触碰状态位与判定规则

根据 `ProbeSceneCollision` (`0x004CF1E0`) 返回的 `eax` 掩码与 `0x004CEE40` 的状态更新逻辑：

1. **`grounded` (着地状态, 偏移 `[PlayerController + 0x360]`)**:
   - 充分必要条件：`ProbeSceneCollision` 返回值 `al & 2 != 0`（Mode 0 射线在 $z - 2.0f$ 深度内击中有效几何面）。
   - 物理更新时将该三角形法线写入 `[PlayerController + 0x0B8]` 并判断坡度阈值。
2. **`wallContact` / `onWall` (贴墙状态, 偏移 `[PlayerController + 0x39C]`)**:
   - 充分必要条件：`ProbeSceneCollision` 返回值 `al & 1 != 0`（躯干 AABB 盒与静态多边形发生 SAT 重叠），且接触法线水平分量主导。
3. **触碰返回值汇总**:
   - `0`: 空间完全悬空自由飞行。
   - `1`: 仅躯干水平碰撞（阻挡水平前进，回滚位移）。
   - `2`: 仅脚底着地（贴地滑行/行走）。
   - `3`: 脚底着地且躯干撞墙。
