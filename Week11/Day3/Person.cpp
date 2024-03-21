#include "Person.h"

APerson::APerson()
	:ID(0),Name("")
{
	cout << "无参构造函数\n" << endl;
	Ptr = new int(0);
}

APerson::APerson(int ID, string Name,int Num)
	:ID(ID), Name(Name)
{
	cout << "有参构造函数\n";
	Ptr = new int(Num);

	/*第二种写法
	Ptr = new int();
	*Ptr = Num;*/

	//cout << "ID" << this->ID << endl;
	//cout << "Name" << this->Name << endl;
}
APerson::APerson(const APerson& Another)
{
	cout << "调用拷贝构造\n";
	this->ID = Another.ID;
	this->Name = Another.Name;
	//cout << Ptr;
	//cout << Another.Ptr ;

	//因为调用拷贝构造吧 P1的值给到了P2 , 但是在析构函数的时候P2先执行了析构 , 
	// 在P1在执行析构的时候Ptr的栈已经被销毁了这时候获取不到会报错
	//this->Ptr = Another.Ptr;  这种方式错误 , 在拷贝的时候是直接吧指针地址给到了P1

	this->Ptr = new int(*Another.Ptr);

}

//APerson::~APerson()
//{
//	//cout << this << endl;
//	cout << "析构函数调用\n" << endl;
//	if (Ptr) {
//		delete Ptr;
//		Ptr = nullptr;
//	}
//}


 void APerson::Display()
{
	if (ID > 0) {
		cout << "父类 "<< ID << ":" << Name  << "Num" << Num << "Ptr " << Ptr << endl;
	}
}
