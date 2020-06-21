#pragma once

#include "entity.hpp"

class Player : public Entity{
	int health;

public:
	Player(int x, int y, int width, int height);
};
