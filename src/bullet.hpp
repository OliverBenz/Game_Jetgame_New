#pragma once

#include "entity.hpp"

class Bullet : public Entity{
public:
	int damage;
	Bullet(SDL_Rect *position);
};
