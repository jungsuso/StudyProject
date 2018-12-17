#pragma once
#include <vector>

// 게임 실행 시, 콘솔창의 크기 조절
void SetConsoleView();

// 화면 디자인을 위해 커서 이동
void gotoxy(int x, int y);

// 메인화면 그리기
void DrawReadyGame();

// 시작화면 그리기
void DrawStartGame(int score, int life, std::vector<std::string>& pastWord);