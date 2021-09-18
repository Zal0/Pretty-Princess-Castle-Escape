#include "Banks/SetAutoBank.h"
#include "main.h"

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "Music.h"

IMPORT_MAP(winmap);

DECLARE_MUSIC(gameover);

void START() {
	InitScroll(BANK(winmap), &winmap, 0, 0);

	PlayMusic(gameover, 0);
}

void UPDATE() {
	if(KEY_TICKED(J_START)) {
		SetState(StateMenu);
	}
}