#include "player.hpp"
#include "definitions.hpp"

Player::Player(SDL_Rect position) : Entity(position){
	this->health = PLAYER_HEALTH;
}
