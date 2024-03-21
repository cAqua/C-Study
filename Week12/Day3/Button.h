#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//定义无参无返回值
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

