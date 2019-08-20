#pragma once

#include "LinkList.hpp"

template <class T>
class Queue {
private:
	//队列的有效元素个数
	int count;


	//队列的最大容量
	int max;


	//保存队列的链表
	LinkList<T> list;

public:

	//有参构造
	Queue(const int num);


	//析构函数
	~Queue();


	//判空
	bool isEmpotyQueue()const ;


	//判满
	bool isFullQueue()const ;



	//入队
	void putQueue(const T& data);



	//出队
	T* getQueue();




	//清空
	void clearQueue();



	//打印
	void printQueue()const;
};




