
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "DobuleLinkSDK.h"

using namespace std;
using std::setw;


#pragma region 数据列表结构体

/* 结构体学生信息 */
struct FStudentInfo
{
	//序号
	int ID;
	//姓名
	string Name;
	//学号
	int StudentID;
	//性别
	string Sex;
	//年龄
	int Age;
};
int ListIndex = 3;

#pragma endregion

#pragma region 权限模块

//权限模块
struct FPermission {
	bool bIsAdd;//增加
	bool bIsDel; //删除
	bool bIsAllDel; //全部删除
	bool bIsChange; //更改
	bool bIsShow; //显示
	bool bIsSeach;//搜索
};
string FunList[8] = {};
int FunListLength;

#pragma endregion

#pragma region 用户信息

/* 设定账号信息 */
struct FUserAccountInfo
{
	//账号
	string Account;
	//密码
	string Password;
	//用户类型
	string UserType;
	//权限
	FPermission UserPermission;
};
//账号和密码
//管理员所有权限 教师增删改查没有全部删除 学生查
FUserAccountInfo UserAccoutInfoArr[4] = {
	{"admin","88888888","管理员",{true,true,true,true,true,true}}, //管理员
	{"teacher","123","教师",{true,true,false,true,true,true} }, // 教师
	{"123","123","学生",{false,false,false,false,true,true} }, // 学生
	{"test","123","test",{true,true,true,true,true,true} }, // test
};
// 链表头
FData<FStudentInfo>* Head = nullptr;
//登录的用户信息
FUserAccountInfo UserInfo = FUserAccountInfo{};
//登录状态
bool bIsLogin = false;


#pragma endregion

#pragma region 函数声明
void Login();//登录;
void AddStudentInfo();//录入学生信息
void ShowStudentInfo();//显示学生信息
void ChangeStudentInfo();//修改学生信息
void SearchStudentInfo();//查找学生信息
void DelStudentInfo(bool bIsDellAii = false);//删除学生信息
void Logout();//退出系统
void ToHome();//展示首页
void GetUserFun(FPermission Per, string UserType); //获取用户功能
void Input();
#pragma endregion



int main()
{

	//判断用户登录状态
	if (!bIsLogin) {
		Login();
	};

	GetUserFun(UserInfo.UserPermission, UserInfo.UserType);//渲染功能信息

	system("pause");

}


//登录
void Login() {
	string Account; //账号
	string Password; //密码
	do {
		cout << "欢迎来到学生管理系统" << endl;
		cout << "请输入账号密码登录" << endl;
		cout << "请输入账号:  ";
		cin >> Account;
		cout << "请输入密码:  ";
		cin >> Password;
		//判断账号密码是否存在
		for (int i = 0; i < size(UserAccoutInfoArr); i++)
		{
			if (UserAccoutInfoArr[i].Account == Account
				&&
				UserAccoutInfoArr[i].Password == Password) {
				cout << "账号密码正确";
				UserInfo = UserAccoutInfoArr[i];//登录用户信息
				system("cls");
				bIsLogin = true;

				AddData(Head, FStudentInfo{ 1, "张三三", 1001, "男", 18 });
				AddData(Head, FStudentInfo{ 2,"李四",1002,"女",20 });
				AddData(Head, FStudentInfo{ 3,"王五",1003,"男",18 });

				return;

			}
		}
		cout << endl << "账号密码错误请重新输入\n\n";

	} while (!bIsLogin);
	return;

}

//录入学生信息
void AddStudentInfo() {
	FStudentInfo Info = {};
	cout << "当前录入的学生序号: " << ListIndex + 1 << endl;
	cout << "输入学生姓名: ";
	cin >> Info.Name;
	cout << "学号: ";
	cin >> Info.StudentID;
	cout << "性别: ";
	cin >> Info.Sex;
	cout << "年龄: ";
	cin >> Info.Age;
	cout << "\n学生信息 姓名:" << Info.Name
		<< "  学号:" << Info.StudentID
		<< "  性别:" << Info.Sex
		<< "  年龄:" << Info.Age;
	AddData(Head, Info);
	cout << endl << "添加成功";
	cout << "输入1返回首页";
	ToHome();

};
#pragma region 系统函数

