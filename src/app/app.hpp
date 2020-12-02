#pragma once

#include <SDL2/SDL.h>
#include "../globals.hpp"

class App{
	const int renderFlag = SDL_RENDERER_ACCELERATED;
	const int windowFlag = 0;

	//SDL_Renderer* renderer = nullptr;
	SDL_Window *window = nullptr;

	// Background Bitmap
	SDL_Surface *background; 
	SDL_Texture *texture;

	// LeftWin Bitmap
	SDL_Surface *lwSurface;
	SDL_Texture *lwTexture;

	// RightWin Bitmap
	SDL_Surface *rwSurface;
	SDL_Texture *rwTexture;	

public:
	// Initialize SDL
	App();

	bool init();
	void destroy();

	void drawBackground();
	void drawLeftWin();
	void drawRightWin();

	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

};
