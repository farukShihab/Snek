#include<windows.h>
#include<iostream>
#include<conio.h>
#include "Snek.hpp"
#include "Food.hpp"
int width = 30;
int height = 20;
char border = '#';
void showGame(std::vector<std::string>& area) {
	for (int i = 0;i < area.size();i++) {
		for (int j = 0;j < area[i].size();j++) {
			printf("%c", area[i][j]);
			if (area[i][j] != ' ' && area[i][j] != border) {
				area[i][j] = ' ';
			}
		}
		printf("\n");
	}
	printf("\n");
}
bool isCollision(std::pair<int,int> head) {
	if (head.first >= height || head.second >= width || head.first<=0 || head.second<=0) {
		return true;
	}
	return false;
}
void handleEvent(Snek& snek) {
	if (_kbhit()) {
		char n = _getch();
		switch (n) {
		case 'd':
			snek.event(1);
			break;
		case 'a':
			snek.event(2);
			break;
		case 'w':
			snek.event(3);
			break;
		case 's':
			snek.event(4);
			break;
		}
	}
}
void initArea(std::vector<std::string>& area) {
	area.resize(height);
	for (int i = 1;i <= height;i++) {
		for (int j = 1;j <= width;j++) {
			if (i == 1 || j == 1 || i == height || j == width) {
				area[i - 1] += '#';
			}
			else {
				area[i - 1] += ' ';
			}
		}
	}
}
int main(int argc, char* argv[]) {
	std::vector<std::string> area;
	initArea(area);
	bool isRunning = true;
	DWORD a, b;
	int FPS = 60;
	int frameRate = 1000 / FPS;
	int frameNum = 0;
	Snek snek;
	Food food;
	food.init(width, height);
	snek.init(width / 2, height / 2, 1);
	while (isRunning) {
		a = GetTickCount();
		printf("%d\n", frameNum++);
		if (isCollision(snek.getHead())) {
			isRunning = false;
			break;
		}
		system("cls");
		handleEvent(snek);
		showGame(area);
		snek.showSnek(area);
		food.showFood(area);
		if (frameNum % 10 == 0) {
			snek.update();
		}
		b = GetTickCount();
		if (b - a < frameRate) {
			Sleep(frameRate - (b - a));
		}
	}
}