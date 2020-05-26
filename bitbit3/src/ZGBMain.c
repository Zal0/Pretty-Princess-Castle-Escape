#include "ZGBMain.h"

UINT8 next_state = StateMenu;

UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == StateGame) {
		*tile = 0;
		switch(*tile_ptr) {
				case 54: return SpriteZurrapa;
				case 55: return SpriteAznar;
				case 60: return SpriteFlag;
		}
		*tile = *tile_ptr;
	}
	return 255u;
}