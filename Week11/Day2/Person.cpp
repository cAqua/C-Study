#include "Person.h"


// Ĭ�ϵ����޲ι��캯��
Person::Person() 
	: CNum(0)
{
	//std::cout << CNum << endl;
	cout << "�޲ι��캯��" << endl;
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
	cout << "�вι��캯��" << endl;
}