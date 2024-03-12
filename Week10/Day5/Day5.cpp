// Day5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "Template.h"
#include <iostream>

using namespace std;

//template <typename T>



int main()
{
	std::cout << "Hello World!\n";

	int Num = 1;
	int Num1 = 2;

	float Num2 = 3;
	float Num3 = 4;

	//swap(T Num, T  Num1);
	myswap(Num2, Num3);


	//cout << Num << endl;
	//cout << Num1 << endl;

	cout << Num2 << endl;
	cout << Num3 << endl;

	system("pause");

}

