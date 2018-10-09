// 双向链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//using namespace std;
#include <iostream>
#include "双向链表.h"


DblNode *DblList::Locate(int i, int d)
{
	if(i>len || i<0) return NULL;
	if(i ==  0) return first;
	DblNode *p = first;
	if(d == 0)
	{
		int j;
		for( j = 1; j <= i; j++)
		{
			p = p->lLink;
			if(p == first) break;
		}
		if( j<=i ) return NULL;
		else return p;
	}
   if(d == 1)
	{
		int j;
		for(j = 1; j <= i; j++)
		{
			p = p->rLink;
			if(p == first) break;
		}
		if( j<=i ) return NULL;
		else return p;
	}
   return NULL;
}

int DblList::GetData(int i,int d)
{
	DblNode *p = Locate(i,d);
	if(p == NULL) 
	{
		cerr<<"越界或者出错"<<endl;
		exit(-1);
	}
	else
		return p->data;
}

void DblList::SetData(int i,const int &x,int d)
{
    DblNode *p = Locate(i,d);
	if(p == NULL) 
	{
		cerr<<"越界或者出错"<<endl;
		exit(-1);
	}
	else
		p->data = x;
}

int DblList::Search(int x,int d)
{
	if(first->lLink == first)
	{
		cerr<<"表空"<<endl;
		return 0;
	}
    int i=1;
	DblNode *p;
	if(d == 0)
	{
		p = first->lLink;
		while(p != first)
		{
			if(p->data == x) return i;
			p = p->lLink;
			i++;
		}
	}
	else if(d == 1)
	{
		p = first->rLink;
		while(p != first)
		{
			if(p->data == x) return i;
			p = p->rLink;
			i++;
		}
	}
	return 0;
}

bool DblList::Insert(int i, int x, int d)
{
	DblNode *p ;
	DblNode *newNode = new DblNode(x);
	if(newNode == NULL)
		return false;
	if(d == 0)
	{
        p = Locate(i,d);
		if(p == NULL)  
			return false;
		newNode->rLink = p;
		newNode ->lLink = p->lLink;
		p->lLink->rLink = newNode;
		p->lLink = newNode;
		len ++;
	}
	else if(d ==1)
	{
		p = Locate(i,d);
		if(p == NULL)  
			return false;
		newNode->rLink = p->rLink;
		newNode ->lLink = p;
		p->rLink= newNode;
		newNode->rLink->lLink = newNode;
		len ++;
	
	}
		return true;
}

bool DblList::Remove(int i, int &x, int d)
{
	if(i>len || i<=0) return false;
	DblNode *p = Locate(i,d);
	if(p == NULL)  return false;
	x = p->data;
	p->lLink->rLink = p->rLink;
	p->rLink->lLink = p->lLink;
	delete p;
	p = NULL;
	len --;
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	DblList d;
	for(int i=0; i<10;i++)
	{
		d.Insert(i,i,1);
	}
	d.output(1);
	d.output(0);
	int x;
	cout<<"向右删除第二个"<<endl;
	d.Remove(2,x,1);
	cout<<x<<endl;
	d.output(1);
	cout<<"向左删除第三个"<<endl;
    d.Remove(3,x,0);
	cout<<x<<endl;
	d.output(1);
	cout<<"向左查找x=5"<<endl;
	cout<<d.Search(5,0)<<endl;
	cout<<"表长"<<endl;
	cout<<d.Length()<<endl;
	return 0;
}

