#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Goods
{
	//商品ID
	int goodsId;

	//商品价格
	int price;

	//商品名称
	char name[20];

	//库存
	int stock;


	//商家Id
	int userId;
}Goods;

typedef struct GoodsNode {
	//商品信息
	Goods goods;

	//前一个商品
	GoodsNode* pre;

	//下一个商品
	GoodsNode* next;
}GoodsNode;

typedef struct GoodsList
{
	//头
	GoodsNode* head;

	//尾
	GoodsNode* tail;

	//有效元素个数
	int count;

}GoodsList;


//初始化
void initGoodsList(GoodsList* p);


//判空
bool judgeEmpotGoodsList(const GoodsList list);


//插入，在第position个位置插入一个用户
int insertPositionGoods(GoodsList* p, const const int position, const Goods goods);


//删除--根据Id删除
Goods* deleteGoodsById(GoodsList* p, const int Id);



//查找--按照值查询返回查找用户
Goods* searchGoodsById(const GoodsList list, const int goodsId);

//清空
void clearGoodsList(GoodsList* p);


//打印所有
void printGoodsrList(const GoodsList list);


//打印单个商品信息
void printGoodsInfo(const Goods goods);


//将商品信息保存到文件
void saveGoods(const GoodsList list);


//将文件中的商品读取到队列
void getGoodsData(GoodsList* p);