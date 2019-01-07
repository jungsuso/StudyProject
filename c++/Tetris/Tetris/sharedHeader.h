#pragma once

#include <conio.h>

#include "gameManager.h"

#define MAX_HEIGHT 50
#define MAX_WIDTH 31
#define MAGIC_KEY 224
#define SPACEBAR 32
#define ESC 27

extern int screen[MAX_HEIGHT][MAX_WIDTH];

enum MENU
{
	GAMESTART,
	GAMEINFO,
	QUIT,
};

enum MAPTYPE
{
	EMPTY = 0,
	BACKGROUND,
	FIGURE,
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

struct Position
{
	int x;
	int y;
};

enum TETRISFIGURE
{
	Stick = 0,
	Nieun,
	Rnieun,
	O,
	UpStairs,
	DownStairs,
	Square,
};