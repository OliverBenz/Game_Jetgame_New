#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "app.hpp"
#include "player.hpp"
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

Player player1(&l, BM_PLAYER1);
Player player2(&r, BM_PLAYER2);

bool endProgram = false;

int main(int argc, char *argv[]){
	App app;
	if(! app.init())
		return EXIT_FAILURE;

	// Create player and Event Handler	
	player1.create(app.getRenderer());
	player2.create(app.getRenderer());
	EventHandler ev;

	// Game Loop
	while(!endProgram){
		app.drawBackground();

		ev.handle();

		player1.update(app.getRenderer());
		player2.update(app.getRenderer());

		SDL_RenderPresent(app.getRenderer());
		SDL_Delay(20);
	}

	// Destroy Elements
	player1.destroy();
	player2.destroy();
	app.destroy();

	return 0;
}
