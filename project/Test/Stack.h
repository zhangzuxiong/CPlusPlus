#pragma once

#include "LinkList.hpp"

template <class T>
class Stack
{
private:

	//ջ��ЧԪ�ظ���
	int count;


	//����ջԪ�ص�����
	LinkList<T> list;

public:
	//�޲ι���
	Stack();

	

	//��������
	Stack(const Stack& that);


	//��������
	~Stack();

	//�п�
	bool isEmpltyStack()const;


	//��ջ
	void push(const T& data);


	//��ջ
	T* pop();


	//���
	void clearStack();


	//��ӡ����Ԫ��
	void printStack()const;

};

