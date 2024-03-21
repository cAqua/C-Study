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
	// ��Ѫ��Ҫ���Ƿ�����
	if (ReducedHP <= Def) return;
	HP -= (ReducedHP - Def);
	// �����߼�����
	if (HP <= 0) Die();
}

void Pawn::Attack(Pawn* InPawn)
{
	// ��ӡ˭������˭
	if (InPawn == nullptr || InPawn->GetHP() <= 0) return; // InPawnΪ��ָ���ʱ�򷵻� // !InPawn
	cout << Name << "������" << InPawn->Name << endl;

	// InPawn->ReduceHP(Atk);
	
}

void Pawn::Die()
{
	cout << Name << "����" << endl;
}
