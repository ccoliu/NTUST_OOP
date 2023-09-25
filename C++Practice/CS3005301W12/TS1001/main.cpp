//Name: ¼B®a¦¨
//Date: 2023/5/10
//Last Update: 2023/5/10
//Problem statement: Print all combinations of C(n,m)

#include "PrintCombination.h"
#include <stddef.h>

#define ELEMENTS_FOR_COMBINATION 5	//i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != nullptr)
		delete[] arrayPtr;

	return 0;
}
