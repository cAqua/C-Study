#include "Button.h"
#include <string>

AButton& AButton::BindEventToOnClicked(Ptr Event)
{
	auto IT = find(Onclicked.begin(), Onclicked.end(), Event);
	if (IT == Onclicked.end()) Onclicked.push_back(Event);
	return *this;
}

void AButton::UnbindEvent(Ptr Event)
{
	auto IT = find(Onclicked.begin(), Onclicked.end(), Event);
	if (IT != Onclicked.end()) Onclicked.erase(IT);
}

void AButton::UnbindAll()
{
	Onclicked.clear();
}

void AButton::Click()
{
	for (auto IT = Onclicked.begin(); IT != Onclicked.end(); IT++)
	{
		(*IT)();
	}
}
