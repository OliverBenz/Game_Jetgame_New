#pragma once 

#include <SDL2/SDL.h>
#include "player.hpp"

enum GAMESTATE{
    GS_Titlescreen,
    GS_Main,
    GS_Winscreen
};
extern GAMESTATE gameState;

extern Player player1;
extern Player player2;

extern bool endProgram;
extern DIRECTION winner;

extern SDL_Renderer *renderer;
