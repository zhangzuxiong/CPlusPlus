// ConsoleApplication5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	ofstream ofs("text.txt");

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
	{
		ofs << arr[i]<<"\t";
	}

	ofs.close();

	ifstream ifs("text.txt");

	int arr1[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		ifs >> arr1[i];
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << "\t";
	}

	ifs.close();

	return 0;
}

