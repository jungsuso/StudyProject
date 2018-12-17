#include "gameManager.h"

void GameManager::FindPlayerPosition(ObjectPlayer * pPlayer)
{
	for (int y = 0; y < MAX_HEIGHT; ++y)
	{
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			if (map[y][x] == PLAYER)
			{
				pPlayer->SetX(x);
				pPlayer->SetY(y);
				return;
			}
		}
	}
}

void GameManager::DrawMap(int life)
{
	system("cls");
	for (int y = 0; y < MAX_HEIGHT; ++y)
	{
		for (int x = 0; x < MAX_WIDTH; ++x)
		{
			switch (map[y][x])
			{
			case EMPTY:
				cout << "  ";
				break;
			case WALL:
				cout << "▩";
				break;
			case PLAYER:
				cout << "＊";
				break;
			case HOLE:
				cout << "□";
				break;
			case BOX:
				cout << "▤";
				break;
			case HOLEWITHBOX:
				cout << "■";
				break;
			case HOLEWITHPLAYER:
				cout << "▣";
				break;
			}
		}
		cout << "\n";
	}
	gotoxy(13, 2);
	cout << "Life : " << life << endl;
	gotoxy(0, 11);
}

bool GameManager::ReadyGame()
{
	return true;
}

void GameManager::StartGame(ObjectPlayer* pPlayer)
{
	int life = LIFE;
	FindPlayerPosition(pPlayer);

	while (true)
	{
		DrawMap(life);
		// 플레이어가 움직이고
		// 박스가 움직이고
		// 스테이지가 클리어 되었는지 확인

		int firstInput = _getch();
		if (firstInput == 224)
		{
			Position movePos;
			switch (_getch())
			{
			case UP:
				movePos.x = 0;
				movePos.y = -1;
				break;
			case DOWN:
				movePos.x = 0;
				movePos.y = 1;
				break;
			case LEFT:
				movePos.x = -1;
				movePos.y = 0;
				break;
			case RIGHT:
				movePos.x = 1;
				movePos.y = 0;
				break;
			}

			pPlayer->MovePosition(movePos);
		}
	}
	// game start
}

void GameManager::gotoxy(int x, int y)
{
	COORD Position;
	Position.X = 2 * x;
	Position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}