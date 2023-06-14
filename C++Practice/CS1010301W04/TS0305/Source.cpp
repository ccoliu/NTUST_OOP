//Name:¼B®a¦¨
//Date: 2022/3/16
//Last Update: 2022/3/17
//Problem statement: Simple Drawing program

#include <iostream>
using namespace std;

void printboard(char** board, int m, int n) // print out the board
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int m, n; //m = row, n = column
	while (cin >> m >> n)
	{
		char** board = new char* [n] {}; //using pointer to allocate variable-sized array
		for (int i = 0; i < n; i++)
		{
			board[i] = new char[m];
			for (int j = 0; j < m; j++)
			{
				board[i][j] = '*';
			}
		}
		string method = "";
		while (cin >> method)
		{
			if (method == "\n") continue;
			else if (method == "EXIT" || method == "exit") break;
			else if (method == "S" || method == "s")
			{
				int w = 0, x = 0, y = 0;
				cin >> w >> x >> y;
				if (x + w > m || y + w > n || x < 0 || y < 0) //if x or y is out of border, output error messages.
				{
					cout << "Out of range." << endl << endl;
					continue;
				}
				else
				{
					int down = 0;
					int right = 0;
					for (down; down < w; down++)
					{
						for (right = 0; right < w; right++)
						{
							board[y + down][x + right] = 'X'; //making square inside the board.
						}
					}
					printboard(board, m, n);
				}
			}
			else if (method == "T" || method == "t")
			{
				int w = 0, x = 0, y = 0;
				string side = "";
				cin >> w >> x >> y >> side;
				int ver = 0;
				int hor = 0;
				if (side[0] == 'L') //to check if the triangle is in the border.
				{
					if (x - w + 1 < 0)
					{
						cout << "Out of range." << endl << endl;
						continue;
					}
				}
				else if (side[0] == 'R')
				{
					if (x + w > m)
					{
						cout << "Out of range." << endl << endl;
						continue;
					}
				}
				if (side[1] == 'U')
				{
					if (y - w + 1 < 0)
					{
						cout << "Out of range." << endl << endl;
						continue;
					}
				}
				else if (side[1] == 'D')
				{
					if (y + w > n)
					{
						cout << "Out of range." << endl << endl;
						continue;
					}
				}
				if (side[0] == 'L')
				{
					for (hor; hor < w; hor++)
					{
							board[y][x - hor] = 'X';
					}
				}
				else
				{
					for (hor; hor < w; hor++)
					{
							board[y][x + hor] = 'X';
					}
				}
				if (side[1] == 'U')
				{
					for (ver; ver < w; ver++)
					{
						board[y - ver][x] = 'X';						
					}
				}
				else
				{
					for (ver; ver < w; ver++)
					{
						board[y + ver][x] = 'X';
					}
				}
				hor--;
				ver--;
				if (side == "LU")
				{
					int a = y - ver;
					int b = x;
					for (a, b; a < y && b >(x - hor); a++, b--)
					{
						board[a][b] = 'X';
					}
				}
				else if (side == "LD")
				{
					int a = y + ver;
					int b = x;
					for (a, b; a > y && b > (x - hor); a--, b--)
					{
						board[a][b] = 'X';
					}
				}
				else if (side == "RU")
				{
					int a = y - ver;
					int b = x;
					for (a, b; a < y && b < (x + hor); a++, b++)
					{
						board[a][b] = 'X';
					}
				}
				else
				{
					int a = y + ver;
					int b = x;
					for (a, b; a > y && b < (x + hor); a--, b++)
					{
						board[a][b] = 'X';
					}
				}
				printboard(board, m, n);
			}
			else if (method == "L" || method == "l")
			{
				int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
				cin >> x1 >> y1 >> x2 >> y2;
				if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= m || y1 >= n || x2 >= m || y2 >= n) // check if the dots are outside the board.
				{
					cout << "Out of range." << endl << endl;
					continue;
				}
				else
				{
					if (y1 == y2)
					{
						if (x1 > x2) swap(x1, x2);
						int i = x1;
						int j = y1;
						for (i; i <= x2; i++)
						{
							board[j][i] = 'X';
						}
					}
					else if (x1 == x2)
					{
						if (y1 > y2) swap(y1, y2);
						int i = x1;
						int j = y1;
						for (j; j <= y2; j++)
						{
							board[j][i] = 'X';
						}
					}
					else
					{
						if (y1 > y2)
						{
							int i = x1;
							int j = y1;
							if (x1 < x2)
							{
								for (i, j; i <= x2 && j >= y2; i++, j--)
								{
									board[j][i] = 'X';
								}
							}
							else
							{
								for (i, j; i >= x2 && j >= y2; i--, j--)
								{
									board[j][i] = 'X';
								}
							}
						}
						else
						{
							int i = x2;
							int j = y2;
							if (x1 < x2)
							{
								for (i, j; i >= x1 && j >= y1; i--, j--)
								{
									board[j][i] = 'X';
								}
							}
							else
							{
								for (i, j; i <= x1 && j >= y1; i++, j--)
								{
									board[j][i] = 'X';
								}
							}
						}
					}
					printboard(board, m, n);
				}
			}
		}
	}
}