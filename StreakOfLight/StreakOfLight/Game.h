#pragma once
# include <Siv3D.hpp>

# include "MyLight.h"

class Game {
public:
	Game();
	enum GAMESTATE {START, GAME, SCORE};

	void update();
	void draw();

	//図形を配置
	void put_graphics();
private:
	std::shared_ptr<MyLight> light;
	GAMESTATE gameState;
};