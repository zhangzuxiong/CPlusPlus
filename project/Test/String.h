#pragma once

#include <iostream>
using namespace std;

class String
{
public:


	//无参构造
	String();




	//有参构造
	String(const char* str);





	//析构函数
	~String();



	//拷贝构造
	String(const String& that);



	//比较大小
	int compare(const String& right)const;




	//获取字符长的长度
	int getLength()const;




	//=重载
	String operator=(const String& right);




	//重载+=
	String& operator+=(const String& right);



	//<<重载
	friend ostream& operator<<(ostream& os, const String& right);



	//>>重载
	friend istream& operator>>(istream& is, String& right);



	//获取元数据
	char* getChar()const;

private:
	int length;
	char* data;

};

