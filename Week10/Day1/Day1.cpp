// Day1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

//void swap(int x, int y); //形式函数声明
//void swap1(int* x, int* y); //指针函数声明
//void swap2(int& x, int& y);//引用调用
//int sum(int a, int b); //函数在main函数后面加载需要加 声明
//void ChangeArray(int Nums[]);
using namespace std;




int main()
{

#pragma region 函数

	/*return_type function_name(parameter list) 函数的组成部分
	{
		body of the function
	}*/

	/*函数传参*/
	//传值调用 
	//cout << "形式传参";
	//int a = 100;
	//int b = 200;

	//cout << "a"  << a << endl;
	//cout << "b"  << b << endl;
	//swap(a, b);//调用的时候不会影响实参

	//cout << "a"  << a << endl;
	//cout << "b" << b << endl;

	////指针调用
	//cout << "指针传参";
	//int a1 = 100;
	//int b1 = 200;

	//cout << "a" << a << endl;
	//cout << "b" << b << endl;
	//swap1(&a, &b); //调用的时候影响实参
	//cout << "a" << a << endl;
	//cout << "b" << b << endl;

	////引用调用
	//cout << "引用调用";
	//int a2 = 100;
	//int b2 = 200;

	//cout << "a" << a << endl;
	//cout << "b" << b << endl;
	//swap2(a, b); //调用的时候影响实参
	//cout << "a" << a << endl;
	//cout << "b" << b << endl;

	///*参数的默认值*/
	//int a3 = 100;
	//int b3 = 200;
	//int result;

	//result = sum(a, b);
	//cout << "sum" << result;
	//cout << "打印数组" << endl;
	//int Arr[]{ 1,2 ,3,4 };
	//ChangeArray(Arr);
	//cout << "size" << size(Arr);






#pragma endregion

#pragma region 文件读写

	try
	{

		int arr[]{ 1,2,3,4,5 };

		//写入文字
		//std::ofstream outfile;
		//outfile.open("test.txt", ios::app);
		//outfile << "okok1231" << endl;
		//outfile.close();

		//数组写入文字
		//ofstream outfile;
		//outfile.open("./test.txt", ios::app);
		////outfile << arr << endl; //写入了数组内存地址

		//for (int i = 0; i < size(arr); i++)
		//{
		//	outfile << arr[i] << endl;
		//}

		//outfile.close();

		//is_open() : 这是一个成员函数，当文件成功打开时返回 true，否则返回 false。
		// 通常在打开文件后需要检查文件是否成功打开，以确保可以正常读取文件内容。

		//eof() : 这是一个成员函数，用于检查文件是否已经到达文件末尾(End Of File)。
		// 当文件指针到达文件末尾时，eof() 函数返回 true；否则返回 false。在循环读取文件内容时，通常会在循环中使用 eof() 函数来判断是否已经读取完整个文件。
		char data[100];
		ifstream ReadFile;
		ReadFile.open("test.txt");
		if (ReadFile.is_open()) {
			while (!ReadFile.eof()) {
				ReadFile.getline(data, 100);
				cout << data << endl;
			}

			ReadFile.close();
		}
		else {
			cout << "无法打开文件" << endl;
		}
		system("pause");
		return 0;

	}
	catch (const std::exception& e)
	{
		cout << "pause";
		cout << "MyException" << endl;
		cout << e.what() << endl;
		system("pause");
	}


#pragma endregion





}
//void swap(int x, int y) {
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//
//	return;
//}
//void swap1(int* x, int* y) {
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//	return;
//}
//void swap2(int& x, int& y) {
//	int temp;
//	temp = x;
//	x = y;
//	y = temp;
//	return;
//}
//int sum(int a, int b) { //int类型函数不需要提前声明
//	int result;
//	result = a + b;
//	return (result);
//}	
//void ChangeArray(int Nums[]) {
//	for (int i = 0; i < sizeof(Nums) / sizeof(Nums[0]); i++)
//	{
//		cout << Nums[i] << endl;;
//	}
//	cout << sizeof(Nums) << endl;
//}