#include "entity.hpp"
#include "definitions.hpp"

Entity::Entity(SDL_Rect position, std::string bmloc, int speed){
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

void Entity::create(SDL_Renderer *renderer){
	this->surface = SDL_LoadBMP(this->bmloc.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


void Entity::update(SDL_Renderer *renderer){
	move();
	draw(renderer);
}

void Entity::draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, texture, NULL, &position);
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &this->position);
}

void Entity::setMovement(DIRECTION dir, bool val){
	this->movement[dir] = val;
	
	switch(dir){
		case UP:	movement[DOWN] = false;  break;
		case DOWN:	movement[UP] = false; 	 break;
		case LEFT:	movement[RIGHT] = false; break;
		case RIGHT: movement[LEFT] = false;  break;
	}
}

void Entity::move(){
	if(this->movement[UP]){
		this->position.y -= speed;
		if(this->position.y <= 0)
			this->position.y = 0;
	}
	else if(this->movement[DOWN]){
		if(! (this->position.y >= SCREEN_HEIGHT - this->position.h))
			this->position.y += speed;
	}

	if(this->movement[LEFT]){
		this->position.x -= speed;
		if(this->position.x < 0)
			this->position.x = 0;
	}
	else if(this->movement[RIGHT]){
		if(! (this->position.x >= SCREEN_WIDTH - this->position.w))
			this->position.x += speed;
	}
}
