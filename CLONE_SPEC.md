# Meteor.exe — Behavioral Clone Spec (CLONE_SPEC.md)

> Clean-room reverse-engineering behavior spec for the Meteor (流星蝴蝶剑) PC
> executable. Target rebuild: **MeteorRebuild** (Unity C#).
> Working draft — private area, movable into MeteorRebuild later by owner.

## Rules (from REAP §4 — non-negotiable)
- Extract **behavior**, not code. Never copy proprietary source, assets, branding, or licensing mechanisms.
- Every requirement cites **evidence**: function, address, string, or captured request.
- Mark anything unconfirmed as **UNKNOWN**.
- Static analysis first; do not execute the game unless runtime observation is explicitly required.

## Status legend
- ✅ confirmed (cited evidence)
- 🟡 inferred (reasonable from evidence, not proven)
- ❓ unknown (not yet determined)

---

## 0. Overview / Engine
- Engine / framework identity, render loop, update/tick order, top-level module map.
- Entry points, main loop, subsystem init order. `[evidence]`

## 1. Combat
### 1.1 Hit detection (判定帧)
### 1.2 Damage model (真实伤害)
### 1.3 Combo / chain system (连招)
### 1.4 Hitstun / knockback / 部位判定
### 1.5 Movement anchors / 位移 (冲刺 / 跳跃 / 锚点)

### 1.0 Combat function anchors (static, evidence)
> Seed from `CombatAnchor` Ghidra pass over `MeteorProj` (10,734 funcs / 95.45%).
> 43 unique functions reference combat keywords. All auto-named (`FUN_xxxx`).
> Ranked by #distinct combat keywords referenced, then size.

| Address | Size | Keywords | Likely role |
|---------|------|----------|-------------|
| `FUN_0045b280` | 9383 | attack,block,guard,hit,weapon | **Combat core / damage裁决** |
| `FUN_0045d730` | 2725 | attack,block,guard,hit,weapon | Combat handler (sibling) |
| `FUN_004d1740` | 1419 | attack,guard,hit,weapon | Combat handler |
| `FUN_0056bc60` | 1551 | animation,damage,frame | **Hit-detection / 判定帧 + 伤害** |
| `FUN_005012f0` | 742  | attack,dodge,guard | Dodge/guard handler |
| `FUN_00436bb0` | 23301 | hit,sword | **Weapon-update routine (clone A)** — see §1.7 |
| `FUN_00446380` | 23068 | hit,sword | **Weapon-update routine (clone B, byte-identical to A)** — see §1.7 |
| `FUN_00452af0` | 21760 | hit,sword | ~~Per-frame action FSM~~ **RETRACTED → UI / menu renderer** — see §1.7 |
| `FUN_0057aaf0` | 4628 | action,attack | Action/attack dispatch |
| `FUN_004e90b0` | 4435 | frame,move | Movement / frame logic (位移) |
| `FUN_004ba240` | 2638 | guard,hit | Guard/hit |
| `FUN_005637d0` | 2415 | attack,damage | Attack/damage |
| `FUN_004b63b0` | 1423 | move,weapon | Move/weapon |
| `FUN_004f8f60` | 1331 | attack,dodge | Attack/dodge |
| `FUN_00420f70` | 1076 | action,counter | Counter |
| `FUN_00504be0` | 847  | attack,guard | Attack/guard |
| `FUN_00563300` | 562  | animation,damage | Animation/damage |
| `FUN_004fb8b0` | 496  | attack,dodge | Attack/dodge |

(remaining 25 functions: single-keyword refs — see `combat_anchor.csv`)

> **Role correction (static, evidence):** `FUN_0045b280` is NOT the per-frame
> combat resolver — it is a **config / command-string orchestrator** (4648 lines,
> 0 `switch`, calls `FUN_00509ed4`×49 / `FUN_0050aaa9`×48, both string/config utils;
> ...copies `s_favourite_*` / `s_user_cfg_*` buffers).
>
> **Where the real logic lives (corrected):** NOT in that trio. The actual §1.1–§1.5
> implementation is the set of **small, byte-anchored functions identified by vtable
> slot + float signature** — see **§1.9 (physics), §1.10 (damage), §1.11 (keywords)**.
> `FUN_00436bb0` and `FUN_00446380` remain a byte-identical pair of ~23KB update
> routines; `FUN_00452af0` is **removed from the combat queue** (UI renderer, §1.7).

### 1.6 Named-attribute system (data model) — ✅ confirmed
> Source: `FUN_0056bc60` (0x56bc60), decompiled `decomp_0056bc60.c`.
> Combat / animation data is addressed by **string-keyed attribute names**, not
> hardcoded offsets — a data-driven property table.

- Input: a context `param_1`; extracts a **type-tagged object** (`switch(*(iVar6+4))`):
  type ∈ {3,4} → resolver `FUN_00564f90(obj+8)`; type ∈ {7,8} → `FUN_00564fc0(obj+0xc)`.
- Resolves the object's attribute-name string (`*(char**)(iVar7+0xc)`, length `iVar7+0x10 − iVar7+0xc`)
  against known names; on match writes a numeric **attribute code** to `*puVar3`.
- Guard: caller state `*(param_1+4)` must be ≥2 (animation/damage branch requires ≥3),
  else returns 0 (no resolution).

**Attribute-name → code map (from FUN_0056bc60):**

| attribute name | code | symbol |
|---|---|---|
| `animation` | 10 | s_animation_005d1598 |
| `damage` | 3 | s_damage_005d1590 |
| `machine` | 12 | s_machine_005d1570 |
| `treasure` | 15 | s_treasure_005d153c |
| `normal` | 0 | s_normal_005d1568 |
| `targeta` | 13 | s_targeta_005d1550 |
| `targetb` | 14 | s_targetb_005d1548 |
| *(unnamed)* | 4 | DAT_005d1588 |
| *(unnamed)* | 5 | DAT_005d1580 |
| *(unnamed)* | 6 | DAT_005d1578 |
| *(unnamed)* | 11 | DAT_005c9c14 |

**✅ RESOLVED (all four):** the previously-unidentified codes are now read from the
binary — `4 = "hell"`, `5 = "safea"`, `6 = "safeb"`, `11 = "door"`
(`strings_dump.txt`, read via `DumpStrings.java` at `0x5d1588 / 0x5d1580 / 0x5d1578 / 0x5c9c14`).
The complete confirmed vocab is now **15 keys**:
`normal(0) damage(3) hell(4) safea(5) safeb(6) animation(10) door(11) machine(12)
targeta(13) targetb(14) treasure(15)` + the second comparison region
(`decomp_0056bc60.c:343+`) still to map: `frame`/`collision`/`active`/`attribute`/
`interactive`/`reborn`/`visible`.

Note the shape this reveals: with `hell`/`safea`/`safeb`/`door`/`treasure`/`machine`/
`targeta`/`targetb` present, this is not purely a combat-attribute table — it reads as a
**general entity-type / spawn-role taxonomy** shared by combat and level objects.

**Implication for MeteorRebuild:** model combat/animation attributes as a named-property
system (string key → enum code), with two backend resolvers keyed by object type
{3,4} vs {7,8}. The confirmed vocab is the minimum the rebuild must support.

### 1.7 ~~Per-frame action FSM~~ — ❌ RETRACTED: this is a **UI / menu renderer**
> **Retracted 2026-10-27.** Our earlier read classified `FUN_00452af0` as the per-frame
> combat FSM. That was **wrong**. User-supplied counter-evidence (full read of the body)
> plus our own re-verification settles it. **String anchoring produced this false positive.**
>
> **Confirmed evidence that it is UI, not combat:**
> - `operator_new(0x50)` at `decomp_452af0.c:110 / 428 / 2012 / 2900` — repeated fixed-size
>   control/widget allocation.
> - `DAT_005c7b60 * _DAT_005a8b10` etc. at lines 115–121 — **text coordinate scaling**.
> - The `0x45xxxx` values we took for handler *functions* are **labels inside this same
>   function**: `functionContaining(0x4559e4)` and `functionContaining(0x453308)` both
>   return `FUN_00452af0`. They are jump targets, not call targets — hence Ghidra's
>   correct "NO FUNCTION" verdict.
> - `DAT_005e0068/74/78` and `DAT_00667588` read back **entirely null / zero**
>   (`tables_dump.txt`) → they are `.bss`, filled at runtime; no static content exists,
>   so the "state→handler-table" model had **no observable basis**.
> - Its `hit`/`sword` hits come from **UI copy** (help/moveset legend text), not combat code.

**Methodological lesson (applies to the rest of this spec):** a string match is a *lead*,
not a verdict. **vtable slots and call sites are the authority.** Every combat claim below
is now anchored on vtable offsets / float signatures, not strings.
> Sources: `FUN_00452af0` (0x452af0, decompiled `decomp_452af0.c`, 4320 lines);
> `FUN_005565e0` (0x5565e0, decompiled `decomp_5565e0.c`); `FUN_004630b0` (0x4630b0, decompiled `decomp_4630b0.c`).

**Signature:** `FUN_00452af0(obj, state, variant, flag)` — 4 args.

- **State read:** `FUN_005565e0(x) = *(x + 0x20)` — a trivial getter of the combat
  object's **current action/state field** (offset +0x20). Called 122× inside the FSM
  → the FSM constantly re-reads `obj->state`.
- **Top-level dispatch:** `switch(state /*param_2*/)` at `decomp_452af0.c:76`.
  Each case loads a **handler-table + offset** indirection:
  - case 2 → `(DAT_005e0068, 0x453308)`; case 3 → `(DAT_005e0068, 0x456fb5)`;
    case 4 → `(DAT_005e0078, 0x456fb5)`; case 5/7 branch on `flag` (param_4);
    case 6 → `(DAT_005e0074, 0x456f7b)`; case 8 → `(DAT_005e0068, 0x457d30)`;
    case 9 sets `*(obj+0x2dc)=7` then calls `FUN_00468f20` conditionally;
    case 10 → `(DAT_005e0068, 0x457ad8)`.
  - cases **99 / 100 / 0x65 / 0x66 fall through together** (terminal/idle group).
- **Inner dispatch:** `switch(variant /*param_3*/)` at lines 2785 / 3202 — each
  variant is a `do { iVar5=0; ... } while` loop (frame/iteration stepping).
- **Flag:** `param_4` modulates entry (cases 5, 7 test `param_4 != 0` / `== 0`).

**❌ RETRACTED — every sentence below this line until §1.8.**
This described a "state→handler-table FSM". It does not exist:
* the `DAT_*` tables are `.bss` (all zero statically) — no handler content is observable;
* the supposed handler addresses are **internal labels of `FUN_00452af0` itself**;
* the function is a UI renderer. Nothing here may be used as a MeteorRebuild design input.
(The structural notes about `FUN_005565e0` / `FUN_004630b0` survive independently — see §1.8.)

**Behavioral rule (original, now VOID):**
`state` selects a handler table (data at `DAT_005e0068/74/78…`), `variant` selects a
handler within it, `flag` is a modifier. States 1–10 are active action states; the
99/100/0x65/0x66 cluster is idle/terminal. **The actual per-state action code lives in
the handler tables at those `DAT_*` addresses — not inlined in the FSM body.** This is
the real §1.1–§1.5 host.

**Implication for MeteorRebuild:** implement combat as `StateMachine<ActionState,
ActionVariant>` with a **data-driven handler registry** (state→handler-array), not a
hardcoded `switch`. The `obj->state` field at +0x20 and the flag/variant parameters
must be modeled 1:1.

### 1.9 Main physics integrator (movement / collision / grounding) — ✅ confirmed
> Source: `FUN_004ceb50` (0x4ceb50, 1,671 B body), decompiled `decomp_4CEB50.c` (212 lines).
> **Signature:** `void __thiscall FUN_004ceb50(int *self, double dt, float *normal, int mode, float *outNormal)`.

This is the movement core, and it is unambiguous.

- **Object / inheritance:** `self[4]` is a multi-inheritance adjustor; base obtained as
  `self[4] + (-0x65c)` (the same `-0x65c` adjustor appears in `0x4d0540` / `0x4d0ac0`
  → they operate on the **same object family**). All external work goes through
  **vtable calls**: `*base + 0x6c` (setup), `*base + 0x70` (commit/notify),
  **`*self + 0x100` (collision query)**.
- **Velocity is a 3-float in-place vector** (read/written through `unaff_retaddr[0..2]`).
- **Damping pass:** if `DAT_005aa934 < FUN_0047ecf0()` then all three components are
  multiplied by `DAT_005aa934` — a global damping factor applied per axis.
- **Broad-phase sweep** (only when `DAT_005a9510 < dt * t`): two successive calls to
  `FUN_00564760(&sweptMin, &sweptMax)` with different axis padding
  (`+DAT_005a84ac` / `±DAT_005a8cf0`). A non-zero return **cancels velocity and
  returns early**, setting `self[0xd8] = 1` and `self[0xf2] = 0x15`.
- **Per-axis resolve (the important part):** each axis is handled **independently** and
  only if its velocity component is non-zero (`!= DAT_005a83e4`, i.e. `!= 0.0`):
  1. `delta = v[axis] * dt`
  2. `flags = (*self + 0x100)(...)` — collision query returning a **bitmask**
  3. `flags & 1` → **`v[axis] = 0`** (axis blocked — stop)
  4. `flags & 2` → velocity is **overwritten** with the corrected vector
     `(fStack_90, fStack_8c, fStack_88)`
  Axis results accumulate into a **collision bitmask**: `bit0 = X`, `bit2 (4) = Y`,
  `bit4 (16) = Z` (via `| Rp`, `| Rp*4`, `| flags<<4`). Written back to `self[0xf2]`.
- **Grounding (Z axis only):** if the collision query returns non-zero:
  - `DAT_005aa92c <= penetration` → **`self[0xd7] = 1`** = *grounded*
  - else (airborne) a **restitution term** is computed:
    `k = (self[0x36]*dt + v[2]) * pen + (fStack_78 + fStack_7c) * 0.0`
    `bounce = 1.0 - 2*k` → written to `self[0x2e]/[0x2f]/[0x30]` as the corrected displacement.
- **Wall slide (tail):** when the flag `& 2` path wrote a normal, the velocity is
  **projected along the surface**:
  `fVar1 = dot(normal, velocity)`; gated by `mode` (`0` → skip when `fVar1 >= 0`,
  `1` → skip when `fVar1 <= 0`); then
  **`velocity -= normal * dot(normal, velocity)`** — textbook slide-along-wall.
- **Normal output:** if `flags & 2` and `outNormal != NULL`, the collision normal is
  copied out to `outNormal[0..2]`.

**Confirmed facts:** 3-axis independent resolve · bitmask collision flags
(X=1, Y=4, Z=16) · grounded flag at `self[0xd7]` · touched flag at `self[0xd8]` ·
result code at `self[0xf2]` · global damping `DAT_005aa934` · sweep test `FUN_00564760` ·
collision query via `vtable+0x100` · restitution of the form `1 - 2k` · wall-slide projection.
**Inferred:** `DAT_005a83e4` is `0.0` and `DAT_005a84ac` is `1.0` (used as literal constants);
`DAT_005aa92c` is a penetration/ground tolerance.
**Unknown:** exact struct field names; whether `FUN_00564760` is AABB or capsule sweep.

**Implication for MeteorRebuild:** implement `MoveAndCollide` as
**(1) sweep test → (2) per-axis resolve with a collision bitmask → (3) ground flag →
(4) `v -= n * dot(v,n)` slide**. This ordering is what makes the original feel
solid; a naive "move then push out" will not reproduce it.

### 1.10 Damage / knockback application (四级击退) — ✅ confirmed
> Source: `FUN_004d0ac0` (0x4d0ac0), decompiled `decomp_4D0AC0.c` (92 lines).

- Gate: `(*self + 0x154)()` — a **vtable query at +0x154** decides whether damage applies.
- Allocates a **0x1d0** record, resolves the source position via
  `(*(self[4]-0x65c) + 4)(&vOut, buf)`, then `vOut.z += DAT_005a8b08` (height offset).
- **The knockback ladder — four discrete levels**, selected by `switch(puStack_8)`
  on the damage type, values are IEEE-754 bit patterns:
  | case | raw | float |
  |---|---|---|
  | default | `0x44160000` | **600.0** |
  | `0x8` | `0x43af0000` | **350.0** |
  | `0x9` | `0x43c80000` | **400.0** |
  | `0xa` / `0xb` | `0x43e10000` | **450.0** |
- The magnitude is passed as a single scalar: `(*obj + 0x10)(magnitude)` (vtable +0x10).
- Attacker info is copied in: `dst[0x16] = src[0x48]`, two `__ftol()` conversions, and
  `dst[0x15] |= src[0x30] << 10` (flags packed into bits 10+).
- **Final knockback velocity = direction * magnitude**, stored as three ints:
  `dst[0x1c]/[0x1d]/[0x1e] = (int)(dir[0..2] * magnitude)`.
- Dispatch: `(*obj + 0xc)(0xd, record, 0)` — vtable **+0xc, command `0xd`** = the
  damage event is delivered by message, not direct call.

**Implication for MeteorRebuild:** knockback is **4 discrete tiers (350/400/450/600)**
scaling a normalised direction vector — not a continuous damage→force curve. Deliver
damage as a **command message (`0xd`)** so future systems (UI/audio/AI) can subscribe.

### 1.11 ~~Keyword / tag parser (action annotations)~~ — 🔄 REVISED (user census upheld, mechanism+semantics corrected)

> Source: `FUN_004d1740` (0x4d1740, body `0x4d1740–0x4d1cca`, 1,419 B, **436 instructions**).
> Artifacts: `decomp_4D1740.c` (426 lines), **`dis_body.txt`** (raw listing),
> `keywords16.txt` (resolved strings), `keywords16_map.json` (keyword→code map).

**Ruling on the "16 vs 4" dispute — the 16-keyword census is UPHELD.** My previous "4 tags"
reading was a **tooling artifact**: I had grepped only `DAT_*` symbols and missed the
`s_*` symbols Ghidra had already named. Full independent recount from the raw listing
confirms **16 comparison sites**, all resident in this one function body, stride 23 B:

```
004d1899  MOV  EAX,[EBX]        ; token char ptr
004d189b  XOR  EBP,EBP          ; per-token accumulator RESET
004d189d  MOV  EDI,0x5c91fc     ; "Attack"
004d18a2  MOV  ESI,EAX
004d18a4  MOV  ECX,0x7          ; strlen+1
004d18ab  CMPSB.REPE ES:EDI,ESI
004d18ad  JNZ  0x004d18b4       ; no match → try next keyword
004d18af  MOV  EBP,0x1000       ; match → set code
```

#### Complete resolved table (byte-level, every row cited)

| # | keyword | str @ | cmp site | code site | code | dec | VK check |
|---|---|---|---|---|---|---|---|
| 1 | `Attack` | `0x5c91fc` | `0x4d189d` | `0x4d18af` | `0x1000` | 4096 | — |
| 2 | `Guard` | `0x5c9cdc` | `0x4d18b4` | `0x4d18c6` | `0x20` | 32 | **VK_SPACE** |
| 3 | `Jump` | `0x5c9cd4` | `0x4d18cb` | `0x4d18dd` | `0x1200` | 4608 | — |
| 4 | `SwitchWeapon` | `0x5c9cc4` | `0x4d18e2` | `0x4d18f4` | `0x45` | 69 | **'E'** |
| 5 | `Unlock` | `0x5c9cbc` | `0x4d18f9` | `0x4d190b` | `0x51` | 81 | **'Q'** |
| 6 | `DropWeapon` | `0x5c9cb0` | `0x4d1910` | `0x4d1922` | `0x47` | 71 | **'G'** |
| 7 | `Fake` | `0x5c9ca8` | `0x4d1927` | `0x4d1939` | `0x59` | 89 | **'Y'** |
| 8 | `RightTurn` | `0x5c9c9c` | `0x4d193e` | `0x4d1950` | `0x27` | 39 | **VK_RIGHT** |
| 9 | `LeftTurn` | `0x5c9c90` | `0x4d1955` | `0x4d1967` | `0x25` | 37 | **VK_LEFT** |
| 10 | `DropItem` | `0x5c9c84` | `0x4d196c` | `0x4d197e` | `0x48` | 72 | **'H'** |
| 11 | `Cure` | `0x5c9c7c` | `0x4d1983` | `0x4d1995` | `0x54` | 84 | **'T'** |
| 12 | `Crouch` | `0x5c9c74` | `0x4d199a` | `0x4d19ac` | `0x43` | 67 | **'C'** |
| 13 | `InitialCamera` | `0x5c9c64` | `0x4d19b1` | `0x4d19c3` | `0x4c` | 76 | **'L'** |
| 14 | `Fool` | `0x5c9c5c` | `0x4d19c8` | `0x4d19da` | `0x52` | 82 | **'R'** |
| 15 | `Score` | `0x5c9c54` | `0x4d19df` | `0x4d19f1` | `0x9` | 9 | **VK_TAB** |
| 16 | `HitAttack` | `0x5c9c48` | `0x4d19f8` | `0x4d1a08` | `0x46` | 70 | **'F'** |
| — | `"+"` | `0x5c9c44` | `0x4d1a5a` | — | *(separator)* | — | — |

Self-check that this is a single packed table: the string addresses step monotonically
downward `0x5c9cdc → 0x5c9c48` with deltas of 4/8/12/16 bytes = `ceil(len+1) rounded`,
and every `MOV ECX` load equals `strlen+1` exactly. No additional keyword exists between
them.

#### Three corrections this pass — all carried by the listing, not by inference

**(a) "位标志 (0x1000/0x0020/0x1200…)" is REFUTED at opcode level.**
Every assignment is `MOV EBP,imm`; there is **no `OR`/`AND`/`ADD` on `EBP` anywhere in the
436 instructions** (only three `XOR EBP,EBP` resets at `0x4d1773/0x4d189b/0x4d1ab8`).
`EBP` is *overwritten*, never accumulated → each token yields **exactly one scalar**, not a
composable flag set. Only three values are single- or few-bit shaped; the thirteen in
`0x25–0x59` are **not** bit patterns.

**(b) The `'r'` string is `fopen`'s mode argument, not a comparison operator.**
`FUN_00509f8f(param_2, &DAT_005c67d0)` is **`fopen(path, "r")`**. Corroborated by:
`FUN_0050a118(&buf, 1, 1, stream)` = **`fread` one byte at a time**; a `(stream+0xc) & 0x20`
flag test branching to `FUN_0050b19a(s_Read_error_005c9150)` = **"Read error"**;
`FUN_00509e57(stream)` = **`fclose`** at the end. `DAT_005c67d0` sits in the *prologue*
(`0x4d1762`, instruction 13), before any token loop — not in a compare chain.

**(c) The five "tag handlers" are `std::map` internals, not per-tag consumers.**

| address | decompiled shape | verdict |
|---|---|---|
| `0x49c330` | walks a **binary tree** (`parent +4`, `left +8`, `right +0xc`), compares `*key < *(node+0x10)`, allocates via `FUN_0049e160`, rebalances via `FUN_00460be0`, `size++`, returns `pair<node*,bool>` | **`map::insert`** |
| `0x49aff0` | walks the same tree, frees with `FUN_00402e90` (24-byte node), resets head/sentinel, `size = 0` | **`map::clear` / dtor** |
| `0x49c0d0` | `return (*a < *b) ? b : a;` | **`max` helper** |
| `0x49be40` | 4,014 chars of tree surgery | tree rotate / erase (same family) |
| `0x4a1ab0` | `if (DAT_006659bc == 0) { operator_new(4); DAT_006659bc = FUN_004a1a60(); }` | **lazy singleton getter** |

#### What the function actually is — confirmed mechanics

It is a **text-config-file loader**, not a runtime per-frame evaluator:

1. `fopen(path, "r")`; on failure returns immediately (`LAB_004d1c8a` path).
2. `fread` **byte-by-byte**, checking the stream error bit each iteration → `"Read error"`.
3. Accumulates characters into tokens stored as **12-byte records** (`stride 0xc`, the
   decompiler's `puVar8 + 3` step and the `(end - begin)/0xc` free-size both confirm it).
4. For each record: try all **16 keywords** → `EBP = scalar code`.
5. The **next** record is converted by `FUN_0050915b → FUN_005090d0` = **`atoi`** (skips the
   `&8` whitespace class, accepts `+`/`-` sign, accumulates the `&4` digit class, negates
   on `-`) — result guarded `< 0x100` (`JNC` skip at `0x4d1a2c`).
6. `(code, number)` is inserted into a **local `std::map`** via `0x49c330`.
7. A following `"+"` token (`0x4d1a5a`) chains one further `atoi` operand to the same code.
8. On exit: `fclose`, `map::clear`, free the token buffer, return `1`.

Note the result map is **function-local**; the only global written at the tail
(`DAT_005d59e8 = 0` plus a list push into `DAT_005d59a4[(n+7)>>3]`) is the **MSVC CRT
small-block free-list** — `xref_globals.txt` shows thousands of references to those two
globals from hundreds of functions, with `(size+7)>>3` 8-byte bucket indexing. Hence they
are **memory management, not this parser's output store**.

#### Buckets

**Confirmed:** 16 keywords and their 16 scalars, all 34 cited addresses above; no bit
accumulation; the file-I/O framing (`fopen/fread/fclose/"Read error"`); `atoi` on the
following token with a `<0x100` guard; `"+"` chaining; `std::map` insert/clear/max
machinery; 12-byte token stride; function-local result map.

**Inferred:** this is a **control / key-binding config loader**. Evidence: **14 of 16 codes
are exact Windows virtual-key codes** — `VK_TAB(0x09)`, `VK_SPACE(0x20)`, `VK_LEFT(0x25)`,
`VK_RIGHT(0x27)`, and `0x41–0x5A` VK-letter codes matching `'C' 'E' 'F' 'G' 'H' 'L' 'Q'
'R' 'T' 'Y'`; the keyword names are all *bindable player actions* (Attack / Guard / Jump /
Crouch / LeftTurn / RightTurn / SwitchWeapon / DropWeapon / DropItem / HitAttack /
Unlock / InitialCamera / Score / Cure / Fake / Fool); and `FUN_0045b280` (§1.0) references
`s_favourite_*` / `s_user_cfg_*` — a user-config surface. `Attack=0x1000` and `Jump=0x1200`
sit outside the VK range and most plausibly encode **mouse buttons** or an extended device.

**Unknown (must be closed before any rebuild claim):**
- Whether the map is keyed by the **action scalar** or by the **atoi'd number** — the
  `__thiscall` stack slot could not be pinned unambiguously from this one call site.
- Whether the numbers are key codes, frame counts, or slot indices. The `<0x100` bound is
  consistent with all three.
- The file's name/format extension. **Not** determinable from this function alone.
- **Nothing here is a cancel window.** No frame maths, no state transition, no combo
  counter appears anywhere in the 436 instructions.

**Implication for MeteorRebuild:** do **not** build a "cancel keyword bitflag" system from
this function. If anything, it is the **input-binding config table**: 16 bindable actions,
each taking one or more small integers (`+`-chained), stored in a map. Rebuild priority is
low until the consumer of the parsed map is located (see §Open).

### 1.8 Named-record resolver & state getter — ✅ confirmed
> Sources: `FUN_004630b0` (0x4630b0, `decomp_4630b0.c`); `FUN_005565e0` (0x5565e0).

- **`FUN_004630b0(obj, name)`** — **name→record linked-list lookup**. Walks the list at
  `obj+0x30` (`node[0]=next`, `node[2]=data`; `data+4` = a byte-string name), compares
  the byte-string against `name` byte-by-byte, returns the matched `node[2]` (record ptr)
  or 0. Called 113× in the FSM → actions are **fetched by name from a record list**.
- **`FUN_005565e0(obj)`** — `obj->state` getter (offset +0x20), called 122×.

**Behavioral rule:** Meteor's combat data model is **named-record driven** — animation/
action records live in **name-indexed linked lists** (`obj+0x30`), resolved by byte-string
name (`FUN_004630b0`) and parsed into numeric property codes (`FUN_0056bc60`, §1.6).
This is the bridge between the string-keyed property system and the per-frame FSM.

**Implication for MeteorRebuild:** replace hardcoded offsets with a **named registry**
(`Dictionary<string, Record>`) keyed the same way; `FUN_004630b0` ≡ a name lookup,
`FUN_0056bc60` ≡ the property parser feeding that registry.

## 2. AI (enemy / NPC state machines)
- Perception, decision, attack selection, FSM transitions. `[evidence]`

## 3. Asset & Level pipeline
- Level / animation load & serialization order, data tables, archives (.amb / .mv / level data).
- Where gameplay data lives (tables, scripts, archives). `[evidence]`

## 4. UI / Menus / Input
- Layout logic, key dispatch, command routing, input buffering semantics. `[evidence]`

## 5. Persistence / Save
- Save format, paths, checksum/validation, settings layout. `[evidence]`

## 6. Audio
- Trigger model, banks, attenuation rules. `[evidence]`

## 7. Networking
- Expected offline single-player; document any residual netcode / IPC. `[evidence]`

## 8. Error / edge-case behaviors
- Failure modes, recovery, undefined-input handling. `[evidence]`

---

### 1.12 Input sampling → movement axes — ✅ confirmed
> Source: `FUN_004cb260` (0x4cb260, 900 B body), decompiled `decomp_4cb260.c` (180 lines).
> **Note:** the address in our earlier queue was `0x4cb270`, which is **not an entry** —
> it sits at `+0x10` inside `FUN_004cb260`. Real entry is `0x4cb260`. Same offset-vs-entry
> trap as §1.7. Evidence: `getFunctionContaining(0x4cb270) = FUN_004cb260`.

This is the keyboard / controller poller, and it is entirely API-anchored (no strings).

- **Dual input source per axis** — every axis is `( GetAsyncKeyState(vk) != 0 ) || ( vtable_axis() rel 0 )`,
  i.e. **keyboard OR analogue axis**, combined with logical OR.
- **`aiStack_114` is a virtual-key table** scanned linearly for up to 27 entries (`iVar5 < 0x1b`),
  each entry being a `pair<vkCode, operand>` at `aiStack_114[i*2] / [i*2+1]`.
- **Resolved mapping** (virtual-key codes are Win32 constants):

  | virtual key | hex | target field | positive condition | negative condition |
  |---|---|---|---|---|
  | **W** | `0x57` | `self[0x18]` (forward/back) | key down **or** `vtable+8() > 0` | — |
  | **S** | `0x53` | `self[0x18]` | — | key down **or** `vtable+8() < 0` |
  | **D** | `0x44` | `self[0x19]` (strafe) | key down **or** `vtable+4() > 0` | — |
  | **A** | `0x41` | `self[0x19]` | — | key down **or** `vtable+4() < 0` |
  | **Right** | `0x27` | `self[0x22]` | key down **or** `vtable+0xc() > 0` | — |
  | **Left** | `0x25` | `self[0x22]` | — | key down **or** `vtable+0xc() < 0` |
  | **Up** | `0x26` | `self[0x21]` | key down **or** `vtable+0x10() > 0` | — |
  | **Down** | `0x28` | `self[0x21]` | — | key down **or** `vtable+0x10() < 0` |

- Axes are `±1` integers accumulated per poll, then **all four are packed and dispatched**
  as a single message: `(*self + 0xc)(0x33, &pack, 0x10)` — vtable **+0xc, command `0x33`**,
  16-byte payload. (Note: `+0xc` is the *same* message slot used by damage in §1.10 —
  this object routes both input and damage through one dispatcher.)
- Each poll resets the axes to 0 first (`param_1[0x18]=0` etc.), so these are
  **edge-accumulated deltas per frame**, not absolute states.
- Singleton lazily created on first call: `DAT_005e0328` via `operator_new(0x33c)` + `FUN_0044d020()`.

**Confirmed:** all 8 virtual keys, the 4 target fields, the OR-combination of keyboard and
analogue axis, the `0x33` dispatch cmd, per-frame axis reset.
**Inferred:** `vtable+4/+8/+0xc/+0x10` are gamepad stick axes (they return a sign, like a stick).
**Unknown:** whether axis values can exceed ±1 within one frame (no clamp observed), and
which singleton `DAT_005e0328` is.

**Implication for MeteorRebuild:** build input as **two independent sources reduced into
four signed axes**, then ship one `InputAxes` message per frame — do not read keys directly
in gameplay code. The original already separates sampling (`0x4cb260`, §1.12) from
integration (`0x4ceb50`, §1.9), and that split is worth preserving.

> **Standing correction to the prior ruling:** `0x4cb270` was queued as
> "连招 + 怒气扣除". The function at that location performs neither — no combo counter and
> no resource deduction appear anywhere in its body. It is the **input poller**. The combo
> /anger logic must be located elsewhere (not yet found).

### 1.13 Jump dispatch — ✅ confirmed
> Source: `FUN_004cf5b0` (0x4cf5b0, small body), decompiled `decomp_4CF5B0.c`.
> Byte-anchored (vtable + float globals), no string dependence.

Guard `param_1[4] != 0`, then `switch (param_1[0x37])` — a **jump-mode selector** stored on
the character object:

| case | behaviour | cited evidence |
|---|---|---|
| `0` | `vtable[+0x80](param_2)` — try jump; on success set `param_1[0x39] = 1`, then `FUN_00549a90(0,0)` | `decomp_4CF5B0.c` |
| `1` / `0xb` | `vtable[+0x68]()`; pick vertical impulse **`_DAT_005aa93c`** (default) or **`_DAT_005aa940`** (when `param_2 != 0`); write to `param_1[0xe6]`; `vtable[+0x12c](0)`; set `param_1[0x39] = 1`; `FUN_00549a90(0,0)`; if `param_1[0xd3] == 0` → **`vtable[+0xc](7, &stack0, 4)`** | same |
| `2` | `vtable[+0x84](0, 0, 0xbf800000)` (`0xbf800000 = -1.0f`), `vtable[+0x74](uVar4)`, builds a vector through `FUN_0047ec40`, then **scales the whole velocity triple `(+0xe4,+0xe5,+0xe6)`** by the same `_DAT_005aa93c` / `_DAT_005aa940` select | same |

Returns `0` on success, `0xffffffff` otherwise.

**Confirmed:** the two impulse float globals, the `param_2`-select between them, the mode
switch, and that every successful branch emits **`vtable[+0xc](7, …)`**.
**Inferred:** `_DAT_005aa93c` = standing jump impulse, `_DAT_005aa940` = directional /
running jump impulse; `0x39` is an "airborne / jump taken" flag; `0xd3` gates whether the
command still needs sending (already-set suppression).
**Unknown:** absolute values of the two floats (read at runtime from memory — require a dump
of `_DAT_005aa93c/940`), and what case `2`'s `-1.0f` argument orients.

> **Cross-check:** this is the **third** subsystem seen routing through **vtable `+0xc`**
> (input `0x33` in §1.12, damage `0xd` in §1.10, jump `7` here). `+0xc` is the object's
> single **command-dispatch channel**, and the payload is always `(cmd, ptr, len)`.

### 1.14 Wall-contact dynamics — ✅ confirmed
> Source: `FUN_004cd200` (0x4cd200), decompiled `decomp_4CD200.c`.

- Gated on **`param_1[0x18] == 1`** (a contact/state flag) plus a time test:
  `FUN_00549b00()` returns a `long double` compared against **`_DAT_005aa8f0`** (interval).
- If `param_1[0x3a] != 0`, a second temporal gate against **`_DAT_005aa8e8`** escapes early
  via `vtable[+0x104]()`.
- Otherwise it fetches a transform through `**(param_1[4]) + 4` into a 12-byte buffer, then
  again emits **`vtable[+0xc](7, &ptr, 4)`**.
- Velocity accumulation on fields `+0xe4 / +0xe5 / +0xe6`, blending with **`_DAT_005aa8e0`**
  and **`_DAT_005a83ec`**: e.g.
  `*pfVar1 = (float)param_1[0xe4] * _DAT_005aa8e0 + param_1[0x31] + param_1[0x34] * _DAT_005a83ec`,
  then accumulated back into `*pfVar1` — an **incremental velocity blend**, consistent with
  slide-along-wall.
- Final optional step: if `param_1[0x2a] != 0 && param_1[0xea] != 0`, calls
  `vtable[+0xfc](out, out, ?, ?, param_1+0x2b, 1, 0)` and stores the result to
  `param_1[0xda]`.

**Confirmed:** the two time globals, the `0x18`/`0x3a` gates, the two blend coefficients, the
`(7, …)` command emission, and that integration is **additive into existing velocity**
rather than a replacement.
**Inferred:** this is the **wall-slide / sticking** pass that runs *after* the §1.9 physics
integrator; `FUN_00549b00` is the engine timer.
**Unknown:** the numeric values of the three float globals, and what `vtable[+0x104]`
(the early-out path) represents.

### 1.15 Note on `FUN_004d0540` (impulse maths) — ✅ confirmed (terminology reconciled)

Body `0x4d0540–0x4d0a8c` (**1,356 B**). It performs **direction negation × global
coefficient + quaternion construction + list recycle**, and it contains the previously
byte-verified impulse maths at **`0x4d0674–0x4d06be`**: `fmul [0x5aa934]` (= **600.0**) and
`fadd [0x5aa944]` (= **0.13**).

The two descriptions ("OnHit impulse equation" vs. "direction negation × global
coefficient") are **the same maths**: `V = n̂ · 600` with the normal negated, plus the 0.13
offset — i.e. impulse along the reflected contact normal at magnitude 600, with a small
bias term. `vtable[+0x110]` anchoring is unchanged. **No separate investigation needed.**

### 1.16 The `vtable+0xC` command pipe (receiver side) — ✅ confirmed (end-to-end, byte-anchored)
> Method: no strings used. vtable occupancy scan + **arity proof** (`RET n` byte count) only.

**Why this pass exists.** §1.9/1.10/1.12–1.14 established that six unrelated combat functions all emit
`this->vtable[3](cmd, buf, len)` with `cmd ∈ {0x33 input, 0xd damage, 7 jump/wall}`. That pointed at one
shared channel. This section resolves **the receiving side**, hop by hop.

**Hop 0 — all six senders are methods of one class.** Vtable-occupancy scan (`VtabMap.java`,
`EvPipe.java`): every one of `FUN_004cb260 / 004cd200 / 004ceb50 / 004cf5b0 / 004d0540 / 004d0ac0`
occurs exactly once in the pointer array beginning at `0x005aa658` (150 consecutive function
pointers). One class family, verified six ways.

**Hop 1 — the operative slot-3 is `FUN_004a9770`, by arity proof.** Several vfptr values are legal
for one object under MSVC multiple inheritance. All five values written by constructors were
resolved and their `slot-3` target checked:

| vfptr written | slot-3 target | return instr | arity | verdict |
|---|---|---|---|---|
| `0x005aa658` | `FUN_004c8a70` | tail-`JMP [EDX+0xc]` | 0 | ❌ would corrupt stack by 12 B |
| `0x005aa65c` | `FUN_004c8bd0` | `RET 0x4` | 1 | ❌ |
| `0x005aa660` | `FUN_004c9180` | `RET` | 0 | ❌ |
| **`0x005aa6a8`** | **`FUN_004a9770`** | **`RET 0xc`** | **3** | ✅ matches `(cmd,buf,len)` |
| `0x005aa88c` | `FUN_004d1630` | `RET` | 0 | ❌ |

> **Precise reconciliation of a prior claim.** Read literally, `mem[0x005aa658 + 0xc]` **is**
> `0x004c8a70`, so the earlier statement "`vtable[3] = 0x4C8A70`" is byte-true for that base. But that
> entry takes **no arguments** and its body merely clears five member vectors (then tail-jumps), i.e.
> a destructor-shaped routine. The binding actually bound at the six send sites is `FUN_004a9770`
> under vfptr `0x005aa6a8`.

```asm
; FUN_004a9770  (18 bytes) — the shared slot-3 forwarder
004a9770  MOV ECX,[ECX+0xc]        ; inner = this->member_0xc
004a9773  TEST ECX,ECX
004a9775  JZ   +7
004a9777  MOV EAX,[ECX]
004a9779  JMP  dword ptr [EAX+0x20]   ; tail-forward: inner->vtable[8](cmd,buf,len)
004a977c  OR EAX,-1
004a977f  RET 0xc                      ; no inner → return -1
```
`FUN_004a9770` occupies slot 3 in **32 vtable slots** — the most shared slot-3 implementation in the
binary. Its second-level sibling `FUN_004a9790` (32 B) does the identical forward explicitly.
This is a **bridge/decorator pattern**: the slot-3 method is *only* a router, never a handler.

**Hop 2 — the terminal dispatcher `FUN_004bb800`.** The class whose vtable begins `0x005a9fe0`
(225 slots) has `slot 8 = 0x004bb800`, `slot 3 = 0x004a9770`. It is the only function in the binary
that simultaneously satisfies: (a) occupies slot 8, (b) carries a computed jump (jump table at
`0x004bbfe8`), (c) returns `RET 0xc`.

```c
uint __thiscall FUN_004bb800(int *param_1, int param_2, uint *param_3, int param_4)
// this, cmd, payload, len — 387 lines, 44 case labels, range 0x3 … 0x35
```
Each case forwards to a virtual slot of **the same object** — the command table is a
`cmd → member-function-slot` registry, not behaviour:

| cmd | target | cmd | target | cmd | target |
|---|---|---|---|---|---|
| `0x05` | `vtable[59]` | `0x17` | `vtable[87]` | `0x2c` | `vtable[14]` |
| `0x06` | `vtable[51]` | `0x19` | `vtable[90]` | `0x2d` | `vtable[15]` |
| `0x07` | `vtable[106]` | `0x1a` | `vtable[77]` | `0x30` | `vtable[16]` |
| `0x0a` | `vtable[60]` | `0x1c` | `vtable[48]` | `0x31` | `vtable[120]` |
| `0x0c` | `vtable[49]` | `0x1d` | `vtable[31]` | `0x32` | `vtable[121]` |
| `0x0f` | `vtable[19]` | `0x1e/0x1f` | `vtable[26]` | **`0x33`** | **`vtable[122]`** |
| `0x13` | `vtable[41]` | `0x20` | `vtable[28]` | `0x35` | `vtable[18]` |
| `0x14` | `vtable[46]` | `0x22/0x2b/0x2e` | `member+0x88 → vtable[13]` | `0x10` | same indirect |
| `0x15` | `vtable[112]` | `0x18` | `singleton→vtable[136]` | `0x34` | `singleton→vtable[222]` |
| `0x16` | `vtable[84]` |  |  |  |  |

Gaps in `0x03–0x35`: **14, 18, 35, 36, 37, 38, 39** (no case).
Cases `0x03/0x04/0x08/0x09/0x0b/0x0d/0x11/0x21/0x28/0x29/0x2a/0x2f` handle inline (field writes, e.g.
`+0xfc`, `+0xc2`) rather than dispatching. Full table: `cmd_dispatch_map.json`.

**Hop 3 — `case 0x33` → `FUN_004bc100`.** `mem[0x005a9fe0 + 0x1e8] = 0x004bc100` (31 bytes):

```asm
004bc100  PUSH ESI
004bc101  CALL 0x00487830          ; lazy singleton getter
004bc106  MOV ECX,[ESP+0x8]        ; payload buffer
004bc10a  MOV EDX,[EAX]            ; singleton vptr
004bc10c  MOV ESI,[ECX+0x4]        ; b = buf[1]
004bc10f  MOV ECX,[ECX]            ; a = buf[0]
004bc111  PUSH ESI
004bc112  PUSH ECX
004bc113  MOV ECX,EAX
004bc115  CALL dword ptr [EDX+0x37c]   ; singleton->vtable[223](a, b)
004bc11c  RET 0x4
```

**Hop 4 — the singleton and the gate.** `FUN_00487830` is a classic lazy singleton:
`if (DAT_006659b8 == 0) DAT_006659b8 = FUN_00486610(operator_new(0x2970))` — a **10,608-byte** object,
stored in the global `DAT_006659b8`, constructed by `FUN_00486610`. That constructor writes vfptr
`0x005a9068` (primary) and `0x005a9444` (secondary base). Resolved by arity again — the call passes
two arguments, so the target must end in `RET 0x8`:

| vfptr | slot-223 target | return | arity | verdict |
|---|---|---|---|---|
| **`0x005a9068`** | **`FUN_00489510`** (51 B) | **`RET 0x8`** | **2** | ✅ |
| `0x005a9444` | `FUN_004a0370` (30 B) | `RET 0x4` | 1 | ❌ (deleting dtor shape) |

```c
// FUN_00489510 — GATE + forward
if (this->vtable[218]() == 0) return 0;                      // gate
return this->member_0x2410->vtable[13](a, b) != 0 ? 1 : 0;   // forward, returns success flag
```

**Confirmed facts.** The complete delegation chain (4 hops, every hop anchored by `RET n` arity and
memory reads); the 44-entry command→slot registry; gap set; the two-level forwarding stubs
(`0x4a9770`, `0x4a9790`); the singleton's construction site and size; the gate at `FUN_00489510`.

**Inferred.** `buf[0]/buf[1]` for `0x33` are the two motion axes packed by the input sampler
(consistent with `0x4cb260` writing three dwords into a 16-byte packet). `vtable[218]` is a
"can-accept-input" predicate (gating input during hit-stun / cutscene / menu). `FUN_004bb800`'s
relative ordering of cmd IDs suggests `0x03–0x0f` ≈ core state commands, `0x28–0x35` ≈ UI/debug tier.

**Unknown.** Identity of the object at `member_0x2410` and its `vtable[13]` handler — that is where
the per-frame action FSM actually begins, and it is **exactly one hop beyond this round**. Whether
the gate is hit-stun, menu focus, or both. Nothing in this chain touches combo counters or resource
spend — so **combo / cancel-window semantics remain unlocated** (unchanged from the previous pass).

**Implication for MeteorRebuild.** The original is a three-layer bridge, not a switch:
`Emitter → this->vtable[3] (router) → inner->vtable[8] (switch) → this->vtable[N] (handler) → singleton`.
Rebuild it as `ICommandSink.Handle(cmd, payload, len)` with a **command→slot registry loaded as data**
(the `cmd_dispatch_map.json` table is directly reusable), and keep the router trivial. The presence of
a **gate before the real handler** is a behavioural detail most clones miss — and it likely *is* the
runtime half of the cancel window (data side = the `.pos` / action-window fields already covered by
the `ActionInterrupt` work).

---

### 1.17 The fifth hop — `member_0x2410` resolved (and the cancel-window hypothesis refuted)
> Method: listing only. **No decompiler** — `DecompInterface` hangs indefinitely on `FUN_004c8eb0`
> (killed after 38 min wall clock, zero output growth); raw listing answered everything in one pass.
> Stop-rule agreed in advance: *if `vtable[13]` turned out to be another pure router, stop there.*
> **It did not**, so this section delivers the resolved object.

#### 1.17.1 What the gate actually is — ❌ my cancel-window hypothesis is REFUTED

`GameApp` slot 218 was read directly from `mem[0x005a9068 + 0x368]`, not inferred:

```asm
; FUN_004891c0  (14 bytes) — GameApp::IsSubsystemLoaded()
004891c0  MOV EDX,dword ptr [ECX + 0x2414]
004891c6  XOR EAX,EAX
004891c8  TEST EDX,EDX
004891ca  SETNZ AL
004891cd  RET
```

It reads `this + 0x2414`, the **4 bytes immediately following the `member_0x2410` pointer** — a
readiness flag, not `unit+0x11c` (anger) and not any hitstun field. Two outcomes were agreed up front;
the second occurred, so the hypothesis is dead **by evidence, not by exhaustion**:

| predicted if hands-on-hand feel gates on "can I cancel now" | observed |
|---|---|
| gate reads unit state (anger `+0x11c` / hitstun / action id) | reads a **load flag** at a fixed `GameApp` offset |
| gate varies per hit | gate is **constant** until the subsystem is swapped |

**Corrected model:** the gate is a *lifecycle* check (`is this command sink attached?`), not a
*window* check. Consequently the cancel window has **no counterpart in this chain** — the runtime
side is not here, which upgrades the earlier "probably data-driven" reading to the default position
for MeteorRebuild: implement cancel windows purely from the action/`.pos` data and do not look for a
runtime gate to mirror.

#### 1.17.2 `FUN_00489510` (slot 223) — the whole body, confirmed

`undefined4 __thiscall (GameApp *this, int a, int b)`, `RET 0x8`, 51 bytes, listing verbatim in
`lasthop2.txt`. Both earlier readings of the body hold; note the argument order is **stdcall
(right-to-left)**: `b` is pushed first, so the callee sees `(a, b)`.

```c
if (this->vtable[218]() != 0) {          // IsSubsystemLoaded()
    this->member_0x2410->vtable[13](a, b);
    return 1;                             // accepted
}
return 0;                                 // swallowed silently
```

#### 1.17.3 Who `member_0x2410` is — three independent anchors converge

| anchor | value | how obtained |
|---|---|---|
| allocation size | **0x118 = 280 B** | `operator_new(0x118)` at two load sites (`FUN_004890a0`, `FUN_00489570`) |
| constructor | **FUN_004C8730** (324 B) | called with the fresh block in `ECX` |
| **vfptr** | **`0x005AA660`** | `MOV dword ptr [ESI],0x5aa660` @ `0x004c8854` inside that ctor; second writer `0x004c88c1` in `FUN_004c88a0` |

Constructor `FUN_004C8730` zeroes members `+0x8 … +0x50` (including the trio `+0x28 / +0x2c / +0x30`,
recognisable as an MSVC `std::vector`'s `begin / end / capacity`), then constructs an inner object at
`LEA ECX,[ESI+0x58]`. This is the **same `0x005aa660` that appeared as a row in the §1.16 arity
table** — in §1.16 it was one of five vfptr candidates and was rejected *as the sender's base*; that
rejection stands and is unrelated to its identity here as this object's vfptr.

#### 1.17.4 Lifecycle: the object is hot-swappable, and always starts absent

Three `GameApp` methods write `member_0x2410`; together they form a textbook attach/detach pair.

```c
// FUN_00487450 (984 B) — called LAST inside FUN_00486610, after `*this = &PTR_FUN_005a9068`
// zeroes 0x2410, 0x2414, 0x2418, 0x2420 alongside twenty-odd other members  → subsystem starts absent

// FUN_004890a0 (167 B) — vtable slot 211 — Attach(flag)
void __thiscall Attach(GameApp *this, int enable) {
    if (enable != 0) {
        this->0x2414 = 1;                                  // gate opens
        if (this->0x2410) this->0x2410->vtable[0](1);      // release the old one
        p = operator_new(0x118);
        obj = p ? FUN_004C8730(p) : 0;
        this->0x2410 = obj;
        obj->vtable[2](0);                                 // Init(0)
    } else {
        this->0x2414 = 0;                                  // gate closes, old object kept
    }
}

// FUN_00489570 (159 B) — vtable slot 214 — TryLoad(id) : bool
p = operator_new(0x118); obj = FUN_004C8730(p);
if (obj->vtable[15](id) != 0) { Release(this->0x2410); this->0x2410 = obj; return 1; }
return 0;   // rejected — nothing is swapped in

// FUN_00489150 (37 B) — vtable slot 245 — Detach(): release + zero both 0x2410 and 0x2414
```

`operator_new` of **exactly one size for one type**, validated *before* it can replace the live one —
this is a **plug-in slot**, e.g. one moveset / one driver per game mode.

#### 1.17.5 `vtable[13]` — not a router. It is the input-intent **queue producer**

`FUN_004C8EB0`, 175 B, `RET 0x8`, `__thiscall`. Full listing in `terminus2.txt`; reconstructed:

```c
// PER: member_0x2410 -> vtable[13](int x, int y)
a = clamp(x, -1, 1);                 // 004c8eb7–0x4c8ecf
b = clamp(y, -1, 1);                 // 004c8ed2–0x4c8eea
key = (b + 1) << 8 | (a + 1);        // both axes packed into one int, value set {(0,1,2)}²

vec = this + 0x28;                   // MSVC vector: begin / end(0x2c) / capacity(0x30)
if (begin != end && *(int *)(end - 8) == key)
    goto done;                       // ★ identical trailing entry → NOT enqueued again

t = FUN_00549B00(this + 0x58);       // returns a float
if (end == capacity)  FUN_004CA1F0(vec, end, &key);        // slow path: grow + push
else if (end != 0)  { *(int *)end = key; *(float *)(end + 4) = t; end += 8; }
this[0x34] = begin;                  // cache front for the consumer
done: return;
```

Three structural facts, all byte-level:

1. **entry size = 8 bytes** — `{ int32 packed key; float32 t }` (`MOV [EAX],ECX`; `MOV [EAX+0x4],EDX`;
   `ADD EAX,0x8` at `0x004c8f32`).
2. **de-duplication** — a repeat of the trailing key is dropped (`0x004c8f03` → done at `0x004c8f57`).
3. **inputs are two tri-state axes** clamped to `{-1,0,1}`, packed into one integer — i.e. the *signed
   direction axes* already described in §1.12, carried all the way here.

> **Stop rule check.** On the pre-agreed criterion — "another pure router like slot 3?" — this is
> 175 bytes of clamp + pack + dedupe + fast/slow push paths with **two real calls inside**. It is a
> **terminal**. Investigation continues one step further only because it stopped being a chain and
> became a data structure.

#### 1.17.6 The consumer candidates (superseded by §1.18 — read that instead)

Scanning every method reachable from `0x005aa660` for *queue-walk* shape (touching both `+0x28` and
`+0x2c` with 8-byte stepping and backward jumps — `terminus3.txt` §B) ranks two identical-signature
methods far above the rest:

| slot | function | size | touches `+0x28`/`+0x2c` | back-jumps | note |
|---|---|---|---|---|---|
| 15 | **FUN_004C94A0** | 1062 | 6 / 6 | 5 | `LEA EDI,[ESI+0x28]` @`0x004c9748`; calls **`FUN_00487830`** (the GameApp singleton) then `GameApp->vtable[133]` @`0x004c953a` |
| 19 | **FUN_004CC130** | 1174 | 1 / 1 | 0 | also reads both, long body |
| 14 | FUN_004C91A0 | 727 | 3 / 5 | 5 | same prologue family |

Slot 15 is *already known from the other side*: §1.17.4 showed it is the validator that `TryLoad`
calls before swapping this object in. **Producer and consumer are methods of one object, and that
object calls back into `GameApp`** — the chain closes into a loop, not a dead end.

#### 1.17.7 Bonus: the Tier-1 anchors are in this same pointer run

The 150-pointer run reached from `0x005aa660` resolves to:

| vtable slot | function | earlier section |
|---|---|---|
| 21 | `FUN_004a9770` (18 B) | §1.16 hop-1 router |
| 26 | `FUN_004a9790` (32 B) | §1.16 second router |
| 39 | `FUN_004cb260` | §1.12 input sampling → cmd `0x33` |
| 66 | `FUN_004d0540` | §1.15 impulse maths |
| 67 | `FUN_004d0ac0` | §1.10 four-tier knockback |
| 75 | `FUN_004cd200` | §1.14 wall dynamics |
| 81 | `FUN_004ceb50` | §1.9 main physics integrator |
| 84 | `FUN_004cf5b0` | §1.13 jump dispatch |
| 147 | `FUN_004d1740` | §1.11 keyword-table parser |

🟡 **Inferred, deliberately not promoted to confirmed** — that these form **one** vtable rather than
several adjacent vtables in one pool. The pointer-run contiguity is byte-fact; single-class membership
is not, because methods such as `FUN_004ceb50` address `this + 0x35c` (`self[0xd7]`, §1.9), which the
confirmed **280-byte** object of §1.17.3 cannot contain. Either the Tier-1 methods belong to a larger
class whose vfptr shares this run, or `this` reaches them through an inner member. Resolve before use.

#### 1.17.8 Buckets

**Confirmed** — gate is a load flag at `GameApp+0x2414`; slot 223 forwards `(a,b)` and returns 1/0;
`member_0x2410` = a 280-byte object of vfptr `0x005aa660`, ctor `FUN_004c8730`, hot-swappable via slots
211/214/245; `vtable[13]` enqueues 8-byte `{key,float}` records with trailing-key dedupe; that object
also owns the validator (slot 15) and the largest candidate consumers (slots 15/19).

**Not yet shown:** where any entry is matched against a move list, i.e. no combo *match* hardware has
been read.

**Unknown — 5th honest record.** Combo counters and resource spend still appear nowhere in five hops.
The difference from the previous four records: the search space is no longer unbounded. It is now
`FUN_004c94a0` and `FUN_004cc130`. Anything outside those two is outside this subsystem.

**Implication for MeteorRebuild.** Build it as an **input-intent queue**, not as a switch on key state:
`{ int packedAxes; float value; }`, 8 bytes, append with trailing-duplicate suppression, drain in a
single consumer that may query `GameApp`. Suppressing consecutive identical entries is a *feel*
decision — with it, a held direction is one intent; without it, every frame is one intent, and the
downstream timing table would have to compensate. Reimplement `cancel windows` from data only.

---

### 1.18 Both consumer candidates opened — §1.17.6 revised, one candidate eliminated
> Method: listing only (see §1.17 caveat — the decompiler hangs on this family). Independent audit by
> the reviewer confirmed every byte-level claim of §1.17 beforehand, including the Tier-1 slot map of
> §1.17.7 (**7/7 slots re-read and exact**) and the run-nature verdict: a *cross-class method-family
> run*, not one vtable. The `🟡 inferred, unproven` grading stands.

#### 1.18.1 A new target first: `GameApp->vtable[133]` is not a decision point

Your hypothesis was that vtable[133] held the intent→action verdict. It does not. Read from
`mem[0x005a9068 + 0x214]`:

```asm
; FUN_0049a3b0  (23 bytes) — GetLimits(int *a, int *b)
0049a3b0  MOV EAX,[ESP+0x4]
0049a3b4  MOV ECX,[ESP+0x8]
0049a3b8  MOV dword ptr [EAX],0x9     ; *a = 9
0049a3be  MOV dword ptr [ECX],0x7     ; *b = 7
0049a3c4  RET 0x8
```

A **constant getter**. Downstream (`0x004c9540`–`0x004c9560`) both values are used as capacity ceilings
(`if (9 > count) fail`, `if (7 > count) fail`), i.e. bounds guards before the load. Revise the mental
model: `GameApp` is a **provider of limits and lifecycle**, not the arbiter of moves.

#### 1.18.2 Slot 15 is NOT a combo matcher — it is a three-queue loader (inference retracted)

I predicted a matcher. The listing says otherwise. `FUN_004C94A0` (1062 B, **`RET 0x4`** = one argument)
is a serialise/replay routine, and the three vectors first seen as zeroed blocks in the constructor
(§1.17.3) turn out to have **three different entry strides**:

| vector | member | entry stride | evidence | slow path |
|---|---|---|---|---|
| A | `this+0x18` | **12 B** | `PUSH 0xc` @`0x004c9700`; writes `[EAX]`,`[EAX+0x4]`,`[EAX+0x8]`; `ADD [EDI+0x4],0xc` | `FUN_004c9eb0` (747 B) / `FUN_004c9b80` (731 B) |
| B | `this+0x28` | **8 B** | `MOV EBP,0x8` @`0x004c974b`; writes `[EAX]`,`[EAX+0x4]`; `ADD [EDI+0x4],EBP` — the input-intent queue of §1.17.5 | `FUN_004ca1f0` (638 B) |
| C | `this+0x38` | **16 B** | `PUSH 0x10` @`0x004c97a6` | `FUN_004ca4c0` (731 B) / `FUN_004ca7f0` (747 B) |

Shape of the whole body:

1. magic check **0x1e0d** (7693) — `MOV EDI,0x1e0d`, `CMP [ESP+0x94],EDI`, `JNZ fail`;
2. `GameApp` singleton → `vtable[133]` → limits `(9, 7)` → capacity guards;
3. **three bounded loops**, each `DEC reg / JNZ`, filling A then B then C via the shared append helper
   `FUN_00507fb7` (72 B, called **18 times**);
4. `CALL dword ptr [EAX+0xc]` @`0x004c9865` — **the §1.16 command channel**, sent once at the end;
5. `RET 0x4`.

So the object is a **composite record**: three typed queues — 12-byte, 8-byte and 16-byte entries —
loaded together and shipped as one command. Its role as `TryLoad`'s validator (§1.17.4) now reads
correctly: it validates by **attempting the load**, not by matching anything.

#### 1.18.3 Slot 19 — the one that survived: a per-frame driver

`FUN_004CC130`, 1174 B, ends in a bare **`RET`** (no `RET n` ⇒ thiscall with **no** extra arguments).
That signature is the per-frame tick signature, and the body agrees:

```asm
004cc141  CMP dword ptr [ESI + 0x10],EDI      ; gate on this->0x10
004cc144  JZ  0x004cc5be                       ; absent → early exit, nothing happens
004cc14a  MOV ECX,dword ptr [ESI + 0x348]      ; NOTE: +0x348 > 280 B — a larger class than §1.17.3
004cc157  CALL dword ptr [EAX + 0x58]          ; that member's vtable[22]
004cc167  LEA ECX,[ESI + 0x18]                 ; the 12-byte queue A
004cc19f  CALL 0x00487830                      ; GameApp singleton
```

Three findings that matter:

1. **It shares the time source with the producer.** `FUN_00549B00` supplies the float stored into every
   8-byte entry at `this+0x28` (§1.17.5) *and* is called here at `0x004cc221` and `0x004cc392`. One
   clock for write and read — which is what makes those floats legible as timestamps rather than weights.
2. **A dense polymorphic dispatch chain.** Ten consecutive slots of one interface are called in
   sequence — `+0xcc, 0xd0, 0xd4, 0xd8, 0xdc, 0xe0, 0xe4, 0xe8, 0xec, 0xf0` (`0x004cc439`–`0x004cc549`).
   That is not a `switch`; it is a fan-out over an interface, the shape you get when behaviour is
   selected by object identity rather than by a command value.
3. **300 recurs.** `0x12c` appears three times here and once in the constructor (`MOV [EDI+0x30],0x12c`,
   §1.17.3). A magic number shared between construction and the tick is a prime suspect for a window
   or budget constant. 🟡 — unproven, but it is the first candidate worth a targeted experiment.

#### 1.18.4 Buckets after this pass

**Confirmed** — `GameApp vtable[133]` returns the constant pair `(9, 7)` and is used for capacity
guards; slot 15 is a **three-stride queue loader** (12 / 8 / 16-byte entries) that emits one
`vtable+0xc` command when it succeeds, gated on magic `0x1e0d`; slot 19 is a **zero-argument per-frame
driver** sharing `FUN_00549B00` with the producer and fanning out over ten consecutive interface slots.

**Retracted (mine)** — §1.17.6 named slot 15 as the consumer where combo logic must live. It is a
loader. Do not chase matching logic there.

**Unknown — 6th honest record.** No combo counter, no resource spend, no move list matching has been
read anywhere. What changed this time is not success but **compression**: after six attempts the
unread surface is one function, `FUN_004CC130`, and inside it two concrete leads — the shared clock
`FUN_00549B00` and the constant `0x12c`. Anything outside it is outside this subsystem.

**Implication for MeteorRebuild.** Two things moved. First, **do not model the clone as matching against
a table inside the receiver** — the receiver loads typed queues on request (`TryLoad` = attempt the
load, magic `0x1e0d`, limits `9`/`7`). Second, the **per-frame shape is now specified**: a zero-arg tick
that early-exits on a null member, reads a queue, obtains one timestamp, then fans out over an
interface. Build that shape and leave the move table as data; swapping the table should not require
touching the driver.

---

### 1.19 Workspace ledger — two project trees exist (for the repo docs)
> Administrative, not behavioural. Recorded here because this is the working copy; **the decision to
> write it into `MeteorRE`'s audit document belongs to the repository owner.**

| | tree A — release source | tree B — analysis workspace |
|---|---|---|
| path | `D:\MeteorRE` | `D:\xinnixiang\nixiangyuama` |
| git | yes, frozen and pushed | **none** (`ls -d .git` → not found) |
| docs/10 | `10_TEXT_COVERAGE_AUDIT.md`, **632 lines** | `10_REA_PROMPTS_TEMPLATE_VERIFICATION.md`, **3,953 lines at 23:10** |
| R50 artefacts | absent | `r50v{,2,3,4,5}.py` + `r50v*_verify.txt` + `r50_apply.py` |
| `claim_audit.json` | absent | `data/claim_audit.json` (54,894 B; `.bak_r50` 43,843 B) |

**Why the "docs/10 doesn't match" mystery had two causes, not one.** They are not two versions of one
file — tree B's `docs/10` is a **different document** with a different name, and its line count was
still growing when it was read (mtime later than the reading clock). Both trees also carry **different
content** under identical numbers 01–09, e.g. `07_INPUT_AND_COMBO_BUFFER` is 2,614 B in A and 13,915 B
in B, `09_CAMERA_AND_EFFECT_SYSTEM` is 3,391 B in A and 78,715 B in B. The numbering is not shared.

**Asset guard — the scan you asked for, run on tree B. It has content.**

| tree B directory | size | what is in it |
|---|---|---|
| `extracted_assets/UITexture` | 368 K | 58 files — `A0..A11`, `AF001-3`, `AT001`, `ATarget`, `Asnow`, `FLAG01`, `FW01–FW12`, `NET`, `arrow`, `circle`, `ray`, `star` … **`.bmp` / `.jpg` / `.tga`** |
| `extracted_assets/ETexture/ETexture` | 1.3 M | `Allbin00-403`, `Ball0b00`, `CTP0h00`, `FF80100`, `FIRE2/3`, `FIRL3600`, `FLASH000-607` … `.BMP` |
| `extracted_assets/ctexture` | 6.2 M | further original art |

≈7.9 MB of original game imagery in tree B. **No `.git` today, so nothing can leak right now** — but this
is exactly the class of content the release tree was scrubbed of, and it means tree B **must** pass the
same zero-asset scan before it ever gets a remote. Recommend adding tree B explicitly to whatever
pre-push procedure already covers tree A.

---

### 1.21 Round 7 groundwork — the fan-out is a switch, and it builds a direction string
> Includes a retraction of my own §1.18.3 bullet 2.

#### 1.21.1 Retraction: it *is* a switch

§1.18.3 claimed: *"not a switch; it is a fan-out over an interface, behaviour selected by object
identity."* **Wrong.** In `0x004cc42b`–`0x004cc549`, every branch ends in **`JMP 0x004cc54f`** — one
shared epilogue. That is the definition of a multi-way branch. Moreover there is **no jump table**:
the cases are reached by `TEST`/`CMP`/`JZ` chains, i.e. a compiler-lowered `if/else if` or dense `switch`.

#### 1.21.2 The selector is not a weapon type — it is a direction string

Hypothesis put forward for round 7 was that the ten consecutive slots `+0xCC…+0xF0` are indexed by
weapon type. The listing does not support that; it supports something better.

Every case has the identical shape:

```asm
004cc4e3  MOV EAX,[ESP+0x1c]
004cc4e7  MOV ECX,[ESP+0x18]
004cc4eb  MOV EDX,[ESI]              ; <- always this->vptr (ESI unchanged throughout)
004cc4ed  PUSH EAX
004cc4ee  PUSH ECX
004cc4f1  CALL dword ptr [EDX + 0xd4] ; one slot, chosen per case
004cc4f7  JMP 0x004cc54f              ; shared epilogue
```

and each case is preceded by a **buffer append**:

```asm
004cc245  LEA EDI,[ESI + 0x2e8]       ; begin/end/capacity triple = MSVC string or vector<char>
004cc2a6  MOV byte ptr [ECX],0x66     ; 'f'
004cc2eb  MOV byte ptr [EAX],0x62     ; 'b'
004cc337  MOV byte ptr [ECX],0x6c     ; 'l'
004cc30f  MOV byte ptr [ECX],0x72     ; 'r'
004cc24f  MOV byte ptr [EAX],0x0      ; terminator
```

**The vocabulary is exactly four characters: `f` · `b` · `l` · `r` — forward, back, left, right.**
The selector reads `this+0x60` (`0x004cc257`) and `this+0x64` (`0x004cc2f3`), appending one character
per axis combination into `this+0x2e8`, then branching to one of ten consecutive virtual slots.

#### 1.21.3 This closes the loop back to §1.12

`this+0x60` is the same field written to zero at the top of both `GetAsyncKeyState` samplers:

```asm
004cb283  MOV dword ptr [EDI + 0x60],EBP   ; FUN_004cb260   (§1.12 input sampler)
00503040  MOV dword ptr [EBX + 0x60],0x0   ; FUN_00503020   (its twin)
004cc257  MOV EAX,dword ptr [ESI + 0x60]   ; FUN_004cc130   (this tick, reads it)
```

Three functions, one field, no guessing. The IAT evidence from the aborted cross-check also belongs
here and is now confirmed: `0x005a8258 (PTR_GetAsyncKeyState)` has **exactly two referrers in the whole
image** — `0x004cb362` inside `FUN_004cb260` and `0x005030ba` inside `FUN_00503020` — and `FUN_004cb260`
fires the loaded pointer **eight times** (`CALL EBP` at `0x004cb369` … `0x004cb4f8`), one per virtual key.

#### 1.21.4 What round 7 is actually looking for

The previous six rounds looked for a *decision function* and never found one because there isn't one.
The shape is:

```text
per-frame tick (slot 19)
  └─ read polled axis state (this+0x60 / +0x64)      ← written by FUN_004cb260
  └─ append one of {'f','b','l','r'} to the buffer at this+0x2e8
  └─ select ONE of this->vtable[51..60] and call it (thiscall, 2 args)
  └─ shared epilogue
```

So ten consecutive slots `51–60` (`+0xCC`…`+0xF0`) are ten **per-weapon or per-state move handlers**,
selected by the accumulated direction string. The decision lives in the *comparison that builds and
matches that string*, not in any single named function.

#### 1.21.5 Ledger correction carried forward (second-order, still open)

My §1.19 asset figure of ~7.9 MB was **wrong by a factor of 7.4**. Independently re-measured after the
reviewer's correction: image assets (`jpg` 30.6 MB + `bmp` 24.7 MB + `tga` 3.4 MB) total **58.6 MB
across 1,753 files**, and the `sn01`–`sn22` level directories are indeed the bulk — my original count
only walked three named directories. The corrected figure is now recorded in the release tree
(`MeteorRE` commit `5c3798c`).

**Still unreported anywhere:** `extracted_assets` also holds ≈213 MB of *non-image* original assets —
`.pvb` 169.5 MB, `.gmb` 21.1 MB, `.zip` 10.0 MB, `.cob` 3.2 MB, `.wav` 2.4 MB, `.des` 0.9 MB. Those are
derived engine resources rather than art, so they may be in scope or out, but the guardrail note should
say so explicitly rather than leave it implied.

---

### 1.22 The attack key — found, and it is not where six rounds looked

> Round 7's second track. The previous six rounds searched for a *decision function*; this one
> searched for the **producer of the key event**, and the whole chain fell out in one pass. The
> conclusion is unambiguous: the attack input never touches the direction-intent queue directly.

#### 1.22.1 The key-event router

`FUN_004cb820(this, keyCode, pressed)` — **1,009 B, `RET 0x8`** — is the single entry point for
every discrete key transition. Body, in order:

```asm
004cb836  PUSH 0x8                 ; payload size
004cb838  PUSH &payload            ; 8-byte stack struct = {keyCode, pressed}
004cb839  PUSH 0x31                ; ---- cmd 0x31 ----
004cb845  CALL [EAX+0xc]           ; command channel, unconditionally, for every key

004cb848  CMP EDI,0x48             ; then: dispatch on keyCode
004cb85a  CMP EAX,0x27 / JMP [EDX*4 + 0x4cbc14]   ; 0x20..0x47 via byte index @0x4cbc40
004cba15  CMP EAX,0xa  / JMP [ECX*4 + 0x4cbc68]   ; 0x49..0x54 via byte index @0x4cbc80
004cbb6b  CMP EDI,0x1000           ; ------------------ MOUSE1 ------------------
004cbb73  CMP EDI,0x1200           ; ------------------ MOUSE2 ------------------
004cbc08  (default: return)
```

So every key press **and** release are recorded first (cmd `0x31`, `{key, pressed}`), then the
action dispatch runs. Recording is not conditional on the action being accepted.

#### 1.22.2 The attack branch, byte for byte

```asm
004cbbb0  TEST EBX,EBX          ; EBX = pressed
004cbbb2  JZ   0x004cbc08       ; release -> the branch consumes nothing at all
004cbbb4  MOV  EAX,[ESI]
004cbbb6  MOV  ECX,ESI
004cbbb8  CALL [EAX+0x1bc]      ; gate 1  = slot 111 -> FUN_004d0d90
004cbbbe  TEST EAX,EAX
004cbbc0  JNZ  0x004cbbe4       ; gate 1 non-zero => skip the request
004cbbc2  MOV  EDX,[ESI]        ; NOTE: two setup instructions sit between the
004cbbc4  MOV  ECX,ESI          ; gates; an excerpt that drops them shifts the
004cbbc6  CALL [EDX+0x1b4]      ; second call site by 4 bytes (0x4cbbc6, not 0x4cbbc2)
004cbbcc  TEST EAX,EAX
004cbbce  JZ   0x004cbbe4       ; gate 2 zero     => skip the request
004cbbd0  MOV  EDI,[ESI]
004cbbd2  PUSH 0x4              ; payload size 4
004cbbd6  CALL [EDI+0x94]       ; slot 37 -> FUN_004ce3c0, returns the payload value
004cbbdd  PUSH 0x1d             ; ---- cmd 0x1d ----
004cbbdf  CALL [EDI+0xc]
```

The three small resolvers, all byte-exact:

| slot | function | size | body |
|---|---|---|---|
| 111 (+0x1bc) | `FUN_004d0d90` | 24 | `return [this+0x10] && [this+0x34c]` |
| 109 (+0x1b4) | `FUN_004ce2d0` | 18 | `return [this+0x348] ? [this+0x348]->vtable[21]() : 0` |
| 37 (+0x94) | `FUN_004ce3c0` | 16 | `return [this+0x10] ? [this+0x10] - 0x65c : 0` |

Interpretation: attack requires **a live device pointer (+0x10), a non-zero state flag (+0x34c),
and a positive answer from a sub-object at +0x348** — then the payload is the device pointer
offset by `0x65c`, i.e. an entity handle, not a move id.

After the request the same branch runs a **report path**:

```asm
004cbbe4  CALL [EAX+0xa0]       ; slot 40 -> FUN_004cff40 (674 B)
004cbbf0  JZ   0x004cbc08
004cbbf2  CALL 0x00487830       ; GameApp singleton
004cbbfb  PUSH 0x5c9c34         ; the literal, see below
004cbc02  CALL [EDX+0x2b0]      ; GameApp slot 172
```

`0x005c9c34` reads **`"Active Attack"`** — a plain ASCII literal sitting immediately after the
action-name table of §1.21.4. It is the only string in this function and it fires *only* on the
MOUSE1 path. That is the hardest possible confirmation that this branch is the attack.

#### 1.22.3 `cmd 0x1d` terminates in a frame clock, not an action

§1.16's table maps `cmd 0x1d -> this->vtable[31] (+0x7c)`. Reading that slot on the input object
gives `FUN_004cf4c0` (122 B):

```asm
004cf4d9  MOV EAX,[ESI+0xe8]     ; lazily-created member
004cf4e1  JNZ 0x004cf516         ; already exists -> skip
004cf4e3  PUSH 0x48              ; ---- operator_new(0x48) ----
004cf4ff  CALL 0x005498c0        ; construct
004cf510  MOV [ESI+0xe8],EAX
004cf51c  PUSH 0x0
004cf51e  PUSH 0x0
004cf520  CALL 0x00549a90        ; (obj, 0.0, 0)
```

The 0x48-byte object is a **frame clock**, and its constants give it away:

| field | value | meaning |
|---|---|---|
| `+0x08`/`+0x0c` | `0` / `0x403e0000` | **double 30.0** |
| `+0x18`/`+0x1c` | `0x9999999a` / `0x3fc99999` | **double 0.2** |
| ctor | `CALL [0x5a81dc]`, `CALL [0x5a81d4]` | two time sources (perf-counter pair) |
| ctor | `FILD qword` / `FDIV double [+0x8]` | ticks / 30.0 => **frame number** |
| `+0x20`/`+0x28`/`+0x30`/`+0x38` | 64-bit pairs | now / deadline / start / last |

`FUN_00549a90(obj, double, int)` recomputes a deadline from the clock, i.e. it **arms a deadline
in 30 fps frames**. So `cmd 0x1d` does not choose a move — it **opens an attack timing window**.
Where that deadline is consumed is still unread (§1.22.7).

#### 1.22.4 Correction: the slot base was wrong, and two indices point at the same dword

The input object's vtable is **`0x005AA6A8`**, not `0x005AA660`. Two independent proofs:

1. `mem[0x5AA6B4] = 0x004A9770` — slot 3 must be the 18-byte router, and only the 0x5AA6A8 base
   puts it at slot 3.
2. Every function reached through 0x5AA6A8 touches *this* object's real fields (`+0x10` device,
   `+0x2e8` direction string, `+0x348`/`+0x34c` children, `+0x3c4` gate) — the members §1.21
   established independently.

Re-indexed table (all reads byte-exact):

| slot | A+off | function | size |
|---|---|---|---|
| 18 | +0x48 | `FUN_004d03f0` | 166 |
| 19 | +0x4c | `FUN_004ce230` | 32 |
| 20 | +0x50 | `FUN_004ce250` | 77 |
| **21** | **+0x54** | **`FUN_004cb260`** | **900** |
| 22 | +0x58 | `FUN_004cfc00` | 120 |
| 23 | +0x5c | `FUN_004cc0e0` | 47 |
| **24** | **+0x60** | **`FUN_004cbce0`** | **293** |
| 25 | +0x64 | `FUN_004cc600` | 69 |
| 26 | +0x68 | `FUN_004cf770` | 82 |
| 27 | +0x6c | `FUN_004cf7d0` | 147 |
| 28 | +0x70 | `FUN_004cf8c0` | 388 |
| 29 | +0x74 | `FUN_004cfb00` | 210 |
| 30 | +0x78 | `FUN_004cccb0` | 1345 |
| **31** | **+0x7c** | **`FUN_004cf4c0`** | **122** |
| 32 | +0x80 | `FUN_004cc840` | 1065 |
| 33 | +0x84 | `FUN_004ccc70` | 52 |
| 34 | +0x88 | `FUN_004cc650` | 218 |

The arithmetic settles the "run spans multiple classes" question **without** a class boundary:
`0x5AA660 + 39*4 = 0x5AA6FC` and `0x5AA6A8 + 21*4 = 0x5AA6FC`. **Same dword.** "Slot 39 of
0x5AA660" and "slot 21 of the input object" are one pointer counted from two bases 18 slots apart.
The run is contiguous .rdata; the apparent class-jumping was my own indexing error, not evidence
of a shared method family.

#### 1.22.5 The direction string is key-driven as well as tick-driven

`A.slot[24] = FUN_004cbce0` (293 B) is an **append-one-byte** helper on the string at `this+0x2e8`
— the exact buffer §1.21 analysed:

```asm
004cbce8  MOV EAX,[EDI+0x2ec]    ; end
004cbcee  MOV EDX,[EDI+0x2f0]    ; capacity
004cbcf4  LEA ESI,[EDI+0x2e8]    ; begin
004cbcfd  CMP ECX,EDX / JNZ ...  ; grow path CALL 0x0049be40
004cbd31  CALL 0x00402bc0        ; reserve
004cbd41  MOV byte ptr [ECX],BL  ; *end = char
```

Mechanism, stated precisely (this replaces an earlier loose wording): `FUN_004cbce0` has **zero
direct `E8` callers** in the whole image — it is reached only as **slot 24 / `+0x60`** through a
virtual `CALL [reg+0x60]`. The character arrives as the **stack argument** of that call, not from
any table lookup and not via `MOV BL,imm8`: the callee does `MOV EBX,[ESP+0x18]` and stores it with
`MOV byte ptr [ECX],BL` at `0x4CBD41` (+0x61 into the function). A raw `6A` census of
`FUN_004CB820` finds **28** `PUSH imm8` instructions, and exactly four of them are the direction
characters:

| char | push site | dispatch |
|---|---|---|
| `'r'` 0x72 | `0x004cb87c` | `CALL [EAX+0x60]` |
| `'l'` 0x6c | `0x004cb896` | `CALL [EDX+0x60]` |
| `'b'` 0x62 | `0x004cba37` | `CALL [EDX+0x60]` |
| `'f'` 0x66 | `0x004cbb07` | `CALL [EDX+0x60]` |

So the direction buffer has **two writers**: the per-frame tick (§1.21, axis-derived) and the key
router (edge-derived). Any clone must dedupe across both, not within one.

#### 1.22.6 What the four input commands actually carry

`FUN_004cb820` also explains the neighbouring producers found by the command-emission scan.

| cmd | producer | payload | bridge (C vtable `0x5A9FE0`) | GameApp | queue object B method | record |
|---|---|---|---|---|---|---|
| `0x31` | `FUN_004cb820` @`0x4cb839` | 8 B `{key, pressed}` | slot 120 `FUN_004bc0c0` | slot 220 `FUN_00489470` | method 10 `FUN_004c8c40` | 12 B -> queue `+0x18` |
| `0x32` | `FUN_004cb5f0` @`0x4cb696` | 12 B stick A | slot 121 `FUN_004bc0e0` | slot 221 `FUN_004894b0` | method 11 `FUN_004c8d80` | 12 B -> queue `+0x48` |
| `0x34` | `FUN_004cb5f0` @`0x4cb6a6` | 12 B stick B | — | slot 222 `FUN_004894e0` | method 12 `FUN_004c8e10` | 16 B -> queue `+0x38` |
| `0x33` | `FUN_004cb260` @`0x4cb53b` | 16 B `{fwd, right, counter, x}` | slot 122 `FUN_004bc100` | slot 223 `FUN_00489510` | method 13 `FUN_004c8eb0` | 8 B packed key -> queue `+0x28` |

All four GameApp stubs share one shape: gate `this->vtable[218]()` then forward to the queue
object, returning 1/0. `FUN_004cb5f0` (194 B) is the gamepad router — `MOVSD.REP` of 7 dwords from
`GameApp+0x1dcc`, one device read `CALL [ECX+0x4]`, then two stick records.

**The input layer is therefore a four-channel event recorder**, not a state snapshot: keys,
stick A, stick B and axes each land in their own typed queue, and one per-frame consumer
(B.slot 19, `FUN_004cc130`) drains them.

#### 1.22.7 Buckets

**Confirmed (byte-exact)**
- attack = **MOUSE1 `0x1000`**, handled in `FUN_004cb820`, **press-only**; the release branch does
  nothing at all (`0x4cbbb2 JZ 0x4cbc08`).
- jump = **MOUSE2 `0x1200`**, and it *does* handle release (`CALL [EDX+0x104]` at `0x4cbba1`).
- attack's command number is **`0x1d`**, payload 4 bytes.
- `cmd 0x1d` -> `vtable[31]` = `FUN_004cf4c0` -> lazily allocates a **0x48-byte 30 fps frame
  clock** and arms a deadline.
- `"Active Attack"` @`0x005c9c34`, reached only from the MOUSE1 branch.
- `0x31/0x32/0x33/0x34` are four distinct typed input channels, not four actions.

**Inferred**
- the armed deadline is what gates a follow-up attack (chain window); the consumer is unread.
- `FUN_004cff40` (slot 40) is a reporting/log path, not gameplay.

**Unknown**
- combo counters / resource spend — **7th record**. Nothing in the attack chain increments,
  decrements or compares a counter; the only numeric constant on the path is the 30.0 frame rate.
- where the 0x48 clock's deadline is read.

#### 1.22.8 Directives for MeteorRebuild

1. Attack must be modelled as an **edge event with two gates**, never as a polled axis. A clone
   that samples mouse-down per frame will double-fire.
2. Attack and jump differ in release handling — jump needs an explicit release path, attack must
   not have one.
3. The direction buffer needs **dual-source dedupe** (tick + key edge), and the buffer is a
   `std::string`-like growable byte array with a capacity field.
4. Model the input layer as four typed queues with timestamps, drained by one tick — do not
   collapse them into a single "input state".
5. `combo.json`'s `"SJ"`/`"SWJ"` alphabet maps onto the `f/b/l/r` set plus the attack edge; keep
   the mapping table external, because the binary keeps the *sequence* in a plain byte string and
   the *meaning* elsewhere.

> # ⛔ VOID as of 2026-10-28 01:15 — superseded by `D:\MeteorRE\docs\02_PLAYER_CONTROLLER_AND_PHYSICS.md` §二
>
> Everything below mis-identifies the PlayerController's **jump** machinery as an attack chain. The
> authoritative reading is in `docs/02`; this section is kept only as a record of the error.
> Three findings are retracted, each with a byte reason:
>
> 1. **`0.11` is a dimensionless ratio, not seconds.** `FUN_00549b00` ends both branches with
>    `FILD qword [esp+4]` / `FILD qword [esi+0x38]` / `FDIVP` (`0x549b30`, `0x549b58`) — Δticks divided
>    by the timer's own span. The "0.11 s ≈ 3.3 frames @30 fps" figure was *derived* from
>    `[+0x8] == 30.0`, but 30.0 is not the divisor. **Retracted.**
> 2. **`FUN_004cf540` is the hold-jump discriminator**, returning high-jump (1) / low-jump (0) — not a
>    window closer. Its boolean is a jump type, not a chain verdict. **Retracted.**
> 3. **`FUN_004cf5b0` is the jump dispatcher** (`PlayerController::vftable[86]`, offset `+0x158`), whose
>    three live cases are air-dash / ground-jump / wall-kick — not a 3-state chain machine. **Retracted.**
>
> Consequence: **282.0 / 375.0 are `kJumpSpeedLow` / `kJumpSpeedHigh`** (initial vertical speed) and
> `[+0x398]` is `jumpForceY`. The conclusion in §1.23.5 ("no combo counter — the chain is a window plus a
> multiplier") is therefore **void**: it described jump hold-length selection. The seven-round unknown
> about combo counters **returns to open**.
>
> Slot numbering note: the canonical base is **`0x5AA658`** (PlayerController primary), so `+0x158` is
> slot 86. The `0x5AA6A8`-based indices used below are the same dwords counted from the subobject base —
> same function, non-canonical label. Use `docs/02`'s numbering.

### 1.23 The attack window closes — and what it feeds

> Round 7's final hop. §1.22.3 left one question: `cmd 0x1d` arms a 30 fps clock at `A+0xE8`, so who
> reads it? The answer took four mechanical scans and produced two things the project had been
> hunting for seven rounds: the window length, and the only chain-state variable that exists.

#### 1.23.1 The storage target is a field, not a global

The user's proposed method (find the storage target, xref it, writers vs readers) works — but the
target is `A+0xE8`, a member of the input object, not a static address. Full-image scan of `+0xe8`
gives 78 functions, of which only seven are also A-class. Of those, exactly **four** are real field
accesses; the rest are `CALL [reg+0xe8]`, i.e. **virtual slot 58** (see §1.23.6 for why that
collision is dangerous):

| site | kind | function | meaning |
|---|---|---|---|
| `0x4CF510` | write | `FUN_004CF4C0` | arm: `operator_new(0x48)` → `[A+0xE8]` |
| `0x4CAFFF` | write | `FUN_004CAFB0` | state reset (`[A+0xE8] = 0`, plus `[+0x3D0] = 0x1869F`) |
| `0x4CADC9` | read | `FUN_004CADA0` | destructor: `operator_delete([A+0xE8])` |
| **`0x4CD3BE`** | **read** | **`FUN_004CD3B0`** | **the only gameplay reader** |

Bonus, and harder than the slot-3 argument: `FUN_004CADA0` writes the class token itself —
`MOV dword ptr [EBP], 0x5AA6A8` at `0x4CADC2`. That is a constructor/destructor vfptr store, so
`0x5AA6A8` as the input object's vtable is no longer an inference (§1.22.4) but a literal.

#### 1.23.2 The reader is slot 58, and it compares against 0.11

`FUN_004CD3B0` is **2,386 B, `RET 0x8`**, and it is **slot 58 (`+0xE8`)** of `0x5AA6A8`
(pointer at `0x5AA790` — its only reference in the image, which is why xref-based search finds
nothing and slot-based search finds everything).

```asm
004cd3be  MOV ECX,[ESI+0xe8]      ; the clock
004cd3c4  CMP ECX,EBP / JZ  skip  ; null -> main body
004cd3c8  CALL 0x00549b00         ; clock -> elapsed (double)
004cd3cd  FCOMP double ptr [0x005aa8e8]
004cd3d5  AND EAX,0x4100          ; C3|C2
004cd3da  JNZ 0x004cd3f5          ; elapsed < threshold -> main body
004cd3e0  CALL dword ptr [EAX+0x104]   ; slot 65 = close the window
004cd3e9  XOR EAX,EAX / RET 0x8
```

`0x005AA8E8` reads **0.11** (double, `3fbc28f5c28f5c29`), and `0x005A9D50` reads **30.0**
(double `403e000000000000`) — the frame rate from §1.22.3.

**So the attack window is 0.11 s ≈ 3.3 frames at 30 fps.** That is the first hard number for the
"cancel / chain window" that seven rounds of searching had failed to produce.

#### 1.23.3 The closer passes the verdict onward

Slot 65 = `FUN_004CF540` (107 B) — the symmetric half of the same test, using the same 0.11:

```asm
004cf543  MOV EAX,[ESI+0xe8] / TEST / JZ  return -1
004cf54f  CALL [EAX+0x180]        ; slot 96 gate -> if non-zero, return -1 (do nothing)
004cf55f  CALL 0x00549b00
004cf564  FCOMP double [0x005aa8e8]        ; 0.11 again
004cf571  JP  0x004cf57f
004cf575  PUSH 0x0 / CALL [EDX+0x108]      ; not yet expired -> slot 66 with FALSE
004cf583  PUSH 0x1 / CALL [EAX+0x108]      ; expired         -> slot 66 with TRUE
004cf58f  operator_delete(clock); [A+0xE8] = 0
```

So the window object is single-use: closed → destroyed. The boolean handed to slot 66 is the
**only** state that survives the window, and it is the chain's whole memory of the previous attack.

#### 1.23.4 Slot 66 is a three-state dispatcher, and the boolean picks a distance

Slot 66 = `FUN_004CF5B0` (409 B, `RET 0x4`):

```asm
004cf5b7  MOV EAX,[ESI+0x10]      ; device must exist
004cf5be  MOV EAX,[ESI+0xdc]      ; ---- the chain state ----
004cf5c4  CMP EAX,0xb / JA default
004cf5cb  MOV CL,byte ptr [EAX + 0x4cf75c]   ; 12-byte index
004cf5d1  JMP dword ptr [ECX*4 + 0x4cf74c]
```

The index table reads `0 1 2 3 3 3 3 3 3 3 3 1` — **only three live cases**; states 3–10 fall to
the `OR EAX,-1; RET` default and state 11 maps onto case 1. So `[A+0xDC] ∈ {0,1,2}` is a genuine
3-state machine and nothing more:

| state | case | what it does |
|---|---|---|
| 0 | `0x4CF5D8` | calls slot 32 with the boolean; if it accepts, sets `[A+0xE4]=1`, **arms a second clock at `A+0xF0`**, then (only when `[A+0x34C]==0`) emits **`cmd 0x7`** with payload `1` |
| 1 | `0x4CF60F` | `[A+0x398] = (expired ? 375.0 : 282.0)` |
| 2 | `0x4CF680` | builds a 12-byte vector at `A+0x390` from `[+0x39C]/[+0x3A0]/[+0x3A4] + [0x5A83F4]`, applies `FUN_0047EC40`, then scales it by **375.0 if expired, 282.0 if not** |

The two constants are real floats in `.rdata`: `0x005AA93C = 282.0` (`438d0000`),
`0x005AA940 = 375.0` (`43bb8000`). They neighbour the §1.15 impulse constants
(`0x005AA934 = 600.0`, `0x005AA944 = 0.13`), which is a good sign they belong to the same
movement block.

Note also that case 0 emits `cmd 0x7` — the same command §1.13/§1.14 established for jump and
wall-stick. So slot 66 is a **movement-action dispatcher**, not an attack dispatcher.

#### 1.23.5 Consequence: there is no combo counter, there is a chain *multiplier*

Seven rounds looked for a counter that increments per chained attack. The path is now fully read
from key press to displacement, and **no integer counter exists anywhere on it**. What exists is:

1. a **0.11 s single-use window** armed at the attack press,
2. a **boolean** ("did the window expire?") extracted when it closes,
3. a **3-state selector** `[A+0xDC]` that consumes that boolean,
4. and a **distance scalar 282 → 375** (≈ +33 %) chosen by it.

That is the chain mechanic: *press again inside 3.3 frames and the next displacement is 33 % larger;
let the window expire and it is not.* It is a scalar bonus, not a count — which explains why every
search for "combo counters / resource spend" came back empty without being wrong about the code.

#### 1.23.6 A trap worth recording

`+0xE8` on this class is **both** a field (the clock pointer) and **virtual slot 58**. So the same
function legitimately contains `MOV ECX,[ESI+0xE8]` (field read) and `CALL [EAX+0xE8]` (slot 58
call), and a text scan for `+ 0xe8]` cannot tell them apart — it reported 78 "readers" of which
74 were virtual calls. Disambiguate by operand shape (`CALL dword ptr [...]` vs `MOV`), not by the
displacement alone.

#### 1.23.7 Buckets

**Confirmed (byte-exact)**
- window length **0.11 s** (`0x005AA8E8`), frame rate **30.0** (`0x005A9D50`).
- reader = `FUN_004CD3B0` = **slot 58 (`+0xE8`)**, only reference is the vtable slot at `0x5AA790`.
- closer = `FUN_004CF540` = slot 65, passes `0/1` to slot 66 and destroys the clock.
- slot 66 = `FUN_004CF5B0`, 12-entry index table `0 1 2 3×8 1` ⇒ **3 live states**.
- chain scalars **282.0 / 375.0** at `0x005AA93C` / `0x005AA940`.
- input object vfptr store `MOV [EBP],0x5AA6A8` at `0x4CADC2`.

**Inferred**
- `[A+0xDC]` is the chain state and its three values mean roughly "ready / post-hit / moving";
  the names are not in the binary.
- case 0's second clock at `A+0xF0` is a *per-action* timer, distinct from the 0.11 s window.

**Unknown**
- what advances `[A+0xDC]` between 0 and 2 (the transitions are not in these three functions).
- whether 282/375 are units, centimetres or engine units — no conversion constant was found.

#### 1.23.8 Update to the MeteorRebuild directive

Replace "combo counter" with **"chain verdict boolean + displacement multiplier"**:

```csharp
// on attack press:
window = 0.11f;                       // seconds, single-use
// each frame, while window is open:
if (elapsed >= window) { chainExpired = true; Close(); }
// on close:
chainState = Select(elapsed >= window);   // 3-state selector
distance   = chainState == Moving ? (expired ? 375f : 282f) * dir.x : 0f;
```

Do **not** implement a hit counter — the original has none, and adding one will make the chain feel
different from the source precisely where it matters.

---

> # ⛔ VOID as of 2026-10-28 01:15 — for the same reason as §1.23
>
> The 0.11 threshold, the 282/375 scalars and the "chain" narrative below are jump mechanics.
> What survives from §1.22 is only: the key router `FUN_004cb820`, `MOUSE1 = 0x1000` /
> `MOUSE2 = 0x1200`, the two gates, the emission of `cmd 0x1d`, and the `"Active Attack"` literal.
> ### The `cmd 0x1d` landing point — RESOLVED (2026-10-28 01:20)
>
> The 44-table entry says `this->vtable[31] (+0x7c)` without naming a base. `+0x7c` was read on three
> candidate bases and gives three different functions:
>
> | base | `+0x7c` resolves to | verdict |
> |---|---|---|
> | `0x005aa658` (PlayerController primary) | `0x004a96c0` (164 B) | not the dispatcher's class |
> | `0x005aa6a8` (subobject) | `0x004cf4c0` (122 B, arms the jump timer `+0xE8`) | implausible for an attack press |
> | **`0x005a9fe0`** | **`0x004bc710` (402 B)** | ✅ **correct — this base is the only one independently corroborated** |
>
> `0x5A9FE0` is not a guess: `cmd 0x33`'s handler `FUN_004bc100` sits at `0x5A9FE0 + 0x1E8`
> (slot 122), which was verified several rounds ago. **A slot index without its base produced two
> wrong answers before the third base settled it — methodology 7/10 in its purest form.**
>
> `FUN_004BC710` (402 B, SEH-framed, returns a value) is now read end to end:
>
> ```c
> int FUN_004bc710(this) {                       // cmd 0x1d handler
>     cfg = [0x5E0328] ?: lazy_new(0x33C, ctor 0x44D020);   // shared settings singleton
>     snap = FUN_0045A450(cfg);                  // struct copy from cfg+0x94
>     if (snap[0x34] /* = cfg+0xC8 */ != 0)
>         result = FUN_004f1960(this);           // the action
>     else
>         result = 0;
>     free two temp vectors;                     // 0x402E90 / 0x50 89fd small-alloc path
>     return result;
> }
> ```
>
> and `FUN_004F1960` is a **15-byte two-hop forwarder**:
>
> ```asm
> 004f1960  MOV EAX,[ECX]
> 004f1962  CALL [EAX+0x44]      ; this->vtable[17] -> returns a sub-object
> 004f1965  MOV EDX,[EAX]
> 004f1967  MOV ECX,EAX
> 004f1969  JMP  [EDX+0x1b4]     ; sub->vtable[109], tail call
> ```
>
> **A claim of mine is revised by this**: §1.17 concluded that `0x1000` / `0x1200` have no runtime
> consumer, based on their absence from the pollers. That was wrong in scope — the consumer exists but
> is reached **through the settings snapshot**, not through key polling. `[0x5E0328]` is the same
> 0x33C object `FUN_00503020` builds before polling the binding table, so the attack command handler
> and the key poller share one settings instance. Cross-line note: that global is the object the R50
> line catalogued as the router area (`0x5E0324`/`0x5E0328`), so the two analysis lines converge here.
>
> ### Third hop — resolved, with one identity collision to settle
>
> `FUN_004F1960`'s `this` is the command receiver (base `0x5A9FE0`), so its `vtable[17]` is
> `[0x5AA024] = 0x004f1d90` (119 B), a **get-or-create factory**:
>
> ```asm
> 004f1da9  MOV EAX,[ESI+0x1a4]      ; cached?
> 004f1db1  JNZ 0x004f1df1           ; -> return it
> 004f1db3  PUSH 0x528               ; 1,320 bytes
> 004f1dd2  CALL 0x004cabd0          ; ctor — the very ctor named in the repo's own commit fe1642a
> 004f1de8  MOV [ESI+0x1a4],EAX
> 004f1dee  CALL [EDX+0x10]          ; notify host (vtable[4])
> 004f1df5  MOV EAX,[ESI+0x1a4]      ; return the instance
> ```
>
> `0x4CABD0` + `0x528` is the PlayerController class (vtable `0x5AA6A8`, dtor `0x4CADA0`), so the
> command's tail call is:
>
> ```
> pc->vtable[109] (+0x1B4) = FUN_004ce2d0 (18 B)
>    = [pc+0x348] ? [pc+0x348]->vtable[21] (+0x54) : 0
> ```
>
> **Full chain, key press to terminal**
>
> ```
> MOUSE1 0x1000 -> gate111 (+0x10 && +0x34c) -> gate109 [pc+0x348]->vtable[21]
>   -> cmd 0x1d -> FUN_004bc710 (settings gate cfg+0xC8)
>     -> FUN_004f1960 -> vtable[17] -> get-or-create PlayerController
>       -> pc->vtable[109] -> [pc+0x348]->vtable[21]        <-- terminal
> ```
>
> **The collision:** the press gate (`0x4CBBC6`) and the command terminal (`0x4CE2DC`) are the *same
> function* `FUN_004ce2d0`. Two readings, and they are distinguishable:
>
> 1. **re-check** — the command executes on a later tick, so the predicate is re-evaluated after state
>    changed; the duplication is correct by design.
> 2. **wrong class** — slot 17 might return something other than the PlayerController, in which case
>    `+0x1B4` resolves elsewhere. What would settle it: confirm `[receiver+0x1A4]` is the same pointer
>    the repo's commit records at `[GameApp+0x2184]`, i.e. that the factory's owner is that slot.
>
> Until one of those is shown, treat the terminal as **`[pc+0x348]->vtable[21]`, identity of the
> caller unresolved** — not as a confirmed re-check.
>
> **Trap noted:** `+0x348` is a *pointer* on PlayerController (installed at `0x4CFD54` in
> `FUN_004CFD20`, cleared by the reset at `0x4CB0B9`) but a *boolean* on at least one other class
> (`0x4E8437` writes literal `0`, `0x4E8443` writes literal `1`). A scan for the offset alone mixes
> the two — fifth instance of the §1.23.6 trap.
>
> ### Fourth hop — and the chain ends in a constant (negative result)
>
> The weapon controllers are **Meyers singletons**, not heap objects. `FUN_004E3D80` (79 B) is a
> 12-way jump table over `type 0..11` to twelve 51-byte getters; each getter guards a static flag,
> calls a 73-byte ctor, registers the dtor through `atexit (0x5089BC)`, and returns the static
> instance address. Deriving ctor → vtable → `slot 21` mechanically for all twelve gives:
>
> | type | vtable | slot 21 (+0x54) | bytes |
> |---|---|---|---|
> | 0 | `0x005aab00` | `0x004f5860` | `B8 01 00 00 00 C3` = `MOV EAX,1; RET` |
> | 1 | `0x005aae10` | `0x004f5860` | same |
> | 2 | `0x005aac50` | `0x004e40d0` | `33 C0 C3` = `XOR EAX,EAX; RET` |
> | 3 | `0x005aacc0` | `0x004e40d0` | same |
> | 4 | `0x005aada0` | `0x004f5860` | return 1 |
> | 5 | `0x005aabe0` | `0x004f5860` | return 1 |
> | 6 | `0x005aad30` | `0x004e40d0` | return 0 |
> | 7 | `0x005aab70` | `0x004f5860` | return 1 |
> | 8 | `0x005aae80` | `0x004f5860` | return 1 |
> | 9 | `0x005aaef0` | `0x004f5860` | return 1 |
> | 10 | `0x005aafe8` | `0x004f5860` | return 1 |
> | 11 | `0x005aaf70` | `0x004f5860` | return 1 |
>
> **So `vtable[21]` is a compile-time constant, not a predicate.** For the sword it is literally
> `return 1`. The expected "weapon release gate → move selection" does not exist: the `cmd 0x1D`
> chain terminates in a hardcoded true for nine weapon types and a hardcoded false for types 2/3/6.
>
> Consequences, stated as consequences rather than conclusions:
>
> 1. **The attack command selects nothing.** Whatever starts a swing, it is not this path — the
>    command's net effect for the sword is `return 1`.
> 2. `cmd 0x1D` therefore behaves like a **permission probe**, not an action. That is consistent with
>    its call site: the key router emits it *between* two gates and then reports `"Active Attack"`.
> 3. The three types returning `0` (2, 3, 6) are worth naming before anyone concludes "these weapons
>    are disabled" — if they are non-player weapons the constant means something else entirely.
> 4. This is the fourth time the expected mechanism turned out to be a stub. It does not invalidate
>    the chain (every hop is byte-anchored); it invalidates the *expectation* that the chain ends in
>    gameplay logic.
>
> ### Fifth hop — `slot 40` is the executor, and the string was never in it
>
> `FUN_004CFF40` (674 B) has now been read end to end (211 instructions, **zero jump tables**, 16
> memory writes, 18 call sites). It is **not** a reporter. Shape:
>
> ```asm
> 004cff5c  CALL [EAX+0x130]        ; slot 76 -> a state value
> 004cff66..7c  CMP EAX,{1,0,3,6} / JZ proceed ; anything else -> return 0
> 004cff79  CMP EAX,0xb / JNZ exit
> 004cff82  CALL [EDX+0xf8]         ; state 0xb -> slot 62, then return 0
> 004cff9b  MOV ECX,[ESI+0x348]     ; the weapon singleton
> 004cffa4  CALL [EAX+0x20]         ; weapon->vtable[8], null -> alternate tail
> ```
>
> then it builds three or four stack temporaries (`0x4024A0` string-ish ctor, one carrying vtable
> `0x005a94e4`) and **emits two commands**:
>
> ```asm
> 004d0051  PUSH 0 ; PUSH 0 ; PUSH 0x30 ; CALL [EDX+0xc]     ; ---- cmd 0x30 ----  (exact)
> 004d00c3  PUSH EDI ; PUSH 0 ; PUSH 0 ; PUSH 0x35 ; CALL [EAX+0xc]   ; ---- cmd 0x35 ----  (exact)
> ```
>
> and finally writes `MOV [ESI+0x524],EDX`. The two landing points:
>
> | cmd | slot | target | body |
> |---|---|---|---|
> | `0x30` | 16 (`+0x40`) | `FUN_004cfca0` (56 B) | zeroes `+0x390/+0x394/+0x398`, then `device->vtable[32] (+0x80)` with **4 args**, `RET 0xC` |
> | `0x35` | 18 (`+0x48`) | `FUN_004d03f0` (166 B) | real body, not yet read |
>
> **The attribution error, stated plainly:** `"Active Attack"` is pushed at `0x4CBBFB` — inside
> `FUN_004CB820`, the *caller* — **not inside `FUN_004CFF40`**. The 674-byte function contains no
> string reference at all — the whole-image data-ref scan over `0x5C0000–0x5EFFFF` returns three
> references over two addresses, `0x005d59e8` ×2 and `0x005d59a4` ×1, all CRT allocator machinery. Labelling slot 40 "the reporter" because a string near its call
> site said so is the **sixth** string-first misjudgement in this document, and the first one where
> the string belonged to a different function than the one being named.
>
> **What this changes:**
>
> 1. The attack press has **two legs**, not one: `cmd 0x1d` is a permission probe (returns the
>    constant from §1.24's fourth hop), and `slot 40` is the leg that actually issues commands.
> 2. The `"Active Attack"` notice is gated on `slot 40`'s **return value** (`0x4CBBE4 CALL [EAX+0xa0]`
>    → `JZ` skip the notice), so it reports *that the executor ran*, not that a key was pressed.
>3. `cmd 0x30` zeroing `+0x390/+0x394/+0x398` is a **movement-state reset** — `+0x398` is the
>    `jumpForceY` field named in `docs/02`. So the executor's first act is to cancel the vertical
>    impulse before issuing the follow-up command. That is gameplay, not logging.
> 4. The attack path is therefore **not** closed by "it's just a notification": the real tail is
>    `cmd 0x35 → FUN_004d03f0` (166 B), still unread.
>
> ### Sixth hop — the terminal has behaviour, and it closes the old `[+0xDC]` question
>
> `FUN_004d03f0` (166 B, `RET 0x10` = four arguments) is **not** a forwarder. Fifty-one
> instructions, no jump table, five stores and five calls:
>
> ```asm
> 004d03f5  CALL [EAX+0x130]        ; slot 76 -> state
> 004d03fb  CMP EAX,7 / JZ 0x004d0490   ; state 7 -> return 0
> 004d0404  CMP EAX,9 / JZ 0x004d0490   ; state 9 -> return 0
> 004d0422  CALL [EDX+0x74]         ; slot 29 -> the action, 4 args
> 004d0427  PUSH 0x4
> 004d042b  CALL [EDX+0x12c]        ; slot 75 = FUN_004d0500 -> [pc+0xDC] = 4
> 004d0439  MOV [ESI+0x380],ECX  / 004d0449  MOV [ESI+0x37c],EAX
> 004d044f  CALL 0x00549a90         ; arm a third timer at [ESI+0x210]
> 004d0464..7f  copy [+0x390..+0x398] -> [+0x3B8..+0x3C0]   ; save the impulse vector
> 004d046a  MOV [ESI+0x524],0
> 004d0466  PUSH 0x35 / PUSH 0 / PUSH 0 / CALL [EAX+0xc]    ; re-emit cmd 0x35
> 004d0487  MOV EAX,1 / RET 0x10
> ```
>
> **This is the writer §1.24.4 recorded as open, and it carries its own value.** `FUN_004d0500` stores
> the argument verbatim, so `[pc+0xDC] = 4`. The jump dispatcher's 12-byte index reads
> `0 1 2 3 3 3 3 3 3 3 3 1`, so **4 maps to case 3 = `OR EAX,-1; RET`** — a no-op. In other words:
>
> **setting state 4 disables the jump dispatcher. The attack and the jump are mutually exclusive by a
> single stored state, not by a flag check.** The old open item is answered for this edge: attack →
> state 4 → jump blocked; the reset at `0x4cb0a7` (and any transition back to 0) re-enables it.
>
> Three further details worth carrying:
>
> 1. `slot 29 (+0x74)` receives **four arguments** taken from the caller's stack — this is the only
>    call on the entire attack path that takes a caller-supplied action payload.
> 2. A **third** timer is armed here, at `[+0x210]`, distinct from the `+0xE8` jump-hold clock and the
>    `+0xF0` secondary one. Three independent timers now exist on one object.
> 3. The 12-byte impulse vector is **copied** from `+0x390` to `+0x3B8` before the state change — a
>    save/restore pair, which is why the vector survives the `cmd 0x30` reset in the previous hop.
>
> ### Seventh hop — and the chain turns out to be an *aiming* report, not a selector
>
> `slot 29 (+0x74)` on base `0x5AA6A8` is `FUN_004cfb00` (210 B, `RET 0x10` = four arguments, 68
> instructions, no jump table). Read end to end:
>
> ```asm
> 004cfb08  CALL [EAX+0x94]          ; slot 37 -> entity id; zero -> return
> 004cfb23  CALL [EDX+0x1a0]         ; slot 104, takes arg1        (a setter)
> 004cfb35  CALL [EAX+0x134]         ; slot 77; if (result == arg1) -> return     <-- dedup guard
> 004cfb45  CALL 0x0055de10          ; on the entity
> 004cfb5e  MOV [ESP+0x28],0
> 004cfb66  CALL [EDX+0x58]          ; slot 22 (4 args) -> writes a float local   <-- the aim value
> 004cfb72  CALL [EDX+0x6c]          ; weapon singleton, slot 27
> ; ---- quantise and pack ----
> 004cfb75  FLD  [ESP+0x18] ; FMUL [0x5a8f7c]=200.0 ; FADD [0x5a8460]=0.5(double) ; CALL 0x509980 (fptosi)
> 004cfb93  FLD  [ESP+0x24] ; FADD [0x5a8b80]=2.0   ; FMUL [0x5a84c8]=100.0 ; FADD [0x5a83e8]=0.5 ; CALL 0x509980
> 004cfb7f  SHL EDI,8 ; OR EDI,EBX            ; payload[0] = (arg2 << 8) | arg1
> 004cfbb7  OR  EDI,EAX                        ; payload[1] = (i1 << 8) | i2
> 004cfbbb  PUSH 0x8 ; PUSH &payload ; PUSH 0x4 ; CALL [EAX+0xc]    ; ---- cmd 0x04, 8 bytes ----
> ```
>
> The five constants are quantisation constants, byte-exact: **200.0, 0.5 (double), 2.0, 100.0, 0.5**
> at `0x5a8f7c / 0x5a8460 / 0x5a8b80 / 0x5a84c8 / 0x5a83e8`. Two 8-bit fields are packed per dword, so
> the payload is a **direction/orientation sample**, not a move id.
>
> **Confirmed:** the packing math, the guards, the constants, the two slot calls, and the
> `cmd 0x04` emission with an 8-byte payload.
> **Inferred:** that the two quantised fields are yaw/pitch (or an equivalent pair of normalised
> angles) rather than a cell coordinate. Either way it is a *sample*, not a *choice*.
>
> **The chain therefore contains no move selection at all.** Seven hops, and what MOUSE1 actually
> does is:
>
> | hop | action |
> |---|---|
> | key router | classifies the key, emits `cmd 0x31 {key, pressed}` |
> | gates | `[+0x10] && [+0x34c]`, then `[+0x348]->vtable[21]` |
> | `cmd 0x1d` | permission probe → weapon capability constant |
> | slot 40 | state filter → weapon gate → `cmd 0x30` (cancel `jumpForceY`) + `cmd 0x35` |
> | `cmd 0x35` | `SetState(4)` (disables jump dispatch), arms `+0x210`, saves the impulse vector |
> | slot 29 | quantise the aim and emit `cmd 0x04` (8 bytes) |
>
> Nothing here picks a pose, an action id, or a combo link. **Selection is downstream** — which is
> the sixth-round lesson arriving with byte evidence this time instead of by elimination: the attack
> press establishes *permission, posture, state and facing*, and hands the actual choice to whatever
> drains queue A (the 12-byte `{key, pressed}` records at `+0x18`).
>
> Note also that `cmd 0x04` has no handler of its own: the 44-entry map lists it as **pure inline,
> two lines** — the dispatcher does whatever it does in place.

### 1.24 Round 7 close-out — what is settled, what stays open, and the one number that matters

> This section closes the seven-round hunt. Everything above is byte-anchored; this one records
> the three end-state facts that change the spec's conclusions, plus the single loose end that
> resisted the last scan — stated as open rather than smoothed over.

#### 1.24.1 Units are already anchored — no new constant needed

An earlier draft of §1.23.7 listed "282/375 have no conversion constant" as unknown. That was
wrong, and the correction is worth recording because it removes a whole class of future doubt:

`0x005AA93C` (282.0) and `0x005AA940` (375.0) sit in the **same `.rdata` block as the §1.15 impulse
constants** — `0x005AA934` (600.0) and `0x005AA944` (0.13) — and `FUN_004CF5B0`'s jump dispatch
(case 0, `cmd 0x7`) reads from that same block. So the chain scalars are expressed in the **same
world-unit space as the jump speeds**, and the clip's unit scale (移植端自定 `0.048283 m/unit`，非原版常量) applies
directly. No new constant, no new conversion.

#### 1.24.2 Two windows, two constants — do not merge them

| window | value | domain |
|---|---|---|
| attack chain window | **0.11 s** (≈3.3 frames @30 fps), `0x005AA8E8` | this section's chain |
| input buffer tolerance | 12 frames (0.2 s @60 Hz) | 移植端自定输入环（非原版常量） |

They are unrelated constants that both happen to bound "how long an input stays meaningful". A
clone that reuses one for the other will feel wrong in exactly the place players notice.

#### 1.24.3 The 0x48 clock's gate — already in §1.23.3, now with the ordering explicit

`FUN_004CF540` has **two** gates before it touches the boolean, and both return `-1` (do nothing) on
failure:

```asm
004cf543  MOV EAX,[ESI+0xe8] / TEST / JZ  0x4cf5a6   ; no clock      -> -1
004cf54f  CALL [EAX+0x180]                            ; slot 96 gate  -> non-zero -> -1
004cf564  FCOMP double [0x005aa8e8]                   ; 0.11 re-test
004cf575  PUSH 0x0 / CALL [EDX+0x108]                 ; not expired -> slot 66(FALSE)
004cf583  PUSH 0x1 / CALL [EAX+0x108]                 ; expired     -> slot 66(TRUE)
004cf598  MOV [ESI+0xe8],0                            ; single-use
```

Slot 66 is reached by **virtual call**, never `E8` — which is why an "is slot 66 called directly?"
check returns zero and looks like a contradiction. It is not.

#### 1.24.4 The last loose end: `[A+0xdc]`, honestly open

The three-state selector's **writer exists and is fully identified**:

| item | finding |
|---|---|
| dedicated setter | `FUN_004D0500` — **13 B**, `MOV EAX,[ESP+4]` / `MOV [ECX+0xdc],EAX` / `RET 0x4` |
| its binding | **A.slot 75 (`+0x12c`)** on base `0x5AA6A8`; also slot 93 (`+0x174`) on base `0x5AA660` |
| its callers | **zero direct `E8`** — vtable-reached only |
| reset path | `0x4CB0A7 MOV [ESI+0xdc],EDI` inside `FUN_004CAFB0` (state reset, `EDI` = 0) |
| best candidate caller | `0x4BB81F`, the **`cmd == 0x0F`** case of the dispatcher — index 12 of the 51-entry table at `0x4bBFE8` — gated on `[A+0x35C] == 1` (corrected: this was attributed to cmd 3; see §1.24.7) |

**Why it is not closed:** at `0x4BB830` the dispatcher does `MOV EDX,[ESI] / MOV ECX,ESI /
CALL [EDX+0x12c]` with **no argument pushed**, while `FUN_004D0500` is `RET 0x4`. Either the
dispatcher's `this` is not A (so `+0x12c` is some other class's slot), or the case body relies on a
push that the listing does not show. Both readings are byte-consistent; neither is proven. The
`+0x12c` is a popular slot offset and cannot be used as an identifier on its own — a fourth
instance of the §1.23.6 trap. Exact census (see §1.24.6 for why the earlier number was wrong):
**66** call-form sites image-wide, distributed 12 in `0x48xxxx`, 10 in `0x49xxxx`, 24 in `0x4Cxxxx`,
8 in `0x4Bxxxx`, 6 in `0x4Dxxxx`, 4 in `0x4Exxxx`, 2 in `0x4Fxxxx`; **271** instructions carry the
displacement in any form.

**What this does and does not change:** the chain verdict (0.11 s window → boolean → 3-state
selector → 282/375) is fully anchored regardless of who flips the selector, because the selector is
*read* in one place (§1.23.4) and that read is byte-exact. Only the *transition rule* between the
three states is open. A clone can ship the window and the multiplier today and leave the transition
to play-testing.

#### 1.24.5 End state of §1

| link | status |
|---|---|
| key event → router (MOUSE1 = 0x1000) | ✅ §1.22.1–1.22.2 |
| gates → `cmd 0x1d` | ✅ §1.22.2 |
| `cmd 0x1d` → 0x48 clock @ 30 fps | ✅ §1.22.3 |
| clock → 0.11 s reader (slot 58) | ✅ §1.23.1–1.23.2 |
| closer (slot 65) → boolean → slot 66 | ✅ §1.23.3 |
| slot 66 → 3-state → 282/375 multiplier | ✅ §1.23.4 |
| chain state transitions (`[A+0xdc]` writer value) | ⚠️ open (§1.24.4) |
| combo counter / resource spend | ❌ **does not exist** (§1.23.5) |

Seven rounds produced six retractions and one negative result that was true all along: the thing
being hunted was never a counter. That is the finding.

#### 1.24.6 The 17-byte decode, cmd 0x3's real exit, and a count that was wrong

Three items from the close-out audit, recorded because two of them change what is in this document.

**The 17 bytes contain no hidden argument.** The gap between the gate and the setter call decodes
completely as:

```asm
004BB81F  CMP dword ptr [ESI+0x35c],0x1   ; 7 bytes  - the gate
004BB826  JNE 0x004bbfdb                  ; 6 bytes  - gate fails -> default
004BB82C  MOV EDX,[ESI]                   ; 2 bytes
004BB82E  MOV ECX,ESI                     ; 2 bytes  - thiscall setup
004BB830  CALL [EDX+0x12c]                ; 6 bytes  - A.slot 75, zero explicit args
```

17 bytes, fully accounted for, **zero `PUSH`**. So the arity mismatch in §1.24.4 is real and the
`❓ open` verdict stands. This matters as a precedent: the "compressed excerpt hides an argument"
hypothesis had already been correct twice, and it was still wrong the third time — the hypothesis
had to be tested, not assumed.

**But the same decode yields cmd 0x3's actual output**, which §1.24.4 did not state: after the
setter, the case continues

```asm
004BB836  CALL 0x00487830          ; GameApp singleton
004BB843  CALL [EAX+0x4c]          ; A.slot 19 = FUN_004CE230 -> latches [A+0x34C]
004BB846  PUSH EAX
004BB849  CALL [EBX+0x174]          ; GameApp slot 93 -> receives the latched value
```

So cmd 0x3 is: **set the selector (by a call whose argument count does not match) → latch the
`+0x34C` flag → report that latched value to `GameApp.slot93`**. The last step is the command's
semantic exit, and it is independent of the arity puzzle — whoever closes §1.24.4 should carry that
exit with it, because `GameApp.slot93` is where the value becomes observable outside this class.

**A count in this document was wrong, and the reason matters.** §1.24.4 and methodology item 10
originally said `+0x12c` appears "sixteen times in a single module". Sixteen was the number of
lines a truncated listing happened to display, not a measurement. The exact census:

| form | total | distribution |
|---|---|---|
| `CALL dword ptr [reg + 0x12c]` | **66** | 0x48: 12, 0x49: 10, 0x4B: 8, 0x4C: 24, 0x4D: 6, 0x4E: 4, 0x4F: 2 |
| any instruction carrying `+ 0x12c]` | **271** | 0x4A: 49, 0x40: 25, 0x4C: 24, 0x48: 14, 0x42: 13, 0x49: 11, … |

The conclusion is unaffected — `+0x12c` is still not an identifier — but the number is now a
measurement. It is the third time a display-truncated figure leaked into prose (after the 16 in this
section and the "four call sites" in §1.22.5); methodology item 10 now carries the rule.

#### 1.24.7 Erratum: `0x4BB81F` is cmd 0x0F, and how the mistake was made

The dispatcher `FUN_004bb800` begins `ADD EAX,-3 / CMP EAX,0x32 / JMP [EAX*4 + 0x4bbfe8]`, so the
table at `0x4bbfe8` is indexed by `cmd - 3`. Reading all 51 entries settles every attribution:

| index | cmd | target | note |
|---|---|---|---|
| 0 | `0x03` | `0x4bbfd0` | shared no-op exit |
| 1 | `0x04` | `0x4bbfd0` | same exit — hence "pure inline" |
| 6 | `0x09` | `0x4bbfd0` | same exit |
| **12** | **`0x0F`** | **`0x4bb81f`** | the gate + setter + latch + GameApp.slot93 chain |
| **11, 15, 32–36** | `0x0E`, `0x12`, `0x23`–`0x27` | `0x4bbfdb` | second shared exit (7 commands) — idx column corrected, the cmd column was already right |

Three table entries are worth recording because they close the loop with §1.16's map: `cmd 0x1D` ->
idx 26 -> `0x4bbade`, `cmd 0x33` -> idx 48 -> `0x4bba20`, `cmd 0x35` -> idx 50 -> `0x4bb96e`. Every
command used by the seven-hop chain has its own trampoline in this table.

**Two corrections follow.**

1. §1.24.4's "best candidate caller = `cmd 3`'s case" is **wrong**. The body at `0x4bb81f` belongs to
   **`cmd 0x0F`**. Everything else about it stands — the gate on `[+0x35C] == 1`, the zero-argument
   `SetState` call with the `RET 0x4` mismatch, the `GameApp.slot93` exit — it simply belongs to a
   different command. The open item moves with it.
2. `cmd 0x03 / 0x04 / 0x09` are **shared no-op exits**, so `cmd_dispatch_map`'s "pure inline" label
   for them means exactly that: the case body is three instructions ending at `0x4bbfd0`, not a
   hidden handler.

**How the mistake was made, because it is a new failure mode for this document.** `0x4bb81f` sits
immediately after the dispatch instruction `JMP [EAX*4 + 0x4bbfe8]` at `0x4bb818`, so it *looks* like
the first case body. I read the layout instead of the table. In every earlier retraction the error was
a wrong base, a wrong operand or a string taken as a conclusion; this one is **proximity mistaken for
identity** — the body that follows a jump table is not necessarily the body of its first entry.

The check that catches it is one line: read the table, map index → cmd, then look up the address.
`cmd_dispatch_map` had `cmd 0x0F → vtable[19] (+0x4c)` all along, and the body contains
`CALL [EAX+0x4c]` at `0x4bb843` — **the map and the code agreed; only the prose disagreed with both.**

#### 1.24.8 The drain side: eleven calls, ten distinct handlers, and they are *movement*

`FUN_004cc130` (slot 19, 1,174 B) fan-out, enumerated byte-exactly: **11 call sites over 10 distinct
slots**, `51..60` (`+0xcc..+0xf0`), with **`+0xe8` called twice** (`0x4cc3f3`, `0x4cc439`).

```text
0x4cc3f3 [EAX+0xe8] slot 58     0x4cc4db [EDX+0xcc] slot 51
0x4cc439 [EAX+0xe8] slot 58     0x4cc4f1 [EDX+0xd4] slot 53
0x4cc46b [EAX+0xe4] slot 57     0x4cc507 [EDX+0xec] slot 59
0x4cc4a9 [EDX+0xe0] slot 56     0x4cc51d [EDX+0xd8] slot 54
0x4cc4c2 [EDX+0xd0] slot 52     0x4cc533 [EDX+0xdc] slot 55
                                0x4cc549 [EDX+0xf0] slot 60
```

Resolving `51..60` on the two candidate bases produces a decisive split:

| base | distinct | note |
|---|---|---|
| **`0x5aa6a8` (PlayerController)** | **10 / 10** | slot 58 = `FUN_004cd3b0` (**2,386 B**) — the clock reader of §1.23.2 |
| `0x5aab00` (sword weapon controller) | 9 / 10 | slot 58 = `0x004e4070`, a bare `RET 0x4` |

**The PlayerController base is the right one**, and not by preference: the doubled `+0xe8` call must be
the clock reader, and only this base yields a 2,386-byte function there. The weapon table is a
**decoy** — it also has ten populated slots, so a distinct-count test alone cannot tell them apart.

The ten handlers, with sizes:

| slot | offset | function | size | known role |
|---|---|---|---|---|
| 51 | `+0xcc` | `FUN_004ce080` | 122 | — |
| 52 | `+0xd0` | `FUN_004cdd60` | 155 | — |
| 53 | `+0xd4` | `FUN_004cde90` | 82 | — |
| 54 | `+0xd8` | `FUN_004cdef0` | 150 | — |
| 55 | `+0xdc` | `FUN_004ce010` | 70 | — |
| 56 | `+0xe0` | `FUN_004ce3d0` | 336 | — |
| **57** | **`+0xe4`** | **`FUN_004cd200`** | **429** | **wall-stick (§1.14)** |
| 58 | `+0xe8` | `FUN_004cd3b0` | 2386 | clock reader (§1.23.2) |
| 59 | `+0xec` | `FUN_004cde00` | 130 | — |
| 60 | `+0xf0` | `FUN_004cdf90` | 124 | — |

**Two results, one positive and one negative.**

*Positive:* the prediction that the ten slots would collapse to two or three implementations — the way
`weapon->vtable[21]` collapsed to two constants — is **falsified**. Ten slots, ten distinct functions.
The dispatch is genuine identity-by-selector, consistent with §1.21's switch on the accumulated
direction string.

*Negative, and the more important one:* **all ten handlers live in the `0x4cd`–`0x4ce` movement/physics
module, and slot 57 is the wall-stick routine.** So the drain path does not select attacks either. It
selects among **movement states**. The queue A `{key, pressed}` records are consumed here as input to
movement handling, not as combo input.

**Stop rule applied.** No move-table matching loop was found in this path: the selection is the
direction-string switch (§1.21), and its targets are movement handlers. There is therefore nothing to
report as "table base + pose ids" — the attack move selection is **not** on the drain path.

Consequence: after eight hops plus the drain side, **the attack's move selection has not been located
anywhere**. That is now a strong negative spanning both legs of the architecture, and it points at the
one place not yet read: the data side itself (`.pos`/characteract tables), i.e. the code reads a move
list rather than the code containing one.

---

### 1.25 The selection question closes — and the answer was already on disk

> Nine hops of static work in `Meteor.exe` found no move-selection machinery (§1.22–§1.24.8). That
> negative was correct. This section records *why* it was correct, and where the machinery actually
> lives. **No new binary evidence is introduced here** — the finding is a source/data reconciliation
> inside the project's own `_sources/` tree.

#### 1.25.1 Three implementations exist in this project, not two

| implementation | origin | role |
|---|---|---|
| `Meteor.exe` (9.07) | original C++ client, 2002 | the analysis target of §1.1–§1.24 |
| `MeteorPort` apk v0.2.8.0 | **third-party Unity 5.5.5p1 rewrite** (Mono + SLua) | a *readable* reimplementation reusing the original data formats |
| `MeteorRebuild` | this project | the clone being built |

`MeteorPort/REPORT.md` states this outright: the apk "**不是原版游戏的移植包**，而是一套用 Unity
重写、并复用原版流星蝴蝶剑数据格式的引擎实现". It is therefore **not authoritative**, but it *is*
the only readable implementation of the mechanism in hand.

#### 1.25.2 The selector, read from source

`Assembly-CSharp/ActionInterrupt.cs` (16,411 B) + `InputModule.cs` (3,789 B) + `InputItem.cs`
(4,179 B) contain the whole of it:

```text
ActionInterrupt
  Root : ActionNode                     root of the action tree
  Whole : Dictionary<int, ActionNode>   actionIdx -> node
  Lines : Dictionary<int, List<int>>    KeyMap (group ordinal) -> its member action ids   [see 1.25.8]
  skill : int[12]                       per-weapon skill table
  CacheGround / CacheAir : Dictionary<int, List<ActionNode>>   memo by source action
  IsWeaponKey(weapon, KeyMap)  Scan(weapon, ref dst, ref src, ref scan)
  GetNormalNode / GetSlashNode / GetSkillNode / GetSkillPose / GetActions / FindAct / Init
```

`InputModule` holds one `InputItem` per row of `Input.txt`; `InputItem` carries
`keyInput : char[]` (the literal sequence, e.g. `S`,`W`,`J`), `lines` / `linesAir`
(`Dictionary<int, List<int>>` cloned out of `ActionInterrupt.Lines`), plus `state`, `frame`,
`totalState`. `InputModule.OnKeyDown` walks `inputs` **backwards** (last-loaded wins) and the first
`InputItem` that accepts the key wins — i.e. **longest/most specific sequences are tried first by
load order, not by length comparison**.

#### 1.25.3 The 27 hard-coded arrays are `Input.txt` transcribed — 27/27, zero drift

`GetSlashNode` contains 27 explicit `int[]` literals. Mechanically compared against `Input.txt`'s
`Lines` / `LinesAir` columns:

| | |
|---|---|
| `Input.txt` rows | 20 (`J`, `SJ`, `AJ`, `DJ`, `WJ`, `SSJ`, `WWJ`, `AAJ`, `DDJ`, `SWJ`, `WSJ`, `ADJ`, `DAJ`, `ADSJ`, `SADJ`, `ADWJ`, `SSWJ`, `SWWJ`, `WWWJ`, `ADWSJ`) |
| non-empty text vectors (`Lines` + `LinesAir`) | 29 |
| C# `scan` literals | 27 (one unnumbered 14-element `scan` + `scan2`…`scan27`) |
| **exact matches** | **27 / 27 — every element, every order** |

The unnumbered 14-element `scan` is `Idx 2 (SJ).Lines`; `scan2` is `Idx 2 (SJ).LinesAir`; the
sequence then runs monotonically to `scan27` = `Idx 20 (ADWSJ).Lines`.

**The one absence is the proof.** `Idx 1 = J` (plain attack) has **no** corresponding literal —
27 vectors cover Idx 2–20 only. `Input.txt`'s own comment on row 2 says exactly this:
"所有的基础动作，都不由连招系统负责，而由基本按键识别系统识别". Two independent sources, one
conclusion: **plain attack never enters the chain matcher.**

This also explains §1.22's surprise. `J` reaching the code as a raw key event with no follow-up was
not an incomplete trace — it was the correct trace of the *basic* path. The chained path is reached
only from a *completed sequence*, and the sequence never leaves `InputItem`.

#### 1.25.4 `Combo.cs` closes the nine-round counter question — it is a UI label

`Combo.cs` is 1,272 B:

```csharp
public class Combo {
    private int mComboCount;
    private GameObject mCombo;
    private UILabel mCountLabel;      // NGUI label
    private TweenScale mTween;        // NGUI
    private TweenAlpha mTweenAlpha;   // NGUI
    public void OnComboHit(int comboHit) { ... mComboCount.ToString() ... }
    public void ClearComboCount() { ... }
}
```

It is a **hit-count floater** — text, scale tween, alpha tween. No gameplay read, no damage
modifier, no resource call. This is the independent confirmation of §1.22.7 / §1.23.5 from the other
side: the counter exists, it is *display only*, and it is why nine rounds of combat-code search found
nothing. **Record it as: the counter is real, and it is cosmetic.**

#### 1.25.5 Full selection algorithm (as implemented, ready to port)

```text
on key edge (J / S / A / D / W):
    for item in inputs (reverse load order):
        if item accepts key:                       # advance item.state
            if item.state == len(item.keyInput):   # whole sequence matched
                chainId  = item.Idx
                pool     = onGround ? item.lines[chainId] : item.linesAir[chainId]
                candidate = first in pool whose Whole[] node passes IsWeaponKey(weapon, KeyMap)
                if candidate: request action = candidate
                item.Reset(); return true
    # no whole match -> basic-key path (never the chain matcher)
on action finished:
    next = GetSlashNode(owner, currentNode)
        weaponType = owner.GetWeaponType()
        if CacheGround/CacheAir has currentNode.ActionIdx: return cached
        scan the 27 vectors (ground set = 19 vectors, air set = 8 vectors)
            keep node if IsWeaponKey(weaponType, node.KeyMap)
                    and node is in source.target relation set
        memoise into CacheGround / CacheAir
```

Two properties worth carrying over verbatim:

1. **Ground and air are disjoint vector sets**, not one set with a flag. §1.25.3's table splits
   19 ground vectors / 8 air vectors, and a clone that filters after the fact will diverge wherever
   the same action id appears on both sides.
2. **The memo is keyed on the *source* action, not on the input.** Consequence: the reachable set
   from an action is computed **once per action lifetime** and the weapon type is baked into it. A
   weapon swap mid-action will serve a stale set unless the cache is invalidated. This is a real
   defect class the clone must either replicate or deliberately fix — and if it fixes it, §1.25.3's
   comparison will diverge on the first swap test.

#### 1.25.6 What this says about the nine-hop negative

The negative stands and is now *explained* rather than merely *observed*: `Meteor.exe`'s attack path
(§1.22–§1.24.8) carries permission, posture, state, and aim — the decision is a **table lookup keyed
by an accumulated key sequence**, and the sequence lives in the input layer, not in the attack chain.
Two separate legs, exactly as the "decision is data-side" reading predicted, now with the data side
identified by name and row.

#### 1.25.7 Buckets

**Confirmed**
- selector = `InputItem.keyInput` sequence match → `Lines`/`LinesAir` lookup → `IsWeaponKey` filter
- 27 C# literals == 19 `Input.txt` chains, `Lines`+`LinesAir`, element-exact (§1.25.3)
- `Idx 1 (J)` absent from the matcher, matching the table's own note
- `Combo.cs` is NGUI display only

**Inferred**
- `Meteor.exe` uses the same 20-row table (strong: the C# arrays are transcribed from it, and the
  table's own comments describe classic Meteor behaviour), but **the exe has no `Input.txt` string**
  — its loader reads a different filename or an embedded copy. Unverified.
- `Scan()`'s `source.target` relation is the `characteract.txt` `action -> nextpose` graph.

**Unknown**
- the exe-side loader and the sequence matcher's address in `Meteor.exe` (not needed for the clone
  if §1.25.5 is adopted, but needed to *prove* isomorphism rather than assert it)

#### 1.25.8 Correction: `KeyMap` is the group ordinal, not an action id

Reading `Scan()` and `Init()` to the end corrects two statements in §1.25.2–1.25.5.

**What `Scan()` actually compares:**

```csharp
if (scan[j] == src[i].KeyMap && !IsSkill(src[i].ActionIdx) && IsWeaponKey(weapon, src[i].KeyMap))
```

It matches **`KeyMap`**, not `ActionIdx`. Therefore the numbers in the 27 literals — and, by
§1.25.3, the numbers in `Input.txt`'s `Lines` / `LinesAir` columns — are **KeyMap values**.

**What `KeyMap` is** (`Init()`, `characteract.txt` parser):

```csharp
int num3 = 1;                          // running counter
...
if (text.StartsWith("group")) {
    ...
    actionNode9.KeyMap = num3;         // <-- KeyMap = ordinal of this group occurrence
    Lines[num3] = { expanded actionIdx... };
    num3++;
}
```

So `KeyMap` = **the 1-based ordinal of each `group(...)` line as it appears in `characteract.txt`**.
Measured: the file holds **160 group lines**, and the largest value appearing in the `scan` literals
is exactly **160** — the index space closes with zero slack.

`Lines[KeyMap]` is the second half of the bridge: it expands a group into its concrete `ActionIdx`
members. The `226(227,235)` lines are a separate statement form and build the `target` graph:

```text
group(200)          -> KeyMap = k, Lines[k] = {200}, 200 becomes a legal opener (Root.target += 200)
group(203-204)      -> KeyMap = k, Lines[k] = {203,204}, 203 becomes a legal opener
226(227,235)        -> Whole[226].target += {227, 235}
```

**The corrected mechanism is a two-ended KeyMap match**, not an action-sequence comparison:

```text
input side:   key sequence  -> Input.txt row (Idx) -> its Lines/LinesAir = a SET of KeyMaps
action side:  current node.target  -> keep those whose KeyMap is in that set,
                                     are not skills, and pass IsWeaponKey(weapon, KeyMap)
              -> memoise per source ActionIdx in CacheGround / CacheAir
bridge:       KeyMap -> Lines[KeyMap] = the concrete ActionIdx list to execute
```

This supersedes the wording in §1.25.5 ("按当前 action 找可接招"). The ground/air split and the
memo-keyed-on-source-action caveat both still stand.

> Why this matters for the clone: a port that compares **action ids** against `Input.txt` will appear
> to work on the first chain and fail on every branch thereafter, because `Input.txt` never mentions
> an action id at all. The join key is the group ordinal.

#### 1.25.9 What the Unity implementation can and cannot settle

`MeteorUnit.cs` is 3,120 lines / 72,462 B and is **not a mirror of the original**. It re-implements
the unit as a `MonoBehaviour` with `PoseStatus` / `CharacterLoader` / `MeteorController` /
`WeaponLoader`, and hands physics to the engine. Its constants prove the divergence:

| constant | Unity rewrite (`MeteorUnit.cs`) | original `Meteor.exe` |
|---|---|---|
| `Jump2Velocity` | 160.0 | `282.0` @`0x005AA93C` |
| `JumpVelocityForward` | 180.0 | `375.0` @`0x005AA940` |
| `groundFriction` | 2000.0 | `600.0` @`0x005AA934` |
| jump falloff | `JumpLimit = 68.0` | `0.13` @`0x005AA944` |

Four different numbers in four rows: **the rewrite tuned its own physics.** Nothing in it can be
used as an oracle for original constants.

Settled / not settled, item by item:

| open item | settleable from the Unity source? | why |
|---|---|---|
| 20-row input table, `Lines`/`LinesAir` | ✅ **yes** | data format is reused verbatim; 27/27 verified |
| `KeyMap` = group ordinal (160 groups) | ✅ **yes** | parser is explicit, index space closes |
| `target` graph from `226(227,235)` | ✅ **yes** | parser is explicit |
| 12-weapon filter shape | ✅ **yes — structurally** | `IsWeaponKey` switch over 12 weapons matches §1.24.x's 12-vtable factory; the *contents* are still the rewrite's own |
| plain attack `J` bypasses the matcher | ✅ **yes** | two independent sources (§1.25.3) |
| `[+0xDC]` 0..11 state machine | ❌ **no** | Unity has no equivalent field; its movement state is engine-side |
| `0.11` hold-jump ratio | ❌ **no** | no analogue; physics reimplemented |
| `cmd 0x0F` zero-arg setter | ❌ **no** | the command channel does not exist in the rewrite |

So the honest split is **five settled, three not** — and the three that remain are exactly the
runtime-state items that `MeteorOriginalMonitor` already reads (`MoveState = PC+0xDC`,
`SubState = PC+0xE0`). Those three close by **sampling, not by reading source**.
#### 1.25.10 The `[+0xDC]` machine, measured — from a log that was already on disk

§1.24.4 was left `❓ open` with only a setter and one edge (`attack -> 4 -> jump disabled`). It closes
**without a new experiment**, because `MeteorOriginalMonitor` has been logging `moveState` and
`subState` all along (`MeteorOriginalMonitor.cs` line 396: `moveState={22}(sub={23})`), and
`PlaytestLogs/original_meteor_latest.log` holds 1.5 MB / **3,374 sampled ticks** from a real session.

**Distribution**

| state | ticks | share | dominant poses |
|---|---|---|---|
| 0 | 1,378 | 40.8% | `JumpFall` 524, `Jump` 358, `ClimbUp` 215, `JumpFallOnGround` 133, `JumpBack` 54 |
| 1 | 1,290 | 38.2% | `Idle` 657, `WalkLeft` 295, `WalkRight` 192, `Run` 86 |
| 2 | 540 | 16.0% | `ClimbUp` 506, `ClimbRight` 25, `ClimbLeft` 9 |
| 3 | 154 | 4.6% | `Pose249` 38, `Pose248` 31, `Pose250` 54, `Pose332` 13, `Pose333` 6 |
| 4 | 12 | 0.4% | **`Pose90` × 12 — one pose, exclusively** |

**Transition graph (counted over state changes)**

```text
0 <-> 1   133 / 136     airborne <-> grounded   (the dominant oscillation)
0 <-> 2    70 /  70     airborne <-> climbing
1  -> 3     8           grounded -> attack wind-up
3  -> 1     9           wind-up abandoned
0  -> 3     3           airborne -> attack wind-up
3  -> 4     2           wind-up -> attack execution
4  -> 1     2           attack execution -> grounded
```

**Every observed `state 4` tick, without exception:** `act=90 (Pose90)`, `grounded=False`,
`sub=0`, and `keys=[LMB]` on the entry frame. The two complete episodes are:

```text
169.914s  ms=3  act=249 Pose249  keys=[LMB]
169.977s  ms=4  act=90  Pose90   keys=[LMB]     <- 6 ticks at 0.062 s spacing
170.287s  ms=4  act=90  Pose90   keys=[]
170.348s  ms=1  act=0   Idle     keys=[]        <- released
171.029s  ms=3  act=249 Pose249  keys=[]
171.090s  ms=4  act=90  Pose90   keys=[LMB]
171.429s  ms=4  act=90  Pose90   keys=[LMB]
171.491s  ms=1  act=0   Idle     keys=[LMB]
```

**So the machine is:**

| state | meaning | evidence |
|---|---|---|
| 0 | airborne / jumping | `JumpFall` + `Jump` + `ClimbUp` dominate |
| 1 | grounded idle + locomotion | `Idle` + `Walk*` + `Run` |
| 2 | climbing | `ClimbUp` 94% of it, plus `ClimbLeft/Right` |
| 3 | attack wind-up (weapon pose) | `Pose248/249/250/332/333` |
| 4 | **air attack execution** | `Pose90` only, `grounded=False` on all 12 ticks |

This matches the static chain exactly. §1.24.4's confirmed edge was *attack -> `SetState(4)` -> jump
dispatcher becomes a no-op*; the measurement adds that the state is **air-only** (`grounded=False`
throughout) and **pose-monogamous** (`Pose90` and nothing else). The gameplay reading is coherent:
`Pose90` is an airborne attack, and suppressing the jump dispatcher prevents a mid-air double jump
for its duration. `Pose249` is the wind-up that the LMB edge interrupts into `Pose90`.

> `Idx 6 (SSJ)`'s `Lines` in `Input.txt` contains `90` (§1.25.3), so `Pose90` is reachable from the
> chain table as a member of the SSJ group — consistent, though this log does not prove which input
> produced it.

**Buckets**

- **Confirmed:** the five states' semantic domains; `state 4 -> Pose90` exclusively; `state 4` is
  always airborne; `3 -> 4` requires an LMB edge on the entry frame; `4 -> 1` returns to `Idle`.
- **Inferred:** `state 4` *is* the "jump suppressed" flag rather than merely correlated with it — the
  static path (§1.24.4) says so, but no tick in this log presses jump during `state 4`, so the
  suppression itself was not exercised.
- **Unknown:** whether `Pose90` is the only pose that can hold `state 4`, or merely the only one this
  session reached.

**Sample-size caveat.** 3,374 ticks, one session, two complete `3->4->1` episodes. Treat the graph
as *directionally* established and the "Pose90 only" claim as *unrefuted* rather than exhaustive.
---

### 1.26 Project topology, and a correction: the resource spend exists, in the selector

> This section exists because I had the workspace map wrong. `_sources/` is the **Android/APK
> tear-down**; the three live Unity projects are elsewhere. And re-reading the selector chain in the
> *right* file surfaced the thing nine rounds of combat-code search declared absent.

#### 1.26.1 The map (corrected)

| path | what it is | Unity | role |
|---|---|---|---|
| `C:\Program Files (x86)\Meteor\Meteor.exe` | original 9.07 C++ client | — | **analysis target** (§1.1–§1.24) |
| `D:\MeteorProjects\_sources` | **Android APK tear-down root** | — | source of reference implementations |
| ├ `MeteorV0.2.8.0.apk` + `Meteor_APK_Extract` | Android build | 5.5.5p1 | the APK itself |
| ├ `MeteorPort/` | **APK decompilation** (`Assembly-CSharp.rebuilt.dll` + `Managed/`) | — | what §1.25 was read from — the *thinnest* copy |
| ├ `_gt/master/meteor_original_ios-master` | GitHub master of `meteor_for_unity` ("端游流星蝴蝶剑.net 用 unity 重新写的仿造工程") | 2020 | 28,308 B `ActionInterrupt.cs` |
| ├ `_gt/v280/Assets` | v2.8 **source** tree | — | same version as the APK, but source |
| ├ `Meteor_Extracted/` | **original `.pos` / resource parse results** | — | the real ground truth for move data |
| └ `Meteor_UnityProject/ExportedProject` | Windows build export | — | assets + serialized scripts |
| `D:\MeteorUnity\meteor_551_u2020` | 5.5.1 → 2020 upgrade project, with `GoldenMaster/`, `Mods/`, `UPGRADE.md` | 2020.3.48f1c1 | **37,914 B / 940 L** `ActionInterrupt.cs` — the fullest copy |
| `D:\MeteorWin\UnityProject\ExportedProject` | Windows export (live) | 2020.3.48f1c1 | assets |
| `D:\MeteorProjects\MeteorRebuild` | this project | 2020.3.48f1c1 | the clone |

**Three different `ActionInterrupt.cs` exist**, and §1.25 was based on the smallest:

| copy | size | lines |
|---|---|---|
| `MeteorPort` (APK decompiled) | 16,411 B | 733 |
| `_gt/master` (GitHub source) | 28,308 B | 683 |
| `meteor_551_u2020` (upgraded source) | **37,914 B** | **940** |

Conclusion 1.25's *data* findings stand (they were verified against `Input.txt` and
`characteract.txt`, not against this file), but any **behavioural** claim read from `MeteorPort`
alone should be re-checked in `meteor_551_u2020`.

#### 1.26.2 The original move data is already parsed — 574 poses

`_sources/Meteor_Extracted/` holds the result of parsing the original `.pos` files, which is the
data the exe's flex/bison keyword table (`0x005d1930`–`0x005d1f6c`, §1.25) exists to read:

| file | size | content |
|---|---|---|
| `POS招式帧数据.json` | **5.17 MB** | per-pose frame ranges: `pose`, `note` (Chinese), `start`/`end`, `loop_start`/`loop_end`, `effect_type`/`effect_id`, and `sub[]` segments typed `Blend` / `Action` with speeds |
| `P0POS_完整574.json` | 268 KB | 574 poses, full field set |
| `POS_v4_完整字段.json` | 154 KB | field schema v4 |
| `★最终招式总表.json` | 181 KB | final move table |
| `动作衔接表.json` | 27 KB | action adjacency |
| `combat_database_v3.json` / `combat_database_修正版.json` | 119 KB / 66 KB | combat parameters |
| `原版机制_完整数据.json` | 14 KB | original mechanics |
| `武器数据_原版实测.json` | 7 KB | per-weapon data |
| `RootMotion_v2_轴序校正.json` | 419 KB | root motion, axis-corrected |

Example record (`ATKPose.pos`, pose 200, note `暗器輕`): `start 3511`, `end 3533`,
`sub = [Blend 3511–3513, Action 3514–3530, Blend 3531–3533]`, `effect_id Pos200`.

**So the "where are the move frames" question is closed by data, not by disassembly.** Any remaining
work on move content is a *file-format* question, and it is already answered.

#### 1.26.3 CORRECTION — the resource spend is real, and I declared it absent four times

`MeteorInput.CheckPos(int KeyMap, int targetAct)` (39,399 B file, body 1,664 lines) opens with a
gate, then a **two-dimensional table over weapon type × `KeyMap`**:

```csharp
public bool CheckPos(int KeyMap, int targetAct) {
    bool flag = false;
    if (!AcceptInput()) return false;
    int weaponType = mOwner.GetWeaponType();
    switch (weaponType) {
    case 1:
        switch (KeyMap) {
        case 25: flag = true; break;                       // free
        ...
        case 31:
            if (Singleton<GameData>.Instance.gameStatus.EnableInfiniteAngry) { flag = true; break; }
            if (mOwner.AngryValue < 100) { flag = false; break; }
            flag = true;
            mOwner.AngryValue -= 100;                      // <-- the spend
            break;
        case 88:
            if (mOwner.AngryValue < 60) { flag = false; break; }
            mOwner.AngryValue -= 60;                       // <-- the spend
            flag = true; break;
        ...
```

Extracted in full — 12 weapon types carry a table, 4–12 `KeyMap`s each:

| weapon | free KeyMaps | costs |
|---|---|---|
| 0 | 44, 47 | 45:**100**, 151:60, 152:60 |
| 1 | 25,26,27,28,29,30,32,34,84 | 31:**100**, 88:60, 150:60 |
| 2 | 7, 59 | 8:**100**, 147:60 |
| 3 | 1, 85, 87 | 4:**100**, 143:60, 144:60 |
| 4 | 59, 81, 83 | 82:**100**, 157:60, 158:**100** |
| 5 | 59, 70, 72 | 71:**100**, 155:60, 156:60 |
| 6 | 11, 59 | 12:**100**, 145:60, 146:60 |
| 7 | 57, 60 | 58:**100**, 153:60, 154:60 |
| 8 | 20, 24 | 21:**100**, 148:60, 149:60 |
| 9 | 106 | 104:**100**, 159:60, 160:60 |
| 10 | 114, 119 | 115:60, 120:**100**, 121:**100** |
| 11 | 127, 135, 140 | 128:50, 136:50, 141:50, 142:**10** |
| 89/90/92/93/95/97/98/99/101–104/159/160 | — | (empty cases) |
| 105 | 106 | — |

**This overturns §1.22.7 / §1.23.5's "no counter, no resource spend — 7th record".** The statement
was scoped to the *attack command chain* and was correct there; it was wrong as a statement about
the game. The spend lives in the **selector**, keyed on `KeyMap`, and it is per weapon type. Four
times I wrote "not found" while the answer sat in a file the project already had.

Two supporting observations:

- `EnableInfiniteAngry` is a **cheat flag read at the spend site**, not at load time — so the spend
  path is the same code with one branch skipped. A clone that gates on a global at load time will
  diverge whenever the flag is toggled mid-session.
- The threshold `100` and the cost `100` coincide, but `60`/`60` and `50`/`50` and `10` also appear,
  so cost and threshold are independent numbers per row, not one shared constant.

#### 1.26.4 What this does *not* yet prove

`CheckPos` is read from the **Android decompilation**, not from `Meteor.exe`. So the table above is
`🟡 inferred` for the original, not `✅ confirmed`:

- The 12-weapon shape matches §1.24.x's 12-constructor weapon factory, which is independent
  corroboration for the *structure*.
- The `KeyMap` index space matches `Input.txt`'s `Lines` values (25–34, 84, 88, 150 all appear in
  the table's own `Idx 1..20` rows), which is corroboration for the *keys*.
- The specific costs (100/60/50/10) have **no exe-side evidence yet.**

Attempted exe verification and its negative result: scanning all `CMP [reg+off],0x64|0x3c`
instructions across the image returns **exactly 2 sites, at 2 different displacements, never both
constants at the same offset** — i.e. the original does not compare against 100 and 60 as immediates
at one field. So either the field is compared via a register-loaded constant, or the original's
units are not 100/60. **This is an open item (`❓`), not a refutation** — but it means the 100/60
numbers must not be assumed correct for the original.

#### 1.26.5 Revised status of the "selection" question

| piece | state | source |
|---|---|---|
| input sequences → group (`KeyMap`) | ✅ | `Input.txt` + `ActionInterrupt.Init()` |
| `KeyMap` → `ActionIdx` members | ✅ | `characteract.txt` `group(...)` |
| `ActionIdx` adjacency (`226(227,235)`) | ✅ | `characteract.txt` |
| weapon filter (which groups a weapon may use) | ✅ structure | `IsWeaponKey` + 12-type factory |
| **anger gate + spend per `KeyMap`** | 🟡 | `MeteorInput.CheckPos` (Android); exe未证 |
| move frame data (574 poses) | ✅ | `POS招式帧数据.json` |
| `[+0xDC]` movement machine | ✅ measured | §1.25.10 |
| `0.11` hold-jump ratio semantics | ❓ | §1.24.4 remains |
| `cmd 0x0F` zero-arg setter | ❓ | §1.24.4 remains |
---

### 1.27 Cross-checking the tear-down: source vs. decompile, same version

> Method correction. §1.25–§1.26 were read from `MeteorPort`, which is the **APK decompilation**.
> The correct control is *inside `_sources`*: `_gt/v280` holds the **v2.8 source tree** — the same
> version as `MeteorV0.2.8.0.apk`. Comparing the two is the cheapest possible audit of my own reading.
> (The three live Unity projects are deliverables, not evidence, and are not used below.)

#### 1.27.1 The two copies, side by side

| file | size | lines |
|---|---|---|
| `_gt/v280/Assets/Meteor/ResLoader/ActionInterrupt.cs` (source) | 36,988 B | 939 |
| `MeteorPort/src/Assembly-CSharp/ActionInterrupt.cs` (decompiled) | 16,411 B | 733 |

The decompile is **44% smaller**. What the source has and the decompile does not:

- **named arrays** — `slash0Ground` … `slash18Ground` instead of `scan`, `scan2` … `scan27`
- **per-array Chinese labels** — `//下A地面`, `//左攻击无空中招式`, `//上上上-枪绝招`
- **a verbatim block comment** reproducing `Input.txt`'s 19 rows with their key sequences

Critical point: the **structure is identical**. Ground set = 19 arrays, air set = 8, total 27 — exactly
what §1.25.3 counted from the decompile. So that section's numbers are **independently confirmed by
source**, and its `scan2..scan27` labels can now be replaced with real names:

| source name | `Input.txt` Idx | key sequence | note in source |
|---|---|---|---|
| `slash0Ground` / `slash0Air` | 2 | `SJ` | 下A |
| `slash1Ground` | 3 | `AJ` | 左攻击（无空中） |
| `slash2Ground` | 4 | `DJ` | 右攻击（无空中） |
| `slash3Ground` / `slash3Air` | 5 | `WJ` | 上攻击 |
| `slash4Ground` / `slash4Air` | 6 | `SSJ` | 下下攻击 |
| `slash5Ground` / `slash5Air` | 7 | `WWJ` | 上上攻击 |
| `slash6Ground` / `slash6Air` | 8 | `AAJ` | 左左攻击 |
| `slash7Ground` / `slash7Air` | 9 | `DDJ` | 右右攻击 |
| `slash8Ground` / `slash8Air` | 10 | `SWJ` | 下上攻击 |
| `slash9Ground` / `slash9Air` | 11 | `WSJ` | 上下攻击 |
| `slash10Ground` | 12 | `ADJ` | 左右攻击 |
| `slash11Ground` | 13 | `DAJ` | 右左攻击 |
| `slash12Ground` | 14 | `ADSJ` | 左右下攻击 |
| `slash13Ground` | 15 | `SADJ` | 下左右A |
| `slash14Ground` | 16 | `ADWJ` | 左右上 |
| `slash15Ground` | 17 | `SSWJ` | 下下上 |
| `slash16Ground` | 18 | `SWWJ` | 下上上 |
| `slash17Ground` | 19 | `WWWJ` | **上上上-枪绝招** (`{153}`) |
| `slash18Ground` | 20 | `ADWSJ` | **左右下上-忍刀绝招** (`{136}`) |

**`slash1`/`slash2`/`slash10`/`slash11` have no air array at all** — the source says so explicitly
(`//左攻击无空中招式`). §1.25.5's "ground and air are disjoint sets" is therefore literal: four of the
nineteen ground chains are ground-only by construction, not by filter.

#### 1.27.2 The weapon enum, which names the fourth hop's mystery

`_gt/v280/Assets/Meteor/Common.cs`:

```csharp
public enum EquipWeaponType {
    Sword = 0,        // 剑
    Knife = 1,        // 匕首
    Gun = 2,          // 火枪
    Dart = 3,         // 飞镖
    Hammer = 4,       // 锤子
    Blade = 5,        // 刀
    Guillotines = 6,  // 血滴子
    Lance = 7,        // 长枪
    Brahchthrust = 8, // 分水刺
    HeavenLance = 9,  // 乾坤拔刀
    Gloves = 10,      // 拳套
    NinjaSword = 11,  // 忍刀
}
```

§1.24.x found that `weapon->vtable[21]` is a compile-time constant, `RET 1` for 9 types and `RET 0`
for types **2, 3, 6**, and explicitly declined to name those three pending evidence. Now they are
named: **Gun (火枪), Dart (飞镖), Guillotines (血滴子)** — the three ranged weapons. The constant is a
**"may this weapon enter melee chain selection"** answer, and 0 is correct for a firearm.

#### 1.27.3 `CheckPos`, from source, with the original's own comments

`_gt/v280/Assets/Meteor/MeteorController.cs` holds the same function the decompile filed under
`MeteorInput`, with the **same signature** `public bool CheckPos(int KeyMap, int targetAct)` but
switching on `case (int)EquipWeaponType.Knife:` rather than on bare integers. Re-extracted:

| weapon | free KeyMaps | paid (cost) | source comments |
|---|---|---|---|
| **Sword** (0) | 44, 47 | **45:100**, 151:60, 152:60 | 大招 / 左右A剑气 / 右左A小绝旋转 |
| **Knife** (1) | 25,26,27,28,29,30,32,33,34 | 31:**100**, 88:60, 150:60 | 下上上A 阎罗 / 下下A 地面小绝 下扎 / 空中下下A |
| **Gun** (2) | 6, 59 | **7:20**, 8:100, 147:60 | 大绝 / 一般空踢 / 小绝 |
| **Dart** (3) | 1, 85, 87 | 4:**100**, 143:60, 144:60 | 落樱雪 / 地面八方绝 / 空中八方绝 |
| **Hammer** (4) | 59, 81, 83 | 82:**100**, 157:60, 158:**100** | 铜皮 / 震荡波 / 大绝 |
| **Blade** (5) | 59, 70, 72 | 71:**100**, 155:60, 156:60 | 大绝招 / 旋风斩 / 雷电斩 |
| **Guillotines** (6) | 11, 59 | 12:**100**, 145:60, 146:60 | 一般空踢 |
| **Lance** (7) | 57, 60 | 58:**100**, 153:60, 154:60 | 大招 / 强攻 前前前A / 左右下A 小绝招 |
| **Brahchthrust** (8) | 20, 24 | 21:**100**, 148:60, 149:60 | 左右上小绝 / 加速BUFF |
| **HeavenLance** (9) | 106 | 104:**100**, 159:60, 160:60 | 大绝招 / 持枪小绝-Pos 570 / 拔刀小绝-Pos 568 |
| **Gloves** (10) | 114, 119 | 115:60, 120:**100**, 121:**100** | 大绝 / 嗜血 |
| **NinjaSword** (11) | 127, 135, 140 | 128:50, 136:50, 141:50, **142:10** | 忍术-隐忍 / 天地同寿 / 忍爆弹-忍大招 / 左右A 10气 |

**Corrections to §1.26.3's table** (that one was parsed from the decompile, which splits merged
`case` labels differently):

- **Gun (2), KeyMap 7 costs 20** — §1.26.3 listed it as free. It is the only 20-cost row in the game.
- **Knife (1), KeyMap 84 is free** — it shares a `case` label with 33 (`case 84: case 33:`) and the
  decompile split them; §1.26.3 put 84 in "free" and omitted 33. Both are free.
- Everything else matched.

The 20/50/60/100 spread is not a single scale: **Gun's 7 costs 20** while every other "small ultimate"
costs 50 or 60, and NinjaSword's plain 左右A costs **10**. Cost and threshold are per-row independent
numbers, never one shared constant — confirmed by source, not inferred.

#### 1.27.4 Three rule comments that matter more than the table

These are the original author's own notes, and they are behavioural specifications that no amount of
disassembly had produced:

1. **`case 27 // 上上A, 前3个按键里面只有找到至少2个按下W按键`**
   — "double-W" is **not a literal adjacent sequence**: it is *counted within the last 3 key events*.
   A clone matching `W,W` adjacently will drop inputs the original accepts (e.g. `W, X, W`). This is a
   windowed count, not a string compare.

2. **`case 25 // 匕首普攻, 需要看输入缓冲是否含有其他方向键, 或者含有任意方向键的状态`**
   — plain attack's behaviour depends on the **contents and state** of the input buffer, not only on
   whether the button was pressed.

3. **`case 84 // 下A 空 地都可以 接空中252不能在地面 接地面343不能在空中`**
   — an adjacency that is legal in air and illegal on ground, i.e. the ground/air split is enforced a
   **second time** at the transition, not only in `GetSlashNode`'s two array sets.

HeavenLance (9) additionally carries a 17-line comment block mapping KeyMaps 89–106 to action ids
(`89: 左A 拔刀切换持枪 430`, `90: 下下A 拔刀切换居合 431`, `104: 451 大绝招`, `106: 空中下A 446`, …),
which is the closest thing to a documented transition table found anywhere in this project.

#### 1.27.5 Status changes

| claim | before | now |
|---|---|---|
| 19 ground / 8 air, 27 total vectors | ✅ (decompile only) | ✅ **source-confirmed** |
| vector contents == `Input.txt` `Lines`/`LinesAir` | ✅ 27/27 | ✅ **source-confirmed** (source has the table pasted as a comment) |
| `vtable[21]` returning 0 for types 2/3/6 | 🟡 unnamed | ✅ **named: Gun / Dart / Guillotines — ranged** |
| anger table shape (12 weapons × KeyMap) | 🟡 decompile | ✅ **source-confirmed** |
| anger costs 100/60/50/10 | 🟡 | ✅ **source-confirmed**, plus a 20 that §1.26.3 missed |
| anger values apply to `Meteor.exe` | ❓ | ❓ **unchanged** — still no exe-side evidence (§1.26.4) |
| "double-W" = adjacent `W,W` | implicit | ❌ **wrong** — it is ≥2 W within the last 3 events |
---

### 1.28 Android tear-down vs. the Windows binary — the actual reconciliation

> Task: reconcile the Android reverse-engineering artefacts against the Windows build being analysed.
> Result: the two **do not overlap in what they can answer**. The data is Windows; the code is Android.
> Mixing them silently is the main risk this section exists to prevent.

#### 1.28.1 The hardest possible anchor: the executables are byte-identical

```text
D:\MeteorProjects\_sources\Meteor_Extracted\app\Meteor.exe
C:\Program Files (x86)\Meteor\Meteor.exe
  size 1,945,600 B   md5 cf2aa5c21a0a687afacc5e5c0876c543   — identical
```

`Meteor_Extracted/app/` is a full unpacked client (it also holds `Meteor.exe.i64` — an IDA database,
`Meteor.res`, `ETexture.pak`, `Level/`, `Patch/`, `PScriptLib/`). Because its `Meteor.exe` is the very
binary this spec has been disassembling, **every file under `Meteor_Extracted/` is by construction
data of the exact build under analysis.** No version-inference is required.

`★交付总览.md` names the build: **9.07.16**, unpacked from `Meteor_9.07_Setup.exe` (Windows) plus
`MeteorV0.2.8.0.apk` (Android).

#### 1.28.2 Three `.pos` sources exist and they are all different

| source | `P0.pos` size | note |
|---|---|---|
| `Meteor_Extracted/app/pmodel/` | **296,888 B** | the build being analysed (9.07.16) |
| `_gt/master/.../Resources/9.07/P0.pos.bytes` | 278,385 B | an **earlier 9.07 point release** |
| `_gt/master/.../Resources/1.07/P0.pos.bytes` | 274,178 B | 1.07 |

Same held for all 20 files (`P0`–`P19`): **0 of 21 identical between 9.07 and 1.07** in the iOS tree, and
the 9.07.16 copy is a further ~18 KB larger than the iOS tree's 9.07.

**Consequence:** "9.07" is not one dataset. A clone that reads the iOS tree's `9.07/*.pos.bytes`
gets a **different** pose set from the one `POS招式帧数据.json` (574 poses) was derived from. These
must not be mixed.

#### 1.28.3 The `KeyMap` space is stable, the action space is not

| file | 9.07 | 1.07 |
|---|---|---|
| `characteract.bytes` size | 9,945 B | 6,881 B |
| `group(...)` count | **160** | **160** |
| Windows `.txt` equivalent | 10,398 B / 160 groups | 7,281 B / 160 groups |

*160 in all four*, so the group ordinal space (which **is** `KeyMap`, §1.25.8) is version-invariant:
`Input.txt`'s `Lines`/`LinesAir` columns index it safely across versions. But the byte sizes differ by
45%, so **the members of each group differ** — later versions add actions to existing groups.

⇒ **`KeyMap` is portable between 9.07 and 1.07; the `ActionIdx` list it expands to is not.** Any table
keyed on action ids must be regenerated per version; any table keyed on `KeyMap` need not.

This also independently corroborates §1.25.8's group count (160, measured from `characteract.txt`)
and `★交付总览.md`'s "取消系统：160 group + 189 条衔接".

#### 1.28.4 What each tree can and cannot answer

| artefact | belongs to | usable as |
|---|---|---|
| `POS招式帧数据.json` (5.17 MB, 574 poses, `sub[Blend/Action]`) | **Windows 9.07.16** | ✅ **primary** — same build as the binary |
| `P0POS_完整574.json`, `POS_v4_完整字段.json` (171 attack poses) | Windows 9.07.16 | ✅ primary |
| `动作衔接表.json` (160 group + 189 transitions) | Windows 9.07.16 | ✅ primary |
| `★最终招式总表.json` (240 moves × 13 weapon groups) | Windows 9.07.16 | ✅ primary |
| `RootMotion_v2_轴序校正.json` (164 moves) | Windows 9.07.16 | ✅ primary |
| `Meteor_res_音效招式对照.json` (315 entries) | Windows **only** (总览 marks it so) | ✅ primary |
| `Input.txt`, `characteract.txt` | Android v0.2.8.0 | 🟡 format reference; **verify** against 9.07.16 |
| `ActionInterrupt.cs`, `MeteorInput/MeteorController.CheckPos`, `EquipWeaponType` | Android v0.2.8.0 rewrite | 🟡 **algorithm reference only** |
| `MeteorUnit.cs` physics constants (160/180/2000/68) | Android rewrite's own tuning | ❌ not original values (§1.25.9) |

**The two trees are complementary, not redundant:** Windows supplies *content*, Android supplies a
*readable implementation*. Neither can substitute for the other, and the Android numbers must never
be presented as original values.

#### 1.28.5 Reconciliation verdict

| question | answer | strength |
|---|---|---|
| is the 574-pose data from the build under analysis? | **yes** — binary md5 identical | ✅ byte-exact |
| is `Input.txt`'s 20-row table from 9.07.16? | **unproven** — it ships with the Android project; no Windows-side original has been located | ❓ open |
| does the `KeyMap`→group ordinal mapping hold across versions? | **yes** — 160 groups in all four sources | ✅ confirmed |
| do action ids transfer across 9.07 point releases? | **no** — 21/21 `.pos` files differ; group bodies differ 45% by size | ✅ confirmed |
| are the anger values (100/60/50/20/10) original? | **unproven** — Android source only; no exe-side evidence (§1.26.4) | ❓ open |
| is `EquipWeaponType`'s 12-weapon enum original? | **structure yes** (matches §1.24.x's 12-constructor factory); **names/order unproven** | 🟡 |

