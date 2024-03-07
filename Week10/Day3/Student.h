#pragma once
#include <iostream>


struct FStudent {
	int ID = 0;
	std::string Name = "";
	float Height = 0.f;
	bool bIsMale = false;
	void Display();
};