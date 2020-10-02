#include "player.hpp"
#include "../definitions.hpp"
#include "../globals.hpp"

Player::Player(SDL_Rect *position, DIRECTION side, std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->side = side;
	this->health = PLAYER_HEALTH;
}

void Player::shoot(DIRECTION dir){
	if(shootTimeout <= 0 && (dir == LEFT || dir == RIGHT)){
		// Bullet can only move left or right
		SDL_Rect *bPos = new SDL_Rect{
			.x = side == LEFT ? (position->x + position->w) : (position->x),
			.y = (position->y + (position->h / 2) - BULLET_SIZE/2),
			.w = BULLET_SIZE,
			.h = BULLET_SIZE
		};

		Bullet b(bPos);
		b.create();
		b.setMovement(dir, true);
		bullets.push_back(b);
		shootTimeout = SHOOT_TIMEOUT;
	}
}

void Player::update(Uint32 time){
	if(health <= 0){
		gameState = GS_Winscreen;
		winner = side == LEFT ? RIGHT : LEFT;
		return;
	}

	if(shootTimeout > 0)
		shootTimeout -= 5;

	move(time);
	draw();

	if(bullets.size() != 0){
		for(auto it = std::begin(bullets); it != std::end(bullets); ++it){
			// Check if bullet out of bounds
			if((side == LEFT && it->position->x >= SCREEN_WIDTH - BULLET_SIZE) ||
				(side == RIGHT && it->position->x <= 0))
			{
				it->destroy();
				bullets.erase(it);
				--it;
				continue;
			}
			else{
				it->update(time);
			}
		}
	}
}

void Player::move(Uint32 time){
	Entity::move(time);
	switch(side){
		case LEFT:
			if(position->x + PLAYER_WIDTH > SCREEN_WIDTH / 2)
				position->x = (SCREEN_WIDTH / 2 ) - PLAYER_WIDTH;
			break;

		case RIGHT:
			if(position->x < SCREEN_WIDTH / 2)
				position->x = SCREEN_WIDTH / 2;
			break;
	}
}

void Player::checkCollision(std::vector<Bullet>* bullets){
	for(auto it = std::begin(*bullets); it != std::end(*bullets); ++it){
		// Ignore Bullets not in x range
		if(it->position->x + BULLET_SIZE < this->position->x || it->position->x > this->position->x + PLAYER_WIDTH)
			continue;

		// Ignore Bullets not in y range
		if(it->position->y + BULLET_SIZE < this->position->y || it->position->y > this->position->y + PLAYER_HEIGHT)
			continue;

		// Remaining Bullets are in Player range
		health -= it->damage;

		delete it->position;
		bullets->erase(it);
		--it;

		continue;
	}
}

std::vector<Bullet>* Player::getBullets(){
	return &bullets;
}

void Player::reset(){
	// Delete all Bullets
	for(Bullet b: this->bullets)
		b.destroy();
	bullets.clear();

	// Reset Player stats
	health = PLAYER_HEALTH;
	shootTimeout = 0;

	// Reset Player position
	switch(side){
		case LEFT:
			position->x = 0;
			position->y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;
			break;

		case RIGHT:
			position->x = SCREEN_WIDTH - PLAYER_WIDTH;
			position->y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;
			break;
		default:
			fprintf(stderr, "Invalid player side definition");
	}
}

void Player::destroy(){
	for(Bullet& b: bullets)
		b.destroy();
	Entity::destroy();
}
