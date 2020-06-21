#include "bullet.hpp"
#include "definitions.hpp"

Bullet::Bullet(int x, int y, int width, int height) : Entity(x, y, width, height){
	this->damage = BULLET_DAMAGE;
}
