#include "Person.h"

APerson::APerson()
	:ID(0),Name("")
{
	cout << "�޲ι��캯��\n" << endl;
	Ptr = new int(0);
}

APerson::APerson(int ID, string Name,int Num)
	:ID(ID), Name(Name)
{
	cout << "�вι��캯��\n";
	Ptr = new int(Num);

	/*�ڶ���д��
	Ptr = new int();
	*Ptr = Num;*/

	//cout << "ID" << this->ID << endl;
	//cout << "Name" << this->Name << endl;
}
APerson::APerson(const APerson& Another)
{
	cout << "���ÿ�������\n";
	this->ID = Another.ID;
	this->Name = Another.Name;
	//cout << Ptr;
	//cout << Another.Ptr ;

	//��Ϊ���ÿ�������� P1��ֵ������P2 , ����������������ʱ��P2��ִ�������� , 
	// ��P1��ִ��������ʱ��Ptr��ջ�Ѿ�����������ʱ���ȡ�����ᱨ��
	//this->Ptr = Another.Ptr;  ���ַ�ʽ���� , �ڿ�����ʱ����ֱ�Ӱ�ָ���ַ������P1

	this->Ptr = new int(*Another.Ptr);

}

//APerson::~APerson()
//{
//	//cout << this << endl;
//	cout << "������������\n" << endl;
//	if (Ptr) {
//		delete Ptr;
//		Ptr = nullptr;
//	}
//}


 void APerson::Display()
{
	if (ID > 0) {
		cout << "���� "<< ID << ":" << Name  << "Num" << Num << "Ptr " << Ptr << endl;
	}
}
