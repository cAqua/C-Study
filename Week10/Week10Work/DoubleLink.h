#pragma once
#include <iostream>

struct FUserInfo
{
	FUserInfo* pHead; //ͷ
	//string Name; //����
	int ID;
	FUserInfo* pTail; //β
};

void AddUserInfo();