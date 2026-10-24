#ifndef METEOR_TYPES_H
#define METEOR_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t     BOOL;
typedef uint8_t     BYTE;
typedef uint16_t    WORD;
typedef uint32_t    DWORD;

/* Meteor 3D Vector (Direct3D 7 / Left-Handed, Y-Up) */
typedef struct Vector3 {
    float x;
    float y;
    float z;
} Vector3;

/* 4x4 Transformation Matrix */
typedef struct Matrix4x4 {
    float m[4][4];
} Matrix4x4;

/* Orientation Quaternion */
typedef struct Quaternion {
    float x;
    float y;
    float z;
    float w;
} Quaternion;

/* Axis-Aligned Bounding Box */
typedef struct AABB {
    Vector3 min;
    Vector3 max;
} AABB;

/* Ray for Physics Collision Checking */
typedef struct Ray {
    Vector3 origin;
    Vector3 direction;
    float   length;
} Ray;

/* Movement State Enumeration (MoveState at PlayerController + 0xDC) */
typedef enum MoveState {
    MOVE_STATE_IDLE         = 0,
    MOVE_STATE_GROUND       = 1,
    MOVE_STATE_WALL_CLIMB   = 2,
    MOVE_STATE_RUN          = 3,
    MOVE_STATE_JUMP_ACTION  = 4,
    MOVE_STATE_SLIDE        = 5,
    MOVE_STATE_FALL         = 6,
    MOVE_STATE_ATTACK       = 7,
    MOVE_STATE_HURT         = 8,
    MOVE_STATE_DEFEND       = 9,
    MOVE_STATE_DEAD         = 10,
    MOVE_STATE_RUN_ACCEL    = 11
} MoveState;

/* Weapon Type IDs */
typedef enum WeaponType {
    WEAPON_UNARMED      = 0, // 拳套
    WEAPON_DAGGER       = 1, // 匕首 (Poses 245-259)
    WEAPON_SWORD        = 2, // 长剑 (Poses 200-219)
    WEAPON_BLADE        = 3, // 大刀
    WEAPON_SPEAR        = 4, // 长枪
    WEAPON_HAMMER       = 5, // 大锤
    WEAPON_DUAL_BLADES  = 6, // 双刺
    WEAPON_STAFF        = 7, // 乾坤玄铁棍
    WEAPON_KATANA       = 8, // 忍刀
    WEAPON_GAUNTLET     = 9  // 指虎
} WeaponType;

#ifdef __cplusplus
}
#endif

#endif /* METEOR_TYPES_H */
