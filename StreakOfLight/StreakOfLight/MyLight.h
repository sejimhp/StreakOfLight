#pragma once
# include <Siv3D.hpp>

class MyLight {
public:
	MyLight();
	void update();
	void draw();
private:
	Vec2 place;
	double dx, dy;
	Circle player;
};