#pragma once

#include <vector>
#include "entity.hpp"
#include "bullet.hpp"

class Player : public Entity{
public:
	int health;
	std::vector<Bullet> bullets;

	Player(SDL_Rect *position, std::string bmloc);

	void update();
	void checkCollision(std::vector<Bullet>* bullets);

	std::vector<Bullet>* getBullets();

	void destroy();
	void shoot(DIRECTION dir);
};
