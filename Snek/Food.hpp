#include<iostream>
#include<vector>
class Food {
public:
	Food();
	void init(int width, int height);
	void update();
	void showFood(std::vector<std::string>& str);
	void generateNewFood();
	std::pair<int, int> getFood() {
		return std::make_pair(x, y);
	}
private:
	int width;
	int height;
	int x;
	int y;
	void randomize();
};