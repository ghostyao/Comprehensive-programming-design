// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "���ȼ����С�����.h"
#include "˫�˶��С�����.h"
#include "˫�˶��С�����.h"
#include "ѭ�����С�˳�����.h"
#include "��ʽ����.h"



int _tmain(int argc, _TCHAR* argv[])
{
	int x;
//	SeqQueue <int>s(10);
//	s.EnQueue(1);
//	s.EnQueue(2);
//	cout<<"Size:"<<s.Size()<<endl;
//	cout<<"IsFull:"<<(int)s.IsFull()<<endl;
//	s.GetFront(x);
//	cout<<"GetFront"<<x<<endl;
//   
//   s.DeQueue(x);
//   cout<<x<<endl;
//   s.DeQueue(x);
//   cout<<x<<endl;
//   cout<<"Size:"<<s.Size()<<endl;
//   cout<<"IsEmpty()"<<(int)s.IsEmpty()<<endl;
//cout<<endl;
//	cout<<endl;
//	cout<<endl;
//   LinkQueue<int > l;
//   l.EnQueue(1);
//   l.EnQueue(2);
//   l.EnQueue(3);
//   cout<<"Size:"<<l.Size()<<endl;
//	
//	l.GetFront(x);
//	cout<<"GetFront:"<<x<<endl;
//   
//   l.DeQueue(x);
//   cout<<x<<endl;
//   l.DeQueue(x);
//   cout<<x<<endl;
//   cout<<"Size:"<<l.Size()<<endl;
//   cout<<"IsEmpty()"<<(int)l.IsEmpty()<<endl;

PQueue<int> p(3);
p.Insert(2);
p.GetFront(x);
cout<<"Front:"<<x<<endl;
p.Insert(4);
p.GetFront(x);
cout<<"Front:"<<x<<endl;
p.Insert(1);
p.GetFront(x);
cout<<"Front:"<<x<<endl;
cout<<"IsFull:"<<(int)p.IsFull()<<endl;
p.RemoveMin(x);
cout<<"RemoveMin:"<<x<<endl;
cout<<"Size:"<<p.Size()<<endl;
p.RemoveMin(x);
cout<<"RemoveMin:"<<x<<endl;
p.RemoveMin(x);
cout<<"RemoveMin:"<<x<<endl;
cout<<"IsEmpty:"<<(int)p.IsEmpty()<<endl;
	return 0;
}