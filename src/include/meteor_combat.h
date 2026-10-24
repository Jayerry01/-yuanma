#ifndef METEOR_COMBAT_H
#define METEOR_COMBAT_H

#include "meteor_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Combat Attack Types */
typedef enum AttackType {
    ATTACK_TYPE_NORMAL      = 0, // 普通打击
    ATTACK_TYPE_KNOCKBACK   = 1, // 击飞/击退
    ATTACK_TYPE_KNOCKDOWN   = 2, // 击倒
    ATTACK_TYPE_STUN        = 3, // 僵直/重创
    ATTACK_TYPE_BREAK_GUARD = 4  // 破防
} AttackType;

/* Combat HitBox attached to Bone */
typedef struct HitBox {
    int32_t boneIndex;      // Bone index in character skeleton (e.g. RightHand = 26)
    Vector3 localOffset;    // Center offset from bone pivot
    float   radius;         // Spherical contact radius
    int32_t activeStart;    // Start frame within pose
    int32_t activeEnd;      // End frame within pose
} HitBox;

/* Damage Packet sent during Hit Event */
typedef struct DamagePacket {
    int32_t     attackerId;     // Character index of attacker
    int32_t     victimId;       // Character index of target
    int32_t     attackPoseId;   // Active pose ID of attack
    int32_t     damageValue;    // Raw damage points
    AttackType  attackType;     // Attack category
    Vector3     hitPoint;       // World position of contact
    Vector3     knockback;      // Velocity impulse applied to victim
    BOOL        isGuardBroken;  // True if target's defense was pierced
} DamagePacket;

/* Combat System Functions (Meteor.exe FUN_0045B280) */
int32_t Meteor_ProcessCombatEvent(void* combatMgr, int32_t eventType, const DamagePacket* packet);
int32_t Meteor_CalculateDamage(int32_t baseDamage, int32_t attackWeight, int32_t defenseRate);

#ifdef __cplusplus
}
#endif

#endif /* METEOR_COMBAT_H */
