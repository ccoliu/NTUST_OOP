//Name:¼B®a¦¨
//Date: 2023/4/13
//Last Update: 2023/4/13
//Problem statement: With a given dictionary, find all words that can be formed by removing one character from the given word.


#include "Form.h"
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

void Form::SetInputWord(string inputWord) // set input
{
	word = inputWord; // set input word
}

void Form::ProcessInputWord() // process input
{
	for (int i = 0; i < word.length(); i++) // convert to lower case
	{
		word[i] = tolower(word[i]);
	}
}

void Form::SetFileName(string fileName) // set file name
{
	fin = fileName; // set file name
}
void Form::Load_CompareWord() // read-in data and compare
{
	map<string, int> mmap; // map to store words
	ifstream in(fin); // open file
	string temp;
	while (in >> temp) // read-in data
	{
		if (temp.length() <= word.length() && mmap.find(temp) == mmap.end()) //if word length is less than or equal to input word length and word is not in map
		{
			for (int i = 0; i < temp.length(); i++) // convert to lower case
			{
				temp[i] = tolower(temp[i]);
			}
			bool no_char_match = false; // flag to check if there is no character match
			string temp2 = word; // copy input word
			string temp3 = temp; // copy word from file
			while (no_char_match == false) // while there is character match
			{
				no_char_match = true; // set flag to true
				for (int i = 0; i < temp2.length(); i++) // compare characters
				{
					for (int j = 0; j < temp3.length(); j++) 
					{
						if (temp2[i] == temp3[j]) // if character match
						{
							temp2.erase(i, 1); // erase character from input word
							temp3.erase(j, 1); // erase character from word from file
							no_char_match = false; // set flag to false
							break; // break out of loop
						}
					}
				}
			}
			if (temp3.length() == 0) // if all characters are matched
			{
				foundWords.push_back(temp); // add word to vector
			}
			mmap[temp] = 1; // add word to map
		}
	}
}

void Form::PrintFoundWords() // print answers
{
	for (int i = 0; i < foundWords.size(); i++) // print answers
	{
		cout << foundWords[i] << endl;
	}
}