// String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class String {
private:
	int length;
	//int size;
	char* str;

public:
	String() :length(0),str(NULL){}

	String(const char* str){
		length = 0;
		while (str[length]!='\0')
		{
			length++;
		}

		this->str = new char[length+1];
		int i = 0;
		while (str[i]!='\0')
		{
			this->str[i] = str[i];
			i++;
		}
		this->str[i] = '\0';
	}

	String(const String& that) :str(new char[that.length+1]) {
		int i = 0;
		while (that.str[i]!='\0')
		{
			this->str[i] = that.str[i];
			i++;
		}
		this->str[i] = '\0';
		this->length = that.length;
	}

	~String() {
		delete[] str;
	}

	String operator=(const String& string) {
		delete[] this->str;

		str = new char[string.length + 1];
		this->length = string.length;

		int i = 0;
		while (string.str[i]!='\0')
		{
			str[i] = string.str[i];
			i++;
		}
		str[i] = '\0';

		return *this;
	}

	//重载+=
	String operator+=(const String right) {
		char* temp = new char[this->length + right.length + 1];

		int i = 0;
		while (this->str[i]!='\0')
		{
			temp[i] = this->str[i];
			i++;
		}

		i = 0;
		while (right.str[i]!='\0')
		{
			temp[this->length + i] = right.str[i];
			i++;
		}

		temp[this->length + i] = '\0';

		delete[] this->str;

		this->str = temp;

		//temp = NULL;

		this->length += right.length;
		return *this;
	}

	//返回长度
	const int getLength() const {
		return length;
	}

	//复制函数，将对象中的从start开始的count个字符字符串复制到ss中
	int copy(char* ss, const int count, const int start = 0) {
		if (ss==NULL)
		{
			return -1;
		}

		if (this->length-start<count)
		{
			//长度有误
			return -2;
		}

		int i = 0;
		for ( i = 0; i < count; i++)
		{
			ss[i] = this->str[start + i];
		}

		return i;
	}

	//判断相等，如果this小于str返回-1，如果this大于str返回1，如果相等返回0
	int compare(const char* str) const {
		if (str==NULL)
		{
			return -2;
		}

		int i = 0;
		while ((this->str[i]!='\0')||(str[i]!='\0'))
		{
			if (this->str[i]>str[i])
			{
				return 1;
			}
			else if (this->str[i]<str[i])
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

	int compare(const String& str) const {
		int i = 0;
		while ((this->str[i] != '\0') || (str.str[i] != '\0'))
		{
			if (this->str[i] > str.str[i])
			{
				return 1;
			}
			else if (this->str[i] < str.str[i])
			{
				return -1;
			}
			else
			{
				i++;
			}
		}
		//if((this->str[i]=='\0')&&(str.str[i]=='\0'))
		return 0;
	}


	//重载==
	bool operator==(const String& right) const {
		int i = 0;
		while ((this->str[i]!='\0')||(right.str[i]!='\0'))
		{
			if (this->str[i]!=right.str[i])
			{
				return false;
			}
			else
			{
				i++;
			}
		}

		return true;
	}

	//转为C语言字符串
	const char* c_str()const {
		return this->str;
	}

	//在字符串中查找
	int find(const char c, const int start = 0) const {
		int i = start;
		while (this->str[i]!='\0')
		{
			if (this->str[i]==c)
			{
				return i;
			}
			i++;
		}
		return -1;
	}

	int find(const char* s, const int start = 0) {
		if (s==NULL)
		{
			return -1;
		}

		int i = 0;
		int j = 0;
		bool flag = false;
		while (this->str[i]!='\0')
		{
			if (s[0]==this->str[i])
			{
				j = 0;
				while (s[j]!='\0')
				{
					if (s[j]==this->str[i+j])
					{
						flag = true;
					}
					else
					{
						flag = false;
					}
					j++;
				}
				if (flag)
				{
					return i;
				}
			}

			i++;
		}

		return -1;

	}

	//重载[]
	char& operator[](const int index) {
		//作为左值
		return this->str[index];
	}

	const char& operator[](const int index)const {
		//作为右值
		return this->str[index];
	}

	//重写输出
	friend ostream& operator<<(ostream& os,const String& str) {
		if (str.length!=NULL)
		{
			os << str.str;
		}
		return os;
	}



};

int main()
{

	String str1 = "qwerdf";

	cout << " str1 = " << str1 << endl;


	String str2 = "123";
	str2 += str1;
	cout << " str2 = " << str2 << endl;


	String str3;

	cout << " str3 = " << str3 << endl;

	str3 = str2;

	cout << " str3 = " << str3 << endl;


	String str4;

	str4 = str3 = str1;

	cout << " str4 = " << str4 << endl;


	String str5 = "123";

	str5 += str4;

	cout << " str5 = " << str5 << endl;

	cout << " str5.length = " << str5.getLength() << endl;


	String str6 = "zxc";

	str6 += str5 += str4;

	cout << " str6 = " << str6 << endl;

	cout << " str6.length = " << str6.getLength() << endl;


	char s1[20] = { 0 };

	str1.copy(s1, 6);

	cout << " s1 = " << s1 << endl;

	char s2[20] = "1234567890";

	str2.copy(s2, 4, 3);

	cout << " s2 = " << s2 << endl;


	char s3[10] = "1235";

	String str7 = "1234";

	cout << " str7.compare(s3) = " << str7.compare(s3) << endl;

	String str8 = "1233";

	cout << " str7.compare(str8) = " << str7.compare(str8) << endl;

	cout << " str7 == str8 = " << (str7 == str8) << endl;


	cout << " str8.c_str() = " << str8.c_str() << endl;


	String str9 = "1234567890987654321";

	cout << " str9.find('1') = " << str9.find('1') << endl;

	cout << " str9.find('1', 10) = " << str9.find('1', 10) << endl << endl << endl;

	cout << str9 << endl;
	cout << "str9.find(\"909\",0)=" << str9.find("909", 0) << endl;

	return 0;
}

