#pragma once
#include "tetrisParent.h"

class FigureSquare : public TetrisParent
{
public:

	void CreateSquare();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};