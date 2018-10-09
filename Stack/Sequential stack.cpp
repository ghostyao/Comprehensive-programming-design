#include "stdafx.h"
#include <iostream>
using namespace std;
#include "À≥–Ú’ª.h"


template <class T>
ostream &operator << (ostream &os, SeqStack<T> &s)
{
	if(!s.IsEmpty())
	{
		os << "The Stack has "<<s.Size()<<" elements:"<<endl;
		for(int i=0; i<s.Size(); i++)
			os << s.elements[i]<< " ";
		os<<endl;
	}
	return os;
}