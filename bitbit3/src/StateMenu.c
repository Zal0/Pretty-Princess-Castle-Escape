#pragma bank 2
#include "main.h"
UINT8 bank_STATE_MENU = 2;

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

#include "../res/src/splash.h"
#include "../res/src/splashtiles.h"

extern const unsigned char * start_mod_Data[];

extern UINT8 level;
extern UINT16 reset_x;
extern UINT16 reset_y;

#include "Palette.h"
const UINT16 bgPALMenu[] = {PALETTE_FROM_HEADER(splashtiles)};

void Start_STATE_MENU() {
	SetPalette(BG_PALETTE, 0, 8, bgPALMenu, bank_STATE_MENU);

	InitScrollTiles(0, &splashtiles);
	InitScroll(&splashmap, 0, 0);
	SHOW_BKG;

	level = 0;
	PlayMusic(start_mod_Data, 2, 1);
}

void Update_STATE_MENU() {
	if(KEY_TICKED(J_START)) {
		reset_x = 32;
		reset_y = 112;
		SetState(STATE_GAME);
	}

	/*if(KEY_TICKED(J_UP)) {
		level = 0;
	}
	if(KEY_TICKED(J_DOWN)) {
		level = 1;
	}*/
}