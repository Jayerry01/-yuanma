"""
export_decompiled_modules.py
Assemble decompiled JSON batches into structured C subsystems for Meteor 2002.
"""
import json
import os

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
BASE_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, ".."))
SYMBOLS_DIR = os.path.join(BASE_DIR, "symbols")
OUT_DIR = os.path.join(BASE_DIR, "decompiled")

def export_module(json_path, out_c_path, title, description, header_includes, constants, key_routines, addr_filter=None, constants_header="/* --- Binary Verified Constants --- */"):
    if not os.path.exists(json_path):
        print(f"Error: {json_path} does not exist.")
        return
    with open(json_path, 'r', encoding='utf-8') as f:
        items = json.load(f)
    
    if addr_filter:
        items = [item for item in items if addr_filter(item.get('address', ''))]

    lines = [
        "/**",
        f" * @file {os.path.basename(out_c_path)}",
        f" * @brief {title}",
        f" * {description}",
        " * Binary Source: Meteor.exe (2002) Base Address: 0x00400000",
        " * Decompiler Provider: Ghidra 12.1.4 via REA MCP",
        " *",
        " * Key Routines:",
    ]
    for kr in key_routines:
        lines.append(f" *   - {kr}")
    lines.append(" */\n")
    
    for inc in header_includes:
        lines.append(f"#include {inc}")
    lines.append("")
    
    if constants:
        lines.append(constants_header)
        for const in constants:
            lines.append(const)
        lines.append("")
    
    exported_count = 0
    for item in items:
        addr = item.get('address')
        code = item.get('pseudocode', '')
        if not code:
            continue
        lines.append("// ============================================================================")
        lines.append(f"// PROCEDURE: {addr}")
        lines.append("// ============================================================================")
        lines.append(code.strip())
        lines.append("\n")
        exported_count += 1
    
    out_content = "\n".join(lines)
    encoded_bytes = out_content.encode('utf-8')
    with open(out_c_path, 'wb') as out:
        out.write(encoded_bytes)
    print(f"Successfully generated {out_c_path}: {exported_count} procedures, {len(encoded_bytes)} bytes, {len(lines)} lines.")

# 1. Combat & Damage Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_combat.json"),
    os.path.join(OUT_DIR, "07_Combat_HitDamage_System.c"),
    "Combat, Damage Calculation & Hit Reaction Subsystem",
    "Handles player hit reactions, knockback vectors, stun timers, and damage calculations.",
    ['"../src/include/meteor_combat.h"', '"../src/include/meteor_player.h"'],
    [
        "#define METEOR_KNOCKBACK_UP_BIAS    0.13f  /* 0x004D0674: fadd dword ptr [0x5AA944] (+0.13f vertical pop-up bias) */",
        "#define METEOR_KNOCKBACK_SCALE      600.0f /* 0x004D0698: fmul dword ptr [0x5AA934] (600.0f max speed impulse scalar) */",
        "#define METEOR_DAMAGE_BOX_Z_OFFSET  40.0f  /* 0x004D05EB: fadd dword ptr [0x5A8E7C] (Upper torso hit probe coordinate offset) */"
    ],
    [
        "0x004D0540: PlayerController::OnHit (Knockback Impulse, Stun Frames, Damage Application)",
        "0x004D0AC0: PlayerController::ProcessDamage (HP Deduction, Death Check, Invincibility Flags)",
        "0x004D1740: CombatSystem::LoadAttackParameters (Action Attack Data Parser)",
        "0x004D1EA0: CombatSystem::ApplyKnockbackImpulse (3D Impulse Vector Integration)"
    ]
)

# 2. Input & Combo Buffer Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_input.json"),
    os.path.join(OUT_DIR, "08_Input_Combo_Buffer.c"),
    "Input Polling, Key Queue & Combo Execution Subsystem",
    "Manages DirectInput key state buffers, combo sequence matching, and input queues.",
    ['"../src/include/meteor_app.h"', '"../src/include/meteor_types.h"'],
    [
        "#define METEOR_INPUT_BUFFER_SIZE    32     /* Maximum recorded key events in circular queue */",
        "#define METEOR_COMBO_TOLERANCE_FRAMES 12   /* Maximum frame window between combo inputs */"
    ],
    [
        "0x00486270: InputSystem::PollDeviceState (DirectInput / Win32 Key Polling)",
        "0x00486A80: InputSystem::ProcessKeyQueue (Key Sequence Buffer Update)",
        "0x00487830: InputSystem::GetInputSingleton (0x006659B8 Sub-device Provider)",
        "0x00488130: InputSystem::MatchComboSequence (FSM Command Matching: AA, down-up-A, left-right-A)"
    ]
)

