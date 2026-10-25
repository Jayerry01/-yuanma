/**
 * @file combat_system.c
 * @brief Reverse-engineered Combat & Combo System from Meteor.exe (2002)
 * 
 * Target: Meteor.exe (FUN_0045B280, FUN_004D0540, FUN_004D0AC0, FUN_005706C0, FUN_004FDD70)
 * Implements:
 *   - Attack hitbox detection and SAT OBB resolution
 *   - Binary-verified damage calculation formula
 *   - 4-Tier knockback velocity lookup & pop-up bias
 *   - Weapon property unpacking and damage packet construction
 *   - AI rage breakout / super reversal logic
 *   - Dagger combo progression & cancel windows
 */

#include "include/meteor_combat.h"
#include "include/meteor_pose.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Dagger Combo Progression Map */
static const struct {
    int32_t currentPose;
    int32_t nextPose;
    int32_t cancelWindowStart;
    int32_t cancelWindowEnd;
} g_DaggerCombos[] = {
    { DAGGER_POSE_ATTACK_1, DAGGER_POSE_ATTACK_2, 8,  14 }, // 248 -> 249
    { DAGGER_POSE_ATTACK_2, DAGGER_POSE_ATTACK_3, 10, 18 }, // 249 -> 250
    { DAGGER_POSE_ATTACK_3, DAGGER_POSE_ATTACK_4, 12, 20 }, // 250 -> 251
    { DAGGER_POSE_ATTACK_4, DAGGER_POSE_HEAVY_THRUST, 15, 24 }, // 251 -> 253
    { DAGGER_POSE_BACKSTAB_1, DAGGER_POSE_BACKSTAB_2, 6, 12 },  // 257 -> 258
    { DAGGER_POSE_AIR_DIVE_START, DAGGER_POSE_AIR_DIVE_LAND, 0, 999 } // 370 -> 371
};

#define DAGGER_COMBO_COUNT (sizeof(g_DaggerCombos) / sizeof(g_DaggerCombos[0]))

/**
 * @brief Calculate final damage points
 * Mirrors Meteor.exe damage formula decompiled from 0x004D0C26 & 0x004D08CD
 */
int32_t Meteor_CalculateDamage(int32_t baseDamage, int32_t attackWeight, int32_t defenseRate) {
    if (baseDamage <= 0) baseDamage = 10;

    /* Attack weight scaling: 100 = 1.0x */
    float damage = (float)baseDamage * ((float)attackWeight / 100.0f);

    /* Defense mitigation (defenseRate: percent reduction, capped at 80%) */
    if (defenseRate > 80) defenseRate = 80;
    damage *= (1.0f - ((float)defenseRate / 100.0f));

    /* Round to nearest integer (+0.5f) matching __ftol @ 0x004D08D6 */
    return (int32_t)(damage + 0.5f);
}

/**
 * @brief Compute knockback impulse vector from hit normal and impact level
 * Decompiled from Meteor.exe @ 0x004D0668 - 0x004D0C88 (PlayerController::OnHit & ProcessDamage)
 */
void Meteor_Combat_ComputeKnockback(const Vector3* hitNormal, int32_t impactLevel, Vector3* outKnockback) {
    if (!hitNormal || !outKnockback) return;

    /* 1. Determine speed scale from impact level (0x004D0BA5 - 0x004D0BD0) */
    float speed;
    switch (impactLevel) {
        case 8:  speed = METEOR_KNOCKBACK_LEVEL_8;  break; /* 350.0f */
        case 9:  speed = METEOR_KNOCKBACK_LEVEL_9;  break; /* 400.0f */
        case 10: speed = METEOR_KNOCKBACK_LEVEL_10; break; /* 450.0f */
        case 11: speed = METEOR_KNOCKBACK_LEVEL_10; break; /* 450.0f */
        default: speed = METEOR_KNOCKBACK_LEVEL_DEFAULT; break; /* 600.0f */
    }

    /* 2. Apply Pop-Up Bias (+0.13f @ 0x005AA944) on vertical component */
    outKnockback->x = hitNormal->x * speed;
    outKnockback->y = hitNormal->y * speed;
    outKnockback->z = (hitNormal->z + METEOR_HIT_POPUP_BIAS) * speed;
}

/**
 * @brief Build DamagePacket from equipped weapon and hit event
 * Decompiled from Meteor.exe @ 0x004D0AC0, 0x004D08A6 - 0x004D0936
 */
void Meteor_Combat_BuildDamagePacket(const MeteorWeaponProperty* weapon, int32_t attackerId, int32_t victimId, int32_t impactLevel, const Vector3* hitNormal, DamagePacket* outPacket) {
    if (!outPacket) return;

    outPacket->attackerId   = attackerId;
    outPacket->victimId     = victimId;
    outPacket->impactLevel  = impactLevel;
    outPacket->isGuardBroken= FALSE;

    if (weapon) {
        outPacket->damageValue = weapon->baseAttack;

        /* Quantize attack & defense multipliers (+0.5f rounding @ 0x004D08CD) */
        uint32_t minAtkPct = (uint32_t)(weapon->minAttackRate * 100.0f + 0.5f) & 0xFFFF;
        uint32_t maxAtkPct = (uint32_t)(weapon->attackMultiplier * 100.0f + 0.5f) & 0xFFFF;
        uint32_t minDefPct = (uint32_t)(weapon->minDefenseRate * 100.0f + 0.5f) & 0xFFFF;
        uint32_t maxDefPct = (uint32_t)(weapon->defenseMultiplier * 100.0f + 0.5f) & 0xFFFF;

        outPacket->attackRates  = (minAtkPct << 16) | maxAtkPct;
        outPacket->defenseRates = (minDefPct << 16) | maxDefPct;
        outPacket->damageFlags  = (weapon->attributeFlags << 10) | 0x30000;
    } else {
        outPacket->damageValue  = 10;
        outPacket->attackRates  = (100 << 16) | 100;
        outPacket->defenseRates = 0;
        outPacket->damageFlags  = 0x30000;
    }

    if (hitNormal) {
        Meteor_Combat_ComputeKnockback(hitNormal, impactLevel, &outPacket->knockback);
    }
}

