#pragma once
#include "wall.h"

class Food {
public:
	Food(Wall& tempWall);
	void setFood();
private:
	int foodX;
	int foodY;
	Wall& wall;		//ʳ��Ҫ�����ڶ�ά������
};
