#pragma once

#include <iostream>

using namespace std;

template <class T>
class ArrayList {
private:

	//可以存储size个T
	int size;

	//有效元素个数
	int length;

	//存储数据
	T* list;

public:
	//ArrayList() : size(0), length(0),list(new T){}

	ArrayList(const int num);

	~ArrayList();

	

	//往数组中添加一个数据
	void add(const T data);


	//获取第index个位置的数据
	T* get(const int index) const;

	

	//返回数组的长度
	int getLength()const;


	//查找,返回数据的下标
	int search(const T data)const;


	//删除
	bool remove(const T data);



	//是否为空
	bool isEmpoty()const;


	//打印所有数据
	void print()const;



	//动态扩展内存，防止数组越界
	/*void copy(T* oldList, T* newList) {
		newList = new T[length + 1];
		for (int i = 0; i < length; i++)
		{
			newList[i] = oldList[i];
		}
	}*/


};





