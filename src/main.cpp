#include <stdlib.h>
#include <error.h>
#include <SDL2/SDL.h>

#include "definitions.hpp"
#include "app.hpp"
#include "player.hpp"

void eventHandler(SDL_Event *event);
void keyboardHandler(SDL_Scancode sc);

// FIXME: Global player, Acces eventHandler
Player p(0, 0, 64, 64);
bool endProgram = false;

int main(int argc, char *argv[]){
	App app;
	if(! app.init()) 
		return EXIT_FAILURE;

	SDL_Event event;

	// Background Bitmap
	SDL_Surface *background = SDL_LoadBMP("../res/Background/background.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(app.getRenderer(), background);

	while(!endProgram){
		SDL_RenderCopy(app.getRenderer(), texture, NULL, NULL);
		//SDL_SetRenderDrawColor(app.getRenderer(), 0, 0, 0, 0);
		//SDL_RenderClear(app.getRenderer());

		eventHandler(&event);

		p.draw(app.getRenderer());

		SDL_RenderPresent(app.getRenderer());

		//SDL_Delay(200);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(background);
	app.destroy();

	return 0;
}

void eventHandler(SDL_Event *event){
	while(SDL_PollEvent(event)){
		switch(event->type){
			case SDL_QUIT:
				endProgram = true;
				break;
			case SDL_KEYDOWN:
				keyboardHandler(event->key.keysym.scancode);
				break;
			default:
				break;
		}
	}
}

void keyboardHandler(SDL_Scancode sc){
	switch(sc){
		case SDL_SCANCODE_ESCAPE:
			endProgram = true;
			break;
		case SDL_SCANCODE_W:
			p.move(UP);	
			break;

		case SDL_SCANCODE_S:
			p.move(DOWN);
			break;

		case SDL_SCANCODE_A:
			p.move(LEFT);
			break;

		case SDL_SCANCODE_D:
			p.move(RIGHT);
			break;
			
		default:
			break;
	}
}
