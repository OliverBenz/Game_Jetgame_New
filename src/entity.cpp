#include "entity.hpp"
#include "definitions.hpp"

Entity::Entity(SDL_Rect position, std::string bmloc){
	this->position = position;
	this->surface = nullptr;
	this->texture = nullptr;
	this->bmloc = bmloc;
};

void Entity::draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, texture, NULL, &position);
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &this->position);
}

void Entity::create(SDL_Renderer *renderer){
	this->surface = SDL_LoadBMP(this->bmloc.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Entity::move(DIRECTION dir){
	switch(dir){
		case UP:
			this->position.y -= speed;
			if(this->position.y < 0)
				this->position.y = 0;
			break;

		case DOWN:
			if(! (this->position.y >= SCREEN_HEIGHT - this->position.h))
				this->position.y += speed;
			break;

		case LEFT:
			this->position.x -= speed;
			if(this->position.x < 0)
				this->position.x = 0;
			break;

		case RIGHT:
			if(! (this->position.x >= SCREEN_WIDTH - this->position.w))
				this->position.x += speed;
			break;

		default:
			break;
	}
}
