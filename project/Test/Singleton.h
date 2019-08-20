#pragma once

#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* single;
	
	static Singleton* getSingleton() {
		if (single==NULL)
		{
			single = new Singleton();
		}
		return single;
	}


private:


	Singleton() {

	}

	Singleton(const Singleton& that) {}
};

Singleton* Singleton::single = NULL;



class Singleton1 {
public:
	static Singleton1 single;

	static Singleton1& getSingleton1() {
		return single;
	}

private:
	Singleton1() {}
	Singleton1(const Singleton1& that) {}
};

Singleton1 Singleton1::single;