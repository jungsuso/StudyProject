#pragma once

class GameManager
{
public:
	// �ܼ�â�� ũ�� ����
	void SetConsoleSize();

	// �ܼ�â���� Ŀ�� �̵��� �ϴ� �Լ�
	void gotoxy(int x, int y);

	// �޴� ����â Ŀ��
	void DrawUserCursor(int& y);

	// ���θ޴� �׸���
	void DrawMainScreen();

	// ���� ���۽� ȭ�� �׸���
	void DrawGameStart();

	// ���� ���� �׸���
	void DrawGameInfo();

	// ��Ʈ���� ��� �׸���
	void DrawFigures();

private:
};