#pragma once

class GameManager
{
public:
	// 콘솔창의 크기 조절
	void SetConsoleSize();

	// 콘솔창에서 커서 이동을 하는 함수
	void gotoxy(int x, int y);

	// 메뉴 선택창 커서
	void DrawUserCursor(int& y);

	// 메인메뉴 그리기
	void DrawMainScreen();

	// 게임 시작시 화면 그리기
	void DrawGameStart();

	// 게임 정보 그리기
	void DrawGameInfo();

	// 테트리스 모양 그리기
	void DrawFigures();

private:
};