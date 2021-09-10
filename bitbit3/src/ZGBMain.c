#include "ZGBMain.h"

UINT8 next_state = StateMenu;

extern UINT8* tile_replacement_tile_ptr;
extern UINT8* tile_replacement_ptr;
extern UINT8  tile_replacement_enemy_type;

void GetTileReplacement() {
	if(current_state == StateGame) {
		*tile_replacement_ptr = 0;
		switch(*tile_replacement_tile_ptr) {
				case 54: tile_replacement_enemy_type = SpriteZurrapa; return;
				case 55: tile_replacement_enemy_type = SpriteAznar; return;
				case 60: tile_replacement_enemy_type = SpriteFlag; return;
		}
	}

	tile_replacement_enemy_type = 255u;
	*tile_replacement_ptr = *tile_replacement_tile_ptr;
}