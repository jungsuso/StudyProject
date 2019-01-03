#include "tetrisStick.h"

void FigureStick::CreateStick()
{
	screen[10][9] = 2;
	screen[11][9] = 2;
	screen[12][9] = 2;
	screen[13][9] = 2;
}

bool FigureStick::CheckPosition(const Position movePos)
{
	return false;
}

void FigureStick::MovePosition(const Position movePos)
{
}
