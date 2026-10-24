#ifndef METEOR_POSE_H
#define METEOR_POSE_H

#include "meteor_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 8-Byte Pose Definition parsed from character.act */
typedef struct PoseDef {
    int16_t startFrame;     // Starting animation frame in character.amb
    int16_t endFrame;       // Ending animation frame
    int16_t loopStart;      // Frame to loop back to (-1 if no loop)
    int16_t flags;          // Bit 0: loop, Bit 1: air only, Bit 2: invincible
} PoseDef;

/* 20-Byte Action Definition parsed from character.act */
typedef struct ActionDef {
    int32_t actionId;       // Unique action identifier
    int32_t poseId;         // Bound animation pose ID
    int32_t nextPoseId;     // Transition pose ID on completion
    float   blendDuration;  // Cross-fade blend time in seconds (e.g. 0.1f)
    int32_t flags;          // Action category (Attack, Hit, Dodge, Idle, etc.)
} ActionDef;

/* Dagger Pose ID Constants (Poses 245-259, 370-371) */
#define DAGGER_POSE_DEFEND_IDLE     245
#define DAGGER_POSE_DEFEND_HIT_L    246
#define DAGGER_POSE_DEFEND_HIT_H    247
#define DAGGER_POSE_ATTACK_1        248 // group(248-249)
#define DAGGER_POSE_ATTACK_2        249
#define DAGGER_POSE_ATTACK_3        250 // group(250-251)
#define DAGGER_POSE_ATTACK_4        251
#define DAGGER_POSE_EQUIP           252
#define DAGGER_POSE_HEAVY_THRUST    253 // group(253)
#define DAGGER_POSE_SPECIAL_SHADOW  255 // group(255) 鬼影迷踪
#define DAGGER_POSE_UNEQUIP         256
#define DAGGER_POSE_BACKSTAB_1      257 // group(257-258) 暗杀背刺
#define DAGGER_POSE_BACKSTAB_2      258
#define DAGGER_POSE_GUARD_BREAK     259 // group(259) 破防斩
#define DAGGER_POSE_AIR_DIVE_START  370 // group(370-371) 碧血凌空
#define DAGGER_POSE_AIR_DIVE_LAND   371

/* Pose Group Descriptor */
typedef struct PoseGroup {
    int32_t groupId;
    int32_t startPose;
    int32_t endPose;
    const char* groupName;
} PoseGroup;

#ifdef __cplusplus
}
#endif

#endif /* METEOR_POSE_H */
