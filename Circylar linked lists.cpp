#include "stdafx.h"
//using namespace std;
#include <iostream>
#include "循环链表.h"


CircLinkNode *CircList::Locate(int i)   //搜索第i个元素的地址
{
	if(i<0 || i>len) 
	{
		cerr<<"下标越界！"<<endl;
		return NULL;
	}
	if(first->next == first || i==0) return first;
	CircLinkNode *p = first;
	for(int m=1;m<=i;m++)
		p = p->next;
	return p;
}

int CircList::getData(int i)  //获得第i个结点的值
{
	if(first->next == first) 
	{
		cerr<<"链表为空！"<<endl;
		return 0;
	}
	CircLinkNode *p = Locate(i);
	if(p != NULL) 
		return p->context;
	else
		return 0;
}
bool CircList::setData(int i,int x)
{
   if(first->next == first) 
	{
		cerr<<"链表为空！"<<endl;
		return false;
	}
	CircLinkNode *p = Locate(i);
	if(p != NULL) 
	{
		p->context = x;
		return true;
	}
	else
		return false;
}

int CircList::Search(int x)
{
	if(first->next == first) return 0;
	CircLinkNode *p = first->next;
	int i = 1;
	while(p != first)
	{
		if(p->context == x)
			return i;
		p = p->next;
		i++;
	}
	return 0;
}
bool CircList::Insert(int i,int x)
{
	CircLinkNode *newNode = new CircLinkNode(x);
	if(newNode == NULL)
	{
		cerr<<"存储分配错误！"<<endl;
		return false;
	}
	CircLinkNode *p = Locate(i);
	if(p == NULL)   
		return false;
	newNode->next = p->next;
	p->next = newNode;
	if(newNode->next == first)
		last = newNode;
	len ++;
	return true;
}
bool CircList::Remove(int i,int &x)
{
	if(i<=0 || i>len) 
		return false;
	if(first->next == first)
		return false;
	CircLinkNode *p = Locate(i-1);
	if(p == NULL) 
		return false;
	CircLinkNode *q = p->next;
	p->next = q->next;
	if(p->next == first)    last = p;
	x = q->context;
	delete q;
	len --;
	return true;
}

void CircList::input()
{
	int m = 0;
	while(1)
	{
		cout<<"请输入表项个数："<<endl;
		cin>>m;
		if(m > 0) break;
	}
    int x;
	cout<<"请依次输入各个表项值："<<endl;
	for(int i=0; i<m; i++)
	{
		cin>>x;
		Insert(i,x);
	}
}
void CircList::output()
{
	if(first->next != first)
	{
		cout<<"链表如下："<<endl;
		CircLinkNode *p = first->next;
		while(p != first)
		{
            cout<<p->context;
			p = p->next;
		}
	}	
	cout<<endl;
}
CircList &CircList::operator = (const CircList &c)
{
	MakeEmpty();
	first->next = last->next = first;
	len = c.len;
	if(c.len != 0)
	{
		CircLinkNode *p = first;
		CircLinkNode *q = c.first->next;
		while(q != c.first)
		{
			p = new CircLinkNode(q->context);
			last->next = p;
			p->next = first;
			last = p;
			q = q->next;
		}
	}
	return *this;
}