**The single actionable risk:** if `MeteorRebuild` consumes the iOS tree's `9.07/*.pos.bytes`, it will
run on a *different pose set* from the 574-pose dataset that all the combat tables were built from.
Point it at `Meteor_Extracted/app/pmodel/` instead — that is the only tree provably tied to the
analysed binary.
---

### 1.29 Verification run — the data chain closes

> §1.28 established *provenance*. This section runs the checks that would fail if the provenance were
> wrong. Six tests, all computed from the artefacts themselves; no inference.

#### 1.29.1 Setup

| role | file | identity |
|---|---|---|
| original chain graph | `Meteor_Extracted/app/Common/character.act` | 9.07.16, Big5 text, 10,389 B, md5-locked to the analysed binary's tree |
| original pose table | `Meteor_Extracted/P0POS_完整574.json` | 574 poses, ids 0..573 |
| input table | `MeteorPort/TextAssets/…__Input.txt` | 20 rows, `Lines` / `LinesAir` = KeyMap sets |
| parser under audit | `ActionInterrupt.Init()` semantics (§1.25.8) | group ordinal = `KeyMap`, 1-based |

`character.act` was parsed with the same algorithm as `Init()`: every `group(...)` line advances a
counter, the counter **is** the `KeyMap`, and `group(N-M)` expands to the inclusive range `N..M`.

