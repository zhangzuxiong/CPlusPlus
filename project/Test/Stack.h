#pragma once

#include "LinkList.hpp"

template <class T>
class Stack
{
private:

	//栈有效元素个数
	int count;


	//保存栈元素的链表
	LinkList<T> list;

public:
	//无参构造
	Stack();

	

	//拷贝构造
	Stack(const Stack& that);


	//析构函数
	~Stack();

	//判空
	bool isEmpltyStack()const;


	//入栈
	void push(const T& data);


	//出栈
	T* pop();


	//清空
	void clearStack();


	//打印所有元素
	void printStack()const;

};

