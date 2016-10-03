# include "MyLight.h"
# include <algorithm>

MyLight::MyLight() {
	points.push_front(Vec2(100.0, 300.0));
	points.push_front(Vec2(100.0, 300.0));
	speed_x = 10;
	speed_y = 10;
	clear_flag = false;
}

void MyLight::update(std::vector<Rect> rects, std::vector<Line>lines){
	points[0] += Vec2(speed_x, speed_y);

	collision_detection(rects, lines);

	//線の長さ
	double sum = 1000;
	//一定の長さ以上で切る
	for (int i = 0; i < points.size()-1; i++) {
		Vec2 diff = points[i] - points[i + 1];
		double len = sqrt(pow(diff.x, 2.0) + pow(diff.y, 2.0));
		if (len > sum) {
			sum /= sqrt(2);
			points[i + 1].x = points[i].x > points[i+1].x ? points[i].x - sum : points[i].x + sum;
			points[i + 1].y = points[i].y > points[i+1].y ? points[i].y - sum : points[i].y + sum;
			while (i + 2 != points.size()) {
				points.pop_back();
			}
		}
		else {
			sum -= len;
		}
	}
}

void MyLight::draw() {
	for (int i = 0; i < points.size()-1; i++) {
		Line(points[i], points[i+1]).draw();
	}
}

void MyLight::collision_detection(std::vector<Rect> rects, std::vector<Line>lines){
	player = Circle(points[0], 1);
	Vec2 p = points[0];

	//壁の当たり判定
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

	//矩形の当たり判定
	for (int i = 0; i < rects.size(); i++) {
		Rect rect = rects[i];
		if (player.intersects(rect)) {
			double line[4];
			line[0] = abs(rect.top.begin.x - player.x);
			line[1] = abs(rect.top.begin.y - player.y);
			line[2] = abs(rect.top.end.x - player.x);
			line[3] = abs(rect.bottom.end.y - player.y);
			double mi = 100;
			int num = 0;

			for (int i = 0; i < 4; i++) {
				if (mi > line[i]) {
					num = i;
					mi = line[i];
				}
			}
			if (num == 0 || num == 2) {
				speed_x = -speed_x; 
				points.push_front(p);
				if(i == 0)	clear_flag = true;
			}
			else { 
				speed_y = -speed_y; 
				points.push_front(p);
				if(i == 0) clear_flag = true;
			}
		}
	}
}