//Name: ¼B®a¦¨
//Date: 2023/5/10
//Last Update: 2023/5/10
//Problem statement: Print all combinations of C(n,m)

#include "PrintCombination.h"
#include <vector>
#include <iostream>
#include <stddef.h>
using namespace std;

//recursion function that finds all combinations of C(n,m)
//everytime it eaches the number of elements for choice, it prints the combination
//the times n that function recurses means the position n of the element that is being chosen
void findAllChoice(int* arrayPtr, int elementsForCombination, int elementsForChoice, vector<int> combination, int idx)
{
	if (combination.size() == elementsForChoice) //if combination size reaches the number of elements for choice, print the combination
	{
		for (int i = 0; i < elementsForChoice; i++) //loop through the vector
		{
			cout << combination[i]; //print the element
			if (i < elementsForChoice - 1) cout << " "; //if it is not the last element, print a space
		}
		cout << endl; //print a new line
		return; //return to the previous function
	}
	for (int i = idx; i < elementsForCombination; i++)
	{
		combination.push_back(arrayPtr[i]); //push the element into the vector
		findAllChoice(arrayPtr, elementsForCombination, elementsForChoice, combination, i+1); //do recursion of the i+1th element
		combination.pop_back(); //pop the element out of the vector and do the next element
	}
}

void PrintCombination(int* arrayPtr, int elementsForCombination, int elementsForChoice)
{
	vector<int> combination; //empty vector to store the combination
	for (int i = 0; i <= elementsForCombination - elementsForChoice; i++) //loop until the last element that can be chosen
	{
		combination.push_back(arrayPtr[i]); //push the element into the vector
		findAllChoice(arrayPtr, elementsForCombination, elementsForChoice, combination, i+1); //do recursion of the i+1th element
		combination.clear(); //clear the vector
	}
}
