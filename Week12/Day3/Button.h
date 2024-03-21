#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//�����޲��޷���ֵ
typedef void (*Ptr)();

class AButton
{
protected:
	vector<Ptr> Onclicked;
public:
	AButton& BindEventToOnClicked(Ptr Event);
	void UnbindEvent(Ptr Event);
	void UnbindAll();
	void Click();

};

