// DesignPatterns.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

// 饿汉--单例模式
class Singleton {
public:

	int num;

	// 公开一个接口 来产生一个 对象
	static Singleton* get_Singleton() {

		return &singl;
	}

	// 类内 静态成员 （自身对象） 唯一
	static Singleton singl;

private:

	// 构造函数
	Singleton() : num(0) {

	}

	// 拷贝构造函数
	Singleton(const Singleton& singl) {

	}
};

Singleton Singleton::singl;


// 懒汉--单例模式
class SingletonPattern {

public:

	static SingletonPattern* getSingletonPattern() {

		if (single==NULL)
		{
			single =new SingletonPattern();
		}

		return single;
	}

	int num;

	static SingletonPattern* single;

private:

	// 构造函数
	SingletonPattern() : num(0) {

	}

	// 拷贝构造函数
	SingletonPattern(const SingletonPattern& single) {

	}

};

SingletonPattern* SingletonPattern::single=NULL;


int main()
{
	Singleton* s = Singleton::get_Singleton();

	s->num = 100;

	cout << " s->num = " << s->num << endl;



	Singleton* s1 = Singleton::get_Singleton();

	//s1->num = 101;

	cout << " s1->num = " << s1->num << endl;


	cout << "=================================" << endl;

	SingletonPattern* single = SingletonPattern::getSingletonPattern();

	single->num = 200;

	cout << "single->num=" << single->num <<endl;

	SingletonPattern* single1 = SingletonPattern::getSingletonPattern();

	single1->num = 201;

	cout << "single1->num=" << single1->num << endl; 
	cout << "single->num=" << single->num << endl;


	return 0;
}
