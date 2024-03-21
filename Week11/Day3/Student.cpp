#include "Student.h"

using namespace std;

AStudent::AStudent()
	:APerson(), Address()
{
	Address = "";
}

AStudent::AStudent(int ID, string Name, int Num, string Address)
	:APerson(ID, Name, Num)
{
	this->Address = Address;
}


void AStudent::Display()
{
	//APerson::Display(); // 调用父类的逻辑
	if (ID > 0)
	{
		cout << "子类 " << ID << ": " << Name << " " << *Ptr << endl;
	}
}

void AStudent::Show()
{
	cout << "子类的Show()" << Name << endl;
}
