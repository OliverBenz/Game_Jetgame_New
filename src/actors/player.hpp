#pragma once

#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

#include "../app/Direction.hpp"

class Player : public Entity{
	int health;
	std::vector<Bullet> bullets;

	int shootTimeout;

	// Player on left or right side of screen
	Direction side;

public:
	Player(SDL_Rect position, Direction id, std::string bmloc);

	void update(const Uint32 time, SDL_Renderer* renderer);
	void reset();
	void destroy();

	void checkCollision(std::vector<Bullet>& bullets);

	std::vector<Bullet>& getBullets();
	void shoot(const Direction dir, SDL_Renderer* renderer);
	void move(const Uint32 time);
	bool isDead();
};
