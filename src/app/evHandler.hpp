#pragma once

#include <SDL2/SDL.h>

#include "Gamestate.hpp"
#include "../actors/player.hpp"

class EventHandler{
	SDL_Event event;
	Gamestate gameState = Gamestate::Main;

public:
	void Handle(Player& player1, Player& player2);
	Gamestate GameState() noexcept;

private:
	void KeyboardHandle(const SDL_Scancode *sc, Player& player1, Player& player2, bool val);
};