#### 1.29.2 Results

| # | test | result |
|---|---|---|
| **T1** | every `KeyMap` referenced by `Input.txt` exists as a group | ✅ 159 distinct KeyMaps, max 160, **0 missing** |
| **T2** | every group member exists as a pose | ✅ 227 members, ids 200..572, **0 missing** from the 574-pose table |
| **T3** | 20 chains expand to actions, all of which exist as poses | ✅ **226 distinct actions, 0 missing** |
| **T4** | measured `Pose90` matches the pose table | ✅ see §1.29.3 — frame-exact |
| **T5** | `group_count` | ✅ 160 = 160 |
| **T6** | `transition_count` | ⚠️ 189 (JSON) vs 217 (lines) vs 1,673 (edges) — see §1.29.4 |

`Input.txt` row 1 (`J`) is the only row that resolves against group 1 *and* was expected to bypass the
matcher — consistent with §1.25.3's note rather than a contradiction, since `J`'s 32 actions are the
plain-attack pool reached by the basic-key path.

#### 1.29.3 T4 is the load-bearing check: three independent sources agree

| source | statement |
|---|---|
| static chain (§1.24.4) | attack → `SetState(4)`; state 4 makes the jump dispatcher a no-op |
| runtime log (§1.25.10) | every one of 12 `state 4` ticks is `act=90`, and the frame counter reads **`f=1694`** |
| pose table (this test) | `pose 90` → `start=1694, end=1701` (8 frames) |

