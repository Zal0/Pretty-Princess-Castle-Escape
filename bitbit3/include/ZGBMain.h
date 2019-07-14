#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES           \
_STATE(STATE_DISCLAIMER) \
_STATE(STATE_MENU)       \
_STATE(STATE_GAME)       \
_STATE(STATE_GAME_OVER)  \
_STATE(STATE_WIN)        \
_STATE(STATE_TESTS)      \
STATE_DEF_END

#define SPRITES \
_SPRITE_COLOR(SPRITE_PRINCESS, princess,  2, FRAME_16x16, 10) \
_SPRITE_COLOR(SPRITE_ZURRAPA,  zurrapa,   0, FRAME_16x16,  2) \
_SPRITE_COLOR(SPRITE_PARTICLE, particles, 2, FRAME_16x16,  6) \
_SPRITE_COLOR(SPRITE_AXE,      princess,  2, FRAME_16x16, 10) \
_SPRITE_COLOR(SPRITE_AZNAR,    aznar,     2, FRAME_16x16,  5) \
_SPRITE_COLOR(SPRITE_FLAG,     flag,      0, FRAME_16x16,  2) \
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif
