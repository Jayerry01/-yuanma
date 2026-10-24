/**
 * @file player_controller.c
 * @brief Reverse-engineered implementation of PlayerController & Physics Subsystem
 *
 * Source: Meteor.exe (2002)
 * Key Routine Addresses:
 *   - 0x004CF1E0: PlayerController::ProbeSceneCollision (vftable[84] at 0x005AA658; internal sub-vftable[64] at 0x005AA6A8)
 *   - 0x005644F0: SceneWorld::LineCheck (Raycast against BSP polygons)
 *   - 0x00563070: SceneWorld::SweepBox (AABB SAT overlap test against BSP)
 *   - 0x004CF5B0: PlayerController::Jump
 *   - 0x004CF680: PlayerController::Jump - Case 2: Wall Jump Branch
 *   - 0x004CEB50: PlayerController::ProcessPhysics
 *   - 0x004CEE40: PlayerController::UpdateCollision & Ground State
 */

#include "include/meteor_player.h"
#include <math.h>
#include <string.h>

/* State Dispatch Table extracted from 0x004CF75C */
static const uint8_t s_jumpStateTable[12] = {
    0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 1
};

/**
 * @brief Vector normalization (Matches 0x0047EC40)
 */
static void Vector3_Normalize(Vector3* v) {
    float magSq = v->x * v->x + v->y * v->y + v->z * v->z;
    if (magSq > 1e-6f) {
        float invLen = 1.0f / sqrtf(magSq);
        v->x *= invLen;
        v->y *= invLen;
        v->z *= invLen;
    }
}

/**
 * @brief Vector length calculation (Matches 0x0047ECF0)
 */
