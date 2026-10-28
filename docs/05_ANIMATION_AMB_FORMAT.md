# 《流星蝴蝶剑.net》动画数据文件 (character.amb) 二进制格式逆向解析

> **本条目的判据只有一个：`Meteor.exe` 内的 `FUN_00574460`（载入+头解析）与 `FUN_00574190`（每帧解析）。**

## 一、 两个格式、两种打开模式

`FUN_00574460` 先取文件名**最后一个字符**判断走哪条路：

```asm
0057447e  MOV AL,byte ptr [ECX + EDX - 1]   ; 文件名末字符
00574482  CMP AL,0x62      ; 'b'
00574484  JZ  0x00574499
00574486  CMP AL,0x42      ; 'B'
00574488  JZ  0x00574499
; ---- 非 b/B：.amc ----
00574492  PUSH 0x5ca380    ; "rt"    ← 文本模式
; ---- b/B：.amb ----
005744a1  PUSH 0x5c4580    ; "rb"    ← 二进制模式
```

| 扩展名 | 打开模式 | 魔数 | 每帧有 `startFlag`/`key` | 帧数据读法 |
| :--- | :--- | :--- | :--- | :--- |
| **`.amb`** | `"rb"` **二进制** | `"BANIM"` | **有** | `fread` 定长 |
| `.amc` | `"rt"` 文本 | — | 无（两项 `fseek` 跳过） | `fscanf("%f")` / `fscanf("%s")` |

**`character.amb` = BANIM 二进制**（昱泉私有格式）：
`_strncmp(header, "BANIM", 5)`（`0x5d18c0` = `"BANIM"`），不匹配则整函数返回 0。

---

## 二、 文件头（**21 字节**）

`FUN_00574460` @`0x00574509`–`0x00574581` 的读取序列：

| 顺序 | 长度 | 字段 | 落点 | 说明 |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 5 | `magic` | 栈缓冲 | `"BANIM"`，`memcmp` 校验 |
| 2 | 4 | `boneCount` | `[obj+0x0C]` | 骨骼总数（**含根骨骼**） |
| 3 | 4 | `dummyCount` | `[obj+0x10]` | 挂点数（`d_wpnR` / `d_wpnL` 等） |
| 4 | 4 | `frameCount` | `[obj+0x04]` | 总帧数 |
| 5 | 4 | `frameRate` | `[obj+0x08]` **float** | 读入为 int32，经 `FILD` + `FSTP` 转存为 **float** |

```asm
0057457a  FILD dword ptr [ESP + 0x50]    ; int32
00574581  FSTP float ptr [ESI + 0x8]     ; 存为 float ← 是帧率，不是"读了不用"
```

> **字段顺序注意**：文件里是 `bone, dummy, frame, frameRate`，而内存落点是 `0x0C, 0x10, 0x04, 0x08`——
> 顺序被打乱了（BC++ 编译器按结构体成员重排）。**写解析器必须按文件顺序读，别按内存偏移读。**

---

## 三、 每帧数据（文件视角）

`FUN_00574190`（707 B）逐帧解析，参数含 `isAmb`（即上面的 b/B 判定）。

```asm
00574301  isAmb == 1  →  fread 按定长；== 0（.amc）→ fscanf 文本
```

### 1. 帧头（**仅 `.amb`**，8 字节）

| 字段 | 类型 | 校验 |
| :--- | :--- | :--- |
| `startFlag` | `int32` | **必须 == `-1`**，否则解析失败（`CMP EAX,-1; JNZ 失败`） |
| `key` | `int32` | 关键帧标记 |

### 2. 骨骼段（`boneCount` 次，**根骨骼与其余骨骼长度不同**）

`FUN_00574190` @`0x005741d2` 处按骨骼索引分叉：

| 骨骼索引 | 每帧 float 数 | 每帧字节 | 内容 |
| :--- | :--- | :--- | :--- |
| **0（根骨骼）** | **7**（`MOV ESI,0x7`） | **28** | **位置 3 + 四元数 4** |
| 1 … n-1 | **4** | **16** | 仅四元数 |

```asm
005741de  MOV ESI,0x7           ; 根骨骼：7 个 float
005741e3  MOV dword ptr [ESP+0x1c],0x3   ; 其中前 3 个是位置
005741f6  LEA ECX,[EAX + ECX*4]          ; 目标 = base + frameIdx*28
...
00574206  SHL EBP,0x4                    ; 非根骨骼：frameIdx*16
```

**根骨骼 7 个 float 的存放顺序（memcpy 目标偏移）**：

| 读入序 | → 内存偏移 | 含义 |
| :--- | :--- | :--- |
| `buf[0..2]` | `+0x10, +0x14, +0x18` | **位置**（3 float） |
| `buf[3..6]` | `+0x00, +0x04, +0x08, +0x0C` | **四元数**（4 float） |

⇒ 内存里根骨骼结构 = `Quaternion(16) + Vector3(12) = 28 字节`，但**文件里位置在前、四元数在后**。

> **这正是流星所有招式带位移（轻功滑行、前冲斩、绝技穿梭）的根源：移动由根骨骼位移驱动（Root Motion）。**

### 3. 挂点段（`dummyCount` 次）

```asm
00574327  PUSH 0x5
0057432a  CALL 0x0050a118      ; fread(buf, 1, 5, fp)  ← 固定跳过 5 字节
```
随后再读 7 个 float（位置 3 + 四元数 4）。

| 项 | 字节 |
| :--- | :--- |
| 文件步长 | **5（跳过）+ 28 = 33** |
| 内存结构 | **36**（`operator_new(count × 0x24)`；前 28 有效，余 8 未用） |

> ⚠️ **33 与 36 都是真值，但属于两个不同对象**：33 是**文件**步长，36 是**内存**分配。
> 混用会把挂点区读进骨骼区（症状：满屏"单位四元数"配天文数字坐标）。

### 4. 单帧总长（文件）

```
amc:  0                                  + (bones 按索引 7/4) + dummies × 33
amb:  8 + (bones 按索引 7/4) + dummies × 33
```

---

## 四、 内存结构（供克隆侧对照，非文件格式）

| 数组 | 分配式 | 元素 |
| :--- | :--- | :--- |
| 骨骼指针表 | `operator_new(boneCount × 4)` → `[obj+0x14]` | `boneCount` 个指针 |
| 骨骼 0 数据 | `operator_new(frameCount × 0x1C)` = ×28 | 每帧 `quat(16) + pos(12)` |
| 骨骼 1..n 数据 | `operator_new(frameCount × 0x10)` = ×16（循环内每骨骼一次） | 每帧四元数 |
| 挂点指针表 | `operator_new(dummyCount × 4)` → `[obj+0x18]` | `dummyCount` 个指针 |
| 挂点数据 | `operator_new(frameCount × 0x24)` = ×36（循环内每挂点一次） | 每帧 36，前 28 有效 |

---

## 五、 坐标换算

文件是 **Z-up** 骨骼空间（与 `.bnc` 同源）。原版解析时的轴处理与本项目 `BncParser` 一致：

```csharp
Quaternion C = Quaternion.Euler(-90f, 0f, 0f);   // AxisFix

rootPosition   = new Vector3(-px, py, pz);        // 文件 (x, z, y) → 取反 X
boneRotation   = new Quaternion(r1, -r2, -r3, w); // 文件 (w, x, z, y)
dummyPosition  = (X, Y, Z) → (X, -Z, Y);
dummyRotation  = C⁻¹ · q · C;
```

**X 轴取反**与 `.bnc`（骨架）完全一致 —— 两者同为 Z-up 骨骼局部空间。

---

---

## 七、 与 `.bnc` / `.skc` 的关系

| 文件 | 内容 | 与 `.amb` 的关系 |
| :--- | :--- | :--- |
| `.bnc` | 骨架（骨骼名 + 父子层级 + 绑定姿态） | 与 `.amb` **同为 Z-up**，轴变换公式一致 |
| `.skc` | 模型 + 材质 | 蒙皮目标，不参与轴变换 |
| `.amb` | 动画关键帧（本文件） | 每帧 `boneCount` 组四元数按 `.bnc` 层级逐级相乘 |
