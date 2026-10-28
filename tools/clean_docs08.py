# -*- coding: utf-8 -*-
import sys

path = r'D:\MeteorRE\docs\08_AI_AND_PATHFINDING.md'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

start = text.find('## 一、 NPC 决策架构与思考循环')
end = text.find('## 三、 关卡路网与寻路导航')
assert start != -1 and end != -1, "Slice markers not found"

new_sec1_2 = """## 一、 既往伪模型撤回：不存在硬编码的「5 宏观状态」与「cos ≥ 0.5」

> ❌ **彻底证伪并撤回**：早前草稿中记载的「0巡逻/1警戒/2战斗/3防御/4寻物」5 宏观状态机与「cos ≥ 0.5 视场」在 `Meteor.exe` **根本不存在**。经二进制逐指令扫描（见 §五.1–§五.5），所谓 `0x40A2A0`/`0x40C040` 均为世界网格与关卡求交函数，非 AI 决策；百分比难度矩阵亦为移植重写版的臆测。

---

## 二、 原版 PC 二进制的真实 AI 架构：脚本驱动的 8 大原生行为

`Meteor.exe` 的真实 AI 并非硬编码状态机，而是由 **`Level/*.pst` 脚本驱动 + 原生派发器 `0x004F8F60` (`ChangeBehavior`)** 承载的 **8 大行为对象体系**（详见 `docs/13` §四）：

| 行为名 (字符串) | 名字 VA | 原生行为对象 | 装载入口 | 运行时语义与参数契约 |
|---|---|---|---|---|
| **`wait`** | `0x5CA11C` | `0x503970` | `0x4FD5B0` | 停止当前动作，原地待命等待触发 |
| **`idle`** | `0x5CA114` | `0x5039F0` | `0x4FD5B0` | 常规闲置与呼吸动画循环 |
| **`run`** | `0x5CA110` | `0x503D00` | `0x4FD5B0` | 逃跑/疾跑位移 |
| **`follow`** | `0x5CA108` | `0x503B30` | `0x4FD5B0` | 跟随指定目标玩家/队友 |
| **`patrol`** | `0x5CA100` | `0x503A00` | `0x4FD5B0` | **路网巡逻**：变长参数灌入 `[EBX+0x108]` 向量（如 `ChangeBehavior(g_self,"patrol",12,15,20)` 沿路点 12→15→20 巡游） |
| **`attacktarget`** | `0x5CA0F0` | `0x504A70` | `0x4FD630` | 索敌进攻：锁定 TargetPos 目标槽 [0..9] 并将第 4 参写入 `[ESI+0x88]` |
| **`kill`** | `0x5C9858` | `0x504670` | `0x4FD630` | 死斗决杀：无视撤退阈值全力击杀目标 |
| **`dodge`** | `0x5CA0E8` | `0x504560` | `0x4FD630` | 受击/遇险翻滚闪避（结果写入 `[this+0x74]`） |

### 行为参数来源（全量数据化，非常量）
每个 NPC 思考频率与行为偏好由 `Level/npc*.pst` 动态注入 18 个整数：
- `View`（索敌视野半径）、`Think`（思考间隔毫秒/Tick）
- `Attack1/2/3`（普攻/连招/绝招权重）
- `Guard` / `Dodge` / `Jump` / `Look` / `Burst` / `Aim` / `GetItem` / `Spawn` / `HP`

---

"""

text = text[:start] + new_sec1_2 + text[end:]

old_223 = "同样 §一 的「5 个宏观状态」与「视场 cos ≥ 0.5」也未在二进制中找到对应，标 ❓。"
new_223 = "同样旧草稿的「5 个宏观状态」与「视场 cos ≥ 0.5」已彻底证伪并撤除，真实体系为 `0x004F8F60` 的 8 大原生行为。"

assert old_223 in text, "old_223 not found"
text = text.replace(old_223, new_223)

with open(path, 'w', encoding='utf-8') as f:
    f.write(text)

print("docs/08 updated successfully!")
