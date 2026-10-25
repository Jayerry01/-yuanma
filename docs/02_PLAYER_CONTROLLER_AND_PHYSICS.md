# 《流星蝴蝶剑.net》角色物理系统与轻功跳跃底层算法逆向报告（核验校准版）

> **二进制核验状态**: 已逐字节核实（PE 地址基准 `0x00400000`）  
> **反编译与反汇编**: Ghidra 12.1.4 + Capstone 32-bit x86  

---

## 一、 PlayerController 结构体全景内存映射

`PlayerController` 虚表位于 `0x005AA658`，共包含 150 个虚函数指针。关键内部成员偏移如下：

```c
struct PlayerController {
    /* +0x000 */ void*     vptr;           // 指向 0x005AA658 (包含 150 个虚函数)
    /* +0x010 */ void*     transformNode;  // 指向所属角色变换骨骼节点 (CharacterActor = node - 0x65c)
    /* +0x0A8 */ void*     bspCollision;   // 场景 BSP 碰撞树探测器指针
    /* +0x0B8 */ Vector3   wallNormal;     // 碰撞墙面法线 (X: +0x0B8, Y: +0x0BC, Z: +0x0C0)
    /* +0x0D8 */ float     slopeNormalZ;   // 当前接触面法线 Z 分量 (垂直方向)
    /* +0x0DC */ int32_t   moveState;      // 运动状态机 (0=Idle, 1=Ground, 2=Climb, 3..10=Action/Hit, 11=Run)
    /* +0x0E0 */ int32_t   prevMoveState;  // 上一帧状态
    /* +0x0E4 */ int32_t   jumpFlag;       // 起跳阶段标记 (1=起跳/上升期, 0=自由落体)
    /* +0x0E8 */ void*     timerObj;       // 动作与跳跃状态计时器对象
    /* +0x0F0 */ Vector3   inputVector;    // 玩家控制输入方向向量
    /* +0x1D0 */ Vector3   velocity;       // 角色线性移动速度 (X: +0x1D0, Y: +0x1D4, Z: +0x1D8)
    /* +0x34C */ int32_t   combatLocked;   // 招式动作硬直锁 (非0时屏蔽跳跃)
    /* +0x35C */ int32_t   onSlope;        // 地面坡度有效标记 (Normal.z >= 0.42f)
    /* +0x360 */ int32_t   grounded;       // 触地标记: 1 = 着地, 0 = 悬空
    /* +0x390 */ Vector3   jumpVelocity;   // 计算生成的跳跃初速度向量
    /* +0x398 */ float     jumpForceY;     // 跳跃垂直标量 (大跳 375.0f, 小跳 282.0f)
    /* +0x39C */ Vector3   lastContactNrm; // 最近一次碰撞检测法线
    /* +0x3C8 */ uint32_t  contactBits;    // 三轴接触探测打包位域（每轴 2-bit，权重 1/4/16）
};
```

---

## 二、 轻功跳跃 (Jump) 核心算法与入口澄清 (`0x004CF5B0`)

### 1. 函数入口与符号属性澄清
- **`0x004CF540`**: 计时器与跳跃超时回调函数，长度 106 字节，在 `0x004CF5AA` 处以 `ret` 结束，紧跟 5 个 `0x90` (NOP) 填充对齐。
- **`0x004CF5B0`**: **真正的跳跃虚函数入口点**（`PlayerController::vftable[86]`，偏移 `+0x158`），具备独立的栈帧开辟（`sub esp, 0xc`）、寄存器保护与状态派发逻辑。
- **`0x004CF680`**: **不是独立函数入口**，而是 `0x004CF5B0` 内部状态转移表（Jump Table）命中的 **Case 2: 蹬墙反跳分支代码块**。

### 2. 状态转移派发表 (State Lookup Table)
在 `0x004CF75C` 处定义了状态映射表：
```
State Table: [0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 1]
```
- **Case 0 (`0x004CF5D8`)**: 待机/缓动状态，设置起跳标记并启动计时器。
- **Case 1 (`0x004CF60F`)**: 地面跳跃分支（大跳/小跳）。
- **Case 2 (`0x004CF680`)**: 蹬墙反跳分支。
- **Case 3 (`0x004CF604`)**: 攻击/受创/招式硬直，直接返回 `-1` 拒绝跳跃。

