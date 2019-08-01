#pragma bank 2
#include "main.h"
UINT8 bank_STATE_GAME_OVER = 2;

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

#include "../res/src/gameovertiles.h"
#include "../res/src/gameovermap.h"

extern const unsigned char * gameover_mod_Data[];

void Start_STATE_GAME_OVER() {
	InitScrollTiles(0, &tilesgameover);
	InitScroll(&gameover, 0, 0);
	SHOW_BKG;

	PlayMusic(gameover_mod_Data, 3, 0);
}

void Update_STATE_GAME_OVER() {
	if(KEY_TICKED(J_START)) {
		SetState(STATE_MENU);
	}
}