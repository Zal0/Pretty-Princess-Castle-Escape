#include "Banks/SetAutoBank.h"
#include "main.h"

#include <gb/gb.h>
#include "ZGBMain.h"
#include "Scroll.h"
#include "Keys.h"
#include "Music.h"

IMPORT_MAP(splashmap);
DECLARE_MUSIC(start);

extern UINT8 level;
extern UINT16 reset_x;
extern UINT16 reset_y;

void Start_StateMenu() {
	InitScroll(BANK(splashmap), &splashmap, 0, 0);
	SHOW_BKG;

	level = 0;
	
	PlayMusic(start, 1);
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