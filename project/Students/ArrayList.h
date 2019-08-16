#pragma once

#include <iostream>

using namespace std;

template <class T>
class ArrayList {
private:

	//���Դ洢size��T
	int size;

	//��ЧԪ�ظ���
	int length;

	//�洢����
	T* list;

public:
	//ArrayList() : size(0), length(0),list(new T){}

	ArrayList(const int num);

	~ArrayList();

	

	//�����������һ������
	void add(const T data);


	//��ȡ��index��λ�õ�����
	T* get(const int index) const;

	

	//��������ĳ���
	int getLength()const;


	//����,�������ݵ��±�
	int search(const T data)const;


	//ɾ��
	bool remove(const T data);



	//�Ƿ�Ϊ��
	bool isEmpoty()const;


	//��ӡ��������
	void print()const;



	//��̬��չ�ڴ棬��ֹ����Խ��
	/*void copy(T* oldList, T* newList) {
		newList = new T[length + 1];
		for (int i = 0; i < length; i++)
		{
			newList[i] = oldList[i];
		}
	}*/


};





