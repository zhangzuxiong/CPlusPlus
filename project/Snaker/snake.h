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
	//�ڵ�
	struct Point
	{
		int x, y;
		Point* next;
	};

	//��ʼ����
	void initSnake();
	//���ٽڵ�
	void destoryPoint();
	//��ӽڵ�
	void addPoint(int x, int y);
	//ɾ���ڵ㣨β�ڵ㣩
	void delPoint();

	//���ƶ�������ֵ�ж��Ƿ��ƶ��ɹ��� key��ʾ�ƶ�����
	bool move(char key);

	/************�趨�Ѷ�************/
	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�ߵĳ���
	int countList();
	//�÷�
	int getScore();

private:
	Point* pHead;	//��ͷ
	Wall& wall;		//����Ҫ������������
	Food& food;		//����ʳ���λ���ж�
	bool isRool;	//���Լ�תȦ
};

