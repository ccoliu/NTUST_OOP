//Author: ¼B®a¦¨
//Date: 2023/05/02
//Last Update: 2023/05/02
//Problem statement: User enter a series of pairs of character which can be transform from a to b,
//                   and then user can enter a pair of word, program will check if the word can be transform
//                   from the first word to the second word.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<char> box; // store the character that can be transform from the first word to the second word

void DFS(multimap<char, char> dict, char ori) // DFS to find the character that can be transform from the first word to the second word
{
	box.push_back(ori); // push the character into the box
	for (auto it = dict.find(ori); it != dict.end(); it++) //loop through the map
	{
		if (it->first == ori && find(box.begin(), box.end(), it->second) == box.end()) //if the key is equal to the char and it is not in the box
		{
			box.push_back(it->second); // push the character into the box
			DFS(dict, it->second); // DFS
		}
	}
}

int main()
{
	int m, n; // m is the number of pairs of character, n is the number of pairs of word
	while (cin >> m >> n) // loop until m and n are both 0
	{
		if (m == n && m == 0) break; // if m and n are both 0, break the loop
		else
		{
			multimap<char, char> dict; // store the pairs of character
			for (int i = 0; i < m; i++)
			{
				char a, b; // a is the first character, b is the second character
				cin >> a >> b; // input the pair of character
				dict.insert({ a,b }); // insert the pair of character into the map
			}
			for (int i = 0; i < n; i++)
			{
				string ori, ans; // ori is the first word, ans is the second word
				cin >> ori >> ans; // input the pair of word
				if (ori.length() == ans.length()) // if the length of the first word is equal to the length of the second word
				{
					bool flag = true; // flag to check if the word can be transform from the first word to the second word
					for (int i = 0; i < ori.length(); i++) //loop through the characters
					{
						if (ori[i] == ans[i]) continue; // if the character is equal to the character in the same position, continue
						else // if the character is not equal to the character in the same position
						{
							box.clear(); // clear the box
							DFS(dict, ori[i]); // DFS
							if (find(box.begin(), box.end(), ans[i]) == box.end()) // if the character is not in the box
							{
								flag = false; // set flag to false
								break; // break the loop
							}
						}
					}
					((flag) ? cout << "yes" << endl : cout << "no" << endl); // output yes if flag is true, output no if flag is false
				}
				else cout << "no" << endl; // if the length of the first word is not equal to the length of the second word, output no
			}
		}
	}
}