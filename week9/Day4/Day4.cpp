
#include <iostream>

using namespace std;

int main()
{
	cout << "Hello World!\n";

#pragma region for循环
	// 循环次数  从开始  到什么结束  增量 index
	// for(int i = 1; i <= 10; ++i){}
	/*for (int i = 1; i <= 10; ++i)
	{
		cout << "Hello" << endl;
	}*/
	
	// for(); 不允许在条件的()后面直接加; 
		// 直接在()加; 表示循环结束啦(循环没有循环体) 
	// 按照上面的写法 i变量在{}外面（循环体的外面）不能访问的
	// 循环需要注意不要死循环（）

	// 计算1 - 100之间所有数的和；
	//
	/*int Sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		Sum += i;
	}
	cout << Sum << endl;*/


	// 计算1 - 100之间所有奇数的和； 1 3 5 7 9
	/*int Sum = 0;*/
	/*for (int i = 1; i <= 100; i++)
	{
	 
		if (i % 2 != 0)
		{
			Sum += i;
		}
	}
	cout << Sum << endl;*/

	/*for (int i = 1; i < 100; i += 2)
	{
		Sum += i;
	}
	cout << Sum << endl;*/
	
	// 计算1 - 100之间所有偶数的和；

	// 输出所有三位数中的水仙花数（个位立方 + 十位立方 + 百位立方 = 本身，如153）
	// 水仙花数是指一个 3 位数，它的每个数位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153。
	// 100 999(1000)  +1 
	// 459 4 5 9  4*4*4+5*5*5+9*9*9 == 459

	// 459    459 / 100 = 4     459 / 10 % 10 = 5    459 % 10 = 9
	/*int Num = 721;
	cout << (Num / 100) << " " << (Num / 10 % 10) << " " << (Num % 10) << endl;*/

	//for (int i = 100; i <= 999; ++i)
	//{
	//	int H = i / 100; // 百位
	//	int S = i / 10 % 10; // 十位
	//	int G = i % 10; // 个位
	//	if (H * H * H + S * S * S + G * G * G == i)
	//	{
	//		cout << i << endl;
	//	}
	//}

	// 外层循环控制行数，内层循环控制列数
	/*for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << i << " - " << j << " ";
		}
		cout << endl;
	}*/
	// 九九乘法表
	// i 表示行  j 表示列
	//for (int i = 1; i <= 9; ++i)
	//{
	//	for (int j = 1; j <= i; ++j)
	//	{
	//		// 1 * 2 = 2
	//		cout << j << " * " << i << " = " << j * i << (j * i >= 10 ? " " : "  ");
	//	}
	//	cout << endl;
	//}


	// 1000以内的完数 1-1000
	// 完数：一个数的真因子之和 == 自身
	 //真因为：除了自身以外的约数（小于自身，自身能整除这个数） 10 % 1  < 10 == 0
	/*for (int i = 1; i <= 1000; ++i)
	{
		int Sum = 0;
		for (int j = 1; j < i; ++j)
		{
			if (i % j == 0)
			{
				Sum += j;
			}
		}
		if (Sum == i)
		{
			cout << i << endl;
		}
	}*/

	// 打印星星
	//int Num = 0;
	//cout << "请输入要打印星星的行数：";
	//cin >> Num;
	//// 控制行数
	//for (int i = 1; i <= Num; ++i)
	//{
	//	// 打印空格
	//	for (int j = 1; j <= i - 1; ++j)
	//	{
	//		cout << " ";
	//	}
	//	for (int j = (Num - i) * 2 + 1; j >= 1; --j)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}

	


#pragma endregion

#pragma region size_t
	// 循环中不要使用size_t，除非循环条件中没有赋值且0需要格外关注

	// size_t unsigned long long 
	/*size_t Num = -5;
	cout << Num << endl;*/
	
	// 死循环
	/*for (size_t i = 5; i >= 0; i--)
	{
		cout << "执行" << endl;
	}*/

	// 执行了五次
	/*for (size_t i = 5; i > 0; i--)
	{
		cout << "执行" << endl;
	}*/

	//size_t Num = -1;
	//cout << Num << endl;
	//// 不会执行
	//for (size_t i = 5; i >-1; i--)
	//{
	//	cout << "执行" << endl;
	//}

	// 执行了6次
	/*for (size_t i = 5; i < -1; i--)
	{
		cout << "执行" << endl;
	}*/

#pragma endregion

#pragma region continue break
	//int Sum = 0;
	//for (int i = 1; i < 100; ++i)
	//{
	//	int G = i % 10; // 求个位数
	//	// continue  跳过此次循环（进入下一次循环）
	//	// break 跳出（当前）循环  
	//	if (G % 3 == 0)
	//	{
	//		continue;
	//		// break;
	//	}
	//	Sum += i;
	//}
	//cout << Sum << endl;
#pragma endregion

#pragma region while 和 dowhile
	// 有2000块本金，存银行，年利率为2.5%，几年后本息可以超过4000（不确定循环执行次数）
	//  while (true){ }
	// while 用在没有明确的执行次数的情况下，否则优先选择for循环

	//// 与for循环相比  控制循环的变量需要在循环外单独定义   循环的增量需要在循环体中处理
	//float Money = 2000; // 2000 + 2000 * 0.025f
	//int Year = 0;
	//while (Money <= 4000)
	//{
	//	Year++;
	//	Money *= 1.025f;
	//}
	//cout << Year << endl;

	// 
	// int Num = 10;
	// 当条件不满足的时候循环就不会执行
	/*while (Num < 5)
	{
		cout << "测试" << endl;
		Num++;
	}*/
	/*do
	{
		cout << "测试" << endl;
		Num++;
	} while (Num < 5);*/

	// 结论  while有可能一次也不执行，但是do while保证程序至少执行一次


#pragma endregion

#pragma region 补充 死循环指令   goto
	// 1、  2、 3、 5
	//int Cmd = 0; // 输入的指令（选项）
	//while (Cmd != 5)
	//{
	//	cout << "1、添加新用户（手动输入用户信息）；" << endl;
	//	cout << "2、修改已存在的用户信息；" << endl;
	//	cout << "3、查找指定的某个用户；" << endl;
	//	cout << "5、退出系统" << endl;
	//	cout << "请输入要选择的指令: ";
	//	cin >> Cmd;
	//}
	//exit(0); // 退出程序

	// goto 只有第一周可以用
	// 第一步 写标签 英文:
	// 跳转标签

//Label1:
//	for (int i = 0; i < 10; ++i)
//	{
//	
//		cout << "Hello " << i << endl;
//	}
//
//
//	int Num = 10;
//	
//	Num++;
//	cout << Num << endl;
//	goto Label1;
//	cout << "goto之后的语句";
#pragma endregion

#pragma region 数组
	// 含义  存储一组相同类型的数据的容器
	// 一组   相同数据类型   容器

	// 语法  类型 变量名[个数]
	//int Nums[10]; // 定义数组变量并且指定个数
	//int Nums2[5] = { 1, 2, 3, 4, 5}; // 声明的时候同时赋值  {}个数不能比前面定义的时候多
	//int Nums3[5]{ 1, 2, 3}; // 省略 =  // {}中的个数可以比前面定义的时候少
	int Nums4[]{ 1, 2, 3, 4, 5 ,  1, 2, 3}; // 省略个数，通过{}的值来推断数组有几个元素
	//int Nums5[5]{};
	// int Nums5[]; // 不能不写个数也不赋值

	// 注意点：数组在定义的时候就把个数规定好了，后面不能改变数组的长度

	//// 访问数组中的元素
	//Nums2[2] = 300; // 改写数组中的元素
	//cout << Nums2[2] << endl; // 表示访问获取Nums2数组中索引为2的元素，索引从0开始

	//// 访问数组中的默认值
	//// cout << Nums[0] << endl; // 如果数组元素使用第一种定义方式，内部是垃圾值
	//cout << Nums3[3] << endl; // 使用第三种赋值（部分赋值）的方式，没赋值的部分是0
	//cout << Nums5[0] << endl; // 使用第五种赋值方式，默认值是0

	// 访问的时候索引越界会发生生么 -> 数组访问的时候不要越界
	// cout << Nums2[5] << endl; // 如果是数字，不会发生崩溃。如果是复杂类型（指针）发生崩溃

	// 数组的遍历   挨个访问数组中的元素
	// 数组长度1  size(数组)
	//cout << size(Nums4) << endl;
	//// 数组长度2  整个空间大小 / 一个元素的空间大小 = 数组个数
	//// sizeof(Nums4)整个数组占用的内存空间   sizeof(Nums4[0]) 表示第0个索引的数据占用的内存空间
	//cout << sizeof(Nums4) << " " << sizeof(Nums4[0]) << " " << (sizeof(Nums4) / sizeof(Nums4[0])) << endl;

	/*for (int i = 0; i < size(Nums4); ++i)
	{
		cout << Nums4[i] << endl;
	}*/

	/*for (int i = 0; i < sizeof(Nums4) / sizeof(Nums4[0]); ++i)
	{
		cout << Nums4[i] << endl;
	}*/

	// 相当于蓝图中的ForEach   拿不到索引
	for (int Temp : Nums4)
	{
		cout << Temp << endl;
	}


	// 练习1 定义存储姓名的数组，并按照A，B，C 的形式打印，最后一个元素后没有，
	//string Names[3]{ "ZhangSan", "LiSi", "WangWu" };
	//for (int i = 0; i < size(Names); ++i)
	//{
	//	// i == size(Names) - 1  表示 i 是最后一个元素
	//	cout << Names[i] << (i == size(Names) - 1 ? "" : ", ");
	//}
	
	// 练习2 输入姓名，从指定的名称数组中找到对应的索引，如果未找到打印-1
	//string Names[3]{ "ZhangSan", "LiSi", "WangWu" };
	//string Name;
	//cin >> Name;
	//int Index = -1; // 标记查找的索引
	//for (int i = 0; i < sizeof(Names) / sizeof(Names[0]); ++i)
	//{
	//	if (Names[i] == Name)
	//	{
	//		// 说明找到了
	//		Index = i;
	//		break; // 找到之后退出
	//	}
	//}
	//cout << Index << endl;

#pragma endregion



}