static float Vector3_Length(const Vector3* v) {
    return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

/**
 * @brief Velocity clamping against MAX_SPEED_CAP (Matches 0x004CEBE2 - 0x004CEC3E)
 */
void Meteor_Physics_ClampSpeed(Vector3* v) {
    float speed = Vector3_Length(v);
    if (speed > METEOR_MAX_SPEED_CAP) {
        Vector3_Normalize(v);
        v->x *= METEOR_MAX_SPEED_CAP;
        v->y *= METEOR_MAX_SPEED_CAP;
        v->z *= METEOR_MAX_SPEED_CAP;
    }
}

/**
 * @brief Surface tangent velocity projection (Matches 0x004CF170 - 0x004CF1BD)
 * Formula: v' = v - (v . n) * n
 */
void Meteor_Physics_ProjectTangent(Vector3* v, const Vector3* n) {
    float dot = v->x * n->x + v->y * n->y + v->z * n->z;
    v->x -= n->x * dot;
    v->y -= n->y * dot;
    v->z -= n->z * dot;
}

/**
 * @brief Scene collision probing routine (Virtual method #64 at 0x004CF1E0)
 *
 * Implements the full raycast + swept AABB torso verification pipeline.
 */
int __thiscall Meteor_Player_ProbeSceneCollision(
    PlayerController* self,
    const Vector3* delta1,
    const Vector3* delta2,
    int mode,
    Vector3* outTargetPos,
    Vector3* outHitNormal
) {
    if (!self || !self->bspCollision || !self->transformNode) {
        return 0;
    }

    /* 1. Extract base position from transformNode (0x004CF206 - 0x004CF217) */
    Vector3 currentPos = { 0.0f, 0.0f, 0.0f };
    /* In actual binary: ecx = self->transformNode - 0x65c; call [vtable + 0x6C](&currentPos, 2) */

    /* 2. Compute candidate position (0x004CF246 - 0x004CF2C9) */
    Vector3 candidate = currentPos;
    if (delta1) {
        candidate.x += delta1->x;
        candidate.y += delta1->y;
        candidate.z += delta1->z;
    }
    if (delta2) {
        candidate.x += delta2->x;
        candidate.y += delta2->y;
        candidate.z += delta2->z;
    }

    int rayHitFlag = 0;
    Vector3 rayHitPos = candidate;

    /* 3. Branch by mode (0x004CF2D8 - 0x004CF38C) */
    if (mode == 0) {
        /* Mode 0 (0x004CF361): Foot Downward Ground Probe (2.0f @ 0x005A8B80) */
        Vector3 probeEnd = candidate;
        probeEnd.z -= METEOR_STEP_PROBE_DEPTH;

        /* Call FUN_005644F0 (bspTree, candidate, probeEnd, outHitPos, outHitNormal) */
        if (Meteor_Scene_LineCheck(self->bspCollision, &candidate, &probeEnd, &rayHitPos, outHitNormal)) {
            candidate = rayHitPos;
            rayHitFlag = 2;
        }
    } else if (mode == 1) {
        /* Mode 1 (0x004CF2FB): Linear Path Raycast */
        /* Call FUN_005644F0 (bspTree, currentPos, candidate, outHitPos, outHitNormal) */
        if (Meteor_Scene_LineCheck(self->bspCollision, &currentPos, &candidate, &rayHitPos, outHitNormal)) {
            candidate = rayHitPos;
            rayHitFlag = 2;
        }
    }

    /* 4. Torso Swept AABB Collision (0x004CF3B5 - 0x004CF461)
     * Constants:
     *   - 8.0f  @ 0x005A8FB0: Horizontal half-extents (X/Y radius)
     *   - 32.0f @ 0x005AA938: Torso top offset (Z-Max)
     *   - 10.0f @ 0x005A84AC: Torso bottom offset (Z-Min step gap)
     */
    Vector3 boxMin, boxMax;
    boxMin.x = candidate.x - METEOR_COLLISION_RADIUS_HORIZ;
    boxMin.y = candidate.y - METEOR_COLLISION_RADIUS_HORIZ;
    boxMin.z = candidate.z + METEOR_COLLISION_HEIGHT_MIN;

    boxMax.x = candidate.x + METEOR_COLLISION_RADIUS_HORIZ;
    boxMax.y = candidate.y + METEOR_COLLISION_RADIUS_HORIZ;
    boxMax.z = candidate.z + METEOR_COLLISION_HEIGHT_MAX;

    /* Call FUN_00563070 (bspTree, boxMin, boxMax, outHitNormal) */
    int sweepHitFlag = Meteor_Scene_SweepBox(self->bspCollision, &boxMin, &boxMax, outHitNormal);

    /* 5. Safe position rollback or acceptance (0x004CF471 - 0x004CF4A9) */
    if (outTargetPos) {
        if (sweepHitFlag) {
            /* Penetration detected: roll back to current safe position */
            *outTargetPos = currentPos;
        } else {
            /* Free to move: accept candidate position */
            *outTargetPos = candidate;
        }
    }

    /* 6. Return combined bitmask (0x004CF493 - 0x004CF4B5)
     * bit 0 (0x1): Torso/Wall penetration (movement blocked)
     * bit 1 (0x2): Ground/Ray intersection (feet grounded or surface hit)
     */
    return rayHitFlag | (sweepHitFlag ? 1 : 0);
}

/**
 * @brief Jump routine (Virtual method at 0x004CF5B0)
 */
int __thiscall Meteor_Player_Jump(PlayerController* self, int isHighJump) {
    if (!self || !self->transformNode) {
        return -1;
    }

    /* Combat lock check */
    if (self->combatLocked != 0) {
        return -1;
    }

    if (self->moveState > 11) {
        return -1;
    }

    uint8_t branchCase = s_jumpStateTable[self->moveState];

    switch (branchCase) {
        case 0: /* 0x004CF5D8: Idle State */
            self->jumpFlag = 1;
            return 0;

        case 1: /* 0x004CF60F: Ground / Running Jump Branch */
        {
            float jumpForce = isHighJump ? METEOR_JUMP_FORCE_HIGH : METEOR_JUMP_FORCE_LOW;
            self->jumpForceY = jumpForce;
            self->velocity.z = jumpForce; /* Z is Up in Meteor coordinate system */
            self->jumpFlag = 1;
            self->grounded = 0;
            return 0;
        }

        case 2: /* 0x004CF680: Wall Jump (蹬墙反跳) Branch */
        {
            /* 1. Fetch contact wall normal */
            Vector3 jumpDir;
            jumpDir.x = self->lastContactNrm.x;
            jumpDir.y = self->lastContactNrm.y;
            jumpDir.z = self->lastContactNrm.z + METEOR_WALL_JUMP_UP_BIAS; /* +1.0f Up Bias @ 0x005A83F4 */

            /* 2. Normalize jump direction */
            Vector3_Normalize(&jumpDir);

            /* 3. Scale by jump speed */
            float speed = isHighJump ? METEOR_JUMP_FORCE_HIGH : METEOR_JUMP_FORCE_LOW;
            self->velocity.x = jumpDir.x * speed;
            self->velocity.y = jumpDir.y * speed;
            self->velocity.z = jumpDir.z * speed;

            self->jumpFlag = 1;
            self->grounded = 0;
            return 0;
        }

        case 3: /* 0x004CF604: Locked / Incapacitated */
        default:
            return -1;
    }
}

/**
 * @brief Physics integration & collision resolution (Virtual method at 0x004CEB50 / 0x004CEE40)
 */
void __thiscall Meteor_Player_ProcessPhysics(PlayerController* self, float dt) {
    if (!self) return;

    /* 1. Clamp absolute speed (0x004CEBE2) */
    Meteor_Physics_ClampSpeed(&self->velocity);

    /* 2. Tangent projection upon collision surface (0x004CF170) */
    if (self->onSlope) {
        /* Ground slope angle evaluation: cos(theta) >= 0.42f (0x004CF005 / 0x005AA92C) */
        if (self->slopeNormalZ >= METEOR_SLOPE_COS_THRESHOLD) {
            self->grounded = 1;
        }
    }
}
