#pragma once

#include "tetrisParent.h"

class FigureStick : public TetrisParent
{
public:

	void CreateStick();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};