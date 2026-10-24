# 《流星蝴蝶剑.net》战斗打击判定、击飞冲量与伤害结算逆向工程规范

> **二进制基准**: `Meteor.exe` (2002 原版，MD5: `cf2aa5c21a0a687afacc5e5c0876c543`，基址: `0x00400000`)  
> **代码来源**: `07_Combat_HitDamage_System.c` 与 `09_Weapon_HitBox_Pipeline.c`（经 Ghidra 12.1.4 真实反编译）  
> **核心函数定位**:
> - `0x004D0540`: `PlayerController::OnHit`（击飞冲量积分、受击浮空偏置、受击姿态切换）
> - `0x004D0AC0`: `PlayerController::ProcessDamage`（气血扣减、倒地保护、死亡分流）
> - `0x004D1740`: `CombatSystem::LoadAttackParameters`（招式攻击数据解析器）
> - `0x004D1EA0`: `CombatSystem::ApplyKnockbackImpulse`（受击速度叠加与速度限幅）
> - `0x004D3634`: `WeaponSystem::EvaluateHitBoxOverlap`（武器扫掠盒与角色 AABB 求交）

---

## 一、 受击击飞冲量动力学方程 (`0x004D0540`)

在反编译产物 `07_Combat_HitDamage_System.c` 的 `FUN_004d0540` 中，揭示了《流星蝴蝶剑》经典浮空与吹飞手感的真实底层计算式：

```c
/* 提取自 0x004D0668 ~ 0x004D06BE */
// 0x004D0674: fadd dword ptr [0x5AA944] (+0.13f 向上偏置)
// 0x004D0698, 0x004D06A6, 0x004D06BE: fmul dword ptr [0x5AA934] (600.0f 标量缩放)
float impulseX = hitNormalX * 600.0f;
float impulseY = hitNormalY * 600.0f;
float impulseZ = (hitNormalZ + 0.13f) * 600.0f; // 垂直仰角抬升偏置
```

### 1. 物理参数物理学诠释
- **`600.0f` (`METEOR_MAX_SPEED_CAP`)**: 二进制地址 `0x005AA934`。游戏全引擎标量速度天花板，任何攻击的最大瞬间击退初速均以此为基准进行衰减与缩放。
- **`+0.13f` 垂直抬升偏置 (Pop-Up Bias)**: 
  - 即使攻击法线完全水平（`hitNormalZ = 0.0f`），在被击中时也会强制施加 `0.13 * 600.0f = 78.0f/s` 的向上垂直冲量！
  - **这一设计是原版“轻击也能打出微浮空、形成空中连续技（小跳挑空）”的底层物理根本原因**。
- **受击点探测基准 (`+40.0f`)**: 
  - 指令位置 `0x004D05EB: fadd dword ptr [0x5A8E7C]`（机器码 `D8 05 7C 8E 5A 00`）：角色受击检测上身探测点取自脚底原点上浮 40 单位，精确对应人物胸腔重心。

---

## 二、 击飞冲量注入与状态转移 (`0x004D1EA0`)

当受击成立后，`FUN_004d1ea0` 负责将受击矢量融合至角色的主运动速度中：

```
[武器/招式命中] ➔ [读取受击法线与攻击权重] 
                ➔ [合成 (nx*600, ny*600, (nz+0.13)*600)] 
                ➔ [调用 FUN_004d1ea0 注入 PlayerController->velocity]
                ➔ [触发 OnHit 硬直动画 Pose] 
                ➔ [打断当前招式释放 FSM]
```

### 状态派发与保护
1. **浮空判断 (`moveState = 2` 或 `jumpFlag != 0`)**:
   - 若角色已处于空中，受击后不会播放地面后仰动画，而是切换为空中翻滚/失衡动作，垂直速度重置为受击抬升冲量，允许追击（浮空连招）。
2. **倒地保护 (Knockdown Invincibility)**:
   - 当累计受击下坠至地面接触（`grounded == 1` 且垂直冲击力超阈值）时，角色强制进入倒地姿态（Pose 160+）。
   - 倒地期间设置无敌标记位（`combatLocked |= 0x1000`），清除所有外来攻击判定，直至起身动作完成。

---

## 三、 武器攻击判定盒 (HitBox) 扫掠管线 (`0x004D3634`)

武器并非单纯的点测试，而是由双挂点与时间插值构成的扫掠凸包：

1. **挂点采样**:
   - 武器根部: `Dummy0`（剑柄/刀镡）
   - 武器尖端: `Dummy1`（刀尖/剑尖）
2. **扫掠轨迹面 (Ribbon Blade Trail)**:
   - 代码 `0x004D2870` 在每一物理帧（1/30s）缓存上一帧的 `Dummy0_prev`、`Dummy1_prev` 与当前帧的 `Dummy0_curr`、`Dummy1_curr`。
   - 这 4 个点构成了攻击瞬间的四边形切面。
3. **空间重叠测试**:
   - 利用 `0x004D3634`（`WeaponSystem::EvaluateHitBoxOverlap`）将该刀刃切面与敌方角色的复合 AABB（下身 $0 \sim 10.0$，躯干 $10.0 \sim 32.0$，水平半径 $8.0$）进行分离轴定理 (SAT) 快速重叠相交测试。
   - 若相交，立即触发 `0x004D3E60`（`OnWeaponContact`）：播放受击金属/肉体音效、通过特效系统回调（注册于 `0x00560970`，回调实现为 `0x0056C9B0`）生成火花粒子，并调用受击方的 `0x004D0540`。
