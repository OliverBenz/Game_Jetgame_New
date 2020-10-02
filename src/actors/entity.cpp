#include "entity.hpp"
#include "../definitions.hpp"
#include "../globals.hpp"

Entity::Entity(SDL_Rect *position, std::string bmloc, int speed){
	this->position = position;
	this->surface = nullptr;
	this->texture = nullptr;
	this->bmloc = bmloc;

	this->speed = speed;

	this->movement[UP] = false;
	this->movement[DOWN] = false;
	this->movement[LEFT] = false;
	this->movement[RIGHT] = false;
}

void Entity::create(){
	surface = SDL_LoadBMP(bmloc.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	texture = nullptr;

	SDL_FreeSurface(surface);
	surface = nullptr;
}


void Entity::update(Uint32 time){
	move(time);
	draw();
}

void Entity::draw(){
	SDL_RenderCopy(renderer, texture, NULL, position);
}

void Entity::setMovement(DIRECTION dir, bool val){
	movement[dir] = val;
}

bool Entity::getMovement(DIRECTION dir){
	return movement[dir];
}

void Entity::move(Uint32 time){
	if(movement[UP]){
		if (! movement[DOWN]){
			position->y -= speed * time;
			if(position->y <= 0)
				position->y = 0;
		}
	}
	else if(movement[DOWN]){
		if(! (position->y >= SCREEN_HEIGHT - position->h))
			position->y += speed * time;
	}
		
	if(movement[LEFT]){
		if(! movement[RIGHT]){
			position->x -= speed * time;
			if(position->x < 0)
				position->x = 0;
		}
	}
	else if(movement[RIGHT]){
		if(! (position->x >= SCREEN_WIDTH - position->w))
			position->x += speed * time;
	}
}
