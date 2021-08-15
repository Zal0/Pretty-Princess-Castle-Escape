#include "Banks/SetBank2.h"
#include "main.h"

#include "Scroll.h"
#include "Sprite.h"
#include "Keys.h"
#include "SpriteManager.h"

IMPORT_MAP(level1);
IMPORT_MAP(level2);

#include "ZGBMain.h"
#include "Music.h"

#include "Palette.h"

DECLARE_MUSIC(level);

const UINT8 collision_tiles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 47, 48, 53, 56, 57, 58, 59, 0};

UINT16 reset_x;
UINT16 reset_y;
UINT8 level;

struct Sprite* game_over_particle;

extern UINT8 spriteIdxs[];
void SpriteManagerLoadSubsprite(UINT8 sprite_type, UINT8 sprite_type_source) {
	spriteIdxs[sprite_type] = spriteIdxs[sprite_type_source];
}

void Start_StateGame() {
	struct Sprite* princess_sprite;

	game_over_particle = 0;

	SPRITES_8x16;
	SpriteManagerLoad(SpritePrincess);
	SpriteManagerLoadSubsprite(SpriteAxe, SpritePrincess);
	SpriteManagerLoad(SpriteZurrapa);
	SpriteManagerLoad(SpriteParticle);
	SpriteManagerLoad(SpriteAznar);
	SpriteManagerLoad(SpriteFlag);
	SHOW_SPRITES;
	
	princess_sprite = SpriteManagerAdd(SpritePrincess, reset_x, reset_y + 2);

	switch(level) {
		case 0:
			InitScroll(BANK(level1), &level1, collision_tiles, 0);
			break;
		case 1:
			InitScroll(BANK(level2), &level2, collision_tiles, 0);
			break;
	}
	SHOW_BKG;

#ifdef CGB
	if(_cpu != CGB_TYPE)
#endif
		BGP_REG = PAL_DEF(0, 1, 2, 0);

	PlayMusic(level, 1);
}

void Update_StateGame() {
	if(game_over_particle && game_over_particle->anim_frame == 5) {
		SetState(StateGame);
	}
}

