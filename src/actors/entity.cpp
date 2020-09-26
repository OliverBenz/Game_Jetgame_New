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
	this->surface = SDL_LoadBMP(this->bmloc.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


void Entity::update(Uint32 time){
	move(time);
	draw();
}

void Entity::draw(){
	SDL_RenderCopy(renderer, texture, NULL, position);
}

void Entity::setMovement(DIRECTION dir, bool val){
	this->movement[dir] = val;
}

bool Entity::getMovement(DIRECTION dir){
	return this->movement[dir];
}

void Entity::move(Uint32 time){
	if(this->movement[UP]){
		if (! this->movement[DOWN]){
			this->position->y -= speed * time;
			if(this->position->y <= 0)
				this->position->y = 0;
		}
	}
	else if(this->movement[DOWN]){
		if(! (this->position->y >= SCREEN_HEIGHT - this->position->h))
			this->position->y += speed * time;
	}
		
	if(this->movement[LEFT]){
		if(! this->movement[RIGHT]){
			this->position->x -= speed * time;
			if(this->position->x < 0)
				this->position->x = 0;
		}
	}
	else if(this->movement[RIGHT]){
		if(! (this->position->x >= SCREEN_WIDTH - this->position->w))
			this->position->x += speed * time;
	}
}
