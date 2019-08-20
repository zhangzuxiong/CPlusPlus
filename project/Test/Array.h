#pragma once

#include <iostream>

using namespace std;


template <class T>
class Array {
private:
	//������ݵ�ָ��
	T* data;

	//�������ЧԪ�ظ���
	int length;

	//���������
	int size;

public:

	//�޲ι���
	//Array() :data(NULL), length(0),size(0) {}



	//�вι���
	Array(const int count);


	
	//��������
	Array(const Array& that);


	
	//��������
	~Array();



	//����=
	Array& operator=(const Array& right);




	//����<<
	friend ostream& operator<<(ostream& os, const Array<T>& array) {
		for (int i = 0; i < array.length; i++)
		{
			os << array.data[i] << " ";
		}
		return os;
	}


	//����+=
	Array& operator+=(const Array& array);





	//����[],��Ϊ��ֵ
	const T& operator[](const int index) const;


	//����[]����Ϊ��ֵ
	T& operator[](const int index);




	//�����������һ������
	void add(const T& t);




	//��������������������,ÿ������һ���µ��ڴ�ռ�
	void resetSize();

};