//显示学生信息
void ShowStudentInfo() {
	cout << "显示学生信息\n\n";
	cout << "序号" << setw(10) << "姓名" << setw(10) << "学号" << setw(10) << "性别" << setw(10) << "年龄\n" << endl;

	vector<FStudentInfo*> Arr = ShowAllData<FStudentInfo>(Head);

	for (size_t i = 0; i < Arr.size(); ++i)
	{
		FStudentInfo* Item = Arr[i];
		cout << setw(2)
			<< i + 1
			<< setw(12) << Item->Name
			<< setw(10) << Item->StudentID
			<< setw(10) << Item->Sex
			<< setw(8) << Item->Age << endl << endl;

	};

	cout << "输入1返回首页\n";
	ToHome();
};
//修改学生信息
void ChangeStudentInfo() {
	cout << "修改学生信息\n\n输入需要修改的学生学号: ";
	int StudentID;
	cin >> StudentID;

	FStudentInfo* ResultInfo = SearchData<FStudentInfo>(Head, StudentID);
	if (ResultInfo != nullptr)
	{
		cout << "当前要修改的学生学号: " << StudentID << endl;
		cout << "输入学生姓名: ";
		cin >> ResultInfo->Name;
		cout << "学号: ";
		cin >> ResultInfo->StudentID;
		cout << "性别: ";
		cin >> ResultInfo->Sex;
		cout << "年龄: ";
		cin >> ResultInfo->Age;
		cout << "\n学生信息 姓名:" << ResultInfo->Name
			<< "  学号:" << ResultInfo->StudentID
			<< "  性别:" << ResultInfo->Sex
			<< "  年龄:" << ResultInfo->Age;

		cout << endl << "修改成功 ";
		cout << "输入1返回首页";
		ToHome();
	}
	else {
		cout << "没有此学生" << endl;
		cout << "输入1返回首页\n";
		ToHome();
	}

};
//查找学生信息
void SearchStudentInfo() {
	cout << "输入学生学号查找:  ";
	int StudentID;
	cin >> StudentID;

	cout << "搜索结果" << endl;
	FStudentInfo* Result = SearchData<FStudentInfo>(Head, StudentID);
	if (Result != nullptr)
	{
		cout << "\n学生信息 姓名:" << Result->Name
			<< "  学号:" << Result->StudentID
			<< "  性别:" << Result->Sex
			<< "  年龄:" << Result->Age;
	}
	else {
		cout << "没有此学生" << endl;
		cout << "输入1返回首页\n";
		ToHome();
	}

	cout << "\n\n输入1返回首页";
	ToHome();

};
//删除学生信息
void DelStudentInfo(bool bIsDellAii) {
	//cout << " bIsDellAii" << bIsDellAii << endl;
	cout << "\n删除学生信息\n\n";

	//删除所有用户
	if (bIsDellAii) {
		string Password;
		cout << "需要密码才能删除";
		cout << "请输入密码:  ";
		cin >> Password;

		if (Password == "88888888") {
			Head = nullptr;
			cout << "删除成功\n";
			cout << "输入1返回首页";
			ToHome();
			return;
		}

	}
	cout << "输入要删除的学生学号\n";
	int StudentID;
	cin >> StudentID;
	bool bIsDel = DeleteData<FStudentInfo>(Head, StudentID);

	if (bIsDel) {
		cout << "删除成功\n\n";
	}
	else {
		cout << "没有此学生";
	}

	cout << "输入1返回首页";
	ToHome();
};
//退出系统
void Logout() {
	return;
}
//根据不同用户信息展示 管理员 教师 学生功能
void GetUserFun(FPermission Per, string UserType) {
	int Index = 1;

	cout << "欢迎来到学生管理系统" << endl;

	cout << "您是" << UserType << "\n\n";

	if (Per.bIsAdd) {
		cout << "【" << Index << "】录入学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Add";
	}
	if (Per.bIsChange) {
		cout << "【" << Index << "】更改学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Change";
	}
	if (Per.bIsShow) {
		cout << "【" << Index << "】显示学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Show";
	}
	if (Per.bIsSeach) {
		cout << "【" << Index << "】查找学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Seach";
	}
	if (Per.bIsDel) {
		cout << "【" << Index << "】删除学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Del";
	}
	if (Per.bIsAllDel) {
		cout << "【" << Index << "】删除所有学生信息,需要登录管理员账号密码\n" << endl;
		Index++;
		FunList[Index - 1] = "AllDel";

	}
	cout << "【" << Index << "】退出系统\n" << endl;
	Index++;
	FunList[Index - 1] = "Quit";
	FunListLength = Index;
	cout << "\n请选择功能：";
	Input();//输入信息

}
//根据输入动态决定调用功能
void Input() {
	int InputIndex;
	cin >> InputIndex;
	//cout << FunList[InputIndex];

	if (FunList[InputIndex] == "Add") {
		//录入学生信息
		AddStudentInfo();
	}
	else if (FunList[InputIndex] == "Change") {
		//修改学生信息
		ChangeStudentInfo();
	}
	else if (FunList[InputIndex] == "Show") {
		//显示学生信息
		ShowStudentInfo();
	}
	else if (FunList[InputIndex] == "Seach") {
		//查找学生信息
		SearchStudentInfo();
	}
	else if (FunList[InputIndex] == "Del") {
		//删除学生信息
		DelStudentInfo();
	}
	else if (FunList[InputIndex] == "AllDel") {
		//删除所有学生信息
		DelStudentInfo(true);
	}
	else if (FunList[InputIndex] == "Quit") {
		//删除所有学生信息
		Logout();
	}
}
#pragma endregion

#pragma region 功能函数

void ToHome() {
	int Enter;
	cin >> Enter;
	system("cls");
	main();
}

#pragma endregion

