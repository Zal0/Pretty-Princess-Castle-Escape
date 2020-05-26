#include "Banks/SetBank2.h"
#include "main.h"

#include "SpriteManager.h"

const UINT8 anim_explosion[] = {6, 0, 1, 2, 3, 4, 5};

void Start_SpriteParticle() {
	SetSpriteAnim(THIS, anim_explosion, 5u);
	THIS->anim_speed = 33u;
}

void Update_SpriteParticle() {
	if(THIS->anim_frame == 5) {
		SpriteManagerRemove(THIS_IDX);
	}
}

void Destroy_SpriteParticle() {
}