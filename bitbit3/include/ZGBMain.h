#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES           \
_STATE(StateMenu)       \
_STATE(StateGame)       \
_STATE(StateGameOver)  \
_STATE(StateWin)        \
STATE_DEF_END

#define SPRITES \
_SPRITE_COLOR(SpritePrincess, princess ) \
_SPRITE_COLOR(SpriteZurrapa,  zurrapa  ) \
_SPRITE_COLOR(SpriteParticle, particles) \
_SPRITE_COLOR(SpriteAxe,      princess ) \
_SPRITE_COLOR(SpriteAznar,    aznar    ) \
_SPRITE_COLOR(SpriteFlag,     flag     ) \
SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif
