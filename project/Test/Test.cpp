// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Stack.hpp"
//#include "Queue.hpp"
#include "Singleton.h"
#include "Array.cpp"
#include "String.h"

void TestStack() {
	Stack<int> stack;
	int* res = NULL;
	for (int i = 0; i < 4; i++)
	{
		stack.push(i+1);
	}
	cout << endl << endl;

	/*Stack<int> s1 = stack;
	cout << "拷贝构造" << endl;
	s1.printStack();
	cout << endl;*/

	for (int i = 0; i < 4; i++)
	{
		res = stack.pop();
		if (res!=NULL)
		{
			cout << *res << "\t";
		}
	}

	cout << endl;
	stack.printStack();
	cout << endl << endl;

}

//void TestQueue() {
//	Queue<int> queue(10);
//	int* res = NULL;
//	cout << "入队:";
//	for (int i = 0; i < 11; i++)
//	{
//		cout << i << "\t";
//		queue.putQueue(i + 1);
//	}
//	cout << endl << endl;
//
//	cout << "队列元素：";
//	queue.printQueue();
//
//	cout << endl << endl;
//
//	cout << "出队：";
//	for (int i = 0; i < 10; i++)
//	{
//		res = queue.getQueue();
//		cout << *res << "\t";
//	}
//}


void TestSingleton() {
	Singleton* singlep1 = Singleton::getSingleton();
	Singleton* singlep2 = Singleton::getSingleton();
	cout << singlep1 << "\t" << singlep2 << endl << endl;

	Singleton1& single1 = Singleton1::getSingleton1();
	Singleton1& single2 = Singleton1::getSingleton1();
	cout << &single1 << "\t" << &single2 << endl << endl;
}


void TestString() {
	String* str1 = new String("12345");
	String* str2 = new String("12345");
	cout << (str1->compare(*str2)) << endl;
	cout << *str1 << endl << str1->getLength() << endl;

	String str3;
	cin >> str3;
	cout << str3 << endl << str3.getLength() << endl;

	String str4 = "1234567890";
	str3 += str4;
	cout << str3 << endl << str3.getLength() << endl;
}


void TestArray() {
	Array<int>* arr = new Array<int>(10);
	for (int i = 0; i < 10; i++)
	{
		arr->add(i+1);
	}

	cout << (*arr) << endl;
	arr->add(11);
	cout << (*arr) << endl;
	Array<int> arr1 = *arr;
	arr1 += *arr;
	cout << arr1 << endl;

	try
	{
		arr1[-1] = 99;
		cout << arr1[0] << endl;
		cout << arr1 << endl;

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
}


void TestLinkList() {
	LinkList<int> list;
	list.add(1,3);
	list.add(1,2);
	list.add(1,1);
	list.print();
	//cout << list.size() << endl;

	cout << endl << endl;
	LinkList<int> list1 = list;
	list1.print();
	cout << endl << &list << endl << &list1 << endl;

}


int main()
{



	TestLinkList();



	//TestArray();


	//String str1;
	//str1 = NULL;


	//cout << NULL << endl;
	//cout << typeid(NULL).name() << endl;

	//TestLongLongInt();

	//TestString();

	//TestSingleton();


	//TestQueue();

	TestStack();

	return 0;
}


