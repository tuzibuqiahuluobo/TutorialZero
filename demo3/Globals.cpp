#include "Globals.h"
#include "Atlas.h"

bool Running = true;
bool is_game_started = false;

Atlas* atlas_player_left;
Atlas* atlas_player_right;
Atlas* atlas_enemy_left;
Atlas* atlas_enemy_right;

//¹Ì¶¨´°¿Ú
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

const int BUTTON_WIDTH = 192;
const int BUTTON_HEIGHT = 75;