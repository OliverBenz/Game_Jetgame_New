#include "bullet.hpp"
#include "../definitions.hpp"

Bullet::Bullet(SDL_Rect position) : Entity(position, BM_BULLET, BULLET_SPEED){
	damage = BULLET_DAMAGE;
}

void Bullet::destroy(){
	delete position;
	Entity::destroy();
}
