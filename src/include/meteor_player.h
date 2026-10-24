/**
 * @file meteor_player.h
 * @brief PlayerController Definitions & Physics Constants (Verified Binary Extraction)
 * 
 * Target: Meteor.exe (2002) Base Address: 0x00400000
 * Verified against PE disassembly, Capstone analysis, and Ghidra P0 decompilation.
 */

#ifndef METEOR_PLAYER_H
#define METEOR_PLAYER_H

#include "meteor_types.h"

/* --- Verified Physics Constants from PE Image --- */
#define METEOR_JUMP_FORCE_HIGH          375.0f   /* VA: 0x005AA940 - High/Dash Jump Velocity */
#define METEOR_JUMP_FORCE_LOW           282.0f   /* VA: 0x005AA93C - Low/Light Jump Velocity */
#define METEOR_WALL_JUMP_UP_BIAS        1.0f     /* VA: 0x005A83F4 - Wall Jump Normal Up-Bias (+1.0) */
#define METEOR_MAX_SPEED_CAP            600.0f   /* VA: 0x005AA934 - Absolute Speed Clamp */
#define METEOR_SLOPE_COS_THRESHOLD      0.42f    /* VA: 0x005AA92C - Walkable Slope Cosine (~65 deg) */

/* --- Verified Collision Geometry Constants from PE Image --- */
#define METEOR_COLLISION_RADIUS_HORIZ   8.0f     /* VA: 0x005A8FB0 - Horizontal AABB Half-Extent (Radius) */
#define METEOR_COLLISION_HEIGHT_MAX     32.0f    /* VA: 0x005AA938 - Torso AABB Top Offset from Feet */
#define METEOR_COLLISION_HEIGHT_MIN     10.0f    /* VA: 0x005A84AC - Torso AABB Bottom (Step Clearance) */
#define METEOR_STEP_PROBE_DEPTH         2.0f     /* VA: 0x005A8B80 - Mode 0 Ground Raycast Probe Depth */

/* Forward declaration */
typedef struct PlayerController PlayerController;

/**
 * @brief PlayerController Structure (Partial layout mapping to binary offsets)
 */
struct PlayerController {
    /* +0x000 */ void*     vptr;           /* 0x005AA658 (Primary VTable, 150 slots; Sub-vtable 0x005AA6A8 at +0x50) */
    /* +0x010 */ void*     transformNode;  /* CharacterActor = node - 0x65c */
    /* +0x0A8 */ void*     bspCollision;   /* BSP query engine (SceneWorld*) */
    /* +0x0B8 */ Vector3   wallNormal;     /* Wall contact plane normal */
    /* +0x0D8 */ float     slopeNormalZ;   /* Normal Z component */
    /* +0x0DC */ int32_t   moveState;      /* State machine (0..11) */
    /* +0x0E0 */ int32_t   prevMoveState;
    /* +0x0E4 */ int32_t   jumpFlag;
    /* +0x0E8 */ void*     timerObj;
    /* +0x0F0 */ Vector3   inputVector;
    /* +0x1D0 */ Vector3   velocity;       /* Primary linear velocity */
    /* +0x34C */ int32_t   combatLocked;   /* Attack lock */
    /* +0x35C */ int32_t   onSlope;        /* Walkable ground slope flag */
    /* +0x360 */ int32_t   grounded;       /* Is grounded */
    /* +0x390 */ Vector3   jumpVelocity;
    /* +0x398 */ float     jumpForceY;
    /* +0x39C */ Vector3   lastContactNrm;
    /* +0x3C8 */ int32_t   landingState;
};

/* --- Core Method Prototypes --- */

/**
 * @brief Jump routine (Virtual method at 0x004CF5B0)
 * @param self Pointer to PlayerController instance
 * @param isHighJump 1 for High Jump (375.0f), 0 for Low Jump (282.0f)
 * @return 0 on success, -1 if locked or invalid state
 */
int __thiscall Meteor_Player_Jump(PlayerController* self, int isHighJump);

/**
 * @brief Physics integration & collision resolution (Virtual method at 0x004CEB50)
 * @param self Pointer to PlayerController instance
 * @param dt Delta time
 */
void __thiscall Meteor_Player_ProcessPhysics(PlayerController* self, float dt);

/**
 * @brief Scene collision probing routine (Virtual method #64 at 0x004CF1E0)
 * @param self Pointer to PlayerController instance
 * @param delta1 Primary displacement delta
 * @param delta2 Secondary displacement delta (e.g. animation offset)
 * @param mode 0 = Ground probe downward (2.0f), 1 = Linear raycast along path
 * @param outTargetPos Resulting safe position (restored on torso collision)
 * @param outHitNormal Normal of collided surface
 * @return Bitmask: bit 0 (0x1) = Torso/Wall collision, bit 1 (0x2) = Ground/Ray hit
 */
int __thiscall Meteor_Player_ProbeSceneCollision(
    PlayerController* self,
    const Vector3* delta1,
    const Vector3* delta2,
    int mode,
    Vector3* outTargetPos,
    Vector3* outHitNormal
);

/**
 * @brief Raycast against scene BSP tree (Matches FUN_005644F0)
 * @param sceneWorld Pointer to BSP scene object (ecx)
 * @param pStart Ray start position
 * @param pEnd Ray end position
 * @param outHitPos Nearest intersection point (output)
 * @param outHitNormal Surface normal of collided triangle (output)
 * @return Number of intersections (0 if clear)
 */
int __thiscall Meteor_Scene_LineCheck(
    void* sceneWorld,
    const Vector3* pStart,
    const Vector3* pEnd,
    Vector3* outHitPos,
    Vector3* outHitNormal
);

/**
 * @brief AABB box sweep/overlap test against scene BSP tree (Matches FUN_00563070)
 * @param sceneWorld Pointer to BSP scene object (ecx)
 * @param boxMin Minimum corner of bounding box
 * @param boxMax Maximum corner of bounding box
 * @param outHitNormal Surface normal of collided polygon (output)
 * @return 1 if penetrating/colliding, 0 if clear
 */
int __thiscall Meteor_Scene_SweepBox(
    void* sceneWorld,
    const Vector3* boxMin,
    const Vector3* boxMax,
    Vector3* outHitNormal
);

/**
 * @brief Velocity clamping against MAX_SPEED_CAP (0x004CEBE2)
 * @param v In/out velocity vector
 */
void Meteor_Physics_ClampSpeed(Vector3* v);

/**
 * @brief Vector plane tangent projection (0x004CF170)
 * @param v In/out velocity vector
 * @param n Plane surface normal
 */
void Meteor_Physics_ProjectTangent(Vector3* v, const Vector3* n);

#endif /* METEOR_PLAYER_H */
