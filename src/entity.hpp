#pragma once

#include <SDL2/SDL.h>
#include <string>

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Entity{
	int x, y, width, height, speed;

	// Bitmap Path 
	std::string bmloc;	

	SDL_Rect position;
	SDL_Surface *surface;
	SDL_Texture *texture;

public:
	Entity(SDL_Rect position, std::string bmloc, const int speed);

	void create(SDL_Renderer *renderer);
	void destroy();

	void draw(SDL_Renderer *renderer);
	void move(DIRECTION dir);
};