/**
 * @brief Separating Axis Theorem (SAT) Segment vs Oriented Bounding Box (OBB)
 * Decompiled from Meteor.exe @ 0x00570630 & 0x005706C0
 * 
 * Tests if the blade segment (p0 -> p1) intersects with target OBB.
 */
BOOL Meteor_Combat_IntersectSegmentOBB(const Vector3* p0, const Vector3* p1, const MeteorOBB* obb, Vector3* outContact) {
    if (!p0 || !p1 || !obb) return FALSE;

    /* Segment direction vector S = p1 - p0 */
    Vector3 S;
    S.x = p1->x - p0->x;
    S.y = p1->y - p0->y;
    S.z = p1->z - p0->z;

    /* Center difference vector D = obb->center - p0 */
    Vector3 D;
    D.x = obb->center.x - p0->x;
    D.y = obb->center.y - p0->y;
    D.z = obb->center.z - p0->z;

    /* Test Separating Axis along the 3 local axes of the OBB */
    float extents[3] = { obb->extents.x, obb->extents.y, obb->extents.z };
    for (int i = 0; i < 3; ++i) {
        /* Dot product with local axis i */
        float projD = D.x * obb->axes[i].x + D.y * obb->axes[i].y + D.z * obb->axes[i].z;
        float projS = S.x * obb->axes[i].x + S.y * obb->axes[i].y + S.z * obb->axes[i].z;

        float pMin = projD;
        float pMax = projD + projS;
        if (pMin > pMax) {
            float tmp = pMin; pMin = pMax; pMax = tmp;
        }

        /* If segment projection interval does not overlap [-extent, +extent], separating axis found */
        if (pMin > extents[i] || pMax < -extents[i]) {
            return FALSE;
        }
    }

    /* Contact midpoint if requested */
    if (outContact) {
        outContact->x = (p0->x + p1->x) * 0.5f;
        outContact->y = (p0->y + p1->y) * 0.5f;
        outContact->z = (p0->z + p1->z) * 0.5f;
    }

    return TRUE;
}

/**
 * @brief Evaluate AI Rage Breakout / Super Combo Trigger
 * Decompiled from Meteor.exe @ 0x004FDD70 / 0x004FDDC9
 */
BOOL Meteor_AI_CheckRageBreakout(int32_t currentRage, int32_t reactionRate, float distanceToTarget) {
    /* Condition 1: Rage value >= 60 (0x3C @ 0x004FDDC9) */
    if (currentRage < METEOR_AI_BREAKOUT_THRESHOLD) {
        return FALSE;
    }

    /* Condition 2: Target distance <= 80.0f (0x005AB870) */
    if (distanceToTarget > METEOR_AI_BREAKOUT_DISTANCE) {
        return FALSE;
    }

    /* Condition 3: AI Reaction / Aggression Roll (rand() % 100 < reactionRate @ 0x004FDDA9) */
    if ((rand() % 100) >= reactionRate) {
        return FALSE;
    }

    /* Condition 4: 20% Discrete Decision Trigger (rand() % 5 == 0 @ 0x004FDE2F) */
    if ((rand() % 5) != 0) {
        return FALSE;
    }

    return TRUE;
}

/**
 * @brief Process Hit Event between Attacker and Target
 * Decompiled from Meteor.exe @ 0x0045B280 (FUN_0045b280)
 */
int32_t Meteor_ProcessCombatEvent(void* combatMgr, int32_t eventType, const DamagePacket* packet) {
    if (!packet) return 0;

    // Check target guard status
    if (packet->attackType == ATTACK_TYPE_BREAK_GUARD) {
        // Pierces guard directly
        printf("[Combat] Guard Broken! AttackPose: %d, Damage: %d\n", 
               packet->attackPoseId, packet->damageValue);
        return packet->damageValue;
    }

    if (packet->isGuardBroken) {
        return packet->damageValue;
    }

    return packet->damageValue;
}

/**
 * @brief Check next valid combo pose for Dagger
 */
int32_t Meteor_GetNextDaggerCombo(int32_t currentPose, int32_t currentFrame) {
    for (size_t i = 0; i < DAGGER_COMBO_COUNT; ++i) {
        if (g_DaggerCombos[i].currentPose == currentPose) {
            if (currentFrame >= g_DaggerCombos[i].cancelWindowStart &&
                currentFrame <= g_DaggerCombos[i].cancelWindowEnd) {
                return g_DaggerCombos[i].nextPose;
            }
        }
    }
    return -1; // Combo window closed or not chainable
}
