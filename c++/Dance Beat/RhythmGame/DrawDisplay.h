#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>



// ���� ��, �ܼ�â�� ũ��� title�� �����ִ� �Լ�
void SetConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title Dance Beat");
}

// ȭ�鿡�� ���ϴ� ���� ����� �ϱ� ���� Ư�� ��ġ�� Ŀ���� �̵�
void gotoxy(int x, int y);

// ����ȭ�� ��� �Լ�
void DrawReadyGame();

// ���α׷� ���� ��� �Լ�
void DrawInfo_Of_Game();

// ���� �� ȭ�� ��� �Լ�
void DrawStartGame(const int life, const int score, const std::string questionStr, const std::string answerStr);

// ���ӿ��� �� ��� �Լ�
void DrawGameOver(const int& playTime);

// ����ȭ�鿡�� ���ϴ� ��� �����ϵ��� �ϴ� �Լ�
void DrawUserCursor(int& y);