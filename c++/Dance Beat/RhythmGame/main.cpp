#include <iostream>
#include "DrawDisplay.h"
#include "Game_Implementations.h"

int main(void)
{
	SetConsoleView();

	while (true)
	{
		switch (ReadyGame())
		{
		case GAMESTART:
			GameStart();
			break;

		case INFO:
			Infomation_Of_Game();
			break;

		case QUIT:
			return 0;
		}
	}
}