#pragma once


int TestAdd(int Num1, int Num2)
{
	return Num1 + Num2;
}

// 声明和实现拆开
inline int TestSubtract(int Num1, int Num2);

// 声明和实现写在一起
inline int Multiply(int Num1, int Num2) { return Num1 * Num2; }