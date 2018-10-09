// 栈 Stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "顺序栈.h"
#include "链式栈.h"

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

