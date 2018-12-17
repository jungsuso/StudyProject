#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title HangManGame");
}

void DrawReadyGame()
{
	system("cls");
	gotoxy(5, 2);
	cout << "============================";
	gotoxy(5, 3);
	cout << "======= HANGMAN GAME =======";
	gotoxy(5, 4);
	cout << "============================";

	gotoxy(5, 6);
	cout << "�����Ϸ��� 's'�� �����ּ���.";
	gotoxy(5, 7);
	cout << "�����Ϸ��� 'q'�� �����ּ���.";

	gotoxy(14, 14);
	cout << "by. ������";
}

void DrawStartGame(int score, int life, vector<string>& pastWord)
{
	system("cls");
	gotoxy(5, 1);
	cout << "Life = " << life;
	gotoxy(5, 2);
	cout << "Score = " << score;
	gotoxy(5, 8);
	cout << "past = ";
	for (const string &str : pastWord)
		cout << str << " ";
	gotoxy(5, 12);
	cout << "input = ";

	gotoxy(13, 14);
	cout << "����ȭ�� 'qq'" << endl;
}