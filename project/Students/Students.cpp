// Students.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Student.h"

#include "LinkList.hpp"

#include "ArrayList.h"

int main()
{
	Student students[10];


	ArrayList<int>* data = new ArrayList<int>;
	data->add(3);
	data->add(5);
	data->add(7);
	data->print();
	cout << endl;
	cout << data->get(4) << endl;
	cout << data->isEmpoty() << endl;
	cout << data->remove(7) << endl << endl;
	data->print();
	data->add(5);
	data->add(7);
	cout << endl;
	data->print();
	cout << endl;

	return 0;


	LinkList<double>* list = new LinkList<double>;
	list->add(1, 1.1);
	list->add(1, 2.2);
	list->add(1, 3.3);
	list->add(4, 4.4);
	list->add(2, 5.5);
	list->add(7, 5.5);

	list->print();

	cout<<*(list->remove(1));
	cout << endl;
	list->print();

	

    return 0;
}

