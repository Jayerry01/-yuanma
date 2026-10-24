/**
 * @file game_app.c
 * @brief Reverse-engineered GameApp main loop & configuration loader
 * 
 * Target: Meteor.exe (FUN_00486610, FUN_0048AC50, FUN_0045D730)
 * Global Instance: 0x006659B8 (sizeof: 0x2970)
 */

#include "include/meteor_app.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static GameApp* g_LocalGameApp = NULL;

/**
 * @brief Allocate and initialize the GameApp singleton
 * Decompiled from Meteor.exe @ 0x00487830 & 0x00486610
 */
GameApp* Meteor_CreateGameApp(void) {
    if (g_LocalGameApp != NULL) {
        return g_LocalGameApp;
    }

    g_LocalGameApp = (GameApp*)calloc(1, METEOR_GAMEAPP_SIZE);
    if (!g_LocalGameApp) return NULL;

    // Set default debug flags
    g_LocalGameApp->showPositionFlag = 0; // +0x2474
    g_LocalGameApp->showStatusFlag   = 0; // +0x2478

    printf("[GameApp] Initialized GameApp instance at %p (size: 0x%X)\n", 
           (void*)g_LocalGameApp, METEOR_GAMEAPP_SIZE);
    return g_LocalGameApp;
}

/**
 * @brief Parse user.cfg / config.ini parameters
 * Decompiled from Meteor.exe @ 0x0045D730 (FUN_0045d730)
 */
int Meteor_ParseConfigKey(GameConfig* cfg, const char* key, const char* value) {
    if (!cfg || !key || !value) return 0;

    int intVal = atoi(value);
    float floatVal = (float)atof(value);

    if (strcmp(key, "favourite") == 0) {
        cfg->favourite = intVal;
    } else if (strcmp(key, "user_name") == 0) {
        strncpy(cfg->userName, value, sizeof(cfg->userName) - 1);
    } else if (strcmp(key, "s_width") == 0) {
        cfg->screenWidth = intVal;
    } else if (strcmp(key, "s_heigth") == 0) {
        cfg->screenHeight = intVal;
    } else if (strcmp(key, "mousespeed") == 0) {
        cfg->mouseSpeed = floatVal;
    } else if (strcmp(key, "AudioVolume") == 0) {
        cfg->audioVolume = intVal;
    } else if (strcmp(key, "MusicVolume") == 0) {
        cfg->musicVolume = intVal;
    } else if (strcmp(key, "FORWARD") == 0) {
        cfg->keyForward = intVal;
    } else if (strcmp(key, "BACKWARD") == 0) {
        cfg->keyBackward = intVal;
    } else if (strcmp(key, "LEFTSTEP") == 0) {
        cfg->keyLeft = intVal;
    } else if (strcmp(key, "RIGHTSTEP") == 0) {
        cfg->keyRight = intVal;
    } else if (strcmp(key, "ATTACK") == 0) {
        cfg->keyAttack = intVal;
    } else if (strcmp(key, "GUARD") == 0) {
        cfg->keyGuard = intVal;
    } else if (strcmp(key, "SWITCHWEAPON") == 0) {
        cfg->keySwitchWeapon = intVal;
    } else if (strcmp(key, "DROPWEAPON") == 0) {
        cfg->keyDropWeapon = intVal;
    }

    return 1;
}

/**
 * @brief Per-frame simulation tick
 * Decompiled from Meteor.exe @ 0x0048B640
 */
void Meteor_GameApp_Update(GameApp* app, float deltaTime) {
    if (!app) return;

    // 1. Process local player input & physics
    if (app->localPlayer) {
        Meteor_Player_ProcessPhysics(app->localPlayer);
    }

    // 2. Scene collision & particle updates
    // ...
}
