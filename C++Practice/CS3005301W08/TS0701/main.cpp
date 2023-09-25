//Name:¼B®a¦¨
//Date: 2023/4/13
//Last Update: 2023/4/13
//Problem statement: With a given dictionary, find all words that can be formed by removing one character from the given word.

#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("words.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers
	return 0;
}