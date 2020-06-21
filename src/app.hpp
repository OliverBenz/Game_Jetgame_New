#pragma once

#include <SDL2/SDL.h>

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
