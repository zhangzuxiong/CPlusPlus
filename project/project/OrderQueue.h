#pragma once

#define QUEUE_SIZE 50

#include "Order.h"
// ˫����ʵ��ѭ������

typedef struct OrderQueue {

	// ��˫�����������������
	OrderList list;

	// ���е��������
	int max;

	// ��¼������е���ЧԪ�ظ���
	int count;

} OrderQueue;

// 1.��ʼ��
void initOrderQueue(OrderQueue* p);



// 2.�п� ���Ϊ�գ���Ϊ�棻����Ϊ��
int isEmptyOrderQueue(const OrderQueue queue);



// 3.���� ���Ϊ������Ϊ�棻����Ϊ��
int isFullOrderQueue(const OrderQueue queue);



// 4.����,p ��ʾ��Ҫ�����Ķ�����˭�� num ��ʾ��Ҫ�����β�Ķ����Ƕ���
void putOrderQueue(OrderQueue* p, const Order order);



// 5.ȡ��
Order* getOrderQueue(OrderQueue* p);



// 6.���
void clearOrderQueue(OrderQueue* p);



// 7.��ӡ
void printOrderQueue(const UserList userList, const GoodsList goodsList, const OrderQueue list);
