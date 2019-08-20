

#include "Queue.h"

//有参构造
template <class T>
Queue<T>::Queue(const int num):max(num),count(0),list() {
}


//析构函数
template <class T>
Queue<T>::~Queue() {

}


//判空
template <class T>
bool Queue<T>::isEmpotyQueue()const {
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//判满
template <class T>
bool Queue<T>::isFullQueue()const {
	if (count == max)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//入队 将元素加入链表末尾
template <class T>
void Queue<T>::putQueue(const T& data) {
	if (this->isFullQueue())
	{
		return;
	}

	this->list.add(this->list.size()+1, data);
	this->count++;
}



//出队  取出链表头结点
template <class T>
T* Queue<T>::getQueue() {
	if (this->isEmpotyQueue())
	{
		return NULL;
	}
	T* res = this->list.remove(1);
	this->count--;

	return res;
}




//清空
template <class T>
void Queue<T>::clearQueue() {
	if (this->isEmpotyQueue())
	{
		return;
	}

	this->list.clear();
	this->count = 0;
}



//打印
template <class T>
void Queue<T>::printQueue()const {
	if (this->isEmpotyQueue())
	{
		return;
	}

	this->list.print();
}