**1694 matches 1694.** The `start`/`end` fields of `P0POS_完整574.json` are therefore in the same
unit and the same origin as the runtime `AnimFrame` counter — which means the clone can drive frames
straight from that table, with no conversion.

Two further facts fall out of the same test:

- **`pose 90` is not a member of any group and is unreachable from all 20 chains** (`in allg = False`,
  `reachable = False`). It is a *basic* action, not a chain action — exactly what `Input.txt`'s own
  note says ("基础动作…由基本按键识别系统识别"). So the state-4 air attack is entered from the basic
  path, which is consistent with `MOUSE1` arriving as a raw key event (§1.22.1) rather than through
  the chain matcher.
- `pose 90` carries **no name and no segments** (`name=''`, `segs=0`), while adjacent poses 89 and 91
  also have empty names — a block of unnamed basic actions, distinct from the named attack poses.

#### 1.29.4 T6: 189 vs 217 vs 1,673 is a unit mismatch, not a discrepancy

| count | what it measures |
|---|---|
| **160** | `group(...)` lines — matches the JSON exactly |
| **217** | non-`group` lines containing ≥2 integers |
| **1,673** | successor **edges** (each `N(a,b,c)` contributes 3) |
| **189** | the JSON's `transition_count` |

1,673 edges over 217 statements is arithmetically coherent (avg 7.7 successors each). 189 sits 28
below my 217, and the most likely 28 are `section` header lines (weapon names such as `刀`, `刺`,
`劍`) that my line parser counts as statements because they carry digits. **Open, but immaterial:**
the graph used for T2/T3 is built from `group` lines only, which match exactly at 160.

