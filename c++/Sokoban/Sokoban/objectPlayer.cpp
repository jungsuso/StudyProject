#include "objectPlayer.h"

bool ObjectPlayer::CheckPosition(const Position movePos)
{
	// ���� �÷��̾��� ��ġ�� ���������� Ȯ��
	if (!IsinMapNow())
	{
		return false;
	}

	// �������� ������ ��ġ�� ������ ��ġ���� Ȯ��
	int dx = GetX() + movePos.x;
	int dy = GetY() + movePos.y;

	if (!IsinMapNow(dy, dx))
		return false;

	// �������� ������ ��ġ�� ������ Ȯ��
	if (map[dy][dx] == WALL)
		return false;

	// �������� ������ ��ġ�� �ڽ� Ȥ�� Ȧ ���� �ڽ����� Ȯ��
	if (map[dy][dx] == BOX || map[dy][dx] == HOLEWITHBOX)
	{
		//TODO: �ڽ��� �и� �� �ִ� �� Ȯ��
		ObjectBox* pBox = new ObjectBox();
		pBox->SetX(dx);
		pBox->SetY(dy);
		if (!pBox->CheckPosition(movePos))
		{
			return false;
		}
		
		pBox->MovePosition(movePos);
		delete pBox;
	}

	return true;
}

void ObjectPlayer::MovePosition(const Position movePos)
{
	if (!CheckPosition(movePos))
		return;

	// �̵� ����
	int curX = GetX();
	int curY = GetY();

	// Ȧ ���� �÷��̾ �ִ� ��������
	if (map[curY][curX] == HOLEWITHPLAYER)
		map[curY][curX] = HOLE;
	// Ȧ�� ����ִ� ��������
	else
		map[curY][curX] = EMPTY;

	int nextX = curX + movePos.x;
	int nextY = curY + movePos.y;

	SetX(nextX);
	SetY(nextY);

	if (map[nextY][nextX] == HOLE)
		map[nextY][nextX] = HOLEWITHPLAYER;
	else
		map[nextY][nextX] = PLAYER;

}
