#include "snake.h"
#include <windows.h>

void getoxy1(HANDLE hOut1, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);//
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量



Snake::Snake(Wall& tempWall, Food& tempFood) :wall(tempWall), food(tempFood) {
	pHead = NULL;
	isRool = false;//蛇默认不转圈
}

//初始化蛇
void Snake::initSnake() {
	destoryPoint();		//先将原来的蛇销毁
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}
//销毁所有节点
void Snake::destoryPoint() {
	Point* pCur = pHead;
	while (pHead) {
		pCur = pHead->next;
		wall.setWall(pHead->x, pHead->y, ' ');//删除前修改蛇所在位置的标志
		//TODO...
		delete pHead;
		pHead = pCur;
	}
}
//添加节点
void Snake::addPoint(int x, int y) {
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//如何蛇头不空，则更改蛇头为蛇身
	if (pHead) {
		wall.setWall(pHead->x, pHead->y, '=');
		getoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}
	newPoint->next = pHead;
	pHead = newPoint;			//更新蛇头的位置
	wall.setWall(pHead->x, pHead->y, '@');//设置蛇头的标志@
	getoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";
}

void Snake::delPoint() {
	//两个节点以上才删除
	if (pHead == NULL || pHead->next == NULL)
		return;
	Point* pPre = pHead;
	Point* pCur = pHead->next;
	while (pCur->next) {
		pCur = pCur->next;
		pPre = pPre->next;
	}
	//删除为节点
	wall.setWall(pCur->x, pCur->y, ' ');
	getoxy1(hOut1, pCur->y * 2, pCur->x);
	cout << " ";
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

//蛇移动
bool Snake::move(char key) {
	//获取当前蛇头的位置
	int x = pHead->x;
	int y = pHead->y;
	switch (key) {
	case UP:
		--x;
		break;
	case DOWN:
		++x;
		break;
	case LEFT:
		--y;
		break;
	case RIGHT:
		++y;
		break;
	default:
		break;
	}

	//如果蛇头的下一个位置是蛇尾，则蛇不应死亡，而是转圈
	//Point* pPre = pHead;
	Point* pCur = pHead->next;
	while (pCur->next) {
		pCur = pCur->next;
		//pPre = pPre->next;
	}
	if (pCur->x == x && pCur->y == y) {
		isRool = true;//蛇在循环
	}
	else {
		//判断蛇头的目标位置是否可以去
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			//蛇的下一个位置是墙，则显示出蛇死的状态图
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "最终得分：" << getScore() << endl;
			cout << "game over!" << endl;
			return false;
		}
	}


	//移动成功：吃到食物  未吃到食物
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//重设食物
		food.setFood();
	}
	else {//未吃到食物，前进
		addPoint(x, y);
		delPoint();
		if (isRool) {//此时蛇头快要碰上蛇尾，即蛇头蛇尾将要在同一个位置这个位置需要重绘
			wall.setWall(x, y, '@');
			getoxy1(hOut1, 2 * y, x);
			cout << "@";
		}
	}
	return true;
}
//获取刷屏时间
int Snake::getSleepTime() {
	int size = countList();
	int sleepTime = 0;
	if (size < 5)
		sleepTime = 300;
	else if (size > 5 && size < 10)
		sleepTime = 200;
	else
		sleepTime = 100;
	return sleepTime;
}
//获取蛇的长度
int Snake::countList() {
	Point* pTemp = pHead;
	int size = 0;
	while (pTemp) {
		pTemp = pTemp->next;
		++size;
	}
	return size;
}
//得分为蛇吃掉食物的个数
int Snake::getScore() {
	return countList() - 3;
}