#### 1.29.5 Verdict

**The data chain is closed and usable.** The four checks that could have invalidated it — KeyMap
resolution, group→pose coverage, chain→pose coverage, and the frame-origin identity — all pass with
zero missing entries. The one open count (189 vs 217) touches only the reporting of how many
transition *statements* exist, not the graph the clone consumes.

What this licenses:

1. `MeteorRebuild` may read poses from **`Meteor_Extracted/app/pmodel/`** and frame-drive from
   `P0POS_完整574.json` directly — the frame units agree with the running original.
2. Chain selection may be implemented as **KeyMap → group → action** against `character.act`, with the
   20-row `Input.txt` supplying the KeyMap sets. All 226 reachable actions exist.
3. The 348 poses **not** reachable from any chain are the basic/hit/reaction pool — they must be
   driven by the basic-key path, not by the chain matcher.
---

## Methodology note (earned the hard way)

*(The list is 1–11. Item 10 carries one numbered sub-rule, 10.1. Quote accordingly.)*

Three consecutive false trails in this project came from **starting at strings**: string xrefs
classified a 23 KB UI renderer as a weapon FSM; a `fopen` mode string was read as a comparison
operator; `std::map` internals were read as per-tag handlers.

The shape proxies actually used as authority now, in descending reliability:

