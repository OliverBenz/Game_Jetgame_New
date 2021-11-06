#include "evHandler.hpp"

#include "Direction.hpp"

Gamestate EventHandler::GameState() noexcept {
	return gameState;
}

void EventHandler::Handle(Player& player1, Player& player2){
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:    gameState = Gamestate::End;                                            break;
			case SDL_KEYDOWN: KeyboardHandle(&(event.key.keysym.scancode), player1, player2, true);  break;
			case SDL_KEYUP:   KeyboardHandle(&(event.key.keysym.scancode), player1, player2, false); break;
			default:  break;
		}
	}
}

void EventHandler::KeyboardHandle(const SDL_Scancode *sc, Player& player1, Player& player2, const bool val){
	switch(*sc){
		case SDL_SCANCODE_ESCAPE:  // Close Application
			gameState =  Gamestate::End;
			break;

		case SDL_SCANCODE_R:  // Restart Game
			if(gameState == Gamestate::Winscreen)
				gameState = Gamestate::Reset;
			break;

		// Player 1 Controls
		case SDL_SCANCODE_W:     player1.setMovement(Direction::Up, val);    break;
		case SDL_SCANCODE_S:     player1.setMovement(Direction::Down, val);  break;
		case SDL_SCANCODE_A:     player1.setMovement(Direction::Left, val);  break;
		case SDL_SCANCODE_D:     player1.setMovement(Direction::Right, val); break;
		case SDL_SCANCODE_SPACE: player1.shoot(Direction::Right);            break;
	
		//Player 2 Controls	
		case SDL_SCANCODE_UP:    player2.setMovement(Direction::Up, val);    break;
		case SDL_SCANCODE_DOWN:  player2.setMovement(Direction::Down, val);  break;
		case SDL_SCANCODE_LEFT:  player2.setMovement(Direction::Left, val);  break;
		case SDL_SCANCODE_RIGHT: player2.setMovement(Direction::Right, val); break;
		case SDL_SCANCODE_KP_0:  player2.shoot(Direction::Left);             break;

		default: break;
	}
}

