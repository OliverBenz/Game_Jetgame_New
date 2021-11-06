#include "entity.hpp"
#include "../definitions.hpp"

Entity::Entity(SDL_Rect position, std::string bmloc, int speed){
	this->position = position;
	this->surface = nullptr;
	this->texture = nullptr;
	this->bmloc = bmloc;

	this->speed = speed;

	this->movement[Direction::Up] = false;
	this->movement[Direction::Down] = false;
	this->movement[Direction::Left] = false;
	this->movement[Direction::Right] = false;
}

void Entity::create(SDL_Renderer* renderer){
	surface = SDL_LoadBMP(bmloc.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Entity::destroy(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


void Entity::update(const Uint32 time, SDL_Renderer* renderer){
	move(time);
	draw(renderer);
}

void Entity::draw(SDL_Renderer* renderer){
	SDL_RenderCopy(renderer, texture, nullptr, &position);
}

void Entity::setMovement(const Direction dir, const bool val){
	movement[dir] = val;
}

bool Entity::getMovement(const Direction dir){
	return movement[dir];
}

void Entity::move(const Uint32 time){
	if(movement[Direction::Up]){
		if (! movement[Direction::Down]){
			position.y -= speed * time;
			if(position.y <= 0)
				position.y = 0;
		}
	}
	else if(movement[Direction::Down]){
		if(! (position.y >= SCREEN_HEIGHT - position.h))
			position.y += speed * time;
	}
		
	if(movement[Direction::Left]){
		if(! movement[Direction::Right]){
			position.x -= speed * time;
			if(position.x < 0)
				position.x = 0;
		}
	}
	else if(movement[Direction::Right]){
		if(! (position.x >= SCREEN_WIDTH - position.w))
			position.x += speed * time;
	}
}
