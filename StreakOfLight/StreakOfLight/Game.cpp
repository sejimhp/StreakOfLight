# include "Game.h"
# include "MyLight.h"


Game::Game() {
	light = std::make_shared<MyLight>();
	gameState = GAMESTATE::GAME;
	rects.push_back(Rect(100, 100, 100, 100));
	rects.push_back(Rect(500, 300, 100, 100));
	rects.push_back(Rect(50, 250, 100, 100));
}

void Game::update() {
	switch (gameState) {
	case GAMESTATE::START :
		break;
	case GAMESTATE::GAME :
		put_graphics();
		light->update(rects, lines);
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
		draw_graphics();
		light->draw();
		break;
	case GAMESTATE::SCORE :
		break;
	}
}

void Game::put_graphics() {
}


void Game::draw_graphics() {

	for (int i = 0; i < rects.size(); i++) {
		rects[i].draw();
	}
}