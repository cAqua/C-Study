#pragma once

#include <iostream>

class Pawn
{
	// �ǳƣ�����������������HP
protected:
	std::string Name; // �ǳ�
	int Atk;          // ������
	int Def;          // ������
	int HP;           // HP;

public:
	Pawn();
	Pawn(std::string Name, int Attack, int Defense, int InHP);

	// ��Ѫ
	void ReduceHP(int ReducedHP);
	// ����
	virtual void Attack(Pawn* InPawn);

	virtual void Die();

	inline std::string GetName() { return Name; }
	inline void SetName(std::string Name) { this->Name = Name; }

	inline int GetAttack() { return Atk; }
	inline int GetDefense() { return Def; }
	inline int GetHP() { return HP; }
};

