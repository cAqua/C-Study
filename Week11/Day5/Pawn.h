#pragma once

#include <iostream>

class Pawn
{
	// êÇ³Æ£¬¹¥»÷Á¦£¬·ÀÓùÁ¦£¬HP
protected:
	std::string Name; // êÇ³Æ
	int Atk;          // ¹¥»÷Á¦
	int Def;          // ·ÀÓùÁ¦
	int HP;           // HP;

public:
	Pawn();
	Pawn(std::string Name, int Attack, int Defense, int InHP);

	// ¼õÑª
	void ReduceHP(int ReducedHP);
	// ¹¥»÷
	virtual void Attack(Pawn* InPawn);

	virtual void Die();

	inline std::string GetName() { return Name; }
	inline void SetName(std::string Name) { this->Name = Name; }

	inline int GetAttack() { return Atk; }
	inline int GetDefense() { return Def; }
	inline int GetHP() { return HP; }
};

