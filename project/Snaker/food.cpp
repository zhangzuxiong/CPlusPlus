#include "food.h"
#include<ctime>
#include <windows.h>


void getoxy2(HANDLE hOut2, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut2, pos);//
}

HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������

Food::Food(Wall& tempWall) :wall(tempWall) {

}

void Food::setFood() {
	srand((unsigned)time(NULL));
	//while��֤ʳ���������ȷ��λ��
	while (1) {
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;
		//cout << foodX <<" "<< foodY << endl;
		//ֻ�в����������ͷ�ĵط��ſ�������ʳ��
		if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX, foodY, '#');
			getoxy2(hOut2, foodY * 2, foodX);
			cout << "#";
			break;
		}
	}
}

