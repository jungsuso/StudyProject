#pragma once
#include "firstheader.h"
#include "objectPlayer.h"
#include <Windows.h>

#define LIFE 3

using namespace std;

// ������ ��� �κ��� �����ϴ� ���ӸŴ���
class GameManager
{
public:

	// �� �׸���
	void DrawMap(int life);

	bool ReadyGame();
	void StartGame(ObjectPlayer* pPlayer);

	// Ŀ�� �̵��ϴ� �Լ�
	void gotoxy(int x, int y);

private:
	// �÷��̾��� ��ġ�� ã�� �Լ�
	void FindPlayerPosition(ObjectPlayer* pPlayer);
};