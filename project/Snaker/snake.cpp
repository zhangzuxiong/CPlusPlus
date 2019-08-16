#include "snake.h"
#include <windows.h>

void getoxy1(HANDLE hOut1, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);//
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������



Snake::Snake(Wall& tempWall, Food& tempFood) :wall(tempWall), food(tempFood) {
	pHead = NULL;
	isRool = false;//��Ĭ�ϲ�תȦ
}

//��ʼ����
void Snake::initSnake() {
	destoryPoint();		//�Ƚ�ԭ����������
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}
//�������нڵ�
void Snake::destoryPoint() {
	Point* pCur = pHead;
	while (pHead) {
		pCur = pHead->next;
		wall.setWall(pHead->x, pHead->y, ' ');//ɾ��ǰ�޸�������λ�õı�־
		//TODO...
		delete pHead;
		pHead = pCur;
	}
}
//��ӽڵ�
void Snake::addPoint(int x, int y) {
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//�����ͷ���գ��������ͷΪ����
	if (pHead) {
		wall.setWall(pHead->x, pHead->y, '=');
		getoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}
	newPoint->next = pHead;
	pHead = newPoint;			//������ͷ��λ��
	wall.setWall(pHead->x, pHead->y, '@');//������ͷ�ı�־@
	getoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";
}

void Snake::delPoint() {
	//�����ڵ����ϲ�ɾ��
	if (pHead == NULL || pHead->next == NULL)
		return;
	Point* pPre = pHead;
	Point* pCur = pHead->next;
	while (pCur->next) {
		pCur = pCur->next;
		pPre = pPre->next;
	}
	//ɾ��Ϊ�ڵ�
	wall.setWall(pCur->x, pCur->y, ' ');
	getoxy1(hOut1, pCur->y * 2, pCur->x);
	cout << " ";
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

//���ƶ�
bool Snake::move(char key) {
	//��ȡ��ǰ��ͷ��λ��
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

	//�����ͷ����һ��λ������β�����߲�Ӧ����������תȦ
	//Point* pPre = pHead;
	Point* pCur = pHead->next;
	while (pCur->next) {
		pCur = pCur->next;
		//pPre = pPre->next;
	}
	if (pCur->x == x && pCur->y == y) {
		isRool = true;//����ѭ��
	}
	else {
		//�ж���ͷ��Ŀ��λ���Ƿ����ȥ
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
			//�ߵ���һ��λ����ǽ������ʾ��������״̬ͼ
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "���յ÷֣�" << getScore() << endl;
			cout << "game over!" << endl;
			return false;
		}
	}


	//�ƶ��ɹ����Ե�ʳ��  δ�Ե�ʳ��
	if (wall.getWall(x, y) == '#') {
		addPoint(x, y);
		//����ʳ��
		food.setFood();
	}
	else {//δ�Ե�ʳ�ǰ��
		addPoint(x, y);
		delPoint();
		if (isRool) {//��ʱ��ͷ��Ҫ������β������ͷ��β��Ҫ��ͬһ��λ�����λ����Ҫ�ػ�
			wall.setWall(x, y, '@');
			getoxy1(hOut1, 2 * y, x);
			cout << "@";
		}
	}
	return true;
}
//��ȡˢ��ʱ��
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
//��ȡ�ߵĳ���
int Snake::countList() {
	Point* pTemp = pHead;
	int size = 0;
	while (pTemp) {
		pTemp = pTemp->next;
		++size;
	}
	return size;
}
//�÷�Ϊ�߳Ե�ʳ��ĸ���
int Snake::getScore() {
	return countList() - 3;
}
