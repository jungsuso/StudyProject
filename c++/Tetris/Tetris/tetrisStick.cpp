#include "tetrisStick.h"

void FigureStick::CreateStick()
{
	screen[9][11] = 2;
	screen[10][11] = 2;
	screen[11][11] = 2;
	screen[12][11] = 2;
}

bool FigureStick::CheckPosition(const Position movePos)
{
	if (!IsinMapNow())
	{
		return false;
	}

	return true;
}

void FigureStick::MovePosition(const Position movePos)
{
	if (!CheckPosition(movePos))
	{
		return;
	}
}
