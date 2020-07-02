#include "player.hpp"
#include "definitions.hpp"
#include "globals.hpp"

Player::Player(SDL_Rect *position, std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->health = PLAYER_HEALTH;
}

void Player::shoot(DIRECTION dir){
	// Bullet can only move left or right
	if(dir == LEFT || dir == RIGHT){
		SDL_Rect *bPos = new SDL_Rect{
			.x = (this->position->x + this->position->w),
			.y = (this->position->y + (this->position->h / 2)),
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
		// Boundary on screen
		int limit = this->bullets.front().getMovement(RIGHT) ? SCREEN_WIDTH-BULLET_SIZE : 0;
		bool mvRight = this->bullets.front().getMovement(RIGHT);

		for(auto it = std::begin(this->bullets); it != std::end(this->bullets); ++it){
			// Check if bullet out of bounds
			if(mvRight && it->position->x >= limit || !mvRight && it->position->x <= limit){
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
