#pragma once

#include <SDL2/SDL.h>
#include "globals.hpp"

class App{
	int renderFlag, windowFlag;	

	// Background Bitmap
	SDL_Surface *background; 
	SDL_Texture *texture;
	
	SDL_Window *window;

public:
	// Initialize SDL
	App();

	bool init();
	void destroy();

	void drawBackground();

	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

};
