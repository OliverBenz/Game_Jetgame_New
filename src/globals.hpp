#pragma once 

#include <SDL2/SDL.h>
#include "player.hpp"

enum GAMESTATE{
    GS_Menu,        // Menu screen
    GS_Main,        // In game
    GS_Winscreen,   // Player won
    GS_Reset,       // Resetting game
    GS_End          // Exit application
};
extern GAMESTATE gameState;

extern Player player1;
extern Player player2;

extern DIRECTION winner;

extern SDL_Renderer *renderer;