#pragma once
#include "tetrisParent.h"

class FigureDownStairs : public TetrisParent
{
public:

	void CreateDownStairs();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};