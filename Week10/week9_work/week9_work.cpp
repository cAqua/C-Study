
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
using std::setw;


#pragma region 数据列表结构体

/* 结构体学生信息 */
struct StudentInfo
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
//学生信息数组 一共10条学生数据
StudentInfo StudentInfoArr[10] = {
	{1,"张三三",1001,"男",18},
	{2,"李四",1002,"女",20},
	{3,"王五",1003,"男",18},
};
int StudentInfoArrLength = 3;

#pragma endregion

#pragma region 权限模块

//权限模块
struct Permission {
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
struct UserAccountInfo
{
	//账号
	string Account;
	//密码
	string Password;
	//用户类型
	string UserType;
	//权限
	Permission UserPermission;
};
//账号和密码
//管理员所有权限 教师增删改查没有全部删除 学生查
UserAccountInfo UserAccoutInfoArr[3] = {
	{"admin","88888888","管理员",{true,true,true,true,true,true}}, //管理员
	{"teacher","123","教师",{true,true,false,true,true,true} }, // 教师
	{"123","123","学生",{false,false,false,false,true,true} }, // 学生
};
//登录的用户信息
UserAccountInfo UserInfo = UserAccountInfo{};
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
void GetUserFun(Permission obj); //获取用户功能
void Input();
#pragma endregion



int main()
{
	//判断用户登录状态
	if (!bIsLogin) {
		Login();
	};

	GetUserFun(UserInfo.UserPermission);//渲染功能信息

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
				return;

			}
		}
		cout << endl << "账号密码错误请重新输入\n\n";

	} while (!bIsLogin);
	return;

}

//录入学生信息
void AddStudentInfo() {
	StudentInfo StudentInfo = {};
	cout << "当前录入的学生序号: " << StudentInfoArrLength + 1 << endl;
	cout << "输入学生姓名: ";
	cin >> StudentInfo.Name;
	cout << "学号: ";
	cin >> StudentInfo.StudentID;
	cout << "性别: ";
	cin >> StudentInfo.Sex;
	cout << "年龄: ";
	cin >> StudentInfo.Age;
	cout << "\n学生信息 姓名:" << StudentInfo.Name
		<< "  学号:" << StudentInfo.StudentID
		<< "  性别:" << StudentInfo.Sex
		<< "  年龄:" << StudentInfo.Age;
	StudentInfoArr[StudentInfoArrLength] = StudentInfo;
	StudentInfoArrLength++;
	cout << endl << "添加成功";
	cout << "输入1返回首页";
	ToHome();

};
#pragma region 系统函数

//显示学生信息
void ShowStudentInfo() {
	cout << "显示学生信息\n\n";
	cout << "序号" << setw(10) << "姓名" << setw(10) << "学号" << setw(10) << "性别" << setw(10) << "年龄\n" << endl;
	for (int i = 0; i <= StudentInfoArrLength - 1; i++)
	{
		cout << setw(2)
			<< i + 1
			<< setw(12) << StudentInfoArr[i].Name
			<< setw(10) << StudentInfoArr[i].StudentID
			<< setw(10) << StudentInfoArr[i].Sex
			<< setw(8) << StudentInfoArr[i].Age << endl << endl;

	};
	cout << "输入1返回首页";
	ToHome();
};
//修改学生信息
void ChangeStudentInfo() {
	cout << "修改学生信息\n\n输入需要修改的学生序号: ";
	int Index;
	cin >> Index;

	StudentInfo StudentInfo = {};
	cout << "当前要修改的学生序号: " << Index << endl;
	cout << "输入学生姓名: ";
	cin >> StudentInfo.Name;
	cout << "学号: ";
	cin >> StudentInfo.StudentID;
	cout << "性别: ";
	cin >> StudentInfo.Sex;
	cout << "年龄: ";
	cin >> StudentInfo.Age;
	cout << "\n学生信息 姓名:" << StudentInfo.Name
		<< "  学号:" << StudentInfo.StudentID
		<< "  性别:" << StudentInfo.Sex
		<< "  年龄:" << StudentInfo.Age;
	StudentInfoArr[Index - 1] = StudentInfo;
	cout << endl << "修改成功";
	cout << "输入1返回首页";
	ToHome();
};
//查找学生信息
void SearchStudentInfo() {
	//cout << "查找学生信息可输入姓名、学号、性别、年龄等信息查找\n";
	cout << "输入学生姓名查找:  ";
	string Seach;
	cin >> Seach;

	cout << "搜索结果" << endl;
	for (int i = 0; i <= StudentInfoArrLength - 1; i++)
	{
		if (StudentInfoArr[i].Name == Seach) {
			cout << "\n学生信息 姓名: " << StudentInfoArr[i].Name
				<< "  学号: " << StudentInfoArr[i].StudentID
				<< "  性别: " << StudentInfoArr[i].Sex
				<< "  年龄: " << StudentInfoArr[i].Age;
			break;
		}
		else if (!(StudentInfoArr[i].Name == Seach)
			&&
			i == StudentInfoArrLength - 1) {
			//system("pause");
			cout << "\n占无此学生";
		}


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
			for (int i = 0; i <= StudentInfoArrLength - 1; i++)
			{
				StudentInfoArr[i] = StudentInfo{};
			}
			StudentInfoArrLength = 0;
			cout << "删除成功\n";
			cout << "输入1返回首页";
			ToHome();
			return;
		}

	}
	int Index;
	cout << "输入要删除的学生序号\n";
	cin >> Index;

	//删除单个用户 , 在此用户的位置后面的数据往前唯一一位
	for (int i = Index - 1; i <= StudentInfoArrLength - 1; i++)
	{
		StudentInfoArr[i] = StudentInfoArr[i + 1];
	}
	StudentInfoArrLength--;
	cout << "删除成功\n\n";
	cout << "输入1返回首页";
	ToHome();
};
//退出系统
void Logout() {
	return;
}
//根据不同用户信息展示 管理员 教师 学生功能
void GetUserFun(Permission obj) {
	int Index = 1;

	cout << "欢迎来到学生管理系统" << endl;

	cout << "您是" << UserInfo.UserType << "\n\n";

	if (obj.bIsAdd) {
		cout << "【" << Index << "】录入学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Add";
	}
	if (obj.bIsChange) {
		cout << "【" << Index << "】更改学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Change";

	}
	if (obj.bIsShow) {
		cout << "【" << Index << "】显示学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Show";
	}
	if (obj.bIsSeach) {
		cout << "【" << Index << "】查找学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Seach";
	}
	if (obj.bIsDel) {
		cout << "【" << Index << "】删除学生信息\n" << endl;
		Index++;
		FunList[Index - 1] = "Del";
	}
	if (obj.bIsAllDel) {
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

