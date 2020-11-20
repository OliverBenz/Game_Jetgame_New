#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <map>

enum class DIRECTION { UP, DOWN, LEFT, RIGHT };

class Entity{
	int speed;
	
	std::map<DIRECTION, bool> movement;

	// Bitmap Path 
	std::string bmloc;	

	SDL_Surface *surface;
	SDL_Texture *texture;

public:
	SDL_Rect *position;
	Entity(SDL_Rect *position, std::string bmloc, const int speed);

	void create();
	virtual void destroy();
	
	virtual void update(const Uint32 time);
	void draw();
	void setMovement(const DIRECTION dir, const bool val);
	bool getMovement(const DIRECTION dir);
	virtual void move(const Uint32 time);
};
