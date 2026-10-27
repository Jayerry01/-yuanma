# 11 · PScript 脚本虚拟机（NPC 行为 / 关卡流程 / 场景物件）

> **证据口径**：本文所有地址与字节均取自 `D:\MeteorRE\Meteor.exe`
> （md5 `cf2aa5c21a0a687afacc5e5c0876c543`，1,945,600 B，已确认与
> `C:\Program Files (x86)\Meteor\Meteor.exe` 为同一文件），
> 以及安装目录原始资源 `Level\*.pst`、`Level\*.wp`、`PScriptLib\*`。
> 反汇编一律连原始字节摘引，可逐字节复核。
>
> **结论等级**：✅ = 有代码/数据硬证据；❓ = 未验证；❌ = 已证伪。

---

## 一、总览：原版没有 C++ AI 状态机，只有一台脚本 VM

`.pst` 不是"配置"，是**一门完整的类 C 脚本语言**，由 exe 内置的解释器执行。
`Level\*.pst`（110 份）驱动 NPC 与关卡流程，`PScriptLib\*.pst`（5 份）驱动可破坏场景物件。

语言实据（`PScriptLib\box.pst`，原文 Big5）：

```c
int g_iNumBoxes = 65;
int g_iBoxHP[g_iNumBoxes];          // 数组，长度由变量决定
int g_bBoxAlive[g_iNumBoxes];

InitBoxes(int num)                  // 函数定义，参数可省略返回类型
{
    int i;  string name;            // 局部变量 + string 类型
    for ( i=1; i<=num; i++ )        // for
    {
        g_bBoxAlive[i-1] = 1;
        MakeString(name, "D_BBox", i);
        int id = GetSceneItem(name, "index");
        SetSceneItem(id, "attribute", "collision", 1);
    }
}
```

**已观察到的语法面**：`int` / `string`、一维数组、函数定义（**返回类型可省略**）、
局部变量声明、`if / else`、`for`、`return`、`/* */` 与 `//` 注释、`#include`、
可变参数调用（`ChangeBehavior(g_self,"patrol",12,15,20)`）。
❓ 是否有 `while` / `switch` / 浮点 / 结构体：未在 114 份脚本中出现，也没有对应语义证据。

---

## 二、两个独立的 VM 实例

| | VM-A（角色 / NPC） | VM-B（场景物件） |
|---|---|---|
| 注册函数入口 | `0x004F8950` | `0x00560A20` |
| `this` 寄存器 | `ESI` | `EDI` |
| 名字池 | `0x5C9FB8`–`0x5CA0E4` | `0x5D1438`–`0x5D14AC` |
| 内建数量 | **26** + 2 钩子 | **11** |
| 共用注册器 | `0x005714E0` | `0x005714E0`（同一个） |

注册器的调用形状在两处完全一致，所以"注册"这一定性是硬的：

```asm
; VM-A，0x004F89A9
004f89a9  68b08d4f00    PUSH 0x4f8db0            ; 处理函数
004f89ae  68c4a05c00    PUSH 0x5ca0c4 ="GetHP"   ; 名字
004f89b3  8bce          MOV ECX,ESI               ; this = VM
004f89b5  e8268b0700    CALL 0x005714e0           ; register(name, fn)

; VM-B，0x00560A35
00560a35  6898145d00    PUSH 0x5d1498 ="SetSceneItem"
00560a3a  8bcf          MOV ECX,EDI               ; this = 另一个 VM
00560a3c  e89f0a0100    CALL 0x005714e0           ; 同一个注册器
```

注册器本体是瘦包装：`005714e0  83c104 e9b8730000 90909090`
（`ADD ECX,0x4` → `JMP`，后接 `NOP` 填充）。

---

## 三、VM-A 内建函数表（26 个 + 3 个角色级钩子）

全部按**注册顺序**摘录，地址即 `PUSH` 的立即数，逐条可复核：

