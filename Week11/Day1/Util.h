#pragma once

#include <iostream>

//#define ____________ std::cout << "Hello" << std::endl;
//#define ___________ std::cout << "Hello World" << std::endl;
//#define __________ std::cout << "���" << std::endl;
//#define ________ std::cout << "����ʱ��" << std::endl;

#define _FILENAME_ "Info.txt" // ��ʾһ��������ֻ�������滻��������������ͣ�
// const string FileName = "Info.txt"  // cpp���滻������ķ��������Լ������ƥ�䣬Ĭ��ֵ�������Ƿ�ֵ��

// #define ADD(Num1, Num2) Num1+Num2 // ע����β�費��Ҫ�ֺ�

// ������������ �����ͼ�������()������
#define MULTIPLY(Num1, Num2) ((Num1) * (Num2))

#define MAX(Num1, Num2) (((Num1) > (Num2)) ? (Num1) : (Num2))

int Divide(int Num1, int Num2)
{
	std::cout << __FILE__ << std::endl;
	return Num1 / Num2;
}
