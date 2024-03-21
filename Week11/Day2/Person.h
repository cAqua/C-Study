#pragma once
#include <iostream>
//#include <string>
using namespace std;


class Person
{
	friend void GetPerson(Person P);
public:
	Person();// 默认调用无参构造函数
	//有参就为有参函数
	Person(int ID, int InCNum);
	Person(int InID, string InName, int InAge);

	const int CNum = 5;

	int ID;
	string Name;
	//inline void SetAge(int InID) { ID = InID < 0 || InID > 1000 ? 0 : InID; }
	inline void SetAge(int InAge) { Age = InAge < 0 || InAge > 150 ? 0 : InAge; }
	inline int GetAge() { return Age; }
protected:
private:
	int Age;

};

//namespace Person{
//	class APerson
//	{
//
//	public:
//		int ID;
//		string Name;
//		inline void SetAge(int InAge) { Age = InAge < 0 || InAge > 150 ? 0 : InAge; }
//		inline int GetAge() { return Age; }
//	protected:
//	private:
//		int Age;
//
//	};
//
//
//}
