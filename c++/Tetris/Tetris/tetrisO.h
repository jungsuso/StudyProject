#pragma once
#include "tetrisParent.h"

class FigureO : public TetrisParent
{
public:

	void CreateO();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};