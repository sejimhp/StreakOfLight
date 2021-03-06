﻿
# include <Siv3D.hpp>
# include <memory>

# include "Game.h"

void Main()
{
	Window::Resize(800,600);
	auto game = std::make_unique<Game>();

	while (System::Update())
	{
		game->update();
		game->draw();
	}
}
