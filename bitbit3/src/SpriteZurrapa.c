#include "Banks/SetAutoBank.h"
#include "main.h"

#include <gb/gb.h>

#include "Scroll.h"
#include "SpriteManager.h"

const UINT8 anim_zurrapa_idle[] = {2, 0, 1};

void START() {
	SetSpriteAnim(THIS, anim_zurrapa_idle, 5u);
}

void UPDATE() {
	
}

void DESTROY() {
}