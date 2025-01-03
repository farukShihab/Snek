#include<iostream>
#include<vector>
class Food {
public:
	Food();
	~Food();
	void init(int width, int height);
	void update();
	void showFood(std::vector<std::string>& str);
	void generateNewFood();
	std::pair<int, int> getFood();
private:
	int width;
	int height;
	int x;
	int y;
	void randomize();
};