
#include "ArrayList.h"


template <class T>
ArrayList<T>::ArrayList(const int num) :size(num), length(0) {
	list = new T[num];
}


template <class T>
ArrayList<T>::~ArrayList() {
	delete list;
}


//�����������һ������
template <class T>
void ArrayList<T>::add(const T data) {
	
	//����������̬�����ڴ�
	if (size == length)
	{
		T* newList = new T[length + 1];;
		for (int i = 0; i < length; i++)
		{
			newList[i] = this->list[i];
		}
		delete this->list;
		this->list = newList;
		this->list[length] = data;
		this->size++;
		this->length++;
	}
	else
	{
		this->list[length] = data;
		this->length++;
	}
}



//��ȡ��index��λ�õ�����
template <class T>
T* ArrayList<T>::get(const int index) const {
	if (index<1 || index>length)
	{
		return NULL;
	}
	else
	{
		return &(this->list[index - 1]);
	}
}




//�Ƿ�Ϊ��
template <class T>
bool ArrayList<T>::isEmpoty() const {
	return this->length == 0;
}



//��ӡ��������
template <class T>
void ArrayList<T>::print() const {
	for (int i = 0; i < length; i++)
	{
		cout << this->list[i];
	}
}


//��������ĳ���
template <class T>
int ArrayList<T>::getLength()const {
	return this->length;
}


//����,�������ݵ��±�
template <class T>
int ArrayList<T>::search(const T data)const {
	for (int i = 0; i < length; i++)
	{
		if (this->list[i] == data)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��
template <class T>
bool ArrayList<T>::remove(const T data) {
	int index = this->search(data);
	if (index < 0)
	{
		return false;
	}
	else
	{
		for (int i = index; i < length - 1; i++)
		{
			this->list[i] = this->list[i + 1];
		}

		this->length--;
		return true;
	}
}

