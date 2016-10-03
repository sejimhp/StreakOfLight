#pragma once
# include <Siv3D.hpp>
# include <memory>
# include <vector>

# include "MyLight.h"

class Game {
public:
	Game();
	void init();
	enum GAMESTATE {START, GAME, SCORE};

	void update();
	void draw();

	//図形を配置
	void put_graphics();
	void draw_graphics();

private:
	std::shared_ptr<MyLight> light;
	GAMESTATE gameState;

	std::vector<Rect> rects;
	std::vector<Line> lines;

	Point mouse_start, mouse_end;
};