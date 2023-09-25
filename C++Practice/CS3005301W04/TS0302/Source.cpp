//Name:¼B®a¦¨
//Date: 2022/3/15
//Last Update: 2022/3/15
//Problem statement: Text-based histogram

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in;
	ofstream out("grades.Output");
	in.open("grade.txt");
	int scores[6];
	int score;
	int m = 0;
	string s = "";
	while (getline(in,s)) //read file line by line.
	{
		for (int j = 0; j < 6; j++)
		{
			scores[j] = 0; //the program start with a clean array (no data).
		}
		for (int len = 0; len < s.length(); len++)
		{
			if (s[len] != ' ') //datas are seperated with a space, if the current char is the space, we add the data into array.
			{
				scores[s[len] - '0']++;
			}
		}
		for (int i = 0; i < 6; i++) //output the result into the file.
		{
			out << scores[i] << " grade(s) of " << i << endl;
		}
	}
}