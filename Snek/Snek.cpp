#include "Snek.hpp"
Snek::Snek() {

}
Snek::~Snek() {

}
void Snek::init(int x, int y, int dir) {
	body.push_back(std::make_pair(x, y));
	body.push_back(std::make_pair(x, y - 1));
	directions.push_back(dir);
	directions.push_back(dir);
}
bool isGrown = false;
void Snek::update() {
	if (isGrown) {
		body.push_back(std::make_pair(body[body.size() - 1].first, body[body.size() - 1].second));
		directions.push_back(directions[directions.size() - 1]);
	}
	for (int i = 0;i < body.size();i++) {
		if (isGrown && i==body.size()-1) {
			break;
		}
		switch (directions[i]) {
		case 1:
			body[i].second++;
			break;
		case 2:
			body[i].second--;
			break;
		case 3:
			body[i].first--;
			break;
		case 4:
			body[i].first++;
			break;
		}
	}
	std::vector<int> temp = directions;
	for (int i = 1;i < directions.size();i++) {
		if (isGrown && i == directions.size() - 1) {
			isGrown = false;
			break;
		}
		directions[i] = temp[i - 1];
	}
}
void Snek::showSnek(std::vector<std::string>& str) {
	for (int i = 0;i < body.size();i++) {
		str[body[i].first][body[i].second] = 'O';
	}
}
std::pair<int, int> Snek::getHead() {
	return body[0];
}
void Snek::event(int n) {
	if (n == 1 && directions[0] != 2) {
		directions[0] = 1;
	}
	else if (n == 2 && directions[0] != 1) {
		directions[0] = 2;
	}
	else if (n == 3 && directions[0] != 4) {
		directions[0] = 3;
	}
	else if (n == 4 && directions[0] != 3) {
		directions[0] = 4;
	}
}
void Snek::grow() {
	isGrown = true;
}
bool Snek::isSelfCollision() {
	for (int i = 1;i < body.size();i++) {
		if (body[0] == body[i]) {
			return true;
		}
	}
	return false;
}
void Snek::setLength(int& length) {
	length = body.size();
}