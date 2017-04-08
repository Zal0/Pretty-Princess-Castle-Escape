#include "BitBit3.h"

UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == STATE_GAME) {
		*tile = 0;
		switch(*tile_ptr) {
				case 54: return SPRITE_ZURRAPA;
				case 55: return SPRITE_AZNAR;
				case 60: return SPRITE_FLAG;
		}
		*tile = *tile_ptr;
	}
	return 255u;
}