#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Á´Ê½Õ».h"

template <class T>
 ostream& operator << (ostream & os, LinkStack<T> &s)
 {
	 LinkNode<T> *p = top;
	 while(p != NULL)
	 {
		 os<<p->data<<" ";
		 p = p->next;
	 }
	 os<<endl;
	 return os;
 }