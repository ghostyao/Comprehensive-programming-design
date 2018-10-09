// Huffman编码译码系统.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//#include "MinHeap.h"
#include "HuffmanTree.h"
#include "AString.h"

/*
1、	实现霍夫曼编码系统,能够对传输报文进行编码并译码
输入：
英文字母、空格、数字、下划线等的出现概率；
多条报文以及编码

输出：
相应的Huffman树，以及各条输入报文的编码以及输入编码的译码结果。
*/
#include <sstream>
#include <string>

const int MAX_CHAR_NUM = 100;
const int CHAR_SORT = 127;//字符最大种类


void stringOper(char *str,int charnum)
{
	while(1)
	{
		int ind = -1;
		AString as(str);
		do
		{
		    cout<<"-----------------------------------------------------------"<<endl;
			cout<<"◎请选择：\n   ***   字符串长度：1\n   ***   字符串拼接：2\n   ***   子串查找：3\n   ***   提取字符串的字符：4\n"<<endl;
			cin >> ind;
		}while(ind != 1 && ind != 2 && ind != 3 && ind != 4 );
		switch(ind)
		{
		case 1:
			{
				cout << "字符串的长度为："<<as.Length()<<endl;
			}break;
		case 2:
			{
				cout<<"*****字符串拼接："<<endl;
				cout<<"◎请输入您要拼接字符的个数："<<endl;
				int num = 0;
				cin >> num;
				cout << "◎请输入拼接字符："<<endl;
				char *temp = new char[num+1];
				for(int i=0 ; i<num ; i++)
					cin >> temp[i];
				temp[num] = '\0';
				AString app(temp);
				as += app;
				cout<<"★★★结果如下：";
				as.output();
				delete []temp;
			}break;
		case 3:
			{
				cout<<"*****子串查找："<<endl;
				cout<<"◎请输入您要查找字符的个数："<<endl;
				int num = 0;
				cin >> num;
				cout << "◎请输入查找字符串："<<endl;
				char *temp = new char[num+1];
				for(int i=0 ; i<num ; i++)
					cin >> temp[i];
				temp[num] = '\0';
				AString sub(temp);
				int m = as.Find(sub);
				cout<<"★★★出现在："<<m<<"位置上"<<endl;
				delete []temp;

			}break;
		case 4:
			{
				cout<<"*****字符提取："<<endl;
				cout<<"◎请输入您要提取第几位的字符："<<endl;
				int pos= 0;
				cin >> pos;
				cout<<"★★★第"<<pos<<"位字符为："<<as[pos]<<endl;
			}break;
		default:cerr<<"error"<<endl;exit(-1);

		}
		cout << endl;
		cout<<"-----------------------------------------------------------"<<endl;
		cout << "◎输入‘#’退出对字符串的操作，仍要继续请输入任意键。"<<endl;
		char ch;
		cin >> ch;
		if(ch == '#') break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"***********************************************************"<<endl;
	cout<<"******    HuffmanCode   and    HUffmanDecode       ********"<<endl;
	cout<<"******        东南大学成成贤学院                   ********"<<endl;
	cout<<"******            姚俊                           ********"<<endl;
	cout<<"***********************************************************"<<endl;
	
	int sortnum = 0, i = 0;
	Item *chars;
	int choose = -1;
	
	cout<<endl;
	
	do
	{
		cout<<"-----------说明：\n";
		cout<<"这是个Huffman编码系统，首先要知道字符的种类，和他们在报文中统计的出现频率。"<<endl;
		cout<<"如果您想直接输入字符和字符对应的频率，请输入数字1\n如果您想通过输入一段报文统计得到字符和字符出现频率，请输入数字2"<<endl;
		cin >> choose;
	}while(choose != 1 && choose != 2);
	
	switch(choose)
	{
	case 1:
		{
			do{
				cout << endl;
				cout<<"-----------------------------------------------------------"<<endl;
				cout<<"◎首先输入字符种类的个数(范围在2~"<<CHAR_SORT<<")："<<endl;
				cin >> sortnum;

			}while(sortnum <= 1 || sortnum > CHAR_SORT);
		
			chars = new Item[sortnum]; 
			cout << endl;
			cout<<"◎依次输入英文字母、空格、数字、下划线及它们的出现概率（保留6位小数），格式如a,3(回车)"<<endl;
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
					cout << "———▲概率要>0的数字,刚才的输入无效，重新输入："<<endl;
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
				cout << "———▲概率要>0的数字,刚才的输入无效，重新输入："<<endl;
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
				cout << "———▲概率要>0的数字,刚才的输入无效，重新输入："<<endl;
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
			cout<<"请输入一段报文：（输入‘#’结束）"<<endl;
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
	//★★★★★★★调节有效位数
	cout.setf(ios::fixed);
	cout.precision(6);

	HuffmanTree huff(chars, sortnum);
	Item *codestr = new Item[sortnum];
	huff.Coder(codestr, sortnum);
	cout << endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"★★★Huffman Tree(广义表表示)："<<endl;
	huff.Output();
	cout<<endl;
	cout<<endl;
	cout<<"★★★编码结果："<<endl;
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
			cout<<"◎编码请输入：1\n◎译码请输入：2\n◎退出请输入：3\n" <<endl;

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
					cout << "●●●编码" << endl;
					cout << "◎请输入一段要译码的报文，以#结束" <<endl;
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
					cout << "★★★编码结果如下："<< endl;
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
						cout<<"———▲警告：在编码过程中有些字符不在编码范围内，故执行了跳过处理▲"<<endl;
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
					cout << "●●●译码" << endl;
					cout<<"◎请输入一段01编码,以'#'结束"<<endl;
					int charnum = 0;
					char char_to_decode[MAX_CHAR_NUM];
					while(charnum < MAX_CHAR_NUM)
					{
						cin >> char_to_decode[charnum];
						
						if(char_to_decode[charnum] == '#')  break;
						/*if(char_to_decode[charnum] != '0' && char_to_decode[charnum] != '1')
						{
							cout << "———▲您输入的'"<< char_to_decode[charnum] <<"'不是‘0’或‘1’，请重新输入：▲"<<endl;
							continue;
						}*/
						charnum ++;
					}
					cout << endl;
					cout << "★★★译码结果如下:" <<endl;
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
                  cout << "◎字符操作请输入：1\n◎返回上一层请输入：2\n" <<endl;
                  cin >> index1;
                   }while(index1 != 1 && index1 !=2);
                  switch(index1)
                  {
				  case 1:
                   {cout<<"●●●对译码结果进行字符串操作："<<endl;
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
	//cout << "特别鸣谢专业测试人员周洁同学。" << endl;
	cout << endl;
	cout<<"***********************************************************"<<endl;
	cout<<"******                                             ********"<<endl;
	cout<<"******             感谢使用！                      ********"<<endl;
	cout<<"******     特别鸣谢专业测试人员周洁同学。          ********"<<endl;
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

