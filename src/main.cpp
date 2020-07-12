#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "app.hpp"
#include "globals.hpp"
#include "evHandler.hpp"

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

Player player1(&l, LEFT, BM_PLAYER1);
Player player2(&r, RIGHT, BM_PLAYER2);

bool endProgram = false;
DIRECTION winner = LEFT;

GAMESTATE gameState = GS_Main;

SDL_Renderer* renderer;

void GameStateMain(App *app);
void GameStateWinscreen(App *app);

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
			case GS_Titlescreen:
				break;
			case GS_Main:
				GameStateMain(&app);
				break;
			case GS_Winscreen:
				GameStateWinscreen(&app);
				break;
		}

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

void GameStateMain(App *app){
	app->drawBackground();

	// Update player and check for bullet collision
	player1.update();
	player2.update();

	player1.checkCollision(player2.getBullets());
	player2.checkCollision(player1.getBullets());
}

void GameStateWinscreen(App *app){
	if(winner == LEFT)
		app->drawLeftWin();
	else
		app->drawRightWin();
}
