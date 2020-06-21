#include "entity.hpp"
#include "definitions.hpp"

Entity::Entity(int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;	
	
	// NOTE: Will be removed with Entity-Image	
	this->sprite.x = x;
	this->sprite.y = y;
	this->sprite.w = width;
	this->sprite.h = height;
};

void Entity::draw(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &this->sprite);
}

void Entity::move(DIRECTION dir){
	switch(dir){
		case UP:
			this->sprite.y -= speed;
			if(this->sprite.y < 0)
				this->sprite.y = 0;
			break;

		case DOWN:
			if(! (this->sprite.y >= SCREEN_HEIGHT - this->sprite.h))
				this->sprite.y += speed;
			break;

		case LEFT:
			this->sprite.x -= speed;
			if(this->sprite.x < 0)
				this->sprite.x = 0;
			break;

		case RIGHT:
			if(! (this->sprite.x >= SCREEN_WIDTH - this->sprite.w))
				this->sprite.x += speed;
			break;

		default:
			break;
	}
}
