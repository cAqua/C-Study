#pragma once
#include "Person.h"
class AStudent : public APerson
{
	string Address;
public:
	AStudent();
	AStudent(int ID, string Name, int Num, string Address);
	void Show();
	void Display() override;
};

