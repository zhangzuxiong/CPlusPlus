#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct User
{
	//用户Id
	int userId;

	//用户密码
	char passwd[15];

	//用户姓名
	char name[20];

	//联系方式
	char phone[15];


	//收件地址
	char address[50];


	//用户类型
	int type;

	//存放订单Id
	int orderList[SIZE];

	//存放商品Id
	int goodsList[SIZE];

}User;

typedef struct UserNode
{
	User user;

	//下一个用户
	UserNode* next;

	//前一个用户
	UserNode* pre;
}UserNode;

typedef struct UserList
{
	//头指针
	UserNode* head;

	//尾指针
	UserNode* tail;

	//有效元素个数
	int count;
} UserList;


//初始化
void initUserList(UserList* p);


//判空
bool judgeEmpotUserList(const UserList list);


//插入，在第position个位置插入一个用户
int insertPositionUser(UserList* p, const const int position, const User user);


//删除--根据Id删除
User* deleteUserById(UserList* p, const int Id);



//查找--按照值查询返回查找用户
User* searchUserById(const UserList list, const int userId);

//清空
void clearUserList(UserList* p);


//打印
void printUserList(const UserList list);


//注册
void registerUser(UserList* p);


//登录
User* loginUser(const UserList list);

//保存用户信息
void saveUserData(const UserList usreList);


//读取用户信息
void getUserData(UserList* userList);
