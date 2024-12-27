#include<vector>
#include<string>
class Snek {
public:
	Snek();
	~Snek();
	void init(int x, int y,int dir);
	void update();
	void showSnek(std::vector<std::string>& str);
	std::pair<int, int> getHead();
	void event(int n);
	void grow();
	bool isSelfCollision();
	void setLength(int& length);
private:
	std::vector<std::pair<int,int>> body;
	std::vector<int> directions;
};