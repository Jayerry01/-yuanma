#ifndef METEOR_APP_H
#define METEOR_APP_H

#include "meteor_types.h"
#include "meteor_player.h"

#ifdef __cplusplus
extern "C" {
#endif

#define METEOR_GLOBAL_GAMEAPP_PTR   0x006659B8
#define METEOR_GAMEAPP_SIZE         0x2970
#define METEOR_GAMEAPP_VTBL         0x005A9068

/* User Configuration structure (parsed by FUN_0045D730) */
typedef struct GameConfig {
    int32_t favourite;          // +0x094: Character model index
    char    userName[24];       // +0x098: Player screen name
    int32_t texQuality;         // +0x0AC: Texture resolution (0, 1, 2)
    int32_t screenWidth;        // +0x0B0: Resolution width (e.g. 800, 1024)
    int32_t screenHeight;       // +0x0B4: Resolution height (e.g. 600, 768)
    int32_t highAudio;          // +0x0B8: High quality audio flag
    int32_t cdMusic;            // +0x0C0: CD/MIDI music toggle
    int32_t autoCamera;         // +0x0C4: Smart camera assist
    int32_t autoLock;           // +0x0C8: Target auto-lock
    int32_t lockFlag;           // +0x0CC: Lock target marker display
    int32_t showName;           // +0x0D0: Display player HUD name
    int32_t reverseMouse;       // +0x0D4: Invert Y mouse axis
    int32_t dragMouse;          // +0x0D8: Smooth camera drag
    float   mouseSpeed;         // +0x0DC: Mouse sensitivity scale
    int32_t audioVolume;        // +0x160: SFX volume (0-100)
    int32_t musicVolume;        // +0x164: BGM volume (0-100)
    int32_t keyForward;         // Key 'W' (0x57)
    int32_t keyBackward;        // Key 'S' (0x53)
    int32_t keyLeft;            // Key 'A' (0x41)
    int32_t keyRight;           // Key 'D' (0x44)
    int32_t keyAttack;          // Mouse Left Click (0x1000)
    int32_t keyGuard;           // Key Space (0x20)
    int32_t keySwitchWeapon;    // Key 'E' (0x45)
    int32_t keyDropWeapon;      // Key 'G' (0x47)
} GameConfig;

/* Main Game Application Object (0x2970 bytes) */
typedef struct GameApp {
    void*               vptr;               // +0x0000: VTable ptr (0x005A9068)
    uint8_t             pad_0004[0x2470];   // +0x0004: Direct3D device, sound, timer
    int32_t             showPositionFlag;   // +0x2474: HUD debug coordinate toggle
    int32_t             showStatusFlag;     // +0x2478: HUD debug status toggle
    uint8_t             pad_247C[0x01B0];   // +0x247C: UI state, scene world
    PlayerController*   localPlayer;        // +0x262C: Local human player controller
    uint8_t             pad_2630[0x0340];   // +0x2630: Network lobby, peers
} GameApp;

/* Access Global GameApp Singleton */
static inline GameApp* Meteor_GetGameApp(void) {
    return *(GameApp**)METEOR_GLOBAL_GAMEAPP_PTR;
}

#ifdef __cplusplus
}
#endif

#endif /* METEOR_APP_H */
