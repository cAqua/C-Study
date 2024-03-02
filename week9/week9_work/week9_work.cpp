
#include <iostream>

using namespace std;

#pragma region 系统结构体

/* 结构体学生信息 */
struct StudentInfo
{
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
	//{"张三",1001,"男",18},
	//{"李四",1002,"女",20},
	//{"王五",1003,"男",18},
};
int StudentInfoArrLength = 0;

#pragma endregion

#pragma region 账号密码

/* 设定登录账号密码 */
struct UserAccountInfo
{
	//账号
	string Account;
	//密码
	string Password;
};
//账号和密码
UserAccountInfo UserAccoutInfoArr[2] = {
	{"admin","88888888"},
	{"123","123"}
};
bool IsLogin = false;


#pragma endregion

#pragma region 函数声明

void Login();//登录;
void AddStudentInfo();//录入学生信息
void ShowStudentInfo();//显示学生信息
void ChangeStudentInfo();//修改学生信息
void SearchStudentInfo();//查找学生信息
void DelStudentInfo(bool IsDellAii = false);//删除学生信息
void Logout();//退出系统
void ToHome();//展示首页


#pragma endregion



int main()
{
	//登录
	if (!IsLogin) {
		//Login();
	};
	int function;
	cout << "学生管理系统" << endl << endl;
	cout << "【1】录入学生信息" << endl;
	cout << "【2】显示学生信息" << endl;
	cout << "【3】修改学生信息" << endl;
	cout << "【4】查找学生信息" << endl;
	cout << "【5】删除学生信息" << endl;
	cout << "【6】删除所有学生信息,需要登录管理员账号密码" << endl;
	cout << "【7】退出系统" << endl;
	cout << "请选择功能：";
	cin >> function;
	switch (function)
	{
	case 1:
		//录入学生信息
		AddStudentInfo();
		break;
	case 2:
		//显示学生信息
		ShowStudentInfo();
		break;
	case 3:
		//修改学生信息
		ChangeStudentInfo();
		break;
	case 4:
		//查找学生信息
		SearchStudentInfo();

		break;
	case 5:
		//删除学生信息
		DelStudentInfo();
		break;
	case 6:
		//删除所有学生信息
		DelStudentInfo(true);
		break;
	case 7:
		//删除所有学生信息
		Logout();
		break;
	}


}






//登录
void Login() {
	string account;
	string password;
	do {
		cout << "欢迎来到学生管理系统" << endl;
		cout << "请输入账号密码登录" << endl;
		cout << "请输入账号:  ";
		cin >> account;
		cout << "请输入密码:  ";
		cin >> password;
		//判断账号密码
		for (int i = 0; i < size(UserAccoutInfoArr); i++)
		{
			if (UserAccoutInfoArr[i].Account == account
				&&
				UserAccoutInfoArr[i].Password == password) {
				cout << "账号密码正确";
				IsLogin = true;
				system("cls");
				return;

			}
		}
		cout << endl << "账号密码错误请重新输入\n\n";
		//system("cls");

	} while (!IsLogin);
	return;



}

//录入学生信息
void AddStudentInfo() {
	StudentInfo StudentInfo = {};
	cout << "当前录入的学生序号: " << StudentInfoArrLength << endl;
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
	cout << "显示学生信息\n";

	for (int i = 0; i <= StudentInfoArrLength; i++)
	{

		cout << "序号:" << i
			<< "  姓名:" << StudentInfoArr[i].Name
			<< "  学号:" << StudentInfoArr[i].StudentID
			<< "  性别:" << StudentInfoArr[i].Sex
			<< "  年龄:" << StudentInfoArr[i].Age << endl << endl;

	};

	cout << "输入1返回首页";
	ToHome();


};
//修改学生信息
void ChangeStudentInfo() {
	cout << "修改学生信息\n输入需要修改的学生序号";
	int index;
	cin >> index;

	StudentInfo StudentInfo = {};
	cout << "当前要修改的学生序号: " << index << endl;
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
	StudentInfoArr[index] = StudentInfo;
	//StudentInfoArrLength++;
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
	for (int i = 0; i <= StudentInfoArrLength; i++)
	{
		if (StudentInfoArr[i].Name == Seach) {
			cout << "\n学生信息 姓名:" << StudentInfoArr[i].Name
				<< "  学号:" << StudentInfoArr[i].StudentID
				<< "  性别:" << StudentInfoArr[i].Sex
				<< "  年龄:" << StudentInfoArr[i].Age;
		}
	}
	cout << "\n输入1返回首页";
	ToHome();


};
//删除学生信息
void DelStudentInfo(bool IsDellAii) {
	cout << " IsDellAii" << IsDellAii << endl;
	cout << "删除学生信息\n";


	//删除所有用户
	if (IsDellAii) {
		string password;
		cout << "需要密码才能删除";
		cout << "请输入密码:  ";
		cin >> password;

		if (password == "88888888") {
			for (int i = 0; i <= StudentInfoArrLength; i++)
			{
				StudentInfoArr[i] = StudentInfo{};
			}
			//StudentInfoArr[10] = {};
			cout << "删除成功\n";
			cout << "输入1返回首页";



			//ToHome();
			//return;
		}

	}
	int index;
	cout << "输入要删除的学生序号\n";
	cin >> index;

	for (int i = index; i <= StudentInfoArrLength; i++)
	{
		StudentInfoArr[i] = StudentInfoArr[i + 1];
	}
	StudentInfoArrLength--;

	for (int i = 0; i <= StudentInfoArrLength; i++)
	{
		cout << "\n学生信息 姓名:" << StudentInfoArr[i].Name
			<< "  学号:" << StudentInfoArr[i].StudentID
			<< "  性别:" << StudentInfoArr[i].Sex
			<< "  年龄:" << StudentInfoArr[i].Age;
	}
	cout << "输入1返回首页";
	ToHome();
};
//退出系统
void Logout() {
	//system("taskkill /IM /F cmd.exe");
}

#pragma endregion

#pragma region 功能函数

void ToHome() {
	int enter;
	cin >> enter;
	system("cls");
	main();
}

#pragma endregion

