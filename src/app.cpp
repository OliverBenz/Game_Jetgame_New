#include "app.hpp"
#include "definitions.hpp"

App::App(){
	renderFlag = SDL_RENDERER_ACCELERATED;
	windowFlag = 0;

	renderer = nullptr;
	window = nullptr;
}

int App::init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	
	this->window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlag);
	if(! this->window){
		fprintf(stderr, "Could not open window: %s\n", SDL_GetError());
		return -1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	this->renderer = SDL_CreateRenderer(this->window, -1, renderFlag);
	if(! this->renderer){
		fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
		return -1;
	}
	return 1;
}

void App::destroy(){
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

SDL_Renderer* App::getRenderer(){
	return this->renderer;
}

SDL_Window* App::getWindow(){
	return this->window;
}
