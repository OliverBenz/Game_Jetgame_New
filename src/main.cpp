#include <stdlib.h>
#include <error.h>
#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "app.hpp"
#include "player.hpp"
#include "evHandler.hpp"

void eventHandler(SDL_Event *event);
void keyboardHandler(SDL_Scancode sc);

SDL_Rect r = { .x = 0, .y = 0, .w = PLAYER_WIDTH , .h = PLAYER_HEIGHT };
Player player1(r);

bool endProgram = false;

int main(int argc, char *argv[]){
	App app;
	if(! app.init()) 
		return EXIT_FAILURE;
	
	SDL_Event event;

	// Background Bitmap
	SDL_Surface *background = SDL_LoadBMP("../res/Background/background.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(app.getRenderer(), background);

	player1.create(app.getRenderer());
	EventHandler ev;
	while(!endProgram){
		SDL_RenderCopy(app.getRenderer(), texture, NULL, NULL);

		ev.handle();

		player1.draw(app.getRenderer());

		SDL_RenderPresent(app.getRenderer());

		SDL_Delay(20);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(background);
	player1.destroy();
	app.destroy();

	return 0;
}


