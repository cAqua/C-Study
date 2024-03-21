#pragma once
#include <iostream>

using namespace std;

class APerson
{
protected:
	int ID;
	std::string Name;
	int Num;
	int *Ptr = nullptr;

public:
	APerson();
	APerson(int ID, string Name, int Num);
	APerson(const APerson& Another);
	//~APerson();

	inline int* GetPtr() { return Ptr; }

	inline int GetID() { return ID; }
	inline void SetID(int ID) { this->ID = ID; }

	inline string GetName() { return Name; }
	inline void SetName(string Name) { this->Name = Name; }

	virtual void Display();


};

