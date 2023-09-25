//Name: ¼B®a¦¨
//Date: 2023/05/31
//Last Update: 2023/05/31
//Problem statement: Using template to implement binary search

#pragma once

template<typename T> //apply template with typename T
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) { //function prototype
	int mid = (first + last) / 2; //find the middle index
	while (last >= first) //if the last index is greater than the first index
	{ 
		if (key > a[mid]) //if key is greater than the middle index
		{ 
			first = mid + 1; //set the first index to the middle index + 1
		}
		else if (key < a[mid]) //else if key is less than middle index
		{
			last = mid - 1; //set the last index to the middle index - 1
		}
		else //if key is equal to the middle index
		{
			location = mid; //set the location to the middle index
			found = true; //set found to true
			return;
		}
		mid = (first + last) / 2; //find the middle index again
	}
	found = false; //if the key is not found, set found to false
	return;
}


template<typename T> //apply template with typename T
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) { //function prototype
	if (first > last) //if the first index is greater than the last index
	{ 
		found = false; //set found to false
		return;
	}
	int mid = (first + last) / 2; //find the middle index
	if (key > a[mid]) //if key is greater than the middle index
	{ 
		RecBinarySearch(a, mid + 1, last, key, found, location); //call the function again with the first index set to the middle index + 1
	}
	else if (key < a[mid])  //else if key is less than the middle index
	{
		RecBinarySearch(a, first, mid - 1, key, found, location); //call the function again with the last index set to the middle index - 1
	}
	else //if the middle index is equal to the key
	{ 
		found = true; //set found to true
		location = mid; //set the location to the middle index
	}
}