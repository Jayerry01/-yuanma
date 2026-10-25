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
#define METEOR_SLOPE_COS_THRESHOLD      0.42f    /* VA: 0x005AA92C - Walkable Slope Cosine (~65.16 deg) */

/* --- Verified Wall Climb & Mobility Constants from PE Image --- */
#define METEOR_WALL_PROBE_RAY_LEN       16.0f    /* VA: 0x005A8458 - Wall Probe Ray Length */
#define METEOR_WALL_CLIMB_MAX_TIME      1.8      /* VA: 0x005AA8F0 - Max Wall Climb Time (double, sec) */
#define METEOR_WALL_CLIMB_INTERVAL      0.11     /* VA: 0x005AA8E8 - Wall Climb Step Interval (double, sec) */
#define METEOR_WALL_CLIMB_MIN_TICK      0.1      /* VA: 0x005A8C90 - Min Jump Time to Cling (double, sec) */
#define METEOR_WALL_ANGLE_LEFT_MAX      2.7      /* VA: 0x005AA8D0 - Angle Threshold for Climb Left (double) */
#define METEOR_WALL_ANGLE_RIGHT_MIN     -2.7     /* VA: 0x005AA8C8 - Angle Threshold for Climb Right (double) */
#define METEOR_WALL_CLIMB_DAMPING       -1.2f    /* VA: 0x005AA8E0 - Wall Climb Kinetic Damping */
#define METEOR_WALL_CLIMB_GRAVITY       0.1f     /* VA: 0x005A83EC - Wall Climb Gravity Factor */
#define METEOR_WALL_CONTACT_OFFSET      -18.0f   /* VA: 0x005AA8DC - Wall Contact Alignment Offset */
#define METEOR_WALL_FORCE_SCALE         800.0f   /* VA: 0x005AA8D8 - Wall Tangent Force Scaling */
#define METEOR_FALLING_SPEED_THRESHOLD  -40.0f   /* VA: 0x005AA918 - Fall Transition Velocity Threshold */

/* --- Verified Collision Geometry Constants from PE Image --- */
#define METEOR_COLLISION_RADIUS_HORIZ   8.0f     /* VA: 0x005A8FB0 - Horizontal AABB Half-Extent (Radius) */
#define METEOR_COLLISION_HEIGHT_MAX     32.0f    /* VA: 0x005AA938 - Torso AABB Top Offset from Feet */
#define METEOR_COLLISION_HEIGHT_MIN     10.0f    /* VA: 0x005A84AC - Torso AABB Bottom (Step Clearance) */
#define METEOR_STEP_PROBE_DEPTH         2.0f     /* VA: 0x005A8B80 - Mode 0 Ground Raycast Probe Depth */

/* --- Qinggong Animation Pose IDs --- */
typedef enum QinggongPose {
    POSE_RUN_RIGHT              = 141, /* 0x8D: Run Right */
    POSE_RUN_LEFT               = 142, /* 0x8E: Run Left */
    POSE_RUN_BACK               = 143, /* 0x8F: Run Back */
    POSE_RUN_STOP               = 146, /* 0x92: Run Stop Brake */
    POSE_JUMP_PREP              = 150, /* 0x96: Jump Charge / Prep */
    POSE_JUMP_UP                = 151, /* 0x97: Jump Forward / Up */
    POSE_FALL_UP                = 152, /* 0x98: Fall Forward / Up */
    POSE_JUMP_LEFT              = 153, /* 0x99: Jump Left */
    POSE_FALL_LEFT              = 154, /* 0x9A: Fall Left */
    POSE_JUMP_RIGHT             = 155, /* 0x9B: Jump Right */
    POSE_FALL_RIGHT             = 156, /* 0x9C: Fall Right */
    POSE_WALL_KICK_BACK         = 157, /* 0x9D: Wall Kick / Backflip */
    POSE_WALL_FALL_BACK         = 158, /* 0x9E: Wall Kick Fall */
    POSE_WALL_KICK_LEFT         = 159, /* 0x9F: Wall Kick Left */
    POSE_WALL_KICK_RIGHT        = 160, /* 0xA0: Wall Kick Right */
    POSE_CLIMB_UP               = 161, /* 0xA1: Wall Climb Up */
    POSE_CLIMB_LEFT             = 162, /* 0xA2: Wall Climb Left */
    POSE_CLIMB_RIGHT            = 163, /* 0xA3: Wall Climb Right */
    POSE_LANDING_RECOVERY       = 164, /* 0xA4: Landing Buffer / Recovery */
    POSE_HEAVY_LANDING          = 167, /* 0xA7: Heavy Fall Impact Stun */
    POSE_BREAK_FALL             = 213  /* 0xD5: Ground Roll / Break Fall */
} QinggongPose;

/* Forward declaration */
typedef struct PlayerController PlayerController;

/**
 * @brief PlayerController Structure (Partial layout mapping to binary offsets)
 */
