#include "player.hpp"
#include "definitions.hpp"

Player::Player(SDL_Rect *position, std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->health = PLAYER_HEALTH;
}

//void Player::shoot(DIRECTION dir){
//	if(dir == LEFT || dir == RIGHT){
//		SDL_Rect bPos = {
//			.x = Entity::position->x + Entity::position->w,
//			.y = Entity::position->y + (Entity::position->h / 2),
//			.w = BULLET_SIZE,
//			.h = BULLET_SIZE
//		};
//
//		Bullet b(&bPos);
//		b.create();
//		this->bullets.push_back(b);
//	}
//}

//void Player::update(SDL_Renderer *renderer){
//	this->move();
//	this->draw(renderer);
//	for(Bullet b: this->bullets)
//		b.update(renderer);
//}

//void Player::destroy(){
//	Entity::destroy();
//	for(Bullet b: this->bullets)
//		b.destroy();
//}
