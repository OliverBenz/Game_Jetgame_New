#include "evHandler.hpp"
#include "app.hpp"

void keyboardHandle(SDL_Scancode *sc, bool val);

void EventHandler::handle(){
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:		endProgram = true;									 break;
			case SDL_KEYDOWN:	keyboardHandle(&(event.key.keysym.scancode), true);  break;
			case SDL_KEYUP:		keyboardHandle(&(event.key.keysym.scancode), false); break;
			default:
				break;
		}
	}
}

void keyboardHandle(SDL_Scancode *sc, bool val){
	switch(*sc){
		case SDL_SCANCODE_ESCAPE:
			endProgram = true;
			break;

		// Player 1 Controls
		case SDL_SCANCODE_W:	player1.setMovement(UP, val);	break;
		case SDL_SCANCODE_S:	player1.setMovement(DOWN, val);	break;
		case SDL_SCANCODE_A:	player1.setMovement(LEFT, val);	break;
		case SDL_SCANCODE_D:	player1.setMovement(RIGHT, val);break;
//		case SDL_SCANCODE_SPACE:player1.shoot(RIGHT);			break;
	
		//Player 2 Controls	
		case SDL_SCANCODE_UP:	player2.setMovement(UP, val);	break;
		case SDL_SCANCODE_DOWN:	player2.setMovement(DOWN, val);	break;
		case SDL_SCANCODE_LEFT:	player2.setMovement(LEFT, val);	break;
		case SDL_SCANCODE_RIGHT:player2.setMovement(RIGHT, val);break;
//		case SDL_SCANCODE_KP_0:	player2.shoot(LEFT);			break;

		default:
			break;
	}
}