1. **`RET n` arity** — the byte count popped tells you exactly how many arguments an indirect call
   target accepts. This is what finally identified the real slot-3 receiver (§1.16) after five
   candidates looked byte-plausible, and it survives every later check in §1.17. Cheap, unambiguous,
   never lies. Pair it with the **self-tail-jump refutation**: if binding candidate *X* would make an
   emitter call into a body whose own tail jumps straight back to `X`, you get an infinite loop with
   no stack cleanup — that candidate is therefore structurally impossible, regardless of what bytes
   sit in the table. Arity rules candidates **in**; the tail-jump test rules the rest **out**.
   Note carefully that a correct-looking table entry can be simultaneously *byte-true* and *not the
   binding in use* under MSVC multiple inheritance (`mem[0x005aa658+0xc]` really is `0x004c8a70`, yet
   the senders call `FUN_004a9770`) — read the entry, then prove the binding.
2. **vtable occupancy** — which functions co-reside in one pointer array proves class membership;
   how many vtables share one implementation proves it is a shared base/router.
3. **vptr writes inside constructors** — but MSVC multiple inheritance makes several values legal for
   one object, so combine with (1).
4. **float/constant signatures and API call points** — used throughout §1.9–1.15.
5. **strings** — a lead only. Never a conclusion.
6. **Listing before decompiler.** `DecompInterface` can hang indefinitely on a perfectly ordinary
   175-byte body (§1.17), and it burns wall-clock silently while doing so. `_disassembly + `RET n` +
   structural shape answered every question of that pass. Watch for the failure signature: log output
   stops growing. Reach for the decompiler *after* the listing has already told you what to expect.
7. **A slot index is meaningless without its base.** `vtable[N]` is only valid relative to the vfptr
   the object actually stores. §1.22.4 is the cost of getting this wrong: the input object's table
   read from `0x5AA660` produced "slot 39", from `0x5AA6A8` it is "slot 21" — and
   `0x5AA660 + 39*4 == 0x5AA6A8 + 21*4`, one dword. That arithmetic also manufactured a false
   conclusion (a "shared method family spanning classes") out of pure indexing. Before quoting a
   slot number, read the vfptr out of the constructor, confirm slot 3 / slot 0 against a known
   function, and print the byte address rather than the index.
8. **Disambiguate by operand shape, not by displacement.** On the input object `+0xE8` is *both* a
   member (the 0x48-byte clock pointer) and **virtual slot 58**, so `MOV ECX,[ESI+0xE8]` and
   `CALL [EAX+0xE8]` occur in the same function and both are legitimate. A scan for the
   displacement alone returned 78 "readers" of the clock, 74 of which were calls *to* slot 58 —
   i.e. to the reader. Filter on `CALL dword ptr [...]` vs `MOV` before counting anything.
9. **When a storage target has exactly one reference and that reference is a vtable dword, the
   search was slot-based, not xref-based.** `FUN_004CD3B0` has one reference (`0x5AA790`); any
   xref-driven hunt for its callers reports "none" and looks like a dead end.
10. **A slot offset is not an identifier.** `+0x12c` occurs as a virtual-call offset **66** times
   image-wide (12 of them in `0x48xxxx` alone); `+0xE8` is both a member and slot 58; the same dword
   `0x5AA7B0` is slot 86 of base `0x5AA658`, slot 84 of `0x5AA660` and slot 66 of base `0x5AA6A8`.
   Always write `base + index` **and** the resolved address, never the offset alone.
   **10.1 Never quote a count read off a truncated listing.** The first version of this item said
   "16 times in a single module" because 16 was the number of lines a `head -30` happened to show;
   the real figures are 66 / 12 / 24. Print the total on its own line and quote that, never the
   visible remainder. Cite this rule as **10.1**, not as item 11 — the list runs 1–11 and this is a
   sub-rule of 10, which is precisely how the count drifted between two reports of the same
   document.
11. **`RET n` on the callee is the fastest way to falsify a candidate call site.** The
   `cmd 0x0F → setter` link in §1.24.4 fails this test: the call pushes nothing, the callee pops 4.
   Either the `this` is a different class or the listing is missing a push — declaring it "found"
   would have been the seventh wrong answer for the same reason as the first six.
12. **Proximity is not identity.** A case body that sits immediately after the dispatch instruction is
   not necessarily the first entry's body. §1.24.7 cost this document a frozen conclusion because
   `0x4bb81f` follows `JMP [EAX*4 + 0x4bbfe8]` and *looked* like case 0 — it is index 12. Read the
   table, map `index → cmd`, then look up the address. This is a distinct failure mode from the six
   before it, which were all wrong bases, wrong operands, or strings taken as conclusions.

## Appendix: evidence index
| Claim | Function | Address | Status |
|-------|----------|---------|--------|
| 43 combat functions anchored via string xrefs (all auto-named) | CombatAnchor pass | — | ✅ confirmed |
| `FUN_0045b280` = config/command-string orchestrator, not per-frame resolver | FUN_0045b280 | 0x45b280 | 🟡 inferred |
| Combat attributes are string-keyed (data-driven property table) | FUN_0056bc60 | 0x56bc60 | ✅ confirmed |
| attribute→code: animation=10, damage=3, machine=12, treasure=15, normal=0, targeta=13, targetb=14 | FUN_0056bc60 | 0x56bc60 | ✅ confirmed |
| two backend resolvers by object type {3,4}→FUN_00564f90, {7,8}→FUN_00564fc0 | FUN_0056bc60 | 0x56bc60 | ✅ confirmed |
| ~~three ~23KB weapon functions host 连招/位移~~ — premise rejected: the real hosts are the small vtable/float-anchored functions §1.9–§1.11; `452af0` is UI | FUN_00436bb0/446380/452af0 | 0x436bb0/446380/452af0 | ❌ retracted |
| `FUN_00436bb0` ≡ `FUN_00446380` (byte-identical clones, loop-heavy update routine) | diff of decompilations | 0x436bb0 / 0x446380 | ✅ confirmed |
| ~~`FUN_00452af0` = per-frame action FSM~~ **RETRACTED — UI/menu renderer** (`operator_new(0x50)` at :110/428/2012/2900; `DAT_005c7b60` coord scaling at :115–121) | FUN_00452af0 | 0x452af0 | ❌ retracted (§1.7) |
| ~~per-state action in handler tables DAT_005e0068/74/78~~ — those are `.bss`, read back all-null (`tables_dump.txt`); no static content exists | FUN_00452af0 | 0x452af0 | ❌ retracted |
| ~~`0x4559e4`/`0x453308` are external handler functions~~ — `functionContaining` returns `FUN_00452af0` itself: internal labels | FUN_00452af0 | 0x452af0 | ❌ retracted |
| `FUN_005565e0(x) = *(x+0x20)` state getter — fact stands, but its FSM context is now void | FUN_005565e0 | 0x5565e0 | ✅ isolated fact |
| **Main physics integrator: sweep → per-axis resolve (X=1,Y=4,Z=16) → ground `self[0xd7]` → `v -= n*dot(v,n)` slide** | FUN_004ceb50 | 0x4ceb50 | ✅ confirmed (§1.9) |
| collision query via vtable `+0x100`; damping `DAT_005aa934`; sweep `FUN_00564760`; restitution `1-2k` | FUN_004ceb50 | 0x4ceb50 | ✅ confirmed |
| **四级击退 tiers = 600.0 (default) / 350.0 (0x8) / 400.0 (0x9) / 450.0 (0xa,0xb)** | FUN_004d0ac0 | 0x4d0ac0 | ✅ confirmed (§1.10) |
| damage delivered as vtable `+0xc` command `0xd`; knockback = dir × magnitude | FUN_004d0ac0 | 0x4d0ac0 | ✅ confirmed |
| ~~keyword parser: 4 semantic tags Jump/Fake/Cure/Fool + comparator `r`~~ **CORRECTED** — my grep missed Ghidra's `s_*` symbols; the true vocabulary is **16 action keywords**, all resident in this body (`keywords16.txt` / `keywords16_map.json`) | FUN_004d1740 | 0x4d1740 | 🔄 corrected (§1.11) |
| **all 16 keyword→scalar pairs resolved** with cmp site + `MOV EBP` site for each row (Attack 0x1000, Guard 0x20, Jump 0x1200, SwitchWeapon 0x45, Unlock 0x51, DropWeapon 0x47, Fake 0x59, RightTurn 0x27, LeftTurn 0x25, DropItem 0x48, Cure 0x54, Crouch 0x43, InitialCamera 0x4c, Fool 0x52, Score 0x9, HitAttack 0x46) | FUN_004d1740 | 0x4d189d–0x4d1a08 | ✅ confirmed |
| ~~values are composable bit flags (OR-accumulated)~~ **REFUTED**: all 16 are `MOV EBP,imm`; zero `OR`/`AND`/`ADD` on `EBP` in all 436 instructions; only 3 `XOR EBP,EBP` resets | FUN_004d1740 | 0x4d189b / 0x4d18af … | ❌ refuted |
| ~~`"r"` (0x5c67d0) is a comparison operator~~ **CORRECTED**: it is `fopen`'s mode argument; the function is `fopen`→`fread(1B)`→`fclose` with `"Read error"` on `(stream+0xc)&0x20` | FUN_004d1740 | 0x4d1762 / 0x4d1740 tail | 🔄 corrected |
| ~~five tag handlers are per-tag semantic consumers~~ **REFUTED**: they are `std::map` internals — `0x49c330` insert, `0x49aff0` clear/dtor, `0x49c0d0` max, `0x49be40` rotate/erase, `0x4a1ab0` lazy singleton | — | 0x49c330 / 0x49aff0 / 0x49c0d0 / 0x49be40 / 0x4a1ab0 | ❌ refuted |
| token operands converted by `atoi` (`FUN_0050915b → FUN_005090d0`: whitespace `&8`, sign `±`, digit `&4`), guarded `< 0x100`; tokens are 12-byte records; `+` chains one more operand | FUN_004d1740 | 0x4d1a1f / 0x4d1a27 | ✅ confirmed |
| resulting `std::map` is **function-local**; tail globals `0x5d59a4`/`0x5d59e8` are the MSVC CRT small-block free-list (thousands of xrefs, `(size+7)>>3` 8-byte buckets), not this parser's store | — | 0x5d59a4 / 0x5d59e8 | ✅ confirmed |
| **jump dispatch**: `switch(param_1[0x37])`, impulse selected between `_DAT_005aa93c` / `_DAT_005aa940`, emits vtable `+0xc` cmd `7` | FUN_004cf5b0 | 0x4cf5b0 | ✅ confirmed (§1.13) |
| **wall dynamics**: time gates `_DAT_005aa8f0`/`_DAT_005aa8e8`, blend coeffs `_DAT_005aa8e0`/`_DAT_005a83ec`, additive into velocity `+0xe4/+0xe5/+0xe6`, emits cmd `7` | FUN_004cd200 | 0x4cd200 | ✅ confirmed (§1.14) |
| **`vtable +0xc` is a single shared command channel** — input `0x33` (§1.12), damage `0xd` (§1.10), jump/wall `7` (§1.13/1.14) | multiple | — | ✅ confirmed |
| `FUN_004d0540` (1,356 B) holds the impulse maths at `0x4d0674–0x4d06be`: `fmul [0x5aa934]`=600.0, `fadd [0x5aa944]`=0.13; "impulse equation" and "direction negation × global coefficient" describe the same formula | FUN_004d0540 | 0x4d0540 | ✅ reconciled (§1.15) |
| unresolved attribute codes read: `4="hell"`, `5="safea"`, `6="safeb"`, `11="door"` → 15-key vocab | FUN_0056bc60 | 0x56bc60 | ✅ resolved |
| object family shares multi-inheritance adjustor `-0x65c` (0x4ceb50 / 0x4d0ac0 / 0x4d0540) | three functions | — | ✅ confirmed |
| `0x4cb270` is NOT an entry — it lies at +0x10 inside `FUN_004cb260` (900 B) | FUN_004cb260 | 0x4cb260 | ✅ confirmed |
| **input polling = 8 virtual keys (WASD + arrows) OR analogue axis → 4 signed fields → cmd `0x33`** | FUN_004cb260 | 0x4cb260 | ✅ confirmed (§1.12) |
| ~~`0x4cb270` = 连招 + 怒气扣除~~ — body contains no combo counter or resource deduction | FUN_004cb260 | 0x4cb260 | ❌ retracted — combo/anger still unlocated |
| `FUN_004630b0` = name→record linked-list resolver (obj+0x30) | FUN_004630b0 | 0x4630b0 | ✅ confirmed |
| combat data model is named-record driven (name list + property parser) | FUN_004630b0 + FUN_0056bc60 | 0x4630b0 / 0x56bc60 | ✅ confirmed |
| **all six `vtable+0xc` emitters are methods of ONE class family** — each appears exactly once in the 150-pointer array at `0x005aa658` | VtabMap/EvPipe scans | 0x5aa658 | ✅ confirmed (§1.16) |
| ~~`vtable[3] = 0x4C8A70` is the PushEvent receiver~~ **CORRECTED BY ARITY**: `0x4c8a70` is byte-true at `mem[0x5aa658+0xc]` but takes 0 args (clears 5 vectors, tail-jumps) — the bound receiver is `FUN_004a9770` (vfptr `0x005aa6a8`, `RET 0xc` = 3 args) | FUN_004a9770 | 0x4a9770 | 🔄 corrected (§1.16) |
| five vfptr values written by constructors were each resolved & rejected by return-arity except `0x005aa6a8` → `0x4a9770`; others `RET 0x4`/`RET`/tail-jmp | VPtrWrites + Slot3 scans | 0x5aa658/65c/660/6a8/88c | ✅ confirmed |
| `FUN_004a9770` is a pure router (18 B): `this->member_0xc` → `->vtable[8](cmd,buf,len)`, `-1` if absent; occupies slot 3 in **32** vtable slots (most shared slot-3 impl) | FUN_004a9770 | 0x4a9770 | ✅ confirmed |
| second-level router `FUN_004a9790` (32 B) forwards `param_2/3/4` identically — confirms bridge pattern | FUN_004a9790 | 0x4a9790 | ✅ confirmed |
| **terminal dispatcher = `FUN_004bb800`**: only function that is slot-8 resident + computed jump (`0x4bbfe8`) + `RET 0xc` | FUN_004bb800 | 0x4bb800 | ✅ confirmed (§1.16) |
| `FUN_004bb800` = `switch(cmd)` with **44 cases, range 0x3–0x35**, gaps {14,18,35,36,37,38,39}; 25 are self-virtual forwards, rest inline/singleton | FUN_004bb800 | 0x4bb800 | ✅ confirmed (`cmd_dispatch_map.json`) |
| receiver class vtable base = `0x005a9fe0` (225 slots); slot 3 = `0x4a9770`, slot 8 = `0x4bb800`, slot 122 = `0x4bc100` | — | 0x5a9fe0 | ✅ confirmed |
| `case 0x33` → `FUN_004bc100` (31 B): unpacks `buf[0]`,`buf[1]` → singleton `FUN_00487830` → `vtable[223]` | FUN_004bc100 | 0x4bc100 | ✅ confirmed |
| singleton = lazy `operator_new(0x2970)` (10,608 B) ctor'd by `FUN_00486610`, stored in global `DAT_006659b8`, primary vfptr `0x005a9068` | FUN_00487830 / FUN_00486610 | 0x487830 / 0x486610 | ✅ confirmed |
| **final hop = `FUN_00489510` (51 B, `RET 0x8`)** — gates on `this->vtable[218]()`, then forwards `(a,b)` to `member_0x2410 -> vtable[13]`; alternate vfptr yields `RET 0x4` (wrong arity, rejected) | FUN_00489510 | 0x489510 | ✅ confirmed |
| combo counters / resource spend: still nowhere in the traced chain | — | — | ❓ unknown (unchanged) |
| **slot 218 gate = FUN_004891c0 (14 B) reads `this+0x2414`, a load flag** — ~~cancel/anger-window runtime gate~~ **REFUTED**; no unit state is read anywhere in it | FUN_004891c0 | 0x4891c0 | ❌ refuted (§1.17.1) |
| `FUN_00489510` whole body: if `vtable[218]()` then `member_0x2410->vtable[13](a,b)` + return 1, else return 0 (input swallowed); args pushed right-to-left, `RET 0x8` | FUN_00489510 | 0x489510 | ✅ confirmed (§1.17.2) |
| **`member_0x2410` = 280 B object, vfptr `0x005aa660`, ctor `FUN_004c8730`** — three anchors: `operator_new(0x118)`, the ctor call, and `MOV [ESI],0x5aa660` @0x004c8854 (2nd writer 0x004c88c1) | FUN_004c8730 | 0x4c8730 / 0x5aa660 | ✅ confirmed (§1.17.3) |
| ctor zeroes members `+0x8…+0x50` incl. the `+0x28/+0x2c/+0x30` triple = MSVC `std::vector` (begin/end/capacity); inner object at `+0x58` | FUN_004c8730 | 0x4c8730 | ✅ confirmed |
| object starts **absent**: `FUN_00487450` (984 B, last call of `FUN_00486610`, after the vptr write) zeroes 0x2410/0x2414/0x2418/0x2420 | FUN_00487450 | 0x487450 / 0x4877fd | ✅ confirmed |
| attach/detach trio: slot 211 = `Attach(flag)` (set 0x2414, Release old, new+ctor, `vtable[2](0)`), slot 214 = `TryLoad(id)` (validates via `obj->vtable[15](id)` **before** swapping), slot 245 = `Detach()` | FUN_004890a0 / 00489570 / 00489150 | 0x4890a0 / 0x489570 / 0x489150 | ✅ confirmed (§1.17.4) |
| **`vtable[13]` = FUN_004c8eb0 (175 B, `RET 0x8`) is a TERMINAL, not a router**: clamps both args to `[-1,1]`, packs `key=(b+1)<<8|(a+1)`, appends `{int key; float t}` (**8-byte entry**) to the vector at `+0x28`, slow path `FUN_004ca1f0`, then `this[0x34]=begin` | FUN_004c8eb0 | 0x4c8eb0 | ✅ confirmed (§1.17.5) |
| queue **de-duplicates**: if `*(int*)(end-8) == key` the append is skipped entirely | FUN_004c8eb0 | 0x4c8f03 → 0x4c8f57 | ✅ confirmed |
| float stored per entry comes from `FUN_00549b00(this + 0x58)` | FUN_00549b00 | 0x549b00 | ✅ confirmed |
| **consumer side localised**: `FUN_004c94a0` (slot 15, 1062 B) walks the queue (`LEA EDI,[ESI+0x28]` @0x004c9748) and calls back into the GameApp singleton → `GameApp->vtable[133]`; `FUN_004cc130` (slot 19, 1174 B) second candidate | FUN_004c94a0 / 004cc130 | 0x4c94a0 / 0x4cc130 | 🟡 inferred (§1.17.6) |
| the 150-pointer run from `0x005aa660` also holds every Tier-1 anchor: slots 21/26 routers §1.16, 39=0x4cb260, 66=0x4d0540, 67=0x4d0ac0, 75=0x4cd200, 81=0x4ceb50, 84=0x4cf5b0, 147=0x4d1740 | — | 0x5aa660 run | 🟡 inferred, single-class membership unproven (§1.17.7) |
| counter-evidence to single class: `FUN_004ceb50` addresses `this+0x35c` (`self[0xd7]`, §1.9) which the confirmed 280 B object cannot contain | FUN_004ceb50 | 0x4ceb50 | 🟡 open (§1.17.7) |
| tooling: Ghidra `DecompInterface` **hangs indefinitely** on `FUN_004c8eb0` (killed at 38 min, no output growth); raw listing + `RET n` answered the same question in one pass | — | — | ✅ methodology (§1.17) |
| combo counters / resource spend — **search space now bounded to 2 functions** (`FUN_004c94a0`, `FUN_004cc130`); no match hardware read yet | — | — | ❓ unknown, narrowed |
| **7/7 Tier-1 slot anchors in the `0x005aa660` run independently re-verified byte-exact** (39/66/67/75/81/84/147); run graded as cross-class method family, not one vtable | — | 0x5aa660 run | ✅ confirmed (§1.17.7, re-audited) |
| **~~`GameApp vtable[133]` = intent→action verdict~~ REFUTED** — it is `FUN_0049a3b0` (23 B, `RET 0x8`), a constant getter returning `(9, 7)`, consumed as capacity guards at `0x004c9540`–`0x004c9560` | FUN_0049a3b0 | 0x49a3b0 | ❌ refuted (§1.18.1) |
| **~~slot 15 `FUN_004c94a0` is the combo consumer~~ RETRACTED** — it is a **three-stride queue loader**: magic `0x1e0d` check, `(9,7)` capacity guards, three bounded loops loading `this+0x18` (**12 B** entries) / `this+0x28` (**8 B**, the intent queue) / `this+0x38` (**16 B**) via helper `FUN_00507fb7` (18 calls), then one `CALL [EAX+0xc]` | FUN_004c94a0 | 0x4c94a0 | ❌ retracted (§1.18.2) |
| each of the three vectors has a dedicated slow-path append: `FUN_004c9b80`/`004c9eb0` (12 B), `FUN_004ca1f0` (8 B), `FUN_004ca4c0`/`004ca7f0` (16 B) | — | 0x4c9b80 / 0x4ca1f0 / 0x4ca4c0 | ✅ confirmed |
| **slot 19 `FUN_004cc130` (1174 B) is the surviving consumer**: bare `RET` ⇒ zero-arg per-frame tick; early-exits when `this+0x10` is null; reads `this+0x18`; calls GameApp singleton; fans out over ten consecutive interface slots `+0xcc`…`+0xf0` (not a switch) | FUN_004cc130 | 0x4cc130 | 🟡 inferred (§1.18.3) |
| **shared clock**: `FUN_00549b00` supplies the float written into every 8-byte queue entry (producer, §1.17.5) *and* is called twice inside slot 19 → those floats are timestamps, not weights | FUN_00549b00 | 0x549b00 | 🟡 inferred |
| **`0x12c` (300)** occurs 3x in slot 19 and once in the ctor (`MOV [EDI+0x30],0x12c`) — first concrete window/budget candidate; unproven | FUN_004cc130 / FUN_004c8730 | 0x4cc130 / 0x4c883f | 🟡 open |
| slot 19 touches `this+0x348` — beyond the confirmed 280 B object; third datum that this run spans multiple classes | FUN_004cc130 | 0x4cc14a | ✅ confirmed |
| combo counters / resource spend / move-list matching — **6th record**; unread surface now one function with two leads (`FUN_00549b00`, `0x12c`) | — | — | ❓ unknown, narrowed |
| **two project trees exist**: release source `D:\MeteorRE` (git, frozen, pushed) vs analysis workspace `D:\xinnixiang\nixiangyuama` (no git); R50 artefacts + `claim_audit.json` live only in tree B | — | — | ✅ confirmed (§1.19) |
| **why docs/10 mismatched — two causes**: different filename entirely (`10_REA_PROMPTS_TEMPLATE_VERIFICATION.md`, 3,953 lines vs `10_TEXT_COVERAGE_AUDIT.md`, 632) **and** tree B's file was still being written at read time; numbering 01-09 differs in content too (07: 2,614 B vs 13,915 B; 09: 3,391 B vs 78,715 B) | — | — | ✅ confirmed (§1.19) |
| **asset guard on tree B: ~7.9 MB of original game imagery** — `UITexture` 368 K (58 files incl. `FW01`-`FW12`, `ATarget`, `NET` .bmp/.jpg/.tga), `ETexture` 1.3 M, `ctexture` 6.2 M. No remote today => no leak; must pass the same zero-asset scan as tree A before any push | — | — | ⚠️ action required (§1.19) |
| **RETRACTED (own §1.18.3 bullet 2): the fan-out IS a switch** — every case `0x004cc42b`–`0x004cc549` ends in `JMP 0x004cc54f`; no jump table, cases reached by `TEST`/`CMP`/`JZ` chains | FUN_004cc130 | 0x4cc54f | ❌ retracted (§1.21.1) |
| **selector is a direction string, not a weapon index** — cases append one of four ASCII chars to the begin/end/capacity triple at `this+0x2e8`: `0x66='f'`, `0x62='b'`, `0x6c='l'`, `0x72='r'` (forward/back/left/right), terminated with `0x00` | FUN_004cc130 | 0x4cc245 / 0x4cc2a6 / 0x4cc2eb | ✅ confirmed (§1.21.2) |
| selector reads `this+0x60` (`0x4cc257`) and `this+0x64` (`0x4cc2f3`) | FUN_004cc130 | 0x4cc257 | ✅ confirmed |
| **loop closes with §1.12**: `this+0x60` is zeroed by both GetAsyncKeyState samplers — `FUN_004cb260` @`0x4cb283` and `FUN_00503020` @`0x503040` — and read by the tick @`0x4cc257` | three functions | — | ✅ confirmed (§1.21.3) |
| `0x005a8258 (PTR_GetAsyncKeyState)` has **exactly 2 referrers in the whole image**: `0x004cb362` (FUN_004cb260) and `0x005030ba` (FUN_00503020); `FUN_004cb260` re-fires the loaded pointer **8×** (`CALL EBP` `0x004cb369`…`0x004cb4f8`) | — | 0x5a8258 | ✅ confirmed |
| all ten cases share one signature: `MOV EDX,[ESI]` (same `this` throughout), two pushed args from `[ESP+0x18]/[ESP+0x1c]`, `MOV ECX,ESI`, call one slot | FUN_004cc130 | 0x4cc42b–0x4cc549 | ✅ confirmed |
| **slots `+0xCC`…`+0xF0` = vtable slots 51–60, ten consecutive**, one selected per branch ⇒ ten move handlers chosen by the accumulated direction string | — | 0x5aa660 run | 🟡 inferred (§1.21.4) |
| **asset figure corrected: 7.9 MB → 58.6 MB** (1,753 image files; jpg 30.6 + bmp 24.7 + tga 3.4); my original count walked only UITexture/ETexture/ctexture and missed sn01–sn22. Recorded in `MeteorRE` commit `5c3798c` | — | — | 🔄 corrected (§1.21.5) |
| **second-order gap still unreported**: `extracted_assets` also holds ~213 MB non-image original assets — `.pvb` 169.5 MB, `.gmb` 21.1, `.zip` 10.0, `.cob` 3.2, `.wav` 2.4, `.des` 0.9 | — | — | ⚠️ open (§1.21.5) |
| **attack = MOUSE1 (code 0x1000), edge on press only** — the release branch jumps straight to the function exit; two gates precede the request | FUN_004cb820 | 0x4cbbb0-0x4cbbdf | ✅ confirmed (§1.22.2) |
| **jump = MOUSE2 (code 0x1200)**, and it DOES handle release (`CALL [EDX+0x104]`) — asymmetric with attack | FUN_004cb820 | 0x4cbb73-0x4cbba1 | ✅ confirmed |
| **attack command number = 0x1d**, 4-byte payload = `[this+0x10] - 0x65c` (an entity handle, not a move id) | FUN_004cb820 / FUN_004ce3c0 | 0x4cbbdd / 0x4ce3c0 | ✅ confirmed |
| **`cmd 0x1d` → `vtable[31]` = FUN_004cf4c0**, which lazily allocates a 0x48-byte **30 fps frame clock** (double 30.0 at +0x8, double 0.2 at +0x18) and arms a deadline via FUN_00549a90 | FUN_004cf4c0 / FUN_005498c0 | 0x4cf4c0 / 0x5498c0 | ✅ confirmed (§1.22.3) |
| **`"Active Attack"` @0x005c9c34** — the only string on the MOUSE1 path, pushed into GameApp slot 172 | FUN_004cb820 | 0x4cbbfb | ✅ confirmed |
| attack gates: slot 111 `FUN_004d0d90` = `[+0x10] && [+0x34c]`; slot 109 `FUN_004ce2d0` = `[+0x348]->vtable[21]()` | — | 0x4d0d90 / 0x4ce2d0 | ✅ confirmed |
| **four input channels, not four actions**: 0x31 {key,pressed} → GameApp 220 → B.method10 → 12 B @`+0x18`; 0x32 stick A → 221 → method11 → 12 B @`+0x48`; 0x34 stick B → 222 → method12 → 16 B @`+0x38`; 0x33 axes → 223 → method13 → 8 B @`+0x28` | FUN_004cb820 / FUN_004cb5f0 / FUN_004cb260 | 0x4cb839 / 0x4cb696 / 0x4cb53b | ✅ confirmed (§1.22.6) |
| **RETRACTED: the input object vtable is `0x5AA6A8`, not `0x5AA660`** — re-indexed slots 18-34 given; `0x5AA660+39*4 == 0x5AA6A8+21*4 == 0x5AA6FC`, so "slot 39" and "slot 21" are one dword and the run never spanned classes | — | 0x5aa6a8 | 🔄 corrected (§1.22.4) |
| **the direction buffer has two writers**: the tick (axis-derived, §1.21) and the key router `FUN_004cbce0` (appends f/b/l/r on key edges; grow path `0x49be40`) | FUN_004cbce0 | 0x4cbce0 | ✅ confirmed (§1.22.5) |
| ~~combo counters / resource spend~~ — **the 7th-record claim was built on §1.23, now VOID**; 282/375 are jump speeds and 0.11 is a ratio, so this is **OPEN again**, not resolved | — | 0x005AA93C / 0x005AA940 | ❓ open (reverted 2026-10-28) |
| **ERRATUM: `CALL [EDX+0x1b4]` is at 0x4CBBC6**, not 0x4CBBC2 — the two setup instructions `MOV EDX,[ESI]` / `MOV ECX,ESI` sit between the gates; raw bytes `75 22 8b 16 8b ce ff 92` settle it | FUN_004cb820 | 0x4cbbc6 | 🔄 corrected (§1.22.2) |
| **`FUN_004cbce0` has 0 direct `E8` callers**; reached only as slot 24 (`CALL [reg+0x60]`). Char arrives as the stack argument; callee reads `MOV EBX,[ESP+0x18]` and stores `MOV byte ptr [ECX],BL` @0x4CBD41 | FUN_004cbce0 | 0x4cbce0 | ✅ confirmed (§1.22.5) |
| raw `6A` census of `FUN_004cb820`: **28** `PUSH imm8`, of which exactly four are the direction chars at 0x4CB87C('r') / 0x4CB896('l') / 0x4CBA37('b') / 0x4CBB07('f') | FUN_004cb820 | — | ✅ confirmed |
| **input object vfptr store `MOV dword ptr [EBP],0x5AA6A8`** at 0x4CADC2 (destructor) — literal proof of the vtable base, stronger than the slot-3 argument | FUN_004cada0 | 0x4cadc2 | ✅ confirmed (§1.23.1) |
| **attack window = 0.11 s** — double `0x005AA8E8` = 0.11 (`3fbc28f5c28f5c29`), compared against `clock->elapsed()`; frame rate double `0x005A9D50` = 30.0 | FUN_004cd3b0 | 0x4cd3cd | ✅ confirmed (§1.23.2) |
| **the only gameplay reader of `[A+0xE8]`** is `FUN_004CD3B0` = **slot 58 (+0xE8)**, sole reference is the vtable dword at `0x5AA790`; other accesses are destructor free (0x4CADC9) and state reset (0x4CAFFF) | FUN_004cd3b0 | 0x4cd3be | ✅ confirmed (§1.23.1) |
| **closer `FUN_004CF540` (slot 65)** re-tests the same 0.11 and passes `0`/`1` to slot 66, then `operator_delete`s the clock and nulls `[A+0xE8]` — single-use window | FUN_004cf540 | 0x4cf564-0x4cf598 | ✅ confirmed (§1.23.3) |
| **slot 66 = `FUN_004CF5B0`, a 3-state dispatcher**: index table `0 1 2 3 3 3 3 3 3 3 3 1` @0x4CF75C over state `[A+0xDC]`, jump table @0x4CF74C | FUN_004cf5b0 | 0x4cf5be | ✅ confirmed (§1.23.4) |
| **chain scalars 282.0 / 375.0** (`0x005AA93C` / `0x005AA940`) — slot 66 writes `[A+0x398]` or scales a vector by them depending on the expired boolean | FUN_004cf5b0 | 0x4cf61e / 0x4cf6e0 | ✅ confirmed |
| ~~**no combo counter exists on the whole path**~~ — **RETRACTED**: the path described is the jump hold-length selector (docs/02 §二), not a combo chain. `0.11` = Δticks/`[+0x38]` ratio, 282/375 = jump speeds | FUN_00549b00 | 0x549b38 | ❌ retracted (§1.23 VOID) |
| trap: `+0xE8` is **both** a member (clock pointer) and virtual slot 58, so `MOV [ESI+0xE8]` and `CALL [EAX+0xE8]` coexist; the text scan reported 78 'readers' of which 74 were virtual calls | — | — | ⚠️ methodology (§1.23.6) |
| **units already anchored**: 282.0 / 375.0 share the `.rdata` block with the §1.15 impulse constants (600.0 @0x005AA934, 0.13 @0x005AA944) and slot 66's jump dispatch reads that block ⇒ `0.048283 m/unit` applies, **no new constant** | FUN_004cf5b0 | 0x5aa93c / 0x5aa940 | ✅ confirmed (§1.24.1) |
| `FUN_004CF540` has **two** pre-gates: missing clock → `-1`, and slot 96 (`+0x180`) non-zero → `-1`; only then the 0.11 re-test and the 0/1 hand-off | FUN_004cf540 | 0x4cf543-0x4cf57d | ✅ confirmed (§1.24.3) |
| slot 66 is reached **only by virtual call** — a direct-E8 search returns 0 and looks like a contradiction | FUN_004cf540 | 0x4cf575 / 0x4cf583 | ✅ confirmed |
| **`[A+0xdc]` has a dedicated 13-byte setter**: `FUN_004D0500` = A.slot **75 (+0x12c)**; also slot 93 (+0x174) on base 0x5AA660; **zero direct E8 callers** | FUN_004d0500 | 0x4d0500 | ✅ confirmed (§1.24.4) |
| `[A+0xdc]` is zeroed by the state reset at `0x4CB0A7 MOV [ESI+0xdc],EDI` (same function that clears `+0xE8`) | FUN_004cafb0 | 0x4cb0a7 | ✅ confirmed |
| **`0x4BB81F` serves `cmd 0x0F`, not cmd 0x03** — index 12 of the 51-entry table at `0x4bbfe8`; cmd 0x03/0x04/0x09 share the no-op exit `0x4bbfd0`, and cmd 0x0E/0x12/0x23–0x27 share `0x4bbfdb` | FUN_004bb800 | 0x4bc018 | 🔄 corrected (§1.24.7) |
| the zero-argument `SetState` anomaly therefore belongs to **cmd 0x0F**, and remains open | — | 0x4bb830 | ❓ open |
| `cmd_dispatch_map`'s `cmd 0x0F → vtable[19] (+0x4c)` is confirmed by `CALL [EAX+0x4c]` @`0x4bb843` — the map was right, only the prose attribution was wrong | — | 0x4bb843 | ✅ confirmed |
| `+0x12c` census, exact: **66** call-form sites image-wide (12 in `0x48xxxx`, 10 in `0x49xxxx`, 24 in `0x4Cxxxx`), **271** any-form — unusable as an identifier (fourth instance of the §1.23.6 trap). Earlier "16" was a truncated-listing artifact | — | — | 🔄 corrected (§1.24.6) |
| **cmd 0x3's semantic exit**: after the setter it latches `[A+0x34C]` via A.slot19 `FUN_004CE230` and **reports that value to GameApp slot 93 (`+0x174`)** — the command's actual output, independent of the arity puzzle | FUN_004bb800 | 0x4bb843-0x4bb849 | ✅ confirmed (§1.24.6) |
| the 17 bytes between `0x4BB81F` and `0x4BB830` decode to gate + `jne` + two `thiscall` setups — **no hidden PUSH**; the arity mismatch is real and the open status is correct | FUN_004bb800 | 0x4bb81f-0x4bb830 | ✅ confirmed |
| **chain verdict stands independently of the open link** — the selector is *read* in exactly one place (§1.23.4, byte-exact); only the transition rule is unproven | — | — | ✅ confirmed |
| **`cmd 0x1d` lands at `0x005a9fe0 + 0x7c` = `0x004bc710` (402 B)** — the third base, corroborated by `cmd 0x33` → `FUN_004bc100` at `+0x1e8`; the two earlier readings (`0x4a96c0` on 0x5AA658, `0x4cf4c0` on 0x5AA6A8) are ruled out | — | 0x5aa05c | ✅ confirmed (§1.24 VOID banner) |
| **`FUN_004bc710` = settings-gated dispatcher**: lazy `[0x5E0328]` (0x33C, ctor 0x44D020) → snapshot via `FUN_0045A450` (copy from cfg+0x94) → gate on snapshot field `cfg+0xC8` → `FUN_004f1960(this)` | FUN_004bc710 | 0x4bc71e-0x4bc803 | ✅ confirmed |
| `FUN_004f1960` (15 B) = forwarder: `this->vtable[17] (+0x44)` → returned sub-object → tail `JMP [sub+0x1b4]` (slot 109) | FUN_004f1960 | 0x4f1960 | ✅ confirmed |
| **REVISED (own §1.17 claim): `0x1000`/`0x1200` DO have a runtime consumer** — through the settings snapshot at `[0x5E0328]+0xC8`, not through key polling | — | — | 🔄 corrected |
| `0x5AA658+0x104 = FUN_004ce100` (37 B, "exhaustion slide"), **not** `FUN_004cf540`; the latter is canonical slot **85 (+0x154 = 0x5AA7AC)**, the same dword as `0x5AA6A8+0x104` | — | 0x5aa75c / 0x5aa7ac | 🔄 corrected |
| **third hop: `FUN_004F1960` -> `this->vtable[17]` = `FUN_004f1d90`** get-or-create factory, `PUSH 0x528` + `CALL 0x004cabd0` (the ctor the repo already anchored) cached at `[this+0x1a4]` | FUN_004f1d90 | 0x4f1d90 | ✅ confirmed |
| **terminal: `pc->vtable[109]` = `FUN_004ce2d0`** = `[pc+0x348] ? [pc+0x348]->vtable[21] : 0` | FUN_004ce2d0 | 0x4ce2d0 | ✅ confirmed |
| ⚠️ **identity collision**: the press gate `0x4CBBC6` and the command terminal `0x4CE2DC` are the same function — either a deliberate re-check on a later tick, or slot 17 returns a different class than assumed. Not resolved | — | 0x4ce2dc | ❓ open |
| `+0x348` is a pointer on PlayerController (`0x4CFD54` install / `0x4CB0B9` clear) but a boolean on another class (`0x4E8437`=0, `0x4E8443`=1) — offset-only scans mix them | — | — | ⚠️ methodology |
| **12 weapon controllers are Meyers singletons** behind a 79-byte factory `FUN_004e3d80` (12-way jump table); each getter is 51 B (guard flag → 73 B ctor → `atexit(0x5089bc)` → return static instance) | FUN_004e3d80 | 0x4e3d80 | ✅ confirmed |
| **`weapon->vtable[21] (+0x54)` is a constant**: `0x004f5860` = `B8 01 00 00 00 C3` (return 1) for types 0,1,4,5,7,8,9,10,11; `0x004e40d0` = `33 C0 C3` (return 0) for types 2,3,6 | — | 0x4f5860 / 0x4e40d0 | ✅ confirmed |
| **NEGATIVE: the `cmd 0x1d` chain ends in a hardcoded true** — there is no weapon-gate-to-move-selection step. The command's net effect for the sword is `return 1`; it behaves as a permission probe, not an action | — | 0x4ce2dc | ✅ confirmed (§1.24 fourth hop) |
| remaining weight on the attack path: `slot 40 = FUN_004cff40` (674 B), the `"Active Attack"` reporter — classified as logging on string evidence alone, needs re-testing | FUN_004cff40 | 0x4cff40 | ❓ open |
| sword's `slot 22 (+0x58)` = `0x004e4070`, `C2 04 00` = bare `RET 0x4` — a no-op with one argument | — | 0x4e4070 | ✅ confirmed |
| **`FUN_004cff40` (674 B) is an executor, not a reporter** — 211 insns, **0 jump tables**, filters `this->vtable[76]` to {0,1,3,6}, queries `weapon->vtable[8]`, builds 3-4 stack temporaries, emits **cmd 0x30 + cmd 0x35**, writes `[this+0x524]` | FUN_004cff40 | 0x4cff40 | ✅ confirmed (§1.24 fifth hop) |
| **CORRECTION: `"Active Attack"` lives in the CALLER** (`0x4cbbfb`, inside `FUN_004cb820`), not in `FUN_004cff40`; the 674-B function has exactly one data ref in `0x5C0000-0x5EFFFF` (`0x005d59e8`, allocator lock) | — | 0x4cbbfb | ❌ retracted (the "logging path" label) |
| `cmd 0x30` → slot 16 (`+0x40`) `FUN_004cfca0` (56 B): zeroes `+0x390/+0x394/+0x398` then `device->vtable[32] (+0x80)` with 4 args, `RET 0xC` — a movement-state reset, since `+0x398` is `jumpForceY` | FUN_004cfca0 | 0x4cfca0 | ✅ confirmed |
| `cmd 0x35` → slot 18 (`+0x48`) `FUN_004d03f0` (166 B) — **unread**, the new tail of the attack path | FUN_004d03f0 | 0x4d03f0 | ❓ open |
| the `"Active Attack"` notice is gated on slot 40's **return value** (`TEST EAX,EAX / JZ`), so it reports that the executor ran, not that a key was pressed | FUN_004cb820 | 0x4cbbe4-0x4cbc02 | ✅ confirmed |
| **`FUN_004d03f0` (166 B, `RET 0x10`) is the real terminal**: filter state {7,9} -> return 0; else `slot 29 (+0x74)` with 4 args, `SetState(4)`, store `+0x380/+0x37c`, arm a **third** timer at `+0x210`, copy `+0x390..+0x398` to `+0x3B8..+0x3C0`, clear `+0x524`, emit `cmd 0x35`, return 1 | FUN_004d03f0 | 0x4d03f0 | ✅ confirmed (§1.24 sixth hop) |
| **old open item closed for one edge**: `SetState(4)` writes `[pc+0xDC] = 4`, and the jump dispatcher's index maps 4 -> case 3 = `OR EAX,-1; RET`; **state 4 disables jump dispatch** — attack and jump are mutually exclusive through one stored state | FUN_004d0500 / FUN_004cf5b0 | 0x4d0427 / 0x4cf5be | ✅ confirmed |
| erratum: exact `PUSH` addresses are **0x4d0051** (cmd 0x30) and **0x4d00c3** (cmd 0x35); the earlier 0x4d004f / 0x4d00c1 were block-head compressions (off by 2) | FUN_004cff40 | 0x4d0051 / 0x4d00c3 | 🔄 corrected |
| erratum: `FUN_004cff40` has **3 data refs over 2 addresses** (`0x005d59e8` ×2, `0x005d59a4` ×1), not 1 — all CRT allocator; the no-string conclusion stands | — | — | 🔄 corrected |
| last unread link on the attack path: `slot 29 (+0x74)`, the only call taking a caller-supplied action payload | — | 0x4d0422 | ❓ open |
| **`slot 29 (+0x74)` = `FUN_004cfb00` (210 B, `RET 0x10`)**: guards on entity id and a `slot 77 == arg1` dedup, calls `slot 104`, `slot 22` (4 args, produces the aim float), `weapon slot 27`, then quantises and emits **`cmd 0x04` with 8 bytes** | FUN_004cfb00 | 0x4cfb00 | ✅ confirmed (§1.24 seventh hop) |
| quantisation constants, byte-exact: **200.0** (`0x5a8f7c`), **0.5** double (`0x5a8460`), **2.0** (`0x5a8b80`), **100.0** (`0x5a84c8`), **0.5** (`0x5a83e8`); payload = `{(arg2<<8)|arg1, (i1<<8)|i2}` | FUN_004cfb00 | 0x4cfb75-0x4cfbc6 | ✅ confirmed |
| **the payload is a direction/orientation sample, not a move id** — two 8-bit fields per dword; whether the pair is yaw/pitch or a cell coordinate is not settled | — | — | 🟡 inferred |
| **no move selection exists anywhere on the MOUSE1 chain** (7 hops): permission, posture reset, state lock, third timer, impulse save, aim report — and nothing that names an action | — | — | ✅ confirmed (§1.24 seventh hop) |
| `cmd 0x04` has no handler: the 44-entry map lists it as pure inline (2 lines) in the dispatcher | FUN_004bb800 | 0x4bbfe8 table | ✅ confirmed |
| `FUN_004cc130` fan-out = **11 calls / 10 distinct slots** (`+0xcc..+0xf0`), `+0xe8` twice (`0x4cc3f3`, `0x4cc439`) | FUN_004cc130 | 0x4cc3f3-0x4cc549 | ✅ confirmed (§1.24.8) |
| slots 51–60 on **PlayerController `0x5aa6a8` = 10/10 distinct**; on the sword weapon base they are 9/10 — the weapon table is a decoy, disambiguated only by slot 58 being the 2,386-B clock reader | — | 0x5aa6a8 | ✅ confirmed |
| **prediction falsified**: the ten slots do **not** collapse to 2–3 implementations (unlike `weapon->vtable[21]`); dispatch is identity-by-selector via the §1.21 direction-string switch | — | — | ❌ refuted (§1.24.8) |
| **the ten handlers are movement handlers** — all in `0x4cd`–`0x4ce`, slot 57 = wall-stick `FUN_004cd200`; the drain path selects movement states, not attacks | FUN_004cd200 | 0x4cd200 | ✅ confirmed |
| **attack move selection is not on the drain path** — no move-table matching loop exists there; after 8 hops + drain, selection remains unlocated, pointing at the data tables themselves | — | — | ❓ open |
| **selector found: `InputItem.keyInput` sequence match -> `Lines`/`LinesAir` -> `IsWeaponKey`** — `ActionInterrupt`/`InputModule`/`InputItem` read from `_sources/MeteorPort/src/Assembly-CSharp/` | ActionInterrupt.cs / InputModule.cs | — | ✅ confirmed (§1.25.2) |
| **27 C# `int[] scan` literals == `Input.txt` 19 chains (`Lines`+`LinesAir`), 27/27 element-exact, zero drift** | GetSlashNode vs Input.txt | — | ✅ confirmed (§1.25.3) |
| **`Idx 1 (J)` has no literal in the matcher** — matches `Input.txt` row-2 note "基础动作由基本按键识别系统识别"; two independent sources | — | — | ✅ confirmed |
| **`Combo.cs` (1,272 B) is an NGUI hit-count floater** (`UILabel` + `TweenScale` + `TweenAlpha`), no gameplay read — the nine-round counter question closes as *cosmetic* | Combo.cs | — | ✅ confirmed (§1.25.4) |
| ground/air are **disjoint** vector sets (19 ground / 8 air), not one set with a flag | GetSlashNode | — | ✅ confirmed |
| `CacheGround`/`CacheAir` memo is keyed on the **source action**, so weapon type is baked in at first computation — stale after a mid-action weapon swap | ActionInterrupt.cs | — | 🟡 inferred (§1.25.5) |
| `Meteor.exe` reads the same 20-row table but **has no `Input.txt` string** — its loader uses a different filename or an embedded copy | — | — | ❓ unknown (§1.25.7) |
| **`MeteorPort` is a third-party Unity rewrite, not the original** — usable as a readable spec, not as authority | MeteorPort/REPORT.md | — | ✅ confirmed (§1.25.1) |
| **`KeyMap` = 1-based ordinal of each `group(...)` line in `characteract.txt`** (`Init()`: `actionNode.KeyMap = num3; num3++`), **160 groups measured, and the largest value in the 27 `scan` literals is exactly 160** | ActionInterrupt.cs / characteract.txt | — | ✅ confirmed (§1.25.8) |
| **`Scan()` compares `KeyMap`, not `ActionIdx`** — so the `Input.txt` `Lines`/`LinesAir` columns are KeyMap sets, never action ids | ActionInterrupt.cs | — | 🔄 corrected (§1.25.8) |
| `Lines[KeyMap]` is the bridge from group ordinal to concrete `ActionIdx` members; `226(227,235)` builds the `target` graph separately | ActionInterrupt.cs | — | ✅ confirmed |
| **Unity rewrite tuned its own physics**: `Jump2Velocity 160` vs `282.0`, `JumpVelocityForward 180` vs `375.0`, `groundFriction 2000` vs `600.0`, `JumpLimit 68` vs `0.13` — four rows, four divergences | MeteorUnit.cs | — | ✅ confirmed (§1.25.9) |
| **settleable from the Unity source: 5 of 8 open items** (input table, KeyMap, target graph, weapon-filter shape, `J` bypass); **not settleable: 3** (`+0xDC` machine, `0.11` ratio, `cmd 0x0F`) | — | — | ✅ confirmed (§1.25.9) |
| **`[+0xDC]` machine measured from an existing log** (3,374 ticks, no new experiment): 0=airborne, 1=grounded, 2=climbing, 3=attack wind-up, 4=air attack | original_meteor_latest.log | — | ✅ confirmed (§1.25.10) |
| transitions: 0<->1 (133/136), 0<->2 (70/70), 1->3 (8), 3->1 (9), 0->3 (3), **3->4 (2), 4->1 (2)** | — | — | ✅ confirmed |
| **every one of the 12 `state 4` ticks is `act=90 Pose90`, `grounded=False`, entered on an LMB frame** — state 4 is air-attack-only and pose-monogamous | — | — | ✅ confirmed |
| `state 4` IS the jump-suppression flag (vs merely correlated) — not exercised: no tick presses jump during state 4 | — | — | 🟡 inferred |
| `MoveState` field is already logged by `MeteorOriginalMonitor.cs:396` (`moveState={22}(sub={23})`) — **the open item closed by reading disk, not by instrumenting** | — | — | ✅ confirmed |
| **workspace map corrected**: `_sources` is the Android/APK tear-down root; the three live Unity projects are `D:\MeteorWin\UnityProject\ExportedProject`, `D:\MeteorUnity\meteor_551_u2020`, `D:\MeteorProjects\MeteorRebuild` | — | — | 🔄 corrected (§1.26.1) |
| **three different `ActionInterrupt.cs` copies**: APK-decompiled 16,411 B / `_gt/master` 28,308 B / `meteor_551_u2020` **37,914 B** — §1.25 used the thinnest | — | — | ✅ confirmed (§1.26.1) |
| **original move data already parsed: 574 poses** — `POS招式帧数据.json` 5.17 MB with per-pose `start`/`end`/`loop_*`/`effect_id`/`sub[Blend|Action]` | Meteor_Extracted/ | — | ✅ confirmed (§1.26.2) |
| **CORRECTION — the anger spend is real**: `MeteorInput.CheckPos(KeyMap, targetAct)` is a weapon-type × KeyMap table that subtracts 100/60/50/10 from `AngryValue` | MeteorInput.cs | — | 🔄 corrected (§1.26.3) |
| **`EnableInfiniteAngry` is read at the spend site**, not at load — the cheat path skips one branch in the same code | MeteorInput.cs | — | ✅ confirmed |
| full table extracted: 12 weapon types, 4–12 KeyMaps each, 1–3 paid entries (type 11 uses 50/50/50/10) | MeteorInput.cs | — | ✅ confirmed (§1.26.3) |
| **exe-side anger verification attempted and failed to confirm**: `CMP [reg+off],0x64\|0x3c` yields exactly 2 sites at 2 different offsets, never both values at one field | — | — | ❓ open (§1.26.4) |
| so the 100/60 numbers must not be assumed correct for the original — structure corroborated, values unproven | — | — | 🟡 inferred |
| **source vs decompile, same version (2.8)**: `_gt/v280/.../ActionInterrupt.cs` 36,988 B / 939 L vs `MeteorPort` 16,411 B / 733 L — decompile is 44% smaller but **structurally identical** | — | — | ✅ confirmed (§1.27.1) |
| **source names the 27 vectors**: `slash0Ground`…`slash18Ground` + 8 air, with Chinese labels; `slash1/2/10/11` have **no air array by construction** ("左攻击无空中招式") | — | — | ✅ confirmed |
| **`EquipWeaponType` enum resolves §1.24.x's unnamed types 2/3/6 = Gun(火枪) / Dart(飞镖) / Guillotines(血滴子)** — the three ranged weapons, hence `vtable[21] = 0` | Common.cs | — | ✅ confirmed (§1.27.2) |
| `CheckPos` switches on `case (int)EquipWeaponType.Knife:` in source, bare ints in decompile — same signature, same table | — | — | ✅ confirmed |
| **CORRECTION: Gun KeyMap 7 costs 20** (not free as §1.26.3 said) — the only 20-cost row; **Knife 84 is free and shares a label with 33** | MeteorController.cs | — | 🔄 corrected (§1.27.3) |
| **"double-W" is ≥2 W within the last 3 key events, not an adjacent `W,W`** (`case 27 // 前3个按键里面只有找到至少2个按下W按键`) | MeteorController.cs | — | ✅ confirmed (§1.27.4) |
| plain attack reads the input buffer's contents/state, not just the button edge (`case 25` comment) | MeteorController.cs | — | ✅ confirmed |
| ground/air is enforced a **second time** at the transition, not only by the two array sets (`case 84` comment) | MeteorController.cs | — | ✅ confirmed |
| HeavenLance carries a 17-line KeyMap→action map (89:左A拔刀切换持枪430 … 106:空中下A 446) — closest thing to a documented transition table in the project | MeteorController.cs | — | ✅ confirmed |
| anger costs are source-confirmed for the **rewrite**; still **no exe-side evidence** | — | — | ❓ open (unchanged) |
| **`Meteor_Extracted/app/Meteor.exe` is byte-identical to the analysed binary** — 1,945,600 B, md5 `cf2aa5c21a0a687afacc5e5c0876c543`, so every file in that tree is data of the exact build | — | — | ✅ confirmed (§1.28.1) |
| build identified as **9.07.16** (`★交付总览.md`): unpacked from `Meteor_9.07_Setup.exe` + `MeteorV0.2.8.0.apk` | — | — | ✅ confirmed |
| **three different `.pos` sources**: `Meteor_Extracted` 296,888 B / iOS-tree 9.07 278,385 B / 1.07 274,178 B — 0 of 21 files identical between 9.07 and 1.07 | — | — | ✅ confirmed (§1.28.2) |
| **`KeyMap` space is version-invariant: 160 groups in all four sources** (9.07 bytes, 1.07 bytes, both `.txt`) | — | — | ✅ confirmed (§1.28.3) |
| **action ids are NOT version-invariant** — group bodies differ 45% by byte size, so `KeyMap` is portable but its expansion is not | — | — | ✅ confirmed |
| `POS招式帧数据.json` (574 poses) / `动作衔接表.json` (160 group + 189 transitions) / `★最终招式总表.json` (240 moves) are all **Windows 9.07.16** | — | — | ✅ confirmed (§1.28.4) |
| `Input.txt` origin unproven — ships with the Android project, no Windows-side original located | — | — | ❓ open (§1.28.5) |
| **actionable risk: pointing `MeteorRebuild` at the iOS tree's `9.07/*.pos.bytes` yields a different pose set than the 574-pose dataset all combat tables were built from** | — | — | ⚠️ (§1.28.5) |
| **T1 pass: 159 KeyMaps referenced by `Input.txt`, 0 missing from the 160 groups of 9.07.16 `character.act`** | character.act | — | ✅ confirmed (§1.29.2) |
| **T2 pass: all 227 group members exist as poses** (ids 200..572), 0 missing from `P0POS_完整574.json` | — | — | ✅ confirmed |
| **T3 pass: 20 chains expand to 226 distinct actions, 0 missing**; the other 348 poses are the basic/hit pool | — | — | ✅ confirmed |
| **T4 — the load-bearing check: `pose 90 start=1694` == runtime `act=90 f=1694`** — pose-table frames and the runtime `AnimFrame` counter share unit and origin, in three independent sources | P0POS_完整574.json / original_meteor_latest.log | — | ✅ confirmed (§1.29.3) |
| **`pose 90` is in no group and unreachable from all 20 chains** — it is a basic action, matching `Input.txt`'s "基础动作由基本按键识别系统识别" | — | — | ✅ confirmed |
| T5: `group_count` 160 = 160 | — | — | ✅ confirmed |
| **T6 open: `transition_count` 189 (JSON) vs 217 (lines with ≥2 ints) vs 1,673 (edges)** — likely 28 `section` header lines counted as statements; the graph used by T2/T3 comes from `group` lines only and matches exactly | — | — | ❓ open, immaterial (§1.29.4) |
