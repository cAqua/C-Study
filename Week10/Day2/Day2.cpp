

#include <iostream>
#include <fstream>
#include <string>

#include "Util.h" // 包含一个头文件  把头文件中的内容原封不动的复制到这个地方
#include "Util.h"
#include "Util.h"



using namespace std;


struct FStudent
{
    int ID = 0;
    // string Name = "";
    char Name[64]{};
    bool bIsMale = false;
};



FStudent Students[10]{};

// 定义一个函数，可以选择保存的文件名，也可以选择保存是否为二进制
// 保存一个结构体数组
void SaveFile(string FileName, bool bUseBinary = false);

int main()
{
    std::cout << "Hello World!\n";

#pragma region 文件写复习
    //Students[0] = { 10010, "张三", true };
    //Students[3] = { 10011, "李四", true };

    //cout << "输入需要保存的文件名：";
    //string FileName;
    //cin >> FileName;
    //SaveFile(FileName); // SaveFile("Info.txt");
#pragma endregion

#pragma region 文件读
//    // 包含头文件  定义变量   打开文件  读内容  关闭文件
//    ifstream In; // input file stream 
//    In.open("Info.txt");
//    string Str;
//
//#pragma region 不同的读取方式
//   // In >> Str; // 遇到空格自动停止
//   /* while (In >> Str)
//    {
//        cout << Str << endl;
//    }*/
//
//    // getline(In, Str); // 读取一行
//    /*while (getline(In, Str))
//    {
//        cout << Str << endl;
//    }*/
//
//    //// 其他读取方式1
//    //char Content[1024];
//    //while (In >> Content)
//    //{
//    //    cout << Content << endl;
//    //}
//
//    // 其他读取方式2
//    // In.getline()
//    // 第二个参数，读取长度如果设置的不对，读不出来内容，sizeof(变量)
//    /*char Content[1024];
//    while (In.getline(Content, sizeof(Content)))
//    {
//        cout << Content << endl;
//    }*/
//
//    //// 其他读取方式3 一个字符一个字符的读
//    //char C = In.get(); // C默认值一般是先读文件的一个字符
//    //// EOF // 表示End Of File
//    //while (C != EOF)
//    //{
//    //    cout << C;
//    //    C = In.get(); // 读下一个字符，赋值给C
//    //}
//#pragma endregion
//
//    
//
//    In.close();
#pragma endregion

#pragma region 文件读写案例
    // 读写结构体
    //FStudent Student1 = { 10010, "王柳", true };
    //ofstream Out;
    //Out.open("Stu1.txt");
    //Out << Student1.ID << " " << Student1.Name << " " << Student1.bIsMale << endl;
    //Out.close();

    //ifstream In;
    //In.open("Stu1.txt");
    //// 10010 张三 1
    //FStudent Student2;
    //In >> Student2.ID >> Student2.Name >> Student2.bIsMale;
    //In.close();
    //cout << Student2.ID << ":" << Student2.Name << " " << Student2.bIsMale << endl;

    // 读写字符串数组
    //string Names[5]{ "张三", "里斯1", "王 五", "赵六", "朱琪" };
    //ofstream Out;
    //Out.open("Names.txt");
    //for (int i = 0; i < size(Names); ++i)
    //{
    //    Out << Names[i] << endl;
    //}
    //Out.close();

    //string Names1[5]{};
    //ifstream In;
    //In.open("Names.txt");
    //for (int i = 0; i < size(Names1); ++i)
    //{ 
    //    // In >> Names1[i]; // 如果字符串本身带空格，会读乱
    //    getline(In, Names1[i]);
    //}
    //In.close();

    //for (int i = 0; i < size(Names1); ++i)
    //{
    //    cout << Names1[i] << endl;
    //}
    
    // 读写结构体数组
    //Students[0] = { 10010, "张三", true };
    //Students[1] = { 10015, "赵六", false };
    //Students[3] = { 10011, "朱琪", true };
    //ofstream Out;
    //Out.open("Structs.txt");

    //int Count = 0;
    //for (int i = 0; i < size(Students); ++i)
    //{
    //    if (Students[i].ID != 0)
    //    {
    //        Out << Students[i].ID << " " << Students[i].Name << " " << (Students[i].bIsMale ? "男" : "女") << endl;
    //        Count++; // 每成功存一条数据，计数+1
    //    }
    //}
    //Out.close();

    //ifstream In;
    //In.open("Structs.txt");
    //FStudent Students1[10]{};
    ///*for (int i = 0; i < Count; ++i)
    //{
    //    In >> Students1[i].ID >> Students1[i].Name >> Students1[i].bIsMale;
    //}*/

    //// 不知道有多少条数据
    //int Index = 0;
    //string Sex = "";
    //while (In >> Students1[Index].ID >> Students1[Index].Name >> Sex)
    //{
    //    Students1[Index].bIsMale = (Sex == "男" ? true : false);
    //    // Students1[Index].bIsMale = Sex == "男";
    //    Index++; // 每成功读取一条，索引向后偏移一个单位
    //}

    //In.close();


    // 读写数组（存储个数）
    //Students[0] = { 10010, "张三", true };
    //Students[1] = { 10015, "赵六", false };
    //Students[2] = { 10018, "赵六w", false };
    //Students[3] = { 10011, "朱琪", true };
    //ofstream Out;
    //Out.open("Structs.txt");

    //int CountOfValidIndex = 0;
    //// 存文件的时候第一行应该存有效个数
    //for (int i = 0; i < size(Students); ++i)
    //{
    //    if (Students[i].ID != 0)
    //    {
    //        CountOfValidIndex++;
    //    }
    //}
    //Out << CountOfValidIndex << endl;

    //for (int i = 0; i < size(Students); ++i)
    //{
    //    if (Students[i].ID != 0)
    //    {
    //        Out << Students[i].ID << " " << Students[i].Name << " " << (Students[i].bIsMale ? "男" : "女") << endl;
    //    }
    //}
    //Out.close();



    //ifstream In;
    //In.open("Structs.txt");
    //// 首先读取存储的有效个数
    //int Count1 = 0;
    //In >> Count1;
    // 
    //FStudent Students1[10]{};
    //if (Count1 > 0)
    //{
    //    for (int i = 0; i < Count1; ++i)
    //    {
    //        string Str = "";
    //        In >> Students1[i].ID >> Students1[i].Name >> Str;
    //        Students1[i].bIsMale = Str == "男";
    //    }
    //}
    //In.close();



    //cout << "Hello" << endl;

#pragma endregion

#pragma region 二进制文件的读
    //FStudent Student{ 10018, "", false};
    //// Student.Name = "三点水";
    //// 如果结构体中使用了char[]，赋值的时候需要使用特殊的形式
    //strcpy_s(Student.Name, "三点水");

    //ofstream Out;
    //Out.open("Student.sav", ios_base::out | ios_base::binary);
    //Out.write((char*)&Student, sizeof(Student));
    //Out.close();

    //ifstream In;
    //In.open("Student.sav", ios_base::in | ios_base::binary);
    //FStudent Student1;
    //In.read((char*)&Student1, sizeof(Student1));
    //In.close();

    // cout << Student1.ID << " " << Student1.Name << " " << Student1.bIsMale << endl;

    


    // 使用二进制进行读写的时候 ，如果有string类型，F5运行会崩溃，推荐使用Ctrl+F5


    // 使用二进制读写保存一个数组
    /*int Nums[]{ 1,2,3,4,5,6 };
    ofstream Out;
    Out.open("Nums.sav", ios_base::out | ios_base::binary);
    Out.write((char*)Nums, sizeof(Nums));
    Out.close();

    ifstream In;
    In.open("Nums.sav", ios_base::in | ios_base::binary);
    int Nums1[6]{};
    In.read((char*)Nums1, sizeof(Nums1));
    In.close();

    for (int i = 0; i < size(Nums1); ++i)
    {
        cout << Nums1[i] << endl;
    }*/

   
#pragma endregion

#pragma region 二进制文件读写案例
    //// 使用二进制读写结构体数组
    //FStudent Students[]{ {10010, "龘龘", true}, {10011, "三点水", false}, {10015, "Lucy", false} };
    //ofstream Out;
    //Out.open("Info.sav", ios_base::out | ios_base::binary);
    //for (int i = 0; i < size(Students); ++i)
    //{
    //    Out.write((char*)&Students[i], sizeof(Students[i]));
    //}
    //Out.close();

    //ifstream In;
    //In.open("Info.sav", ios_base::in | ios_base::binary);
    //FStudent Students1[3]{};
    //for (int i = 0; i < size(Students1); ++i)
    //{
    //    In.read((char*)&Students1[i], sizeof(Students1[i]));
    //}
    //In.close();

    //cout << "Hello" << endl;
#pragma endregion

#pragma region 多文件编程
    // 一般情况下文件是分组 .h  .cpp  Save.h  Save.cpp  有的时候只有.h，没有.cpp
    // .h中放结构体定义，枚举定义，变量的声明，函数的声明
    // .cpp中一般放实现文件
#pragma endregion

    cout << Add(50, 100) << endl;

}

void SaveFile(string FileName, bool bUseBinary)
{
    // 保存结构体数组（普通保存，二进制保存）
    ofstream Out;
    if (bUseBinary) // 使用二进制打开和保存文件
    {
        Out.open(FileName, ios_base::out | ios_base::binary);
        for (int i = 0; i < size(Students); ++i)
        {
            Out.write((char*)&Students[i], sizeof(Students[i]));
        }
    }
    else // 不使用普通格式保存和打开文件
    {
        Out.open(FileName);
        // 循环数组，挨个把结构体的内容存储到文件中
        for (int i = 0; i < size(Students); ++i)
        {
            if (Students[i].ID != 0) // 判断是否为有效数据
            {
                // 挨个存储结构体中的属性，用空格隔开，每存完一个结构体换行（）
                // Out << Students[i].ID << " " << Students[i].Name << " " << Students[i].bIsMale << endl;
            }
        }
    }

    Out.close();
}
