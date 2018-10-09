// 二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "string.h"
#include "链式栈.h"

//利用二叉链表的二叉树类定义
template <class T>
struct BinTreeNode
{
	T data;
	BinTreeNode *leftChild, *rightChild;
	BinTreeNode()
	{
		leftChild = rightChild = NULL;
	}
	BinTreeNode(T d, BinTreeNode *l=NULL, BinTreeNode *r=NULL)
	{
		data = d;
		leftChild = l;
		rightChild = r;
	}
};
template <class T>
void visit(BinTreeNode <T> *p)
{
	cout<<p->data<<" ";
}

template <class T>
class BinaryTree
{
private:
	BinTreeNode<T> *root;
	T RefValue;
public:
	BinaryTree()
	{
		root = NULL;
	}
	BinaryTree(T value)
	{
		RefValue = value;
		root  = NULL;
	}
	BinaryTree(const BinaryTree &b)
	{
		RefValue = b.RefValue;
		root = NULL;
	}
	~BinaryTree()
	{
		//destory(root);
	}
	bool IsEmpty()
	{
		return root==NULL;
	}
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)
	{
		return  (root == NULL || root == current)? NULL: Parent(root, current);
	}
	BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)
	{
		return (current != NULL)? current->leftChild: NULL;
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T> *current)
	{
		return (current != NULL)? current->rightChild: NULL;
	}
	int Height()
	{
		return Height(root);
	}
	int Size()
	{
		return Size(root);
	}
	BinTreeNode <T>*getRoot() const
	{
		return root;
	}
	void preOrder(void(* visit)(BinTreeNode<T> *p))  //前序遍历
	{
		preOrder(root, visit);
	}
	void inOrder(void(* visit)(BinTreeNode<T> *p));
	void postOrder(void(* visit)(BinTreeNode<T> *p))
	{
		postOrder(root, visit);
	}
	void levelOder(void(* visit)(BinTreeNode<T> *p));
	bool Insert(const T item);
	BinTreeNode<T> *Find(T item)const;
	bool CreateBinaryTreeByArray(T *bArray, int n);
	//bool CreateByArray(BinTreeNode <T> *subTree, T *bArray, int n);
	bool CreateByArray(T *bArray,int index,int n, BinTreeNode <T>*&subTree);

	bool FindAndAncestor(T x);
	bool FindAncestor(BinTreeNode<T> *&subTree, T x);
protected:
	void CreateBinTree(istream &in, BinTreeNode<T> *&subTree);
	bool Insert(BinTreeNode<T> *&subTree, const T &x);
	void destory(BinTreeNode<T> *&subTree);
	bool Find(BinTreeNode<T> *&subTree, const T& x)const;
};
template <class T>
bool BinaryTree<T>::CreateBinaryTreeByArray( T *bArray, int n)
{
	int index=1;
	CreateByArray( bArray, index,n,root);
	return true;
}
template <class T>
bool BinaryTree<T>::CreateByArray(T *bArray,int index,int n, BinTreeNode <T>*&subTree)
{
	if(index <= n && bArray[index-1] != RefValue)
	{
		subTree = new BinTreeNode<T>(bArray[index-1]);
		if(subTree == NULL)
		{
			cerr<<"内存分配错误！"<<endl; exit(-1);
		}
		
		CreateByArray(bArray,2*index,n,subTree->leftChild);
		CreateByArray(bArray,2*index+1,n,subTree->rightChild);
	}
	else
	{
		subTree = NULL;
	}
	return true;
}
template <class T>
bool BinaryTree<T>::FindAndAncestor(T x)
{
	return FindAncestor(root,x);
}
template <class T>
bool BinaryTree<T>::FindAncestor(BinTreeNode<T> *&subTree, T x)
{
	if(subTree == NULL) return false;   //★★★★★★★勿忘结束条件！！！
	if(subTree->data == x)
		return true;
	else if(FindAncestor(subTree->leftChild,x) || FindAncestor(subTree->rightChild, x))
	{
		cout<<subTree->data<<" ";
		return true;
	}
	return false;
}
template <class T>
void BinaryTree<T>::inOrder(void(*visit)(BinTreeNode<T> *p))
{
   LinkStack<BinTreeNode<T> *> S;
   BinTreeNode<T> *p = root;
   do
   {
	   while(p != NULL)
	   {
		   S.push(p);
		   p = p->leftChild;
	   }
	   if(! S.IsEmpty())
	   {
		   S.pop(p);
		   visit(p);
		   p = p->rightChild;
	   }
   }while(p != NULL || !S.IsEmpty());
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *a="ABCDEFGHIJK####";
	BinaryTree <char>bt('#');
	bt.CreateBinaryTreeByArray(a,strlen(a));
	char ch = 'K';
	bt.FindAndAncestor(ch);
	cout<<"中序遍历如下："<<endl;
	bt.inOrder(visit);
	return 0;
}

