# 《流星蝴蝶剑.net》安装包 (C:\Program Files (x86)\Meteor) 资产与专有格式逆向规范

> **目标源路径**: `C:\Program Files (x86)\Meteor\` (总计 623.72 MiB (654.02 MB) / 2,113 文件)  
> **逆向工程基准**: 100% 提取自原安装目录内的二进制与数据文件，杜绝任何外部工程数据污染。  
> **核心引擎**: `Meteor.exe` (2002 原版，MD5: `cf2aa5c21a0a687afacc5e5c0876c543`, 1.86 MiB)

---

## 一、 原版安装目录结构全景

```
C:\Program Files (x86)\Meteor\
├── Meteor.exe              # 核心游戏主程序 (1,945,600 字节)
├── config.exe              # 启动分辨率与按键配置器 (192,512 字节)
├── ddfix.dll               # DirectX 8 -> 9 渲染接口封装 (2,958,848 字节)
├── D3DX9_43.dll            # 微软 DirectX 9 扩展运行库
├── *.pak (共 28 个)         # PKZIP 封包（场景/贴图/水体资源）
├── Meteor.res              # MTTM 资源描述文件
├── menu.res                # UI 界面本地化字符串表
├── *.ini / *.cfg           # 运行配置文件
├── Common/                 # 全局角色动作与动画数据
│   ├── character.act       # 招式派生与硬直定义
│   └── character.amb       # 骨骼动画与根位移
├── Level/ (104 文件)        # 武器逻辑与关卡脚本 (*.pst)
├── PScriptLib/ (5 文件)    # 场景可破坏物体脚本与基础头文件 (Def.h, *.pst)
├── sn01/ ~ sn22/           # 22 个关卡场景源文件 (*.cob, *.des, *.gmb, *.pst, *.pvb)
├── cmodel/ (393 文件)      # 场景物件模型与动画 (*.des, *.fmc, *.gmb, *.pos)
├── pmodel/ (128 文件)      # 角色骨骼姿态定位文件 (*.pos, *.amb, *.skn)
├── mc/ (44 文件)           # 剧情关卡过场动画 (*.MCB)
├── SFX/ (1,093 文件)       # 视觉粒子特效文件 (*.ef)
├── image/ (67 文件)        # UI 2D 位图与贴图 (*.bmp, *.jpg)
├── music/ (13 文件)        # 背景音乐 (*.mp3)
├── Patch/ (30 文件)        # 声音音效 (*.wav)
└── texture/ (33 文件)      # 材质纹理贴图
```

---

## 二、 12 大专有文件格式深度逆向

通过对各文件头特征字节扫描与 `Meteor.exe` 内部加载例程的反汇编分析，各专有格式定义如下：

### 1. 资源封包格式 (`*.pak`)
- **魔数标识**: `50 4B 03 04` (`PK\x03\x04`)
- **格式本质**: **标准 PKZIP 格式归档**。
- **引擎加载函数**: `0x00478F00` ~ `0x00479100`。
  - 函数识别 `.pak` 和 `.zip` 扩展名（字符串 `0x005C80CC` 与 `0x005C80C4`）。
  - 使用内置 UnZip 引擎挂载虚拟文件系统，通过文件表偏移快速流式解压纹理与音效。

### 2. 角色动画文件 (`Common/character.amb`)
- **魔数标识**: `42 41 4E 49 4D` (`BANIM` = Bone Animation)
- **文件体积**: 11,908,599 字节 (11.36 MiB / 11.91 MB)
- **引擎加载函数**: `0x004E8319` -> `FUN_00574460`
- **头部结构**:
  - `Magic`: 5 字节 ASCII (`BANIM`)
  - `BoneCount`: 4 字节整数 (`0x1E` = 30 根骨骼)
  - `MaxFrames`: 4 字节整数 (总帧数)
  - `Bone Data`: 逐帧记录 30 根骨骼的局部坐标变换与旋转四元数。
  - **Bone 0 (Root Motion)**: 每帧 28 字节，直接驱动角色在世界坐标系下的绝对位移与旋转。

### 3. 角色招式派生与状态定义 (`Common/character.act`)
- **格式类型**: ASCII 明文文本
- **文件体积**: 10,389 字节
- **引擎加载函数**: `0x0049869A` 与 `0x004E8309`
- **语法规范**:
  ```
  group(PoseID)
  Action(ActionID)
  {
      ...
  }
  ```
  定义每个 Pose 的输入缓冲、受创硬直、攻击判定帧区间（Start/End/HitFrame）与派生连招链。

### 4. 骨骼姿态索引表 (`pmodel/*.pos`)
- **格式类型**: ASCII 明文文本
- **格式用途**: 将逻辑 Pose ID 映射到 `character.amb` 的动画帧区间。
- **语法规范**:
  ```
  Pose 0
  {
      source     1
      Start      1   
      End        65
      LoopStart  1
      LoopEnd    65
  }
  ```

### 5. 关卡碰撞几何体 (`sn*/sn*.cob`)
- **魔数标识**: `COL V1.0\x00\x00`
- **格式用途**: 静态关卡多边形碰撞网格与 BSP 划分。
- **引擎加载函数**: `0x00562D00` (初始化 SceneWorld 碰撞树)
- **数据组织**:
  - `COL V1.0` 头部魔数
  - 顶点数组 (Vector3: float x, y, z)
  - 三角形面片数组 (VertexIndex[3], PlaneNormal[3], MaterialFlags)
  - 扇区包围盒与空间划分索引（供 `FUN_005644F0` 与 `FUN_00563070` 查询）

### 6. 关卡静态视觉模型 (`sn*/sn*.gmb`)
- **魔数标识**: `GMDL V1.00`
- **格式用途**: 关卡 Direct3D 渲染几何体网格。
- **数据组织**:
  - `GMDL V1.00` 头部魔数
  - 关联材质贴图文件名列表 (`sn01T-05.jpg`, `SN01s2.jpg` 等)
  - 带有 UV 坐标与法线的渲染顶点缓冲。

### 7. 关卡场景描述文件 (`sn*/sn*.des`)
- **格式类型**: ASCII 明文文本 (作者: Peter Pon, Interserv 2002)
- **语法规范**:
  ```
  # GModel Description File V1.0
  # by Peter Pon for Interserv 2002/06/10
  SceneObjects 65 DummeyObjects 146
  Object di01
  {
      Position: -711.079 15.935 0.000
      Quaternion: 0.000 0.000 0.000 1.000
  }
  ```
  定义场景物件实例、空间坐标、旋转四元数、出生点及光源分布。

### 8. 场景物体动画文件 (`cmodel/*.fmc`)
- **格式类型**: ASCII 明文文本
- **头部标识**: `# GModel Animation File V1.0`
- **格式用途**: 记录箱子碎裂、大门开合等场景物件的顶点关键帧形变与骨骼动画。

### 9. 脚本逻辑文件 (`Level/*.pst`, `PScriptLib/*.pst`)
- **格式类型**: 类 C 语法的自定义脚本语言 (PScript)
- **引擎虚拟机**: `0x004BFCA0` ~ `0x004C0500` (语法词法分析与字节码/AST 执行机)
- **语法特性**:
  - 支持 `#include` 预处理。
  - 支持全局变量、数组、函数定义。
  - 原生内置游戏 API：`GetSceneItem()`, `SetSceneItem()`, `MakeString()`, `PlaySound()`。

### 10. 视觉特效文件 (`SFX/*.ef`)
- **魔数标识**: `PonEF V1.00\x03\x00`
- **格式用途**: 武器刀光轨迹、技能光效、命中受创火花与血液喷溅粒子。
- **数据组织**: 特效发射器类型 (`SPHERE`, `LINE`, `CYLINDER`)、绑定骨骼节点 (`Character`)、粒子贴图索引与生命周期色彩渐变。

### 11. 资源索引文件 (`Meteor.res`)
- **魔数标识**: `MTTM Meteor Resource file Version 1.0\x00`
- **引擎加载点**: `0x004D2898`
- **格式用途**: 游戏主资产表索引，包含武器属性表 (`W3_0` 等)、外挂模型与角色属性映射表。

### 12. 剧情过场动画文件 (`mc/*.MCB`)
- **魔数标识**: `MCCM mc binary file.\x00\x00`
- **格式用途**: 单人战役剧情动画镜头轨迹、对白时机触发与 NPC 行为脚本。

---

## 三、 逆向结论与架构映射

1. **资源装载总线**:
   - `Meteor.exe` 启动时首先读取 `config.ini` 与 `menu.res`。
   - 通过 `0x00478F00` 扫描并挂载所有 `.pak` 文件（PKZIP 虚拟文件系统）。
   - 解析 `Meteor.res` 建立全局物件索引表。
2. **战斗与动作闭环**:
   - 动作逻辑由 `Common/character.act` (状态转移) -> `pmodel/*.pos` (帧区间定位) -> `Common/character.amb` (Root Motion 位移推进) 形成闭环。
3. **物理与碰撞闭环**:
   - 场景几何由 `sn*.des` (物件实例) -> `sn*.cob` (COL V1.0 碰撞面) -> `0x004CF1E0` (PlayerController 碰撞探针) -> `FUN_005644F0 / FUN_00563070` (BSP 树射线与盒检测) 形成闭环。
