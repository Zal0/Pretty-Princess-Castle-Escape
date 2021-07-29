#include "Banks/SetBank2.h"
#include "main.h"

#include <gb/gb.h>

#include "SpriteManager.h"
#include "ZGBMain.h"

void Start_SpriteAxe() {
	SetFrame(THIS, 9);
}

void Update_SpriteAxe() {
	UINT8 i;
	struct Sprite* spr;
	struct Sprite* spr2;

	for(i = 0u; i != sprite_manager_updatables[0]; ++i) {
		spr = sprite_manager_sprites[sprite_manager_updatables[i + 1u]];
		if(spr->type == SpriteZurrapa || spr->type == SpriteAznar) {
			if(CheckCollision(THIS, spr)) {
				spr2 = SpriteManagerAdd(SpriteParticle, spr->x, spr->y);

				SpriteManagerRemove(i);
			}
		}
	}
}

void Destroy_SpriteAxe() {
}