#include "Food.hpp"
Food::Food() {}
Food::~Food() {}
void Food::init(int width, int height) {
	this->width = width;
	this->height = height;
	randomize();
}
void Food::update() {

}
void Food::showFood(std::vector<std::string>& str) {
	str[x][y] = '*';
}
void Food::generateNewFood() {
	randomize();
}
void Food::randomize() {
	x = rand() % height;
	y = rand() % width;
	if (x == 0) {
		x++;
	}
	if (y == 0) {
		y++;
	}
	if (x == height - 1) {
		x--;
	}
	if (y == width - 1) {
		y--;
	}
}
std::pair<int, int> Food::getFood() {
	return std::make_pair(x, y);
}