#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "player.hpp"
#include "bullet.hpp"

extern Player player1;
extern Player player2;
extern bool endProgram;

class App{
	int renderFlag, windowFlag;	

	// Background Bitmap
	SDL_Surface *background; 
	SDL_Texture *texture;
	
	SDL_Renderer *renderer;
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
