#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Goods.h"
#include "User.h"


typedef struct Order
{
	//����ID
	int orderId;

	//�û�ID
	int userId;

	//�̼�Id
	int businessId;

	//�µ�ʱ��
	char createDate[20];
	//״̬,
	int status;


	//��Ʒ��Ϣ,������Ʒ��ID
	int goodsId[SIZE];


	//��Ʒ����
	int count[SIZE];
} Order;

typedef struct OrderNode
{
	//����
	Order order;

	//ǰһ������
	OrderNode* pre;

	//��һ������
	OrderNode* next;
}OrderNode;

typedef struct OrderList
{
	//ͷ
	OrderNode* head;

	//β
	OrderNode* tail;

	//��ЧԪ�ظ���
	int count;
}OrderList;



//��ʼ��
void initOrderList(OrderList* p);


//�п�
bool judgeEmpotOrderList(const OrderList list);


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionOrder(OrderList* p, const const int position, const Order order);


//ɾ��--����Idɾ��
Order* deleteOrderById(OrderList* p, const int Id);


//����λ��ɾ��
Order* deletePositionOrderList(OrderList* p, const int position);


//����--����ֵ��ѯ���ز����û�
Order* searchOrderById(const OrderList list, const int orderId);

//���
void clearOrderList(OrderList* p);

//��ӡһ������
void printArray(int* p, int length);

//��ӡ
void printOrderList(const UserList userList, const GoodsList goodsList, const OrderList list);

//��ӡһ������
void printOrder(const UserList userList,const Order order);

//���涩����Ϣ
void saveOrderInfo(const OrderList list);

//��ȡ������Ϣ
void getOrderInfo(OrderList* p);