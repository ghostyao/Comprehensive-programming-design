// ջ Stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "˳��ջ.h"
#include "��ʽջ.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	LinkStack<int> ls;
	ls.push(1);
	ls.pop(x);
	cout<<x<<endl;
	SeqStack<int> ss(10);
	ss.push(1);
	ss.pop(x);
	cout<<x<<endl;
	return 0;
}

