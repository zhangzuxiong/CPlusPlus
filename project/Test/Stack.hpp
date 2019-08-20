#include "Stack.h"

template <class T>
Stack<T>::Stack() :count(0), list() {
}




//拷贝构造
template <class T>
Stack<T>::Stack(const Stack& that){
	//LinkList<T> list = that.list;
	this->list = that.list;
	count = that.count;
}




template <class T>
Stack<T>::~Stack() {
	
}


//判空
template <class T>
bool Stack<T>::isEmpltyStack()const {
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//入栈 在链表的头插入，在链表的头取出
template <class T>
void Stack<T>::push(const T& data) {
	this->list.add(1, data);
	this->count++;
}


//出栈 取出链表头结点
template <class T>
T* Stack<T>::pop() {
	if (this->isEmpltyStack())
	{
		return NULL;
	}
	T* res = this->list.remove(1);
	this->count--;
	return res;
}


//清空
template <class T>
void Stack<T>::clearStack() {
	if (this->isEmpltyStack())
	{
		return;
	}
	this->list.clear();
	this->count = 0;
}


//打印所有元素
template <class T>
void Stack<T>::printStack()const {
	if (this->isEmpltyStack())
	{
		return ;
	}
	this->list.print();
}