| # | 名字 | 名字 VA | 处理函数 | 注册点 |
|---|---|---|---|---|
| 1 | `GetChar` | `0x5CA0E0` | `0x004F8CD0` | `0x4F8976` |
| 2 | `GetAnyChar` | `0x5CA0D4` | `0x004F8D30` | `0x4F8987` |
| 3 | `GetSelf` | `0x5CA0CC` | `0x004F8D90` | `0x4F8998` |
| 4 | `GetHP` | `0x5CA0C4` | `0x004F8DB0` | `0x4F89A9` |
| 5 | `GetMaxHP` | `0x5CA0B8` | `0x004F8DE0` | `0x4F89BA` |
| 6 | `GetTeam` | `0x5CA0B0` | `0x004F8E20` | `0x4F89CB` |
| 7 | `GetEnemy` | `0x5CA0A4` | `0x004F8E50` | `0x4F89DC` |
| 8 | `GetLeader` | `0x5CA098` | `0x004F8E80` | `0x4F89ED` |
| 9 | `GetGameTime` | `0x5CA08C` | `0x004F8F30` | `0x4F89FE` |
| 10 | `EnableWaypoints` | `0x5CA07C` | `0x004F8EB0` | `0x4F8A0F` |
| 11 | `DisableWaypoints` | `0x5CA068` | `0x004F8EF0` | `0x4F8A20` |
| 12 | **`ChangeBehavior`** | `0x5CA058` | **`0x004F8F60`** | `0x4F8A31` |
| 13 | `Perform` | `0x5CA050` | `0x004F94A0` | `0x4F8A42` |
| 14 | `PlayerPerform` | `0x5CA040` | `0x004F9720` | `0x4F8A53` |
| 15 | `StopPerform` | `0x5CA034` | `0x004F9930` | `0x4F8A64` |
| 16 | `IsPerforming` | `0x5CA024` | `0x004F9A70` | `0x4F8A75` |
| 17 | `SetTarget` | `0x5CA018` | `0x004F9AD0` | `0x4F8A86` |
| 18 | `Distance` | `0x5C68A4`¹ | `0x004F9CA0` | `0x4F8A97` |
| 19 | `Rand` | `0x5CA010` | `0x004F9D20` | `0x4F8AA8` |
| 20 | `GameOver` | `0x5CA004` | `0x004F9D40` | `0x4F8AB9` |
| 21 | `AddNPC` | `0x5C9FFC` | `0x004F9D60` | `0x4F8ACA` |
| 22 | `RemoveNPC` | `0x5C9FF0` | `0x004F9DA0` | `0x4F8ADB` |
| 23 | `UpdateAIAttrib` | `0x5C9FE0` | `0x004F9EB0` | `0x4F8AEC` |
| 24 | `Call` | `0x5C9FD8` | `0x004F9DC0` | `0x4F8AFD` |
| 25 | `Say` | `0x5C9FD4` | `0x004F9EE0` | `0x4F8B0E` |
| 26 | `Print` | `0x5C9FCC` | `0x004FA030` | `0x4F8B1F` |

¹ `Distance` 的名字串在 `.rdata`（`0x5C68A4`），不在 `0x5CA0xx` 那个池里，是唯一的例外。

**三个角色级回调钩子**（不是内建，是脚本提供的入口），
全部经同一个查找器 **`0x005715D0`** 按名取函数：

| 钩子 | 名字 VA | 注册/取用点 |
|---|---|---|
| `OnInit` | `0x5C9FB8` | `0x4F8B66`（VM-A 构造处） |
| `OnUpdate` | `0x5C9FC0` | `0x4F8B5C`（VM-A 构造处） |
| **`OnStart`** | **`0x5C9B10`** | **`0x4BFBD5`**（NPC `.pst` 装载器内，**装载成功后立即调用**） |

```asm
004f8b5c  68c09f5c00    PUSH 0x5c9fc0 ="OnUpdate"
004f8b61  e86a8a0700    CALL 0x005715d0
004f8b66  68b89f5c00    PUSH 0x5c9fb8 ="OnInit"
```

`OnStart` 之所以一度"找不到"，是因为它**不在 `0x5CA0xx` 那个池里**，
而在 `0x5C9B10`（紧挨 `"Load NPC %s.pst error"`），且注册发生在**装载器**而非 VM 构造处：

```asm
004bfbcb  50            PUSH EAX                    ; 脚本路径
004bfbcc  e87ffaffff    CALL 0x004bf650             ; LoadPst()  ← "Level\%s_.pst"
004bfbd1  84c0          TEST AL,AL
004bfbd3  741b          JZ 0x004bfbf0               ; 装载失败 → 跳过
004bfbd5  68109b5c00    PUSH 0x5c9b10 ="OnStart"    ; ← 钩子名
004bfbda  8d8b24050000  LEA ECX,[EBX+0x524]         ; ← this = 某对象 +0x524
004bfbe0  e8eb190b00    CALL 0x005715d0             ; ← 同一个按名查找器
004bfbe5  85c0          TEST EAX,EAX
004bfbe7  7407          JZ 0x004bfbf0               ; 脚本没写 OnStart → 跳过
004bfbe9  8b10          MOV EDX,dword ptr [EAX]
004bfbeb  8bc8          MOV ECX,EAX
004bfbed  ff5204        CALL dword ptr [EDX+0x4]    ; ← 经虚表 +0x4 调用
```

第二处引用在 `0x005038E3`（行为区），同样是 `PUSH "OnStart"` → `CALL 0x005715D0`。

> 调用约定已确认：`0x5715D0` 返回一个对象，调用方走 **`[EAX]` 虚表的 `+0x4` 槽**。
> 这是脚本函数在二进制里的统一调用形态。

