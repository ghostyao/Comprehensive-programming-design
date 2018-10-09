#include "stdafx.h"
//using namespace std;
#include <iostream>
#include "ѭ������.h"


CircLinkNode *CircList::Locate(int i)   //������i��Ԫ�صĵ�ַ
{
	if(i<0 || i>len) 
	{
		cerr<<"�±�Խ�磡"<<endl;
		return NULL;
	}
	if(first->next == first || i==0) return first;
	CircLinkNode *p = first;
	for(int m=1;m<=i;m++)
		p = p->next;
	return p;
}

int CircList::getData(int i)  //��õ�i������ֵ
{
	if(first->next == first) 
	{
		cerr<<"����Ϊ�գ�"<<endl;
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
		cerr<<"����Ϊ�գ�"<<endl;
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
		cerr<<"�洢�������"<<endl;
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
		cout<<"��������������"<<endl;
		cin>>m;
		if(m > 0) break;
	}
    int x;
	cout<<"�����������������ֵ��"<<endl;
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
		cout<<"�������£�"<<endl;
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