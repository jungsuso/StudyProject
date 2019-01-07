#include "tetrisO.h"

void FigureO::CreateO()
{
	screen[9][11] = 2;
	screen[10][10] = 2;
	screen[10][11] = 2;
	screen[10][12] = 2;
}

bool FigureO::CheckPosition(const Position movePos)
{
	return false;
}

void FigureO::MovePosition(const Position movePos)
{
}
