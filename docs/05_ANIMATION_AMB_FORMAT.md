# 《流星蝴蝶剑.net》动画数据文件 (character.amb) 二进制格式逆向解析

## 一、 二进制结构概述

由 `Meteor.exe` 中的反汇编函数 `FUN_00574460` (`0x00574460`) 完整揭示：

```c
// 字符串魔数检测
_strncmp(header, "BANIM", 5);
```

`character.amb` 属于昱泉私有二进制骨骼动画格式（**Binary Animation Format - BANIM**）。

---

## 二、 文件头布局 (Header Layout)

| 偏移 (Offset) | 类型 (Type) | 字段名称 | 含义说明 |
| :--- | :--- | :--- | :--- |
| `0x00 - 0x04` | `char[5]` | `magic` | 必须为 `"BANIM"` (ASCII) |
| `0x05 - 0x08` | `int32_t` | `boneCount` | 骨骼总数量 (例如角色骨骼约 30-40 根) |
| `0x09 - 0x0C` | `int32_t` | `dummyCount` | 挂点数量 (武器挂点 `d_wpnR`, `d_wpnL` 等) |
| `0x0D - 0x10` | `int32_t` | `frameCount` | 动画总帧数 (角色主动画库约 5000+ 帧) |
| `0x11 - 0x14` | `float` | `frameRate` | 采样帧率 (标准 30.0 fps 或 60.0 fps) |

---

## 三、 每帧数据排布 (Per-Frame Payload)

由 `0x00574460` 中的堆内存分配操作确定：

1. **根骨骼 0 (Root Motion, 28 字节/帧)**:
   - `pvVar4 = operator_new(*piVar6 * 0x1c);` (`0x1c = 28` 字节)
   - 包含根节点的绝对空间位移 (`Vector3 translation`, 12 字节) + 四元数旋转 (`Quaternion rotation`, 16 字节)。
   - **这正是流星所有招式带位移（如轻功滑行、前冲斩、绝技穿梭）的根源！所有移动完全由根骨骼位移驱动（Root Motion）！**

2. **子骨骼 1..N (16 字节/帧)**:
   - `pvVar4 = operator_new(*piVar6 << 4);` (`<< 4 = 16` 字节)
   - 每个子骨骼仅存储相对于父骨骼的局部旋转四元数 (`Quaternion(x, y, z, w)`)。

3. **挂点 Dummy 节点 (36 字节/帧)**:
   - `pvVar4 = operator_new(*piVar6 * 0x24);` (`0x24 = 36` 字节)
   - 存储 9 个浮点数（3x3 旋转矩阵，定义挂接武器、发光特效朝向与法线）。
