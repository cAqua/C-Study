#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
	:Real(1), Imagine(1), Ptr(nullptr)
{
}

Complex::Complex(int Real, int Imagine, int Num)
	:Real(Real), Imagine(Imagine)
{
	//Complex C3 = Complex (2, 5, Num); 才触发
	Ptr = new int(Num);
}

Complex Complex::operator+(const Complex& Another)
{
	
	return Complex(this->Real + Another.Real,this->Imagine + Another.Imagine,*Ptr = *Another.Ptr);
}

Complex& Complex::operator++()
{
	this->Real++;
	this->Imagine++;
	//cout << &*this<< endl;
	return *this;
	// TODO: 在此处插入 return 语句
}
Complex Complex::operator++(int) {
	Complex Temp = *this;
	this->Real++;
	this->Imagine++;
	return Temp;
}

Complex Complex::operator=(const Complex& Another) 
//只有对2个已经声明的2个对象赋值才会触发 C2 = C1
{
	this->Real = Another.Real;
	this->Imagine = Another.Imagine;

	if (Ptr) {
		*Ptr = *Another.Ptr;
	}
	else {
		Ptr = new int(*Another.Ptr);
	}

	return *this;
}


bool Complex::operator==(const Complex& Another)
{
	return this->Real == Another.Real && this->Imagine == Another.Imagine;
}


void Complex::Display()
{
	cout << Real << "+" << Imagine << "i" << endl;
}
