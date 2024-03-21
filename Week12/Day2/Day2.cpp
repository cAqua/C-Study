#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Nums;


	for (int i = 0; i < 10; ++i) {
		Nums.push_back(i);
	}

	//for (int i = 0; i < Nums.size(); ++i) {
	//	cout << Nums.at(i) << endl;
	//}

	//cout << Nums.front() << endl;
	//cout << Nums.back() << endl;

	//cout << Nums.empty() << endl;

	//Nums.pop_back();

	// 迭代器
	for (auto IT = Nums.begin(); IT != Nums.end(); IT++)
	{
		cout << *IT << endl; //迭代器当前的值 解应用
		//cout << IT << endl;
		//cout << &IT << endl; //迭代器取地址
		cout << &(*IT) << endl; 

	}

	//Nums.insert(Nums.begin(),50);

	//Nums.erase(Nums.begin());



	vector<int>::iterator Nums1 = Nums.insert(Nums.end(), 500, 2);

	cout <<&Nums << endl;
	cout << *Nums1 << endl;


	//for (auto IT = *Nums1.begin(); IT != Nums1.end(); IT++)
	//{
	//	cout << *IT << endl; //迭代器当前的值 解应用
	//	//cout << IT << endl;
	//	//cout << &IT << endl; //迭代器取地址
	//	//cout << &(*IT) << endl;

	//}

	cout << "123";

	system("Pause");

}

