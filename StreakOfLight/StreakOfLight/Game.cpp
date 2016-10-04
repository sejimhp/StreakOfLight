# include "Game.h"
# include "MyLight.h"


Game::Game() {
	light = std::make_shared<MyLight>();
	gameState = GAMESTATE::GAME;
	init();
}

void Game::init() {
	rects.push_back(Rect(750, 0, 50, 50));
	rects.push_back(Rect(50, 50, 750, 10));
}

void Game::update() {
	switch (gameState) {
	case GAMESTATE::START :
		break;
	case GAMESTATE::GAME :
		put_graphics();
		light->update(rects, lines);
		if (light->get_clear_flag()) {
			gameState = GAMESTATE::SCORE;
		}
		if (Input::KeySpace.clicked) {
			rects.clear();
			init();
		}
		break;
	case GAMESTATE::SCORE :
		if (Input::KeySpace.clicked) {
			light->init();
			rects.clear();
			init();
		}
		if (Input::KeySpace.clicked) {
			rects.clear();
			init();
			gameState = GAMESTATE::GAME;
		}
		break;
	}
}

void Game::draw() {
	static Font font(20);
	switch (gameState) {
	case GAMESTATE::START :
		break;
	case GAMESTATE::GAME :
		draw_graphics();
		light->draw();
		break;
	case GAMESTATE::SCORE :
		draw_graphics();
		light->draw();
		Circle(400, 300, 150).draw(Palette::Orange);
		font(L"クリアしたよ").drawCenter(400, 300);
		break;
	}
}

void Game::put_graphics() {
	if (Input::MouseL.clicked)
	{
		mouse_start = Mouse::Pos();
	}        
	if (Input::MouseL.pressed) {
		mouse_end = Mouse::Pos();
	}
	if (Input::MouseL.released)
	{
		mouse_end = Mouse::Pos();
		if (mouse_end.x < mouse_start.x) {
			std::swap(mouse_start.x, mouse_end.x);
		}
		if (mouse_end.y < mouse_start.y) {
			std::swap(mouse_start.y, mouse_end.y);
		}
		rects.push_back(Rect(mouse_start, mouse_end - mouse_start));
		mouse_start = mouse_end = Point(0, 0);
	}
}


void Game::draw_graphics() {
	rects[0].draw(Palette::Aqua);
	for (int i = 1; i < rects.size(); i++) {
		rects[i].draw();
	}
	Rect(mouse_start, mouse_end - mouse_start).draw();
}