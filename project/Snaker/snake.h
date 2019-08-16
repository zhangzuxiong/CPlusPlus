#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;

class Snake {
public:
	enum {
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};

	Snake(Wall& tempWall, Food& tempFood);
	//节点
	struct Point
	{
		int x, y;
		Point* next;
	};

	//初始化蛇
	void initSnake();
	//销毁节点
	void destoryPoint();
	//添加节点
	void addPoint(int x, int y);
	//删除节点（尾节点）
	void delPoint();

	//蛇移动（返回值判断是否移动成功） key表示移动按键
	bool move(char key);

	/************设定难度************/
	//获取刷屏时间
	int getSleepTime();
	//获取蛇的长度
	int countList();
	//得分
	int getScore();

private:
	Point* pHead;	//蛇头
	Wall& wall;		//蛇需要绘制在数组中
	Food& food;		//蛇与食物的位置判断
	bool isRool;	//蛇自己转圈
};

