# include "Game.h"
# include "MyLight.h"


Game::Game() {
	light = std::make_shared<MyLight>();
	gameState = GAMESTATE::GAME;
}

void Game::update() {
	switch (gameState) {
	case GAMESTATE::START :
		break;
	case GAMESTATE::GAME :
		put_graphics();
		light->update();
		break;
	case GAMESTATE::SCORE :
		break;
	}
}

void Game::draw() {
	switch (gameState) {
	case GAMESTATE::START :
		break;
	case GAMESTATE::GAME :
		light->draw();
		break;
	case GAMESTATE::SCORE :
		break;
	}
}

void pur_graphics() {

}