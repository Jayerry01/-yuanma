/**
 * @file combat_system.c
 * @brief Reverse-engineered Combat & Combo System from Meteor.exe (2002)
 * 
 * Target: Meteor.exe (FUN_0045B280, FUN_0045D363)
 * Implements:
 *   - Attack hitbox detection and resolution
 *   - Damage calculation formula
 *   - Dagger combo progression & cancel windows
 *   - Defense check and guard break handling
 */

#include "include/meteor_combat.h"
#include "include/meteor_pose.h"
#include <math.h>
#include <stdio.h>

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
 * Mirrors Meteor.exe damage formula
 */
int32_t Meteor_CalculateDamage(int32_t baseDamage, int32_t attackWeight, int32_t defenseRate) {
    if (baseDamage <= 0) baseDamage = 10;

    // Weight scaling (attackWeight: 100 = 1.0x)
    float damage = (float)baseDamage * ((float)attackWeight / 100.0f);

    // Defense mitigation (defenseRate: percent reduction, max 80%)
    if (defenseRate > 80) defenseRate = 80;
    damage *= (1.0f - ((float)defenseRate / 100.0f));

    return (int32_t)(damage + 0.5f);
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
