#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "app.hpp"
#include "player.hpp"
#include "evHandler.hpp"

SDL_Rect r = { .x = 0, .y = 0, .w = PLAYER_WIDTH , .h = PLAYER_HEIGHT };
Player player1(r, "../res/player/player_left.bmp");

bool endProgram = false;

int main(int argc, char *argv[]){
	App app;
	if(! app.init()) 
		return EXIT_FAILURE;

	// Create player and Event Handler	
	player1.create(app.getRenderer());
	EventHandler ev;

	// Game Loop
	while(!endProgram){
		app.drawBackground();

		ev.handle();
		player1.draw(app.getRenderer());

		SDL_RenderPresent(app.getRenderer());
		SDL_Delay(20);
	}

	// Destroy Elements
	player1.destroy();
	app.destroy();

	return 0;
}


