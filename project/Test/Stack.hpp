#include "Stack.h"

template <class T>
Stack<T>::Stack() :count(0), list() {
}




//��������
template <class T>
Stack<T>::Stack(const Stack& that){
	//LinkList<T> list = that.list;
	this->list = that.list;
	count = that.count;
}




template <class T>
Stack<T>::~Stack() {
	
}


//�п�
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


//��ջ �������ͷ���룬�������ͷȡ��
template <class T>
void Stack<T>::push(const T& data) {
	this->list.add(1, data);
	this->count++;
}


//��ջ ȡ������ͷ���
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


//���
template <class T>
void Stack<T>::clearStack() {
	if (this->isEmpltyStack())
	{
		return;
	}
	this->list.clear();
	this->count = 0;
}


//��ӡ����Ԫ��
template <class T>
void Stack<T>::printStack()const {
	if (this->isEmpltyStack())
	{
		return ;
	}
	this->list.print();
}