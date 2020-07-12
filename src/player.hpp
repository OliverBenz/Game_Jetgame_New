#pragma once

#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity{
	int health;
	std::vector<Bullet> bullets;

	int shootTimeout;

	// Player on left or right side of screen
	enum DIRECTION side;

public:
	Player(SDL_Rect *position, DIRECTION id, std::string bmloc);

	void update();
	void destroy();

	void checkCollision(std::vector<Bullet>* bullets);

	std::vector<Bullet>* getBullets();
	void shoot(DIRECTION dir);
	void move();
};
