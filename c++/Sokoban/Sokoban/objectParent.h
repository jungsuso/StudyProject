#pragma once
#include "firstheader.h"

class ObjectParent
{
public:
	ObjectParent()
	{
		position.x = 0;
		position.y = 0;
	}
	virtual ~ObjectParent() {}

	void SetX(int dx);
	void SetY(int dy);
	int GetX();
	int GetY();
	bool IsinMapNow() const;
	bool IsinMapNow(int dy, int dx);

	virtual bool CheckPosition(const Position movePos) = 0;
	virtual void MovePosition(const Position movePos) = 0;

private:
	Position position;
};