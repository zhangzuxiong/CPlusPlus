#pragma once

#include "LinkList.hpp"

template <class T>
class Queue {
private:
	//���е���ЧԪ�ظ���
	int count;


	//���е��������
	int max;


	//������е�����
	LinkList<T> list;

public:

	//�вι���
	Queue(const int num);


	//��������
	~Queue();


	//�п�
	bool isEmpotyQueue()const ;


	//����
	bool isFullQueue()const ;



	//���
	void putQueue(const T& data);



	//����
	T* getQueue();




	//���
	void clearQueue();



	//��ӡ
	void printQueue()const;
};




