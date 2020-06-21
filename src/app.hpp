#pragma once

#include <SDL2/SDL.h>
#include "player.hpp"

extern Player player1;
extern bool endProgram;

class App{
	int renderFlag, windowFlag;	

	SDL_Renderer *renderer;
	SDL_Window *window;

public:
	// Initialize SDL
	App();

	int init();
	void destroy();

	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

};
