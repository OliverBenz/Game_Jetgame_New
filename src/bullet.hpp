#pragma once

#include "entity.hpp"

class Bullet : public Entity{
	int damage;

public:
	Bullet(SDL_Rect position);
};
