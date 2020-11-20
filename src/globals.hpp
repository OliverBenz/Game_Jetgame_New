#pragma once 

#include <SDL2/SDL.h>
#include "actors/player.hpp"

extern enum class GAMESTATE{
    GS_Menu,        // Menu screen
    GS_Main,        // In game
    GS_Winscreen,   // Player won
    GS_Reset,       // Resetting game
    GS_End          // Exit application
} gameState;

extern Player player1;
extern Player player2;

extern DIRECTION winner;

extern SDL_Renderer *renderer;  // Destroyed in app class