---

## 四、`ChangeBehavior`：这才是"AI 状态机"的真身

`0x004F8F60` 不是查表，是**一串线性 `strcmp`**（`SCASB.REPNE` 求长 + `CMPSB.REPE` 比内容），
顺序即优先级：

```
wait > idle > run > follow > patrol > attacktarget > kill > dodge
```

共 **8 个行为**。每个分支的形状：

```asm
; "wait" 分支，0x004F8FCD
004f8fcd  bf1ca15c00    MOV EDI,0x5ca11c ="wait"
004f8fd7  8b542410      MOV EDX,dword ptr [ESP+0x10]
004f8fdb  f2ae          SCASB.REPNE ES:EDI          ; strlen
004f8feb  49            DEC ECX
004f8fee  2bc2          SUB EAX,EDX
004f8ff0  7524          JNZ 0x004f9016              ; 长度不等 → 下一个
004f8ff2  bf1ca15c00    MOV EDI,0x5ca11c ="wait"
004f8ffb  f3a6          CMPSB.REPE ES:EDI,ESI       ; 内容比较
004f8ffd  7517          JNZ 0x004f9016              ; 不等 → 下一个
004f8fff  8bcb          MOV ECX,EBX
004f9001  e8fa490000    CALL 0x004fda00             ; ← 先停掉当前行为
004f9006  6870395000    PUSH 0x503970               ; ← 行为对象
004f900b  8bcb          MOV ECX,EBX
004f900d  e89e450000    CALL 0x004fd5b0             ; ← 装载新行为
```

### 行为名 → 行为对象

| 行为名 | 名字 VA | 行为对象 | 装载器 | 额外动作 |
|---|---|---|---|---|
| `wait` | `0x5CA11C` | `0x503970` | `0x4FD5B0` | — |
| `idle` | `0x5CA114` | `0x5039F0` | `0x4FD5B0` | — |
| `run` | `0x5CA110` | `0x503D00` | `0x4FD5B0` | — |
| `follow` | `0x5CA108` | `0x503B30` | `0x4FD5B0` | 有/无附加参数两条路径（`0x4F90F9` / `0x4F9163`） |
| `patrol` | `0x5CA100` | `0x503A00` | `0x4FD5B0` | **把多余参数灌进路点表**（见下） |
| `attacktarget` | `0x5CA0F0` | `0x504A70` | `0x4FD630` | 槽位号须 ∈ [0,10)；把 `TargetPos[槽]` 拷进 `+0xD4`（详见 §十一） |
| `kill` | `0x5C9858` | `0x504670` | `0x4FD630` | — |
| `dodge` | `0x5CA0E8` | `0x504560` | `0x4FD630` | 结果写入 `[this+0x74]` |

`0x4FD5B0` 首字节 `568bf18b460c85c07459`（`PUSH ESI; MOV ESI,ECX; MOV EAX,[ESI+0xC]; TEST`），
`0x4FD630` 首字节 `6aff68913d5a0064a1`（`PUSH -1` + SEH 帧）— 两者都是真函数，前者 2 参、后者带 SEH。

### `patrol` 的可变参数 = 路点索引（重要）

```asm
004f91a3  8b4504        MOV EAX,dword ptr [EBP+0x4]   ; argc
004f91a6  bf02000000    MOV EDI,0x2                   ; 从第 3 个参数开始
004f91ab  3bc7          CMP EAX,EDI
004f91ad  7e4c          JLE 0x004f91fb                ; argc<=2 就跳过
004f91af  8db308010000  LEA ESI,[EBX+0x108]           ; ← 路点容器
004f91b8  8b0cb8        MOV ECX,dword ptr [EAX+EDI*0x4]
004f91be  668b5108      MOV DX,word ptr [ECX+0x8]
...
004f91d3  e858cdfbff    CALL 0x004b5f30               ; push_back（扩容分支）
004f91ee  e87db6fcff    CALL 0x004c4870               ; push_back（就地分支）
004f91f6  47            INC EDI
004f91f7  3bf8          CMP EDI,EAX
004f91f9  7cba          JL 0x004f91b5
004f91fb  68003a5000    PUSH 0x503a00                 ; patrol 行为对象
```

`[EBX+0x108]` 是一个 12 字节的 STL 容器头（`[+0]` 首指针、`[+4]` 大小、`[+8]` 容量），
参数 3..N 被逐个 `push_back` 进去。**所以 `ChangeBehavior(g_self,"patrol",12,15,20)` 的
语义是"沿路点 12→15→20 巡逻"**，路点数据来自 `Level\*.wp`。

### `attacktarget` 的参数块

