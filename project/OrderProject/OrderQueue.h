#pragma once

#define QUEUE_SIZE 50

#include "Order.h"
// 双链表实现循环队列

typedef struct OrderQueue {

	// 用双链表来保存队列数据
	OrderList list;

	// 队列的最大容量
	int max;

	// 记录放入队列的有效元素个数
	int count;

} OrderQueue;

// 1.初始化
void initOrderQueue(OrderQueue* p);



// 2.判空 如果为空，则为真；否则为假
int isEmptyOrderQueue(const OrderQueue queue);



// 3.判满 如果为满，则为真；否则为假
int isFullOrderQueue(const OrderQueue queue);



// 4.放入,p 表示需要操作的队列是谁， num 表示需要放入队尾的订单是多少
void putOrderQueue(OrderQueue* p, const Order order);



// 5.取出
Order* getOrderQueue(OrderQueue* p);



// 6.清空
void clearOrderQueue(OrderQueue* p);



// 7.打印
void printOrderQueue(const UserList userList, const GoodsList goodsList, const OrderQueue list);
