#include "entity.hpp"
#include "../definitions.hpp"
#include "../globals.hpp"

Entity::Entity(SDL_Rect *position, std::string bmloc, int speed){
	this->position = position;
	this->surface = nullptr;
	this->texture = nullptr;
	this->bmloc = bmloc;

	this->speed = speed;

	this->movement[DIRECTION::UP] = false;
	this->movement[DIRECTION::DOWN] = false;
	this->movement[DIRECTION::LEFT] = false;
	this->movement[DIRECTION::RIGHT] = false;
}

void Entity::create(){
	surface = SDL_LoadBMP(bmloc.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


void Entity::update(const Uint32 time){
	move(time);
	draw();
}

void Entity::draw(){
	SDL_RenderCopy(renderer, texture, NULL, position);
}

void Entity::setMovement(const DIRECTION dir, const bool val){
	movement[dir] = val;
}

bool Entity::getMovement(const DIRECTION dir){
	return movement[dir];
}

void Entity::move(const Uint32 time){
	if(movement[DIRECTION::UP]){
		if (! movement[DIRECTION::DOWN]){
			position->y -= speed * time;
			if(position->y <= 0)
				position->y = 0;
		}
	}
	else if(movement[DIRECTION::DOWN]){
		if(! (position->y >= SCREEN_HEIGHT - position->h))
			position->y += speed * time;
	}
		
	if(movement[DIRECTION::LEFT]){
		if(! movement[DIRECTION::RIGHT]){
			position->x -= speed * time;
			if(position->x < 0)
				position->x = 0;
		}
	}
	else if(movement[DIRECTION::RIGHT]){
		if(! (position->x >= SCREEN_WIDTH - position->w))
			position->x += speed * time;
	}
}