```asm
004f923a  8b7908        MOV EDI,dword ptr [ECX+0x8]
004f9241  83ff0a        CMP EDI,0xa
004f9244  7d5b          JGE 0x004f92a1                ; 索引 >= 10 → 走错误分支
004f9246  8b74242c      MOV ESI,dword ptr [ESP+0x2c]
004f924a  68704a5000    PUSH 0x504a70
004f9251  e8da430000    CALL 0x004fd630
004f9256  837d0404      CMP dword ptr [EBP+0x4],0x4   ; argc == 4 ?
004f925a  7511          JNZ 0x004f926d
004f9265  898688000000  MOV dword ptr [ESI+0x88],EAX  ; 第 4 参写入 [+0x88]
004f926d  c7868800000000000000  MOV dword ptr [ESI+0x88],0x0
004f9277  8d0c7f        LEA ECX,[EDI+EDI*0x2]         ; idx*3
004f927a  81c6d4000000  ADD ESI,0xd4
004f9280  8d148d58686600 LEA EDX,[ECX*0x4+0x666858]   ; ← 全局参数表
004f928e  8906          MOV dword ptr [ESI],EAX       ; 复制 12 字节到 [+0xD4]
004f9290  8b4a04        MOV ECX,dword ptr [EDX+0x4]
004f9293  894e04        MOV dword ptr [ESI+0x4],ECX
004f9296  8b5208        MOV EDX,dword ptr [EDX+0x8]
004f9299  895608        MOV dword ptr [ESI+0x8],EDX
```

`0x666858` 是一张**按索引 0..9 排列、每项 12 字节**的全局表，
切换 `attacktarget` 时整块拷进角色对象的 `+0xD4`。
✅ **这 12 字节已解** = 目标点表 `0x666858` 的 `TargetPos[槽]`（Vec3，10 槽），见 **§十一**。

---

## 五、动作名词汇表（`Perform` 与玩家输入共用）

> **层次界定（2026-10-28 对账补充）**：本节讲的是**动作名（字符串）→ 动作**这一层，
> 与 `docs/12_COMMAND_PROTOCOL_SPEC.json` 讲的**输入命令通道（cmd 号 → 处理器）**
> 是**上下两层，不是同一张表，也不冲突**：
>
> | 层 | 载体 | 派发器 | 规模 |
> |---|---|---|---|
> | 输入命令通道（下层） | `cmd` 号 `0x31`–`0x34` 等 | `FUN_004BB800`，跳表 `0x004BBFE8` | 51 项，索引 `cmd − 3` |
> | 动作名词汇（本层） | 字符串 `say`/`pause`/`crouch`/… | 中心派发 `0x504C40`–`0x504F60` | 10 个动作名 |
>
> 规格的派发器类虚表 `0x5A9FE0` 经本轮独立复扫 = **225 项**，与规格自称一致；
> 跳表 `0x004BBFE8` 的 **51 项全部落在 `.text`**，两项断言均通过。
> `docs/07` 第 55/68 行记载的 `cmd 0x31`（8 B `{key,pressed}`）与该规格吻合。

`Perform(g_self, "guard")` 里的第二个参数走另一套名字，
而且**与玩家输入用的是同一套词**（`0x4C06xx` 段也在比这些串）：

| 动作名 | VA | 出现在 |
|---|---|---|
| `say` | `0x5C9B7C` | `Perform` `0x4F94F3`；输入 `0x4C06B3`；中心派发 `0x504C67` |
| `pause` | `0x5C9B74` | `Perform` `0x4F9538`；输入 `0x4C06FC`；派发 `0x504CD3` |
| `crouch` | `0x5C9B60` | `Perform` `0x4F958A`；输入 `0x4C07B2`；派发 `0x504E98` |
| `use` | `0x5C9B68` | `Perform` `0x4F960B`；输入 `0x4C0773`；派发 `0x504F03` |
| `block` | `0x5C9B6C` | （池中有，❓ 未见调用点） |
| `guard` | `0x5CA12C` | `Perform` `0x4F9560`；派发 `0x504E24` |
| `faceto` | `0x5CA124` | `Perform` `0x4F95E5`；派发 `0x504BFC` |
| `attack` | `0x5CA384` | 派发 `0x504DC4`；**`.rdata` 也存了一份指针 `0x5AEFD8`** |
| `jump` | `0x5CA38C` | 派发 `0x504D74` |
| `aggress` | `0x5CA394` | 派发 `0x504D2A` |

**这一条很关键**：脚本 `Perform()` 与玩家按键走的是同一个动作词表，
意味着 `docs/07` 记的输入 → 动作映射，和脚本驱动的角色用的是**同一个下游**。
（❓ 具体 ID 数值未解——中心派发器 `0x504C40`–`0x504F60` 里每个名字分支体较长，
需单独一轮。）

`SetTarget` 的目标类型只有两种：`"char"`（`0x5CA140`）与 `"waypoint"`（`0x5CA134`）。