struct PlayerController {
    /* +0x000 */ void*     vptr;           /* 0x005AA658 (Primary VTable, 150 slots; Sub-vtable 0x005AA6A8 at +0x50) */
    /* +0x010 */ void*     transformNode;  /* CharacterActor = node - 0x65c */
    /* +0x060 */ int32_t   inputForward;   /* Forward/Backward key input (+1=W, -1=S, 0=neutral) */
    /* +0x064 */ int32_t   inputLateral;   /* Lateral key input (+1=D, -1=A, 0=neutral) */
    /* +0x080 */ int32_t   specialAction;  /* Special action flag */
    /* +0x084 */ int32_t   turnInput;      /* Turn direction input */
    /* +0x088 */ int32_t   pitchInput;     /* Pitch direction input */
    /* +0x0A8 */ void*     bspCollision;   /* BSP query engine (SceneWorld*) */
    /* +0x0AC */ Vector3   contactOffset;  /* Contact alignment position (Normal * -18.0f) */
    /* +0x0B8 */ Vector3   wallNormal;     /* Wall contact plane normal */
    /* +0x0C4 */ Vector3   climbSlideDir;  /* Wall climb tangent slide direction */
    /* +0x0D0 */ Vector3   climbImpulse;   /* Wall climb accumulated impulse */
    /* +0x0D8 */ float     slopeNormalZ;   /* Normal Z component */
    /* +0x0DC */ int32_t   moveState;      /* State machine (0..11, MoveState) */
    /* +0x0E0 */ int32_t   prevMoveState;
    /* +0x0E4 */ int32_t   jumpFlag;       /* Jump phase flag (1=rising, 0=falling/climbing) */
    /* +0x0E8 */ void*     timerObj;       /* General timer object */
    /* +0x0F0 */ void*     jumpTimer;      /* Jump elapsed time tracking (0.1s threshold @ 0x005A8C90) */
    /* +0x138 */ void*     climbTimer;     /* Wall climb timer (1.8s max duration @ 0x005AA8F0) */
    /* +0x1D0 */ Vector3   velocity;       /* Primary linear velocity */
    /* +0x348 */ void*     animController; /* Animation state machine controller (0x005AAC50) */
    /* +0x34C */ int32_t   combatLocked;   /* Attack / skill hard lock */
    /* +0x35C */ int32_t   onSlope;        /* Walkable ground slope flag */
    /* +0x360 */ int32_t   grounded;       /* Is grounded */
    /* +0x368 */ int32_t   climbHitFlags;  /* Wall climb collision flags */
    /* +0x370 */ int32_t   landingFlag;    /* Landing state flag */
    /* +0x390 */ Vector3   jumpVelocity;   /* Generated jump velocity */
    /* +0x398 */ float     jumpForceY;     /* Vertical jump velocity scalar (375.0f vs 282.0f) */
    /* +0x39C */ Vector3   lastContactNrm; /* Latest collision surface normal */
    /* +0x3C8 */ uint32_t  contactBits;    /* Contact axis bitmask */
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

/**
 * @brief Select four-directional jump pose from player inputs (vtable[46] at 0x004CF770)
 * @param inputForward Forward/Backward input (+1, 0, -1)
 * @param inputLateral Left/Right input (+1, 0, -1)
 * @return QinggongPose ID (151, 153, 155, or 157)
 */
int Meteor_Player_SelectJumpPose(int inputForward, int inputLateral);

/**
 * @brief Transition jump pose to paired falling pose (vtable[47] at 0x004CF7D0)
 * @param currentPose Current jump animation pose ID
 * @return Paired falling pose ID (152, 154, 156, or 158)
 */
int Meteor_Player_UpdateJumpPoseTransition(int currentPose);

/**
 * @brief Wall climb & wall run detection and initiation (vtable[50] at 0x004CCCB0)
 * @param self Pointer to PlayerController
 * @return 1 if wall climb successfully triggered, 0 otherwise
 */
int __thiscall Meteor_Player_CheckAndTriggerWallClimb(PlayerController* self);

/**
 * @brief Map active wall climb pose to corresponding wall kick pose (vtable[53] at 0x004CCC70)
 * @param self Pointer to PlayerController
 * @return Wall kick animation pose ID (157, 159, 160, or default 151)
 */
int __thiscall Meteor_Player_GetWallKickPose(PlayerController* self);

/**
 * @brief Integrate wall climb dynamics and check slip-off thresholds (vtable[77] at 0x004CD200)
 * @param self Pointer to PlayerController
 * @param dt Delta time
 * @return 0 if wall climb continues, -1 if slipped off/timed out
 */
int __thiscall Meteor_Player_UpdateWallClimbPhysics(PlayerController* self, float dt);

/**
 * @brief Landing pose transition evaluator (vtable[0] of 0x005AAC50 at 0x004DEE40)
 * @param self Pointer to PlayerController
 * @param currentPose Falling pose before ground contact
 * @return Landing pose ID (164 Landing Recovery, 167 Heavy Landing, 213 Break Fall Roll)
 */
int __thiscall Meteor_Player_LandingPoseTransition(PlayerController* self, int currentPose);

#endif /* METEOR_PLAYER_H */
