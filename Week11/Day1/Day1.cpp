#include <iostream>
#include "FStudent.h"
#include "Util.h"


using namespace std;

int Add(int Num1, int Num2) { return Num1 + Num2; }
int Subtract(int Num1, int Num2) { return Num1 - Num2; }

void TestFunc(int Num1, int Num2, int (*ptr)(int, int)) { cout << ptr(Num1, Num2) << endl; }

int main()
{
    std::cout << "Hello World!\n";

#pragma region 函数指针复习
    //int (*Temp)(int, int) = Add;
    //cout << Temp(50, 500) << endl;
    //// cout << (*Temp)(50, 500) << endl; // 函数指针的第二种用法
    //Temp = Subtract;
    //cout << Temp(50, 500) << endl;

    //TestFunc(500, 1000, Add);
    //TestFunc(500, 1000, Subtract);
#pragma endregion

#pragma region 函数指针数组
    ////// 函数指针数组的第一种写法  在函数指针类型后面[个数] 最后使用{}进行初始化
    //int (*Funcs[2])(int, int) {Add, Subtract};
    ////// 按照索引访问
    ////cout << Funcs[1](100, 200) << endl;
    ////cout << (*Funcs[1])(100, 200) << endl;

    ////cout << endl;
    ////// 遍历数组，访问函数指针
    //for (int i = 0; i < size(Funcs); ++i)
    //{
    //    if (Funcs[i])
    //    {
    //        cout << Funcs[i](100, 200) << endl;
    //        cout << (*Funcs[i])(100, 200) << endl;
    //    }
    //}
    //// typedef第一种用法 给现有类型起一个别名
    //typedef int Int32; // int Int32  
    //Int32 Num = 500;
    //cout << Num << endl;

    //// typedef第二种用法  用在函数指针之前，用于简化函数指针类型int (*)(int, int)  Func
    //typedef int (*Func)(int, int);
    //Func ptrs[2]{ Add, Subtract };
    /*for (int i = 0; i < size(ptrs); ++i)
    {
        cout << ptrs[i](500, 200) << endl;
        cout << (*ptrs[i])(500, 200) << endl;
    }*/

#pragma endregion

#pragma region 内联函数
    // 避免函数跳转对于程序的额外开销
    // 有两种写法 1）.h中写实现文件(在.h中同时写声明和实现)    
    // 2）inline 关键字
        // 如果声明和实现拆开，都需要加inline
        // 声明和实现写道一起，然后加inline（推荐）

    // 注意点   到底是不是内联函数取决于编译器自己决定
        // 即使按照上面的写法，编译器也可以不认为这是一个内联函数
        // 即使不按照上面的写法，编译器可以认定这是一个内联函数
        // 内联函数中不允许出现循环和switch，代码不能超过十行，递归函数不能是内联函数
    // 存取函数   推荐写成内联函数  GetXX  SetXXX

    // 本质 在调用内联函数时编译器会对内联函数进行展开替换
    // 虚幻中可以强制指定某个函数必须是内联

    // cout << (Num1 + Num2) << endl;
#pragma endregion

#pragma region 宏
    // #define 定义的叫做宏 Macro

    // 宏的本质是单纯的替换，不检查类型
    // 宏的替换出现在预编译阶段（预处理指令）
    // 宏一般都是全大写字母，有的时候需要加上_区分   _FILENAME_   FILE_NAME  __FILENAME__(系统保留宏)
    //Divide(10, 5);
    //cout << __FILE__ << endl; // 表示当前文件的完整路径
    //cout << __LINE__ << endl; // 表示代码所在的行数
    //cout << __LINE__ << endl;

    // 常量宏  参考 Util.h
    // 宏中带参数
    /*cout << ADD(10, 20) << endl;
    cout << ADD(10, 20);*/

    int Result = 10 % MULTIPLY(50, 2);
    // Result = 10 % 50 * 2;
    cout << Result << endl; // 10 

    int Max = MAX(10, 50); // (((10) > (50)) ? (10) : (50))
    cout << Max << endl;
#pragma endregion

#pragma region 常量

#pragma endregion

#pragma region 引用

#pragma endregion

#pragma region 作用域

#pragma endregion


}


