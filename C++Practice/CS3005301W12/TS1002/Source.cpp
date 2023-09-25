//Name: ¼B®a¦¨
//Date: 2023/5/10
//Last Update: 2023/5/10
//Problem statement: Demonstating word game

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


//using BFS to check if the word is valid
bool checkValid(char board[4][4], int y, int x, string str,int log[4][4])
{
	if (y < 0 || x < 0 || y > 3 || x > 3 || log[y][x]) return false; //check if the position is valid
	if (str.length() == 0) return true; //if the word is empty, return true
	if (str[0] == board[y][x]) //if the letter is the same as the letter in the board
	{
		int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; //setting up direction
		log[y][x] = 1; //record the letter we have used
		str.erase(0, 1); //erase the letter we have used
		for (int i = 0; i < 8; i++) //get through the directions
		{
			if (checkValid(board, y + dir[i][0], x + dir[i][1], str, log)) return true; //do recursion to check if the word is valid
		}
	}
	return false; //return false if the word is not valid
}

bool check(char board[4][4], string s) //check if the word is valid
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[0] == board[i][j]) //if we found the first letter of the word
			{
				int log[4][4] = { 0 }; //setting up log to record the letter we have used
				if (checkValid(board, i, j, s, log)) //check if the word is valid
				{
					return true; //return true if the word is valid
				}
			}
		}
	}
	return false; //return false if the word is not valid
}

int main()
{
	char wordGame[4][4]; //setting up word game
	while (cin >> wordGame[0][0] >> wordGame[0][1] >> wordGame[0][2] >> wordGame[0][3]) //while loop to check if the input is valid
	{
		for (int i = 1; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> wordGame[i][j]; //input the word game
			}
		}
		ifstream in("words.txt"); //open the file that stores the words
		string s; //setting up string s
		while (in >> s) //while loop to check if the input is valid
		{
			if (check(wordGame, s)) //check if the word is valid
			{
				cout << s << endl; //output the word
			}
		}
	}
}