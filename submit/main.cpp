/************************************************************************
File:   Source.cpp

Author:
		劉家成，frgnd5433@gmail.com
Modifier:
		陳尚澤，luchiya131072@gmail.com
File Created:
		2023/3/21
Last Modified:
		2023/3/21
Comment:
		User can enter WASD to control hero's movement, Creature was created,
		it will act differently depends on the position of the hero.
************************************************************************/
#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function
using namespace std;

//************************************************************
// The location in the board
//************************************************************
struct Position {
	int x; // X, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;
//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;	//base position x of hero
		this->sPos.y = 0;	//base position y of hero
		this->sIcon = 'H';	//symbol of hero
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Incrementally move the elements 
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/
		if (this->sPos.x + deltaX < GWIDTH - 1 && this->sPos.x + deltaX > 0)
		{
			this->sPos.x += deltaX;
		} //add the delta position x to the base position.
		if (this->sPos.y + deltaY < GHEIGHT - 1 && this->sPos.y + deltaY > 0)
		{
			this->sPos.y += deltaY;
		} //add the delta position y to the base position.
		/************************************************************************/
	}
};

// clip algroithm
float clip(float n, float minimun, float maximum);

class Creature {

	// Implement Creature Class
	/*Please implement your code here*/
private:
	Position cPos;
	char cIcon = '@'; //creature icon set to @

public:
	Creature()
	{
		this->cPos.x = 5; //base position x of creature
		this->cPos.y = 6; //base position y of creature
		this->cIcon = '@'; //the symbol of creature
	}

	// Set position
	void setPos(Position pos) { this->cPos = pos; }
	void setPos(int x, int y) {
		this->cPos.x = x;
		this->cPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->cIcon = icon; }

	// Get position
	Position getPos(void) { return this->cPos; }

	// Get Icon
	char getIcon(void) { return this->cIcon; }

	// Incrementally move the elements 
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/
		if (this->cPos.x + deltaX < GWIDTH - 1 && this->cPos.x + deltaX > 0)
		{
			this->cPos.x += deltaX;
		} //add the delta position x to the base position.
		if (this->cPos.y + deltaY < GHEIGHT - 1 && this->cPos.y + deltaY > 0)
		{
			this->cPos.y += deltaY;
		} //add the delta position y to the base position.
		/************************************************************************/
	}

	bool visible(Position Pos)
	{
		if (abs(this->cPos.x - Pos.x) <= 2 && abs(this->cPos.y - Pos.y) <= 2) // if hero is in creature sight, return true, else return false.
		{
			return true;
		}
		else return false;
	}

	void update(Position Pos)
	{
		if (visible(Pos) == true) //if creature can see hero, track heros position and approach him.
		{
			if (this->cPos.x < Pos.x) //move x first
			{
				move(1, 0);
			}
			else if (this->cPos.x > Pos.x)
			{
				move(-1, 0);
			}
			else if (this->cPos.y < Pos.y) //if x equals, we move y
			{
				move(0, 1);
			}
			else if (this->cPos.y > Pos.y)
			{
				move(0, -1);
			}
		}
		else
		{	//if not, random pick a way to go
			bool moved = false;
			while (!moved) //loop until creature is moved
			{
				int random = rand() % 4;
				switch (random) //random pick a direction to move
				{
				case 0:
					if (this->cPos.x + 1 < GWIDTH - 1)
					{
						move(1, 0); //x add 1
						moved = true; //if the creature is still inside the board after moved, we can exit the loop.
					}
					break;
				case 1:
					if (this->cPos.y + 1 < GHEIGHT - 1)
					{
						move(0, 1); // y add 1
						moved = true;
					}
					break;
				case 2:
					if (this->cPos.x - 1 > 0)
					{
						move(-1, 0); //x minus 1
						moved = true;
					}
					break;
				case 3:
					if (this->cPos.y - 1 > 0)
					{
						move(0, -1); //y minus 1
						moved = true;
					}
					break;
				}
			}
		}
	}
	/************************************************************************/
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

Hero gHero;
Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// Set the position of Hero
	gHero.setPos(2, 2);

	gCreature.setPos(5, 6);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			if (i == 0 || i == GHEIGHT - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	// Print Outputs
	/*Please implement your code here*/
	if (gCreature.visible(gHero.getPos()) == true) //check if the hero can be seen.
	{
		cout << "The creature can see you." << endl;
	}
	/************************************************************************/
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		gHero.move(1, 0);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	//Calculate and Initiate Move
	gCreature.update(gHero.getPos());
	draw();
	drawInfo();
}
