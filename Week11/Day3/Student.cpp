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
	//APerson::Display(); // ���ø�����߼�
	if (ID > 0)
	{
		cout << "���� " << ID << ": " << Name << " " << *Ptr << endl;
	}
}

void AStudent::Show()
{
	cout << "�����Show()" << Name << endl;
}
