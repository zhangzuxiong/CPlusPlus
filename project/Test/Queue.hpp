

#include "Queue.h"

//�вι���
template <class T>
Queue<T>::Queue(const int num):max(num),count(0),list() {
}


//��������
template <class T>
Queue<T>::~Queue() {

}


//�п�
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


//����
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



//��� ��Ԫ�ؼ�������ĩβ
template <class T>
void Queue<T>::putQueue(const T& data) {
	if (this->isFullQueue())
	{
		return;
	}

	this->list.add(this->list.size()+1, data);
	this->count++;
}



//����  ȡ������ͷ���
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




//���
template <class T>
void Queue<T>::clearQueue() {
	if (this->isEmpotyQueue())
	{
		return;
	}

	this->list.clear();
	this->count = 0;
}



//��ӡ
template <class T>
void Queue<T>::printQueue()const {
	if (this->isEmpotyQueue())
	{
		return;
	}

	this->list.print();
}