#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "DrawDisplay.h"
#pragma comment(lib, "winmm.lib")

#define MAGIC_KEY 224
#define SPACE 32
#define KEY_NUM 4
#define LIFE 3
#define MAX_LEVEL 11

// ���θ޴�
enum MENU
{
	GAMESTART,
	INFO,
	QUIT,
};

// Ű���� �Է��� ���� ������ �ڷ�
enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

// �޴� ����â ���� �Լ�
MENU ReadyGame()
{
	int y = 0;
	int input = 0;

	while (true)
	{
		DrawReadyGame();
		DrawUserCursor(y);
		input = _getch();
		// �����
		if (input == MAGIC_KEY)
		{
			switch (_getch())
			{
			case UP:
				--y;
				break;

			case DOWN:
				++y;
				break;
			}
		}
		else if (input == SPACE)
		{
			switch (y)
			{
			case 0:
				return GAMESTART;

			case 1:
				return INFO;

			case 2:
				return QUIT;
			}
		}
	}
}

// INFO �Լ��� ����ϱ� ���� �Լ�
void Infomation_Of_Game()
{
	DrawInfo_Of_Game();
	system("pause>null");
}

// ���� ���� ��, ������ ���� �������� ȭ��ǥ ����
void SetQuestion(std::vector<int>& questionVec, int level)
{
	if (level > MAX_LEVEL)
		level = MAX_LEVEL;

	int num = 0;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < level; ++i) // 5 : ȭ��ǥ�� ����(������ ���̵�)
	{
		num = rand() % KEY_NUM;
		switch (num)
		{
		case 0:
			questionVec.push_back(UP);
			break;

		case 1:
			questionVec.push_back(RIGHT);
			break;

		case 2:
			questionVec.push_back(LEFT);
			break;

		case 3:
			questionVec.push_back(DOWN);
			break;
		}
	}
}

// ���� �񱳸� ���� vector Ÿ���� ���� string Ÿ������ ��ȯ�ϴ� �Լ�
void VectorToString(const std::vector<int>& v, std::string& str)
{
	for (int i = 0; i < static_cast<int>(v.size()); ++i)
	{
		switch (v[i])
		{
		case UP:
			str += "�� ";
			break;

		case RIGHT:
			str += "�� ";
			break;

		case LEFT:
			str += "�� ";
			break;

		case DOWN:
			str += "�� ";
			break;
		}
	}
}

// ����� ������ �Է��� ���� ���ϴ� �Լ�
bool CheckAnswer(const std::vector<int> questionVec, const std::vector<int> answerVec)
{
	// ������ �迭�� ����.
	// ���� üũ
	if (questionVec.size() != answerVec.size())
	{
		return false;
	}
	// �� üũ
	for (int i = 0; i < static_cast<int>(questionVec.size()); ++i)
	{
		if (questionVec[i] != answerVec[i])
		{
			return false;
		}
	}

	return true;
}

// ���� ���� �� �ʿ��� ��ɵ��� ������ �Լ�
void GameStart()
{
	PlaySound(TEXT("HYP-BlueAngle.wav"), NULL, SND_ASYNC | SND_LOOP);
	int life = LIFE;
	int score = 0;

	clock_t startTime, endTime;
	startTime = clock();

	std::vector<int> questionVec;
	std::string questionStr = "";

	std::vector<int> answerVec;
	std::string answerStr = "";

	int firstInput = 0;
	int secondInput = 0;

	while (true)
	{
		int level = (score / 30) + 1;

		// ���� ����
		SetQuestion(questionVec, level);
		// ������ �����ֱ�
		VectorToString(questionVec, questionStr);

		while (true)
		{
			// ���� Ǯ��
			DrawStartGame(life, score, questionStr, answerStr);

			if (life == 0)
			{
				endTime = clock();
				int playTime = static_cast<int>((endTime - startTime) / CLOCKS_PER_SEC);
				DrawGameOver(playTime);
				PlaySound(NULL, NULL, 0);
				return;
			}

			// ���� �Է�
			firstInput = _getch();
			if (firstInput == MAGIC_KEY)
			{
				secondInput = _getch();
				answerVec.push_back(secondInput);
				switch (secondInput)
				{
				case UP:
					answerStr += "�� ";
					break;

				case RIGHT:
					answerStr += "�� ";
					break;

				case LEFT:
					answerStr += "�� ";
					break;

				case DOWN:
					answerStr += "�� ";
					break;
				}
			}
			else if (firstInput == SPACE)
			{
				// �� ����
				// �� Ȯ��
				if (CheckAnswer(questionVec, answerVec))
				{
					score += 10;
				}
				else
				{
					--life;
					score -= 5;
					if (score < 0)
					{
						score = 0;
					}
				}

				questionVec.clear();
				questionStr = "";
				answerVec.clear();
				answerStr = "";

				break;
			}
		}
	}
}