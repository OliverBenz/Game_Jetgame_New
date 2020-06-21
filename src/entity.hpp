#pragma once

#include <SDL2/SDL.h>

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Entity{
	int x, y, width, height;
	const int speed = 8;
	
	SDL_Rect sprite;
	// Bitmap

public:
	Entity(int x, int y, int width, int height);

	void draw(SDL_Renderer *renderer);
	void move(DIRECTION dir);
};
