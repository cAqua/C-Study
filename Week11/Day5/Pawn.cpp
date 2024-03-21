#include "Pawn.h"

using namespace std;

Pawn::Pawn()
{
	Name = "";
	Atk = 0;
	Def = 0;
	HP = 0;
}

Pawn::Pawn(std::string Name, int Attack, int Defense, int InHP)
{
	this->Name = Name;
	Atk = Attack > 0 ? Attack : 0;
	Def = Defense > 0 ? Defense : 0;
	HP = InHP > 0 ? InHP : 0;
}

void Pawn::ReduceHP(int ReducedHP)
{
	// 减血需要考虑防御力
	if (ReducedHP <= Def) return;
	HP -= (ReducedHP - Def);
	// 死亡逻辑处理
	if (HP <= 0) Die();
}

void Pawn::Attack(Pawn* InPawn)
{
	// 打印谁攻击了谁
	if (InPawn == nullptr || InPawn->GetHP() <= 0) return; // InPawn为空指针的时候返回 // !InPawn
	cout << Name << "攻击了" << InPawn->Name << endl;

	// InPawn->ReduceHP(Atk);
	
}

void Pawn::Die()
{
	cout << Name << "阵亡" << endl;
}
