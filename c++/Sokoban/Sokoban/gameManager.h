#pragma once
#include "firstheader.h"
#include "objectPlayer.h"
#include <Windows.h>

#define LIFE 3

using namespace std;

// 게임의 모든 부분을 통제하는 게임매니저
class GameManager
{
public:

	// 맵 그리기
	void DrawMap(int life);

	bool ReadyGame();
	void StartGame(ObjectPlayer* pPlayer);

	// 커서 이동하는 함수
	void gotoxy(int x, int y);

private:
	// 플레이어의 위치를 찾는 함수
	void FindPlayerPosition(ObjectPlayer* pPlayer);
};