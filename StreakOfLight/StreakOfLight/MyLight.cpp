# include "MyLight.h"

MyLight::MyLight() {
	points.push_front(Vec2(500.0, 10.0));
	points.push_front(Vec2(500.0, 10.0));
	speed_x = 5;
	speed_y = 5;
}

void MyLight::update() {
	points[0] += Vec2(speed_x, speed_y);
	player = Circle(points[0], 5);
	
	Vec2 p = points[0];
	if ((p.y < 0 || p.y >= Window::Height()) && (p.x < 0 || p.x >= Window::Width())) {
		speed_y = -speed_y;
		speed_x = -speed_x;
		points.push_front(p);
	}
	else if (p.y < 0 || p.y >= Window::Height()) {
		speed_y = -speed_y;
		points.push_front(p);
	}
	else if (p.x < 0 || p.x >= Window::Width()) {
		speed_x = -speed_x;
		points.push_front(p);
	}
	if (points.size() == 6)
		points.pop_back();
}

void MyLight::draw() {
	//線の長さ
	/*double line_len = 200;
	for (int i = 0; i < points.size(); i++) {
		if (i == points.size() - 1) {

		}
	}*/
	for (int i = 0; i < points.size()-1; i++) {
		Line(points[i], points[i+1]).draw();
	}
}