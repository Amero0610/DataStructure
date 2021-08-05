#include <iostream>
using namespace std;
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};
template<class DataType>
class Linklist
{
public:
	Linklist();
	Linklist(DataType a[], int n);  // 头插法
	Linklist(int n, DataType a[]);  // 尾插法
	~Linklist();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int index, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType> *first;

};
template<class DataType>
Linklist<DataType>::Linklist()
{
	first = new Node<DataType>;
	first->next = NULL;
}

template<class DataType>
Linklist<DataType>::Linklist(DataType a[], int n)
{
	first = new Node<DataType>;
	first->next = NULL;
	for (int i = 0; i < n; i++)
	{
		Node<DataType> *p = new Node<DataType>;
		p->data = a[i];
		p->next = first->next;
		first->next = p;
	}
}

template<class DataType>
Linklist<DataType>::Linklist(int n, DataType a[])
{
	first = new Node<DataType>;
	Node<DataType> *r = new Node<DataType>;
	r = first;
	for (int i = 0; i < n; i++)
	{
		Node<DataType> *p = new Node<DataType>;
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

template<class DataType>
Linklist<DataType>::~Linklist()
{
	Node<DataType> *q;
	while (first != NULL)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

template<class DataType>
void Linklist<DataType>::Insert(int index, DataType x)
{
	Node<DataType> *p = first;
	int count = 0;
	while (p != NULL && count < index - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		throw "插入位置有误";
	}
	else
	{
		Node<DataType> *s;
		s = new Node<DataType>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

template<class DataType>
DataType Linklist<DataType>::Get(int i)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		throw "输入位置有误";
	}
	else
	{
		return p->data;
	}
}

template<class DataType>
int Linklist<DataType>::Length()
{
	int count = 0;
	Node<DataType> *p = first->next;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<class DataType>
void Linklist<DataType>::PrintList()
{
	Node<DataType> *p = first->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
DataType Linklist<DataType>::Delete(int i)
{
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)
	{
		throw "删除位置有误";
	}
	else
	{
		Node<DataType> *s = p->next;
		DataType x = s->data;
		p->next = s->next;
		delete s;
		return x;
	}
}

template<class DataType>
int Linklist<DataType>::Locate(DataType x)
{
	Node<DataType> *p = first->next;
	int count = 1;
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

void show()
{
	cout << "================================" << endl;
}
int main()
{
	int array[] = { 3,4,2,1,2,5,6,2,7,20 };
	//Linklist<int> Testlinklist = Linklist<int>(array, 10);
	Linklist<int> Testlinklist = Linklist<int>(10, array);
	cout << "输出单链表" << endl;
	Testlinklist.PrintList();
	show();
	cout << "单链表长度" << endl;
	cout << Testlinklist.Length() << endl;
	show();
	cout << "单链表中第五个元素是" << endl;
	cout << Testlinklist.Get(5) << endl;
	show();
	cout << "单链表中7的位置是" << endl;
	cout << Testlinklist.Locate(7) << endl;
	show();
	cout << "在单链表位置3处插入22" << endl;
	Testlinklist.Insert(11, 22);
	Testlinklist.PrintList();
	show();
	cout << "删除位置为4的元素" << endl;
	Testlinklist.Delete(4);
	Testlinklist.PrintList();
	show();
	cout << "单链表长度" << endl;
	cout << Testlinklist.Length() << endl;
	show();
	return 0;
}