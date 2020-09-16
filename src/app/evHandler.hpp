#pragma once

#include <SDL2/SDL.h>

class EventHandler{
	SDL_Event event;

public:
	void handle();
};
