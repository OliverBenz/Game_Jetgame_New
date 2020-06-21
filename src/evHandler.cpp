#include "evHandler.hpp"
#include "app.hpp"

void keyboardHandle(SDL_Scancode sc);

void EventHandler::handle(){
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				endProgram = true;
				break;
			case SDL_KEYDOWN:
				keyboardHandle(event.key.keysym.scancode);
				break;
			default:
				break;
		}
	}
}

void keyboardHandle(SDL_Scancode sc){
	switch(sc){
		case SDL_SCANCODE_ESCAPE:
			endProgram = true;
			break;
		case SDL_SCANCODE_W:
			player1.move(UP);	
			break;

		case SDL_SCANCODE_S:
			player1.move(DOWN);
			break;

		case SDL_SCANCODE_A:
			player1.move(LEFT);
			break;

		case SDL_SCANCODE_D:
			player1.move(RIGHT);
			break;
		
		case SDL_SCANCODE_UP:
			player2.move(UP);
			break;

		case SDL_SCANCODE_DOWN: 
			player2.move(DOWN);
			break;

		case SDL_SCANCODE_LEFT:
			player2.move(LEFT);
			break;

		case SDL_SCANCODE_RIGHT:
			player2.move(RIGHT);
			break;

		default:
			break;
	}
}
