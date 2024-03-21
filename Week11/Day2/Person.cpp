#include "Person.h"


// 默认调用无参构造函数
Person::Person() 
	: CNum(0)
{
	//std::cout << CNum << endl;
	cout << "无参构造函数" << endl;
}
Person::Person(int ID, int InCNum) 
	//:CNum(InCNum),ID(ID)
{
	this->ID = 100;

	std::cout << ID << endl;
	std::cout << CNum << endl;
}
Person::Person(int InID,string InName,int InAge) 
	: CNum(0)
{
	ID = InID;
	Name = InName;
	Age = InAge;
	std::cout << CNum << endl;
	cout << "有参构造函数" << endl;
}