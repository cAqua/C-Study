#pragma once
#include <iostream>
using namespace std;

//--静态成员函数和静态成员
class Student
{
protected:
	int ID;
	string Name;


public:
	Student();
	Student(int ID, string Name);

	inline int GetID() const { return ID; }
	inline void SetID(int ID) { this->ID = ID; }

	inline string GetName() const { return Name; }
	inline void SetName(string Name) { this->Name = Name; }

	void Test() const;

	static int Count;
	inline static int GetCount() {
		return Count;
	}

	virtual ~Student();
};

//--单列模式
class GameInstance {
private:
	GameInstance();
	static GameInstance* Instance;

	int ID;

public:
	inline int GetID() { return ID; }
	inline void SetID(int ID) { this->ID = ID; }
	static GameInstance* GetInstance() {

		if (!Instance) {
			Instance = new GameInstance();
		}
		return Instance;
	}

};
//打印机联系
class Printer {
private:
	Printer() {};
	static Printer* PrinterInstance;
	string Arr[10];
	int Length = 0;

public:

	inline void PrinterData(string Info) {

		//if (Length == 10) { //打到最长长度
		//	for (int i = 10; i <= 0 ; i--)
		//	{
		//		Arr[i] = [i]
		//	}
		//}

		Arr[Length] = Info;
		Length++;
		//cout << "打印成功" << endl;
	}
	inline void ShowPrinterData() {
		for (int i = 0; i < Length; i++)
		{
			cout << Arr[i] << endl;
		}
	}
	static Printer* GetInstance() {

		if (!PrinterInstance) {
			PrinterInstance = new Printer();
		}
		return PrinterInstance;

	}

};
