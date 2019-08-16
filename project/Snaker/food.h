#pragma once
#include "wall.h"

class Food {
public:
	Food(Wall& tempWall);
	void setFood();
private:
	int foodX;
	int foodY;
	Wall& wall;		//食物要绘制在二维数组中
};
