#pragma once
# include <Siv3D.hpp>
# include <deque>

class MyLight {
public:
	MyLight();
	void update(std::vector<Rect>, std::vector<Line>);
	void draw();

	void collision_detection(std::vector<Rect>, std::vector<Line>);
private:
	//各点(始点を含める)
	std::deque<Vec2> points;
	//各辺の長さ
	std::deque<double> lengths;
	//始点の移動速度
	double speed_x, speed_y;
	//そのほか後ろの移動速度
	std::deque<Vec2> speeds;
	//あたり判定用？
	Circle player;
};