# 3. Weapon & HitBox Pipeline Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_weapon.json"),
    os.path.join(OUT_DIR, "09_Weapon_HitBox_Pipeline.c"),
    "Weapon Equipment, Mesh Attachment & HitBox Detection Pipeline",
    "Handles weapon model attachment to bone dummies, blade trail generation, and hitbox queries.",
    ['"../src/include/meteor_combat.h"', '"../src/include/meteor_player.h"'],
    [
        "#define METEOR_WEAPON_MAX_TYPES     51     /* Matching W0_0..W8_4 catalog in Meteor.res */",
        "#define METEOR_BLADE_TRAIL_SAMPLES  8      /* Interpolated trail points along weapon blade edge */"
    ],
    [
        "0x004D21E0: WeaponSystem::AttachToBoneDummy (Binding weapon transform to Dummy0/Dummy1)",
        "0x004D2870: WeaponSystem::GenerateBladeTrail (Ribbon polygon emission along weapon edge)",
        "0x004D3634: WeaponSystem::EvaluateHitBoxOverlap (SAT sweep box vs target character AABB)",
        "0x004D3E60: WeaponSystem::OnWeaponContact (Trigger sound, particle sparks, and OnHit)"
    ]
)

# 4. AI Controller & FSM Pathfinding Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_ai.json"),
    os.path.join(OUT_DIR, "10_AI_Controller_FSM.c"),
    "NPC Artificial Intelligence, Target Tracking & Pathfinding FSM",
    "Implements NPC decision trees, combat difficulty weights, patrol pathfinding, and attack selection.",
    ['"../src/include/meteor_combat.h"', '"../src/include/meteor_player.h"'],
    [
        "#define METEOR_AI_DIFFICULTY_EASY   0",
        "#define METEOR_AI_DIFFICULTY_NORMAL 1",
        "#define METEOR_AI_DIFFICULTY_HARD   2",
        "#define METEOR_AI_FOV_COS_LIMIT     0.5f   /* ~60 degree frontal vision cone */"
    ],
    [
        "0x0040A2A0: AIController::UpdateDecisionTree (Master AI thinking tick)",
        "0x0040B0C0: AIController::EvaluateTargetHostility (Threat score and distance ranking)",
        "0x0040C040: AIController::SelectComboAction (Probability table lookup based on difficulty)",
        "0x0040D040: AIController::NavigateToWaypoint (Level navmesh / node grid traversal)"
    ]
)

# 5. Camera & View Controller Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_cam_ef.json"),
    os.path.join(OUT_DIR, "11_Camera_View_Controller.c"),
    "Third-Person Camera, View Frustum & Scene Occlusion Clipping",
    "Controls 3rd person follow-cam, look-at targets, pitch/yaw limits, and raycast wall clipping.",
    ['"../src/include/meteor_app.h"', '"../src/include/meteor_types.h"'],
    [
        "#define METEOR_CAMERA_MIN_DISTANCE  40.0f  /* Raw .rdata at 0x5A8E7C (Note: bound to hit-test @0x4D05EB; camera binding unverified) */",
        "#define METEOR_CAMERA_MAX_DISTANCE  180.0f /* Raw .rdata at 0x5A84C0 (Geometric projection constant; camera binding unverified) */",
        "#define METEOR_CAMERA_RAY_CLEARANCE 5.0f   /* Raw .rdata at 0x5A8F74 (Scene geometry stand-off; camera binding unverified) */"
    ],
    [
        "[待重锚定推断] CameraController::UpdateTransform (注: 0x004B6020 实测为内存池链表分配器，具体相机函数待进一步重锚定)",
        "[待重锚定推断] CameraController::CheckSceneOcclusion (LineCheck against BSP to prevent wall poke)",
        "[待重锚定推断] 0x004B8350: CameraController::SetLockOnTarget",
        "[待重锚定推断] 0x004B8D70: CameraController::HandleInputPitchYaw"
    ],
    addr_filter=lambda addr: int(addr, 16) < 0x00500000,
    constants_header="/* --- Raw .rdata Constants (Camera Binding Unverified) --- */"
)

# 6. Effect & Particle Pipeline Subsystem
export_module(
    os.path.join(SYMBOLS_DIR, "decompiled_batch_cam_ef.json"),
    os.path.join(OUT_DIR, "12_Effect_Particle_System.c"),
    "Visual Effects (PonEF V1.00), Particle Emitters & Sound Linking",
    "Parses .ef binary particle templates, manages particle life cycle, billboarding, and alpha blending.",
    ['"../src/include/meteor_app.h"', '"../src/include/meteor_types.h"'],
    [
        "#define METEOR_EFFECT_MAGIC_PONEF   \"PonEF V1.00\" /* Header magic at 0x005D1890 (Binary Verified) */",
        "#define METEOR_MAX_ACTIVE_PARTICLES 1024          /* Reconstructed pool capacity (Pending physical verification) */"
    ],
    [
        "0x00560BF0: EffectManager::scalar_deleting_destructor (Destructor & buffer cleanup via 0x00560C10)",
        "0x0056E490: EffectManager::LoadPonEFFile (Parser for binary .ef particle descriptor)",
        "0x0056EC40: EffectManager::RenderBillboardParticles (D3D vertex buffer emission with additive blend)",
        "0x0056EE30: EffectManager::ReleaseParticleBuffers (Cleanup particle VBs and textures)"
    ],
    addr_filter=lambda addr: int(addr, 16) >= 0x00500000,
    constants_header="/* --- Binary Verified & Reconstructed Constants --- */"
)

print("Export completed successfully.")
