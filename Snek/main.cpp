#include<windows.h>
#include<iostream>
#include<conio.h>
#include<queue>
#include "Snek.hpp"
#include "Food.hpp"
constexpr int width = 20;
constexpr int height = 20;
char border = '#';
std::queue<int> inputBuffer;
void showGame(std::vector<std::string>& area) {
	for (int i = 0;i < height;i++) {
		std::cout << area[i];
		for (int j = 0;j < width;j++) {
			if (area[i][j] != ' ' && area[i][j] != border) {
				area[i][j] = ' ';
			}
		}
		printf("\n");
	}
	printf("\n");
}
bool isCollision(std::pair<int,int> head) {
	if (head.first >= height-1 || head.second >= width-1 || head.first<=0 || head.second<=0) {
		return true;
	}
	return false;
}
void handleEvent(Snek& snek,bool& isPaused) {
	if (_kbhit()) {
		char n = _getch();
		if (!isPaused) {
			switch (n) {
			case 'd':
				inputBuffer.push(1);
				break;
			case 'a':
				inputBuffer.push(2);
				break;
			case 'w':
				inputBuffer.push(3);
				break;
			case 's':
				inputBuffer.push(4);
				break;
			case ' ':
				if (isPaused)isPaused = false;
				else isPaused = true;
				break;
			}
		}
		else {
			if(n==' ')isPaused = false;
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
void eat(Snek& snek, Food& food, int& score) {
	if (snek.getHead() == food.getFood()) {
		snek.grow();
		food.generateNewFood();
		while(snek.isFoodOverlap(food.getFood()))food.generateNewFood();
		score+=10;
	}
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
int main(int argc, char* argv[]) {
	ShowConsoleCursor(false);
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
	snek.init(height / 2, width / 2, 1);
	int score = 0;
	int length = 2;
	bool isPaused = false;
	while (isRunning) {
		a = GetTickCount64();
		//printf("%d\n", frameNum);
		frameNum++;
		if (isCollision(snek.getHead()) || snek.isSelfCollision()) {
			isRunning = false;
			break;
		}
		system("cls");
		showGame(area);
		eat(snek, food,score);
		snek.showSnek(area);
		handleEvent(snek,isPaused);
		food.showFood(area);
		snek.setLength(length);
		printf("Score: %d\n", score);
		printf("Length: %d\n", length);
		if (frameNum % 10 == 0 && !isPaused) {
			if (!inputBuffer.empty()) {
				snek.event(inputBuffer.front());
				inputBuffer.pop();
			}
			snek.update();
		}
		b = GetTickCount64();
		if (b - a < frameRate) {
			Sleep(frameRate - (b - a));
		}
	}
	printf("Game Over\nPress any button to exit\n");
	_getch();
	return 0;
}