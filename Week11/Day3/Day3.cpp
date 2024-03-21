#include <iostream>
#include "Person.h"
#include "Student.h"

void TestPerson(APerson Person) {
	Person.SetID(100);
	Person.Display();
}

//APerson P;
//APerson& TestPerson1() {
//	return P;
//}
APerson TestPerson2(APerson Person) {
	APerson Person1;
	return Person; //形参接收和return的时候都会生成值和值的拷贝就会发生拷贝构造
}
APerson TestPerson3() {
	APerson Temp;
	return Temp;
}

int main()
{


#pragma region 拷贝构造

	//---拷贝构造调用
	//APerson P1;
	//P1.Display();
	//APerson P2 = APerson(10, "zhangsan");
	//P2.Display();
	//APerson P3 = P2;
	//P3.Display();


	//---拷贝构造调用时时机解析
	//APerson P1; //构造了类
	// 根据这个类申请了内存空间 , 等Aperson()调用后存储返回值
	//APerson P1 = APerson(10000, "王五",10);



#pragma endregion

#pragma region 析构函数

	//cout << "\n拷贝构造解析----" << endl;
	//APerson P2 = P1; // 调用时机 1、

	//TestPerson(P1); // 调用时机 2、
	//TestPerson1(); //在2019发生了拷贝构造在2022没有发生

	//TestPerson2(P1);// 调用时机 3 - 1

	//APerson Temp = TestPerson3(); //调用时机 3 - 2

#pragma endregion

#pragma region 带指针的拷贝构造和析构

	//---浅拷贝
	//int Num = 100;
	//APerson P1 = APerson(1000,"乔峰",Num);
	//APerson P2 = P1;
	//cout << P1.GetPtr() << " " << P2.GetPtr() << endl;
	//P1.Display();
	//P2.Display();

#pragma endregion

#pragma region 继承
	{

		//---函数重定义
		//APerson P1;
		//AStudent S1 = AStudent(); //子类 = 子类
		//S1.SetID(001);
		//S1.SetName("子类");
		//S1.Display(); //打印子类

		//函数重定义
		//APerson P1 = S1; //父类 = 子类
		//P1.Display(); //打印父类

		//APerson P2 = P1; //父类 = 父类(子类)
		//P2.Display(); //打印父类

		//APerson *P3 = &S1; // 父类指针 = 子类引用
		//P3->Display();//父类打印

		//---函数重写
		//APerson P1;
		//AStudent S1 = AStudent(); //子类 = 子类
		//S1.SetID(10012);
		//S1.SetName("子类");
		//S1.Display();


		//APerson* P2 = &S1; //父类指针 = 子类地址
		//P2->Display(); //子类打印 通过virtual重写了

		//AStudent S3 = S2;



	}

#pragma endregion

#pragma region 多态

	//AStudent P1;
	AStudent* Stu = new AStudent(10010, "张三", 100, "火星时代");
	Stu->Display();

#pragma endregion



}

