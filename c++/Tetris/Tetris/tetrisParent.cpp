#include "tetrisParent.h"
#include "gameManager.h"
#include "tetrisStick.h"

void TetrisParent::SetX(int dx)
{
	position.x = dx;
}

void TetrisParent::SetY(int dy)
{
	position.y = dy;
}

int TetrisParent::GetX()
{
	return position.x;
}

int TetrisParent::GetY()
{
	return position.y;
}

bool TetrisParent::IsinMapNow() const
{
	if (position.x < 19 && position.x > 2
		&& position.y < 47 && position.y > 9)
		return true;

	return false;
}

bool TetrisParent::IsinMapNow(int dy, int dx)
{
	if (dx < 19 && dx > 2
		&& dy < 47 && dy > 9)
		return true;

	return false;
}

void TetrisParent::CreateFigures(int figures_number)
{
	switch (figures_number)
	{
	case Stick:
		FigureStick* FgStick = new FigureStick();
		FgStick->CreateStick();
		break;
	/*
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
	*/
	}
}
