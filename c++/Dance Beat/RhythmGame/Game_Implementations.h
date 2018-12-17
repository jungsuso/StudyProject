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

// 메인메뉴
enum MENU
{
	GAMESTART,
	INFO,
	QUIT,
};

// 키보드 입력을 위한 열거형 자료
enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

// 메뉴 선택창 구현 함수
MENU ReadyGame()
{
	int y = 0;
	int input = 0;

	while (true)
	{
		DrawReadyGame();
		DrawUserCursor(y);
		input = _getch();
		// ↑↓→←
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

// INFO 함수를 출력하기 위한 함수
void Infomation_Of_Game()
{
	DrawInfo_Of_Game();
	system("pause>null");
}

// 게임 시작 시, 문제를 위해 랜덤으로 화살표 생성
void SetQuestion(std::vector<int>& questionVec, int level)
{
	if (level > MAX_LEVEL)
		level = MAX_LEVEL;

	int num = 0;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < level; ++i) // 5 : 화살표의 개수(문제의 난이도)
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

// 문자 비교를 위해 vector 타입의 값을 string 타입으로 변환하는 함수
void VectorToString(const std::vector<int>& v, std::string& str)
{
	for (int i = 0; i < static_cast<int>(v.size()); ++i)
	{
		switch (v[i])
		{
		case UP:
			str += "↑ ";
			break;

		case RIGHT:
			str += "→ ";
			break;

		case LEFT:
			str += "← ";
			break;

		case DOWN:
			str += "↓ ";
			break;
		}
	}
}

// 제출된 문제와 입력한 답을 비교하는 함수
bool CheckAnswer(const std::vector<int> questionVec, const std::vector<int> answerVec)
{
	// 숫자의 배열이 같다.
	// 길이 체크
	if (questionVec.size() != answerVec.size())
	{
		return false;
	}
	// 값 체크
	for (int i = 0; i < static_cast<int>(questionVec.size()); ++i)
	{
		if (questionVec[i] != answerVec[i])
		{
			return false;
		}
	}

	return true;
}

// 게임 시작 시 필요한 기능들을 구현한 함수
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

		// 문제 세팅
		SetQuestion(questionVec, level);
		// 문제를 보여주기
		VectorToString(questionVec, questionStr);

		while (true)
		{
			// 문제 풀기
			DrawStartGame(life, score, questionStr, answerStr);

			if (life == 0)
			{
				endTime = clock();
				int playTime = static_cast<int>((endTime - startTime) / CLOCKS_PER_SEC);
				DrawGameOver(playTime);
				PlaySound(NULL, NULL, 0);
				return;
			}

			// 정답 입력
			firstInput = _getch();
			if (firstInput == MAGIC_KEY)
			{
				secondInput = _getch();
				answerVec.push_back(secondInput);
				switch (secondInput)
				{
				case UP:
					answerStr += "↑ ";
					break;

				case RIGHT:
					answerStr += "→ ";
					break;

				case LEFT:
					answerStr += "← ";
					break;

				case DOWN:
					answerStr += "↓ ";
					break;
				}
			}
			else if (firstInput == SPACE)
			{
				// 답 제출
				// 답 확인
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