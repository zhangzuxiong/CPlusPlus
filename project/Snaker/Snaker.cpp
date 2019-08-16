#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "wall.h"
#include"snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>

void getoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);//
}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

int main() {
	bool isDead = false;//初始假设蛇未死亡
	char preKey = NULL;//上一次的按键输入

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	getoxy(hOut, 0, Wall::ROW);
	cout << "当前得分：" << snake.getScore() << endl;
	while (!isDead) {
		char key = _getch();
		//启动游戏时，蛇静止，按下左键‘a’蛇不动，也不会死，等待下一次有效按键
		if (preKey == NULL && key == snake.LEFT)
			continue;
		do {
			//本次按键方向与上一次完全相反
			if ((key == snake.UP && preKey == snake.DOWN) ||
				(key == snake.DOWN && preKey == snake.UP) ||
				(key == snake.RIGHT && preKey == snake.LEFT) ||
				(key == snake.LEFT && preKey == snake.RIGHT)) {
				key = preKey;
			}
			else {
				preKey = key;//按键与蛇前进方向不冲突  更新按键
			}
			//只有wasd时蛇才移动
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT) {
				if (snake.move(key)) {
					//system("cls");
					//wall.drawWall();
					getoxy(hOut, 0, Wall::ROW);
					cout << "当前得分：" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;//蛇死亡
					break;		  //退出内层while
				}
			}
			else {//对wasd以外的按键不反应（不改变前进方向）
				key = preKey;//强制将wasd以外的按键更改为上次的移动按键
			}
			preKey = key;

		} while (!_kbhit());//当没有键盘输入的时候返回0
	}
	system("pause");
	return 0;
}
