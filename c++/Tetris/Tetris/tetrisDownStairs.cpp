#include "tetrisDownStairs.h"

void FigureDownStairs::CreateDownStairs()
{
	screen[9][9] = 2;
	screen[9][10] = 2;
	screen[10][10] = 2;
	screen[10][11] = 2;
}

bool FigureDownStairs::CheckPosition(const Position movePos)
{
	return false;
}

void FigureDownStairs::MovePosition(const Position movePos)
{
}
