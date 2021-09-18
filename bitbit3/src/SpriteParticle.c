#include "Banks/SetAutoBank.h"
#include "main.h"

#include "SpriteManager.h"

const UINT8 anim_explosion[] = {6, 0, 1, 2, 3, 4, 5};

void START() {
	SetSpriteAnim(THIS, anim_explosion, 5u);
	THIS->anim_speed = 33u;
}

void UPDATE() {
	if(THIS->anim_frame == 5) {
		SpriteManagerRemove(THIS_IDX);
	}
}

void DESTROY() {
}