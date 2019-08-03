#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Goods
{
	//��ƷID
	int goodsId;

	//��Ʒ�۸�
	int price;

	//��Ʒ����
	char name[20];

	//���
	int stock;


	//�̼�Id
	int userId;
}Goods;

typedef struct GoodsNode {
	//��Ʒ��Ϣ
	Goods goods;

	//ǰһ����Ʒ
	GoodsNode* pre;

	//��һ����Ʒ
	GoodsNode* next;
}GoodsNode;

typedef struct GoodsList
{
	//ͷ
	GoodsNode* head;

	//β
	GoodsNode* tail;

	//��ЧԪ�ظ���
	int count;

}GoodsList;


//��ʼ��
void initGoodsList(GoodsList* p);


//�п�
bool judgeEmpotGoodsList(const GoodsList list);


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionGoods(GoodsList* p, const const int position, const Goods goods);


//ɾ��--����Idɾ��
Goods* deleteGoodsById(GoodsList* p, const int Id);



//����--����ֵ��ѯ���ز����û�
Goods* searchGoodsById(const GoodsList list, const int goodsId);

//���
void clearGoodsList(GoodsList* p);


//��ӡ����
void printGoodsrList(const GoodsList list);


//��ӡ������Ʒ��Ϣ
void printGoodsInfo(const Goods goods);


//����Ʒ��Ϣ���浽�ļ�
void saveGoods(const GoodsList list);


//���ļ��е���Ʒ��ȡ������
void getGoodsData(GoodsList* p);