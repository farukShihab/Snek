#include "Snek.hpp"
Snek::Snek() {

}
Snek::~Snek() {

}
void Snek::init(int x, int y, int dir) {
	body.push_back(std::make_pair(x, y));
	body.push_back(std::make_pair(x, y - 1));
	body.push_back(std::make_pair(x, y - 2));
	body.push_back(std::make_pair(x, y - 3));
	body.push_back(std::make_pair(x, y - 4));
	directions.push_back(dir);
	directions.push_back(dir);
	directions.push_back(dir);
	directions.push_back(dir);
	directions.push_back(dir);
}
void Snek::update() {
	for (int i = 0;i < body.size();i++) {
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
	int temp1,temp2;
	for (int i = 1;i < directions.size();i++) {
		temp1 = directions[i];
		temp2 = directions[i - 1];
	}
}
void Snek::showSnek(std::vector<std::string>& str) {
	for (int i = 0;i < body.size();i++) {
		str[body[i].first][body[i].second] = 'a';
	}
}
std::pair<int, int> Snek::getHead() {
	return body[0];
}
void Snek::event(int n) {
	directions[0] = n;
}