//Name: �B�a��
//Date: 2023/06/06
//Last Update: 2023/06/06
//Problem statement: ��set�Ӧs��name.txt����ơA�åB��X

#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ifstream in("name.txt"); //�}���ɮ�
	set<string> myset; //�ŧiset
	string name; //�ŧiname
	while (getline(in, name)) //Ū���ɮ�
	{
		myset.insert(name); //�Nname�s�Jset
	}
	for (auto s = myset.begin(); s != myset.end(); s++) 
	{
		cout << *s << endl; //��Xset
	}
}