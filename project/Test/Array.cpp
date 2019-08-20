
#include "Array.h"






//�вι���
template <class T>
Array<T>::Array(const int count) :data(new T[count]), length(0), size(count) {
	//data = { 0 };
}



//��������
template <class T>
Array<T>::Array(const Array& that) :data(new T[that.size]), length(that.length), size(that.size) {
	for (int i = 0; i < that.size; i++)
	{
		data[i] = that.data[i];
	}
}



//��������
template <class T>
Array<T>::~Array() {
	delete[] data;
	data = NULL;
	size = 0;
	length = 0;
}



//����=
template <class T>
Array<T>& Array<T>::operator=(const Array& right) {

	Array arr = right;
	T* temp = this.data;
	this->data = arr.data;
	arr.data = temp;

	this->length = right.length;
	this->size = right.size;
	return *this;
}


template <class T>
ostream& operator<<(ostream& os, const Array<T>& array) {
	for (int i = 0; i < array.length; i++)
	{
		os << array.data[i] << " ";
	}
	return os;
}




//����+=
template <class T>
Array<T>& Array<T>::operator+=(const Array& array) {
	T* temp = new T[this->size + array.size];
	int i = 0;
	for (i = 0; i < this->length; i++)
	{
		temp[i] = this->data[i];
	}

	int j = 0;
	for (j = 0; j < array.length; j++)
	{
		temp[i] = array.data[j];
		i++;
	}

	delete[] this->data;
	this->data = temp;
	this->length += array.length;
	this->size += array.size;
	return *this;
}





//����[],��Ϊ��ֵ
template <class T>
const T& Array<T>::operator[](const int index) const {
	if (index > this->length || index < 0)
	{
		throw exception("λ�ò���ȷ");
	}
	else
	{
		return this->data[index];
	}
}


//����[]����Ϊ��ֵ
template <class T>
T& Array<T>::operator[](const int index) {
	if (index<0 || index>this->size || index > this->length + 1)
	{
		throw exception("λ�ò���ȷ");
	}
	else
	{
		return this->data[index];
	}
}




//�����������һ������
template <class T>
void Array<T>::add(const T& t) {
	//���������������µ��ڴ�ռ�
	if (this->length == this->size)
	{
		this->resetSize();
	}

	this->data[length++] = t;
}




//��������������������,ÿ������һ���µ��ڴ�ռ�
template <class T>
void Array<T>::resetSize() {
	T* temp = new T[this->size + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = this->data[i];
	}
	delete[] this->data;
	this->size += 1;
	this->data = temp;
}