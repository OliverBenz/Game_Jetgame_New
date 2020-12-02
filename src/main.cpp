#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "globals.hpp"
#include "app/app.hpp"
#include "app/evHandler.hpp"

// Startposition of Player r(right), l(left)
SDL_Rect l = {
	.x = 0,
	.y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2,
	.w = PLAYER_WIDTH,
	.h = PLAYER_HEIGHT
};
SDL_Rect r = {
	.x = SCREEN_WIDTH - PLAYER_WIDTH,
	.y = SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2,
	.w = PLAYER_WIDTH,
	.h = PLAYER_HEIGHT
};
Player player1(&l, DIRECTION::LEFT, BM_PLAYER1);
Player player2(&r, DIRECTION::RIGHT, BM_PLAYER2);

// Init globals
GAMESTATE gameState = GAMESTATE::GS_Main;
DIRECTION winner = DIRECTION::LEFT;
SDL_Renderer* renderer = nullptr;

// Gamestate Functions
void GameStateMenu(App& app);
void GameStateMain(App& app);
void GameStateWinscreen(App& app);
void GameStateReset();

bool endProgram = false;
Uint32 lastTicks = SDL_GetTicks();

int main(int argc, char *argv[]){
	App app;
	if(! app.init())
		return EXIT_FAILURE;

	// Create player and Event Handler	
	player1.create();
	player2.create();
	EventHandler ev;

	// Game Loop
	while(!endProgram){
		ev.handle();

		switch(gameState){
			case GAMESTATE::GS_Menu:      GameStateMenu(app);      break;
			case GAMESTATE::GS_Main:      GameStateMain(app);      break;
			case GAMESTATE::GS_Winscreen: GameStateWinscreen(app); break;
			case GAMESTATE::GS_Reset:     GameStateReset();        break;
			case GAMESTATE::GS_End:       endProgram = true;       break;
		}

		lastTicks = SDL_GetTicks();

		// Render to screen
		SDL_RenderPresent(renderer);
		SDL_Delay(20);
	}

	// Destroy Elements
	player1.destroy();
	player2.destroy();
	app.destroy();

	return 0;
}

void GameStateMenu(App& app){
	// TODO: Implement
}

void GameStateMain(App& app){
	Uint32 gameTicks = SDL_GetTicks();
	app.drawBackground();

	// Update player and check for bullet collision
	player1.update((gameTicks - lastTicks) / 12);
	player2.update((gameTicks - lastTicks) / 12);

	player1.checkCollision(player2.getBullets());
	player2.checkCollision(player1.getBullets());
}

void GameStateWinscreen(App& app){
	if (winner == DIRECTION::LEFT)
		app.drawLeftWin();
	else
		app.drawRightWin();
}

void GameStateReset(){
	player1.reset();
	player2.reset();

	gameState = GAMESTATE::GS_Main;
}
