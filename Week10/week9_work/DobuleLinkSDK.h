#pragma once
#include <iostream>
#include <vector>

using namespace std;

#pragma region ˫�����������˼·���������
/*
	˫�����������˼·���������
		����:
			���߼� : ����������Աʹ�õĹ��߼� , ����װ��������������Աֻ��Ҫ���ú������ɴ����ɾ�Ĳ�����Ŀ��
		�������� :
			�� : ����������һ������һ������ , �����ظ�������ڴ��ַ�����ڵ�����λ�÷������������
			ɾ : �����û������Data��ֵ , �ҵ���Ԫ�ؽ���ɾ�� , ���Ѻ�̽ڵ� | ǰ�̵�Prev��Next��������ʹ�������� , �ɷ���ɾ���Ƿ�ɹ��ͺ�̽ڵ�ָ���ַ�����������
			�� : �û�����Data���ݱ������� ,�ҵ��󲢰���ֵ���� , �󷵻��ڴ��ַ��
			�� : ����Data�������� , �����Ƿ��ҵ� �ҵ������ڴ��ַ , �Ҳ�������false��
*/
#pragma endregion


#pragma region ����ṹ��
template <class T>
struct FData
{
	T Data; //����
	FData* Prev; //ͷ
	FData* Next; //β

	FData() : Data(T()), Prev(nullptr), Next(nullptr) {}
};
#pragma endregion

#pragma region ����
template <class T>
void AddData(FData<T>*& Head, T Value) {
	//�½����ͽڵ�
	FData<T>* NewNode = new FData<T>();
	NewNode->Data = Value;

	// ˵����һ�ν���
	if (Head == nullptr) {
		Head = NewNode;
	}
	else {
		//����βԪ��
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

#pragma region ɾ��
template <class T>
bool DeleteData(FData<T>*& Head, int Value) {
	FData<T>* Temp = Head;

	while (Temp != nullptr)
	{
		/*
		���һ ���ݾ��ڵ�һ��
			��next->prev�ÿ� , ɾ������ ,
		����� ����ֻ��һ���Ҳ��ҵľ����Լ�
			ɾ������
		����� ���ҵ�ֵ�����һ��
			��temp->prev->Next �ÿ� ,  Ȼ��ɾ���Լ�
		����� ����ֵ���м���ǰ���ýڵ�
			�� temp->prev->Next = temp->next
			temp->next->prev = temp->prev
		*/
		if (Temp->Data.StudentID == Value) {

			if (Temp->Prev == nullptr && Temp->Next == nullptr)
			{
				//cout << "����ֻ��һ���Ҳ��ҵľ����Լ�\n" << Temp->Data;
				delete Head;
				Head = nullptr;
				return true;
			}
			else if (Temp->Next != nullptr && Temp->Prev != nullptr) {
				//cout << "ɾ���������м������\n";
				Temp->Prev->Next = Temp->Next;
				Temp->Next->Prev = Temp->Prev;
				delete Temp;
				Temp = nullptr;
				return true;
			}
			else if (Temp->Next != nullptr) {
				//cout << "ɾ�����ݾ��ڵ�һ��,���к�Ԫ��\n";
				Head = Temp->Next;
				Head->Prev = nullptr;
				delete Temp;
				Temp = nullptr;
				return true;
			}
			else if (Temp->Next == nullptr) {
				//cout << "ɾ�����������һ��\n";
				Temp->Prev->Next = nullptr;
				delete Temp;
				Temp = nullptr;
				return true;
			}
		}
		//��ǰval ��ƥ��temp����Ųһλ
		Temp = Temp->Next;
	}
	return false;
}
#pragma endregion

#pragma region ��
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

#pragma region ��
template <class T>
T* SearchData(FData<T>*& Head, int queryStudentID) {
	FData<T>* Temp = Head;
	while (Temp != nullptr) {
		if (Temp->Data.StudentID == queryStudentID) {
			return &(Temp->Data);
		}
		Temp = Temp->Next;
	}
	return nullptr; // ���û���ҵ����򷵻� nullptr
}

#pragma endregion

#pragma region ð������
template <class T>
void Sort(FData<T>*& Head, int Mode = 0) {
	/// 0 ���� 1���� ��̬���㵹������
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

			if (Compare(Cur->Data, Cur->Next->Data)) {
				T Temp = Cur->Data;
				Cur->Data = Cur->Next->Data;
				Cur->Next->Data = Temp;
				bSwapped = true;
			}
			Cur = Cur->Next;
		}
		LinkTail = Cur; //�´�ѭ���ų����Ԫ��

	} while (bSwapped);
}

#pragma endregion

#pragma region ��������
template <class T>
vector<T*> ShowAllData(FData<T>* Head) {
	FData<T>* Temp = Head;
	vector<T*> pArr;

	while (Temp != nullptr) {
		pArr.push_back(&(Temp->Data));
		Temp = Temp->Next;
	}
	//��������������������ɵ�����ָ��
	return pArr;
}

#pragma endregion
