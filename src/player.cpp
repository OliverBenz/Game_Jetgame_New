#include "player.hpp"
#include "definitions.hpp"

Player::Player(SDL_Rect *position, std::string bmloc) : Entity(position, bmloc, PLAYER_SPEED){
	this->health = PLAYER_HEALTH;
}
