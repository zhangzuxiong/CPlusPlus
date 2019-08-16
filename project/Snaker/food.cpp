#include "food.h"
#include<ctime>
#include <windows.h>


void getoxy2(HANDLE hOut2, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut2, pos);//
}

HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

Food::Food(Wall& tempWall) :wall(tempWall) {

}

void Food::setFood() {
	srand((unsigned)time(NULL));
	//while保证食物放置在正确的位置
	while (1) {
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;
		//cout << foodX <<" "<< foodY << endl;
		//只有不是蛇身和蛇头的地方才可以生成食物
		if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX, foodY, '#');
			getoxy2(hOut2, foodY * 2, foodX);
			cout << "#";
			break;
		}
	}
}

