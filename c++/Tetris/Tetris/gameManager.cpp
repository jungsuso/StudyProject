#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "gameManager.h"
#include "sharedHeader.h"
#include "tetrisParent.h"
#include "tetrisStick.h"

void GameManager::SetConsoleSize()
{
	system("mode con:cols=62 lines=50");
	system("title TETRIS");
}

void GameManager::gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void GameManager::DrawUserCursor(int& y)
{
	using namespace std;

	if (y < 0)
		y = 2;
	else if (y > 2)
		y = 0;
	gotoxy(11, 27 + y);
	cout << ">";
}

void GameManager::DrawMainScreen()
{
	using namespace std;

	system("cls");

	gotoxy(4, 11);
	cout << "бсбсбс  бсбсбс  бсбсбс  бсбсбс  бсбсбс  бсбсбс" << endl;
	gotoxy(4, 12);
	cout << "  бс    бс        бс    бс  бс    бс    бс" << endl;
	gotoxy(4, 13);
	cout << "  бс    бсбсбс    бс    бсбсбс    бс    бсбсбс" << endl;
	gotoxy(4, 14);
	cout << "  бс    бс        бс    бсбс      бс        бс" << endl;
	gotoxy(4, 15);
	cout << "  бс    бсбсбс    бс    бс  бс  бсбсбс  бсбсбс" << endl;

	gotoxy(13, 27);
	cout << "Game Start" << endl;
	gotoxy(13, 28);
	cout << "Game Info" << endl;
	gotoxy(13, 29);
	cout << "Quit" << endl;
}

void GameManager::DrawGameStart()
{
	int input = 0;

	using namespace std;
	system("cls");
	for (int y = 0; y < MAX_HEIGHT; ++y)
	{
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			switch (screen[y][x])
			{
			case EMPTY:
				cout << "  ";
				break;
			case BACKGROUND:
				cout << "в╠";
				break;
			case FIGURE:
				cout << "бс";
				break;
			}
		}
		if (y == MAX_HEIGHT - 1)
			break;
		cout << endl;
	}
	input = _getch();
	if (input == ESC)
	{
		//ReadyGame();
	}
}

void GameManager::DrawGameInfo()
{
}

void GameManager::DrawFigures()
{
	//srand((unsigned int)time(0));

	int tetris_figure = 0; // rand() % 7;

	TetrisParent* ttParent = new TetrisParent();

	switch (tetris_figure)
	{
	case Stick:
		ttParent->CreateFigures(tetris_figure);
		break;
	case Nieun:
		break;
	case RNieun:
		break;
	case O:
		break;
	case UpStairs:
		break;
	case DownStairs:
		break;
	case Square:
		break;
	}
}