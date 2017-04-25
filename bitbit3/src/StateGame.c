#pragma bank=2
#include "StateGame.h"
UINT8 bank_STATE_GAME = 2;

#include "Scroll.h"
#include "Frame.h"
#include "Sprite.h"
#include "Keys.h"
#include "SpriteManager.h"
#include "SpritePrincess.h"
#include "SpriteAznar.h"

#include "../res/src/map.h"
#include "../res/src/map2.h"
#include "../res/src/tilemap.h"

#include "BitBit3.h"
#include "gbt_player.h"

#include "Palette.h"
#include "../res/src/princess.h"
#include "../res/src/tilemap.h"
const UINT16 spritesPAL[] = {PALETTE_FROM_HEADER(princess)};
const UINT16 bgPAL[] = {PALETTE_FROM_HEADER(tilemap)};


extern const unsigned char * level_mod_Data[];

const UINT8 collision_tiles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 47, 48, 53, 56, 57, 58, 59, 0};

UINT16 reset_x;
UINT16 reset_y;
UINT8 level;

struct Sprite* game_over_particle;

extern UINT8 spriteIdxs[];
void SpriteManagerLoadSubsprite(UINT8 sprite_type, UINT8 sprite_type_source) {
	spriteIdxs[sprite_type] = spriteIdxs[sprite_type_source];
}

void Start_STATE_GAME() {
	struct Sprite* princess_sprite;

	game_over_particle = 0;

	SPRITES_8x16;
	SpriteManagerLoad(SPRITE_PRINCESS);
	SpriteManagerLoadSubsprite(SPRITE_AXE, SPRITE_PRINCESS);
	SpriteManagerLoad(SPRITE_ZURRAPA);
	SpriteManagerLoad(SPRITE_PARTICLE);
	SpriteManagerLoad(SPRITE_AZNAR);
	SpriteManagerLoad(SPRITE_FLAG);
	SHOW_SPRITES;
	
	princess_sprite = SpriteManagerAdd(SPRITE_PRINCESS, reset_x, reset_y);

	InitScrollTilesColor(0, 61, tilemap, 2, tilemapCGB);
	switch(level) {
		case 0:
			InitScroll(level1Width, level1Height, level1 , collision_tiles, 0, 3);
			break;
		case 1:
			InitScroll(level2Width, level2Height, level2, collision_tiles, 0, 3);
			break;
	}
	SHOW_BKG;

	SetPalette(SPRITES_PALETTE, 0, 8, spritesPAL, bank_STATE_GAME);
	SetPalette(BG_PALETTE,      0, 8, bgPAL,      bank_STATE_GAME);

	PlayMusic(level_mod_Data, 3, 1);
}

void Update_STATE_GAME() {
	if(game_over_particle && game_over_particle->current_frame == 5) {
		SetState(STATE_GAME);
	}
}