### 3. 跳跃速度标定常量
- **大跳 (长按/疾走跳)**: 读取常量 `0x005AA940` = **`375.0f`**
- **小跳 (轻点)**: 读取常量 `0x005AA93C` = **`282.0f`**
- 写入 `jumpForceY` (`fstp dword ptr [esi + 0x398]`)。

### 4. 蹬墙反跳 (Wall Jump, 0x004CF680) 空间几何公式
```c
// 1. 读取碰撞墙面法线 (注意原版坐标系 Z 为向上)
float nx = self->lastContactNrm.x; // [esi + 0x39C]
float ny = self->lastContactNrm.y; // [esi + 0x3A0]
float nz = self->lastContactNrm.z; // [esi + 0x3A4]

// 2. 核心数学法则：在垂直法线分量上叠加上偏常数 1.0f (地址 0x005A83F4)
Vector3 jumpDir;
jumpDir.x = nx;
jumpDir.y = ny;
jumpDir.z = nz + 1.0f; // 常量 1.0f 强行保证蹬墙跳斜向上脱离

// 3. 归一化 (调用 0x0047EC40: Vector3::Normalize)
Vector3_Normalize(&jumpDir);

// 4. 按大跳(375.0f)或小跳(282.0f)缩放
float speed = isHighJump ? 375.0f : 282.0f;
self->velocity.x = jumpDir.x * speed;
self->velocity.y = jumpDir.y * speed;
self->velocity.z = jumpDir.z * speed;
```

---

## 三、 运动物理、受击冲量与碰撞投影 (`0x004D0540` / `0x004CEB50`)

### 1. `FUN_004D0540` 真实功能: 受击浮空与冲量计算 (`PlayerController::OnHit`)
- `0x004D0540` 是角色受击后的击飞冲量与浮空解算核心函数（早期推测中提及的 `"d_wpnR"` 机器码位于 `0x004D076F: 68 cc 92 5c 00`，经反编译确认属于被 Ghidra 按不可达分支 unreachable block 剔除而未进入有效导出的死代码）。
- 其活跃代码直接读取受击接触面法线 $\vec{n}$，并在垂直方向叠加向上仰角偏置 `+0.13f` (`0x005AA944`)，最后整体缩放至绝对速度上限 `600.0f` (`0x005AA934`)：
  $$\vec{v}_{\text{impulse}} = (n_x \times 600.0,\; n_y \times 600.0,\; (n_z + 0.13) \times 600.0)$$
- 随后将冲量向量传入 `FUN_004D1EA0` 进行 3D 动力学积分。

### 2. 真实的物理积分与碰撞更新函数: `0x004CEB50` (`vftable[83]`)
真实的运动积分与碰撞响应在 `0x004CEB50` 中执行：

#### ① 最大速度截断 (`MAX_VELOCITY_CAP = 600.0f`)
在 `0x004CEBE2 - 0x004CEC3E`（其中 `0x004CEBE2` 为截断块入口，浮点比较指令 `fcom` 实际物理地址位于 `0x004CEBE7`）：
```x86
0x004CEBE2: call 0x47ecf0                  ; 计算当前速度模长: length = sqrt(vx*vx + vy*vy + vz*vz)
0x004CEBE7: fcom dword ptr [0x5aa934]      ; 与 0x005AA934 (600.0f) 比较
fnstsw ax
and eax, 0x4100
jne 0x4cec41                               ; 若 length <= 600.0f，不作限制
call 0x47ec40                              ; 若超速，归一化速度向量
fmul dword ptr [0x5aa934]                  ; vx = dir.x * 600.0f
fmul dword ptr [0x5aa934]                  ; vy = dir.y * 600.0f
fmul dword ptr [0x5aa934]                  ; vz = dir.z * 600.0f
```
**`600.0f` 的真实物理含义是角色绝对速度上限 (Speed Cap)，任何冲量叠加均不可超越 600.0！**

#### ② 地面坡度判定 (`SLOPE_COS_THRESHOLD = 0.42f`)
在 `0x004CF001 - 0x004CF092`：
- 接触面法线垂直分量与 `0x005AA92C` = **`0.42f`** 比较。
- $\arccos(0.42) \approx 65.16^\circ$。
- **任何倾角 $\le 65^\circ$ 的表面均判定为可站立地面** (`onSlope = 1`, `grounded = 1`)。

#### ③ 碰撞表面速度投影 (Tangent Projection, 无摩擦损耗)
在 `0x004CF170 - 0x004CF1BD`：
当角色撞击斜坡或墙面时，速度不是做阻力衰减，而是直接**沿切平面投影**：
$$\vec{v}' = \vec{v} - (\vec{v} \cdot \vec{n}) \vec{n}$$
不引入人为阻力衰减，保证滑墙与顺坡滑下的绝对动量守恒。

---

## 四、 角色位移驱动源架构：骨骼根位移 (Root Motion)

在 `Meteor.exe` 中，角色的位移由**动画驱动**与**物理投影**协同完成：

1. **动画根位移驱动 (Root Motion)**:
   - 由 `FUN_00574460`（`character.amb` 解析器）负责处理，Bone 0（Root 骨骼）每帧带有 **28 字节** 位移与旋转曲线。
   - 所有招式冲刺、大跳后摇滑步、招式收招位移，均直接由动画曲线带动。
2. **物理层定位**:
   - 物理层在每帧只负责两件事：
     - 调用 `0x004CF1E0` (`ProbeSceneCollision`) 进行 BSP 场景相交测试。
     - 若发生碰撞，沿接触面切平面进行速度投影 $\vec{v}' = \vec{v} - (\vec{v} \cdot \vec{n})\vec{n}$。
   - 引擎本身不使用任何人为的人工阻力公式衰减初速度，动作的滑步位移完全受控于 `Common/character.amb` 动画帧数据。

---

## 五、 走壁与爬墙系统深度逆向 (`0x004CCCB0` / `0x004CD200`)

### 1. 触发前置条件与时序窗口 (`0x004CCCBB - 0x004CCCFD`)
角色必须同时满足以下条件方可激活挂墙/走壁：
- **前向输入**: `inputForward > 0`（按住 W 键，`[esi + 0x60] > 0`）。
- **跳跃上升期**: `jumpFlag == 1`（`[esi + 0xe4] == 1`），下落期不可触发。
- **垂直初速度**: `jumpForceY > 0.0f`（`[esi + 0x398] > 0`）。
- **起跳最小延时**: 起跳计时器 `GetElapsedTime([esi + 0xf0]) >= 0.1s`（双精度常量 `0x005A8C90` = **`0.1`** 秒），防止起跳即刻贴地误挂。

### 2. 双射线场景碰撞探测 (`0x004CCE15 - 0x004CCF60`)
- **射线探测长度**: `0x005A8458` = **`16.0f`**。
- **Pass 0 (正向主射线)**: 角色当前世界坐标朝向与移动速度方向合成并归一化，向前方发射 `16.0f` 长度射线。
- **Pass 1 (侧向辅助射线)**: 若正向射线未命中，且存在侧向输入 (`inputLateral != 0`)，则沿角色横向侧向量 $\pm \vec{r}$ 发射 `16.0f` 射线。
- 命中判定调用 `SceneWorld::LineCheck` (`0x005644F0`) 对场景 BSP 多边形树求交。

### 3. 接触面对齐与动作方向分类 (`0x004CCF7A - 0x004CD1E4`)
当射线命中墙面多边形时：
1. **重置跳跃标记**: `jumpFlag = 0` (`mov [esi + 0xe4], 0`)。
2. **接触面对齐偏移**: 将碰撞法线反向缩放 `Normal * -18.0f`（常量 `0x005AA8DC` = **`-18.0f`**），写入 `[esi + 0xac]`。
3. **切平面滑移力标定**: 计算切向速度基准，缩放系数 `0x005AA8D8` = **`800.0f`**。
4. **走向动作分类判定**（计算角色朝向与墙面法线夹角 $\theta$）:
   - 若 $0 < \theta < 2.7$（双精度常量 `0x005AA8D0` = **`2.7`**）：触发 **Pose 162**（`0xA2`，左侧走壁）。
   - 若 $-2.7 < \theta < 0$（双精度常量 `0x005AA8C8` = **`-2.7`**）：触发 **Pose 163**（`0xA3`，右侧走壁）。
   - 其余角度：触发 **Pose 161**（`0xA1`，直向爬墙 / 挂墙向上）。
5. **切换状态机**: `moveState` 切入 `2` (`MOVE_STATE_WALL_CLIMB`)。

### 4. 爬墙动力学积分与脱出阈值 (`0x004CD200`, `vftable[77]`)
- **最大爬墙时间**: 双精度常量 `0x005AA8F0` = **`1.8`** 秒。超过 1.8 秒自动滑脱脱出进入自由落体。
- **主动脱出**: 若玩家松开前进键 (`inputForward != 1`)，立即中断爬墙滑脱。
- **爬墙阻尼系数**: 单精度常量 `0x005AA8E0` = **`-1.2f`**（逐帧衰减水平与垂直初动能）。
- **重力调节分量**: 单精度常量 `0x005A83EC` = **`0.1f`**。

---

## 六、 蹬墙反跳动作派发器 (`0x004CCC70`, `vtable[53]`)

在挂墙状态下再次按下跳跃键，`0x004CCC70` 负责将当前走壁/爬墙动作精准映射至对应的反跳动作：

| 当前挂墙动作 (Active Pose) | 映射蹬墙反跳动作 (Kick Pose) | 空间动力学行为 |
|---|---|---|
| **Pose 161** (`0xA1`, 直向爬墙) | **Pose 157** (`0x9D`, 蹬墙后跃 / 腾空后翻) | 沿墙面反法线叠加 `+1.0f` 仰角反向弹射脱离 |
| **Pose 162** (`0xA2`, 左侧走壁) | **Pose 159** (`0x9F`, 蹬墙左侧跃) | 沿左侧切线倾斜反跳 |
| **Pose 163** (`0xA3`, 右侧走壁) | **Pose 160** (`0xA0`, 蹬墙右侧跃) | 沿右侧切线倾斜反跳 |
| 其余未分类状态 | **Pose 151** (`0x97`, 默认垂直跳) | 垂直起跳脱离 |

---

## 七、 四向起跳与滞空下落动作对转换 (`0x004CF770` / `0x004CF7D0`)

角色跳跃动画在引擎中采用「起跳段 + 滞空下落段」的严格双态动作对（Action Pairs）：

1. **四向起跳动作选择 (`0x004CF770`, `vtable[46]`)**:
   - `inputForward > 0` 或无输入 $\to$ **Pose 151** (`0x97`, 前向/垂直起跳)
   - `inputForward == 0 && inputLateral > 0` $\to$ **Pose 153** (`0x99`, 左向侧跳)
   - `inputForward == 0 && inputLateral < 0` $\to$ **Pose 155** (`0x9B`, 右向侧跳)
   - `inputForward < 0` $\to$ **Pose 157** (`0x9D`, 后跃腾翻跳)

2. **升空至滞空下落转换 (`0x004CF7D0`, `vtable[47]`)**:
   - Pose 151 (起跳向前) $\to$ **Pose 152** (`0x98`, 滞空下落向前)
   - Pose 153 (起跳向左) $\to$ **Pose 154** (`0x9A`, 滞空下落向左)
   - Pose 155 (起跳向右) $\to$ **Pose 156** (`0x9C`, 滞空下落向右)
   - Pose 157 (起跳向后) $\to$ **Pose 158** (`0x9E`, 滞空下落向后)

---

## 八、 落地缓冲与受身状态机 (`0x004DEE40` / `0x005AAC50`)

落地触地由 `0x004CEB50` 判定接触面法线 $n_z \ge 0.42\text{f}$ 触发：
- **下落速度阈值**: 单精度常量 `0x005AA918` = **`-40.0f`**。当垂直下落速度 $v_z \le -40.0\text{f}$ 时标记为高空下落。
- **普通落地**: 未达到极限速度或普通跳跃落地，平滑过渡至 **Pose 164** (`0xA4`，落地缓冲短硬直)。
- **重坠硬直**: 极端高空坠落且未输入受身，强制进入 **Pose 167** (`0xA7`，重落地大硬直)。
- **翻滚受身**: 在受创或击飞落地时输入指令，由 `0x004DEE40` 派发进入 **Pose 213** (`0xD5`，倒地翻滚受身 Roll)。
