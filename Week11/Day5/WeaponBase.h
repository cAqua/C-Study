#pragma once

#include <iostream>

class Pawn; // ��һ��д��

class WeaponBase
{
	// ���ƣ������˺�;  int Attack(Pawn* )   virtual int SkillAttack1(Pawn* ) = 0  virtual int SkillAttack2(Pawn* ) = 0
protected:
	std::string Name;
	int Atk;

public:
	WeaponBase();
	WeaponBase(std::string Name, int InAtk);

	inline std::string GetName() { return Name; }
	inline void SetName(std::string Name) { this->Name = Name; }

	inline int GetAttack() { return Atk; }

	virtual int Attack(class Pawn* InPawn); // �ڶ���д��

	virtual int Skill1Attack(Pawn* InPawn) = 0;

	virtual int Skill2Attack(Pawn* InPawn) = 0;
};

