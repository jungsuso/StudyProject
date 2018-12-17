#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include "DrawScreen.h"

using namespace std;

int GetKeyDown()
{
	if (_kbhit() != 0) // 키보드 입력을 인지, 키보드 입력이 없는 경우는 계속 0을 return. 키보드 입력이 생기면 0이 아닌 수를 return
	{
		return _getch(); // 하나의 char를 input
	}
	return 0;
}



void SetDictionary(vector<string>& strArr)
{
	static const string str[4] = { "apple", "banana", "code", "program" };
	ifstream readFromFile("words.txt");
	if (!readFromFile.is_open())
	{
		ofstream writeToFile("words.txt");
		for (int i = 0; i < 4; ++i)
		{
			string tmp = str[i];
			tmp += "\n";
			writeToFile.write(tmp.c_str(), tmp.size());
			strArr.push_back(str[i]);
		}
		writeToFile.close();
		return;
	}

	while (!readFromFile.eof())
	{
		string tmp;
		getline(readFromFile, tmp);
		strArr.push_back(tmp);
	}

	readFromFile.close();
	return;
}

bool ReadyGame()
{
	DrawReadyGame();
	while (true)
	{
		int key = GetKeyDown();
		if (key == 's' || key == 'S')
			return true;
		else if (key == 'q' || key == 'Q')
			break;
	}

	return false;
}



void StartGame()
{
	int score = 0;
	vector<string> pastWord;
	vector<string> strArr;
	//string strArr[WORD_MAX] = { "apple", "banana", "code", "program" };
	SetDictionary(strArr); // read from file

	while (true)
	{
		// 1 play
		int num = 0;

		srand((unsigned int)time(NULL));
		//num = rand() % WORD_MAX;
		num = rand() % (int)strArr.size();

		const string strOriginal = strArr[num];
		string strQuestion;

		// init
		for (int i = 0; i < (int)strOriginal.length(); ++i)
			strQuestion += "_";

		int life = (int)strOriginal.length() + 2;
		// 1 question
		while (true)
		{
			DrawStartGame(score, life, pastWord);

			// draw word
			gotoxy(5, 5);
			for (int i = 0; i < (int)strQuestion.length(); ++i)
				cout << strQuestion[i] << " ";
			cout << endl;

			char input[20];
			gotoxy(9, 12);
			cin >> input; // 사용자가 입력
			string strInput = input;

			if (strInput == "qq" || strInput == "QQ")
				return;

			pastWord.push_back(strInput);

			if (strInput.length() == 1)
			{
				// alphabet
				for (int i = 0; i < (int)strOriginal.length(); ++i)
				{
					if (strOriginal[i] == strInput[0])
					{
						strQuestion[i] = strInput[0];
					}
				}
			}
			else if (strInput.length() > 1)
			{
				// word
				if (strOriginal == strInput)
				{
					// score up
					score += 5;
					pastWord.clear();
					break;
				}
			}

			--life;
			if (life < 0)
			{
				score -= 5;
				if (score < 0)
					score = 0;
				pastWord.clear();
				break;
			}
		}
	}
}