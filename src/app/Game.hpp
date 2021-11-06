#pragma once

#include <SDL2/SDL.h>

#include "../actors/player.hpp"
#include "app.hpp"
#include "Gamestate.hpp"

class Game {
	App app;

	Uint32 lastTicks;

	Player player1;
	Player player2;

	bool endGame = false;
	Direction winner = DIRECTION::LEFT;

public:
	Game();
	~Game();

	void Start();

private:
	void GameStateMenu();
	void GameStateMain();
	void GameStateWinscreen();
	void GameStateReset();
};