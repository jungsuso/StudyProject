#include "tetrisUpStairs.h"

void FigureUpStairs::CreateUpStairs()
{
	screen[10][9] = 2;
	screen[10][10] = 2;
	screen[9][10] = 2;
	screen[9][11] = 2;
}

bool FigureUpStairs::CheckPosition(const Position movePos)
{
	return false;
}

void FigureUpStairs::MovePosition(const Position movePos)
{
}
