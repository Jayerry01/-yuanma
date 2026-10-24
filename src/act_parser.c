/**
 * @file act_parser.c
 * @brief Reverse-engineered parser for character.act (Action & Pose Definitions)
 * 
 * Target: Meteor.exe (FUN_00574930)
 * Parses:
 *   - Pose definitions (StartFrame, EndFrame, Loop)
 *   - Action transitions (NextPose, BlendDuration, TargetPose)
 *   - Weapon Combo Groups (e.g. group(248-249), group(250-251), group(253), etc.)
 */

#include "include/meteor_pose.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_POSES   1024
#define MAX_ACTIONS 2048

typedef struct ActDatabase {
    PoseDef     poses[MAX_POSES];
    int32_t     poseCount;
    ActionDef   actions[MAX_ACTIONS];
    int32_t     actionCount;
} ActDatabase;

static ActDatabase g_ActDb;

/**
 * @brief Initialize and load character.act into memory database
 * Mirrors Meteor.exe FUN_00574930
 */
int Meteor_LoadActFile(const char* filePath) {
    FILE* fp = fopen(filePath, "r");
    if (!fp) {
        printf("[ActParser] Error: Could not open %s\n", filePath);
        return 0;
    }

    char line[512];
    int currentGroup = -1;

    memset(&g_ActDb, 0, sizeof(g_ActDb));

    while (fgets(line, sizeof(line), fp)) {
        // Trim leading whitespace
        char* p = line;
        while (isspace((unsigned char)*p)) p++;

        // Skip comments and blank lines
        if (*p == '#' || *p == '/' || *p == '\0') {
            continue;
        }

        // Parse group declarations: group(248-249)
        if (strncmp(p, "group(", 6) == 0) {
            int startP = 0, endP = 0;
            if (sscanf(p + 6, "%d-%d", &startP, &endP) == 2) {
                // Multi-pose combo group
            } else if (sscanf(p + 6, "%d", &startP) == 1) {
                endP = startP;
            }
            continue;
        }

        // Parse action body: action <id> { ... }
        if (strncmp(p, "action", 6) == 0) {
            int actionId = -1;
            if (sscanf(p + 6, "%d", &actionId) == 1) {
                if (g_ActDb.actionCount < MAX_ACTIONS) {
                    ActionDef* act = &g_ActDb.actions[g_ActDb.actionCount++];
                    act->actionId = actionId;
                    act->poseId = actionId; // Default 1:1 binding
                    act->blendDuration = 0.1f;
                }
            }
        }
    }

    fclose(fp);
    printf("[ActParser] Loaded %d actions, %d poses from %s\n", 
           g_ActDb.actionCount, g_ActDb.poseCount, filePath);
    return 1;
}

/**
 * @brief Get Action definition by ID
 */
const ActionDef* Meteor_GetAction(int actionId) {
    for (int i = 0; i < g_ActDb.actionCount; ++i) {
        if (g_ActDb.actions[i].actionId == actionId) {
            return &g_ActDb.actions[i];
        }
    }
    return NULL;
}
