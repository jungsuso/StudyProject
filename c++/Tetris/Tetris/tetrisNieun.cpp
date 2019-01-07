#include "tetrisNieun.h"

void FigureNieun::CreateNieun()
{
	screen[9][9] = 2;
	screen[10][9] = 2;
	screen[10][10] = 2;
	screen[10][11] = 2;
}

bool FigureNieun::CheckPosition(const Position movePos)
{
	return false;
}

void FigureNieun::MovePosition(const Position movePos)
{
}
