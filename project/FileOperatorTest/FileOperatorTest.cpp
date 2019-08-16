// FileOperatorTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

#include "ArrayList.hpp"

using namespace std;

class A {


	int x;
	int y;


public:
	A():x(0),y(0){}
	A(int n1,int n2):x(n1),y(n2){}
	A(const A& that):x(that.x),y(that.y){}
	~A() {}

	friend ostream& operator<<(ostream& os, const A& a) {
		os << "x=" << a.x << ",y=" << a.y << endl;
		return os;
	}

	friend ofstream& operator<<(ofstream& ofs, const A& a) {
		ofs << a.x << "\t" << a.y << endl;
		return ofs;
	}

	friend ifstream& operator>>(ifstream& ifs, A& a) {
		ifs >> a.x;
		ifs >> a.y;
		return ifs;
	}

	friend istream& operator>>(istream& is, A& a) {
		cout << "请输入x:";
		is >> a.x;
		cout << "请输入y:";
		is >> a.y;
		return is;
	}
};


int main()
{

	/*ArrayList<int>* ll = new ArrayList<int>(4);
	ll->add(1);
	ll->add(2);
	ll->add(3);
	ll->print();
	return 0;*/

	


	const int size = 2;
	ArrayList<A>* list = new ArrayList<A>(size);
	A a;
	for (int i = 0; i < size; i++)
	{
		cin >> a;
		list->add(a);
	}

	list->print();
	cout << list->getLength() << endl;

	ofstream ofs("test.txt");

	for (int i = 1; i <= size; i++)
	{
		ofs << *(list->get(i));
	}

	ofs.close();

	cout << "读取文件" << endl;

	ifstream ifs("text.txt");

	for (int i = 0; i < size; i++)
	{
		ifs >> a;
		cout << a;
	}

	ifs.close();

	return 0;
}

