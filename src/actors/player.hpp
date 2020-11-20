#pragma once

#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity{
	int health;
	std::vector<Bullet> bullets;

	int shootTimeout;

	// Player on left or right side of screen
	DIRECTION side;

public:
	Player(SDL_Rect *position, const DIRECTION id, const std::string bmloc);

	void update(const Uint32 time);
	void reset();
	void destroy();

	void checkCollision(std::vector<Bullet>& bullets);

	std::vector<Bullet>& getBullets();
	void shoot(const DIRECTION dir);
	void move(const Uint32 time);
};
