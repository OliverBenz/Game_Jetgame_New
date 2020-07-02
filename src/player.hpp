#pragma once

#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity{
	int health;
	std::vector<Bullet> bullets;

public:
	Player(SDL_Rect *position, std::string bmloc);

	void update();
	void destroy();

	void checkCollision(std::vector<Bullet>* bullets);

	std::vector<Bullet>* getBullets();
	void shoot(DIRECTION dir);
};
