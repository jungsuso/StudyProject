#include "objectParent.h"

void ObjectParent::SetX(int dx)
{
	position.x = dx;
}

void ObjectParent::SetY(int dy)
{
	position.y = dy;
}

int ObjectParent::GetX()
{
	return position.x;
}

int ObjectParent::GetY()
{
	return position.y;
}

bool ObjectParent::IsinMapNow() const
{
	if (position.x < MAX_WIDTH && position.x > 0 &&
		position.y < MAX_HEIGHT && position.y > 0)
	{
		return true;
	}
	return false;
}

bool ObjectParent::IsinMapNow(int dy, int dx)
{
	if (dx < MAX_WIDTH && dx > 0 &&
		dy < MAX_HEIGHT && dy > 0)
	{
		return true;
	}
	return false;
}
