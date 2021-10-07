#include<iostream>
using namespace std;
template<class DataType>
struct BTNode
{
	DataType data;
	BTNode<DataType> *lchild, *rchild;
};
template<class DataType>
class BTree
{
public:
	BTree() { root = Create(root); }
	~BTree() { Release(root); }
	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }

private:
	BTNode<DataType> *root;
	BTNode<DataType> *Create(BTNode<DataType> *bt);
	void Release(BTNode<DataType> *bt);
	void PreOrder(BTNode<DataType> *bt);
	void InOrder(BTNode<DataType> *bt);
	void PostOrder(BTNode<DataType> *bt);
};

template<class DataType>
BTNode<DataType>* BTree<DataType>::Create(BTNode<DataType>* bt)
{
	int ch;
	cin >> ch;
	if (ch ==0)
	{
		bt = NULL;
	}
	else
	{
		bt = new BTNode<DataType>();
		bt->data = ch;
		cout << "Please Input" << bt->data << "left:" << endl;
		bt->lchild = Create(bt->lchild);
		cout << "Please Input" << bt->data << "right:" << endl;
		bt->rchild = Create(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BTree<DataType>::Release(BTNode<DataType>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

template<class DataType>
void BTree<DataType>::PreOrder(BTNode<DataType>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	else
	{
		cout << bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

template<class DataType>
void BTree<DataType>::InOrder(BTNode<DataType>* bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		cout << bt->data;
		InOrder(bt->rchild);
	}
}

template<class DataType>
void BTree<DataType>::PostOrder(BTNode<DataType>* bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data;
	}
}
int main()
{
	BTree<int> mytree = BTree<int>();
	cout << "PreOrder" << endl;
	mytree.PreOrder();
	cout << endl;
	cout << "InOrder" << endl;
	mytree.InOrder();
	cout << endl;
	cout << "PostOrder" << endl;
	mytree.PostOrder();
	return 0;
}