---

## 六、VM-B 内建函数表（场景物件，11 个）

| # | 名字 | 名字 VA | 处理函数 | 注册点 |
|---|---|---|---|---|
| 1 | `SetScene` | `0x5D14A8` | `0x0056C400` | `0x560A21` |
| 2 | `SetSceneItem` | `0x5D1498` | `0x0056BC60` | `0x560A30` |
| 3 | `GetSceneItem` | `0x5D1488` | `0x0056C290` | `0x560A41` |
| 4 | `NetEvent` | `0x5D147C` | `0x0056BBF0` | `0x560A52` |
| 5 | `GameCallBack` | `0x5D146C` | `0x0056BB80` | `0x560A63` |
| 6 | `MakeString` | `0x5D1460` | `0x0056C630` | `0x560A74` |
| 7 | `Output` | `0x5D1458` | `0x0058E140` | `0x560A85` |
| 8 | `Misc` | `0x5D1450` | `0x0056C770` | `0x560A96` |
| 9 | `rand` | `0x5D1448` | `0x0056C960` | `0x560AA7` |
| 10 | `CreateEffect` | `0x5D1438` | `0x0056C9B0` | `0x560AB8` |
| 11 | `GetTeam` | `0x5CA0B0` | `0x0056CB10` | `0x560AC9` |

`GetTeam` 是两个 VM **同名但不同实现**（VM-A `0x4F8E20`，VM-B `0x56CB10`）。

---

## 七、AI 参数全部是脚本全局，不是二进制常量

`0x00501350` 起的函数逐条从 VM 里**按名字取全局整型**：

```asm
005013ac  68c4a25c00    PUSH 0x5ca2c4 ="View"
005013b3  e8a8020700    CALL 0x00571660          ; GetScriptInt(name)
005013d3  68bca25c00    PUSH 0x5ca2bc ="Think"
005013da  e881020700    CALL 0x00571660
005013fa  68b4a25c00    PUSH 0x5ca2b4 ="Attack1"
00501421  68aca25c00    PUSH 0x5ca2ac ="Attack2"
00501448  68a4a25c00    PUSH 0x5ca2a4 ="Attack3"
0050146f  68dc9c5c00    PUSH 0x5c9cdc ="Guard"
00501496  68aca15c00    PUSH 0x5ca1ac ="Dodge"
005014bd  68d49c5c00    PUSH 0x5c9cd4 ="Jump"
```

（每个名字都取两次，❓ 推测一次读当前值、一次读默认值，未验证。）

取数器 `0x00571660` 首字节 `83ec088b412453555685c057`——真函数。

**名字池完整清单**（`0x5CA284`–`0x5CA2C8` + 散落项）：

`Spawn` `0x5CA288` · `Aim` `0x5CA290` · `Burst` `0x5CA294` · `Look` `0x5CA29C` ·
`Attack3` `0x5CA2A4` · `Attack2` `0x5CA2AC` · `Attack1` `0x5CA2B4` · `Think` `0x5CA2BC` ·
`View` `0x5CA2C4` · `HP` `0x5CA284` · `Guard` `0x5C9CDC` · `Dodge` `0x5CA1AC` · `Jump` `0x5C9CD4`

与 `Level\npc01_01.pst` 里的声明**逐字对应**：

```c
int View = 400;  int Think = 40;
int Attack1 = 50; int Attack2 = 30; int Attack3 = 0;
int Guard = 20;  int Dodge = 10;  int Jump = 5;  int Look = 10;
int Burst = 2;   int Aim = 60;    int GetItem = 3;  int Spawn = 53;
int HP = 1000;
```

> **因此 `docs/08` §二 那张"15% / 45% / 85% 难度矩阵"是错的，已撤回。**
> 原版没有难度百分比，只有上面这组**每个 NPC 一份**的整数权重
> （`View` 视距、`Think` 思考间隔、`Attack1/2/3` 三档攻击倾向、`Burst` 爆气等）。
> 想调难度，改 `.pst`，不是改代码常量。

---

## 八、顺带发现：连招输入键串池

`0x5CA1FC`–`0x5CA23E` 是一组 2–4 字节的小串，形状高度一致：

```
lrfb  ll  rr  blr  fff  bbf  lrb  lrf  lr  bff  ff  fb  rl  bf  bb
```

`l/r/f/b` = 左/右/前/后 —— 这是 `docs/07` 记的**连招输入序列**的字符串形式。
❓ 是否被 VM 读取、还是仅供调试输出：未验证（该段紧跟在 `Init` 之后，
且 `0x5CA240` 起是 7 个 `24 5A 5D` 型 4 字节值，疑似指针数组尾部）。

---

## 九、对 `docs/00` §9 的两处更正

