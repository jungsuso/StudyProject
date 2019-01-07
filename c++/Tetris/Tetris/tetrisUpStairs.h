#pragma once
#include "tetrisParent.h"

class FigureUpStairs : public TetrisParent
{
public:

	void CreateUpStairs();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};