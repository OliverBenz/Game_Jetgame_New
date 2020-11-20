#include "evHandler.hpp"
#include "../globals.hpp"

void keyboardHandle(const SDL_Scancode *sc, const bool val);

void EventHandler::handle(){
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:    gameState = GAMESTATE::GS_End;                       break;
			case SDL_KEYDOWN: keyboardHandle(&(event.key.keysym.scancode), true);  break;
			case SDL_KEYUP:   keyboardHandle(&(event.key.keysym.scancode), false); break;
			default:  break;
		}
	}
}

void keyboardHandle(const SDL_Scancode *sc, const bool val){
	switch(*sc){
		case SDL_SCANCODE_ESCAPE:  // Close Application
			gameState = GAMESTATE::GS_End;
			break;

		case SDL_SCANCODE_R:  // Restart Game
			if(gameState == GAMESTATE::GS_Winscreen)
				gameState = GAMESTATE::GS_Reset;
			break;

		// Player 1 Controls
		case SDL_SCANCODE_W:     player1.setMovement(DIRECTION::UP, val);    break;
		case SDL_SCANCODE_S:     player1.setMovement(DIRECTION::DOWN, val);  break;
		case SDL_SCANCODE_A:     player1.setMovement(DIRECTION::LEFT, val);  break;
		case SDL_SCANCODE_D:     player1.setMovement(DIRECTION::RIGHT, val); break;
		case SDL_SCANCODE_SPACE: player1.shoot(DIRECTION::RIGHT);            break;
	
		//Player 2 Controls	
		case SDL_SCANCODE_UP:    player2.setMovement(DIRECTION::UP, val);    break;
		case SDL_SCANCODE_DOWN:  player2.setMovement(DIRECTION::DOWN, val);  break;
		case SDL_SCANCODE_LEFT:  player2.setMovement(DIRECTION::LEFT, val);  break;
		case SDL_SCANCODE_RIGHT: player2.setMovement(DIRECTION::RIGHT, val); break;
		case SDL_SCANCODE_KP_0:  player2.shoot(DIRECTION::LEFT);             break;

		default: break;
	}
}

