#include "Food.hpp"
Food::Food() {
}
void Food::init(int width, int height) {
	this->width = width;
	this->height = height;
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
	x = rand() % width;
	y = rand() % height;
}