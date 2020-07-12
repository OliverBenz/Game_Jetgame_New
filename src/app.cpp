#include <error.h>
#include "app.hpp"
#include "definitions.hpp"

App::App(){
	renderFlag = SDL_RENDERER_ACCELERATED;
	windowFlag = 0;

	renderer = nullptr;
	window = nullptr;
}

bool App::init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
		return false;
	}
	
	this->window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlag);
	if(! this->window){
		fprintf(stderr, "Could not open window: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(this->window, -1, renderFlag);
	if(! renderer){
		fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
		return false;
	}

	// Create Background
	this->background = SDL_LoadBMP(BM_BACKGROUND);
	this->texture = SDL_CreateTextureFromSurface(renderer, background);
	
	// Create LeftWin Background
	this->lwSurface = SDL_LoadBMP(BM_LEFTWIN);
	this->lwTexture = SDL_CreateTextureFromSurface(renderer, lwSurface);

	// Create RightWin Background
	this->rwSurface = SDL_LoadBMP(BM_RIGHTWIN);
	this->rwTexture = SDL_CreateTextureFromSurface(renderer, rwSurface);

	return true;
}

void App::drawBackground(){
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void App::drawLeftWin(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, lwTexture, NULL, NULL);
}

void App::drawRightWin(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, rwTexture, NULL, NULL);
}

void App::destroy(){
	// Destroy Background
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(background);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

SDL_Renderer* App::getRenderer(){
	return renderer;
}

SDL_Window* App::getWindow(){
	return window;
}
