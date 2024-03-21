#include <iostream>
#include "Student.h"

using namespace std;

class AHuman {

public:
	virtual void Walk();
};

class AChild : public AHuman {
public:
	virtual void Walk() override;
};

//class Adult : public AHuman {
//public:
//	virtual void Walk() override;
//};
//class OldMan : public AHuman {
//public:
//	virtual void Walk() override;
//
//};
//void AHuman::Walk()
//{
//	cout << "Human Walk" << endl;
//}
//void AChild::Walk()
//{
//	cout << "Child Walk" << endl;
//}
//void Adult::Walk()
//{
//	cout << "Adult Walk" << endl;
//}
//void OldMan::Walk()
//{
//	cout << "Old Man Walk" << endl;
//}

//--共合体
struct MyStruct { //结构体按照变量最大字节申请内存空间
	bool bMuUnion;
	int Num1;
	bool bResult;
	long long LNum;
};
union MyUnion // 共用体根据最大的决定内存空间
{
	int Num;
	long long LNum;
	bool bMuUnion;
};
struct MyStudent1
{
	MyUnion Mu;
	MyStruct St;
};

int main()
{


#pragma region 多态

	//--virtual应用
	AHuman H1 = AHuman();
	H1.Walk(); //父类

	//AHuman H2 = AChild();
	//H2.Walk(); //父类

	//AChild Child;
	//AHuman& H3 = Child;
	//H3.Walk();

	//AHuman* H4 = new OldMan();
	//H4->Walk();
	//delete H4;
	//H4 = nullptr;

	//--virtual 多态的本质
	//AHuman H1 = AHuman();

	//AHuman *C1 = new AChild();

	//C1->Walk();
	//system("pause");

#pragma endregion
	
#pragma region 共用体 面试题

	//cout << sizeof(MyStudent1); //计算公用体&结构体字节大小

#pragma endregion


#pragma region 动态数组

#pragma endregion

#pragma region 命名空间

	//using namespace MyNamespae;

	//MyNamespae::aa;

	//using MyNamespae::aa;

	//aa

#pragma endregion

#pragma region 抽象类

#pragma endregion

#pragma region UML图

#pragma endregion

	system("pause");
}


