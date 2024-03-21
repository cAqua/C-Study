#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

class Person {
public:
	int ID;
	string Name;
	Person()
		:Name(""), ID(0)
	{
	};
	Person(string Name, int ID)
		:Name(Name), ID(ID)
	{}
};

int main()
{

#pragma region Set
	//set<int> Nums;
	//Nums.insert(10);
	//Nums.insert(20);
	//Nums.insert(20);


	////cout << Nums.size() << endl;

	//for (auto IT = Nums.begin(); IT != Nums.end(); IT++)
	//{
	//	cout << *IT << endl;
	//}

	////cout << Nums.count(10) << endl << endl; //查找

	//auto IT = Nums.find(20);
	//if (IT != Nums.end()) {
	//	cout << *IT << endl;
	//}
#pragma endregion


#pragma region Queue

	//queue<int> Q1;
	//Q1.push(1);
	//Q1.push(2);
	//Q1.push(3);
	//Q1.push(4);

	//cout << Q1.size() << endl;

	////Q1.pop();

	////Q1.back();


	//cout << Q1.front() << " " << Q1.back() << endl;

#pragma endregion

#pragma region Deque

	//deque<int> Dq1;

	//Dq1.push_back(1);
	//Dq1.push_back(2);
	//Dq1.push_back(3);
	//Dq1.push_back(4);
	//Dq1.push_front(5);
	//Dq1.push_back(6);

	//for (int IT : Dq1) {
	//	cout << IT << endl;
	//}

	// 有十个评委打分（ 70 - 100 ）求选手最终得分（去掉最低分，去掉最高分，取平均值）
	//deque<int> Dq1;

	//Dq1.push_back(70);
	//Dq1.push_front(92);
	//Dq1.push_back(90);
	//Dq1.push_back(85);
	//Dq1.push_front(83);
	//Dq1.push_front(78);
	//Dq1.push_back(100);
	//Dq1.push_back(80);
	//Dq1.push_front(71);
	//Dq1.push_front(97);


	//sort(Dq1.begin(), Dq1.end());
	//Dq1.pop_front();
	//Dq1.pop_back();

	//int Length = 0;
	//int Count = 0;
	//for (int IT : Dq1)
	//{
	//	Length++;
	//	Count += IT;
	//}

	//cout << (Count / Length) << endl;


#pragma endregion

#pragma region stack

	//stack<int> Nums;
	//Nums.push(100);
	//Nums.push(50);
	//Nums.push(200);

	////cout << Nums.size() << endl;
	////cout << Nums.top() << endl;
	//Nums.pop();

	//cout << Nums.top() << endl;


#pragma endregion

#pragma region 算法和Lambda表达式

	//vector<int> Nums;

	//srand((unsigned int)time(0));
	//for (int i = 0; i < 10; ++i) {
	//	//cout << rand() % 31 << endl;
	//	Nums.push_back(rand() % 31 + 70);
	//}

	//sort(
	//	Nums.begin()
	//	, Nums.end()
	//	, [](const int& Num1, const int& Num2)->bool {return Num1 > Num2; }
	//);

	//for (int IT : Nums) {
	//	cout << IT << endl;
	//}

	//--for_each
	//vector<int> Nums1;
	//for (auto IT = 0; IT < 10; IT++)
	//{
	//	Nums1.push_back(IT);
	//}

	//for_each(Nums1.begin(), Nums1.end(), [](int& Nums) {Nums *= 5; });

	//for (int IT : Nums1)
	//{
	//	cout << IT << endl;
	//}

	//vector<string> Name1;
	//Name1.push_back("张三");
	//Name1.push_back("李四");

	//vector<string> Name2;
	//Name1.push_back("王五");
	//Name1.push_back("老六");

	//vector<vector<string>> Names;
	//Names.push_back(Name1);
	//Names.push_back(Name2);

	//for_each(Names.begin(), Names.end(), [](vector<string>& Name) {

	//	for_each(Name.begin(), Name.end(), [](string& Temp) {
	//		cout << Temp << " ";
	//		cout << endl;
	//		});

	//	});

	//定义Person类 , 使用sort按照姓名进行排序, 排序后使用for_each输出
	vector<Person> P;
	P.push_back(Person("张三", 3));
	P.push_back(Person("李四", 1));
	P.push_back(Person("王五", 4));
	P.push_back(Person("老六", 0));
	P.push_back(Person("小七", 10));
	P.push_back(Person("老八", 8));


	//sort(P.begin(), P.end(), [](Person& P1, Person& P2)->bool {
	//	return P1.ID < P2.ID;
	//	});

	//for_each(P.begin(), P.end(), [](Person& P) {
	//	cout << P.ID << " : " << P.Name << endl;
	//	});

	int ID = 10;
	int Temp = 0;

	auto Result = count_if(P.begin(), P.end(), [=, &Temp](Person& P)->bool {
		Temp++;
		return P.ID > ID;
		});

	//cout << Result << endl;
	//cout << Temp << endl;
	bool Result1 = any_of(P.begin(), P.end(), [](Person& P)->bool {
		return P.ID >= 10;
		});
	cout << Result1 << endl;

	bool Result2 = all_of(P.begin(), P.end(), [](Person& P)->bool {
		return P.ID > 0;
		});

	cout << Result2 << endl;


#pragma endregion





}
