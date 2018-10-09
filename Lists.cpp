// 广义表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <assert.h>
#include <stdlib.h>
#include "链式栈.h"

template <class T>
struct GenListNode
{
   int utype;
   GenListNode<T> *tlink;
   union
   {
	   int ref;
	   T value;
	   GenListNode <T> *hlink;
   }info;
};

template <class T>
struct Items
{
   int utype;
   union
   {
	   int ref;
	   T value;
	   GenListNode<T> *hlink;
   }info;

   Items()
   {
	   utype = 0;
	   info.ref = 0;
   }
   Items(Items<T> &RL)
   {
	   utype = RL.utype;
	   info = RL.info;
   }
};

template <class T>
class GenList
{
private:
	GenListNode <T> *first;
	GenListNode<T> *Copy(GenListNode<T> *Is)
	{		//私有成员，复制一个Is指示的无共享子表的非递归表
		GenListNode <T> *q = NULL;
		if(Is != NULL)
		{
			q = new GenListNode<T>;
			q->utype = Is->utype;
			switch(Is->utype)
			{
			case 0: q->info.ref = Is->info.ref; break;
			case 1: q->info.value = Is->info.value; break;
			case 2: q->info.hlink = Copy(Is->info.hlink); break;
			}
			q->tlink = Copy(Is->tlink);
		}
		return q;
	}
	int Length (GenListNode <T> *Is);
	int Depth(GenListNode <T> *Is);
	bool Equal(GenListNode <T> *s, GenListNode<T> *t);
	void Remove(GenListNode<T> *Is);
	void CreateList(istream &in, GenListNode<T> *&Is);

public:
	GenList()
	{
		first = new GenListNode;
		first->info.ref = 0;
		assert(first != NULL);
	}
	~GenList()
	{
		MakeEmpty();
		delete first;
	}

	bool Head(Items &x) //返回表头元素x
	{
		if(IsEmpty())
			return false;
		else
		{
			Items temp;
			temp.utype = first->tlink->utype;
			temp.info = first->tlink->info;
			x = temp;
			return true;
		}
	}
	bool Tail(GenList<T> &It)  //返回表尾It
	{
	   if(IsEmpty())
		   return false;
	   if(It.IsEmpty())
	   {
		   It.first->utype = 0;
		   It.first->info.ref = 0;
		   It.first->tlink = Copy(first->tlink->tlink);
		   return true;
	   }
	   return false;
	}
	GenListNode<T> *First()  //返回第一个元素
	{
		if(IsEmpty())
			return NULL;
		else 
			return first->tlink;
	}
	GenListNode<T> *Next(GenListNode<T> *elem) //返回表元素elem的直接后继元素
	{
		if(elem->tlink == NULL)
			return NULL;
		else 
			return elem->tlink;
	}
	bool IsEmpty()
	{
		return first->tlink == NULL;
	}
	void MakeEmpty()
	{
	}
	void Copy(const GenList<T> &R)
	{
		R.MakeEmpty();
		first = Copy(R.first);
	}

	int Length();
	int Depth();
	friend istream & operator >> (istream &in, GenList<T> &L);
	int Length2(GenListNode<T> *Is);
	int Depth2(GenListNode<T> *Is);
};

template <class T>
bool Equal(GenListNode <T>*s,GenListNode <T>*t)
{
	//s,t为两个广义表的表头指针
	int x;
	if(s->tlink == NULL && t->tlink == NULL)
		return true;
	else if(s->tlink->utype == t->tlink->utype)
	{
		if(s->tlink->utype == 1)
			x = (s->tlink->info.value == t->tlink->info.value)?1:0;
		else if(s->tlink->utype == 2)
			x=Equal(s->tlink->info.hlink, t->tlink->info.hlink)?1:0;
		if(x == 1)
			return Equal(s->tlink, t->tlink);
	}
	return false;
}

template <class T>
void Devalue(GenListNode <T>* Is, T x)
{
	if(Is->tlink != NULL)
	{
		GenListNode <T>* p = Is->tlink;
		while(p != NULL && (p->utype == 1 && p->info.value == x))
		{
			Is->tlink = p->tlink;
			delete p;
			p = Is->tlink;
		}
		if(p != NULL)
		{
			if(p ->utype == 2)
			{
				Devalue(p->info.hlink, x);
			}
			Devalue(p,x);
		}
	}
}
//广义表的递归算法
//template <class T>
//void GenList<T>::Copy(const GenListNode<T> *R)
//{
//	R.MakeEmpty();
//	first = Copy(R.first);
//}

//template <class T>
//GenListNode<T> *GenList<T>::Copy(GenListNode<T> *Is)
//{
//私有成员，复制一个Is指示的无共享子表的非递归表
//	GenListNode <T> *q = NULL;
//	if(Is != NULL)
//	{
//		q = new GenListNode<T>;
//		q->utype = Is->utype;
//		switch(Is->utype)
//		{
//		case 0: q->info.ref = Is->info.ref; break;
//		case 1: q->info.value = Is->info.value; break;
//		case 2: q->info.hlink = Copy(Is->info.hlink); break;
//		}
//		q->tlink = Copy(Is->tlink);
//	}
//	return q;
//}　　　　　　　　　　　　　

template <class T>
int GenList<T>::Length()
{
	return Length(first);
}
template <class T>
int GenList<T>::Length(GenListNode<T> *Is)
{
	if(Is != NULL)
		return 1+Length(Is->tlink);
	else return 0;
}
template <class T>
int GenList<T>::Length2(GenListNode<T> *Is)
{
	if(Is == NULL)
		return 0;
	GenListNode <T> *p = Is;
	int len=0;
	while(p != NULL)
	{
        len ++;
		p = p->tlink;
	}
	return len;
}
template <class T>
int GenList<T>::Depth()
{
	return Depth(first);
}
template <class T>
int GenList<T>::Depth(GenListNode<T> *Is)
{
	if(Is->tlink == NULL)
		return 1;
	GenListNode<T> *temp = Is->tlink;
	int m=0, n;
	while(temp != NULL)
	{
		if(temp ->utype == 2)
		{
			n = Depth(temp->info.hlink);
			if(m < n) m = n;
		}
		temp = temp->tlink;
	}
	return m+1;
}
template <class T>
struct Child
{
     GenListNode <T> *pre;
	 int depth;
	 Child(GenListNode<T> *m, int d=1 )
	 {
		 pre = m;
		 depth = d;
	 }
};
template <class T>
int GenList<T>::Depth2(GenListNode<T> *Is)
{
	if(Is->tlink == NULL)
	   return 1;
   int depth=0, n=0;
   LinkStack<Child> st;
   Child<T> c(Is->tlink, 1);
   st.push(c);
   GenListNode<T> *p;
   int preDepth;
   while(!st.IsEmpty())
   {
	   st.pop(c);
	   p = c.pre;
	   preDepth += c.depth;
	   if(depth < preDepth)
		   depth = preDepth;
	   if(p->utype == 2)
	   {
		   c.pre = p;
		   c.depth = 1;
            st.push(c);	
	   }
	   else
	   {
		   p = p->tlink;
		   if(p != NULL)
		   {
			   Child <T>c1(p,0);
			   st.push(p);
		   }
	   }

   }
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

