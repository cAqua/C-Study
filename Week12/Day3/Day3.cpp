#include <iostream>
#include "Button.h"
#include <list>
#include <algorithm>
#include <map>
using namespace std;

void SayHi() {
	cout << "SayHi" << endl;
}
void SayBey() {
	cout << "SayBey" << endl;
}
void SayHeeloWorld() {
	cout << "SayHeeloWorld" << endl;
}

struct AStudent
{
	int ID = 0;
	string Name = "";
	AStudent();
	AStudent(int ID, string Name);
	bool operator>(const AStudent& Another)const {
		return this->ID > Another.ID;
	}
	bool operator<(const AStudent& Another)const {
		return this->ID < Another.ID;
	}
};
struct StudentCompare //Asutdnet的仿函数
{
	bool operator()(const AStudent& S1, const AStudent& S2)const {
		return S1.ID > S2.ID;
		//return true;

	}
};

//防函数 结构体形式
struct IntCompare
{
	bool operator()(const int& Key1, const int& Key2)const {
		return Key1 > Key2;
	}
};

//类形式
class IntCompare1
{
public:
	bool operator()(const int& Key1, const int& Key2)const {
		return Key1 > Key2;
	}
};

int main()
{

#pragma region 按钮代理
	AButton B1;
	//B1.BindEventToOnClicked(SayHi)
	//	.BindEventToOnClicked(SayBey)
	//	.BindEventToOnClicked(SayHeeloWorld); //链式调用
	////B1.BindEventToOnClicked(SayBey);
	////B1.BindEventToOnClicked(SayHeeloWorld);

	////B1.UnbindEvent(SayBey);
	//B1.Click();

#pragma endregion

#pragma region 链表

	//srand(time(0));
	//vector<int> Nums;
	//for (int i = 0; i < 10; i++)
	//{
	//	Nums.push_back(rand());
	//}

	//sort(Nums.begin(), Nums.end());

	//list<int> Nums1;

	//for (int i = 0; i < 10; i++)
	//{
	//	Nums1.push_back(rand());
	//}
	////Nums1.sort();
	////sort(Nums1.begin(), Nums.end()); //链表因为其特点只能用他自己的sort
	//cout << 123 << endl;


#pragma endregion


#pragma region Map

	//pair<int, string> P1(1, "11");
	//pair<int, string> P2(2, "22");

	//cout << P1.first << " : " << P1.second << endl;

	//vector<int> Nums;
	//Nums.push_back(33);
	//Nums.push_back(333);

	//pair<string, vector<int>> P3 = { "3",Nums };

	//map<string, vector<int>>Error1;

	//Error1.insert(P3);

	//cout << P3.first << " : " << endl;

	//for (auto IT = P3.second.begin(); IT != P3.second.end(); IT++)
	//{
	//	cout << *IT << endl << endl;
	//}

	//map<int, string>Error;


	//Error.insert(P1);
	//Error.insert(P2);
	////Error.insert(P3);
	//Error.insert(make_pair(4, "44"));
	//Error[5] = "55";
	//Error.insert(pair<int, string>(6, "66"));
	//Error.insert(map<int, string>::value_type(7, "77"));



	//for (auto IT = Error.begin(); IT != Error.end(); IT++)
	//{
	//	cout << (*IT).first << " : " << (*IT).second << endl;
	//}

	//cout << "---------\n";

	//for (auto IT = Error.rbegin(); IT != Error.rend(); IT++) //rbegin() rend()
	//{
	//	cout << (*IT).first << " : " << (*IT).second << endl;
	//}

	//for (auto IT = Error.cbegin(); IT != Error.cend(); IT++) //cbegin() 不允许修改
	//{
	//	(*IT).first = 123; // 错误
	//	cout << (*IT).first << " : " << (*IT).second << endl;
	//}

	//cout << "123";

#pragma endregion

#pragma region 字典高级


	//--防函数

	map<int, string, IntCompare1>Error; // 自定义仿函数
	map<int, string, greater<IntCompare1>>Error; // 自定义仿函数 倒序
	pair<int, string> P1(1, "11");

	//map<int, string>Error;

	Error[10010] = "22";
	Error[10012] = "11";
	Error.insert(P1);
	Error.insert(map<int, string>::value_type(7, "77"));
	Error[10015] = "55";
	Error.insert(pair<int, string>(6, "66"));
	Error.insert(make_pair(4, "44"));
	Error[102] = "33";

	for (auto IT = Error.begin(); IT != Error.end(); IT++)
	{
		cout << (*IT).first << " : " << (*IT).second << endl;
	}

	//IntCompare IC; //防函数
	//cout << IC(80, 70) << endl;

	// 自定义类型作为key
	// 单纯定义变量不会报错，一旦插入的时候就会报错
	// 仿函数定义的是排序规则，不能使用 == !=    必须是 > < >= <= 否则字典只能保存一个元素
	//// 系统自带的仿函数
	//less<int> Less;
	//cout << Less(50, 80) << endl

	//-- 结构体仿函数
	map < AStudent, int, greater<AStudent>> AstudentMap; //自定义了 仿函数
	//map < AStudent, int, greater<AStudent>> AstudentMap; //自定义了 仿函数

	pair< AStudent, int> S1(AStudent(11, "22"), 222);
	pair< AStudent, int> S2(AStudent(22, "33"), 333);

	AstudentMap.insert(S1);
	AstudentMap.insert(S2);

	AstudentMap.insert(pair< AStudent, int>(AStudent(44, "55"), 555));

	for (auto IT = AstudentMap.begin(); IT != AstudentMap.end(); IT++)
	{
		cout << (*IT).first.ID << " : " << (*IT).first.ID << "  value" << (*IT).second << endl;
	}


#pragma endregion


}

AStudent::AStudent()
	:ID(0), Name("")
{
}

AStudent::AStudent(int ID, string Name)
	:ID(ID), Name(Name)
{
}
