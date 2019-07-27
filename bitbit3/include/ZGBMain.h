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
_SPRITE_COLOR(SPRITE_PRINCESS, princess ) \
_SPRITE_COLOR(SPRITE_ZURRAPA,  zurrapa  ) \
_SPRITE_COLOR(SPRITE_PARTICLE, particles) \
_SPRITE_COLOR(SPRITE_AXE,      princess ) \
_SPRITE_COLOR(SPRITE_AZNAR,    aznar    ) \
_SPRITE_COLOR(SPRITE_FLAG,     flag     ) \
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif
