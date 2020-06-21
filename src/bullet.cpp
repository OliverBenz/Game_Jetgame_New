#include "bullet.hpp"
#include "definitions.hpp"

Bullet::Bullet(SDL_Rect position) : Entity(position){
	this->damage = BULLET_DAMAGE;
}
