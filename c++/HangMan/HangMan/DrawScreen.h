#pragma once
#include <vector>

// ���� ���� ��, �ܼ�â�� ũ�� ����
void SetConsoleView();

// ȭ�� �������� ���� Ŀ�� �̵�
void gotoxy(int x, int y);

// ����ȭ�� �׸���
void DrawReadyGame();

// ����ȭ�� �׸���
void DrawStartGame(int score, int life, std::vector<std::string>& pastWord);