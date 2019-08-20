#pragma once

#include <iostream>
using namespace std;

class String
{
public:


	//�޲ι���
	String();




	//�вι���
	String(const char* str);





	//��������
	~String();



	//��������
	String(const String& that);



	//�Ƚϴ�С
	int compare(const String& right)const;




	//��ȡ�ַ����ĳ���
	int getLength()const;




	//=����
	String operator=(const String& right);




	//����+=
	String& operator+=(const String& right);



	//<<����
	friend ostream& operator<<(ostream& os, const String& right);



	//>>����
	friend istream& operator>>(istream& is, String& right);



	//��ȡԪ����
	char* getChar()const;

private:
	int length;
	char* data;

};

