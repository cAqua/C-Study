#include <iostream>

using namespace std;

#pragma region 双向链表工具设计思路及需求分析
/*
	双向链表工具设计思路及需求分析
		定义:
			工具集 : 供其他程序员使用的工具集 , 即封装出方法其他程序员只需要调用函数即可达成增删改查排序目的
		功能描述 :
			增 : 往链表的最后一项增加一项数据 , 并返回该数组的内存地址及所在的索引位置方便后续操作。
			删 : 根据用户输入的Data的值 , 找到该元素进行删除 , 并把后继节点 | 前继的Prev和Next关联操作使链表完整 , 可返回删除是否成功和后继节点指针地址方便后续操作
			改 : 用户传入Data数据遍历链表 ,找到后并把新值填入 , 后返回内存地址。
			查 : 根据Data遍历链表 , 返回是否找到 找到返回内存地址 , 找不到返回false。
*/
#pragma endregion


#pragma region 链表结构体
template <class T>
struct FData
{
	T Data; //数据
	FData* Prev; //头
	FData* Next; //尾

	FData() : Data(T()), Prev(nullptr), Next(nullptr) {}
};
#pragma endregion

#pragma region 增加
template <class T>
void AddData(FData<T>*& Head, T Value) {
	//新建泛型节点,
	FData<T>* NewNode = new FData<T>();
	NewNode->Data = Value;

	// 说明第一次进入
	if (Head == nullptr) {
		Head = NewNode;
	}
	else {
		//查找尾元素
		FData<T>* Temp = Head;
		while (Temp->Next != nullptr)
		{
			Temp = Temp->Next;
		}
		Temp->Next = NewNode;
		NewNode->Prev = Temp;
	}

};
#pragma endregion

#pragma region 删除
template <class T>
void DeleteData(FData<T>*& Head, T Value) {
	FData<T>* Temp = Head;

	while (Temp != nullptr)
	{
		/*
		情况一 数据就在第一项
			把next->prev置空 , 删除本身 ,
		情况二 链表只有一项且查找的就是自己
			删除本身
		情况三 查找的值在最后一项
			把temp->prev->Next 置空 ,  然后删除自己
		情况四 链表值在中间有前后置节点
			把 temp->prev->Next = temp->next
			temp->next->prev = temp->prev
		*/
		if (Temp->Data == Value) {

			if (Temp->Prev == nullptr && Temp->Next == nullptr)
			{
				//cout << "链表只有一项且查找的就是自己\n" << Temp->Data;
				delete Head;
				Head = nullptr;
				return;
			}
			else if (Temp->Next != nullptr && Temp->Prev != nullptr) {
				//cout << "删除了链表中间的数据\n";
				Temp->Prev->Next = Temp->Next;
				Temp->Next->Prev = Temp->Prev;
			}
			else if (Temp->Next != nullptr) {
				//cout << "删除数据就在第一项,且有后即元素\n";
				Head = Temp->Next;
				Head->Prev = nullptr;
			}
			else if (Temp->Next == nullptr) {
				//cout << "删除数据在最后一项\n";
				Temp->Prev->Next = nullptr;
			}
			delete Temp;
			Temp = nullptr;
			return;

		}
		//当前val 不匹配temp往后挪一位
		Temp = Temp->Next;
	}

}
#pragma endregion

#pragma region 改
template <class T>
FData<T>* ChangeData(FData<T>*& Head, T OldValue, T NewValue) {
	FData<T>* Temp = Head;
	while (Temp != nullptr)
	{
		if (Temp->Data == OldValue) {
			Temp->Data = NewValue;
			return Temp;
		}
		else if (Temp->Next == nullptr) {
			return Temp->Next;
		}
		Temp = Temp->Next;
	}
}

#pragma endregion

#pragma region 查
template <class T>
FData<T>* SeachData(FData<T>*& Head, T Query) {
	FData<T>* Temp = Head;
	while (Temp != nullptr)
	{
		if (Temp->Data == Query) {
			return Temp;
		}
		else if (Temp->Next == nullptr) {
			return Temp->Next;
		}
		Temp = Temp->Next;
	}
	cout << Head;
};
#pragma endregion

#pragma region 冒泡排序
template <class T>
void Sort(FData<T>*& Head, int Mode = 0) {
	/// 0 正序 1倒序 动态计算倒序正序
	auto Compare = (Mode == 0) ?
		[](T a, T b) { return a > b; } :
		[](T a, T b) { return a < b; };

	bool bSwapped;
	FData<T>* Cur = Head;
	FData<T>* LinkTail = nullptr;

	do
	{

		bSwapped = false;
		Cur = Head;
		while (Cur->Next != LinkTail) {

			if (Compare(Cur->Data , Cur->Next->Data)) {
				T Temp = Cur->Data;
				Cur->Data = Cur->Next->Data;
				Cur->Next->Data = Temp;
				bSwapped = true;
			}
			Cur = Cur->Next;
		}
		LinkTail = Cur;

	} while (bSwapped);
}

#pragma endregion

#pragma region 遍历所有
template <class T>
void ShowAllData(FData<T>*& Head) {
	FData<T>* Temp = Head;
	while (Temp != nullptr)
	{
		//返回一个指针数组 
		cout << "该节点的地址" << Temp << endl;
		cout << "该链表值为: " << Temp->Data;
		cout << "  它的Prev指针" << Temp->Prev;
		cout << "-它的Next指针" << Temp->Next;
		cout << endl << endl;
		if (Temp->Next != nullptr) {
			Temp = Temp->Next;
			continue;
		}
		Temp = nullptr; //表示链表已经到头
	}

}
#pragma endregion

int main()
{
	FData<string>* Head = nullptr;

	AddData<string>(Head, "6");
	AddData<string>(Head, "4");
	AddData<string>(Head, "9");
	AddData<string>(Head, "3");
	AddData<string>(Head, "8");
	AddData<string>(Head, "1");
	AddData<string>(Head, "2");
	AddData<string>(Head, "5");
	AddData<string>(Head, "7");

	//DeleteData<string>(Head, "6");


	//ChangeData<string>(Head, "3", "1");
	//cout << ChangeData<string>(Head, "", "");
	//FData<string>*  Result = ChangeData<string>(Head, "7", "10");
	//if (Result != nullptr) {
	//	cout << "更改成功\n";
	//}
	//else {
	//	cout << "更改失败\n";
	//}

	//FData<string>* SeachResult = SeachData<string>(Head, "7");
	//if (SeachResult != nullptr)
	//{
	//	cout << "找到了" << SeachResult->Data << "它的地址是" << SeachResult << endl;
	//}
	//else {
	//	cout << "没有改项" << endl;
	//}

	Sort(Head, 0); //正序
	ShowAllData(Head);


	//cout << StudentInfoArr;
	system("pause");
	return 0;
}

