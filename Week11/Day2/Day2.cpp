#include <iostream>
#include <string>
//#include "Enums.h"
#include "Person.h"
#include "Pet.h"
#include "HuMan.h"

//正常 std::cout 应用了std命名空间
// 然后代码就可以cout直接打印
using namespace std;
// 
//using namespace Person; //命名空间

void GetPerson(Person P) {
	P.Age = 15;
	cout << P.Age;
}

int main()
{
#pragma region 枚举
	//普通创建-------
	//EMuDay MyDay = EMD_Weekday;
	//EMuDay MyDay = EMuDay::EMD_Weekend;

	//cout << MyDay << endl;

	//switch (MyDay)
	//{
	//case EMD_Weekday:
	//	break;
	//case EMD_Weekend:
	//	break;
	//default:
	//	break;
	//}
	//类创建-------
	//int Num = 10;
	//Eseason MyDay2 = (Eseason)Num;
	//Eseason MyDay3 = Eseason::ES_Summer;
	//cout << (int)MyDay2 << endl;
	//cout << (int)MyDay3 << endl;


	//Eseason Season1 = Eseason::ES_Spring;

	//switch (Season1)
	//{
	//case Eseason::ES_Spring: {
	//	cout << "123";
	//}
	//	break;
	//case Eseason::ES_Summer:
	//{
	//	cout << "312";
	//}
	//	break;
	//case Eseason::ES_Autuem:
	//	break;
	//case Eseason::ES_Winter:
	//	break; -+
	//default:
	//	break;
	//}


#pragma endregion

#pragma region 命名空间

	//Person::Person aa = Person::Person();
	//cout << aa.GetAge();


#pragma endregion


#pragma region 面向对象
	//using namespace std;
	///
	// 声明 : namespace Person
	// 使用 : using namespace Person;
	// 就可以直接简略Persson:: 直接调用通过Aperson里面的
	// 

#pragma endregion


#pragma region 类的基本使用

	//Person P1;
	//APerson P2 = APerson();
	//APerson* P3 = &P1;
	//APerson* P4 = new APerson();
	//P1.SetAge(10);
	//GetPerson( P1); //调用友元
	//P1.SetAge(20);
	//cout << endl << P1.GetAge();

	//Test

	//友元
	//GetPerson( P1); //调用友元
	//AHuMan H;
	//H.Name = "王五";
	//APet P;
	//P.NickName = "小咪";
	//H.MyPet = &P;
	//P.Owner = H;
	//P.DisplayOwner();
	//H.DisplayPet();

#pragma endregion

#pragma region 封装的访问修饰符

#pragma endregion

#pragma region 构造函数

	//Person P = Person(); //调用了无参构成函数
	//Person P1 = Person(1, "123", 19); //调用有参构造函数
	//Person P2 = Person(2, 13);

#pragma endregion

#pragma region 成员变量指针

	class FTestClass
	{
	public:
		string Name;
		void Say(string Info) { cout << Name << ":" << Info << endl; }
	};
	class USPhereComponet {
		void (FTestClass::* CallBack)(string Info);
		FTestClass* Obj;
	public:
		void AddDynamic(FTestClass* Object, void (FTestClass::* func)(string Info)) {
			Obj = Object;
			CallBack = func;
		}
		void Exec() {
			(Obj->*CallBack)("天");
		}
	};

	FTestClass* tc = new FTestClass;
	tc->Name = "哈哈";

	USPhereComponet* SphereComp = new USPhereComponet;
	SphereComp->AddDynamic(tc, &FTestClass::Say);

	SphereComp->Exec();



#pragma endregion



}
