#include "WeaponBase.h"

WeaponBase::WeaponBase()
	: Name(""), Atk(0)
{
}

WeaponBase::WeaponBase(std::string Name, int InAtk)
{
	this->Name = Name;
	Atk = InAtk > 0 ? InAtk : 0;
}

int WeaponBase::Attack(Pawn* InPawn)
{
	return 0;
}
