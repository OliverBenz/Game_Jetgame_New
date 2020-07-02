#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class Entity{
	int speed;
	
	std::map<DIRECTION, bool> movement;

	// Bitmap Path 
	std::string bmloc;	

	SDL_Surface *surface;
	SDL_Texture *texture;

protected:
	SDL_Rect *position;

public:
	Entity(SDL_Rect *position, std::string bmloc, const int speed);

	void create(SDL_Renderer *renderer);
	virtual void destroy();
	
	virtual void update(SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer);
	void setMovement(DIRECTION dir, bool val);
	void move();
};
