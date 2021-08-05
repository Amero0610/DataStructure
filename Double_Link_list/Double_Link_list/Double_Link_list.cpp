#include <iostream>
using namespace std;

template<class DataType>
struct DoubleNode
{
	DataType data;
	DoubleNode<DataType> *head;
	DoubleNode<DataType> *next;
};

template<class DataType>
class DoubleLinkList
{
public:
	DoubleLinkList();
	DoubleLinkList(int n,DataType a[]);
	~DoubleLinkList();
	int GetLength();
	int GetLocate(DataType x);
	DataType GetElement(int i);
	void InsertElement(int index, DataType x);
	DataType DeleteElement(int i);
	void PrintList();
private:
	DoubleNode<DataType> *first;
};
template<class DataType>
DoubleLinkList<DataType>::DoubleLinkList()
{
	first = new DoubleNode<DataType>;
	first->next = NULL;
	first->head = NULL;
}

template<class DataType>
DoubleLinkList<DataType>::DoubleLinkList(int n, DataType a[])
{
	first = new DoubleNode<DataType>;
	DoubleNode<DataType> *r = new DoubleNode<DataType>;
	first->next = NULL;
	first->head = NULL;
	r = first;
	for (int i = 0; i < n; i++)
	{
		DoubleNode<DataType> *p = new DoubleNode<DataType>;
		/*p->data = a[i];
		p->next = first->next;
		first->next->head = p;
		p->head = first;
		first->next = p;*/
		p->data = a[i];
		p->next = NULL;
		p->head = r;
		r->next = p;
		r = p;
	}
}

template<class DataType>
DoubleLinkList<DataType>::~DoubleLinkList()
{
	DoubleNode<DataType> *p = first;
	while (p != NULL)
	{
		DoubleNode<DataType> *q = new DoubleNode<DataType>;
		q = p;
		p = p->next;
		delete q;
	}

}

template<class DataType>
int DoubleLinkList<DataType>::GetLength()
{
	int count = 0;
	DoubleNode<DataType> *p = first->next;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;

}

template<class DataType>
int DoubleLinkList<DataType>::GetLocate(DataType x)
{
	int count = 1;
	DoubleNode<DataType> *p = first->next;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return count;
		}
		else
		{
			p = p->next;
			count++;
		}
	}
	return 0;
}

template<class DataType>
DataType DoubleLinkList<DataType>::GetElement(int i)
{
	DoubleNode<DataType> *p = first->next;
	int j = 1;
	if (i == 0)
		return NULL;
	if (i < 0)
		throw "输入有误";
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p != NULL)
	{
		return p->data;
	}
	else
	{
		return NULL;
	}

}

template<class DataType>
void DoubleLinkList<DataType>::InsertElement(int index, DataType x)
{
	DoubleNode<DataType> *p = first;
	int j = 0;
	if (index < 0 || index == 0)
	{
		throw "输入错误";
	}
	while (p != NULL && j < index-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
	{
		throw "输入有误";
	}
	else
	{
		DoubleNode<DataType> *s = new DoubleNode<DataType>;
		s->data = x;
		s->next = p->next;
		if (p->next != NULL)
		{
			p->next->head = s;
		}
		s->head = p;
		p->next = s;
	}

}

template<class DataType>
DataType DoubleLinkList<DataType>::DeleteElement(int i)
{
	DoubleNode<DataType> *p = first;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p != NULL)
	{
		DoubleNode<DataType> *q = new DoubleNode<DataType>;
		DataType x = p->next->data;
		q = p->next;
		p->next = q->next;
		if (q->next != NULL)
		{
			q->next->head = p;
		}
		delete q;
		return x;
	}
}

template<class DataType>
void DoubleLinkList<DataType>::PrintList()
{
	DoubleNode<DataType> *p = first->next;
	while (p != NULL) 
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void show() 
{
	cout << "===============================" << endl;
}

int main()
{
	int array[] = { 2,3,5,1,7,8,4,10,22,21 };
	DoubleLinkList<int> TestLinkList = DoubleLinkList<int>(10,array);
	TestLinkList.PrintList();
	show();
	cout << "Get Length:" << "  ";
	cout << TestLinkList.GetLength() << endl;
	show();
	cout << "Get Element '1' Locate:" << "  ";
	cout << TestLinkList.GetLocate(1) << endl;
	show();
	cout << "Get Locate '2' Element:" << "  ";
	cout << TestLinkList.GetElement(2) << endl;
	show();
	cout << "Insert Element '32' to Locate '11':" << "  ";
	TestLinkList.InsertElement(11, 31);
	TestLinkList.PrintList();
	show();
	cout << "Delete Locate '11' Element:" << "  ";
	TestLinkList.DeleteElement(11);
	TestLinkList.PrintList();
} 