#include <iostream>
#include "Student.h"
#include "Complex.h"

void Test(const Student* S1) {
	//cout << S1->Set(123); 只能调用非常量函数
	//cout << S1->GetID();
}

Complex operator+(const Complex& A, const Complex& B) { //全局运算符重载
	return Complex(A.Real + B.Real, A.Imagine + B.Imagine,*A.Ptr + *A.Ptr);
}

Complex operator-(const Complex& A, const Complex& B) {
	return Complex(A.Real - B.Real, A.Imagine - A.Imagine, *A.Ptr - *A.Ptr);
}
bool operator>(const Complex& A, const Complex& B) {
	return A.Real > B.Real && A.Imagine > B.Imagine;
}

ostream& operator<<(ostream& Out, const Complex& C)
{
	Out << C.Real << "+" << C.Imagine << "i" << endl;
	return Out;
	// TODO: 在此处插入 return 语句
}

istream& operator>>(istream& stream, Complex& C)
{
	// TODO: 在此处插入 return 语句
	cout << C;
	stream >> C.Real >> C.Imagine;
	return stream;
}

int main()
{

#pragma region 常函数

	//Student S1 = Student(1, "张三");
	//S1.Test();

	//Test(&S1);

	//常量当函数

#pragma endregion


#pragma region  静态成员函数和静态成员

	//Student S1;
	//cout << S1.Count << endl;

	//Student::Count = 123;

	//cout << S1.Count << endl;

	//Student S2;

	//cout << S1.Count << endl;
	//cout << S2.Count << endl;


	//cout << &S1.Count << endl; //三者的静态成员都是一个内存地址
	//cout << &S2.Count << endl;
	//cout << &Student::Count << endl;

	//cout << Student::GetCount() << endl;

	////{
	////	Student S1;
	////	Student S2;
	////	cout << Student::GetCount() << endl;

	////}
	//{
	//	Student *S1 = new Student(); //因为是new 没有del没有触发析构函数
	//	Student S2;
	//	cout << Student::GetCount() << endl;

	//}
	//cout << Student::GetCount() << endl;


#pragma endregion


#pragma region 单列模式

	//cout << GameInstance::GetInstance()->GetID() << endl;
	//GameInstance::GetInstance()->SetID(10020);
	//cout << GameInstance::GetInstance()->GetID() << endl;

	//--打印机
	//Printer* P1 = Printer::GetInstance();
	//P1->PrinterData("简历一");
	//P1->PrinterData("简历二");
	//P1->PrinterData("简历三");
	//P1->ShowPrinterData();




#pragma endregion

#pragma region 运算符重载
	int Num = 10;
	Complex C1(2, 5, Num);
	Complex C2(2, 5, Num);
	Complex C3 = C1 + C2;

	Complex C4 = C2 - C1;

	C3.Display();
	C4.Display();

	cout << (C1 > C2) << endl; //>运算符重载

	cout << (C1 == C2) << endl; // == 运算符重载
	
	(++C1).Display();// 前置++

	C1++;
	C1.Display();

	cout << C1;

	cin >> C1;
	cout << C1;
	Complex C3 = Complex (2, 5, Num);
	C2 = C1;


	system("Pause");

#pragma endregion


}

