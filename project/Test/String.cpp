#include "String.h"





//无参构造
String::String() :length(0), data(NULL) {

}




//有参构造
String::String(const char* str) :length(0), data(NULL) {
	if (str==NULL)
	{
		return;
	}
	while (str[length] != 0)
	{
		length++;
	}

	data = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		data[i] = str[i];
	}
	data[length] = 0;
}





//析构函数
String::~String() {
	delete[] data;
}



//拷贝构造
String::String(const String& that) :data(new char[that.length + 1]) {
	int i = 0;
	while (that.data[i] != 0)
	{
		this->data[i] = that.data[i];
		i++;
	}
	this->length = that.length;
	this->data[i] = 0;
}



//比较大小
int String::compare(const String& right)const {

	int i = 0;
	int j = 0;
	while ((this->data[i] != 0) || (right.data[i] != 0))
	{
		if (this->data[i] > right.data[i])
		{
			return 1;
		}
		else if (this->data[i] < right.data[i])
		{
			return -1;
		}
		else
		{
			i++;
		}
	}
	return 0;
}




//获取字符长的长度
int String::getLength()const {
	return length;
}




//=重载
String String::operator=(const String& right) {
	delete[] this->data;
	this->data = new char[right.length + 1];
	this->length = right.length;
	int i = 0;
	while (right.data[i] != 0)
	{
		this->data[i] = right.data[i];
		i++;
	}
	data[i] = 0;
	return *this;
}




//重载+=
String& String::operator+=(const String& right) {
	this->length += right.length;
	char* temp = new char[this->length + 1];
	int i = 0;
	while (this->data[i] != 0)
	{
		temp[i] = this->data[i];
		i++;
	}

	int j = 0;
	while (right.data[j] != 0)
	{
		temp[i] = right.data[j];
		i++;
		j++;
	}
	temp[i] = 0;
	delete[] this->data;
	this->data = temp;
	return *this;
}



//<<重载
ostream& operator<<(ostream& os, const String& right) {
	if (right.length > 0)
	{
		os << right.data;
	}
	return os;
}



//>>重载
istream& operator>>(istream& is, String& right) {

	char str[200] = { 0 };
	char c = 0;
	int i = 0;
	while ((c = getchar()) != '\n')
	{
		str[i] = c;
		i++;
	}

	right.data = new char[i + 1];
	right.length = i;

	for (i = 0; i < right.length; i++)
	{
		right.data[i] = str[i];
	}
	right.data[i] = 0;

	return is;
}


char* String::getChar()const {
	return this->data;
}
