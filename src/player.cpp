#include "player.hpp"
#include "definitions.hpp"

Player::Player(int x, int y, int width, int height) : Entity(x, y, width, height){
	this->health = PLAYER_HEALTH;
}
