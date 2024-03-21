#pragma once
#include <iostream>
#include "HuMan.h"

class APet
{
public:
	AHuMan Owner;
	std::string	NickName;
	void DisplayOwner();
};

