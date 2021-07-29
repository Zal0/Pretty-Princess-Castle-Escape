#include "Banks/SetBank2.h"
#include "main.h"

#include "gb/gb.h"

#include "ZGBMain.h"
#include "Sprite.h"
#include "Keys.h"
#include "Scroll.h"
#include "SpriteManager.h"

//#define DEBUG_CONTROLS

//Princes anims
const UINT8 anim_walk[] = {12, 0, 1, 2, 3, 2, 1, 0, 4, 5, 6, 5, 4};
const UINT8 anim_idle[] = {4, 0, 0, 0, 7};
const UINT8 anim_jump[] = {1, 6};
const UINT8 anim_fire[] = {2, 8, 8};

typedef enum  {
	PRINCESS_STATE_NORMAL,
	PRINCESS_STATE_JUMPING,
	PRINCESS_STATE_FIRE
}PRINCESS_STATE;
PRINCESS_STATE princes_state;
INT16 princess_accel_y;

struct Sprite* axe_sprite;

extern struct Sprite* game_over_particle;

extern UINT16 reset_x;
extern UINT16 reset_y;
extern UINT8 level;

void Start_SpritePrincess() {
	SetSpriteAnim(THIS, anim_idle, 3u);
	//THIS->coll_x += 4u;
	//THIS->coll_w -= 8u;
	//THIS->coll_y += 2u;
	//THIS->coll_h -= 2u;

	princess_accel_y = 0;

	scroll_target = THIS;

	princes_state = PRINCESS_STATE_NORMAL;

	axe_sprite = 0;
}

void Die(struct Sprite* sprite, UINT8 idx) {
	SpriteManagerRemove(idx);
	game_over_particle = SpriteManagerAdd(SpriteParticle, sprite->x, sprite->y);
	scroll_target = 0;
}

UINT8 tile_collision;
void CheckCollisionTile(struct Sprite* sprite, UINT8 idx) {
	if(tile_collision == 33u) {
		Die(sprite, idx);
	} else if(tile_collision == 53u) {
		if(level == 1) {
			SetState(StateWin);
		} else {
			level ++;
			reset_x = 32;
			reset_y = 112;
			SetState(StateGame);
		}
	}
}

void MovePrincess(struct Sprite* sprite, UINT8 idx) {
	if(KEY_PRESSED(J_RIGHT)) {
		tile_collision = TranslateSprite(sprite, 1 << delta_time, 0);
		THIS->mirror = NO_MIRROR;
		CheckCollisionTile(sprite, idx);
	} else if(KEY_PRESSED(J_LEFT)) {
		tile_collision = TranslateSprite(sprite, -1 << delta_time, 0);
		THIS->mirror = V_MIRROR;
		CheckCollisionTile(sprite, idx);
	}
	
#ifdef DEBUG_CONTROLS
	if(KEY_PRESSED(J_UP)) {
		tile_collision = TranslateSprite(sprite, 0, -1 << delta_time);
		CheckCollisionTile(sprite, idx);
	} else if(KEY_PRESSED(J_DOWN)) {
		tile_collision = TranslateSprite(sprite, 0, 1 << delta_time);
		CheckCollisionTile(sprite, idx);
	}
#endif
}

void UpdateAxePos() {
	axe_sprite->mirror = THIS->mirror;
	if(THIS->mirror == V_MIRROR) 
		axe_sprite->x = THIS->x - 16u;
	else
		axe_sprite->x = THIS->x + 16u; 
	axe_sprite->y = THIS->y;
}

#include <gb/bgb_emu.h>
void Update_SpritePrincess() {
	UINT8 i;
	struct Sprite* spr;

	switch(princes_state) {
		case PRINCESS_STATE_NORMAL:
			MovePrincess(THIS, THIS_IDX);
	
			//Choose idle anim or walk
			if(KEY_PRESSED(J_RIGHT) || KEY_PRESSED(J_LEFT) ) {
				SetSpriteAnim(THIS, anim_walk, 33u);
			} else {
				SetSpriteAnim(THIS, anim_idle, 3u);
			}

			//Check jumping
			if(KEY_TICKED(J_A)) {
				princess_accel_y = -50;
				princes_state = PRINCESS_STATE_JUMPING;
			} 

			//Check falling
			if((princess_accel_y >> 4) > 1) {
				princes_state = PRINCESS_STATE_JUMPING;
			}
			break;

		case PRINCESS_STATE_JUMPING:
			SetSpriteAnim(THIS, anim_jump, 33u);
			MovePrincess(THIS, THIS_IDX);
			break;

		case PRINCESS_STATE_FIRE:
			if(THIS->anim_frame == 1) {
				princes_state = PRINCESS_STATE_NORMAL;
				SpriteManagerRemoveSprite(axe_sprite);
			} else {
				MovePrincess(THIS, THIS_IDX);
				UpdateAxePos();
			}
			break;
	}

#ifndef DEBUG_CONTROLS
	//Simple gravity physics 
	if(princess_accel_y < 40) {
		princess_accel_y += 2;
	}
	tile_collision = TranslateSprite(THIS, 0, princess_accel_y >> 4);
	if(!tile_collision && delta_time != 0 && princess_accel_y < 40) { //Do another iteration if there is no collision
			princess_accel_y += 2;
			tile_collision = TranslateSprite(THIS, 0, princess_accel_y >> 4);
	}
	if(tile_collision) {
		princess_accel_y = 0;
		if(princes_state == PRINCESS_STATE_JUMPING) {
			princes_state = PRINCESS_STATE_NORMAL;
		}

		CheckCollisionTile(THIS, THIS_IDX);
	}
#endif

BGB_PROFILE_BEGIN();
	//Check enemy collision
	for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
		spr = sprite_manager_sprites[sprite_manager_updatables[i + 1u]];
		if(spr->type == SpriteZurrapa || spr->type == SpriteAznar) {
			if(CheckCollision(THIS, spr)) {
				Die(THIS, THIS_IDX);
			}
		} else if(spr->type == SpriteFlag) {
			if(CheckCollision(THIS, spr)) {
				reset_x = spr->x;
				reset_y = spr->y + 2;
			}
		}
	}
BGB_PROFILE_END(Coll);

	if(KEY_TICKED(J_B) && princes_state != PRINCESS_STATE_FIRE) {
		SetSpriteAnim(THIS, anim_fire, 15u);
		princes_state = PRINCESS_STATE_FIRE;

		axe_sprite = SpriteManagerAdd(SpriteAxe, THIS->x, THIS->y);
		UpdateAxePos();
	}


	/*if(KEY_TICKED(J_B) ) {
		sprite_test = SpriteManagerAdd(SpriteZurrapa, THIS->x, THIS->y);
	}*/
}

void Destroy_SpritePrincess() {
}