| 原记载 | 判定 | 依据 |
|---|---|---|
| 内置 API 含 `PlaySound()` | ❌ **不存在** | 全镜像（`0x5A8000`–`0x5D4000`）搜 `PlaySound` 零命中；114 份脚本零调用 |
| 引擎 VM 位于 `0x004BFCA0`~`0x004C0500` | ❌ **不是入口** | `0x4BFCA0` 处首 4 字节为 `00 00 00 00`，其后 `83c460 c20400` 是**函数尾声**，非 prologue |

真正有据的 VM 相关入口：

| 地址 | 首字节 | 说明 |
|---|---|---|
| `0x004F8950` | `64a100000000` | VM-A 构造 + 注册 26 个内建 |
| `0x00560A20` | — | VM-B 注册 11 个内建 |
| `0x005714E0` | `83c104 e9b8730000` | 内建注册器（两 VM 共用） |
| `0x004BF650` | `8b54240483ec4085d2535556` | `"Level\%s_.pst"` 装载器（665 B） |
| `0x004BF910` | `83ec105355568b74242085f6` | `"Load NPC %s.pst error"` 装载器（748 B） |
| `0x004C2DE0` | — | `"%s.wp"` 路点装载器（1,515 B） |
| `0x004C2C40` | — | `"Waypoints %d\n"`（404 B） |

---

## 十、场景物件 VM 的回调机制（`sprintf` 拼名，2026-10-28 补）

`box.pst` 里那 130 个 `D_BBox01_OnIdle` / `D_Chair05_OnAttack` 不是硬编码的函数名，
而是**运行时用 `sprintf("%s_OnIdle", 物件名)` 拼出来再按名查找**的。

### 10.1 每物件 6 个回调

格式串池：`0x5D15BC`–`0x5D15FF`，拼接器 `CALL 0x00508AE6`，查找器同样是 `0x005715D0`。

| 格式串 | VA | 语义 |
|---|---|---|
| `%s_OnLoad` | `0x5D15F8` | 物件载入 |
| `%s_OnInit` | `0x5D15EC` | 物件初始化 |
| `%s_OnAttack` | `0x5D15E0` | 被攻击（`BoxOnAttack` 类） |
| `%s_OnTouch` | `0x5D15D4` | 被触碰 |
| `%s_OnPickUp` | `0x5D15C8` | 被拾取（掉落物） |
| `%s_OnIdle` | `0x5D15BC` | 空闲每帧 |

```asm
00563ea1  68f8155d00    PUSH 0x5d15f8 ="%s_OnLoad"
00563ea7  e83a4cfaff    CALL 0x00508ae6          ; 拼出 "D_BBox01_OnLoad"
00563eb6  e815d70000    CALL 0x005715d0          ; 按名查脚本函数
00563ec0  68ec155d00    PUSH 0x5d15ec ="%s_OnInit"
00563ec9  e8184cfaff    CALL 0x00508ae6
00563ee4  68e0155d00    PUSH 0x5d15e0 ="%s_OnAttack"
00563eea  e8f74bfaff    CALL 0x00508ae6
```

结果逐个写入 `[EAX+0x34]` 起始的物件记录槽位（`[EDI-4]`、`[EDI]`、…）。

### 10.2 场景级 5 个固定钩子

| 钩子 | VA | 存储槽 | 引用点 |
|---|---|---|---|
| `Scene_OnLoad` | `0x5D164C` | `[EBX+0x6C4]` | `0x563E0B` |
| `Scene_OnClose` | `0x5D163C` | `[EBX+0x6C8]` | `0x563E28` |
| `Scene_OnInit` | `0x5D162C` | `[EBX+0x6CC]` | `0x563E34` |
| `Scene_OnIdle` | `0x5D161C` | `[EBX+0x6D0]` | `0x563E46` |
| `Scene_OnCharacterEvent` | `0x5D1604` | `[EBX+0x6D4]` | `0x563E58` |

`Scene_OnLoad` 取到后**立即执行**（`0x563E24 CALL [EDX+0x4]`），
与角色侧 `OnStart` 装载即调用是同一套时序设计。

> ⚠️ 读这段汇编时注意 MSVC 的**错峰调度**：`MOV [EBX+0x6C8],EAX` 出现在
> 下一个 `PUSH` 与 `CALL` 之间，所以存储槽要**往前错一位**对齐，
> 不能按书写顺序直接配（照字面配会整体偏移一格）。

---

## 十一、目标点表 `0x666858`（10 槽 Vec3，2026-10-28 解出）

这是 `SetTarget` / `Distance` / `ChangeBehavior("attacktarget")` 三者共用的数据结构。

### 11.1 结构

- **基址 `0x666858`，10 槽 × Vec3（3×float32 = 12 字节），共 120 字节。**
- 位于 `.data` 的**未初始化区**（`.data` raw 只覆盖到 `0x5D6000`），
  ⇒ **文件内容读不出来，全部由运行时填充**。想看数值只能挂调试器。

### 11.2 写入者：`SetTarget`

脚本形态（`Level\*.pst` 实测）：

```c
SetTarget(0, "char", c2);          // 槽 0 = 角色 c2 的位置
SetTarget(1, "char", player);      // 槽 1 = 玩家的位置
SetTarget(0, "waypoint", 119);     // 槽 0 = 路点 119 的位置
```

**第一个参数就是槽位号**（脚本里实际只用 0 和 1）。

`"char"` 分支（`0x4F9B40`–`0x4F9B78`）：

```asm
004f9b45  d90528b85a00    FLD float ptr [0x005ab828]      ; ← 30.0
004f9b4b  8d0c49          LEA ECX,[ECX+ECX*0x2]           ; slot*3
004f9b4e  c1e102          SHL ECX,0x2                     ; *4 → slot*12
004f9b51  83c018          ADD EAX,0x18                    ; 源 = 角色对象 +0x18
004f9b54  8d9158686600    LEA EDX,[ECX+0x666858]
004f9b5a  8b30            MOV ESI,dword ptr [EAX]
004f9b5c  8932            MOV dword ptr [EDX],ESI         ; 拷贝 x
004f9b5e  8b7004          MOV ESI,dword ptr [EAX+0x4]
004f9b61  897204          MOV dword ptr [EDX+0x4],ESI     ; 拷贝 y
004f9b65  8b4008          MOV EAX,dword ptr [EAX+0x8]
004f9b69  894208          MOV dword ptr [EDX+0x8],EAX     ; 拷贝 z
004f9b71  d88160686600    FADD float ptr [ECX+0x666860]   ; ← z += 30.0
004f9b78  d99960686600    FSTP float ptr [ECX+0x666860]
```

`"waypoint"` 分支（`0x4F9BA6`–`0x4F9BE5`）：经 `CALL 0x004C2BF0` 取路点坐标后
直接拷 12 字节，**不加 30.0**。

### 11.3 那个 30.0 是什么

`0x005AB828` = **30.0f**（字节 `00 00 f0 41`，`.rdata` 可读）。

轴向由 `docs/06` 已确证的常量定死：

| 常量 | VA | 值 | 记载 |
|---|---|---|---|
| 躯干顶高 AABB Z-Max | `0x005AA938` | `32.0f` | `cz + 32.0f` |
| 下身步进间隙 Z-Min | `0x005A84AC` | `10.0f` | `cz + 10.0f` |

`docs/06` 写作 **`cz + 32.0f`**，即引擎世界是 **Z-up**，角色全高约 32 单位。
所以 `z += 30.0` = **把目标点抬到角色上身/头部高度**（30 / 32 ≈ 94% 全高）。

两个分支的**不对称**本身就是硬证据：瞄角色要抬高，瞄路点（地面点）不抬。

### 11.4 读取者

| 消费者 | 位置 | 行为 |
|---|---|---|
| `Distance(a,b)` | `0x004F9CA0` | `TargetPos[a] − TargetPos[b]` 求模 → float |
| `ChangeBehavior(...,"attacktarget",slot)` | `0x4F9277` | 把 `TargetPos[slot]` 拷进行为对象 `+0xD4` |

`Distance` 的脚本用法（实测）：

```c
if (Distance(0, 1) < 100)    // 槽 0 与槽 1 的目标点距离 < 100 单位
if (Distance(0, 1) < 400)
```

⚠️ **纠正一个容易想当然的点**：`Distance` 不是"两个角色之间的距离"，
而是**两个目标点槽位之间的距离**。它内部直接读 `0x666858`，
所以必须先 `SetTarget` 写过对应槽位才有意义。

```asm
004f9cbb  d9049558686600  FLD float ptr [EDX*0x4+0x666858]
004f9cc2  d8248558686600  FSUB float ptr [EAX*0x4+0x666858]
004f9cd7  d95c2400        FSTP float ptr [ESP]              ; x 分量
004f9cdb  d94104          FLD float ptr [ECX+0x4]           ; y 分量
004f9ce5  d94108          FLD float ptr [ECX+0x8]           ; z 分量
004f9d0b  e8e04ff8ff      CALL 0x0047ecf0                   ; 向量长度
```

### 11.5 完整语义

```
SetTarget(slot, "char", actor)        → TargetPos[slot] = actor.pos，z += 30.0
SetTarget(slot, "waypoint", wpIndex)  → TargetPos[slot] = waypoint[wpIndex].pos
Distance(slotA, slotB)                → |TargetPos[slotA] − TargetPos[slotB]|
ChangeBehavior(who,"attacktarget",slot[,mode])
                                      → who 的 +0xD4 ← TargetPos[slot]
                                        （argc==4 时再把第 4 参写入 who 的 +0x88）
```

---

## 十二、仍未闭合

| 项 | 状态 |
|---|---|
| ~~`OnStart` 钩子的注册点~~ | ✅ **闭合**（`0x5C9B10` → `0x4BFBD5` / `0x5038E3`，见 §三） |
| ~~场景物件回调名的来源~~ | ✅ **闭合**（`sprintf("%s_OnIdle")` 拼接，见 §十） |
| ~~`0x666858` 那张 12 字节×10 表~~ | ✅ **闭合** = 10 槽目标点表（Vec3），见 §十一 |
| 表中数值本身 | ❌ **静态不可得**（在 `.data` 未初始化区，需运行时读取） |
| ~~`attacktarget` 拷进 `+0xD4` 的 12 字节~~ | ✅ **闭合** = `TargetPos[槽]` Vec3，见 §十一 |
| `attacktarget` 第 4 参写入的 `+0x88` 语义 | ❓ |
| 中心动作派发器 `0x504C40`–`0x504F60` 的动作 ID 数值 | ❓ |
| `block` 动作名的调用点 | ❓ |
| AI 属性"取两次"的含义 | ❓ |
| `0x5CA1FC` 连招键串池的消费方 | ❓ |
| VM 是字节码还是 AST 直解 | ❓ 未见字节码分派特征，倾向 AST/树遍历，无证据 |

---

## 附：本文证据文件

| 文件 | 内容 |
|---|---|
| `evidence/pst_dispatch.txt` | A–O 十五段反汇编（连字节），含 `OnStart`、场景回调拼名块、`SetTarget`、`Distance` |
| `evidence/pst_api_table.txt` | 四组名字池的指针槽扫描 |
| `evidence/pst_builtins.txt` | 从 87 份 `.pst` 抽出的调用词汇 |
| `tools/pe_strings.py` | 按 VA 区间从 PE 原始字节抽串（绕开最小长度过滤） |
| `tools/scan_ptr.py` | 全文件扫 32 位小端指针槽 |
| `tools/ghidra_scripts/PstApiTable.java` | 名字池 → 指针槽 |
| `tools/ghidra_scripts/PstDispatch.java` | 分段反汇编 + 立即数字符串解析 |
| `_install_snapshot/` | 安装目录 `PScriptLib/` + `Level/` 快照（109 文件） |

## 十二、地图脚本头常量：.pst 头部解析与脚本语言面（2026-10-27，社区文档 × 二进制互证）

社区整理的脚本层文档（Rule/RoundTime/PlayerSpawn/PlayerHP、Int/String/数组、
GameOver(±1)、OnStart/OnUpdate、自定义函数）与本仓库二进制侧对榫：

**名表（.data 连续区 0x5C9A74–0x5CA004）**：`PlayerHP@0x5C9A7C`、`PlayerWeapon2@0x5C9A88`、
`PlayerWeapon@0x5C9A98`、`PlayerSpawnDir@0x5C9AA8`、`PlayerSpawn@0x5C9AB8`、
`RoundTime@0x5C9AC4`、`Rule@0x5C9AD0`、`OnStart@0x5C9B10`、`OnUpdate@0x5C9FC0`、
`GameOver@0x5CA004` —— 头常量与事件钩子**按名注册**，社区文档的名单与二进制名表一致。

**头部解析器（`0x4BF8xx` 起）**：逐字段 `push 名字指针; call 0x571660`（**VM 全局按名查找**）
→ 命中则 `mov eax,[eax+8]`（取全局整值）→ 存入关卡对象 `[ebx+0x584/0x588/0x590…]`：
- `PlayerWeapon2` → `+0x584`
- **`PlayerHP` → `+0x588`，缺省 `0x3E8 = 1000`**（`mov dword [ebx+0x588],0x3e8`）——
  **显示血量 = PlayerHP ÷ 10（缺省显示 100），×10 语义获字节铁证**（社区文档说法证实）。

**游戏模式 Rule（社区语义，1=盟主 2=劫镖 3=护城 4=暗杀 5=死斗，<1 或 >5 一律按死斗兜底）**：
模式值由脚本全局 `Rule` 携带（名表已锚），胜利判定侧的 1..5 分支开关未在本轮定位
（`0x4BF884/0x4BF89E` 两处引用实为 PlayerHP 查找，Rule 的读取点待下一轮定位）。

**与既有章节的对接**：
- `PlayerSpawn` = AI 路径点索引——与 §十一 目标点表 `0x666858`、docs/08 路点寻路同源；
- `OnStart/OnUpdate` = §10.2 场景级 5 固定钩子的玩家侧对应；
- 自定义函数/Int/String/数组 = VM 字节码层的既有覆盖（§一/§二），无新增机制。
