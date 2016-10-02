# include "MyLight.h"

MyLight::MyLight() {
	place = Vec2(500.0, 10.0);
	dx = 10;
	dy = 10;
}

void MyLight::update() {
	place += Vec2(dx, dy);
	player = Circle(place, 5);
	if ((place.y < 0 || place.y >= Window::Height()) && (place.x < 0 || place.x >= Window::Width())) {
		dy = -dy;
		dx = -dx;
	}
	else if (place.y < 0 || place.y >= Window::Height())
		dy = -dy;
	else if (place.x < 0 || place.x >= Window::Width())
		dx = -dx;
}

void MyLight::draw() {
	Circle(place, 3).draw();
}