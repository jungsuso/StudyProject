#include "gameManager.h"
#include "firstheader.h"

int map[MAX_HEIGHT][MAX_WIDTH] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 2, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 3, 4, 0, 0, 1, 1},
	{1, 1, 0, 0, 3, 4, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main()
{
	GameManager* pGameManager = new GameManager();
	ObjectPlayer* pPlayer = new ObjectPlayer();

	while (true)
	{
		if (pGameManager->ReadyGame())
		{
			pGameManager->StartGame(pPlayer);
		}
	}

	//gameManager->DrawMap();
	system("pause");

	delete pPlayer;
	delete pGameManager;
	
	return 0;
}