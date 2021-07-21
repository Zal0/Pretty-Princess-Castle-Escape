#include "Banks/SetBank2.h"
#include "main.h"

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "Music.h"

#include "../res/src/winmap.h"
#include "../res/src/splashtiles.h"

#include "Palette.h"
const UINT16 bgPALWin[] = {PALETTE_FROM_HEADER(splashtiles)};

DECLARE_MUSIC(gameover);

void Start_StateWin() {
	SetPalette(BG_PALETTE, 0, 8, bgPALWin, bank_StateWin);

	InitScroll(&winmap, 0, 0);
	SHOW_BKG;

	PlayMusic(gameover, 0);
}

void Update_StateWin() {
	if(KEY_TICKED(J_START)) {
		SetState(StateMenu);
	}
}