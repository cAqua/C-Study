// Day4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;


void Fun(int* a, int* b);

string* AddendStr(string Str) {
	string TempStr = Str + "Hello";
	return &TempStr;
}

string* pStr = nullptr;

void ChangePStr() {
	string Str = "321";
	pStr = &Str;
	cout << "函数内部" << pStr << endl;
};

struct FName {
	string Name;
};

void ChangeFName(FName* obj) {
	//obj.Name = 
	(*obj).Name = "123";
	cout << obj->Name << endl;
}

struct AA
{
	int a = 5;
};

struct FStudent
{
	string Name;
	int ID;
	int* pID = nullptr;
};


void TestStudent(FStudent* Stu)
{
	// Stu->ID = 0;
	// Stu是一个指针，*解引用变成普通结构体 
	(*Stu).ID = 0;
}
struct MyStruct // 12
{
	char C1; // 4（3）
	int ID;  // 4
	char C2; // 4（3）
};

struct MyStruct1 // 8
{
	char C1; // 4(3)
	char C2; // (2)
	int ID; // 4(0)
};

struct MyStruct2 // 88 
{
	string Str = ""; // 40 
	string Str1 = ""; // 40 
	char c1; // 8(7)
	char C2; //
	int ID; // 
};


int main()
{
#pragma region 指针基本概念

	/*
	指针概念 : 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，
	您必须在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为
	*/
	//int var = 20; // 实际变量的声明
	//int* ip; // 指针变量的声明

	//ip = &var; // 在指针变量中存储 var 的地址

	//string str = "123";
	//string* strIp = &str;

	////string ipp = &var;

	//cout << "实际变量var :" << var << endl;

	//cout << "存储了var内存地址指针变量*ip  : " << ip << endl;

	//cout << "指向了var内存地址的值ip : " << *ip << endl;

	//cout << strIp << endl;

#pragma endregion

#pragma region Null指针

	//int num = 20;
	//int* numIp = &num;

	//cout << *numIp << endl;

	//int* numIp1 = NULL;

	//cout << &numIp1;



#pragma endregion

#pragma region 指针的算术运算符

	//const int MAX = 3;

	//int Num = 5;
	//int* NumIp = &Num;
	//int Arr[MAX]{ 10,100,200 };
	//int* Ptr = Arr;
	//char* a;

	//cout << "Num内存地址" << NumIp << endl;
	//cout << *--Ptr << endl;

	//for (int i = 0; i < MAX; i++)
	//{
	//	cout << "Address of var[" << i << "] = ";
	//	cout << Ptr << endl;

	//	cout << "Value of var[" << i << "] = ";
	//	cout << *Ptr << endl;

	//	// 移动到下一个位置
	//	Ptr++;
	//}

	//int Num = 1;
	//int* NumIp = &Num;

	//cout << *NumIp << endl;
	//cout << NumIp++ << endl;
	//cout << *NumIp << endl;

#pragma endregion

#pragma region 二级指针

	// int 存在既有地址

	//int a = 0;

	//int* b = &a;

	//int** c = &b;

	//cout << **c;


#pragma endregion

#pragma region 无效指针的几种情况

	//int* pNum = nullptr;
	//cout << pNum << endl;
	//cout << *pNum << endl; //报错不能对nullptr解开引用

	// 现象1 、指针如 nullptr, 直接打即指针没有问以（不同系统可能会有不同的结果）， nullptr* 解引用白分之白崩溃 / 
	// 结论1 、使用指针之前需要先判断是不是空指针，如果是就停止运行，如果不是再继续

	//string* pString = nullptr;
	//cout << *pString << endl;

	//struct FUserInfo
	//{
	//	int ID = 0;
	//	string Name;
	//};
	//FUserInfo UserInfo;
	//FUserInfo* pUserInfo = &UserInfo;
	//cout << UserInfo.ID << endl;
	//cout << pUserInfo->ID;

#pragma endregion

#pragma region 动态内存分配 new delete

	//struct MyStruct
	//{
	//	string Name;
	//	MyStruct* next;
	//};



	//MyStruct Fhead = {
	//	"张三",
	//	nullptr,
	//};

	//MyStruct Fhead1 = {
	//"李四",
	//nullptr,
	//};

	//cout << Fhead.next;

	//return 0;

	//int Num = 123;

	//int* pNum = &Num;

	//cout << *pNum << endl;

	//int* pNum1 = new int(321);

	//cout << *pNum1 << endl;

	////delete pNum;

	//delete pNum1;
	//pNum1 = nullptr;

	//2个变量的内存地址一样 , 他们就是一个变量

#pragma endregion

#pragma region 指针函数 : 值传递和指针传递



	//int Num1 = 1;
	//int Num2 = 2;
	//int* pNum1 = &Num1;

	//cout << Num1 << "  " << Num2 << endl;
	//cout << pNum1;
	//Fun(&Num1, &Num2);
	//cout << Num1 << "  " << Num2 << endl;




#pragma endregion


#pragma region 指针作为函数返回地址

	//cout << *AddendStr("123"); // 函数在取地址的时候返回的地址已经销毁了

#pragma endregion

#pragma region 指针作为全局变量注意点

	//string Str = "123";
	//cout << pStr << endl;
	//pStr = &Str;
	//cout << pStr << endl;
	//ChangePStr();
	///*
	//无法访问 , 因为pstr在函数内部已经被更改了地址了 ,但是那个地址随着函数弹栈被销毁了 ,
	//避免在函数里面更改全局指针
	//*/
	//cout << "123" <<  * pStr << endl; 

#pragma endregion

#pragma region 结构体指针

	//结构体作为函数参数默认不会更改其值
	//传递指针会
	//FName StrBody = { "zhangsan" };
	//ChangeFName(&StrBody);
	//cout << StrBody.Name;

	/*结构体中包含指针*/
	//int Num = 100;
	//FStudent Stu1{ "张三",1000,&Num }; //声明的时候吧&Num的地址指向Stu1.pID
	//cout << Stu1.pID << endl; 
	//cout << *Stu1.pID << endl; 


	/*结构体计算大小*/
	cout << sizeof(MyStruct2) << endl;
	// 1、结构体空间不够的时候按照多少申请新的空间（所有基础属性中占用最大的）
	// 2、当空间够用的时候先不申请，不够存储新属性的时候再申请
	// 3、同一种类型（包含数组）可以进行空间挤压
	// 4、如果结构体中有string类型，不是按照40去申请  按照8申请 


#pragma endregion




}

void Fun(int* a, int* b) {
	int* Temp = a;
	a = b;
	b = Temp;

	//cout << "pA\n" << pA << endl;
	cout << *a << "  " << *b << endl;
};
