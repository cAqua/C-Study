#include "Student.h"

int Student::Count = 0;

Student::Student()
	:ID(0), Name("")
{
	Count++;
}

Student::Student(int ID, string Name)
	:ID(ID),Name(Name)
{
	Count++;
}

void Student::Test() const
{
	//ID = 123;
	//cout << GetID();
	//SetID(123);
	Student S1;
	S1.ID = 123;

}

Student::~Student()
{
	Count--;
}


//--单列模式
GameInstance::GameInstance()
	:ID(10010)
{
}
GameInstance* GameInstance::Instance = nullptr;
Printer* Printer::PrinterInstance = nullptr;