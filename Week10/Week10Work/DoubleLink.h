#pragma once
#include <iostream>

struct FUserInfo
{
	FUserInfo* pHead; //Í·
	//string Name; //Ãû×Ö
	int ID;
	FUserInfo* pTail; //Î²
};

void AddUserInfo();