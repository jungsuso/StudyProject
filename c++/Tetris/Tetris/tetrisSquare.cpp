#include "tetrisSquare.h"

void FigureSquare::CreateSquare()
{
	screen[9][9] = 2;
	screen[9][10] = 2;
	screen[10][9] = 2;
	screen[10][10] = 2;
}

bool FigureSquare::CheckPosition(const Position movePos)
{
	return false;
}

void FigureSquare::MovePosition(const Position movePos)
{
}
