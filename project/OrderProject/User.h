#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct User
{
	//�û�Id
	int userId;

	//�û�����
	char passwd[15];

	//�û�����
	char name[20];

	//��ϵ��ʽ
	char phone[15];


	//�ռ���ַ
	char address[50];


	//�û�����
	int type;

	//��Ŷ���Id
	int orderList[SIZE];

	//�����ƷId
	int goodsList[SIZE];

}User;

typedef struct UserNode
{
	User user;

	//��һ���û�
	UserNode* next;

	//ǰһ���û�
	UserNode* pre;
}UserNode;

typedef struct UserList
{
	//ͷָ��
	UserNode* head;

	//βָ��
	UserNode* tail;

	//��ЧԪ�ظ���
	int count;
} UserList;


//��ʼ��
void initUserList(UserList* p);


//�п�
bool judgeEmpotUserList(const UserList list);


//���룬�ڵ�position��λ�ò���һ���û�
int insertPositionUser(UserList* p, const const int position, const User user);


//ɾ��--����Idɾ��
User* deleteUserById(UserList* p, const int Id);



//����--����ֵ��ѯ���ز����û�
User* searchUserById(const UserList list, const int userId);

//���
void clearUserList(UserList* p);


//��ӡ
void printUserList(const UserList list);


//ע��
void registerUser(UserList* p);


//��¼
User* loginUser(const UserList list);

//�����û���Ϣ
void saveUserData(const UserList usreList);


//��ȡ�û���Ϣ
void getUserData(UserList* userList);
