//Name: ¼B®a¦¨
//Date: 2023/05/03
//Last Update: 2023/05/03
//Problem statement: Longest reverse word

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, int> mymap; //create a map to store the words
	string s; //create a string to store the input
	int maxLength = 0; //create a variable to store the max length
	string res = ""; //create a string to store the result
	while (cin >> s)
	{
		string reverseS = s; //create a string to store the reverse word
		reverse(reverseS.begin(), reverseS.end()); //reverse the word
		if (mymap.find(reverseS) != mymap.end()) //if the reverse word is in the map
		{
			if (s.length() > maxLength) //if the length of the word is longer than the max length
			{
				maxLength = s.length(); //update the max length
				res = reverseS; //update the result
			}
		}
		else
		{
			mymap[s] = 1; //add the word to the map
		}
	}
	cout << res << endl; //print the result
}