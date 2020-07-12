#pragma once 

#include <SDL2/SDL.h>
#include "player.hpp"

enum GAMESTATE{
    GS_Menu,
    GS_Main,
    GS_Winscreen,
    GS_End
};
extern GAMESTATE gameState;

extern Player player1;
extern Player player2;

extern DIRECTION winner;

extern SDL_Renderer *renderer;