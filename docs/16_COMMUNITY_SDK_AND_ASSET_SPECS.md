# 16 · 社区 SDK 架构与文件格式规范（2026-10-28 建立）

> 本文件基于对流星资源网核心工具资产（`As脚本引擎2.7.7`、`图像增强补丁6.5.9`、`个人地图制作心得2.0.1`）的逆向解包与实测分析，
> 系统归纳并建立流星动作状态机（Pose）、地图与场景文件（DES/FMC/COB/GMC）、原生导出 API 与场景破坏道具的权威技术规格。

---

## 一、动作姿态与出招序列规范（PoseMap & KeySeries）

### 1.1 招式键位序列（KeySeriesList）与底层招式库对齐
社区按键序列 `KeySeriesList.txt` 与我们在 `Meteor.exe` 中闭环的 `0x004FF200`（`AI_InitWeaponCombos`）及 `0x5CA1FC` 招式键串池 100% 对齐：

| 武器编号 | 武器名称 | 核心出招指令序列（KeySeries） |
| :---: | :---: | :--- |
| **0** | **轻剑** | `f`（前）, `b`（后）, `l`（左）, `r`（右）, `bb`, `bf`, `fb`, `ff`, `bff`, `lr`, `rl`, `lrf` |
| **1** | **匕首** | `f`, `ff`, `l`, `r`, `b`, `bf`, `bb`, `bff` |
| **2** | **火铳** | `f`, `b`, `bf`, `bff` |
| **3** | **飞镖** | `f`, `b`, `bf`, `bff` |
| **4** | **大锤** | `f`, `b`, `bf`, `ff`, `bb`, `lr`, `rl`, `lrb`, `lrf`, `bff`, `bbf` |
| **5** | **大刀** | `f`, `b`, `l`, `r`, `ff`, `bf`, `bb`, `lr`, `lrf`, `bbf`, `lrb` |
| **6** | **飞轮** | `f`, `b`, `bf`, `bff` |
| **7** | **长枪** | `b`, `f`, `rl`, `bb`, `bf`, `ff`, `lr`, `bbf`, `lrf`, `fff`, `lrb`, `bff` |
| **8** | **双刺** | `f`, `r`, `l`, `lr`, `bf`, `b`, `ff`, `bbf`, `lrf`, `blr` |
| **9** | **乾坤** | `f`, `b`, `l`, `r`, `bb`, `ff`, `lrf`, `lrb`, `bf`, `fb`, `bbf` |
| **10** | **指虎** | `b`, `lr`, `ll`, `rr`, `bb`, `lrf`, `bf`, `ff`, `fb`, `bbf`, `lrb`, `bff` |
| **11** | **忍刀** | `f`, `b`, `fb`, `ff`, `ll`, `rr`, `bb`, `lr`, `bbf`, `bf`, `lrf`, `lrfb`, `lrb`, `bff` |

---

### 1.2 动作 ID（PoseID）映射全景（摘录核心动作）
- **飞镖**：`200` 黑蜂针(A), `201` 八方绝(下上A), `202` 空中黑蜂针, `203` 落樱雪蓄气(下上上A), `204` 落樱雪爆发, `209` 雷神锥(上A), `210` 赤炼牙(下A), `214` 暗器空中踢, `551` 空中八方绝。
- **双刺**：`230` 左扇手(A), `213` 右扇手(AA), `232` 虎归山(AAA), `233` 进撵猴(上A), `234` 马分鬃(上A上A), `237` 右揽鹊尾(右A), `238` 左揽鹊尾(左A), `239` 双龙通臂掌(左右A), `240` 玉女穿梭(下上A), `241` 七星踏(下A), `242` 跨虎步, `243` 十字鞭(上上A), `244`–`364` 合太极起手与全套连击。
- **大刀**：`260` 斩(A), `261` 拔刀(AA), `262` 劈(AAA), `263` 左右逢源(左右A), `264` 腥风(下A), `265` 血雨(下下A), `266` 扫(上A), `267` 狂风(上下A), `268` 暴雪(上下A), `269` 旋风(左右上A), `270` 雷霆(下上A), `271` 疾电(下上上A)。

