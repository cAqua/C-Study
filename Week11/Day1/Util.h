#pragma once

#include <iostream>

//#define ____________ std::cout << "Hello" << std::endl;
//#define ___________ std::cout << "Hello World" << std::endl;
//#define __________ std::cout << "你好" << std::endl;
//#define ________ std::cout << "火星时代" << std::endl;

#define _FILENAME_ "Info.txt" // 表示一个常量（只是类型替换，不检查具体的类型）
// const string FileName = "Info.txt"  // cpp中替换常量宏的方法（可以检查类型匹配，默认值，变量是否赋值）

// #define ADD(Num1, Num2) Num1+Num2 // 注意宏结尾需不需要分号

// 如果宏带参数的 参数和计算结果用()括起来
#define MULTIPLY(Num1, Num2) ((Num1) * (Num2))

#define MAX(Num1, Num2) (((Num1) > (Num2)) ? (Num1) : (Num2))

int Divide(int Num1, int Num2)
{
	std::cout << __FILE__ << std::endl;
	return Num1 / Num2;
}
