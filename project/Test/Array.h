#pragma once

#include <iostream>

using namespace std;


template <class T>
class Array {
private:
	//存放数据的指针
	T* data;

	//数组的有效元素个数
	int length;

	//数组的容量
	int size;

public:

	//无参构造
	//Array() :data(NULL), length(0),size(0) {}



	//有参构造
	Array(const int count);


	
	//拷贝构造
	Array(const Array& that);


	
	//析构函数
	~Array();



	//重载=
	Array& operator=(const Array& right);




	//重载<<
	friend ostream& operator<<(ostream& os, const Array<T>& array) {
		for (int i = 0; i < array.length; i++)
		{
			os << array.data[i] << " ";
		}
		return os;
	}


	//重载+=
	Array& operator+=(const Array& array);





	//重载[],作为右值
	const T& operator[](const int index) const;


	//重载[]，作为左值
	T& operator[](const int index);




	//往数组中添加一个数据
	void add(const T& t);




	//重新设置数组对象的容量,每次申请一个新的内存空间
	void resetSize();

};


