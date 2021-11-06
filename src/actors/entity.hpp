#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>

#include "../app/Direction.hpp"

class Entity{
	int speed;
	
	std::map<Direction, bool> movement;

	// Bitmap Path 
	std::string bmloc;	

	SDL_Surface *surface;
	SDL_Texture *texture;

public:
	SDL_Rect position;
	Entity(SDL_Rect position, std::string bmloc, int speed);

	void create(SDL_Renderer* renderer);
	virtual void destroy();
	
	virtual void update(Uint32 time, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
	void setMovement(Direction dir, bool val);
	bool getMovement(Direction dir);
	virtual void move(Uint32 time);
};
