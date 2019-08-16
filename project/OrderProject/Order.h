#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Goods.h"
#include "User.h"


typedef struct Order
{
	//订单ID
	int orderId;

	//用户ID
	int userId;

	//商家Id
	int businessId;

	//收货人姓名
	char name[20];

	//收货人联系方式
	char phone[15];


	//订单收货地址
	char address[50];

	//下单时间
	char createDate[20];
	//状态,
	int status;


	//商品信息,保存商品的ID
	int goodsId[SIZE];


	//商品数量
	int count[SIZE];
} Order;

typedef struct OrderNode
{
	//订单
	Order order;

	//前一个订单
	OrderNode* pre;

	//下一个订单
	OrderNode* next;
}OrderNode;

typedef struct OrderList
{
	//头
	OrderNode* head;

	//尾
	OrderNode* tail;

	//有效元素个数
	int count;
}OrderList;



//初始化
void initOrderList(OrderList* p);


//判空
bool judgeEmpotOrderList(const OrderList list);


//插入，在第position个位置插入一个用户
int insertPositionOrder(OrderList* p, const int position, const Order order);


//删除--根据Id删除
Order* deleteOrderById(OrderList* p, const int Id);


//根据位置删除
Order* deletePositionOrderList(OrderList* p, const int position);


//查找--按照值查询返回查找用户
Order* searchOrderById(const OrderList list, const int orderId);


//查找返回订单节点
OrderNode* searchOrderNodeById(const OrderList list, const int orderId);

//更改订单
void updateOrderByOrder(OrderList* list,const Order order);

//清空
void clearOrderList(OrderList* p);

//打印一个数组
void printArray(int* p, int length);

//打印
void printOrderList(const UserList userList, const GoodsList goodsList, const OrderList list);

//打印一个订单
void printOrder(const UserList userList,const Order order);

//保存订单信息
void saveOrderInfo(const OrderList list);

//读取订单信息
void getOrderInfo(OrderList* p);