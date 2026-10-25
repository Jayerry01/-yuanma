#ifndef METEOR_COMBAT_H
#define METEOR_COMBAT_H

#include "meteor_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* --- Verified Binary Combat & Impact Constants --- */
#define METEOR_KNOCKBACK_LEVEL_8        350.0f   /* VA: 0x004D0BB4 (0x43AF0000) - Light Impact Knockback */
#define METEOR_KNOCKBACK_LEVEL_9        400.0f   /* VA: 0x004D0BBE (0x43C80000) - Medium Impact Knockback */
#define METEOR_KNOCKBACK_LEVEL_10       450.0f   /* VA: 0x004D0BC8 (0x43E10000) - Heavy Impact Knockback */
#define METEOR_KNOCKBACK_LEVEL_DEFAULT  600.0f   /* VA: 0x004D0B9D (0x44160000) - Maximum Impact Knockback */
#define METEOR_HIT_POPUP_BIAS           0.13f    /* VA: 0x005AA944 - Vertical Pop-Up Angle Bias */
#define METEOR_HITBOX_CHEST_OFFSET      40.0f    /* VA: 0x005A8E7C - Torso Center of Mass Height Offset */
#define METEOR_HITBOX_MID_OFFSET        20.0f    /* VA: 0x005A8B08 - Impact Midpoint Vertical Offset */
#define METEOR_AI_BREAKOUT_THRESHOLD    60       /* VA: 0x004FDDC9 (0x3C) - AI Rage Breakout / Reversal Threshold */
#define METEOR_AI_BREAKOUT_DISTANCE     80.0f    /* VA: 0x005AB870 (0x42A00000) - AI Rage Burst Max Proximity */
#define METEOR_WEAPON_STRUCT_SIZE       104      /* 0x68 bytes per weapon entry indexed in 0x0055DDD0 */

/* Character Actor Attribute IDs (CharacterActor vtable[13] @ 0x004DC4C0) */
typedef enum ActorAttributeId {
    ACTOR_ATTR_CURRENT_HP   = 2,   /* 0x02: Current HP (气血) - Cached at 0x005E0454 */
    ACTOR_ATTR_MAX_HP       = 3,   /* 0x03: Maximum HP (最大气血) - Cached at 0x005E045C */
    ACTOR_ATTR_ANGRY        = 6,   /* 0x06: Rage / Angry Value (怒气, 0..100) - Cached at 0x005E04A4 */
    ACTOR_ATTR_POISON       = 10   /* 0x0A: Poison Status Flag (中毒) */
} ActorAttributeId;

/* Action Cancel Flags (Parsed in 0x004D1740 from character.act) */
typedef enum ActionCancelFlag {
    CANCEL_FLAG_ATTACK          = 0x1000, /* Attack Chain Cancel / 普攻连招取消 */
    CANCEL_FLAG_GUARD           = 0x0020, /* Guard Cancel / 防御取消 */
    CANCEL_FLAG_JUMP            = 0x1200, /* Jump Cancel / 小跳取消 */
    CANCEL_FLAG_SWITCH_WEAPON   = 0x0045, /* Weapon Switch Cancel / 换武器取消 */
    CANCEL_FLAG_UNLOCK          = 0x0051, /* Target Unlock Cancel / 解除锁定 */
    CANCEL_FLAG_DROP_WEAPON     = 0x0047, /* Drop Weapon Cancel / 丢弃武器 */
    CANCEL_FLAG_FAKE            = 0x0059, /* Feint / Fake Move Cancel / 虚招佯攻 */
    CANCEL_FLAG_RIGHT_TURN      = 0x0027, /* Right Turn Cancel / 右转 */
    CANCEL_FLAG_LEFT_TURN       = 0x0025, /* Left Turn Cancel / 左转 */
    CANCEL_FLAG_DROP_ITEM       = 0x0048, /* Drop Item Cancel / 丢弃道具 */
    CANCEL_FLAG_CURE            = 0x0054, /* Medication / Cure Cancel / 服药疗伤 */
    CANCEL_FLAG_CROUCH          = 0x0043, /* Crouch Cancel / 蹲伏 */
    CANCEL_FLAG_INITIAL_CAMERA  = 0x004C, /* Initial Camera Reset Cancel / 视角重置取消 */
    CANCEL_FLAG_FOOL            = 0x0052, /* Taunt / Fool Cancel / 挑衅嘲讽取消 */
    CANCEL_FLAG_SCORE           = 0x0009, /* Score / Finish Pose Cancel / 收招评分结算取消 */
    CANCEL_FLAG_HIT_ATTACK      = 0x0046  /* Hit-Confirm Attack Cancel / 命中确认追加攻击取消 */
} ActionCancelFlag;

