#pragma once

#include <SDL2/SDL.h>

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Entity{
	int x, y, width, height;
	const int speed = 8;
	
	SDL_Rect position;
	SDL_Surface *surface;
	SDL_Texture *texture;

public:
	Entity(SDL_Rect position);

	void create(SDL_Renderer *renderer);
	void destroy();

	void draw(SDL_Renderer *renderer);
	void move(DIRECTION dir);
};
