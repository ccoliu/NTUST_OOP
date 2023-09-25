#include <iostream>
using namespace std;
bool hasFind = false;


typedef struct
{
	int x;
	int y;
} Pos;

void reachable(char board[8][8], Pos start, Pos end)
{
	board[start.y][start.x] = 'X';
	if (abs(start.y - end.y) + abs(start.x - end.x) <= 1)
	{
		cout << "pair matched" << endl;
		hasFind = true;
		return;
	}
	if (start.x - 1 > 0 && board[start.y][start.x - 1] == '0')
	{
		reachable(board, { start.x - 1, start.y }, end);
	}
	if (start.x + 1 <= 7 && board[start.y][start.x + 1] == '0')
	{
		reachable(board, { start.x + 1, start.y }, end);
	}
	if (start.y - 1 > 0 && board[start.y - 1][start.x] == '0')
	{
		reachable(board, { start.x, start.y - 1 }, end);
	}
	if (start.y + 1 <= 7 && board[start.y + 1][start.x] == '0')
	{
		reachable(board, { start.x, start.y + 1 }, end);
	}
	return;
}

int main()
{
	char shisensho[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			shisensho[i][j] = '0';
		}
	}
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			cin >> shisensho[i][j];
		}
	}
	Pos pos1, pos2;
	while (cin >> pos1.x >> pos1.y >> pos2.x >> pos2.y)
	{
		pos1.x++;
		pos1.y++;
		pos2.x++;
		pos2.y++;
		if (shisensho[pos1.y][pos1.x] != shisensho[pos2.y][pos2.x])
		{
			cout << "bad pair" << endl;
			continue;
		}
		char cloneBoard[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cloneBoard[i][j] = shisensho[i][j];
			}
		}
		reachable(cloneBoard, pos1, pos2);
		if (hasFind)
		{
			shisensho[pos1.y][pos1.x] = '0';
			shisensho[pos2.y][pos2.x] = '0';
		}
		else
		{
			cout << "bad pair" << endl;
		}
		hasFind = false;
	}
}