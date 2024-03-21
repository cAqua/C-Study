#include "HuMan.h"
#include "Pet.h"

using namespace std;

void AHuMan::DisplayPet()
{
	if (MyPet) {
		cout << "Pet Name: " << MyPet->NickName;
	}
}
