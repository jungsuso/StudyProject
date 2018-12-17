#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

void gotoxy(int x, int y)
{
	COORD Position;
	Position.X = 2 * x;
	Position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); // COORD ����ü���� return�Ǵ� x, y ������ Ŀ���� �̵�
}

void DrawReadyGame()
{
	system("cls"); // ȭ���� ��µ� �� ���� ��µ� ���ڵ��� ��� ����
	gotoxy(5, 2);
	std::cout << "******************************";
	gotoxy(5, 3);
	std::cout << "**        Dance Beat        **";
	gotoxy(5, 4);
	std::cout << "******************************";
	gotoxy(10, 8);
	std::cout << "GameStart";
	gotoxy(10, 9);
	std::cout << "GameInfo";
	gotoxy(10, 10);
	std::cout << "Quit" << std::endl;
}

void DrawInfo_Of_Game()
{
	system("cls");
	gotoxy(1, 3);
	std::cout << "*********************************************";
	gotoxy(1, 4);
	std::cout << "|������ - ������";
	gotoxy(1, 5);
	std::cout << "|���߱Ⱓ - 18.11.18 ~ 18.11.25";
	gotoxy(1, 6);
	std::cout << "*********************************************";
}

void DrawStartGame(const int life, const int score, const std::string questionStr, const std::string answerStr)
{
	system("cls");
	gotoxy(2, 1);
	std::cout << "*********************************************";
	gotoxy(4, 3);
	std::cout << "Life : " << life;
	gotoxy(4, 4);
	std::cout << "Score : " << score;
	gotoxy(4, 8);
	std::cout << "Q : " << questionStr;
	gotoxy(4, 10);
	std::cout << "A : " << answerStr;
	gotoxy(4, 12);
	std::cout << "SPACE!�� ���� ���� �����ϼ���.";
	gotoxy(2, 18);
	std::cout << "*********************************************" << std::endl;
}

void DrawGameOver(const int& playTime)
{
	gotoxy(8, 8);
	std::cout << "-----------------";
	gotoxy(8, 9);
	std::cout << "    GAME OVER    ";
	gotoxy(8, 10);
	std::cout << "      " << playTime << " sec";
	gotoxy(8, 11);
	std::cout << "-----------------";
	system("pause>null");
}

void DrawUserCursor(int& y)
{
	if (y < 0)
		y = 2;
	else if (y > 2)
		y = 0;
	gotoxy(9, 8 + y);
	std::cout << ">";
}