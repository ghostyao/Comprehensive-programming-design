// 多项式（链表实现）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//using namespace std;
#include <iostream>
#include "多项式（链表实现）.h"

Polynomial Polynomial ::operator +(const Polynomial &p) const
{
	Polynomial sum;
	if(p.IsEmpty())  
		return *this;
	else if(IsEmpty())
		return p;

	Term *p1 = first->next ;
	Term *p2 = p.first->next;
	int index=0; 
	while(p2 != NULL && p1 != NULL)
	{
		if(p1->exp < p2->exp)
		{
			sum.Insert(index, p1->exp, p1->coef);
			index++;
			p1 = p1->next;
		}
		else if(p1->exp == p2->exp)
		{
			sum.Insert(index, p1->exp,p1->coef+p2->coef);
			index++;
			p1 = p1->next;
			p2 = p2->next;
		}
		else 
		{
			sum.Insert(index,p2->exp,p2->coef);
			index++;
			p2 = p2->next;
		}
	}
	if(p1 != NULL)
	{
		while(p1 != NULL)
		{
			sum.Insert(index,p1->exp,p1->coef);
			index++;
			p1 = p1->next;
		}
	}
	else if(p2 != NULL)
	{
		while(p2 != NULL)
		{
			sum.Insert(index,p2->exp,p2->coef);
			index++;
			p2 = p2->next;
		}
	}
	return sum;
}

Polynomial Polynomial::operator *(const Polynomial &p) const
{
	Polynomial result;
	if(IsEmpty() || p.IsEmpty())
		return result;

	Term *p1 = first->next;
	Term *p2 = p.first->next;
	while(p1 != NULL)
	{
		int exp = p1->exp;
		float coef = p1->coef;
		Polynomial multi;
		int index = 0;
		p2 = p.first->next;
		while(p2 != NULL)
		{
			multi.Insert(index,exp+p2->exp,coef*p2->coef);
			index++;
			p2 = p2->next;
		}
		result = result + multi;
		p1 = p1->next;
	}
	return result;
}

Polynomial Polynomial ::Inverse()
{
	Term *pr =first->next;
	while(pr != NULL)
	{
		pr->coef = -pr->coef;
		pr = pr->next;
	}
	return *this;
}

Polynomial Polynomial ::operator -(const Polynomial &p) const
{
	Polynomial temp = p;
	temp = temp.Inverse();	
	return *this+temp;
}

ostream & operator << (ostream &out, const Polynomial &p)
{
	Term *pr = p.first->next;
	bool firstTime = true;
	while(pr != NULL)
	{
		if(pr->coef < 0)
			out<<'-';
		else if(pr->coef > 0)
		{
			if(firstTime)
				firstTime = false;
			else
				out<<'+';
		}
		out<<pr->coef<<"X^"<<pr->exp;
		pr = pr->next;
	}
	out<<endl;
	return out;
}
istream &operator >>(istream &in, Polynomial &p)
{
	p.MakeEmpty();
	int num;
	while(1)
	{
		cout<<"请输入项数，再依次输入指数和系数"<<endl;
		cin>>num;
		if(num > 0) break;
	}
	for(int i =0;i<num; i++)
	{
		int exp;
		float coef;
		cout<<"指数：";
		cin>>exp;
		cout<<"系数：";
		cin>>coef;
		p.Insert(i,exp,coef);
	}
 return in;
}
int _tmain(int argc, _TCHAR* argv[])
{

	 Polynomial p1,p2;
	 cout<<"input p1"<<endl;
	 cin>>p1;
	 cout<<p1;
	 cout<<"input p2"<<endl;
	 cin>>p2;
	 cout<<p2;
	 cout<<"p1+p2"<<endl;
	 cout<<p1+p2;
//	 cout<<"p1-p2"<<endl;
//	cout<<p1-p2;
//    cout<<"p1*p2"<<endl;
//	 cout<<p1*p2;
	 cout<<"p1 = where x=2"<<endl;
	 cout<<p1.value(2)<<endl;


     
 
	return 0;
}

