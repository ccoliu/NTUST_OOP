//Name:¼B®a¦¨
//Date:2023/4/19
//Last Update:2023/4/20
//Problem statement:Memory Simulation


#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main()
{
	unsigned int memSize; //the size of memory
	int cases; //the number of cases
	char* mem = NULL; //create an empty memory
	while (cin >> memSize >> cases) //input the size of memory and the number of cases
	{
		mem = new char[memSize] {}; //create a memory
		string command, type; //command is the command of the case, type is the type of the case
		unsigned int position; //position is the position of the case
		unsigned int int_value; //int_value is the value of int in the case
		unsigned char char_value; //char_value is the value of char in the case
		unsigned short short_value; //short_value is the value of short in the case
		string str_value; //str_value is the value of string in the case
		for (int i = 0; i < cases; i++)
		{
			cin >> command >> position >> type; //input the command, position and type of the case
			if (position < 0 || position >= memSize) //if the position is out of the range of memory, output the error message
			{
				cout << "Violation Access." << endl;
				continue;
			}
			if (type == "String") //if the type is string
			{
				if (command == "Set") //if the command is set
				{
					getline(cin, str_value); //input the value of string
					str_value.erase(0, 1); //erase the spare space
					if (position + str_value.size() >= memSize) //if the position is out of the range of memory, output the error message
					{
						cout << "Violation Access." << endl; //output error message
						memcpy(mem + position, str_value.c_str(), memSize - position); //created an size that can put part of string into memory
						continue; //continue the loop
					}
					memcpy(mem + position, str_value.c_str(), str_value.size()); //put the string into memory
				}
				else if (command == "Get") //if the command is get
				{
					char* p = mem + position; //create a pointer to point the position of memory
					int k = position; //create a variable to count the position
					while (*p != '\0' && k < memSize) //if the pointer is not the end of string and the position is not out of the range of memory
					{
						cout << (char)*p; //output the string
						p++; //move the pointer to next position
						k++; //add 1 to position
					}
					cout << endl; //output the end of line
				}
			}
			else if (type == "int") //if the type is int
			{
				if (position + sizeof(int) > memSize) //if the position is out of the range of memory, output the error message
				{
					cout << "Violation Access." << endl; //output error message
					if (command == "Set") //if the command is set
					{
						cin >> int_value; //input the value of int
						memcpy(mem + position, &int_value, memSize - position); //created an size that can put part of int into memory
					}
					continue; //continue the loop
				}
				if (command == "Set") //if the command is set
				{
					cin >> int_value; //input the value of int
					memcpy(mem + position, &int_value, sizeof(int)); //put the int into memory
				}
				else if (command == "Get") //if the command is get
				{
					memcpy(&int_value, mem + position, sizeof(int)); //get the int from memory
					cout << int_value << endl; //output the int
				}
			}
			else if (type == "short") //if the type is short
			{
				if (position + sizeof(short) > memSize) //if the position is out of the range of memory, output the error message
				{
					cout << "Violation Access." << endl; //output error message
					if (command == "Set") //if the command is set
					{
						cin >> short_value; //input the value of short
						memcpy(mem + position, &short_value, memSize - position); //created an size that can put part of short into memory
					}
					continue; //continue the loop
				}
				if (command == "Set") //if the command is set
				{
					cin >> short_value; //input the value of short
					memcpy(mem + position, &short_value, sizeof(short)); //put the short into memory
				}
				else if (command == "Get") //if the command is get
				{
					memcpy(&short_value, mem + position, sizeof(short)); //get the short from memory
					cout << short_value << endl; //output the short
				}
			}
			else if (type == "char") //if the type is char
			{
				int tmp; //create a variable to store the value of char
				if (position + sizeof(char) > memSize) //if the position is out of the range of memory, output the error message
				{
					cout << "Violation Access." << endl; //output error message
					//because the size of char is 1, so we don't need to create a size that can put part of char into memory
					continue; //continue the loop
				}
				if (command == "Set") //if the command is set
				{
					cin >> tmp; //input the value of char
					memcpy(mem + position, &tmp, sizeof(char)); //put the char into memory
				}
				else if (command == "Get") //if the command is get
				{
					memcpy(&char_value, mem + position, sizeof(char)); //get the char from memory
					cout << (int)char_value << endl; //output the char
				}
			}
		}
		delete[] mem; //delete the memory
		mem = NULL; //set the memory to NULL
	}
}