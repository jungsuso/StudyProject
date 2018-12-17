#include "DrawScreen.h"
#include "function_Implementations.h"

//#define WORD_MAX 4

int main()
{
	SetConsoleView();
	bool isStart = false;

	while (true)
	{
		isStart = ReadyGame();
		if (isStart)
			StartGame();
		else
			break;
	}
	
	return 0;
}