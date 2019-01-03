#pragma once
#include "sharedHeader.h"

class TetrisParent
{
public:
	void SetX(int dx);
	void SetY(int dy);
	int GetX();
	int GetY();
	bool IsinMapNow() const;
	bool IsinMapNow(int dy, int dx);

	// @TODO : Rotation,

	virtual bool CheckPosition(const Position movePos) = 0;
	virtual void MovePosition(const Position movePos) = 0;

private:
	Position position;
};