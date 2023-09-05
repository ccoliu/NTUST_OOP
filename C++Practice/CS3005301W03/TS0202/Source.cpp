//Name:¼B®a¦¨
//Date: 2022/3/8
//Last Update: 2022/3/8
//Problem statement:file executing.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void getHighScores(vector<string> names, vector<int> scores) 
{
	for (int i = 0; i < scores.size()-1; i++) //sort all the datas into decreasing form.
	{
		for (int j = 0; j < scores.size() - i - 1; j++)
		{
			if (scores[j] < scores[j + 1]) 
			{
				int temp1 = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp1;
				string temp2 = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp2;
			}
		}
	}
	for (int k = 0; k < 3; k++)	//only output first 3 datas.
	{
		cout << names[k] << endl << scores[k] << endl;
	}
}

int main()
{
	ifstream in;
	in.open("scores.txt");
	vector<string> names;
	vector<int> scores;
	string name;
	int score;
	while (in >> name >> score) //input all the datas from the file.
	{
		names.push_back(name);
		scores.push_back(score);
	}
	getHighScores(names, scores);
}