// Huffman��������ϵͳ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//#include "MinHeap.h"
#include "HuffmanTree.h"
#include "AString.h"

/*
1��	ʵ�ֻ���������ϵͳ,�ܹ��Դ��䱨�Ľ��б��벢����
���룺
Ӣ����ĸ���ո����֡��»��ߵȵĳ��ָ��ʣ�
���������Լ�����

�����
��Ӧ��Huffman�����Լ��������뱨�ĵı����Լ�����������������
*/
#include <sstream>
#include <string>

const int MAX_CHAR_NUM = 100;
const int CHAR_SORT = 127;//�ַ��������


void stringOper(char *str,int charnum)
{
	while(1)
	{
		int ind = -1;
		AString as(str);
		do
		{
		    cout<<"-----------------------------------------------------------"<<endl;
			cout<<"����ѡ��\n   ***   �ַ������ȣ�1\n   ***   �ַ���ƴ�ӣ�2\n   ***   �Ӵ����ң�3\n   ***   ��ȡ�ַ������ַ���4\n"<<endl;
			cin >> ind;
		}while(ind != 1 && ind != 2 && ind != 3 && ind != 4 );
		switch(ind)
		{
		case 1:
			{
				cout << "�ַ����ĳ���Ϊ��"<<as.Length()<<endl;
			}break;
		case 2:
			{
				cout<<"*****�ַ���ƴ�ӣ�"<<endl;
				cout<<"����������Ҫƴ���ַ��ĸ�����"<<endl;
				int num = 0;
				cin >> num;
				cout << "��������ƴ���ַ���"<<endl;
				char *temp = new char[num+1];
				for(int i=0 ; i<num ; i++)
					cin >> temp[i];
				temp[num] = '\0';
				AString app(temp);
				as += app;
				cout<<"���������£�";
				as.output();
				delete []temp;
			}break;
		case 3:
			{
				cout<<"*****�Ӵ����ң�"<<endl;
				cout<<"����������Ҫ�����ַ��ĸ�����"<<endl;
				int num = 0;
				cin >> num;
				cout << "������������ַ�����"<<endl;
				char *temp = new char[num+1];
				for(int i=0 ; i<num ; i++)
					cin >> temp[i];
				temp[num] = '\0';
				AString sub(temp);
				int m = as.Find(sub);
				cout<<"��������ڣ�"<<m<<"λ����"<<endl;
				delete []temp;

			}break;
		case 4:
			{
				cout<<"*****�ַ���ȡ��"<<endl;
				cout<<"����������Ҫ��ȡ�ڼ�λ���ַ���"<<endl;
				int pos= 0;
				cin >> pos;
				cout<<"�����"<<pos<<"λ�ַ�Ϊ��"<<as[pos]<<endl;
			}break;
		default:cerr<<"error"<<endl;exit(-1);

		}
		cout << endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout << "�����롮#���˳����ַ����Ĳ�������Ҫ�����������������"<<endl;
		char ch;
		cin >> ch;
		if(ch == '#') break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"***********************************************************"<<endl;
	cout<<"******    HuffmanCode   and    HUffmanDecode       ********"<<endl;
	cout<<"******        ���ϴ�ѧ�ɳ���ѧԺ                   ********"<<endl;
	cout<<"******            Ҧ��                           ********"<<endl;
	cout<<"***********************************************************"<<endl;
	
	int sortnum = 0, i = 0;
	Item *chars;
	int choose = -1;
	
	cout<<endl;
	
	do
	{
		cout<<"-----------˵����\n";
		cout<<"���Ǹ�Huffman����ϵͳ������Ҫ֪���ַ������࣬�������ڱ�����ͳ�Ƶĳ���Ƶ�ʡ�"<<endl;
		cout<<"�������ֱ�������ַ����ַ���Ӧ��Ƶ�ʣ�����������1\n�������ͨ������һ�α���ͳ�Ƶõ��ַ����ַ�����Ƶ�ʣ�����������2"<<endl;
		cin >> choose;
	}while(choose != 1 && choose != 2);
	
	switch(choose)
	{
	case 1:
		{
			do{
				cout << endl;
				cout<<"-----------------------------------------------------------"<<endl;
				cout<<"�����������ַ�����ĸ���(��Χ��2~"<<CHAR_SORT<<")��"<<endl;
				cin >> sortnum;

			}while(sortnum <= 1 || sortnum > CHAR_SORT);
		
			chars = new Item[sortnum]; 
			cout << endl;
			cout<<"����������Ӣ����ĸ���ո����֡��»��߼����ǵĳ��ָ��ʣ�����6λС��������ʽ��a,3(�س�)"<<endl;
			//char temp[3];
			char str[100];
			double pro=1;
			cin.getline(str,100);

			for(i=0; i<sortnum; i ++)
			{
				//cin >> chars[i].ch ;
				//cin >> chars[i].probability;
				cin.getline(str,100);
				chars[i].ch = str[0];
				istringstream ss(str+1);
				char c;
				ss >> c;
				if (!(ss >> chars[i].probability) || chars[i].probability <=0)
				{
					cout << "������������Ҫ>0������,�ղŵ�������Ч���������룺"<<endl;
					i --;
				}
				else 
				{
					cout << "               ok (*^__^*) ok" << endl;
				}
				//cout << chars[i - 1].probability << endl;
				/*
				cin.getline(str,100);
				istringstream ss(str);
				ss >> chars[i].ch;
				char c;
				ss >> c;
				if (!(ss >> chars[i].probability) || chars[i].probability <=0)
				{
				cout << "������������Ҫ>0������,�ղŵ�������Ч���������룺"<<endl;
				i --;
				}
				else 
				{
				cout << "               ok (*^__^*) ok" << endl;
				}
				//cout << chars[i - 1].probability << endl;
				*/


				/*
				if(i>=1)
				{
				istringstream ss(str);
				ss >> chars[i-1].ch;
				char c;
				ss >> ',';
				//chars[i-1].ch = str[0];
				if (!(ss >> chars[i-1].probability) || chars[i-1].probability <=0){
				//chars[i-1].probability = pro;
				//if(pro <=0 || !(str[2]>='0'&& str[2]<='9') || str[2] != '.')
				//{
				cout << "������������Ҫ>0������,�ղŵ�������Ч���������룺"<<endl;
				i --;
				}
				else 
				{
				//cout<<"pro="<<pro<<endl;
				cout << "               ok (*^__^*) ok" << endl;
				}
				}
				*/
			}
		}break;
	case 2:
		{
			cout<<"������һ�α��ģ������롮#��������"<<endl;
		    int HashTable[CHAR_SORT];
			int i;
			for(i=0; i<CHAR_SORT; i++)
				HashTable[i] = 0;
			char ch;
			cin >> ch;
			int hashnum = 0;
			while(ch != '#')
			{
				hashnum = (int)ch; 
				HashTable[hashnum] ++;
				if(HashTable[hashnum] == 1)
					sortnum ++;
				cin >> ch;
			}
			chars = new Item[sortnum];
			int m = 0;
            for(i=0; i <CHAR_SORT; i++)
				if(HashTable[i] > 0)
				{
					chars[m].ch = (char)(i);
					chars[m].probability = HashTable[i];
					m ++;
				}
		}break;
	}
	//�������������Чλ��
	cout.setf(ios::fixed);
	cout.precision(6);

	HuffmanTree huff(chars, sortnum);
	Item *codestr = new Item[sortnum];
	huff.Coder(codestr, sortnum);
	cout << endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"����Huffman Tree(������ʾ)��"<<endl;
	huff.Output();
	cout<<endl;
	cout<<endl;
	cout<<"�����������"<<endl;
	for(i=0; i<sortnum; i++)
	{
		cout << codestr[i].ch<< "->"  ;
		for(int j=0; j<codestr[i].codelen; j++)
			cout << codestr[i].code[j];
		cout << endl;
	}

	while(1)
	{
		int index = 0;
		do{
			cout<<"-----------------------------------------------------------"<<endl;
			cout << endl;
			cout<<"����������룺1\n�����������룺2\n���˳������룺3\n" <<endl;

			cin >> index;
		}while(index != 1 && index != 2 && index != 3);

		if(index == 3)
			break;
		else
		{
			switch(index)
			{
			case 1:
				{
					cout << endl;
					cout << "-----------------------------------------------------------"<<endl;
					cout << endl;
					cout << "�������" << endl;
					cout << "��������һ��Ҫ����ı��ģ���#����" <<endl;
					int charnum = 0;
					char char_to_code[MAX_CHAR_NUM];
					while(charnum < MAX_CHAR_NUM)
					{
						cin >> char_to_code[charnum];
						if(char_to_code[charnum] == '#')  break;
						charnum ++;
					}
					bool find = false, hasInvalid = false;
					cout << endl;
					cout << "������������£�"<< endl;
					for(i = 0; i < charnum; i++)
					{
						int m = 0;
						for(m=0; m < sortnum; m++)
						{
							if(char_to_code[i] == codestr[m].ch)
							{ 	find = true;break;}
						}
						if( !find ) { hasInvalid = true;continue;}
						for(int k=0; k<codestr[m].codelen ; k++)
							cout << codestr[m].code[k];
					}
					if(hasInvalid)
					{
						cout<< endl;
						cout<<"�����������棺�ڱ����������Щ�ַ����ڱ��뷶Χ�ڣ���ִ�������������"<<endl;
					}
					cout <<endl;
					cout<<"-----------------------------------------------------------"<<endl;
					cout << endl;                  
				}break;
			case 2:
				{
					cout << endl;
					cout<<"-----------------------------------------------------------"<<endl;
					cout << endl;
					cout << "��������" << endl;
					cout<<"��������һ��01����,��'#'����"<<endl;
					int charnum = 0;
					char char_to_decode[MAX_CHAR_NUM];
					while(charnum < MAX_CHAR_NUM)
					{
						cin >> char_to_decode[charnum];
						
						if(char_to_decode[charnum] == '#')  break;
						/*if(char_to_decode[charnum] != '0' && char_to_decode[charnum] != '1')
						{
							cout << "���������������'"<< char_to_decode[charnum] <<"'���ǡ�0����1�������������룺��"<<endl;
							continue;
						}*/
						charnum ++;
					}
					cout << endl;
					cout << "��������������:" <<endl;
					char char_decoded[MAX_CHAR_NUM];
					int decodednum = 0;
					huff.Decoder(char_to_decode, charnum, char_decoded,MAX_CHAR_NUM ,decodednum);
                  char_decoded[decodednum] = '\0';
					for(int i=0;i<decodednum; i++)
					{
						cout << char_decoded[i];
					}
					cout << endl;
                  cout << endl;
				  cout<<"-----------------------------------------------------------"<<endl;
				  cout << endl;
				  int index1 = -1;
                  do
                  {
                  cout << "���ַ����������룺1\n�򷵻���һ�������룺2\n" <<endl;
                  cin >> index1;
                   }while(index1 != 1 && index1 !=2);
                  switch(index1)
                  {
				  case 1:
                   {cout<<"����������������ַ���������"<<endl;
					  stringOper(char_decoded,decodednum);break;
                   }
				  case 2:
					  break;
				  default:cerr<<"error!"<<endl;
                }
				}break;
			default: cerr <<"error"<<endl; break;
			}
		}
	}
	//cout << "�ر���лרҵ������Ա�ܽ�ͬѧ��" << endl;
	cout << endl;
	cout<<"***********************************************************"<<endl;
	cout<<"******                                             ********"<<endl;
	cout<<"******             ��лʹ�ã�                      ********"<<endl;
	cout<<"******     �ر���лרҵ������Ա�ܽ�ͬѧ��          ********"<<endl;
	cout<<"******                                             ********"<<endl;
	cout<<"***********************************************************"<<endl;

delete []chars;

//char *str = "abacabvfhecbjdskbuewighufew";
//char *pat = "vfh";
//AString as(str);
//AString pat1(pat);
//cout<<"substring:"<<as.Find(pat1)<<endl;
//cout<<"length:"<<as.Length()<<endl;
//cout<<"+=:";
//as+=pat1;
//as.output();

 cout<<"       .-. __ _ .-."<<endl;
 cout<<"       |  `  / \  |"<<endl;
 cout<<"       /     \'.()--\\"<<endl;
 cout<<"      |         '._/"<<endl;
 cout<<"     _| O   _   O |_"<<endl;
 cout<<"      =\    '-'    /="<<endl;
 cout<<"       '-._____.-'"<<endl;
 cout<<"       /`/\\___/\\`\\"<<endl;
 cout<<"      /\\/o     o\\/\\"<<endl;
 cout<<"     (_|         |_)"<<endl;
 cout<<"       |____,____|"<<endl;
 cout<<"       (____|____)"<<endl;
	return 0;
}

