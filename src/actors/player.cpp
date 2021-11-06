#include "player.hpp"
#include "../definitions.hpp"

Player::Player(SDL_Rect position, const Direction side, const std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->side = side;
	this->health = PLAYER_HEALTH;
}

void Player::shoot(const Direction dir, SDL_Renderer* renderer){
	if(shootTimeout <= 0 && (dir == Direction::Left || dir == Direction::Right)){
		// Bullet can only move left or right
		SDL_Rect bPos {
			.x = side == Direction::Left ? (position.x + position.w) : (position.x),
			.y = (position.y + (position.h / 2) - BULLET_SIZE/2),
			.w = BULLET_SIZE,
			.h = BULLET_SIZE
		};

		Bullet b(bPos);
		b.create(renderer);
		b.setMovement(dir, true);
		bullets.push_back(b);
		shootTimeout = SHOOT_TIMEOUT;
	}
}

void Player::update(const Uint32 time, SDL_Renderer* renderer){
	if(shootTimeout > 0)
		shootTimeout -= 5;

	move(time);
	draw(renderer);

	if(!bullets.empty()){
		for(auto it = std::begin(bullets); it != std::end(bullets); ++it){
			// Check if bullet out of bounds
			if((side == Direction::Left && it->position.x >= SCREEN_WIDTH - BULLET_SIZE) ||
				(side == Direction::Right && it->position.x <= 0))
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

void Player::move(const Uint32 time){
	Entity::move(time);
	switch(side){
		case Direction::Left:
			if(position.x + PLAYER_WIDTH > SCREEN_WIDTH / 2)
				position.x = (SCREEN_WIDTH / 2 ) - PLAYER_WIDTH;
			break;

		case Direction::Right:
			if(position.x < SCREEN_WIDTH / 2)
				position.x = SCREEN_WIDTH / 2;
			break;

		default:
			break;
	}
}

void Player::checkCollision(std::vector<Bullet>& bulletsEnemy){
	for(auto it = std::begin(bulletsEnemy); it != std::end(bulletsEnemy); ++it){
		// Ignore Bullets not in x range
		if(it->position.x + BULLET_SIZE < this->position.x || it->position.x > this->position.x + PLAYER_WIDTH)
			continue;

		// Ignore Bullets not in y range
		if(it->position.y + BULLET_SIZE < this->position.y || it->position.y > this->position.y + PLAYER_HEIGHT)
			continue;

		// Remaining Bullets are in Player range
		health -= it->damage;

		bulletsEnemy.erase(it);
		--it;
	}
}

bool Player::isDead() {
	return health <= 0;
}

std::vector<Bullet>& Player::getBullets(){
	return bullets;
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
		case Direction::Left:
			position.x = 0;
			position.y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;
			break;

		case Direction::Right:
			position.x = SCREEN_WIDTH - PLAYER_WIDTH;
			position.y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2;
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
