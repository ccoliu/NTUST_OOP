//Author:¼B®a¦¨
//Date:2023/4/13
//Last Update:2023/4/13
//Problem statement:Calculate Levenshtein Distance

#include <iostream>
#include <string>
using namespace std;

int LevenshteinDistance(string a, string b) //Calculate Levenshtein Distance
{
	int lenA = a.length(); //length of string a
	int lenB = b.length(); //length of string b
	int **arr = new int*[lenB + 1]; //create a 2D array
	for (int i = 0; i <= lenB; i++)
	{
		arr[i] = new int[lenA + 1]; //create a 1D array
	}
	for (int i = 0; i <= lenB; i++)
	{
		for (int j = 0; j <= lenA; j++)
		{
			arr[i][j] = 0; //initialize the array
		}
	}
	for (int i = 0; i <= lenB; i++)
	{
		arr[i][0] = i; //initialize the first column to i
	}

	for (int i = 0; i <= lenA; i++)
	{
		arr[0][i] = i; //initialize the first row to i
	}
	int cost = 0; //cost of replace
	for (int i = 1; i <= lenB; i++)				 
	{
		for (int j = 1; j <= lenA; j++)
		{
			if (a[j - 1] == b[i - 1])
			{
				cost = 0; //if the character is the same, cost is 0
			}
			else cost = 1; //if the character is different, cost is 1
			int deleteCost = arr[i - 1][j] + 1; //delete the character in string a
			int insertCost = arr[i][j - 1] + 1; //insert the character in string b
			int replaceCost = arr[i - 1][j - 1] + cost; //replace the character in string a with the character in string b
			arr[i][j] = min(min(deleteCost, insertCost), replaceCost); //find the minimum cost
		}
	}
	return arr[lenB][lenA]; //return the Levenshtein Distance
}

int main()
{
	string a, b; //two strings
	while (getline(cin,a)) //read the string a
	{
		getline(cin, b); //read the string b
		cout << LevenshteinDistance(a, b) << endl; //print the Levenshtein Distance
	}
}
