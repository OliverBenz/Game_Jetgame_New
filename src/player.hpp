#pragma once

#include "entity.hpp"

class Player : public Entity{
public:
	int health;
	Player(SDL_Rect position, std::string bmloc);
};
