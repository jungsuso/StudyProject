#include "tetrisRnieun.h"

void FigureRnieun::CreateRnieun()
{
	screen[9][11] = 2;
	screen[10][11] = 2;
	screen[10][10] = 2;
	screen[10][9] = 2;
}

bool FigureRnieun::CheckPosition(const Position movePos)
{
	return false;
}

void FigureRnieun::MovePosition(const Position movePos)
{
}
