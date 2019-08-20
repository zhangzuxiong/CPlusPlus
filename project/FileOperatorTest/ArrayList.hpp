
#include "ArrayList.h"


template <class T>
ArrayList<T>::ArrayList(const int num) :size(num), length(0) {
	list = new T[num];
}


template <class T>
ArrayList<T>::~ArrayList() {
	delete list;
}


//往数组中添加一个数据
template <class T>
void ArrayList<T>::add(const T data) {
	
	//数组已满动态申请内存
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



//获取第index个位置的数据
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




//是否为空
template <class T>
bool ArrayList<T>::isEmpoty() const {
	return this->length == 0;
}



//打印所有数据
template <class T>
void ArrayList<T>::print() const {
	for (int i = 0; i < length; i++)
	{
		cout << this->list[i];
	}
}


//返回数组的长度
template <class T>
int ArrayList<T>::getLength()const {
	return this->length;
}


//查找,返回数据的下标
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


//删除
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

