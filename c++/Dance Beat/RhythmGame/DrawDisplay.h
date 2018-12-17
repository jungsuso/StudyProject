#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>



// 시작 시, 콘솔창의 크기와 title을 정해주는 함수
void SetConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title Dance Beat");
}

// 화면에서 원하는 곳에 출력을 하기 위해 특정 위치로 커서를 이동
void gotoxy(int x, int y);

// 메인화면 출력 함수
void DrawReadyGame();

// 프로그램 정보 출력 함수
void DrawInfo_Of_Game();

// 시작 시 화면 출력 함수
void DrawStartGame(const int life, const int score, const std::string questionStr, const std::string answerStr);

// 게임오버 시 출력 함수
void DrawGameOver(const int& playTime);

// 메인화면에서 원하는 기능 선택하도록 하는 함수
void DrawUserCursor(int& y);