// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>

using namespace std;

class A {

private:
	int num;
	int value;

public:

	A() :num(0), value(0) {

	}

	A(int a, int b) :num(a), value(b) {

	}

	A(const A& that) : num(that.num), value(that.value) {
		cout << "拷贝函数" << endl;
	}

	//重载  +
	A operator+(const A& a) const {
		A temp;
		temp.num = num + a.num;
		temp.value = value + a.value;
		return temp;
	}


	//友元函数重载  -
	friend A operator-(const A& a1, const A& a2);

	//重载 *
	A operator*(const A& a)const {
		return A(this->num * a.num, this->value * a.value);
	}


	//重载  /   取余
	A operator/(const A& a) const {
		return A(this->num / a.num, this->value / a.value);
	}


	//重载  %
	A operator%(const A& a) const {
		return A(this->num % a.num, this->value % a.value);

	}


	//重载  =  左边不能加  const  左值要修改因此不能加const
	A operator=(const A& a) {
		this->num = a.num;
		this->value = a.value;
		return A(a.num, a.value);
	}


	//重载  ==
	bool operator==(const A& a) const {
		return (this->num == a.num) && (this->value == a.value);
	}

	//重载  !=
	bool operator!=(const A& a) const {
		return (this->num != a.num) || (this->value != a.value);
	}


	//重载 <
	bool operator<(const A& a) const {
		return (this->num < a.num) && (this->value < a.num);
	}


	//重载 >
	bool operator>(const A& a) const {
		return ((this->num > a.num) && (this->value > a.num));
	}

	//重载 >=
	bool operator>=(const A& a) const {
		return (this->num >= a.num) && (this->value >= a.num);
	}

	//重载 <=
	bool operator<=(const A& a) const {
		return (this->num <= a.num) && (this->value <= a.num);
	}

	//重载 +=
	void operator+=(const A& a) {
		this->num += a.num;
		this->value += a.value;
	}


	//重载 -=
	void operator-=(const A& a) {
		this->num -= a.num;
		this->value -= a.value;
	}


	//重载 /=
	void operator/=(const A& a) {
		this->num /= a.num;
		this->value /= a.value;
	}

	//重载 *=
	void operator*=(const A& a) {
		this->num *= a.num;
		this->value *= a.value;
	}

	//重载 %=
	void operator%=(const A& a) {
		this->num %= a.num;
		this->value %= a.value;
	}


	//重载输出 <<
	friend void operator<<(ostream& os, const A& a);

	//重载输入 >>
	friend void operator>>(istream& in, A& a);



	/*static A operator/(const A& a1, const A& a2) {
		return A(a1.num*a2.num,a1.value*a2.value);
	}*/

	void print() const {
		cout << "num=" << num << ",value=" << value << endl;
	}
};

/*A A::operator/(const A& a1, const A& a2) {
	return A(a1.num * a2.num, a1.value * a2.value);
}*/

A operator-(const A& a1, const A& a2) {
	A temp;
	temp.num = a1.num - a2.num;
	temp.value = a1.value - a2.value;
	return temp;
}
void operator<<(ostream& os, const A& a) {
	os << "num=" << a.num << ",value=" << a.value << endl;
}

void operator>>(istream& in, A& a) {
	in >> a.num;
	in >> a.value;
}


int main()
{

	const A a1(10, 20);
	cout << "a1:";
	a1.print();

	const A a2(5, 10);
	cout << "a2:";
	a2.print();

	A a3;

	A a4;

	a3 = a4 = a1;

	cout << a3;
	cout << a4;

	a3 = a1 + a2;
	cout << a3;

	a3 = a1 - a2;
	cout << a3;

	a3 = a1 * a2;
	cout << a3;

	a3 = a1 / a2;
	cout << a3;

	a3 = a1 % a2;
	cout << a3;

	cout << (a1 > a2) << endl;
	cout << (a1 < a2) << endl;
	cout << (a1 >= a2) << endl;
	cout << (a1 <= a2) << endl;
	cout << (a1 == a2) << endl;
	cout << (a1 != a2) << endl;

	a3 = a2;
	a3 += a1;
	cout << a3;

	a3 = a2;
	a3 -= a1;
	cout << a3;

	a3 = a2;
	a3 *= a1;
	cout << a3;

	a3 = a2;
	a3 /= a1;
	cout << a3;


	a3 = a2;
	a3 %= a1;
	cout << a3;


	cout << typeid(A).name() << endl;

	return 0;
}


