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

public:
	SDL_Rect *position;
	Entity(SDL_Rect *position, std::string bmloc, const int speed);

	void create();
	virtual void destroy();
	
	virtual void update(Uint32 time);
	void draw();
	void setMovement(DIRECTION dir, bool val);
	bool getMovement(DIRECTION dir);
	virtual void move(Uint32 time);
};
