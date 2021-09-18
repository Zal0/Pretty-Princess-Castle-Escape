#include "Banks/SetAutoBank.h"
#include "main.h"

#include "SpriteManager.h"
#include "Scroll.h"

const UINT8 anim_aznar_walk[] = {8, 0, 1, 2, 3, 4, 3, 2, 1};

void START() {
	SetSpriteAnim(THIS, anim_aznar_walk, 20u);

	//THIS->coll_x += 4;
	//THIS->coll_w -= 8;
	THIS->lim_x = 160u;
	THIS->lim_y = 160u;
}

void UPDATE() {
	if(THIS->mirror == V_MIRROR) {
		//moving left
		if(TranslateSprite(THIS, -1, 0)) {
			THIS->mirror = V_MIRROR;
		} else	if(!scroll_collisions[GetScrollTile((THIS->x >> 3), (THIS->y >> 3) + 2u)]) {
			THIS->mirror = NO_MIRROR;
		}
	} else {
		//moving right
		if(TranslateSprite(THIS, +1, 0)) {
			THIS->mirror = V_MIRROR;
		} else if(!scroll_collisions[GetScrollTile(((THIS->x + THIS->coll_w) >> 3), (THIS->y >> 3) + 2u)]) {
			THIS->mirror = V_MIRROR;
		}
	}
}

void DESTROY() {
}