---

## 二、场景与几何资产文件格式规格（DES / FMC / GMC）

### 2.1 场景描述符格式（.des）
根据过山河/yish 的导出源码，`.des` 采用结构化 ASCII 描述块：
```text
# GModel Description File V1.0
SceneObjects <count> DummeyObjects <count>
Object <MeshName>
{
  Position: <X> <Y> <Z>
  Quaternion: <W> <X> <Y> <Z>    # 注意：流星四元数分量顺序为 W, X, Y, Z
  TextureAnimation: 0 0.000 0.000
  Custom:
  {
  }
}
```

### 2.2 顶点动画文件格式（.fmc）
```text
# GModel Animation File V1.0
SceneObjects <count> DummeyObjects <count>
FPS <tmpFrameRate> Frames <frameCount> Mode: RIGID
```
帧率控制规则：`tmpFrameRate = frameRate / 2`，流星底层骨骼动画默认执行半速采样以配合插值平滑。

---

## 三、原生导出引擎接口（滴风 Api.h 逆向提取）

通过分析 `As脚本引擎 2.7.7` 暴露的底层 C++ 抽象，明确了 `Meteor.exe` 核心引擎的 C 导出调用模型：

```cpp
// 角色战斗与动作驱动
void CharAttackImm(int charId, const string& keySeries); // 瞬发指定键位招式
void CharJumpImm(int charId);                          // 瞬发跳跃
void CharShowPose(int charId, int poseId);              // 强制设置动作 ID (写入 +0x5E0)
void CharSwitchWeapon(int charId, bool active = true);  // 切换主副手武器
int GetActivePose(int charId);                          // 读取当前动作 ID (读取 +0x5E0)

// 射线探测与物理视线
bool IsTwoPointsVisible(const Vector3& p1, const Vector3& p2); // 两点是否遮挡（BSP 射线求交）
bool WorldRayCast(const Vector3& start, const Vector3& dir, Vector3& hitPoint); // 物理拾取

// 场景道具与销毁控制
void CharDropTempItem(int charId, int type, int itemId, const Vector3& pos, float angle);
void CharCreateTempItem(int charId, int type, int itemId, const Vector3& pos);
```

---

## 四、场景可破坏物道具标准参数（Def.as）

| 道具名称 | 变量名 | 最大生命值 (MaxHP) | 伤害值 (Damage) | 特殊机制 / 冷却时限 |
| :--- | :--- | :---: | :---: | :--- |
| **小木箱** | `g_iBoxMaxHP` | 50 | — | 击碎掉落包子/飞镖 |
| **大木箱** | `g_iBBoxMaxHP` | 100 | — | 击碎掉落大武器/红酒坛 |
| **椅子** | `g_iChairMaxHP` | 40 | — | 击碎生成木片碎屑 |
| **桌子** | `g_iDeskMaxHP` | 70 | — | 碰撞硬阻挡体 |
| **水罐** | `g_iJugMaxHP` | 30 | — | 易碎碰撞体 |
| **拒马** | `g_iGiMaMaxHP` | 3,000 | — | 第4关拒马 HP 升至 10,000 |
| **石灯/石柱** | `g_iLevel01StoneMaxHP` | 500 | 300 | 碎裂倒塌对周围造成 300 范围伤害 |
| **机关暗箭** | `g_iLevel07KnifeDamage` | — | 300 | 触发射击伤害 300 |
| **机关地刺** | `g_iLevel07PinDamage` | — | 200 | 踩踏伤害 200 |
| **机关暗门** | `g_iLevel03DoorWaitTime` | 10,000 | 50 | 门开延迟 7,000ms，撞击门伤害 50 |
| **决死桥梁** | `g_iLevel13BridgeHP` | 4,000 | — | 击碎断桥坠崖 |
