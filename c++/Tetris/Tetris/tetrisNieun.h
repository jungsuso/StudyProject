#pragma once
#include "tetrisParent.h"

class FigureNieun : public TetrisParent
{
public:

	void CreateNieun();

	bool CheckPosition(const Position movePos) override;
	void MovePosition(const Position movePos) override;

private:
};