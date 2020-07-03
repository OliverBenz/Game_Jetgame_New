#include "player.hpp"
#include "definitions.hpp"
#include "globals.hpp"

Player::Player(SDL_Rect *position, DIRECTION side, std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->side = side;
	this->health = PLAYER_HEALTH;
}

void Player::shoot(DIRECTION dir){
	// Bullet can only move left or right
	if(dir == LEFT || dir == RIGHT){
		SDL_Rect *bPos = new SDL_Rect{
			.x = this->side == LEFT ? (this->position->x + this->position->w) : (this->position->x),
			.y = (this->position->y + (this->position->h / 2) - BULLET_SIZE/2),
			.w = BULLET_SIZE,
			.h = BULLET_SIZE
		};

		Bullet b(bPos);
		b.create();
		b.setMovement(dir, true);
		this->bullets.push_back(b);
	}
}

void Player::update(){
	this->move();
	this->draw();

	if(this->bullets.size() != 0){
		for(auto it = std::begin(this->bullets); it != std::end(this->bullets); ++it){
			// Check if bullet out of bounds
			if((this->side == LEFT && it->position->x >= SCREEN_WIDTH - BULLET_SIZE) || (this->side == RIGHT && it->position->x <= 0)){
				delete it->position;
				this->bullets.erase(it);
				--it;
				continue;
			}
			it->update();
		}
	}
}

void Player::checkCollision(std::vector<Bullet>* bullets){
	for(auto& b: *bullets){
		// If collision -> remove bullet
	}
}


std::vector<Bullet>* Player::getBullets(){
	return &(this->bullets);
}

void Player::destroy(){
	for(Bullet b: this->bullets){
		delete b.position;
		b.destroy();
	}
	Entity::destroy();
}
