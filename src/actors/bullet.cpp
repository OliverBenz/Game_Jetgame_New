#include "bullet.hpp"
#include "../definitions.hpp"

Bullet::Bullet(SDL_Rect *position) : Entity(position, BM_BULLET, BULLET_SPEED){
	this->damage = BULLET_DAMAGE;
}

void Bullet::destroy(){
	delete this->position;
	Entity::destroy();
}
