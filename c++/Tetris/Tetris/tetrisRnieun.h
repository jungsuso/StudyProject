#pragma once
#include "tetrisParent.h"

class FigureRnieun : public TetrisParent
{
public:

	void CreateRnieun();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};