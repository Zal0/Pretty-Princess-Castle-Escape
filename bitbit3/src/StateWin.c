#pragma bank 2
#include "main.h"
UINT8 bank_STATE_WIN = 2;

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"

#include "../res/src/winmap.h"
#include "../res/src/splashtiles.h"

#include "Palette.h"
const UINT16 bgPALWin[] = {PALETTE_FROM_HEADER(splashtiles)};


extern const unsigned char * gameover_mod_Data[];

void Start_STATE_WIN() {
	SetPalette(BG_PALETTE, 0, 8, bgPALWin, bank_STATE_WIN);

	InitScrollTilesColor(0, 104, splashtiles, 2);
	InitScroll(winmapWidth, winmapHeight, winmap, 0, 0, 2);
	SHOW_BKG;

	PlayMusic(gameover_mod_Data, 3, 0);
}

void Update_STATE_WIN() {
	if(KEY_TICKED(J_START)) {
		SetState(STATE_MENU);
	}
}