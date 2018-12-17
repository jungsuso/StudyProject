#pragma once
#include "objectParent.h"
#include "objectBox.h"

class ObjectPlayer : public ObjectParent
{
public:
	ObjectPlayer()
	{

	}
	~ObjectPlayer() {}

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};