#include <iostream>
#include <cstdlib>
using namespace std;

template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};
template<class DataType>
class StackLink
{
public:
	StackLink();
	~StackLink();
	void PushElement(DataType x);
	DataType Pop();
	DataType GetTop();
	bool JudgeEmpty();
private:
	Node<DataType> *top;
};

template<class DataType>
StackLink<DataType>::StackLink()
{
	top = NULL;
}

template<class DataType>
StackLink<DataType>::~StackLink()
{
}

template<class DataType>
void StackLink<DataType>::PushElement(DataType x)
{
	Node<DataType> *s = new Node<DataType>;
	s->data = x;
	s->next = top;
	top = s;
}

template<class DataType>
DataType StackLink<DataType>::Pop()
{
	Node<DataType> *p = new Node<DataType>;
	DataType x;
	if (!JudgeEmpty())
	{
		x = top->data;
		p = top;
		top = top->next;
		delete p;
		return x;
	}
	else
	{
		return 0;
	}


}

template<class DataType>
DataType StackLink<DataType>::GetTop()
{
	return top->data;
}

template<class DataType>
bool StackLink<DataType>::JudgeEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void show()
{
	cout << "================" << endl;
}
void main()
{
	StackLink<int> TestStackLink;
	for (int i = 0; i < 20; i++)
	{
		TestStackLink.PushElement(rand() % 20);
	}
	cout << "Get Top Element" << endl;
	cout << TestStackLink.GetTop() << endl;
	show();
	cout << "Delete Top Element" << endl;
	cout << TestStackLink.Pop() << endl;
	show();
	cout << "Element at The Top Now" << endl;
	cout << TestStackLink.GetTop() << endl;
}