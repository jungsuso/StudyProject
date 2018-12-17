#pragma once
#include "objectParent.h"

class ObjectBox : public ObjectParent
{
public:
	ObjectBox()
	{
		SetX(0);
		SetY(0);
	}
	~ObjectBox() {}

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};