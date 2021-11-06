#include "Game.hpp"

Game::Game() {
	if(! app.init())
		return EXIT_FAILURE;

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

	player1 = Player(l, DIRECTION::LEFT, BM_PLAYER1);
	player2 = Player(r, DIRECTION::RIGHT, BM_PLAYER2);
}

Game::~Game() {
	player1.destroy();
	player2.destroy();
	app.destroy();
}

void Game::Start() {
	// Create player and Event Handler
	player1.create(app.getRenderer());
	player2.create(app.getRenderer());
	EventHandler ev;

	// Game Loop
	lastTicks = SDL_GetTicks();
	while(gameState != Gamestate::End){
		ev.handle(player1, player2);

		switch(ev.GameState()){
			case Gamestate::Menu:      GameStateMenu();       break;
			case Gamestate::Main:      GameStateMain();       break;
			case Gamestate::Winscreen: GameStateWinscreen();  break;
			case Gamestate::Reset:     GameStateReset();      break;
			default: break;
		}

		lastTicks = SDL_GetTicks();

		// Render to screen
		SDL_RenderPresent(app.getRenderer());
		SDL_Delay(20);
	}
}


void Game::GameStateMenu(){
	// TODO: Implement
}

void Game::GameStateMain(){
	Uint32 gameTicks = SDL_GetTicks();
	app.drawBackground();

	// TODO: Fix this
	if (player1.isDead()) {
		endGame = true;
		winner = Direction::Right;
		return;
	}
	if(player2.isDead()) {
		endGame = true;
		winner = Direction::Left;
		return;
	}

	// Update player and check for bullet collision
	player1.update((gameTicks - lastTicks) / 12, app.getRenderer());
	player2.update((gameTicks - lastTicks) / 12, app.getRenderer());

	player1.checkCollision(player2.getBullets());
	player2.checkCollision(player1.getBullets());
}

void Game::GameStateWinscreen(){
	if (winner == DIRECTION::LEFT)
		app.drawLeftWin();
	else
		app.drawRightWin();
}

void Game::GameStateReset(){
	player1.reset();
	player2.reset();

	gameState = Gamestate::Main;
}