/* Combat Attack Types */
typedef enum AttackType {
    ATTACK_TYPE_NORMAL      = 0, // 普通打击
    ATTACK_TYPE_KNOCKBACK   = 1, // 击飞/击退
    ATTACK_TYPE_KNOCKDOWN   = 2, // 击倒
    ATTACK_TYPE_STUN        = 3, // 僵直/重创
    ATTACK_TYPE_BREAK_GUARD = 4  // 破防
} AttackType;

/* Weapon Property Definition (104 bytes / 0x68 from 0x0055DDD0) */
typedef struct MeteorWeaponProperty {
    char        name[32];           /* +0x00: Model / Resource Name */
    uint32_t    weaponType;         /* +0x20: Category (0:Blade, 1:Dagger, 2:Sword, 3:Lance...) */
    uint32_t    subType;            /* +0x24: Subtype */
    uint32_t    meshHandle;         /* +0x28: 3D Render Mesh Handle */
    uint32_t    boneDummyId;        /* +0x2C: Bone Dummy Attachment ID */
    uint32_t    attributeFlags;     /* +0x30: Weapon Attributes & Elemental Flags */
    uint32_t    reserved1[2];       /* +0x34: Padding */
    float       minAttackRate;      /* +0x3C: Minimum Attack Scaling Rate */
    float       minDefenseRate;     /* +0x40: Minimum Defense Mitigation Rate */
    uint32_t    reserved2;          /* +0x44: Padding */
    int32_t     baseAttack;         /* +0x48: Base Attack Power */
    uint32_t    reserved3[5];       /* +0x4C: Sound / FX Triggers */
    float       attackMultiplier;   /* +0x60: Primary Attack Multiplier */
    float       defenseMultiplier;  /* +0x64: Primary Defense Mitigation Multiplier */
} MeteorWeaponProperty;

/* Oriented Bounding Box for SAT Hit Collision (0x00570630 / 0x005706C0) */
typedef struct MeteorOBB {
    Vector3     center;             // World position center
    Vector3     extents;            // Half dimensions along local axes
    Vector3     axes[3];            // Orthogonal orientation vectors (normalized)
} MeteorOBB;

/* Combat HitBox attached to Bone */
typedef struct HitBox {
    int32_t boneIndex;      // Bone index in character skeleton (e.g. RightHand = 26)
    Vector3 localOffset;    // Center offset from bone pivot
    float   radius;         // Spherical contact radius
    int32_t activeStart;    // Start frame within pose
    int32_t activeEnd;      // End frame within pose
} HitBox;

/* Action Cancel Window Range Definition */
typedef struct CancelWindowDef {
    uint32_t cancelType;    // ActionCancelFlag
    int32_t  startFrame;    // Start frame
    int32_t  endFrame;      // End frame (startFrame + duration if '+' used)
} CancelWindowDef;

/* Damage Packet sent during Hit Event (Allocated with size 0x1D0 = 464 bytes @ 0x004D0B04) */
typedef struct DamagePacket {
    int32_t     attackerId;     // Character index of attacker
    int32_t     victimId;       // Character index of target
    int32_t     attackPoseId;   // Active pose ID of attack
    int32_t     damageValue;    // Raw damage points
    AttackType  attackType;     // Attack category (0..4)
    int32_t     impactLevel;    // Impact velocity level (8=350, 9=400, 10/11=450, def=600)
    Vector3     hitPoint;       // World position of contact
    Vector3     knockback;      // Velocity impulse applied to victim (scaled by impact speed)
    BOOL        isGuardBroken;  // True if target's defense was pierced
    uint32_t    damageFlags;    // Packed attribute flags (attributeFlags << 10 | 0x30000)
    uint32_t    attackRates;    // High 16: minAtkPct, Low 16: maxAtkPct
    uint32_t    defenseRates;   // High 16: minDefPct, Low 16: maxDefPct
} DamagePacket;

/* Combat System Functions */
int32_t Meteor_ProcessCombatEvent(void* combatMgr, int32_t eventType, const DamagePacket* packet);
int32_t Meteor_CalculateDamage(int32_t baseDamage, int32_t attackWeight, int32_t defenseRate);
void    Meteor_Combat_ComputeKnockback(const Vector3* hitNormal, int32_t impactLevel, Vector3* outKnockback);
BOOL    Meteor_Combat_IntersectSegmentOBB(const Vector3* p0, const Vector3* p1, const MeteorOBB* obb, Vector3* outContact);
BOOL    Meteor_AI_CheckRageBreakout(int32_t currentRage, int32_t reactionRate, float distanceToTarget);
void    Meteor_Combat_BuildDamagePacket(const MeteorWeaponProperty* weapon, int32_t attackerId, int32_t victimId, int32_t impactLevel, const Vector3* hitNormal, DamagePacket* outPacket);

#ifdef __cplusplus
}
#endif

#endif /* METEOR_COMBAT_H */
