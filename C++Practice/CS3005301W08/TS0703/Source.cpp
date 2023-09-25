#include <iostream>
using namespace std;

void printdigital(char digital[3][300]) // print the digital
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			cout << digital[i][j];
		}
		cout << endl;
	}
}

void cleardigital(char digital[3][300]) // clear the digital
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			digital[i][j] = '\0';
		}
	}
}

int main()
{
	char digital[3][300]; // store the digital
	cleardigital(digital); // clear the digital
	string number; // store the number
	while (cin >> number) // read in until EOF
	{
		cleardigital(digital); // clear the digital
		for (int i = 0; i < number.length(); i++) // loop through the string
		{
			if (number[i] == '1') // if the number is 1
			{
				digital[1][i*3+2] = '|';
				digital[2][i*3+2] = '|';
			}
			if (number[i] == '2') // if the number is 2
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = ' ';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = '|';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = ' ';
			}
			if (number[i] == '3') // if the number is 3
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = ' ';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = ' ';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '4') // if the number is 4
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = ' ';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = ' ';
				digital[2][i * 3 + 1] = ' ';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '5') // if the number is 5
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = ' ';
				digital[2][i * 3] = ' ';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '6') // if the number is 6
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = ' ';
				digital[2][i * 3] = '|';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '7') // if the number is 7
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = ' ';
				digital[1][i * 3 + 1] = ' ';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = ' ';
				digital[2][i * 3 + 1] = ' ';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '8') // if the number is 8
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = '|';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '9') // if the number is 9
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = '_';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = ' ';
				digital[2][i * 3 + 1] = ' ';
				digital[2][i * 3 + 2] = '|';
			}
			if (number[i] == '0') // if the number is 0
			{
				digital[0][i * 3] = ' ';
				digital[0][i * 3 + 1] = '_';
				digital[0][i * 3 + 2] = ' ';
				digital[1][i * 3] = '|';
				digital[1][i * 3 + 1] = ' ';
				digital[1][i * 3 + 2] = '|';
				digital[2][i * 3] = '|';
				digital[2][i * 3 + 1] = '_';
				digital[2][i * 3 + 2] = '|';
			}
		}
		printdigital(digital); // clear the digital
	}
}