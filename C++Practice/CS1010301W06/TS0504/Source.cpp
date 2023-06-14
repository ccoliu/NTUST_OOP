//Name:¼B®a¦¨
//Date: 2023/3/30
//Last Update: 2023/3/30
//Problem statement: Sudoku legitimate distinguish

#include <iostream>
#include <string>
#include <map>
using namespace std;

// function to check if there are any repeated numbers in each row
bool horizontalCheck(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		map<int, int> mp;
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j] < 1 || sudoku[i][j] > 9) // check if number is within 1-9
			{
				return false;
			}
			else
			{
				if (mp.find(sudoku[i][j]) != mp.end()) // check if number has already appeared in row
				{
					return false;
				}
				else
				{
					mp.insert(pair<int, int>(sudoku[i][j], 0)); // add number to map to check for duplicates
				}
			}
		}
	}
	return true; // if no duplicates, return true
}

// function to check if there are any repeated numbers in each column
bool verticalCheck(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		map<int, int> mp;
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[j][i] < 1 || sudoku[j][i] > 9) // check if number is within 1-9
			{
				return false;
			}
			else
			{
				if (mp.find(sudoku[j][i]) != mp.end()) // check if number has already appeared in column
				{
					return false;
				}
				else
				{
					mp.insert(pair<int, int>(sudoku[j][i], 0)); // add number to map to check for duplicates
				}
			}
		}
	}
	return true; // if no duplicates, return true
}

// function to check if there are any repeated numbers in each 3x3 block
bool blockCheck(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		map<int, int> mp;
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + j % 3] < 1 || sudoku[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + j % 3] > 9) // check if number is within 1-9
			{
				return false;
			}
			else
			{
				if (mp.find(sudoku[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + j % 3]) != mp.end()) // check if number has already appeared in 3x3 block
				{
					return false;
				}
				else
				{
					mp.insert(pair<int, int>(sudoku[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + j % 3], 0)); // add number
				}
			}
		}
	}
	return true;
}

//function to clear the board
void clear(int sudoku[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudoku[i][j] = 0;
		}
	}
}

int main()
{
	// initialize a 9x9 sudoku grid
	int sudoku[9][9];
	// initialize the counter t to 0
	int t = 0;
	// initialize a string variable to store user input
	string str;
	// read input until end-of-file
	while (getline(cin, str))
	{
		// initialize a counter s to 0
		int s = 0;
		// iterate over each character in the string
		for (int i = 0; i < str.length(); i++)
		{
			// if the character is a digit
			if (isdigit(str[i]))
			{
				// convert the character to an integer and store it in the sudoku grid
				sudoku[t][s] = (str[i] - '0');
				// increment the counter s
				s++;
			}
		}
		// if s equals 9, increment the counter t
		if (s == 9) t++;
		// if t is greater than 8
		if (t > 8)
		{
			// if the sudoku grid satisfies all the constraints, print "True"
			if (horizontalCheck(sudoku) && verticalCheck(sudoku) && blockCheck(sudoku))
			{
				cout << "True" << endl;
			}
			// otherwise, print "False"
			else cout << "False" << endl;
			// reset the counter t to 0
			t = 0;
		}
	}
	// if t is not equal to 0, print "False"
	if (t != 0) cout << "False" << endl;
}