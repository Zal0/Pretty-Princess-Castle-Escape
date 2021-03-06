#include "Banks/SetBank2.h"
#include "main.h"

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

void Start_StateMenu() {
	SetPalette(BG_PALETTE, 0, 8, bgPALMenu, bank_StateMenu);

	InitScroll(&splashmap, 0, 0);
	SHOW_BKG;

	level = 0;
	PlayMusic(start_mod_Data, 2, 1);
}

void Update_StateMenu() {
	if(KEY_TICKED(J_START)) {
		reset_x = 32;
		reset_y = 112;
		SetState(StateGame);
	}

	/*if(KEY_TICKED(J_UP)) {
		level = 0;
	}
	if(KEY_TICKED(J_DOWN)) {
		level = 1;
	}*/
}