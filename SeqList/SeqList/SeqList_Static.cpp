#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MaxSize 20
using namespace std;
template<class DataType>
class SeqList
{
public:
	SeqList();
	~SeqList();
	SeqList(DataType a[], int n);
	int GetLength();
	DataType GetElement(int index);
	int GetLocate(DataType e);
	void InsertElement(int index, DataType e);
	DataType DeleteElement(int index);
	void PrintList();
private:
	DataType data[MaxSize];
	int length;
};
template<class DataType>
SeqList<DataType>::SeqList()
{
	length = 0;
}
template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MaxSize)
	{
		throw "false";
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}
template<class DataType>
SeqList<DataType>::~SeqList()
{
}
template<class DataType>
int SeqList<DataType>::GetLength()
{
	return length;
}
template<class DataType>
DataType  SeqList<DataType>::GetElement(int index)
{
	if (index > length || index <= 0)
	{
		throw "False";
	}
	return data[index - 1];
}
template<class DataType>
int SeqList<DataType>::GetLocate(DataType e)
{
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (data[i] == e)
		{
			index = i;
		}
	}
	if (index == 0)
	{
		return false;
	}
	return index + 1;
}
template<class DataType>
void SeqList<DataType>::InsertElement(int index, DataType e)
{
	for (int j = length; j >= index; j--)
	{
		data[j] = data[j - 1];
	}
	data[index - 1] = e;
	length++;
}
template<class DataType>
DataType SeqList<DataType>::DeleteElement(int index)
{
	DataType tempelement = data[index - 1];
	for (int i = index; i < length; i++)
	{
		data[i - 1] = data[i];
	}
	length--;
	return tempelement;
}
template<class Datatype>
void SeqList<Datatype>::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}
void show()
{
	cout << "==================================" << endl;
}
int main()
{
	int TestArray[] = { 2,5,8,1,3,7,22,11,10,99 };
	int n = 10;
	SeqList<int> seqlist = SeqList<int>(TestArray,n);
	cout << "Print List" << endl;
	seqlist.PrintList();
	show();
	cout << "Insert '31' into position '5'" << endl;
	seqlist.InsertElement(5, 31);
	seqlist.PrintList();
	show();
	cout << "Get the position of element '22'" << endl;
	cout << seqlist.GetLocate(22) << endl;
	show();
	cout << "Get the element at position '2'" << endl;
	cout << seqlist.GetElement(2) << endl;
	show();
	cout << "Get Length" << endl;
	cout << seqlist.GetLength() << endl;
	show();
	cout << "Delete the element at position '6'" << endl;
	cout << "Delete the element is:  " << seqlist.DeleteElement(6) << endl;
	seqlist.PrintList();
	show();
}