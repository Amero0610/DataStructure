#include <iostream>
using namespace std;
#define MaxSize 30

template<class DataType>
class SeqStack
{
public:
	SeqStack();
	~SeqStack();
	bool PushElement(DataType x);
	DataType Pop();
	DataType GetTop();
	bool JudgeEmpty();

private:
	DataType data[MaxSize];
	int top;
};

template<class DataType>
SeqStack<DataType>::SeqStack()
{
	top = -1;
}

template<class DataType>
SeqStack<DataType>::~SeqStack()
{
	
}

template<class DataType>
bool SeqStack<DataType>::PushElement(DataType x)
{
	if (top == MaxSize - 1)
	{
		return false;
	}
	data[++top] = x;
}

template<class DataType>
DataType SeqStack<DataType>::Pop()
{
	DataType tempElement = data[top];
	top--;
	return tempElement;
}

template<class DataType>
DataType SeqStack<DataType>::GetTop()
{
	return data[top];
}

template<class DataType>
bool SeqStack<DataType>::JudgeEmpty()
{
	if (top == -1) 
	{
		return true;
	}
}
void show()
{
	cout << "============================" << endl;
}
void main()
{
	int TestArray[10] = { 11,32,34,56,12,78,54,32,89,11 };
	SeqStack<int> seqstack = SeqStack<int>();
	for (int i = 0; i < 10; i++)
	{
		seqstack.PushElement(TestArray[i]);
	}
	show();
	cout << "Get Top" << endl;
	cout << seqstack.GetTop() << endl;
	show();
	cout << "Pop Element" << endl;
	cout << seqstack.Pop() << endl;
	cout << seqstack.GetTop() << endl;
}