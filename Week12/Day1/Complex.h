#pragma once
#include <iostream>

class Complex
{
	friend Complex operator+(const Complex& A, const Complex& B);

	friend Complex operator-(const Complex& A, const Complex& B);

	friend bool operator>(const Complex& A, const Complex& B);

	friend std::ostream& operator<<(std::ostream& Out, const Complex& C);

	friend std::istream& operator>>(std::istream& stream, Complex& C);

protected:
	int Real;
	int Imagine;
	int* Ptr = nullptr;
public:
	Complex();
	Complex(int Real, int Imagine,int Num);
	Complex operator+ (const Complex & Another); //成员函数比全局有员优先级高
	Complex& operator++(); //后置++
	Complex operator++(int);
	Complex operator=(const Complex& Another);


	bool operator==(const Complex& Another);

	void Display();
};

